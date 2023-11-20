front_field_base
================

**boundary_field_inward**
-------------------------
**Inherits from:** :ref:`front_field_base` 


this field is used to define the normal vector field standard at the boundary in VDF 
or VEF discretization.

Parameters are:

- **normal_value**  (*type:* string) normal vector value (positive value for a vector oriented outside to inside)  which can depend of the time.


----

**ch_front_input**
------------------
**Inherits from:** :ref:`front_field_base` 


not_set

Parameters are:

- **nb_comp**  (*type:* int) not_set

- **nom**  (*type:* string) not_set

- **[initial_value]**  (*type:* list) not_set

- **probleme**  (*type:* string) not_set

- **[sous_zone]**  (*type:* :ref:`sous_zone`) not_set


----

**ch_front_input_uniforme**
---------------------------
**Inherits from:** :ref:`front_field_base` 


for coupling, you can use ch_front_input_uniforme which is a champ_front_uniforme, 
which use an external value.
It must be used with Problem.setInputField.

Parameters are:

- **nb_comp**  (*type:* int) not_set

- **nom**  (*type:* string) not_set

- **[initial_value]**  (*type:* list) not_set

- **probleme**  (*type:* string) not_set

- **[sous_zone]**  (*type:* :ref:`sous_zone`) not_set


----

**champ_front_bruite**
----------------------
**Inherits from:** :ref:`front_field_base` 


Field which is variable in time and space in a random manner.

Parameters are:

- **nb_comp**  (*type:* int) Number of field components.

- **bloc**  (*type:* :ref:`bloc_lecture`) { [N val L val ] Moyenne m_1.....[m_i ] Amplitude A_1.....[A_ i ]}:  Random nois: If N and L are not defined, the ith component of the field varies randomly  around an average value m_i with a maximum amplitude A_i.  White noise: If N and L are defined, these two additional parameters correspond to  L, the domain length and N, the number of nodes in the domain. Noise frequency will be between 2*Pi/L and 2*Pi*N/(4*L).  For example, formula for velocity: u=U0(t) v=U1(t)Uj(t)=Mj+2*Aj*bruit_blanc where  bruit_blanc (white_noise) is the formula given in the mettre_a_jour (update) method  of the Champ_front_bruite (noise_boundary_field) (Refer to the Champ_front_bruite.cpp  file).


----

**champ_front_calc**
--------------------
**Inherits from:** :ref:`front_field_base` 


This keyword is used on a boundary to get a field from another boundary.
The local and remote boundaries should have the same mesh.
If not, the Champ_front_recyclage keyword could be used instead.
It is used in the condition block at the limits of equation which itself refers to 
a problem called pb1.
We are working under the supposition that pb1 is coupled to another problem.

Parameters are:

- **problem_name**  (*type:* :ref:`pb_base`) Name of the other problem to which pb1 is coupled.

- **bord**  (*type:* string) Name of the side which is the boundary between the 2 domains in the domain  object description associated with the problem_name object.

- **field_name**  (*type:* string) Name of the field containing the value that the user wishes to use at the  boundary. The field_name object must be recognized by the problem_name object.


----

**champ_front_composite**
-------------------------
**Inherits from:** :ref:`front_field_base` 


Composite front field.
Used in multiphase problems to associate data to each phase.

Parameters are:

- **dim**  (*type:* int) Number of field components.

- **bloc**  (*type:* :ref:`bloc_lecture`) Values Various pieces of the field, defined per phase. Part 1 goes to phase 1, etc...


----

**champ_front_contact_vef**
---------------------------
**Inherits from:** :ref:`front_field_base` 


This field is used on a boundary between a solid and fluid domain to exchange a calculated 
temperature at the contact face of the two domains according to the flux of the two 
problems.

Parameters are:

- **local_pb**  (*type:* :ref:`pb_base`) Name of the problem.

- **local_boundary**  (*type:* string) Name of the boundary.

- **remote_pb**  (*type:* :ref:`pb_base`) Name of the second problem.

- **remote_boundary**  (*type:* string) Name of the boundary in the second problem.


----

**champ_front_debit**
---------------------
**Inherits from:** :ref:`front_field_base` 


This field is used to define a flow rate field instead of a velocity field for a Dirichlet 
boundary condition on Navier-Stokes equations.

Parameters are:

