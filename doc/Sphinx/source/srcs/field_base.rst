field_base
==========

**champ_composite**
-------------------
**Inherits from:** :ref:`field_base` 


Composite field.
Used in multiphase problems to associate data to each phase.

Parameters are:

- **dim**  (*type:* int) Number of field components.

- **bloc**  (*type:* :ref:`bloc_lecture`) Values Various pieces of the field, defined per phase. Part 1 goes to phase 1, etc...


----

**champ_don_base**
------------------
**Inherits from:** :ref:`field_base` 


Basic class for data fields (not calculated), p.e.
physics properties.

----

**champ_don_lu**
----------------
**Inherits from:** :ref:`field_base` 


Field to read a data field (values located at the center of the cells) in a file.

Parameters are:

- **dom**  (*type:* :ref:`domaine`) Name of the domain.

- **nb_comp**  (*type:* int) Number of field components.

- **file**  (*type:* string) Name of the file.  This file has the following format:  nb_val_lues -> Number of values readen in th file  Xi Yi Zi -> Coordinates readen in the file  Ui Vi Wi -> Value of the field


----

**champ_fonc_fonction**
-----------------------
**Inherits from:** :ref:`field_base` 


Field that is a function of another field.

Parameters are:

- **problem_name**  (*type:* :ref:`pb_base`) Name of problem.

- **inco**  (*type:* string) Name of the field (for example: temperature).

- **expression**  (*type:* string list) Number of field components followed by the analytical expression for  each field component.


----

**champ_fonc_fonction_txyz**
----------------------------
**Inherits from:** :ref:`field_base` 


this refers to a field that is a function of another field and time and/or space coordinates

Parameters are:

- **problem_name**  (*type:* :ref:`pb_base`) Name of problem.

- **inco**  (*type:* string) Name of the field (for example: temperature).

- **expression**  (*type:* string list) Number of field components followed by the analytical expression for  each field component.


----

**champ_fonc_fonction_txyz_morceaux**
-------------------------------------
**Inherits from:** :ref:`field_base` 


Field defined by analytical functions in each sub-domaine.
It makes possible the definition of a field that depends on the time and the space.

Parameters are:

- **problem_name**  (*type:* :ref:`pb_base`) Name of the problem.

- **inco**  (*type:* string) Name of the field (for example: temperature).

- **nb_comp**  (*type:* int) Number of field components.

- **data**  (*type:* :ref:`bloc_lecture`) { Defaut val_def sous_domaine_1 val_1 ... sous_domaine_i val_i } By default, the value val_def is assigned to the field. It takes the sous_domaine_i identifier Sous_Domaine (sub_area) type object function,  val_i. Sous_Domaine (sub_area) type objects must have been previously defined if the operator  wishes to use a champ_fonc_fonction_txyz_morceaux type object.


----

**champ_fonc_interp**
---------------------
**Inherits from:** :ref:`field_base` 


Field that is interpolated from a distant domain via MEDCoupling (remapper).

Parameters are:

- **nom_champ**  (*type:* string) Name of the field (for example: temperature).

- **pb_loc**  (*type:* string) Name of the local problem.

- **pb_dist**  (*type:* string) Name of the distant problem.

- **[dom_loc]**  (*type:* string) Name of the local domain.

- **[dom_dist]**  (*type:* string) Name of the distant domain.

- **[default_value]**  (*type:* string) Name of the distant domain.

- **nature**  (*type:* string) Nature of the field (knowledge from MEDCoupling is required; IntensiveMaximum,  IntensiveConservation, ...).


----

**champ_fonc_med**
------------------
**Inherits from:** :ref:`field_base` 


Field to read a data field in a MED-format file .med at a specified time.
It is very useful, for example, to resume a calculation with a new or refined geometry.
The field post-processed on the new geometry at med format is used as initial condition 
for the resume.

Parameters are:

- **[use_existing_domain]**  (*type:* flag) whether to optimize the field loading by indicating that the field is supported  by the same mesh that was initially loaded as the domain

