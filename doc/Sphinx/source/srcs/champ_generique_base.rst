champ_generique_base
====================

**champ_generique_base**
------------------------
**Inherits from:** :ref:`champ_generique_base` 


not_set

----

**champ_post_de_champs_post**
-----------------------------
**Inherits from:** :ref:`champ_generique_base` 


not_set

Parameters are:

- **[source]**  (*type:* :ref:`champ_generique_base`) the source field.

- **[nom_source]**  (*type:* string) To name a source field with the nom_source keyword

- **[source_reference]**  (*type:* string) not_set

- **[sources_reference]**  (*type:* :ref:`list_nom_virgule`) not_set

- **[sources]**  (*type:* :ref:`listchamp_generique`) sources { Champ_Post.... { ... } Champ_Post.. { ... }}


----

**champ_post_operateur_base**
-----------------------------
**Inherits from:** :ref:`champ_generique_base` 


not_set

Parameters are:

- **[source]**  (*type:* :ref:`champ_generique_base`) the source field.

- **[nom_source]**  (*type:* string) To name a source field with the nom_source keyword

- **[source_reference]**  (*type:* string) not_set

- **[sources_reference]**  (*type:* :ref:`list_nom_virgule`) not_set

- **[sources]**  (*type:* :ref:`listchamp_generique`) sources { Champ_Post.... { ... } Champ_Post.. { ... }}


----

**champ_post_operateur_eqn**
----------------------------

**Synonyms:** operateur_eqn

**Inherits from:** :ref:`champ_generique_base` 


Post-process equation operators/sources

Parameters are:

- **[numero_source]**  (*type:* int) the source to be post-processed (its number). If you have only one source term, numero_source will correspond to 0 if you want  to post-process that unique source

- **[numero_op]**  (*type:* int) numero_op will be 0 (diffusive operator) or 1 (convective operator) or 2  (gradient operator) or 3 (divergence operator).

- **[numero_masse]**  (*type:* int) numero_masse will be 0 for the mass equation operator in Pb_multiphase.

- **[sans_solveur_masse]**  (*type:* flag) not_set

- **[compo]**  (*type:* int) If you want to post-process only one component of a vector field, you can  specify the number of the component after compo keyword. By default, it is set to -1 which means that all the components will be post-processed. This feature is not available in VDF disretization.

- **[source]**  (*type:* :ref:`champ_generique_base`) the source field.

- **[nom_source]**  (*type:* string) To name a source field with the nom_source keyword

- **[source_reference]**  (*type:* string) not_set

- **[sources_reference]**  (*type:* :ref:`list_nom_virgule`) not_set

- **[sources]**  (*type:* :ref:`listchamp_generique`) sources { Champ_Post.... { ... } Champ_Post.. { ... }}


----

**champ_post_statistiques_base**
--------------------------------
**Inherits from:** :ref:`champ_generique_base` 


not_set

Parameters are:

- **t_deb**  (*type:* double) Start of integration time

- **t_fin**  (*type:* double) End of integration time

- **[source]**  (*type:* :ref:`champ_generique_base`) the source field.

- **[nom_source]**  (*type:* string) To name a source field with the nom_source keyword

- **[source_reference]**  (*type:* string) not_set

- **[sources_reference]**  (*type:* :ref:`list_nom_virgule`) not_set

- **[sources]**  (*type:* :ref:`listchamp_generique`) sources { Champ_Post.... { ... } Champ_Post.. { ... }}


----

**correlation**
---------------

**Synonyms:** champ_post_statistiques_correlation

**Inherits from:** :ref:`champ_generique_base` 


to calculate the correlation between the two fields.

Parameters are:

- **t_deb**  (*type:* double) Start of integration time

- **t_fin**  (*type:* double) End of integration time

- **[source]**  (*type:* :ref:`champ_generique_base`) the source field.

- **[nom_source]**  (*type:* string) To name a source field with the nom_source keyword

- **[source_reference]**  (*type:* string) not_set

- **[sources_reference]**  (*type:* :ref:`list_nom_virgule`) not_set

