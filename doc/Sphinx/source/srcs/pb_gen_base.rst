pb_gen_base
===========

**coupled_problem**
-------------------

**Synonyms:** probleme_couple

**Inherits from:** :ref:`pb_gen_base` 


This instruction causes a probleme_couple type object to be created.
This type of object has an associated problem list, that is, the coupling of n problems 
among them may be processed.
Coupling between these problems is carried out explicitly via conditions at particular 
contact limits.
Each problem may be associated either with the Associate keyword or with the Read/groupes 
keywords.
The difference is that in the first case, the four problems exchange values then 
calculate their timestep, rather in the second case, the same strategy is used for 
all the problems listed inside one group, but the second group of problem exchange 
values with the first group of problems after the first group did its timestep.
So, the first case may then also be written like this:

Probleme_Couple pbc

Read pbc { groupes { { pb1 , pb2 , pb3 , pb4 } } }

There is a physical environment per problem (however, the same physical environment 
could be common to several problems).

Each problem is resolved in a domain.

Warning : Presently, coupling requires coincident meshes.
In case of non-coincident meshes, boundary condition 'paroi_contact' in VEF returns 
error message (see paroi_contact for correcting procedure).

Parameters are:

- **[groupes]**  (*type:* :ref:`list_list_nom`) { groupes { { pb1 , pb2 } , { pb3 , pb4 } } }


----

**pb_avec_passif**
------------------
**Inherits from:** :ref:`pb_gen_base` 


Class to create a classical problem with a scalar transport equation (e.g: temperature 
or concentration) and an additional set of passive scalars (e.g: temperature or concentration) 
equations.

Parameters are:

- **equations_scalaires_passifs**  (*type:* :ref:`listeqn`) Passive scalar equations. The unknowns of the passive scalar equation number N are named temperatureN or concentrationN  or fraction_massiqueN. This keyword is used to define initial conditions and the post processing fields. This kind of problem is very useful to test in only one data file (and then only  one calculation) different schemes or different boundary conditions for the scalar  transport equation.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_base**
-----------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of equations on a domain.
A problem is defined by creating an object and assigning the problem type that the 
user wishes to resolve.
To enter values for the problem objects created, the Lire (Read) interpretor is used 
with a data block.

Parameters are:

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_conduction**
-----------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of the heat equation.

Parameters are:

- **[solide]**  (*type:* :ref:`solide`) The medium associated with the problem.

- **[conduction]**  (*type:* :ref:`conduction`) Heat equation.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_gen_base**
---------------
**Inherits from:** :ref:`pb_gen_base` 


Basic class for problems.

----

**pb_hydraulique**
------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of the Navier-Stokes equations.

Parameters are:

- **fluide_incompressible**  (*type:* :ref:`fluide_incompressible`) The fluid medium associated with the problem.

- **navier_stokes_standard**  (*type:* :ref:`navier_stokes_standard`) Navier-Stokes equations.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_hydraulique_concentration**
--------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of Navier-Stokes/multiple constituent transport equations.

Parameters are:

- **fluide_incompressible**  (*type:* :ref:`fluide_incompressible`) The fluid medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituents.

- **[navier_stokes_standard]**  (*type:* :ref:`navier_stokes_standard`) Navier-Stokes equations.

- **[convection_diffusion_concentration]**  (*type:* :ref:`convection_diffusion_concentration`) Constituent transport vectorial equation (concentration  diffusion convection).

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_hydraulique_concentration_scalaires_passifs**
--------------------------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of Navier-Stokes/multiple constituent transport equations with the additional 
passive scalar equations.

Parameters are:

- **fluide_incompressible**  (*type:* :ref:`fluide_incompressible`) The fluid medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituents.

- **[navier_stokes_standard]**  (*type:* :ref:`navier_stokes_standard`) Navier-Stokes equations.

- **[convection_diffusion_concentration]**  (*type:* :ref:`convection_diffusion_concentration`) Constituent transport equations (concentration  diffusion convection).

