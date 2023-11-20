schema_temps_base
=================

**euler_scheme**
----------------

**Synonyms:** scheme_euler_explicit, schema_euler_explicite

**Inherits from:** :ref:`schema_temps_base` 


This is the Euler explicit scheme.

Parameters are:

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**leap_frog**
-------------
**Inherits from:** :ref:`schema_temps_base` 


This is the leap-frog scheme.

Parameters are:

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**runge_kutta_ordre_2**
-----------------------
**Inherits from:** :ref:`schema_temps_base` 


This is a low-storage Runge-Kutta scheme of second order that uses 2 integration points.
The method is presented by Williamson (case 1) in https://www.sciencedirect.com/science/article/pii/0021999180900339

Parameters are:

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**runge_kutta_ordre_2_classique**
---------------------------------
**Inherits from:** :ref:`schema_temps_base` 


This is a classical Runge-Kutta scheme of second order that uses 2 integration points.

Parameters are:

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**runge_kutta_ordre_3**
-----------------------
**Inherits from:** :ref:`schema_temps_base` 


This is a low-storage Runge-Kutta scheme of third order that uses 3 integration points.
The method is presented by Williamson (case 7) in https://www.sciencedirect.com/science/article/pii/0021999180900339

Parameters are:

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**runge_kutta_ordre_3_classique**
---------------------------------
**Inherits from:** :ref:`schema_temps_base` 


This is a classical Runge-Kutta scheme of third order that uses 3 integration points.

Parameters are:

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**runge_kutta_ordre_4**
-----------------------

**Synonyms:** runge_kutta_ordre_4_d3p

**Inherits from:** :ref:`schema_temps_base` 


This is a low-storage Runge-Kutta scheme of fourth order that uses 3 integration points.
The method is presented by Williamson (case 17) in https://www.sciencedirect.com/science/article/pii/0021999180900339

Parameters are:

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**runge_kutta_ordre_4_classique_3_8**
-------------------------------------
**Inherits from:** :ref:`schema_temps_base` 


This is a classical Runge-Kutta scheme of fourth order that uses 4 integration points 
and the 3/8 rule.

Parameters are:

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**runge_kutta_ordre_4_classique**
---------------------------------
**Inherits from:** :ref:`schema_temps_base` 


This is a classical Runge-Kutta scheme of fourth order that uses 4 integration points.

Parameters are:

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**runge_kutta_rationnel_ordre_2**
---------------------------------
**Inherits from:** :ref:`schema_temps_base` 


This is the Runge-Kutta rational scheme of second order.
The method is described in the note: Wambeck - Rational Runge-Kutta methods for solving 
systems of ordinary differential equations, at the link: https://link.springer.com/article/10.1007/BF02252381.
Although rational methods require more computational work than linear ones, they 
can have some other properties, such as a stable behaviour with explicitness, which 
make them preferable.
The CFD application of this RRK2 scheme is described in the note: https://link.springer.com/content/pdf/10.1007\%2F3-540-13917-6_112.pdf.

Parameters are:

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**sch_cn_ex_iteratif**
----------------------
**Inherits from:** :ref:`schema_temps_base` 


This keyword also describes a Crank-Nicholson method of second order accuracy but 
here, for scalars, because of instablities encountered when dt>dt_CFL, the Crank Nicholson 
scheme is not applied to scalar quantities.
Scalars are treated according to Euler-Explicite scheme at the end of the CN treatment 
for velocity flow fields (by doing p Euler explicite under-iterations at dt<=dt_CFL).
Parameters are the sames (but default values may change) compare to the Sch_CN_iterative 
scheme plus a relaxation keyword: niter_min (2 by default), niter_max (6 by default), 
niter_avg (3 by default), facsec_max (20 by default), seuil (0.05 by default)

Parameters are:

- **[omega]**  (*type:* double) relaxation factor (0.1 by default)

- **[niter_min]**  (*type:* int) minimal number of p-iterations to satisfy convergence criteria (2 by default)

- **[niter_max]**  (*type:* int) number of maximum p-iterations allowed to satisfy convergence criteria (6  by default)

- **[niter_avg]**  (*type:* int) threshold of p-iterations (3 by default). If the number of p-iterations is greater than niter_avg, facsec is reduced, if lesser  than niter_avg, facsec is increased (but limited by the facsec_max value).