- **[sources]**  (*type:* :ref:`listchamp_generique`) sources { Champ_Post.... { ... } Champ_Post.. { ... }}


----

**divergence**
--------------

**Synonyms:** champ_post_operateur_divergence

**Inherits from:** :ref:`champ_generique_base` 


To calculate divergency of a given field.

Parameters are:

- **[source]**  (*type:* :ref:`champ_generique_base`) the source field.

- **[nom_source]**  (*type:* string) To name a source field with the nom_source keyword

- **[source_reference]**  (*type:* string) not_set

- **[sources_reference]**  (*type:* :ref:`list_nom_virgule`) not_set

- **[sources]**  (*type:* :ref:`listchamp_generique`) sources { Champ_Post.... { ... } Champ_Post.. { ... }}


----

**ecart_type**
--------------

**Synonyms:** champ_post_statistiques_ecart_type

**Inherits from:** :ref:`champ_generique_base` 


to calculate the standard deviation (statistic rms) of the field nom_champ.

Parameters are:

- **t_deb**  (*type:* double) Start of integration time

- **t_fin**  (*type:* double) End of integration time

- **[source]**  (*type:* :ref:`champ_generique_base`) the source field.

- **[nom_source]**  (*type:* string) To name a source field with the nom_source keyword

- **[source_reference]**  (*type:* string) not_set

- **[sources_reference]**  (*type:* :ref:`list_nom_virgule`) not_set

- **[sources]**  (*type:* :ref:`listchamp_generique`) sources { Champ_Post.... { ... } Champ_Post.. { ... }}


----

**extraction**
--------------

**Synonyms:** champ_post_extraction

**Inherits from:** :ref:`champ_generique_base` 


To create a surface field (values at the boundary) of a volume field

Parameters are:

- **domaine**  (*type:* :ref:`domaine`) name of the volume field

- **nom_frontiere**  (*type:* string) boundary name where the values of the volume field will be picked

- **[methode]**  (*type:* :ref:`chaine(into=["trace","champ_frontiere"`) ] name of the extraction method (trace by_default  or champ_frontiere)

- **[source]**  (*type:* :ref:`champ_generique_base`) the source field.

- **[nom_source]**  (*type:* string) To name a source field with the nom_source keyword

- **[source_reference]**  (*type:* string) not_set

- **[sources_reference]**  (*type:* :ref:`list_nom_virgule`) not_set

- **[sources]**  (*type:* :ref:`listchamp_generique`) sources { Champ_Post.... { ... } Champ_Post.. { ... }}


----

**gradient**
------------

**Synonyms:** champ_post_operateur_gradient

**Inherits from:** :ref:`champ_generique_base` 


To calculate gradient of a given field.

Parameters are:

- **[source]**  (*type:* :ref:`champ_generique_base`) the source field.

- **[nom_source]**  (*type:* string) To name a source field with the nom_source keyword

- **[source_reference]**  (*type:* string) not_set

- **[sources_reference]**  (*type:* :ref:`list_nom_virgule`) not_set

- **[sources]**  (*type:* :ref:`listchamp_generique`) sources { Champ_Post.... { ... } Champ_Post.. { ... }}


----

**interpolation**
-----------------

**Synonyms:** champ_post_interpolation

**Inherits from:** :ref:`champ_generique_base` 


To create a field which is an interpolation of the field given by the keyword source.

Parameters are:

- **localisation**  (*type:* string) type_loc indicate where is done the interpolation (elem for element or som  for node).

- **[methode]**  (*type:* string) The optional keyword methode is limited to calculer_champ_post for the moment.

- **[domaine]**  (*type:* string) the domain name where the interpolation is done (by default, the calculation  domain)

- **[optimisation_sous_maillage]**  (*type:* :ref:`chaine(into=["default","yes","no",`) ] not_set

- **[source]**  (*type:* :ref:`champ_generique_base`) the source field.

- **[nom_source]**  (*type:* string) To name a source field with the nom_source keyword

- **[source_reference]**  (*type:* string) not_set

- **[sources_reference]**  (*type:* :ref:`list_nom_virgule`) not_set