- **[last_time]**  (*type:* flag) to use the last time of the MED file instead of the specified time. Mutually exclusive with 'time' parameter.

- **[decoup]**  (*type:* string) specify a partition file.

- **[mesh]**  (*type:* string) Name of the mesh supporting the field. This is the name of the mesh in the MED file, and if this mesh was also used to create  the TRUST domain, loading can be optimized with option 'use_existing_domain'.

- **domain**  (*type:* string) Name of the domain supporting the field. This is the name of the mesh in the MED file, and if this mesh was also used to create  the TRUST domain, loading can be optimized with option 'use_existing_domain'.

- **file**  (*type:* string) Name of the .med file.

- **field**  (*type:* string) Name of field to load.

- **[loc]**  (*type:* :ref:`chaine(into=["som","elem"`) ] To indicate where the field is localised. Default to 'elem'.

- **[time]**  (*type:* double) Timestep to load from the MED file. Mutually exclusive with 'last_time' flag.


----

**champ_fonc_med_table_temps**
------------------------------
**Inherits from:** :ref:`field_base` 


Field defined as a fixed spatial shape scaled by a temporal coefficient

Parameters are:

- **[table_temps]**  (*type:* string) Table containing the temporal coefficient used to scale the field

- **[table_temps_lue]**  (*type:* string) Name of the file containing the values of the temporal coefficient used to  scale the field

- **[use_existing_domain]**  (*type:* flag) whether to optimize the field loading by indicating that the field is supported  by the same mesh that was initially loaded as the domain

- **[last_time]**  (*type:* flag) to use the last time of the MED file instead of the specified time. Mutually exclusive with 'time' parameter.

- **[decoup]**  (*type:* string) specify a partition file.

- **[mesh]**  (*type:* string) Name of the mesh supporting the field. This is the name of the mesh in the MED file, and if this mesh was also used to create  the TRUST domain, loading can be optimized with option 'use_existing_domain'.

- **domain**  (*type:* string) Name of the domain supporting the field. This is the name of the mesh in the MED file, and if this mesh was also used to create  the TRUST domain, loading can be optimized with option 'use_existing_domain'.

- **file**  (*type:* string) Name of the .med file.

- **field**  (*type:* string) Name of field to load.

- **[loc]**  (*type:* :ref:`chaine(into=["som","elem"`) ] To indicate where the field is localised. Default to 'elem'.

- **[time]**  (*type:* double) Timestep to load from the MED file. Mutually exclusive with 'last_time' flag.


----

**champ_fonc_med_tabule**
-------------------------
**Inherits from:** :ref:`field_base` 


not_set

Parameters are:

- **[use_existing_domain]**  (*type:* flag) whether to optimize the field loading by indicating that the field is supported  by the same mesh that was initially loaded as the domain

- **[last_time]**  (*type:* flag) to use the last time of the MED file instead of the specified time. Mutually exclusive with 'time' parameter.

- **[decoup]**  (*type:* string) specify a partition file.

- **[mesh]**  (*type:* string) Name of the mesh supporting the field. This is the name of the mesh in the MED file, and if this mesh was also used to create  the TRUST domain, loading can be optimized with option 'use_existing_domain'.

- **domain**  (*type:* string) Name of the domain supporting the field. This is the name of the mesh in the MED file, and if this mesh was also used to create  the TRUST domain, loading can be optimized with option 'use_existing_domain'.

- **file**  (*type:* string) Name of the .med file.

- **field**  (*type:* string) Name of field to load.

- **[loc]**  (*type:* :ref:`chaine(into=["som","elem"`) ] To indicate where the field is localised. Default to 'elem'.

- **[time]**  (*type:* double) Timestep to load from the MED file. Mutually exclusive with 'last_time' flag.


----

**champ_fonc_reprise**
----------------------
**Inherits from:** :ref:`field_base` 


This field is used to read a data field in a save file (.xyz or .sauv) at a specified 
time.
It is very useful, for example, to run a thermohydraulic calculation with velocity 
initial condition read into a save file from a previous hydraulic calculation.

