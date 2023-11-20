precond_base
============

**ilu**
-------
**Inherits from:** :ref:`precond_base` 


This preconditionner can be only used with the generic GEN solver.

Parameters are:

- **[type]**  (*type:* int) values can be 0|1|2|3 for null|left|right|left-and-right preconditionning  (default value = 2)

- **[filling]**  (*type:* int) default value = 1.


----

**precond_base**
----------------
**Inherits from:** :ref:`precond_base` 


Basic class for preconditioning.

----

**precondsolv**
---------------
**Inherits from:** :ref:`precond_base` 


not_set

Parameters are:

- **solveur**  (*type:* :ref:`solveur_sys_base`) Solver type.


----

**ssor**
--------
**Inherits from:** :ref:`precond_base` 


Symmetric successive over-relaxation algorithm.

Parameters are:

- **[omega]**  (*type:* double) Over-relaxation facteur (between 1 and 2, default value 1.6).


----

**ssor_bloc**
-------------
**Inherits from:** :ref:`precond_base` 


not_set

Parameters are:

- **[alpha_0]**  (*type:* double) not_set

- **[precond0]**  (*type:* :ref:`precond_base`) not_set

- **[alpha_1]**  (*type:* double) not_set

- **[precond1]**  (*type:* :ref:`precond_base`) not_set

- **[alpha_a]**  (*type:* double) not_set

- **[preconda]**  (*type:* :ref:`precond_base`) not_set

