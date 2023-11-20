solveur_implicite_base
======================

**ice**
-------
**Inherits from:** :ref:`solveur_implicite_base` 


Implicit Continuous-fluid Eulerian solver which is useful for a multiphase problem.
Robust pressure reduction resolution.

Parameters are:

- **[pression_degeneree]**  (*type:* int) Set to 1 if the pressure field is degenerate (ex. : incompressible fluid with no imposed-pressure BCs). Default: autodetected

- **[reduction_pression | pressure_reduction]**  (*type:* int) Set to 1 if the user wants a resolution with a pressure reduction. Otherwise, the flag is to be set to 0 so that the complete matrix is considered. The default value of this flag is 1.

- **[criteres_convergence]**  (*type:* :ref:`bloc_criteres_convergence`) Set the convergence thresholds for each unknown (i.e:  alpha, temperature, velocity and pressure). The default values are respectively 0.01, 0.1, 0.01 and 100

- **[iter_min]**  (*type:* int) Number of minimum iterations

- **[seuil_convergence_implicite]**  (*type:* double) Convergence criteria.

- **[nb_corrections_max]**  (*type:* int) Maximum number of corrections performed by the PISO algorithm to achieve  the projection of the velocity field. The algorithm may perform less corrections then nb_corrections_max if the accuracy  of the projection is sufficient. (By default nb_corrections_max is set to 21).

- **[facsec_diffusion_for_sets]**  (*type:* double) facsec to impose on the diffusion time step in sets while the total time  step stays smaller than the convection time step.

- **[seuil_convergence_solveur]**  (*type:* double) value of the convergence criteria for the resolution of the implicit system  build by solving several times per time step the Navier_Stokes equation and the scalar  equations if any. This value MUST be used when a coupling between problems is considered (should be  set to a value typically of 0.1 or 0.01).

- **[seuil_generation_solveur]**  (*type:* double) Option to create a GMRES solver and use vrel as the convergence threshold  (implicit linear system Ax=B will be solved if residual error ||Ax-B|| is lesser than  vrel).

- **[seuil_verification_solveur]**  (*type:* double) Option to check if residual error ||Ax-B|| is lesser than vrel after the  implicit linear system Ax=B has been solved.

- **[seuil_test_preliminaire_solveur]**  (*type:* double) Option to decide if the implicit linear system Ax=B should be solved by  checking if the residual error ||Ax-B|| is bigger than vrel.

- **[solveur]**  (*type:* :ref:`solveur_sys_base`) Method (different from the default one, Gmres with diagonal preconditioning)  to solve the linear system.

- **[no_qdm]**  (*type:* flag) Keyword to not solve qdm equation (and turbulence models of these equation).

- **[nb_it_max]**  (*type:* int) Keyword to set the maximum iterations number for the Gmres.

- **[controle_residu]**  (*type:* flag) Keyword of Boolean type (by default 0). If set to 1, the convergence occurs if the residu suddenly increases.


----

**implicite**
-------------
**Inherits from:** :ref:`solveur_implicite_base` 


similar to PISO, but as it looks like a simplified solver, it will use fewer timesteps.
But it may run faster because the pressure matrix is not re-assembled and thus provides 
CPU gains.

Parameters are:

- **[seuil_convergence_implicite]**  (*type:* double) Convergence criteria.

- **[nb_corrections_max]**  (*type:* int) Maximum number of corrections performed by the PISO algorithm to achieve  the projection of the velocity field. The algorithm may perform less corrections then nb_corrections_max if the accuracy  of the projection is sufficient. (By default nb_corrections_max is set to 21).

- **[seuil_convergence_solveur]**  (*type:* double) value of the convergence criteria for the resolution of the implicit system  build by solving several times per time step the Navier_Stokes equation and the scalar  equations if any. This value MUST be used when a coupling between problems is considered (should be  set to a value typically of 0.1 or 0.01).

- **[seuil_generation_solveur]**  (*type:* double) Option to create a GMRES solver and use vrel as the convergence threshold  (implicit linear system Ax=B will be solved if residual error ||Ax-B|| is lesser than  vrel).