- **equations_scalaires_passifs**  (*type:* :ref:`listeqn`) Passive scalar equations. The unknowns of the passive scalar equation number N are named temperatureN or concentrationN  or fraction_massiqueN. This keyword is used to define initial conditions and the post processing fields. This kind of problem is very useful to test in only one data file (and then only  one calculation) different schemes or different boundary conditions for the scalar  transport equation.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_hydraulique_concentration_turbulent**
------------------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of Navier-Stokes/multiple constituent transport equations, with turbulence 
modelling.

Parameters are:

- **fluide_incompressible**  (*type:* :ref:`fluide_incompressible`) The fluid medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituents.

- **[navier_stokes_turbulent]**  (*type:* :ref:`navier_stokes_turbulent`) Navier-Stokes equations as well as the associated turbulence  model equations.

- **[convection_diffusion_concentration_turbulent]**  (*type:* :ref:`convection_diffusion_concentration_turbulent`) Constituent transport equations (concentration  diffusion convection) as well as the associated turbulence model equations.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_hydraulique_concentration_turbulent_scalaires_passifs**
------------------------------------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of Navier-Stokes/multiple constituent transport equations, with turbulence 
modelling and with the additional passive scalar equations.

Parameters are:

- **fluide_incompressible**  (*type:* :ref:`fluide_incompressible`) The fluid medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituents.

- **[navier_stokes_turbulent]**  (*type:* :ref:`navier_stokes_turbulent`) Navier-Stokes equations as well as the associated turbulence  model equations.

- **[convection_diffusion_concentration_turbulent]**  (*type:* :ref:`convection_diffusion_concentration_turbulent`) Constituent transport equations (concentration  diffusion convection) as well as the associated turbulence model equations.

- **equations_scalaires_passifs**  (*type:* :ref:`listeqn`) Passive scalar equations. The unknowns of the passive scalar equation number N are named temperatureN or concentrationN  or fraction_massiqueN. This keyword is used to define initial conditions and the post processing fields. This kind of problem is very useful to test in only one data file (and then only  one calculation) different schemes or different boundary conditions for the scalar  transport equation.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_hydraulique_melange_binaire_qc**
-------------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of a binary mixture problem for a quasi-compressible fluid with an iso-thermal 
condition.

Keywords for the unknowns other than pressure, velocity, fraction_massique are :

masse_volumique : density

pression : reduced pressure

pression_tot : total pressure.

Parameters are:

- **fluide_quasi_compressible**  (*type:* :ref:`fluide_quasi_compressible`) The fluid medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) The various constituants associated to the problem.

- **navier_stokes_qc**  (*type:* :ref:`navier_stokes_qc`) Navier-Stokes equation for a quasi-compressible fluid.

- **convection_diffusion_espece_binaire_qc**  (*type:* :ref:`convection_diffusion_espece_binaire_qc`) Species conservation equation for a binary  quasi-compressible fluid.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_hydraulique_melange_binaire_turbulent_qc**
-----------------------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of a turbulent binary mixture problem for a quasi-compressible fluid with 
an iso-thermal condition.

Parameters are:

- **fluide_quasi_compressible**  (*type:* :ref:`fluide_quasi_compressible`) The fluid medium associated with the problem.

- **navier_stokes_turbulent_qc**  (*type:* :ref:`navier_stokes_turbulent_qc`) Navier-Stokes equation for a quasi-compressible fluid  as well as the associated turbulence model equations.

- **convection_diffusion_espece_binaire_turbulent_qc**  (*type:* :ref:`convection_diffusion_espece_binaire_turbulent_qc`) Species conservation equation for  a quasi-compressible fluid as well as the associated turbulence model equations.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_hydraulique_melange_binaire_wc**
-------------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of a binary mixture problem for a weakly-compressible fluid with an iso-thermal 
condition.

Keywords for the unknowns other than pressure, velocity, fraction_massique are :

masse_volumique : density

pression : reduced pressure

pression_tot : total pressure

pression_hydro : hydro-static pressure

pression_eos : pressure used in state equation.

Parameters are:

- **fluide_weakly_compressible**  (*type:* :ref:`fluide_weakly_compressible`) The fluid medium associated with the problem.

- **navier_stokes_wc**  (*type:* :ref:`navier_stokes_wc`) Navier-Stokes equation for a weakly-compressible fluid.

- **convection_diffusion_espece_binaire_wc**  (*type:* :ref:`convection_diffusion_espece_binaire_wc`) Species conservation equation for a binary  weakly-compressible fluid.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_hydraulique_turbulent**
----------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of Navier-Stokes equations with turbulence modelling.

Parameters are:

- **fluide_incompressible**  (*type:* :ref:`fluide_incompressible`) The fluid medium associated with the problem.

- **navier_stokes_turbulent**  (*type:* :ref:`navier_stokes_turbulent`) Navier-Stokes equations as well as the associated turbulence  model equations.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_multiphase**
-----------------
**Inherits from:** :ref:`pb_gen_base` 


A problem that allows the resolution of N-phases with 3*N equations

Parameters are:

- **[milieu_composite]**  (*type:* :ref:`bloc_lecture`) The composite medium associated with the problem.

- **[milieu_musig]**  (*type:* :ref:`bloc_lecture`) The composite medium associated with the problem.

- **[correlations]**  (*type:* :ref:`bloc_lecture`) List of correlations used in specific source terms (i.e. interfacial flux, interfacial friction, ...)

- **qdm_multiphase**  (*type:* :ref:`qdm_multiphase`) Momentum conservation equation for a multi-phase problem where the  unknown is the velocity

- **masse_multiphase**  (*type:* :ref:`masse_multiphase`) Mass consevation equation for a multi-phase problem where the unknown  is the alpha (void fraction)

- **energie_multiphase**  (*type:* :ref:`energie_multiphase`) Internal energy conservation equation for a multi-phase problem  where the unknown is the temperature

- **[energie_cinetique_turbulente]**  (*type:* :ref:`energie_cinetique_turbulente`) Turbulent kinetic Energy conservation equation for  a turbulent mono/multi-phase problem (available in TrioCFD)

- **[echelle_temporelle_turbulente]**  (*type:* :ref:`echelle_temporelle_turbulente`) Turbulent Dissipation time scale equation for a turbulent  mono/multi-phase problem (available in TrioCFD)

- **[energie_cinetique_turbulente_wit]**  (*type:* :ref:`energie_cinetique_turbulente_wit`) Bubble Induced Turbulent kinetic Energy equation  for a turbulent multi-phase problem (available in TrioCFD)

- **[taux_dissipation_turbulent]**  (*type:* :ref:`taux_dissipation_turbulent`) Turbulent Dissipation frequency equation for a turbulent  mono/multi-phase problem (available in TrioCFD)

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_multiphase_hem**
---------------------

**Synonyms:** pb_hem

**Inherits from:** :ref:`pb_gen_base` 


A problem that allows the resolution of 2-phases mechanicaly and thermally coupled 
with 3 equations

Parameters are:

- **[milieu_composite]**  (*type:* :ref:`bloc_lecture`) The composite medium associated with the problem.

- **[milieu_musig]**  (*type:* :ref:`bloc_lecture`) The composite medium associated with the problem.

- **[correlations]**  (*type:* :ref:`bloc_lecture`) List of correlations used in specific source terms (i.e. interfacial flux, interfacial friction, ...)

- **qdm_multiphase**  (*type:* :ref:`qdm_multiphase`) Momentum conservation equation for a multi-phase problem where the  unknown is the velocity

- **masse_multiphase**  (*type:* :ref:`masse_multiphase`) Mass consevation equation for a multi-phase problem where the unknown  is the alpha (void fraction)

- **energie_multiphase**  (*type:* :ref:`energie_multiphase`) Internal energy conservation equation for a multi-phase problem  where the unknown is the temperature

- **[energie_cinetique_turbulente]**  (*type:* :ref:`energie_cinetique_turbulente`) Turbulent kinetic Energy conservation equation for  a turbulent mono/multi-phase problem (available in TrioCFD)

