class_generic
=============

**amgx**
--------
**Inherits from:** :ref:`class_generic` 


Solver via AmgX API

Parameters are:

- **solveur**  (*type:* string) not_set

- **option_solveur**  (*type:* :ref:`bloc_lecture`) not_set

- **[atol]**  (*type:* double) Absolute threshold for convergence (same as seuil option)

- **[rtol]**  (*type:* double) Relative threshold for convergence


----

**cholesky**
------------
**Inherits from:** :ref:`class_generic` 


Cholesky direct method.

Parameters are:

- **[impr]**  (*type:* flag) Keyword which may be used to print the resolution time.

- **[quiet]**  (*type:* flag) To disable printing of information


----

**class_generic**
-----------------
**Inherits from:** :ref:`class_generic` 


not_set

----

**dt_calc_dt_calc**
-------------------

**Synonyms:** dt_calc

**Inherits from:** :ref:`class_generic` 


The time step at first iteration is calculated in agreement with CFL condition.

----

**dt_calc_dt_fixe**
-------------------

**Synonyms:** dt_fixe

**Inherits from:** :ref:`class_generic` 


The first time step is fixed by the user (recommended when resuming calculation with 
Crank Nicholson temporal scheme to ensure continuity).

Parameters are:

- **value**  (*type:* double) first time step.


----

**dt_calc_dt_min**
------------------

**Synonyms:** dt_min

**Inherits from:** :ref:`class_generic` 


The first iteration is based on dt_min.

----

**dt_start**
------------
**Inherits from:** :ref:`class_generic` 


not_set

----

**gcp_ns**
----------
**Inherits from:** :ref:`class_generic` 


not_set

Parameters are:

- **solveur0**  (*type:* :ref:`solveur_sys_base`) Solver type.

- **solveur1**  (*type:* :ref:`solveur_sys_base`) Solver type.

- **[precond]**  (*type:* :ref:`precond_base`) Keyword to define system preconditioning in order to accelerate resolution  by the conjugated gradient. Many parallel preconditioning methods are not equivalent to their sequential counterpart,  and you should therefore expect differences, especially when you select a high value  of the final residue (seuil). The result depends on the number of processors and on the mesh splitting. It is sometimes useful to run the solver with no preconditioning at all. In particular:  - when the solver does not converge during initial projection,  - when comparing sequential and parallel computations.  With no preconditioning, except in some particular cases (no open boundary), the  sequential and the parallel computations should provide exactly the same results within  fpu accuracy. If not, there might be a coding error or the system of equations is singular.

- **[precond_nul]**  (*type:* flag) Keyword to not use a preconditioning method.

- **seuil**  (*type:* double) Value of the final residue. The gradient ceases iteration when the Euclidean residue standard ||Ax-B|| is less  than this value.

- **[impr]**  (*type:* flag) Keyword which is used to request display of the Euclidean residue standard  each time this iterates through the conjugated gradient (display to the standard outlet).

- **[quiet]**  (*type:* flag) To not displaying any outputs of the solver.

- **[save_matrice | save_matrix]**  (*type:* flag) to save the matrix in a file.

- **[optimized]**  (*type:* flag) This keyword triggers a memory and network optimized algorithms useful for  strong scaling (when computing less than 100 000 elements per processor). The matrix and the vectors are duplicated, common items removed and only virtual  items really used in the matrix are exchanged.NL2 Warning: this is experimental and  known to fail in some VEF computations (L2 projection step will not converge). Works well in VDF.

- **[nb_it_max]**  (*type:* int) Keyword to set the maximum iterations number for the Gcp.


----

**gen**
-------
**Inherits from:** :ref:`class_generic` 


not_set

Parameters are:

- **solv_elem**  (*type:* string) To specify a solver among gmres or bicgstab.

- **precond**  (*type:* :ref:`precond_base`) The only preconditionner that we can specify is ilu.

- **[seuil]**  (*type:* double) Value of the final residue. The solver ceases iterations when the Euclidean residue standard ||Ax-B|| is less  than this value. default value 1e-12.

- **[impr]**  (*type:* flag) Keyword which is used to request display of the Euclidean residue standard  each time this iterates through the conjugated gradient (display to the standard outlet).

- **[save_matrice | save_matrix]**  (*type:* flag) To save the matrix in a file.

- **[quiet]**  (*type:* flag) To not displaying any outputs of the solver.

- **[nb_it_max]**  (*type:* int) Keyword to set the maximum iterations number for the GEN solver.

- **[force]**  (*type:* flag) Keyword to set ipar[5]=-1 in the GEN solver. This is helpful if you notice that the solver does not perform more than 100 iterations. If this keyword is specified in the datafile, you should provide nb_it_max.