- **ch**  (*type:* :ref:`front_field_base`) uniform field in space to define the flow rate. It could be, for example, champ_front_uniforme, ch_front_input_uniform or champ_front_fonc_txyz  that depends only on time.


----

**champ_front_debit_massique**
------------------------------
**Inherits from:** :ref:`front_field_base` 


This field is used to define a flow rate field using the density

Parameters are:

- **ch**  (*type:* :ref:`front_field_base`) uniform field in space to define the flow rate. It could be, for example, champ_front_uniforme, ch_front_input_uniform or champ_front_fonc_txyz  that depends only on time.


----

**champ_front_debit_qc_vdf**
----------------------------
**Inherits from:** :ref:`front_field_base` 


This keyword is used to define a flow rate field for quasi-compressible fluids in 
VDF discretization.
The flow rate is kept constant during a transient.

Parameters are:

- **dimension | dim**  (*type:* int) Problem dimension

- **liste**  (*type:* :ref:`bloc_lecture`) List of the mass flow rate values [kg/s/m2] with the following syntaxe:  { val1 ... valdim }

- **[moyen]**  (*type:* string) Option to use rho mean value

- **pb_name**  (*type:* string) Problem name


----

**champ_front_debit_qc_vdf_fonc_t**
-----------------------------------
**Inherits from:** :ref:`front_field_base` 


This keyword is used to define a flow rate field for quasi-compressible fluids in 
VDF discretization.
The flow rate could be constant or time-dependent.

Parameters are:

- **dimension | dim**  (*type:* int) Problem dimension

- **liste**  (*type:* :ref:`bloc_lecture`) List of the mass flow rate values [kg/s/m2] with the following syntaxe:  { val1 ... valdim } where val1 ... valdim are constant or function of time.

- **[moyen]**  (*type:* string) Option to use rho mean value

- **pb_name**  (*type:* string) Problem name


----

**champ_front_fonc_pois_ipsn**
------------------------------
**Inherits from:** :ref:`front_field_base` 


Boundary field champ_front_fonc_pois_ipsn.

Parameters are:

- **r_tube**  (*type:* double) not_set

- **umoy**  (*type:* list) not_set

- **r_loc**  (*type:* :ref:`listf`) not_set


----

**champ_front_fonc_pois_tube**
------------------------------
**Inherits from:** :ref:`front_field_base` 


Boundary field champ_front_fonc_pois_tube.

Parameters are:

- **r_tube**  (*type:* double) not_set

- **umoy**  (*type:* list) not_set

- **r_loc**  (*type:* :ref:`listf`) not_set

- **r_loc_mult**  (*type:* int list - size is dimension) not_set


----

**champ_front_fonc_t**
----------------------
**Inherits from:** :ref:`front_field_base` 


Boundary field that depends only on time.

Parameters are:

- **val**  (*type:* string list) Values of field components (mathematical expressions).


----

**champ_front_fonc_txyz**
-------------------------
**Inherits from:** :ref:`front_field_base` 


Boundary field which is not constant in space and in time.

Parameters are:

- **val**  (*type:* string list) Values of field components (mathematical expressions).


----

**champ_front_fonc_xyz**
------------------------
**Inherits from:** :ref:`front_field_base` 


Boundary field which is not constant in space.

Parameters are:

- **val**  (*type:* string list) Values of field components (mathematical expressions).


----

**champ_front_fonction**
------------------------
**Inherits from:** :ref:`front_field_base` 


boundary field that is function of another field

Parameters are:

- **dim**  (*type:* int) Number of field components.

- **inco**  (*type:* string) Name of the field (for example: temperature).

- **expression**  (*type:* string) keyword to use a analytical expression like 10.*EXP(-0.1*val) where val be  the keyword for the field.


----

**champ_front_lu**
------------------
**Inherits from:** :ref:`front_field_base` 


boundary field which is given from data issued from a read file.
The format of this file has to be the same that the one generated by Ecrire_fichier_xyz_valeur

Example for K and epsilon quantities to be defined for inlet condition in a boundary 
named 'entree': NL2entree frontiere_ouverte_K_Eps_impose Champ_Front_lu dom 2pb_K_EPS_PERIO_1006.306198.dat

Parameters are:

- **domaine | domain**  (*type:* :ref:`domaine`) Name of domain

- **dim**  (*type:* int) number of components

- **file**  (*type:* string) path for the read file


----