Parameters are:

- **[format]**  (*type:* :ref:`chaine(into=["binaire","formatte","xyz","single_hdf"`) ] Type of file (the file format). If xyz format is activated, the .xyz file from the previous calculation will be given  for filename, and if formatte or binaire is choosen, the .sauv file of the previous  calculation will be specified for filename. In the case of a parallel calculation, if the mesh partition does not changed between  the previous calculation and the next one, the binaire format should be preferred,  because is faster than the xyz format. If single_hdf is used, the same constraints/advantages as binaire apply, but a single  (HDF5) file is produced on the filesystem instead of having one file per processor.

- **filename**  (*type:* string) Name of the save file.

- **pb_name**  (*type:* :ref:`pb_base`) Name of the problem.

- **champ**  (*type:* string) Name of the problem unknown. It may also be the temporal average of a problem unknown (like moyenne_vitesse, moyenne_temperature,...)

- **[fonction]**  (*type:* :ref:`fonction_champ_reprise`) Optional keyword to apply a function on the field being read  in the save file (e.g. to read a temperature field in Celsius units and convert it for the calculation on  Kelvin units, you will use: fonction 1 273.+val )

- **temps | time**  (*type:* string) Time of the saved field in the save file or last_time. If you give the keyword last_time instead, the last time saved in the save file will  be used.


----

**champ_fonc_t**
----------------
**Inherits from:** :ref:`field_base` 


Field that is constant in space and is a function of time.

Parameters are:

- **val**  (*type:* string list) Values of field components (time dependant functions).


----

**champ_fonc_tabule**
---------------------
**Inherits from:** :ref:`field_base` 


Field that is tabulated as a function of another field.

Parameters are:

- **inco**  (*type:* string) Name of the field (for example: temperature).

- **dim**  (*type:* int) Number of field components.

- **bloc**  (*type:* :ref:`bloc_lecture`) Values (the table (the value of the field at any time is calculated  by linear interpolation from this table) or the analytical expression (with keyword  expression to use an analytical expression)).


----

**champ_fonc_tabule_morceaux**
------------------------------

**Synonyms:** champ_tabule_morceaux

**Inherits from:** :ref:`field_base` 


Field defined by tabulated data in each sub-domaine.
It makes possible the definition of a field which is a function of other fields.

Parameters are:

- **domain_name**  (*type:* :ref:`domaine`) Name of the domain.

- **nb_comp**  (*type:* int) Number of field components.

- **data**  (*type:* :ref:`bloc_lecture`) { Defaut val_def sous_domaine_1 val_1 ... sous_domaine_i val_i } By default, the value val_def is assigned to the field. It takes the sous_domaine_i identifier Sous_Domaine (sub_area) type object function,  val_i. Sous_Domaine (sub_area) type objects must have been previously defined if the operator  wishes to use a champ_fonc_tabule_morceaux type object.


----

**champ_fonc_tabule_morceaux_interp**
-------------------------------------
**Inherits from:** :ref:`field_base` 


Field defined by tabulated data in each sub-domaine.
It makes possible the definition of a field which is a function of other fields.
Here we use MEDCoupling to interpolate fields between the two domains.

Parameters are:

- **problem_name**  (*type:* :ref:`pb_base`) Name of the problem.

- **nb_comp**  (*type:* int) Number of field components.

- **data**  (*type:* :ref:`bloc_lecture`) { Defaut val_def sous_domaine_1 val_1 ... sous_domaine_i val_i } By default, the value val_def is assigned to the field. It takes the sous_domaine_i identifier Sous_Domaine (sub_area) type object function,  val_i. Sous_Domaine (sub_area) type objects must have been previously defined if the operator  wishes to use a champ_fonc_tabule_morceaux type object.


----

**champ_init_canal_sinal**
--------------------------
**Inherits from:** :ref:`field_base` 


For a parabolic profile on U velocity with an unpredictable disturbance on V and W 
and a sinusoidal disturbance on V velocity.

Parameters are:

- **dim**  (*type:* int) Number of field components.

