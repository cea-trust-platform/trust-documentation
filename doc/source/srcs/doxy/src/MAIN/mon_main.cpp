/****************************************************************************
* Copyright (c) 2025, CEA
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*****************************************************************************/

#include <mon_main.h>
#include <LecFicDiffuse_JDD.h>
#include <TClearable.h> // To clear caches before exiting, notably Domaine_dis_cache
#include <instancie_appel.h>
#include <SFichier.h>
#include <Comm_Group_MPI.h>
#include <PE_Groups.h>
#include <Journal.h>
#include <cstdio>
#include <Statistiques.h>
#include <communications.h>
#include <petsc_for_kernel.h>
#include <stat_counters.h>
#include <info_atelier.h>
#include <unistd.h> // Pour chdir for other compiler
#ifndef __CYGWIN__
#include <catch_and_trace.h>
#endif

#include <kokkos++.h>

// Initialisation des compteurs, dans stat_counters.cpp
extern void declare_stat_counters();
extern void end_stat_counters();
extern Stat_Counter_Id temps_total_execution_counter_;
extern Stat_Counter_Id initialisation_calcul_counter_;

mon_main::mon_main(int verbose_level, bool journal_master, Nom log_directory, bool apply_verification, bool disable_stop)
{
  verbose_level_ = verbose_level;
  journal_master_ = journal_master;
  log_directory_ = log_directory;
  apply_verification_ = apply_verification;
  // Creation d'un journal temporaire qui ecrit dans Cerr
  init_journal_file(verbose_level, 0 /* filename = 0 => Cerr */, 0 /* append */);
  trio_began_mpi_=false;
  disable_stop_=disable_stop;
  change_disable_stop(disable_stop);
}

// Catching exception signal only in debug mode:
#ifndef NDEBUG
bool error_handlers = true;
#else
bool error_handlers = false;
#endif
static int init_petsc(True_int argc, char **argv, bool with_mpi,bool& trio_began_mpi_)
{
#ifdef PETSCKSP_H
  static char help[] = "TRUST may solve linear systems with Petsc library.\n\n" ;
  Nom pwd(::pwd());
  // On initialise Petsc
#ifdef MPI_INIT_NEEDS_MPIRUN
  True_int flag;
  MPI_Initialized(&flag);
  // si MPI initialise ou si argc>2
  if ((argc>2)||(flag))
    {
      PetscInitialize(&argc, &argv, (char*)0, help);
    }
#else
  PetscInitialize(&argc, &argv, (char*)0, help);
#endif
  // Bizarrerie qui se produit sur une machine (ioulia, MPICH natif): PetscInitialize change le pwd()
  // en sequentiel et si le binaire n'est pas dans le repertoire de l'etude, le pwd est perdu...
  int ierr;
  if (!with_mpi)
    {
      ierr=chdir(pwd);
      if (ierr)
        {
          Cerr << "Error on chdir into mon_main.cpp. Contact TRUST support." << finl;
          Process::exit();
        }
    }
  // Equivalent de -abort_on_error (aucune erreur PETSc n'est tolere):
  PetscPushErrorHandler(PetscAbortErrorHandler, PETSC_NULLPTR);
  // Desactive le signal handler en optimise pour eviter d'etre trop bavard
  // et de "masquer" les messages d'erreur TRUST:
  PetscPopSignalHandler();

  char* theValue = getenv("TRUST_ENABLE_ERROR_HANDLERS");
  if (theValue != nullptr) error_handlers = true;
  if (error_handlers)
    {
      Cerr << "Enabling error handlers catching SIGFPE and SIGABORT and giving a trace of where the fault happened." << finl;
#ifndef __CYGWIN__
      install_handlers();
#endif
    }
#else
  // MPI_Init pour les machines ou Petsc n'est pas
  // installe: ex AIX avec MPICH: il faut que argc et argv soit passes
  // correctement et pas comme dans Comm_Group_MPI::init_group_trio
  // sinon message: xm_348262:  p4_error: Command-line arguments are missing: 0
#ifdef MPI_
  True_int flag;
  MPI_Initialized(&flag);
  if (!flag)
    {
      MPI_Init(&argc,&argv);
      trio_began_mpi_=true;
    }
#endif
#endif
  return 1;
}

static int init_parallel_mpi(OWN_PTR(Comm_Group) & groupe_trio)
{
#ifdef MPI_
  groupe_trio.typer("Comm_Group_MPI");
  Comm_Group_MPI& mpi = ref_cast(Comm_Group_MPI, groupe_trio.valeur());
  // Si ca n'a pas ete fait dans Petsc, c'est ici qu'on fait MPI_Init()
  mpi.init_group_trio();
  return 1;
#else
  return 0;
#endif
}