- **[echelle_temporelle_turbulente]**  (*type:* :ref:`echelle_temporelle_turbulente`) Turbulent Dissipation time scale equation for a turbulent  mono/multi-phase problem (available in TrioCFD)

- **[energie_cinetique_turbulente_wit]**  (*type:* :ref:`energie_cinetique_turbulente_wit`) Bubble Induced Turbulent kinetic Energy equation  for a turbulent multi-phase problem (available in TrioCFD)

- **[taux_dissipation_turbulent]**  (*type:* :ref:`taux_dissipation_turbulent`) Turbulent Dissipation frequency equation for a turbulent  mono/multi-phase problem (available in TrioCFD)

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_post**
-----------
**Inherits from:** :ref:`pb_gen_base` 


not_set

Parameters are:

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_thermohydraulique**
------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of thermohydraulic problem.

Parameters are:

- **[fluide_incompressible]**  (*type:* :ref:`fluide_incompressible`) The fluid medium associated with the problem (only one possibility).

- **[fluide_ostwald]**  (*type:* :ref:`fluide_ostwald`) The fluid medium associated with the problem (only one possibility).

- **[fluide_sodium_liquide]**  (*type:* :ref:`fluide_sodium_liquide`) The fluid medium associated with the problem (only one possibility).

- **[fluide_sodium_gaz]**  (*type:* :ref:`fluide_sodium_gaz`) The fluid medium associated with the problem (only one possibility).

- **[navier_stokes_standard]**  (*type:* :ref:`navier_stokes_standard`) Navier-Stokes equations.

- **[convection_diffusion_temperature]**  (*type:* :ref:`convection_diffusion_temperature`) Energy equation (temperature diffusion convection).

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_thermohydraulique_concentration**
--------------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of Navier-Stokes/energy/multiple constituent transport equations.

Parameters are:

- **fluide_incompressible**  (*type:* :ref:`fluide_incompressible`) The fluid medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituents.

- **[navier_stokes_standard]**  (*type:* :ref:`navier_stokes_standard`) Navier-Stokes equations.

- **[convection_diffusion_concentration]**  (*type:* :ref:`convection_diffusion_concentration`) Constituent transport equations (concentration  diffusion convection).

- **[convection_diffusion_temperature]**  (*type:* :ref:`convection_diffusion_temperature`) Energy equation (temperature diffusion convection).

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_thermohydraulique_concentration_scalaires_passifs**
--------------------------------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of Navier-Stokes/energy/multiple constituent transport equations, with 
the additional passive scalar equations.

Parameters are:

- **fluide_incompressible**  (*type:* :ref:`fluide_incompressible`) The fluid medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituents.

- **[navier_stokes_standard]**  (*type:* :ref:`navier_stokes_standard`) Navier-Stokes equations.

- **[convection_diffusion_concentration]**  (*type:* :ref:`convection_diffusion_concentration`) Constituent transport equations (concentration  diffusion convection).

- **[convection_diffusion_temperature]**  (*type:* :ref:`convection_diffusion_temperature`) Energy equations (temperature diffusion convection).

- **equations_scalaires_passifs**  (*type:* :ref:`listeqn`) Passive scalar equations. The unknowns of the passive scalar equation number N are named temperatureN or concentrationN  or fraction_massiqueN. This keyword is used to define initial conditions and the post processing fields. This kind of problem is very useful to test in only one data file (and then only  one calculation) different schemes or different boundary conditions for the scalar  transport equation.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_thermohydraulique_concentration_turbulent**
------------------------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of Navier-Stokes/energy/multiple constituent transport equations, with 
turbulence modelling.

Parameters are:

- **fluide_incompressible**  (*type:* :ref:`fluide_incompressible`) The fluid medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituents.

- **[navier_stokes_turbulent]**  (*type:* :ref:`navier_stokes_turbulent`) Navier-Stokes equations as well as the associated turbulence  model equations.