- **[seuil_verification_solveur]**  (*type:* double) Option to check if residual error ||Ax-B|| is lesser than vrel after the  implicit linear system Ax=B has been solved.

- **[seuil_test_preliminaire_solveur]**  (*type:* double) Option to decide if the implicit linear system Ax=B should be solved by  checking if the residual error ||Ax-B|| is bigger than vrel.

- **[solveur]**  (*type:* :ref:`solveur_sys_base`) Method (different from the default one, Gmres with diagonal preconditioning)  to solve the linear system.

- **[no_qdm]**  (*type:* flag) Keyword to not solve qdm equation (and turbulence models of these equation).

- **[nb_it_max]**  (*type:* int) Keyword to set the maximum iterations number for the Gmres.

- **[controle_residu]**  (*type:* flag) Keyword of Boolean type (by default 0). If set to 1, the convergence occurs if the residu suddenly increases.


----

**piso**
--------
**Inherits from:** :ref:`solveur_implicite_base` 


Piso (Pressure Implicit with Split Operator) - method to solve N_S.

Parameters are:

- **[seuil_convergence_implicite]**  (*type:* double) Convergence criteria.

- **[nb_corrections_max]**  (*type:* int) Maximum number of corrections performed by the PISO algorithm to achieve  the projection of the velocity field. The algorithm may perform less corrections then nb_corrections_max if the accuracy  of the projection is sufficient. (By default nb_corrections_max is set to 21).

- **[seuil_convergence_solveur]**  (*type:* double) value of the convergence criteria for the resolution of the implicit system  build by solving several times per time step the Navier_Stokes equation and the scalar  equations if any. This value MUST be used when a coupling between problems is considered (should be  set to a value typically of 0.1 or 0.01).

- **[seuil_generation_solveur]**  (*type:* double) Option to create a GMRES solver and use vrel as the convergence threshold  (implicit linear system Ax=B will be solved if residual error ||Ax-B|| is lesser than  vrel).

- **[seuil_verification_solveur]**  (*type:* double) Option to check if residual error ||Ax-B|| is lesser than vrel after the  implicit linear system Ax=B has been solved.

- **[seuil_test_preliminaire_solveur]**  (*type:* double) Option to decide if the implicit linear system Ax=B should be solved by  checking if the residual error ||Ax-B|| is bigger than vrel.

- **[solveur]**  (*type:* :ref:`solveur_sys_base`) Method (different from the default one, Gmres with diagonal preconditioning)  to solve the linear system.

- **[no_qdm]**  (*type:* flag) Keyword to not solve qdm equation (and turbulence models of these equation).

- **[nb_it_max]**  (*type:* int) Keyword to set the maximum iterations number for the Gmres.

- **[controle_residu]**  (*type:* flag) Keyword of Boolean type (by default 0). If set to 1, the convergence occurs if the residu suddenly increases.


----

**sets**
--------
**Inherits from:** :ref:`solveur_implicite_base` 


Stability-Enhancing Two-Step solver which is useful for a multiphase problem.
Ref : J.
H.
MAHAFFY, A stability-enhancing two-step method for fluid flow calculations, Journal 
of Computational Physics, 46, 3, 329 (1982).

Parameters are:

- **[criteres_convergence]**  (*type:* :ref:`bloc_criteres_convergence`) Set the convergence thresholds for each unknown (i.e:  alpha, temperature, velocity and pressure). The default values are respectively 0.01, 0.1, 0.01 and 100

- **[iter_min]**  (*type:* int) Number of minimum iterations

- **[seuil_convergence_implicite]**  (*type:* double) Convergence criteria.

- **[nb_corrections_max]**  (*type:* int) Maximum number of corrections performed by the PISO algorithm to achieve  the projection of the velocity field. The algorithm may perform less corrections then nb_corrections_max if the accuracy  of the projection is sufficient. (By default nb_corrections_max is set to 21).