- **[facsec_max]**  (*type:* double) maximum ratio allowed between dynamical time step returned by iterative  process and stability time returned by CFL condition (2 by default).

- **[seuil]**  (*type:* double) criteria for ending iterative process (Max( || u(p) - u(p-1)||/Max ||  u(p) ||) < seuil) (0.001 by default)

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**sch_cn_iteratif**
-------------------
**Inherits from:** :ref:`schema_temps_base` 


The Crank-Nicholson method of second order accuracy.
A mid-point rule formulation is used (Euler-centered scheme).
The basic scheme is: $$u(t+1) = u(t) + du/dt(t+1/2)*dt$$ The estimation of the time 
derivative du/dt at the level (t+1/2) is obtained either by iterative process.
The time derivative du/dt at the level (t+1/2) is calculated iteratively with a simple 
under-relaxations method.
Since the method is implicit, neither the cfl nor the fourier stability criteria 
must be respected.
The time step is calculated in a way that the iterative procedure converges with 
the less iterations as possible.

Remark : for stationary or RANS calculations, no limitation can be given for time 
step through high value of facsec_max parameter (for instance : facsec_max 1000).
In counterpart, for LES calculations, high values of facsec_max may engender numerical 
instabilities.

Parameters are:

- **[niter_min]**  (*type:* int) minimal number of p-iterations to satisfy convergence criteria (2 by default)

- **[niter_max]**  (*type:* int) number of maximum p-iterations allowed to satisfy convergence criteria (6  by default)

- **[niter_avg]**  (*type:* int) threshold of p-iterations (3 by default). If the number of p-iterations is greater than niter_avg, facsec is reduced, if lesser  than niter_avg, facsec is increased (but limited by the facsec_max value).

- **[facsec_max]**  (*type:* double) maximum ratio allowed between dynamical time step returned by iterative  process and stability time returned by CFL condition (2 by default).

- **[seuil]**  (*type:* double) criteria for ending iterative process (Max( || u(p) - u(p-1)||/Max ||  u(p) ||) < seuil) (0.001 by default)

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**schema_adams_bashforth_order_2**
----------------------------------
**Inherits from:** :ref:`schema_temps_base` 


not_set

Parameters are:

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**schema_adams_bashforth_order_3**
----------------------------------
**Inherits from:** :ref:`schema_temps_base` 


not_set

Parameters are:

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**schema_adams_moulton_order_2**
--------------------------------
**Inherits from:** :ref:`schema_temps_base` 


not_set

Parameters are:

- **[facsec_max]**  (*type:* double) Maximum ratio allowed between time step and stability time returned by  CFL condition. The initial ratio given by facsec keyword is changed during the calculation with  the implicit scheme but it couldn't be higher than facsec_max value.NL2 Warning: Some  implicit schemes do not permit high facsec_max, example Schema_Adams_Moulton_order_3  needs facsec=facsec_max=1.  Advice:NL2 The calculation may start with a facsec specified by the user and increased  by the algorithm up to the facsec_max limit. But the user can also choose to specify a constant facsec (facsec_max will be set  to facsec value then). Faster convergence has been seen and depends on the kind of calculation: NL2-Hydraulic  only or thermal hydraulic with forced convection and low coupling between velocity  and temperature (Boussinesq value beta low), facsec between 20-30NL2-Thermal hydraulic  with forced convection and strong coupling between velocity and temperature (Boussinesq  value beta high), facsec between 90-100 NL2-Thermohydralic with natural convection,  facsec around 300NL2 -Conduction only, facsec can be set to a very high value (1e8)  as if the scheme was unconditionally stableNL2These values can also be used as rule  of thumb for initial facsec with a facsec_max limit higher.

- **[max_iter_implicite]**  (*type:* int) Maximum number of iterations allowed for the solver (by default 200).

