discretisation_base
===================

**discretisation_base**
-----------------------
**Inherits from:** :ref:`discretisation_base` 


Basic class for space discretization of thermohydraulic turbulent problems.

----

**ef**
------
**Inherits from:** :ref:`discretisation_base` 


Element Finite discretization.

----

**polymac**
-----------
**Inherits from:** :ref:`discretisation_base` 


polymac discretization (polymac discretization that is not compatible with pb_multi).

----

**polymac_p0**
--------------
**Inherits from:** :ref:`discretisation_base` 


polymac_p0 discretization (previously covimac discretization compatible with pb_multi).

----

**polymac_p0p1nc**
------------------
**Inherits from:** :ref:`discretisation_base` 


polymac_P0P1NC discretization (previously polymac discretization compatible with pb_multi).

----

**vdf**
-------
**Inherits from:** :ref:`discretisation_base` 


Finite difference volume discretization.

----

**vef**
-------

**Synonyms:** vefprep1b

**Inherits from:** :ref:`discretisation_base` 


Finite element volume discretization (P1NC/P1-bubble element).
Since the 1.5.5 version, several new discretizations are available thanks to the 
optional keyword Read.
By default, the VEFPreP1B keyword is equivalent to the former VEFPreP1B formulation 
(v1.5.4 and sooner).
P0P1 (if used with the strong formulation for imposed pressure boundary) is equivalent 
to VEFPreP1B but the convergence is slower.
VEFPreP1B dis is equivalent to VEFPreP1B dis Read dis { P0 P1 Changement_de_base_P1Bulle 
1 Cl_pression_sommet_faible 0 }

Parameters are:

- **[p0]**  (*type:* flag) Pressure nodes are added on element centres

- **[p1]**  (*type:* flag) Pressure nodes are added on vertices

- **[pa]**  (*type:* flag) Only available in 3D, pressure nodes are added on bones

- **[changement_de_base_p1bulle]**  (*type:* :ref:`entier(into=[0,1`) ] This option may be used to have the P1NC/P0P1 formulation (value  set to 0) or the P1NC/P1Bulle formulation (value set to 1, the default).

- **[cl_pression_sommet_faible]**  (*type:* :ref:`entier(into=[0,1`) ] This option is used to specify a strong formulation (value set  to 0, the default) or a weak formulation (value set to 1) for an imposed pressure  boundary condition. The first formulation converges quicker and is stable in general cases. The second formulation should be used if there are several outlet boundaries with  Neumann condition (see Ecoulement_Neumann test case for example).

- **[modif_div_face_dirichlet]**  (*type:* :ref:`entier(into=[0,1`) ] This option (by default 0) is used to extend control volumes  for the momentum equation.