- **[convection_diffusion_concentration_turbulent]**  (*type:* :ref:`convection_diffusion_concentration_turbulent`) Constituent transport equations (concentration  diffusion convection) as well as the associated turbulence model equations.

- **[convection_diffusion_temperature_turbulent]**  (*type:* :ref:`convection_diffusion_temperature_turbulent`) Energy equation (temperature diffusion  convection) as well as the associated turbulence model equations.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_thermohydraulique_concentration_turbulent_scalaires_passifs**
------------------------------------------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of Navier-Stokes/energy/multiple constituent transport equations, with 
turbulence modelling and with the additional passive scalar equations.

Parameters are:

- **fluide_incompressible**  (*type:* :ref:`fluide_incompressible`) The fluid medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituents.

- **[navier_stokes_turbulent]**  (*type:* :ref:`navier_stokes_turbulent`) Navier-Stokes equations as well as the associated turbulence  model equations.

- **[convection_diffusion_concentration_turbulent]**  (*type:* :ref:`convection_diffusion_concentration_turbulent`) Constituent transport equations (concentration  diffusion convection) as well as the associated turbulence model equations.

- **[convection_diffusion_temperature_turbulent]**  (*type:* :ref:`convection_diffusion_temperature_turbulent`) Energy equations (temperature diffusion  convection) as well as the associated turbulence model equations.

- **equations_scalaires_passifs**  (*type:* :ref:`listeqn`) Passive scalar equations. The unknowns of the passive scalar equation number N are named temperatureN or concentrationN  or fraction_massiqueN. This keyword is used to define initial conditions and the post processing fields. This kind of problem is very useful to test in only one data file (and then only  one calculation) different schemes or different boundary conditions for the scalar  transport equation.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_thermohydraulique_especes_qc**
-----------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of thermo-hydraulic problem for a multi-species quasi-compressible fluid.

Parameters are:

- **fluide_quasi_compressible**  (*type:* :ref:`fluide_quasi_compressible`) The fluid medium associated with the problem.

- **navier_stokes_qc**  (*type:* :ref:`navier_stokes_qc`) Navier-Stokes equation for a quasi-compressible fluid.

- **convection_diffusion_chaleur_qc**  (*type:* :ref:`convection_diffusion_chaleur_qc`) Temperature equation for a quasi-compressible fluid.

- **equations_scalaires_passifs**  (*type:* :ref:`listeqn`) Passive scalar equations. The unknowns of the passive scalar equation number N are named temperatureN or concentrationN  or fraction_massiqueN. This keyword is used to define initial conditions and the post processing fields. This kind of problem is very useful to test in only one data file (and then only  one calculation) different schemes or different boundary conditions for the scalar  transport equation.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_thermohydraulique_especes_turbulent_qc**
---------------------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of turbulent thermohydraulic problem under low Mach number with passive 
scalar equations.

Parameters are:

- **fluide_quasi_compressible**  (*type:* :ref:`fluide_quasi_compressible`) The fluid medium associated with the problem.

- **navier_stokes_turbulent_qc**  (*type:* :ref:`navier_stokes_turbulent_qc`) Navier-Stokes equations under low Mach number as well  as the associated turbulence model equations.

- **convection_diffusion_chaleur_turbulent_qc**  (*type:* :ref:`convection_diffusion_chaleur_turbulent_qc`) Energy equation under low Mach number  as well as the associated turbulence model equations.

- **equations_scalaires_passifs**  (*type:* :ref:`listeqn`) Passive scalar equations. The unknowns of the passive scalar equation number N are named temperatureN or concentrationN  or fraction_massiqueN. This keyword is used to define initial conditions and the post processing fields. This kind of problem is very useful to test in only one data file (and then only  one calculation) different schemes or different boundary conditions for the scalar  transport equation.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_thermohydraulique_especes_wc**
-----------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of thermo-hydraulic problem for a multi-species weakly-compressible fluid.

Parameters are:

- **fluide_weakly_compressible**  (*type:* :ref:`fluide_weakly_compressible`) The fluid medium associated with the problem.