**champ_front_med**
-------------------
**Inherits from:** :ref:`front_field_base` 


Field allowing the loading of a boundary condition from a MED file using Champ_fonc_med

Parameters are:

- **champ_fonc_med**  (*type:* :ref:`field_base`) a champ_fonc_med loading the values of the unknown on a domain boundary


----

**champ_front_musig**
---------------------
**Inherits from:** :ref:`front_field_base` 


MUSIG front field.
Used in multiphase problems to associate data to each phase.

Parameters are:

- **bloc**  (*type:* :ref:`bloc_lecture`) Not set


----

**champ_front_normal_vef**
--------------------------
**Inherits from:** :ref:`front_field_base` 


Field to define the normal vector field standard at the boundary in VEF discretization.

Parameters are:

- **mot**  (*type:* :ref:`chaine(into=["valeur_normale"`) ] Name of vector field.

- **vit_tan**  (*type:* double) normal vector value (positive value for a vector oriented outside to inside).


----

**champ_front_pression_from_u**
-------------------------------
**Inherits from:** :ref:`front_field_base` 


this field is used to define a pressure field depending of a velocity field.

Parameters are:

- **expression**  (*type:* string) value depending of a velocity (like $2*u_moy^2$).


----

**champ_front_recyclage**
-------------------------
**Inherits from:** :ref:`front_field_base` 


\input{{champfrontrecyclage}}

Parameters are:

- **bloc**  (*type:* string) not_set


----

**champ_front_tabule**
----------------------
**Inherits from:** :ref:`front_field_base` 


Constant field on the boundary, tabulated as a function of time.

Parameters are:

- **nb_comp**  (*type:* int) Number of field components.

- **bloc**  (*type:* :ref:`bloc_lecture`) {nt1 t2 t3 ....tn u1 [v1 w1 ...] u2 [v2 w2 ...] u3 [v3 w3 ...] ... un [vn wn ...] }  Values are entered into a table based on n couples (ti, ui) if nb_comp value is 1. The value of a field at a given time is calculated by linear interpolation from this  table.


----

**champ_front_tabule_lu**
-------------------------
**Inherits from:** :ref:`front_field_base` 


Constant field on the boundary, tabulated from a specified column file.
Lines starting with # are ignored.

Parameters are:

- **nb_comp**  (*type:* int) Number of field components.

- **column_file**  (*type:* string) Name of the column file.


----

**champ_front_tangentiel_vef**
------------------------------
**Inherits from:** :ref:`front_field_base` 


Field to define the tangential velocity vector field standard at the boundary in VEF 
discretization.

Parameters are:

- **mot**  (*type:* :ref:`chaine(into=["vitesse_tangentielle"`) ] Name of vector field.

- **vit_tan**  (*type:* double) Vector field standard [m/s].


----

**champ_front_uniforme**
------------------------
**Inherits from:** :ref:`front_field_base` 


Boundary field which is constant in space and stationary.

Parameters are:

- **val**  (*type:* list) Values of field components.


----

**champ_front_xyz_debit**
-------------------------
**Inherits from:** :ref:`front_field_base` 


This field is used to define a flow rate field with a velocity profil which will be 
normalized to match the flow rate chosen.

Parameters are:

- **[velocity_profil]**  (*type:* :ref:`front_field_base`) velocity_profil 0 velocity field to define the profil of velocity.

- **flow_rate**  (*type:* :ref:`front_field_base`) flow_rate 1 uniform field in space to define the flow rate. It could be, for example, champ_front_uniforme, ch_front_input_uniform or champ_front_fonc_t


----

**champ_front_xyz_tabule**
--------------------------
**Inherits from:** :ref:`front_field_base` 


Space dependent field on the boundary, tabulated as a function of time.

Parameters are:

- **val**  (*type:* string list) Values of field components (mathematical expressions).

- **bloc**  (*type:* :ref:`bloc_lecture`) {nt1 t2 t3 ....tn u1 [v1 w1 ...] u2 [v2 w2 ...] u3 [v3 w3 ...] ... un [vn wn ...] }  Values are entered into a table based on n couples (ti, ui) if nb_comp value is 1. The value of a field at a given time is calculated by linear interpolation from this  table.


----

**front_field_base**
--------------------

**Synonyms:** champ_front_base

**Inherits from:** :ref:`front_field_base` 


Basic class for fields at domain boundaries.