----

**gmres**
---------
**Inherits from:** :ref:`class_generic` 


Gmres method (for non symetric matrix).

Parameters are:

- **[impr]**  (*type:* flag) Keyword which may be used to print the convergence.

- **[quiet]**  (*type:* flag) To disable printing of information

- **[seuil]**  (*type:* double) Convergence value.

- **[diag]**  (*type:* flag) Keyword to use diagonal preconditionner (in place of pilut that is not parallel).

- **[nb_it_max]**  (*type:* int) Keyword to set the maximum iterations number for the Gmres.

- **[controle_residu]**  (*type:* :ref:`entier(into=["0","1"`) ] Keyword of Boolean type (by default 0). If set to 1, the convergence occurs if the residu suddenly increases.

- **[save_matrice | save_matrix]**  (*type:* flag) to save the matrix in a file.

- **[dim_espace_krilov]**  (*type:* int) not_set


----

**optimal**
-----------
**Inherits from:** :ref:`class_generic` 


Optimal is a solver which tests several solvers of the previous list to choose the 
fastest one for the considered linear system.

Parameters are:

- **seuil**  (*type:* double) Convergence threshold

- **[impr]**  (*type:* flag) To print the convergency of the fastest solver

- **[quiet]**  (*type:* flag) To disable printing of information

- **[save_matrice | save_matrix]**  (*type:* flag) To save the linear system (A, x, B) into a file

- **[frequence_recalc]**  (*type:* int) To set a time step period (by default, 100) for re-checking the fatest solver

- **[nom_fichier_solveur]**  (*type:* string) To specify the file containing the list of the tested solvers

- **[fichier_solveur_non_recree]**  (*type:* flag) To avoid the creation of the file containing the list


----

**petsc**
---------
**Inherits from:** :ref:`class_generic` 


Solver via Petsc API

\input{{solvpetsc}}

Parameters are:

- **solveur**  (*type:* string) not_set

- **option_solveur**  (*type:* :ref:`bloc_lecture`) not_set

- **[atol]**  (*type:* double) Absolute threshold for convergence (same as seuil option)

- **[rtol]**  (*type:* double) Relative threshold for convergence


----

**rocalution**
--------------
**Inherits from:** :ref:`class_generic` 


Solver via rocALUTION API

Parameters are:

- **solveur**  (*type:* string) not_set

- **option_solveur**  (*type:* :ref:`bloc_lecture`) not_set

- **[atol]**  (*type:* double) Absolute threshold for convergence (same as seuil option)

- **[rtol]**  (*type:* double) Relative threshold for convergence


----

**solv_gcp**
------------

**Synonyms:** gcp

**Inherits from:** :ref:`class_generic` 


Preconditioned conjugated gradient.

Parameters are:

- **[precond]**  (*type:* :ref:`precond_base`) Keyword to define system preconditioning in order to accelerate resolution  by the conjugated gradient. Many parallel preconditioning methods are not equivalent to their sequential counterpart,  and you should therefore expect differences, especially when you select a high value  of the final residue (seuil). The result depends on the number of processors and on the mesh splitting. It is sometimes useful to run the solver with no preconditioning at all. In particular:  - when the solver does not converge during initial projection,  - when comparing sequential and parallel computations.  With no preconditioning, except in some particular cases (no open boundary), the  sequential and the parallel computations should provide exactly the same results within  fpu accuracy. If not, there might be a coding error or the system of equations is singular.

- **[precond_nul]**  (*type:* flag) Keyword to not use a preconditioning method.

- **seuil**  (*type:* double) Value of the final residue. The gradient ceases iteration when the Euclidean residue standard ||Ax-B|| is less  than this value.

- **[impr]**  (*type:* flag) Keyword which is used to request display of the Euclidean residue standard  each time this iterates through the conjugated gradient (display to the standard outlet).

- **[quiet]**  (*type:* flag) To not displaying any outputs of the solver.

- **[save_matrice | save_matrix]**  (*type:* flag) to save the matrix in a file.

- **[optimized]**  (*type:* flag) This keyword triggers a memory and network optimized algorithms useful for  strong scaling (when computing less than 100 000 elements per processor). The matrix and the vectors are duplicated, common items removed and only virtual  items really used in the matrix are exchanged.NL2 Warning: this is experimental and  known to fail in some VEF computations (L2 projection step will not converge). Works well in VDF.

- **[nb_it_max]**  (*type:* int) Keyword to set the maximum iterations number for the Gcp.


----

**solveur_sys_base**
--------------------
**Inherits from:** :ref:`class_generic` 


Basic class to solve the linear system.