- **navier_stokes_wc**  (*type:* :ref:`navier_stokes_wc`) Navier-Stokes equation for a weakly-compressible fluid.

- **convection_diffusion_chaleur_wc**  (*type:* :ref:`convection_diffusion_chaleur_wc`) Temperature equation for a weakly-compressible fluid.

- **equations_scalaires_passifs**  (*type:* :ref:`listeqn`) Passive scalar equations. The unknowns of the passive scalar equation number N are named temperatureN or concentrationN  or fraction_massiqueN. This keyword is used to define initial conditions and the post processing fields. This kind of problem is very useful to test in only one data file (and then only  one calculation) different schemes or different boundary conditions for the scalar  transport equation.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_thermohydraulique_qc**
---------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of thermo-hydraulic problem for a quasi-compressible fluid.

Keywords for the unknowns other than pressure, velocity, temperature are :

masse_volumique : density

enthalpie : enthalpy

pression : reduced pressure

pression_tot : total pressure.

Parameters are:

- **fluide_quasi_compressible**  (*type:* :ref:`fluide_quasi_compressible`) The fluid medium associated with the problem.

- **navier_stokes_qc**  (*type:* :ref:`navier_stokes_qc`) Navier-Stokes equation for a quasi-compressible fluid.

- **convection_diffusion_chaleur_qc**  (*type:* :ref:`convection_diffusion_chaleur_qc`) Temperature equation for a quasi-compressible fluid.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_thermohydraulique_scalaires_passifs**
------------------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of thermohydraulic problem, with the additional passive scalar equations.

Parameters are:

- **fluide_incompressible**  (*type:* :ref:`fluide_incompressible`) The fluid medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituents.

- **[navier_stokes_standard]**  (*type:* :ref:`navier_stokes_standard`) Navier-Stokes equations.

- **[convection_diffusion_temperature]**  (*type:* :ref:`convection_diffusion_temperature`) Energy equations (temperature diffusion convection).

- **equations_scalaires_passifs**  (*type:* :ref:`listeqn`) Passive scalar equations. The unknowns of the passive scalar equation number N are named temperatureN or concentrationN  or fraction_massiqueN. This keyword is used to define initial conditions and the post processing fields. This kind of problem is very useful to test in only one data file (and then only  one calculation) different schemes or different boundary conditions for the scalar  transport equation.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_thermohydraulique_turbulent**
----------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of thermohydraulic problem, with turbulence modelling.

Parameters are:

- **fluide_incompressible**  (*type:* :ref:`fluide_incompressible`) The fluid medium associated with the problem.

- **navier_stokes_turbulent**  (*type:* :ref:`navier_stokes_turbulent`) Navier-Stokes equations as well as the associated turbulence  model equations.

- **convection_diffusion_temperature_turbulent**  (*type:* :ref:`convection_diffusion_temperature_turbulent`) Energy equation (temperature diffusion  convection) as well as the associated turbulence model equations.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_thermohydraulique_turbulent_qc**
-------------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of turbulent thermohydraulic problem under low Mach number.

Warning : Available for VDF and VEF P0/P1NC discretization only.

Parameters are:

- **fluide_quasi_compressible**  (*type:* :ref:`fluide_quasi_compressible`) The fluid medium associated with the problem.

- **navier_stokes_turbulent_qc**  (*type:* :ref:`navier_stokes_turbulent_qc`) Navier-Stokes equations under low Mach number as well  as the associated turbulence model equations.

- **convection_diffusion_chaleur_turbulent_qc**  (*type:* :ref:`convection_diffusion_chaleur_turbulent_qc`) Energy equation under low Mach number  as well as the associated turbulence model equations.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_thermohydraulique_turbulent_scalaires_passifs**
----------------------------------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of thermohydraulic problem, with turbulence modelling and with the additional 
passive scalar equations.

Parameters are:

- **fluide_incompressible**  (*type:* :ref:`fluide_incompressible`) The fluid medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituents.

- **[navier_stokes_turbulent]**  (*type:* :ref:`navier_stokes_turbulent`) Navier-Stokes equations as well as the associated turbulence  model equations.