- **[sources]**  (*type:* :ref:`listchamp_generique`) sources { Champ_Post.... { ... } Champ_Post.. { ... }}


----

**morceau_equation**
--------------------

**Synonyms:** champ_post_morceau_equation

**Inherits from:** :ref:`champ_generique_base` 


To calculate a field related to a piece of equation.
For the moment, the field which can be calculated is the stability time step of an 
operator equation.
The problem name and the unknown of the equation should be given by Source refChamp 
{ Pb_Champ problem_name unknown_field_of_equation }

Parameters are:

- **type**  (*type:* string) can only be operateur for equation operators.

- **[numero]**  (*type:* int) numero will be 0 (diffusive operator) or 1 (convective operator) or 2 (gradient  operator) or 3 (divergence operator).

- **option**  (*type:* :ref:`chaine(into=["stabilite","flux_bords","flux_surfacique_bords"`) ] option is stability  for time steps or flux_bords for boundary fluxes or flux_surfacique_bords for boundary  surfacic fluxes

- **[compo]**  (*type:* int) compo will specify the number component of the boundary flux (for boundary  fluxes, in this case compo permits to specify the number component of the boundary  flux choosen).

- **[source]**  (*type:* :ref:`champ_generique_base`) the source field.

- **[nom_source]**  (*type:* string) To name a source field with the nom_source keyword

- **[source_reference]**  (*type:* string) not_set

- **[sources_reference]**  (*type:* :ref:`list_nom_virgule`) not_set

- **[sources]**  (*type:* :ref:`listchamp_generique`) sources { Champ_Post.... { ... } Champ_Post.. { ... }}


----

**moyenne**
-----------

**Synonyms:** champ_post_statistiques_moyenne

**Inherits from:** :ref:`champ_generique_base` 


to calculate the average of the field over time

Parameters are:

- **[moyenne_convergee]**  (*type:* :ref:`field_base`) This option allows to read a converged time averaged field in a .xyz  file in order to calculate, when resuming the calculation, the statistics fields (rms,  correlation) which depend on this average. In that case, the time averaged field is not updated during the resume of calculation. In this case, the time averaged field must be fully converged to avoid errors when  calculating high order statistics.

- **t_deb**  (*type:* double) Start of integration time

- **t_fin**  (*type:* double) End of integration time

- **[source]**  (*type:* :ref:`champ_generique_base`) the source field.

- **[nom_source]**  (*type:* string) To name a source field with the nom_source keyword

- **[source_reference]**  (*type:* string) not_set

- **[sources_reference]**  (*type:* :ref:`list_nom_virgule`) not_set

- **[sources]**  (*type:* :ref:`listchamp_generique`) sources { Champ_Post.... { ... } Champ_Post.. { ... }}


----

**predefini**
-------------
**Inherits from:** :ref:`champ_generique_base` 


This keyword is used to post process predefined postprocessing fields.

Parameters are:

- **pb_champ**  (*type:* :ref:`deuxmots`) { Pb_champ nom_pb nom_champ } : nom_pb is the problem name and nom_champ  is the selected field name. The available keywords for the field name are: energie_cinetique_totale, energie_cinetique_elem,  viscosite_turbulente, viscous_force_x, viscous_force_y, viscous_force_z, pressure_force_x,  pressure_force_y, pressure_force_z, total_force_x, total_force_y, total_force_z, viscous_force,  pressure_force, total_force


----

**reduction_0d**
----------------

**Synonyms:** champ_post_reduction_0d

**Inherits from:** :ref:`champ_generique_base` 


To calculate the min, max, sum, average, weighted sum, weighted average, weighted 
sum by porosity, weighted average by porosity, euclidian norm, normalized euclidian 
norm, L1 norm, L2 norm of a field.

Parameters are:

- **methode**  (*type:* :ref:`chaine(into=["min","max","moyenne","average","moyenne_ponderee","weighted_average","somme","sum","somme_ponderee","weighted_sum","somme_ponderee_porosite","weighted_sum_porosity","euclidian_norm","normalized_euclidian_norm","l1_norm","l2_norm","valeur_a_gauche","left_value"`) ]  name of the reduction method:  - min for the minimum value,  - max for the maximum value,  - average (or moyenne) for a mean,  - weighted_average (or moyenne_ponderee) for a mean ponderated by integration volumes,  e.g: cell volumes for temperature and pressure in VDF, volumes around faces for velocity  and temperature in VEF,  - sum (or somme) for the sum of all the values of the field,  - weighted_sum (or somme_ponderee) for a weighted sum (integral),  - weighted_average_porosity (or moyenne_ponderee_porosite) and weighted_sum_porosity  (or somme_ponderee_porosite) for the mean and sum weighted by the volumes of the elements,  only for ELEM localisation,  - euclidian_norm for the euclidian norm,  - normalized_euclidian_norm for the euclidian norm normalized,  - L1_norm for norm L1,  - L2_norm for norm L2

- **[source]**  (*type:* :ref:`champ_generique_base`) the source field.

- **[nom_source]**  (*type:* string) To name a source field with the nom_source keyword

- **[source_reference]**  (*type:* string) not_set

- **[sources_reference]**  (*type:* :ref:`list_nom_virgule`) not_set

- **[sources]**  (*type:* :ref:`listchamp_generique`) sources { Champ_Post.... { ... } Champ_Post.. { ... }}


----

**refchamp**
------------

**Synonyms:** champ_post_refchamp

**Inherits from:** :ref:`champ_generique_base` 


Field of prolem

Parameters are:

- **pb_champ**  (*type:* :ref:`deuxmots`) { Pb_champ nom_pb nom_champ } : nom_pb is the problem name and nom_champ  is the selected field name.

- **[nom_source]**  (*type:* string) The alias name for the field


----

**tparoi_vef**
--------------

**Synonyms:** champ_post_tparoi_vef

**Inherits from:** :ref:`champ_generique_base` 


This keyword is used to post process (only for VEF discretization) the temperature 
field with a slight difference on boundaries with Neumann condition where law of the 
wall is applied on the temperature field.
nom_pb is the problem name and field_name is the selected field name.
A keyword (temperature_physique) is available to post process this field without 
using Definition_champs.

Parameters are:

- **[source]**  (*type:* :ref:`champ_generique_base`) the source field.

- **[nom_source]**  (*type:* string) To name a source field with the nom_source keyword

- **[source_reference]**  (*type:* string) not_set

- **[sources_reference]**  (*type:* :ref:`list_nom_virgule`) not_set

- **[sources]**  (*type:* :ref:`listchamp_generique`) sources { Champ_Post.... { ... } Champ_Post.. { ... }}


----

**transformation**
------------------

**Synonyms:** champ_post_transformation

**Inherits from:** :ref:`champ_generique_base` 


To create a field with a transformation.

Parameters are:

- **methode**  (*type:* :ref:`chaine(into=["produit_scalaire","norme","vecteur","formule","composante"`) ] methode  norme : will calculate the norm of a vector given by a source field  methode produit_scalaire : will calculate the dot product of two vectors given by  two sources fields  methode composante numero integer : will create a field by extracting the integer  component of a field given by a source field  methode formule expression 1 : will create a scalar field located to elements using  expressions with x,y,z,t parameters and field names given by a source field or several  sources fields.  methode vecteur expression N f1(x,y,z,t) fN(x,y,z,t) : will create a vector field  located to elements by defining its N components with N expressions with x,y,z,t parameters  and field names given by a source field or several sources fields.

- **[expression]**  (*type:* string list) see methodes formule and vecteur

- **[numero]**  (*type:* int) see methode composante

- **[localisation]**  (*type:* string) type_loc indicate where is done the interpolation (elem for element or som  for node). The optional keyword methode is limited to calculer_champ_post for the moment

- **[source]**  (*type:* :ref:`champ_generique_base`) the source field.

- **[nom_source]**  (*type:* string) To name a source field with the nom_source keyword

- **[source_reference]**  (*type:* string) not_set

- **[sources_reference]**  (*type:* :ref:`list_nom_virgule`) not_set

- **[sources]**  (*type:* :ref:`listchamp_generique`) sources { Champ_Post.... { ... } Champ_Post.. { ... }}