- **solveur**  (*type:* :ref:`solveur_implicite_base`) This keyword is used to designate the solver selected in  the situation where the time scheme is an implicit scheme. solver is the name of the solver that allows equation diffusion and convection operators  to be set as implicit terms. Keywords corresponding to this functionality are Simple (SIMPLE type algorithm),  Simpler (SIMPLER type algorithm) for incompressible systems, Piso (Pressure Implicit  with Split Operator), and Implicite (similar to PISO, but as it looks like a simplified  solver, it will use fewer timesteps, and ICE (for PB_multiphase). But it may run faster because the pressure matrix is not re-assembled and thus provides  CPU gains.  Advice: Since the 1.6.0 version, we recommend to use first the Implicite or Simple,  then Piso, and at least Simpler. Because the two first give a fastest convergence (several times) than Piso and the  Simpler has not been validated. It seems also than Implicite and Piso schemes give better results than the Simple  scheme when the flow is not fully stationary. Thus, if the solution obtained with Simple is not stationary, it is recommended to  switch to Piso or Implicite scheme.

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**schema_adams_moulton_order_3**
--------------------------------
**Inherits from:** :ref:`schema_temps_base` 


not_set

Parameters are:

- **[facsec_max]**  (*type:* double) Maximum ratio allowed between time step and stability time returned by  CFL condition. The initial ratio given by facsec keyword is changed during the calculation with  the implicit scheme but it couldn't be higher than facsec_max value.NL2 Warning: Some  implicit schemes do not permit high facsec_max, example Schema_Adams_Moulton_order_3  needs facsec=facsec_max=1.  Advice:NL2 The calculation may start with a facsec specified by the user and increased  by the algorithm up to the facsec_max limit. But the user can also choose to specify a constant facsec (facsec_max will be set  to facsec value then). Faster convergence has been seen and depends on the kind of calculation: NL2-Hydraulic  only or thermal hydraulic with forced convection and low coupling between velocity  and temperature (Boussinesq value beta low), facsec between 20-30NL2-Thermal hydraulic  with forced convection and strong coupling between velocity and temperature (Boussinesq  value beta high), facsec between 90-100 NL2-Thermohydralic with natural convection,  facsec around 300NL2 -Conduction only, facsec can be set to a very high value (1e8)  as if the scheme was unconditionally stableNL2These values can also be used as rule  of thumb for initial facsec with a facsec_max limit higher.

- **[max_iter_implicite]**  (*type:* int) Maximum number of iterations allowed for the solver (by default 200).

- **solveur**  (*type:* :ref:`solveur_implicite_base`) This keyword is used to designate the solver selected in  the situation where the time scheme is an implicit scheme. solver is the name of the solver that allows equation diffusion and convection operators  to be set as implicit terms. Keywords corresponding to this functionality are Simple (SIMPLE type algorithm),  Simpler (SIMPLER type algorithm) for incompressible systems, Piso (Pressure Implicit  with Split Operator), and Implicite (similar to PISO, but as it looks like a simplified  solver, it will use fewer timesteps, and ICE (for PB_multiphase). But it may run faster because the pressure matrix is not re-assembled and thus provides  CPU gains.  Advice: Since the 1.6.0 version, we recommend to use first the Implicite or Simple,  then Piso, and at least Simpler. Because the two first give a fastest convergence (several times) than Piso and the  Simpler has not been validated. It seems also than Implicite and Piso schemes give better results than the Simple  scheme when the flow is not fully stationary. Thus, if the solution obtained with Simple is not stationary, it is recommended to  switch to Piso or Implicite scheme.

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**schema_backward_differentiation_order_2**
-------------------------------------------
**Inherits from:** :ref:`schema_temps_base` 


not_set

Parameters are:

- **[facsec_max]**  (*type:* double) Maximum ratio allowed between time step and stability time returned by  CFL condition. The initial ratio given by facsec keyword is changed during the calculation with  the implicit scheme but it couldn't be higher than facsec_max value.NL2 Warning: Some  implicit schemes do not permit high facsec_max, example Schema_Adams_Moulton_order_3  needs facsec=facsec_max=1.  Advice:NL2 The calculation may start with a facsec specified by the user and increased  by the algorithm up to the facsec_max limit. But the user can also choose to specify a constant facsec (facsec_max will be set  to facsec value then). Faster convergence has been seen and depends on the kind of calculation: NL2-Hydraulic  only or thermal hydraulic with forced convection and low coupling between velocity  and temperature (Boussinesq value beta low), facsec between 20-30NL2-Thermal hydraulic  with forced convection and strong coupling between velocity and temperature (Boussinesq  value beta high), facsec between 90-100 NL2-Thermohydralic with natural convection,  facsec around 300NL2 -Conduction only, facsec can be set to a very high value (1e8)  as if the scheme was unconditionally stableNL2These values can also be used as rule  of thumb for initial facsec with a facsec_max limit higher.

- **[max_iter_implicite]**  (*type:* int) Maximum number of iterations allowed for the solver (by default 200).

- **solveur**  (*type:* :ref:`solveur_implicite_base`) This keyword is used to designate the solver selected in  the situation where the time scheme is an implicit scheme. solver is the name of the solver that allows equation diffusion and convection operators  to be set as implicit terms. Keywords corresponding to this functionality are Simple (SIMPLE type algorithm),  Simpler (SIMPLER type algorithm) for incompressible systems, Piso (Pressure Implicit  with Split Operator), and Implicite (similar to PISO, but as it looks like a simplified  solver, it will use fewer timesteps, and ICE (for PB_multiphase). But it may run faster because the pressure matrix is not re-assembled and thus provides  CPU gains.  Advice: Since the 1.6.0 version, we recommend to use first the Implicite or Simple,  then Piso, and at least Simpler. Because the two first give a fastest convergence (several times) than Piso and the  Simpler has not been validated. It seems also than Implicite and Piso schemes give better results than the Simple  scheme when the flow is not fully stationary. Thus, if the solution obtained with Simple is not stationary, it is recommended to  switch to Piso or Implicite scheme.

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**schema_backward_differentiation_order_3**
-------------------------------------------
**Inherits from:** :ref:`schema_temps_base` 


not_set

Parameters are:

- **[facsec_max]**  (*type:* double) Maximum ratio allowed between time step and stability time returned by  CFL condition. The initial ratio given by facsec keyword is changed during the calculation with  the implicit scheme but it couldn't be higher than facsec_max value.NL2 Warning: Some  implicit schemes do not permit high facsec_max, example Schema_Adams_Moulton_order_3  needs facsec=facsec_max=1.  Advice:NL2 The calculation may start with a facsec specified by the user and increased  by the algorithm up to the facsec_max limit. But the user can also choose to specify a constant facsec (facsec_max will be set  to facsec value then). Faster convergence has been seen and depends on the kind of calculation: NL2-Hydraulic  only or thermal hydraulic with forced convection and low coupling between velocity  and temperature (Boussinesq value beta low), facsec between 20-30NL2-Thermal hydraulic  with forced convection and strong coupling between velocity and temperature (Boussinesq  value beta high), facsec between 90-100 NL2-Thermohydralic with natural convection,  facsec around 300NL2 -Conduction only, facsec can be set to a very high value (1e8)  as if the scheme was unconditionally stableNL2These values can also be used as rule  of thumb for initial facsec with a facsec_max limit higher.

- **[max_iter_implicite]**  (*type:* int) Maximum number of iterations allowed for the solver (by default 200).

- **solveur**  (*type:* :ref:`solveur_implicite_base`) This keyword is used to designate the solver selected in  the situation where the time scheme is an implicit scheme. solver is the name of the solver that allows equation diffusion and convection operators  to be set as implicit terms. Keywords corresponding to this functionality are Simple (SIMPLE type algorithm),  Simpler (SIMPLER type algorithm) for incompressible systems, Piso (Pressure Implicit  with Split Operator), and Implicite (similar to PISO, but as it looks like a simplified  solver, it will use fewer timesteps, and ICE (for PB_multiphase). But it may run faster because the pressure matrix is not re-assembled and thus provides  CPU gains.  Advice: Since the 1.6.0 version, we recommend to use first the Implicite or Simple,  then Piso, and at least Simpler. Because the two first give a fastest convergence (several times) than Piso and the  Simpler has not been validated. It seems also than Implicite and Piso schemes give better results than the Simple  scheme when the flow is not fully stationary. Thus, if the solution obtained with Simple is not stationary, it is recommended to  switch to Piso or Implicite scheme.

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**schema_euler_implicite**
--------------------------

**Synonyms:** scheme_euler_implicit

**Inherits from:** :ref:`schema_temps_base` 


This is the Euler implicit scheme.

Parameters are:

- **[facsec_max]**  (*type:* double) 1 Maximum ratio allowed between time step and stability time returned  by CFL condition. The initial ratio given by facsec keyword is changed during the calculation with  the implicit scheme but it couldn't be higher than facsec_max value.NL2 Warning: Some  implicit schemes do not permit high facsec_max, example Schema_Adams_Moulton_order_3  needs facsec=facsec_max=1.  Advice:NL2 The calculation may start with a facsec specified by the user and increased  by the algorithm up to the facsec_max limit. But the user can also choose to specify a constant facsec (facsec_max will be set  to facsec value then). Faster convergence has been seen and depends on the kind of calculation: NL2-Hydraulic  only or thermal hydraulic with forced convection and low coupling between velocity  and temperature (Boussinesq value beta low), facsec between 20-30NL2-Thermal hydraulic  with forced convection and strong coupling between velocity and temperature (Boussinesq  value beta high), facsec between 90-100 NL2-Thermohydralic with natural convection,  facsec around 300NL2 -Conduction only, facsec can be set to a very high value (1e8)  as if the scheme was unconditionally stableNL2These values can also be used as rule  of thumb for initial facsec with a facsec_max limit higher.

- **[resolution_monolithique]**  (*type:* :ref:`bloc_lecture`) Activate monolithic resolution for coupled problems. Solves together the equations corresponding to the application domains in the given  order. All aplication domains of the coupled equations must be given to determine the order  of resolution. If the monolithic solving is not wanted for a specific application domain, an underscore  can be added as prefix. For example, resolution_monolithique { dom1 { dom2 dom3 } _dom4 } will solve in a  single matrix the equations having dom1 as application domain, then the equations  having dom2 or dom3 as application domain in a single matrix, then the equations having  dom4 as application domain in a sequential way (not in a single matrix).

- **[max_iter_implicite]**  (*type:* int) Maximum number of iterations allowed for the solver (by default 200).

- **solveur**  (*type:* :ref:`solveur_implicite_base`) This keyword is used to designate the solver selected in  the situation where the time scheme is an implicit scheme. solver is the name of the solver that allows equation diffusion and convection operators  to be set as implicit terms. Keywords corresponding to this functionality are Simple (SIMPLE type algorithm),  Simpler (SIMPLER type algorithm) for incompressible systems, Piso (Pressure Implicit  with Split Operator), and Implicite (similar to PISO, but as it looks like a simplified  solver, it will use fewer timesteps, and ICE (for PB_multiphase). But it may run faster because the pressure matrix is not re-assembled and thus provides  CPU gains.  Advice: Since the 1.6.0 version, we recommend to use first the Implicite or Simple,  then Piso, and at least Simpler. Because the two first give a fastest convergence (several times) than Piso and the  Simpler has not been validated. It seems also than Implicite and Piso schemes give better results than the Simple  scheme when the flow is not fully stationary. Thus, if the solution obtained with Simple is not stationary, it is recommended to  switch to Piso or Implicite scheme.

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**schema_implicite_base**
-------------------------
**Inherits from:** :ref:`schema_temps_base` 


Basic class for implicite time scheme.

Parameters are:

- **[max_iter_implicite]**  (*type:* int) Maximum number of iterations allowed for the solver (by default 200).

- **solveur**  (*type:* :ref:`solveur_implicite_base`) This keyword is used to designate the solver selected in  the situation where the time scheme is an implicit scheme. solver is the name of the solver that allows equation diffusion and convection operators  to be set as implicit terms. Keywords corresponding to this functionality are Simple (SIMPLE type algorithm),  Simpler (SIMPLER type algorithm) for incompressible systems, Piso (Pressure Implicit  with Split Operator), and Implicite (similar to PISO, but as it looks like a simplified  solver, it will use fewer timesteps, and ICE (for PB_multiphase). But it may run faster because the pressure matrix is not re-assembled and thus provides  CPU gains.  Advice: Since the 1.6.0 version, we recommend to use first the Implicite or Simple,  then Piso, and at least Simpler. Because the two first give a fastest convergence (several times) than Piso and the  Simpler has not been validated. It seems also than Implicite and Piso schemes give better results than the Simple  scheme when the flow is not fully stationary. Thus, if the solution obtained with Simple is not stationary, it is recommended to  switch to Piso or Implicite scheme.

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**schema_predictor_corrector**
------------------------------
**Inherits from:** :ref:`schema_temps_base` 


This is the predictor-corrector scheme (second order).
It is more accurate and economic than MacCormack scheme.
It gives best results with a second ordre convective scheme like quick, centre (VDF).

Parameters are:

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.


----

**schema_temps_base**
---------------------
**Inherits from:** :ref:`schema_temps_base` 


Basic class for time schemes.
This scheme will be associated with a problem and the equations of this problem.

Parameters are:

- **[tinit]**  (*type:* double) Value of initial calculation time (0 by default).

- **[tmax]**  (*type:* double) Time during which the calculation will be stopped (1e30s by default).

- **[tcpumax]**  (*type:* double) CPU time limit (must be specified in hours) for which the calculation  is stopped (1e30s by default).

- **[dt_min]**  (*type:* double) Minimum calculation time step (1e-16s by default).

- **[dt_max]**  (*type:* string) Maximum calculation time step as function of time (1e30s by default).

- **[dt_sauv]**  (*type:* double) Save time step value (1e30s by default). Every dt_sauv, fields are saved in the .sauv file. The file contains all the information saved over time. If this instruction is not entered, results are saved only upon calculation completion. To disable the writing of the .sauv files, you must specify 0. Note that dt_sauv is in terms of physical time (not cpu time).

- **[dt_impr]**  (*type:* double) Scheme parameter printing time step in time (1e30s by default). The time steps and the flux balances are printed (incorporated onto every side of  processed domains) into the .out file.

- **[facsec]**  (*type:* double) Value assigned to the safety factor for the time step (1. by default). The time step calculated is multiplied by the safety factor. The first thing to try when a calculation does not converge with an explicit time  scheme is to reduce the facsec to 0.5.  Warning: Some schemes needs a facsec lower than 1 (0.5 is a good start), for example  Schema_Adams_Bashforth_order_3.

- **[seuil_statio]**  (*type:* double) Value of the convergence threshold (1e-12 by default). Problems using this type of time scheme converge when the derivatives dGi/dt NL1  of all the unknown transported values Gi have a combined absolute value less than  this value. This is the keyword used to set the permanent rating threshold.

- **[residuals]**  (*type:* :ref:`residuals`) To specify how the residuals will be computed (default max norm, possible  to choose L2-norm instead).

- **[diffusion_implicite]**  (*type:* int) Keyword to make the diffusive term in the Navier-Stokes equations implicit  (in this case, it should be set to 1). The stability time step is then only based on the convection time step (dt=facsec*dt_convection). Thus, in some circumstances, an important gain is achieved with respect to the time  step (large diffusion with respect to convection on tightened meshes). Caution: It is however recommended that the user avoids exceeding the convection  time step by selecting a too large facsec value. Start with a facsec value of 1 and then increase it gradually if you wish to accelerate  calculation. In addition, for a natural convection calculation with a zero initial velocity, in  the first time step, the convection time is infinite and therefore dt=facsec*dt_max.

- **[seuil_diffusion_implicite]**  (*type:* double) This keyword changes the default value (1e-6) of convergency criteria  for the resolution by conjugate gradient used for implicit diffusion.

- **[impr_diffusion_implicite]**  (*type:* int) Unactivate (default) or not the printing of the convergence during the resolution  of the conjugate gradient.

- **[impr_extremums]**  (*type:* int) Print unknowns extremas

- **[no_error_if_not_converged_diffusion_implicite]**  (*type:* int) not_set

- **[no_conv_subiteration_diffusion_implicite]**  (*type:* int) not_set

- **[dt_start]**  (*type:* :ref:`dt_start`) dt_start dt_min : the first iteration is based on dt_min.  dt_start dt_calc : the time step at first iteration is calculated in agreement with  CFL condition.  dt_start dt_fixe value : the first time step is fixed by the user (recommended when  resuming calculation with Crank Nicholson temporal scheme to ensure continuity).  By default, the first iteration is based on dt_calc.

- **[nb_pas_dt_max]**  (*type:* int) Maximum number of calculation time steps (1e9 by default).

- **[niter_max_diffusion_implicite]**  (*type:* int) This keyword changes the default value (number of unknowns) of the maximal  iterations number in the conjugate gradient method used for implicit diffusion.

- **[precision_impr]**  (*type:* int) Optional keyword to define the digit number for flux values printed into  .out files (by default 3).

- **[periode_sauvegarde_securite_en_heures]**  (*type:* double) To change the default period (23 hours) between the save of the fields  in .sauv file.

- **[no_check_disk_space]**  (*type:* flag) To disable the check of the available amount of disk space during the calculation.

- **[disable_progress]**  (*type:* flag) To disable the writing of the .progress file.

- **[disable_dt_ev]**  (*type:* flag) To disable the writing of the .dt_ev file.

- **[gnuplot_header]**  (*type:* int) Optional keyword to modify the header of the .out files. Allows to use the column title instead of columns number.