static void instantiate_node_mpi(OWN_PTR(Comm_Group) & ngrp, OWN_PTR(Comm_Group) & mgrp, int with_mpi)
{
  if (with_mpi)
    {
      ngrp.typer("Comm_Group_MPI");
      mgrp.typer("Comm_Group_MPI");
    }
  else
    {
      ngrp.typer("Comm_Group_NoParallel");
      mgrp.typer("Comm_Group_NoParallel");
    }
}

static void init_node_mpi(OWN_PTR(Comm_Group) & ngrp)
{
#ifdef MPI_
  assert(ngrp.non_nul());
  Comm_Group_MPI& mpi_on_node = ref_cast(Comm_Group_MPI, ngrp.valeur());
  mpi_on_node.init_comm_on_numa_node();
#endif
}

static void init_node_masters(OWN_PTR(Comm_Group) & master)
{
#ifdef MPI_
  assert(master.non_nul());
  Comm_Group_MPI& mm = ref_cast(Comm_Group_MPI, master.valeur());
  mm.init_comm_on_node_master();
#endif
}

///////////////////////////////////////////////////////////
// Desormais Petsc/MPI_Initialize et Petsc/MPI_Finalize
// sont dans un seul fichier: mon_main
// On ne doit pas en voir ailleurs !
//////////////////////////////////////////////////////////
void mon_main::init_parallel(const int argc, char **argv, bool with_mpi, bool check_enabled, bool with_petsc)
{
  bool init_kokkos_before_mpi = (getenv("KOKKOS_AFTER_MPI") == nullptr);
  // https://kokkos.org/kokkos-core-wiki/ProgrammingGuide/Initialization.html say after !
  if (init_kokkos_before_mpi)
    {
      // Kokkos initialization
      True_int argc2 = argc;
      Kokkos::initialize(argc2, argv);
    }
  Nom arguments_info="";
  arguments_info +="Kokkos initialized!\n";

#ifdef TRUST_USE_CUDA
  //init_cuda(); Desactive car crash crash sur topaze ToDo OpenMP
#endif
  bool must_mpi_initialize = true;
  if (with_petsc)
    {
      if (init_petsc(argc, argv, with_mpi,trio_began_mpi_))
        {
          must_mpi_initialize = false; // Deja fait par Petsc
          arguments_info += "Petsc initialization succeeded.\n";
        }
      else
        {
          arguments_info += "Petsc initialization failed (not compiled ?). Not fatal...\n";
        }
    }
  else
    {
      arguments_info += "Petsc initialization skipped (-petsc=0).\n";
    }
#ifdef MPI_
  Comm_Group_MPI::set_must_mpi_initialize(must_mpi_initialize);
#else
  // avoid variable 'must_mpi_initialize' set but not used error when MPI disabled
  if (must_mpi_initialize) abort();
#endif
  // ***************** Initialisation du parallele *************************
  Comm_Group::set_check_enabled(check_enabled);

  if (with_mpi)
    {
      if (!init_parallel_mpi(groupe_trio_))
        {
          Cerr << "MPI initialization failed (not compiled ?). Fatal." << finl;
          Process::exit();
        }
    }
  else
    groupe_trio_.typer("Comm_Group_NoParallel");

  // Initialisation des groupes de communication.
  PE_Groups::initialize(groupe_trio_);
  arguments_info += "Parallel engine initialized : ";
  arguments_info += groupe_trio_->que_suis_je();
  arguments_info += " with ";
  arguments_info += Nom(Process::nproc());
  arguments_info += " processors\n";

  if (Process::je_suis_maitre())
    Cerr << arguments_info;

  // the node group is instantiated here, so that it's done only once (necessary with ICoCo)
  // however, it is initialized later, as it involves communication operations, which require statistics to be initialized first...
  instantiate_node_mpi(node_group_, node_master_, with_mpi);

  if (!init_kokkos_before_mpi)
    {
      // Kokkos initialization
      True_int argc2 = argc;
      Kokkos::initialize(argc2, argv);
      if (Process::je_suis_maitre())
        Cerr << "Kokkos initialized after MPI !" << finl;
    }
  if (Process::je_suis_maitre())
    Cerr << "You can run --kokkos-help option." << finl;
}

