/****************************************************************************
* Copyright (c) 2024, CEA
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

#ifndef Process_included
#define Process_included

#include <TRUST_Version.h>  // so that it is accessible from everywhere in TRUST

#ifdef LATATOOLS
#include <string>
#include <stdlib.h>
#endif

class Objet_U;
class Nom;
class Sortie;

int get_disable_stop();
void change_disable_stop(int new_stop);

/*! @brief Classe de base de TRUST (notamment Objet_U).
 *
 * Elle fournit quelques services de base
 *    accessibles de partout dans le code (ces services etaient historiquement
 *    des methodes non statiques, depuis que tous ces services sont statiques,
 *    cette classe n'a plus vraiment d'autre fonction que de ranger ces methodes
 *    quelque part)
 *
 * @sa Objet_U
 */

class Process
{
public:
  virtual ~Process() { }

  // Simplified dummy API for lata_tools
#ifdef LATATOOLS
  static int me() { return 0; }
  static int nproc()  { return 1; }
  static bool is_parallel()  { return false; }
  static void exit(int exit_code = -1) { ::exit(exit_code); }
  static void exit(const std::string& s) { ::exit(-1); }

  static double mp_sum(double) { return 0; }
  static double mp_max(double) { return 0; }
  static int mp_max(int) { return 0; }
  static double mp_min(double) { return 0; }
  static int mp_min(int) { return 0; }
  static int mp_sum(int) { return 0; }

#else
  static int me(); /* mon rang dans le groupe courant */
  static int nproc();
  static bool is_parallel();
  static void exit(int exit_code = -1);

  static double mp_sum(double);
  static double mp_max(double);
  static int mp_max(int);
  static double mp_min(double);
  static int mp_min(int);
  static int mp_sum(int);

  static int je_suis_maitre();
  static void exit(const Nom& message, int exit_code = -1);
  static bool is_sequential(); // serial ?
  static void barrier();
  static bool mp_and(bool);
  static void abort();

  static Sortie& Journal(int message_level = 0);
  static double ram_processeur();
  static void imprimer_ram_totale(int all_process = 0);
  static int exception_sur_exit;
  static int multiple_files;
  static bool force_single_file(const int ranks, const Nom& filename);
#endif
};

#endif /* Process_included */