- **[convection_diffusion_temperature_turbulent]**  (*type:* :ref:`convection_diffusion_temperature_turbulent`) Energy equations (temperature diffusion  convection) as well as the associated turbulence model equations.

- **equations_scalaires_passifs**  (*type:* :ref:`listeqn`) Passive scalar equations. The unknowns of the passive scalar equation number N are named temperatureN or concentrationN  or fraction_massiqueN. This keyword is used to define initial conditions and the post processing fields. This kind of problem is very useful to test in only one data file (and then only  one calculation) different schemes or different boundary conditions for the scalar  transport equation.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pb_thermohydraulique_wc**
---------------------------
**Inherits from:** :ref:`pb_gen_base` 


Resolution of thermo-hydraulic problem for a weakly-compressible fluid.

Keywords for the unknowns other than pressure, velocity, temperature are :

masse_volumique : density

pression : reduced pressure

pression_tot : total pressure

pression_hydro : hydro-static pressure

pression_eos : pressure used in state equation.

Parameters are:

- **fluide_weakly_compressible**  (*type:* :ref:`fluide_weakly_compressible`) The fluid medium associated with the problem.

- **navier_stokes_wc**  (*type:* :ref:`navier_stokes_wc`) Navier-Stokes equation for a weakly-compressible fluid.

- **convection_diffusion_chaleur_wc**  (*type:* :ref:`convection_diffusion_chaleur_wc`) Temperature equation for a weakly-compressible fluid.

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).


----

**pbc_med**
-----------
**Inherits from:** :ref:`pb_gen_base` 


Allows to read med files and post-process them.

Parameters are:

- **list_info_med**  (*type:* :ref:`list_info_med`) not_set


----

**problem_read_generic**
------------------------
**Inherits from:** :ref:`pb_gen_base` 


The probleme_read_generic differs rom the rest of the TRUST code : The problem does 
not state the number of equations that are enclosed in the problem.
As the list of equations to be solved in the generic read problem is declared in 
the data file and not pre-defined in the structure of the problem, each equation has 
to be distinctively associated with the problem with the Associate keyword.

Parameters are:

- **[milieu]**  (*type:* :ref:`milieu_base`) The medium associated with the problem.

- **[constituant]**  (*type:* :ref:`constituant`) Constituent.

- **[postraitement | post_processing]**  (*type:* :ref:`corps_postraitement`) One post-processing (without name).

- **[postraitements | post_processings]**  (*type:* :ref:`postraitements`) List of Postraitement objects (with name).

- **[liste_de_postraitements]**  (*type:* :ref:`liste_post_ok`) This

- **[liste_postraitements]**  (*type:* :ref:`liste_post`) This block defines the output files to be written during the computation. The output format is lata in order to use OpenDX to draw the results. This block can be divided in one or several sub-blocks that can be written at different  frequencies and in different directories. Attention. The directory lata used in this example should be created before running the computation  or the lata files will be lost.

- **[sauvegarde]**  (*type:* :ref:`format_file`) Keyword used when calculation results are to be backed up. When a coupling is performed, the backup-recovery file name must be well specified  for each problem. In this case, you must save to different files and correctly specify these files  when resuming the calculation.

- **[sauvegarde_simple]**  (*type:* :ref:`format_file`) The same keyword than Sauvegarde except, the last time step only is  saved.

- **[reprise]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file (see the  class format_file). If format_reprise is xyz, the name_file file should be the .xyz file created by the  previous calculation. With this file, it is possible to resume a parallel calculation on P processors,  whereas the previous calculation has been run on N (N<>P) processors. Should the calculation be resumed, values for the tinit (see schema_temps_base) time  fields are taken from the name_file file. If there is no backup corresponding to this time in the name_file, TRUST exits in  error.

- **[resume_last_time]**  (*type:* :ref:`format_file`) Keyword to resume a calculation based on the name_file file, resume  the calculation at the last time found in the file (tinit is set to last time of saved  files).