- **bloc**  (*type:* :ref:`bloc_lec_champ_init_canal_sinal`) Parameters for the class champ_init_canal_sinal.


----

**champ_input_base**
--------------------
**Inherits from:** :ref:`field_base` 


not_set

Parameters are:

- **nb_comp**  (*type:* int) not_set

- **nom**  (*type:* string) not_set

- **[initial_value]**  (*type:* list) not_set

- **probleme**  (*type:* string) not_set

- **[sous_zone]**  (*type:* :ref:`sous_zone`) not_set


----

**champ_input_p0**
------------------
**Inherits from:** :ref:`field_base` 


not_set

Parameters are:

- **nb_comp**  (*type:* int) not_set

- **nom**  (*type:* string) not_set

- **[initial_value]**  (*type:* list) not_set

- **probleme**  (*type:* string) not_set

- **[sous_zone]**  (*type:* :ref:`sous_zone`) not_set


----

**champ_input_p0_composite**
----------------------------
**Inherits from:** :ref:`field_base` 


Field used to define a classical champ input p0 field (for ICoCo), but with a predefined 
field for the initial state.

Parameters are:

- **[initial_field]**  (*type:* :ref:`field_base`) The field used for initialization

- **[input_field]**  (*type:* :ref:`champ_input_p0`) The input field for ICoCo

- **nb_comp**  (*type:* int) not_set

- **nom**  (*type:* string) not_set

- **[initial_value]**  (*type:* list) not_set

- **probleme**  (*type:* string) not_set

- **[sous_zone]**  (*type:* :ref:`sous_zone`) not_set


----

**champ_musig**
---------------
**Inherits from:** :ref:`field_base` 


MUSIG field.
Used in multiphase problems to associate data to each phase.

Parameters are:

- **bloc**  (*type:* :ref:`bloc_lecture`) Not set


----

**champ_ostwald**
-----------------
**Inherits from:** :ref:`field_base` 


This keyword is used to define the viscosity variation law:

Mu(T)= K(T)*(D:D/2)**((n-1)/2)

----

**champ_som_lu_vdf**
--------------------
**Inherits from:** :ref:`field_base` 


Keyword to read in a file values located at the nodes of a mesh in VDF discretization.

Parameters are:

- **domain_name**  (*type:* :ref:`domaine`) Name of the domain.

- **dim**  (*type:* int) Value of the dimension of the field.

- **tolerance**  (*type:* double) Value of the tolerance to check the coordinates of the nodes.

- **file**  (*type:* string) name of the file  This file has the following format:  Xi Yi Zi -> Coordinates of the node  Ui Vi Wi -> Value of the field on this node  Xi+1 Yi+1 Zi+1 -> Next point  Ui+1 Vi+1 Zi+1 -> Next value ...


----

**champ_som_lu_vef**
--------------------
**Inherits from:** :ref:`field_base` 


Keyword to read in a file values located at the nodes of a mesh in VEF discretization.

Parameters are:

- **domain_name**  (*type:* :ref:`domaine`) Name of the domain.

- **dim**  (*type:* int) Value of the dimension of the field.

- **tolerance**  (*type:* double) Value of the tolerance to check the coordinates of the nodes.

- **file**  (*type:* string) Name of the file.  This file has the following format:  Xi Yi Zi -> Coordinates of the node  Ui Vi Wi -> Value of the field on this node  Xi+1 Yi+1 Zi+1 -> Next point  Ui+1 Vi+1 Zi+1 -> Next value ...


----

**champ_tabule_temps**
----------------------
**Inherits from:** :ref:`field_base` 


Field that is constant in space and tabulated as a function of time.

Parameters are:

- **dim**  (*type:* int) Number of field components.

- **bloc**  (*type:* :ref:`bloc_lecture`) Values as a table. The value of the field at any time is calculated by linear interpolation from this  table.


----

**champ_uniforme_morceaux**
---------------------------
**Inherits from:** :ref:`field_base` 


Field which is partly constant in space and stationary.

Parameters are:

- **nom_dom**  (*type:* :ref:`domaine`) Name of the domain to which the sub-areas belong.

- **nb_comp**  (*type:* int) Number of field components.

- **data**  (*type:* :ref:`bloc_lecture`) { Defaut val_def sous_zone_1 val_1 ... sous_zone_i val_i } By default, the value val_def is assigned to the field. It takes the sous_zone_i identifier Sous_Zone (sub_area) type object value, val_i. Sous_Zone (sub_area) type objects must have been previously defined if the operator  wishes to use a Champ_Uniforme_Morceaux(partly_uniform_field) type object.


----

**champ_uniforme_morceaux_tabule_temps**
----------------------------------------
**Inherits from:** :ref:`field_base` 


this type of field is constant in space on one or several sub_zones and tabulated 
as a function of time.

Parameters are:

- **nom_dom**  (*type:* :ref:`domaine`) Name of the domain to which the sub-areas belong.

- **nb_comp**  (*type:* int) Number of field components.

- **data**  (*type:* :ref:`bloc_lecture`) { Defaut val_def sous_zone_1 val_1 ... sous_zone_i val_i } By default, the value val_def is assigned to the field. It takes the sous_zone_i identifier Sous_Zone (sub_area) type object value, val_i. Sous_Zone (sub_area) type objects must have been previously defined if the operator  wishes to use a Champ_Uniforme_Morceaux(partly_uniform_field) type object.


----

**field_base**
--------------

**Synonyms:** champ_base

**Inherits from:** :ref:`field_base` 


Basic class of fields.

----

**field_func_txyz**
-------------------

**Synonyms:** champ_fonc_txyz

**Inherits from:** :ref:`field_base` 


Field defined by analytical functions.
It makes it possible the definition of a field that depends on the time and the space.

Parameters are:

- **dom**  (*type:* :ref:`domaine`) Name of domain of calculation.

- **val**  (*type:* string list) List of functions on (t,x,y,z).


----

**field_func_xyz**
------------------

**Synonyms:** champ_fonc_xyz

**Inherits from:** :ref:`field_base` 


Field defined by analytical functions.
It makes it possible the definition of a field that depends on (x,y,z).

Parameters are:

- **dom**  (*type:* :ref:`domaine`) Name of domain of calculation.

- **val**  (*type:* string list) List of functions on (x,y,z).


----

**init_par_partie**
-------------------
**Inherits from:** :ref:`field_base` 


ne marche que pour n_comp=1

Parameters are:

- **n_comp**  (*type:* :ref:`entier(into=[1`) ] not_set

- **val1**  (*type:* double) not_set

- **val2**  (*type:* double) not_set

- **val3**  (*type:* double) not_set


----

**tayl_green**
--------------
**Inherits from:** :ref:`field_base` 


Class Tayl_green.

Parameters are:

- **dim**  (*type:* int) Dimension.


----

**uniform_field**
-----------------

**Synonyms:** champ_uniforme

**Inherits from:** :ref:`field_base` 


Field that is constant in space and stationary.

Parameters are:

- **val**  (*type:* list) Values of field components.


----

**valeur_totale_sur_volume**
----------------------------
**Inherits from:** :ref:`field_base` 


Similar as Champ_Uniforme_Morceaux with the same syntax.
Used for source terms when we want to specify a source term with a value given for 
the volume (eg: heat in Watts) and not a value per volume unit (eg: heat in Watts/m3).

Parameters are:

- **nom_dom**  (*type:* :ref:`domaine`) Name of the domain to which the sub-areas belong.

- **nb_comp**  (*type:* int) Number of field components.

- **data**  (*type:* :ref:`bloc_lecture`) { Defaut val_def sous_zone_1 val_1 ... sous_zone_i val_i } By default, the value val_def is assigned to the field. It takes the sous_zone_i identifier Sous_Zone (sub_area) type object value, val_i. Sous_Zone (sub_area) type objects must have been previously defined if the operator  wishes to use a Champ_Uniforme_Morceaux(partly_uniform_field) type object.

