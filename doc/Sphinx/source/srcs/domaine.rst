domaine
=======

**domaine**
-----------
**Inherits from:** :ref:`domaine` 


Keyword to create a domain.

----

**domaineaxi1d**
----------------
**Inherits from:** :ref:`domaine` 


1D domain

----

**ijk_grid_geometry**
---------------------
**Inherits from:** :ref:`domaine` 


Object to define the grid that will represent the domain of the simulation in IJK 
discretization

Parameters are:

- **[perio_i]**  (*type:* flag) flag to specify the border along the I direction is periodic

- **[perio_j]**  (*type:* flag) flag to specify the border along the J direction is periodic

- **[perio_k]**  (*type:* flag) flag to specify the border along the K direction is periodic

- **[nbelem_i]**  (*type:* int) the number of elements of the grid in the I direction

- **[nbelem_j]**  (*type:* int) the number of elements of the grid in the J direction

- **[nbelem_k]**  (*type:* int) the number of elements of the grid in the K direction

- **[uniform_domain_size_i]**  (*type:* double) the size of the elements along the I direction

- **[uniform_domain_size_j]**  (*type:* double) the size of the elements along the J direction

- **[uniform_domain_size_k]**  (*type:* double) the size of the elements along the K direction

- **[origin_i]**  (*type:* double) I-coordinate of the origin of the grid

- **[origin_j]**  (*type:* double) J-coordinate of the origin of the grid

- **[origin_k]**  (*type:* double) K-coordinate of the origin of the grid