- **[facsec_diffusion_for_sets]**  (*type:* double) facsec to impose on the diffusion time step in sets while the total time  step stays smaller than the convection time step.

- **[seuil_convergence_solveur]**  (*type:* double) value of the convergence criteria for the resolution of the implicit system  build by solving several times per time step the Navier_Stokes equation and the scalar  equations if any. This value MUST be used when a coupling between problems is considered (should be  set to a value typically of 0.1 or 0.01).

- **[seuil_generation_solveur]**  (*type:* double) Option to create a GMRES solver and use vrel as the convergence threshold  (implicit linear system Ax=B will be solved if residual error ||Ax-B|| is lesser than  vrel).

- **[seuil_verification_solveur]**  (*type:* double) Option to check if residual error ||Ax-B|| is lesser than vrel after the  implicit linear system Ax=B has been solved.

- **[seuil_test_preliminaire_solveur]**  (*type:* double) Option to decide if the implicit linear system Ax=B should be solved by  checking if the residual error ||Ax-B|| is bigger than vrel.

- **[solveur]**  (*type:* :ref:`solveur_sys_base`) Method (different from the default one, Gmres with diagonal preconditioning)  to solve the linear system.

- **[no_qdm]**  (*type:* flag) Keyword to not solve qdm equation (and turbulence models of these equation).

- **[nb_it_max]**  (*type:* int) Keyword to set the maximum iterations number for the Gmres.

- **[controle_residu]**  (*type:* flag) Keyword of Boolean type (by default 0). If set to 1, the convergence occurs if the residu suddenly increases.


----

**simple**
----------
**Inherits from:** :ref:`solveur_implicite_base` 


SIMPLE type algorithm

Parameters are:

- **[relax_pression]**  (*type:* double) Value between 0 and 1 (by default 1), this keyword is used only by the  SIMPLE algorithm for relaxing the increment of pressure.

- **[seuil_convergence_implicite]**  (*type:* double) Convergence criteria.

- **[nb_corrections_max]**  (*type:* int) Maximum number of corrections performed by the PISO algorithm to achieve  the projection of the velocity field. The algorithm may perform less corrections then nb_corrections_max if the accuracy  of the projection is sufficient. (By default nb_corrections_max is set to 21).

- **[seuil_convergence_solveur]**  (*type:* double) value of the convergence criteria for the resolution of the implicit system  build by solving several times per time step the Navier_Stokes equation and the scalar  equations if any. This value MUST be used when a coupling between problems is considered (should be  set to a value typically of 0.1 or 0.01).

- **[seuil_generation_solveur]**  (*type:* double) Option to create a GMRES solver and use vrel as the convergence threshold  (implicit linear system Ax=B will be solved if residual error ||Ax-B|| is lesser than  vrel).

- **[seuil_verification_solveur]**  (*type:* double) Option to check if residual error ||Ax-B|| is lesser than vrel after the  implicit linear system Ax=B has been solved.

- **[seuil_test_preliminaire_solveur]**  (*type:* double) Option to decide if the implicit linear system Ax=B should be solved by  checking if the residual error ||Ax-B|| is bigger than vrel.

- **[solveur]**  (*type:* :ref:`solveur_sys_base`) Method (different from the default one, Gmres with diagonal preconditioning)  to solve the linear system.

- **[no_qdm]**  (*type:* flag) Keyword to not solve qdm equation (and turbulence models of these equation).

- **[nb_it_max]**  (*type:* int) Keyword to set the maximum iterations number for the Gmres.

- **[controle_residu]**  (*type:* flag) Keyword of Boolean type (by default 0). If set to 1, the convergence occurs if the residu suddenly increases.


----

**simpler**
-----------
**Inherits from:** :ref:`solveur_implicite_base` 


Simpler method for incompressible systems.

Parameters are:

- **seuil_convergence_implicite**  (*type:* double) Keyword to set the value of the convergence criteria for the resolution  of the implicit system build to solve either the Navier_Stokes equation (only for  Simple and Simpler algorithms) or a scalar equation. It is adviced to use the default value (1e6) to solve the implicit system only once  by time step. This value must be decreased when a coupling between problems is considered.