void mon_main::finalize()
{
  // Clear all things that were registered by Register_clearable() method (typically the Domaine_dis_cache instance
  // to make sure all Kokkos views are freed before doing Kokkos finalize):
  TClearable::Clear_all();

#ifdef MPI_
  // MPI_Group_free before MPI_Finalize (not freeing comm as we can not free MPI_COMM_WORLD)
  if (sub_type(Comm_Group_MPI,groupe_trio_.valeur()))
    ref_cast(Comm_Group_MPI,groupe_trio_.valeur()).free();

  if (sub_type(Comm_Group_MPI,node_master_.valeur()))
    ref_cast(Comm_Group_MPI,node_master_.valeur()).free_all(); // free comm + group

  if (sub_type(Comm_Group_MPI,node_group_.valeur()))
    ref_cast(Comm_Group_MPI,node_group_.valeur()).free_all(); // free comm + group


#endif
#ifdef PETSCKSP_H
  // On PetscFinalize que si c'est necessaire
  PetscBool isInitialized;
  PetscInitialized(&isInitialized);
  if (isInitialized==PETSC_TRUE)
    {
      PetscPopErrorHandler(); // Removes the latest error handler that was pushed with PetscPushErrorHandler in init_petsc
#ifdef MPI_
      if (sub_type(Comm_Group_MPI,PE_Groups::current_group()))
        PETSC_COMM_WORLD = ref_cast(Comm_Group_MPI,PE_Groups::current_group()).get_mpi_comm();
#endif
      PetscFinalize();
    }
#endif
#ifdef MPI_
  if (trio_began_mpi_)
    {
      // On MPI_Finalize si MPI_Initialized and not MPI_Finalized
      True_int flag;
      MPI_Initialized(&flag);
      if (flag)
        {
          MPI_Finalized(&flag);
          if (!flag)
            MPI_Finalize();
        }
    }
#endif
  Kokkos::finalize();
}

void mon_main::dowork(const Nom& nom_du_cas)
{
  // Initialisation des compteurs pour les statistiques
  // avant tout appel a envoyer, recevoir, ...
  if (!les_statistiques_trio_U_nom_long_pour_decourager_l_utilisation_directe)
    {
      declare_stat_counters();
    }
  statistiques().begin_count(temps_total_execution_counter_);
  // Ce compteur est arrete dans Resoudre*
  statistiques().begin_count(initialisation_calcul_counter_);

  // Le processeur maitre envoie le nom du cas a tous les processeurs
  // car avec une distribution MPICH 1.2.7 (Debian)
  // la ligne de commande recuperee avec argv ne contient
  // pas le nom du jeu de donnees pour les processeurs autres
  // que le processeur maitre
  Nom tmp = nom_du_cas;
  envoyer(tmp, 0, -1, 0);
  recevoir(tmp, 0, -1, 0);
  Objet_U::get_set_nom_du_cas() = tmp;

  // ******************* Journal ***************************
  // Initialisation du journal parallele (maintenant qu'on connait le rang
  //  du processeur et le nom du cas)
  {
    // Master process creates log directory if needed
    if (Process::je_suis_maitre() && log_directory_!="")
      {
        Nom mkdir_command("mkdir -p ");
        mkdir_command += log_directory_;
        if(system(mkdir_command))
          {
            Cerr << "Error while creating directory: " << log_directory_ << "\n";
            Process::exit();
          }
      }
    Process::barrier(); // Otherwise, non-master processes try to write .log file before mkdir is done
    Nom filename = log_directory_ + nom_du_cas;
    if (Process::nproc() > 1)
      {
        filename += "_";
        char s[20];
        snprintf(s, 20, "%05d", (True_int)Process::me());
        filename += s;
      }
    filename += ".log";
    // Si journal_master_, seul le process maitre ecrit dans le journal:
    if (journal_master_ && !Process::je_suis_maitre())
      verbose_level_ = 0;

    // Si un journal unique n'est pas active, alors desactive les journaux logs au dela d'un certain nombre de rangs MPI:
    // Dans le cas ou l'option "-journal" est specifiee
    if (verbose_level_ < 0)
      {
        if (!journal_master_ && Process::force_single_file(Process::nproc(), nom_du_cas+".log"))
          verbose_level_ = 0;
        else
          verbose_level_ = 1;
      }

    init_journal_file(verbose_level_,filename, 0 /* append=0 */);
    Process::Journal() << "Journal logging started" << finl;
  }

#ifdef TRUST_USE_GPU
  // PL: It will be better to do it sooner (near Cuda init or Kokkos init) but need stat and journal initialized
  // Soon obsolete:
  init_device();
  self_test();
#endif

  Nom nomfic( nom_du_cas );
  nomfic += ".stop";
  if (!get_disable_stop() && Process::je_suis_maitre())
    {
      SFichier ficstop( nomfic );
      ficstop << "Running..."<<finl;
    }

  //---------------------------------------------//
  // Chargement des modules : //
  // on ne les charges que pour le cas nul, pour verifier avec valgrind
  if (Objet_U::nom_du_cas()=="nul")
    {
      Cerr<<"Chargement des modules:"<<finl;
#include <instancie_appel_c.h>
      Cerr<<"Fin chargement des modules "<<finl;
    }

  // initializing communicators on node
  if (Process::is_parallel())
    init_node_mpi(node_group_);
  PE_Groups::initialize_node(node_group_);

  // Node_master needs node_group to be initialized first
  if (Process::is_parallel())
    init_node_masters(node_master_);
  PE_Groups::initialize_node_master(node_master_);

  Cout<< " " << finl;
  Cout<< " * * * * * * * * * * * * * * * * * * * * * * * * * * * *     " << finl;
  Cout<< " *  _________  _______             _______  _________  *     " << finl;
  Cout<< " *  \\__   __/ (  ____ ) |\\     /| (  ____ \\ \\__   __/  * " << finl;
  Cout<< " *     ) (    | (    )| | )   ( | | (    \\/    ) (     *    " << finl;
  Cout<< " *     | |    | (____)| | |   | | | (_____     | |     *     " << finl;
  Cout<< " *     | |    |     __) | |   | | (_____  )    | |     *     " << finl;
  Cout<< " *     | |    | (\\ (    | |   | |       ) |    | |     *    " << finl;
  Cout<< " *     | |    | ) \\ \\__ | (___) | /\\____) |    | |     *  " << finl;
  Cout<< " *     )_(    |/   \\__/ (_______) \\_______)    )_(     *   " << finl;
  Cout<< " *                                                     *     " << finl;
  Cout<< " *                  version : " << TRUST_VERSION << "               *     "  << finl;
  Cout<< " *                       CEA - DES                     *     " << finl;
  Cout<< " *                                                     *     " << finl;
  Cout<< " * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << finl;
  Cout<< " " << finl;

  info_atelier(Cout);
  Cout<<" " << finl;
  Cout<<"  Vous traitez le cas " << Objet_U::nom_du_cas() << "\n";
  Cout<<" " << finl;

  // GF on ecrit la hierarchie que si on a un erreur
  //---------------------------------------------//
  Cerr<<"Debut de l'execution " << finl;
  {
    Nom nomentree = nom_du_cas;
    nomentree+=".data";
    /*
    #ifndef NDEBUG
    if (Process::je_suis_maitre())
      {
        SFichier es("convert_jdd");
      }
    #endif */
    // La verfication est faite maintenant dans LecFicDiffuse_JDD
    // mias je garde les lignes au cas ou
    if (0)
      {
        Cerr << "MAIN: Checking data file for matching { and }" << finl;
        {
          LecFicDiffuse_JDD verifie_entree(nomentree, ios::in, apply_verification_);
          interprete_principal_.interpreter_bloc(verifie_entree,
                                                 Interprete_bloc::FIN /* on attend FIN a la fin */,
                                                 1 /* verifie_sans_interpreter */);
        }
      }
    Cerr << "MAIN: Reading and executing data file" << finl;
    {
      LecFicDiffuse_JDD lit_entree(nomentree, ios::in, apply_verification_);
      lit_entree.set_check_types(1);
      interprete_principal_.interpreter_bloc(lit_entree,
                                             Interprete_bloc::FIN /* on attend FIN a la fin */,
                                             0 /* interprete pour de vrai */);
    }
  }

  Cerr << "MAIN: End of data file" << finl;
  Process::imprimer_ram_totale(1);

  // pour les cas ou on ne fait pas de resolution
  int mode_append=1;
  if (!Objet_U::disable_TU)
    {
      if(GET_COMM_DETAILS)
        statistiques().print_communciation_tracking_details("Statistiques de post resolution", 1);               // Into _csv.TU file

      statistiques().dump("Statistiques de post resolution", mode_append);
      print_statistics_analyse("Statistiques de post resolution", 1);
    }

  double temps = statistiques().get_total_time();
  Cout << finl;
  Cout << "--------------------------------------------" << finl;
  Cout << "clock: Total execution: " << temps << " s" << finl;
  if (!get_disable_stop() && Process::je_suis_maitre())
    {
      SFichier ficstop ( nomfic);
      ficstop  << "Finished correctly"<<finl;
    }
  //  end_stat_counters();
}

mon_main::~mon_main()
{
  // On peut arreter le journal apres les communications:
  // EDIT 12/02/2020: journal needs communication to be turned on if it's written in HDF5 format
  Process::Journal() << "End of Journal logging" << finl;
  end_journal(verbose_level_);
  end_stat_counters();
  // Destruction de l'interprete principal avant d'arreter le parallele
  interprete_principal_.vide();
  // PetscFinalize/MPI_Finalize
  finalize();
  // on peut arreter maintenant que l'on a arrete les journaux
  PE_Groups::finalize();
  groupe_trio_.detach();
  node_group_.detach();

}