- **[seuil_convergence_solveur]**  (*type:* double) value of the convergence criteria for the resolution of the implicit system  build by solving several times per time step the Navier_Stokes equation and the scalar  equations if any. This value MUST be used when a coupling between problems is considered (should be  set to a value typically of 0.1 or 0.01).

- **[seuil_generation_solveur]**  (*type:* double) Option to create a GMRES solver and use vrel as the convergence threshold  (implicit linear system Ax=B will be solved if residual error ||Ax-B|| is lesser than  vrel).

- **[seuil_verification_solveur]**  (*type:* double) Option to check if residual error ||Ax-B|| is lesser than vrel after the  implicit linear system Ax=B has been solved.

- **[seuil_test_preliminaire_solveur]**  (*type:* double) Option to decide if the implicit linear system Ax=B should be solved by  checking if the residual error ||Ax-B|| is bigger than vrel.

- **[solveur]**  (*type:* :ref:`solveur_sys_base`) Method (different from the default one, Gmres with diagonal preconditioning)  to solve the linear system.

- **[no_qdm]**  (*type:* flag) Keyword to not solve qdm equation (and turbulence models of these equation).

- **[nb_it_max]**  (*type:* int) Keyword to set the maximum iterations number for the Gmres.

- **[controle_residu]**  (*type:* flag) Keyword of Boolean type (by default 0). If set to 1, the convergence occurs if the residu suddenly increases.


----

**solveur_implicite_base**
--------------------------
**Inherits from:** :ref:`solveur_implicite_base` 


Class for solver in the situation where the time scheme is the implicit scheme.
Solver allows equation diffusion and convection operators to be set as implicit terms.

----

**solveur_lineaire_std**
------------------------
**Inherits from:** :ref:`solveur_implicite_base` 


not_set

Parameters are:

- **[solveur]**  (*type:* :ref:`solveur_sys_base`) not_set


----

**solveur_u_p**
---------------
**Inherits from:** :ref:`solveur_implicite_base` 


similar to simple.

Parameters are:

- **[relax_pression]**  (*type:* double) Value between 0 and 1 (by default 1), this keyword is used only by the  SIMPLE algorithm for relaxing the increment of pressure.

- **[seuil_convergence_implicite]**  (*type:* double) Convergence criteria.

- **[nb_corrections_max]**  (*type:* int) Maximum number of corrections performed by the PISO algorithm to achieve  the projection of the velocity field. The algorithm may perform less corrections then nb_corrections_max if the accuracy  of the projection is sufficient. (By default nb_corrections_max is set to 21).

- **[seuil_convergence_solveur]**  (*type:* double) value of the convergence criteria for the resolution of the implicit system  build by solving several times per time step the Navier_Stokes equation and the scalar  equations if any. This value MUST be used when a coupling between problems is considered (should be  set to a value typically of 0.1 or 0.01).

- **[seuil_generation_solveur]**  (*type:* double) Option to create a GMRES solver and use vrel as the convergence threshold  (implicit linear system Ax=B will be solved if residual error ||Ax-B|| is lesser than  vrel).

- **[seuil_verification_solveur]**  (*type:* double) Option to check if residual error ||Ax-B|| is lesser than vrel after the  implicit linear system Ax=B has been solved.

- **[seuil_test_preliminaire_solveur]**  (*type:* double) Option to decide if the implicit linear system Ax=B should be solved by  checking if the residual error ||Ax-B|| is bigger than vrel.

- **[solveur]**  (*type:* :ref:`solveur_sys_base`) Method (different from the default one, Gmres with diagonal preconditioning)  to solve the linear system.

- **[no_qdm]**  (*type:* flag) Keyword to not solve qdm equation (and turbulence models of these equation).

- **[nb_it_max]**  (*type:* int) Keyword to set the maximum iterations number for the Gmres.

- **[controle_residu]**  (*type:* flag) Keyword of Boolean type (by default 0). If set to 1, the convergence occurs if the residu suddenly increases.

