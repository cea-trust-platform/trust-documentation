objet_lecture
=============

**bloc_convection**
-------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **aco**  (*type:* :ref:`chaine(into=["{"`) ] Opening curly bracket.

- **operateur**  (*type:* :ref:`convection_deriv`) not_set

- **acof**  (*type:* :ref:`chaine(into=["}"`) ] Closing curly bracket.


----

**bloc_couronne**
-----------------
**Inherits from:** :ref:`objet_lecture` 


Class to create a couronne (2D).

Parameters are:

- **name**  (*type:* :ref:`chaine(into=["origine"`) ] Keyword to define the center of the circle.

- **origin | origine**  (*type:* :ref:`listf`) Center of the circle.

- **name3**  (*type:* :ref:`chaine(into=["ri"`) ] Keyword to define the interior radius.

- **ri**  (*type:* double) Interior radius.

- **name4**  (*type:* :ref:`chaine(into=["re"`) ] Keyword to define the exterior radius.

- **re**  (*type:* double) Exterior radius.


----

**bloc_criteres_convergence**
-----------------------------
**Inherits from:** :ref:`objet_lecture` 


Not set

Parameters are:

- **bloc_lecture**  (*type:* string) not_set


----

**bloc_decouper**
-----------------
**Inherits from:** :ref:`objet_lecture` 


Auxiliary class to cut a domain.

Parameters are:

- **[partitionneur | partition_tool]**  (*type:* :ref:`partitionneur_deriv`) Defines the partitionning algorithm (the effective C++ object  used is 'Partitionneur_ALGORITHM_NAME').

- **[larg_joint]**  (*type:* int) This keyword specifies the thickness of the virtual ghost domaine (data known  by one processor though not owned by it). The default value is 1 and is generally correct for all algorithms except the QUICK  convection scheme that require a thickness of 2. Since the 1.5.5 version, the VEF discretization imply also a thickness of 2 (except  VEF P0). Any non-zero positive value can be used, but the amount of data to store and exchange  between processors grows quickly with the thickness.

- **[nom_zones | zones_name]**  (*type:* string) Name of the files containing the different partition of the domain. The files will be :  name_0001.Zones  name_0002.Zones  ...  name_000n.Zones. If this keyword is not specified, the geometry is not written on disk (you might  just want to generate a 'ecrire_decoupage' or 'ecrire_lata').

- **[ecrire_decoupage]**  (*type:* string) After having called the partitionning algorithm, the resulting partition  is written on disk in the specified filename. See also partitionneur Fichier_Decoupage. This keyword is useful to change the partition numbers: first, you write the partition  into a file with the option ecrire_decoupage. This file contains the domaine number for each element's mesh. Then you can easily permute domaine numbers in this file. Then read the new partition to create the .Zones files with the Fichier_Decoupage  keyword.

- **[ecrire_lata]**  (*type:* string) not_set

- **[nb_parts_tot]**  (*type:* int) Keyword to generates N .Domaine files, instead of the default number M obtained  after the partitionning algorithm. N must be greater or equal to M. This option might be used to perform coupled parallel computations. Supplemental empty domaines from M to N-1 are created. This keyword is used when you want to run a parallel calculation on several domains  with for example, 2 processors on a first domain and 10 on the second domain because  the first domain is very small compare to second one. You will write Nb_parts 2 and Nb_parts_tot 10 for the first domain and Nb_parts 10  for the second domain.

- **[periodique]**  (*type:* string list) N BOUNDARY_NAME_1 BOUNDARY_NAME_2 ... : N is the number of boundary names given. Periodic boundaries must be declared by this method. The partitionning algorithm will ensure that facing nodes and faces in the periodic  boundaries are located on the same processor.

- **[reorder]**  (*type:* int) If this option is set to 1 (0 by default), the partition is renumbered in  order that the processes which communicate the most are nearer on the network. This may slighlty improves parallel performance.

- **[single_hdf]**  (*type:* flag) Optional keyword to enable you to write the partitioned domaines in a single  file in hdf5 format.

- **[print_more_infos]**  (*type:* int) If this option is set to 1 (0 by default), print infos about number of remote  elements (ghosts) and additional infos about the quality of partitionning. Warning, it slows down the cutting operations.


----

**bloc_diffusion**
------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **aco**  (*type:* :ref:`chaine(into=["{"`) ] Opening curly bracket.

- **[operateur]**  (*type:* :ref:`diffusion_deriv`) if none is specified, the diffusive scheme used is a 2nd-order scheme.

- **[op_implicite]**  (*type:* :ref:`op_implicite`) To have diffusive implicitation, it use Uzawa algorithm. Very useful when viscosity has large variations.

- **acof**  (*type:* :ref:`chaine(into=["}"`) ] Closing curly bracket.


----

**bloc_diffusion_standard**
---------------------------
**Inherits from:** :ref:`objet_lecture` 


grad_Ubar 1 makes the gradient calculated through the filtered values of velocity 
(P1-conform).NL2 nu 1 (respectively nut 1) takes the molecular viscosity (eddy viscosity) 
into account in the velocity gradient part of the diffusion expression.

nu_transp 1 (respectively nut_transp 1) takes the molecular viscosity (eddy viscosity) 
into account according in the TRANSPOSED velocity gradient part of the diffusion expression.NL2 
filtrer_resu 1 allows to filter the resulting diffusive fluxes contribution.

Parameters are:

- **mot1**  (*type:* :ref:`chaine(into=["grad_ubar","nu","nut","nu_transp","nut_transp","filtrer_resu"`) ] not_set

- **val1**  (*type:* :ref:`entier(into=[0,1`) ] not_set

- **mot2**  (*type:* :ref:`chaine(into=["grad_ubar","nu","nut","nu_transp","nut_transp","filtrer_resu"`) ] not_set

- **val2**  (*type:* :ref:`entier(into=[0,1`) ] not_set

- **mot3**  (*type:* :ref:`chaine(into=["grad_ubar","nu","nut","nu_transp","nut_transp","filtrer_resu"`) ] not_set

- **val3**  (*type:* :ref:`entier(into=[0,1`) ] not_set

- **mot4**  (*type:* :ref:`chaine(into=["grad_ubar","nu","nut","nu_transp","nut_transp","filtrer_resu"`) ] not_set

- **val4**  (*type:* :ref:`entier(into=[0,1`) ] not_set

- **mot5**  (*type:* :ref:`chaine(into=["grad_ubar","nu","nut","nu_transp","nut_transp","filtrer_resu"`) ] not_set

- **val5**  (*type:* :ref:`entier(into=[0,1`) ] not_set

- **mot6**  (*type:* :ref:`chaine(into=["grad_ubar","nu","nut","nu_transp","nut_transp","filtrer_resu"`) ] not_set

- **val6**  (*type:* :ref:`entier(into=[0,1`) ] not_set


----

**bloc_ef**
-----------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **mot1**  (*type:* :ref:`chaine(into=["transportant_bar","transporte_bar","filtrer_resu","antisym"`) ] not_set

- **val1**  (*type:* :ref:`entier(into=[0,1`) ] not_set

- **mot2**  (*type:* :ref:`chaine(into=["transportant_bar","transporte_bar","filtrer_resu","antisym"`) ] not_set

- **val2**  (*type:* :ref:`entier(into=[0,1`) ] not_set

- **mot3**  (*type:* :ref:`chaine(into=["transportant_bar","transporte_bar","filtrer_resu","antisym"`) ] not_set

- **val3**  (*type:* :ref:`entier(into=[0,1`) ] not_set

- **mot4**  (*type:* :ref:`chaine(into=["transportant_bar","transporte_bar","filtrer_resu","antisym"`) ] not_set

- **val4**  (*type:* :ref:`entier(into=[0,1`) ] not_set


----

**bloc_lec_champ_init_canal_sinal**
-----------------------------------
**Inherits from:** :ref:`objet_lecture` 


Parameters for the class champ_init_canal_sinal.

in 2D:

U=ucent*y(2h-y)/h/h

V=ampli_bruit*rand+ampli_sin*sin(omega*x)

rand: unpredictable value between -1 and 1.

in 3D:

U=ucent*y(2h-y)/h/h

V=ampli_bruit*rand1+ampli_sin*sin(omega*x)

W=ampli_bruit*rand2

rand1 and rand2: unpredictables values between -1 and 1.

Parameters are:

- **ucent**  (*type:* double) Velocity value at the center of the channel.

- **h**  (*type:* double) Half hength of the channel.

- **ampli_bruit**  (*type:* double) Amplitude for the disturbance.

- **[ampli_sin]**  (*type:* double) Amplitude for the sinusoidal disturbance (by default equals to ucent/10).

- **omega**  (*type:* double) Value of pulsation for the of the sinusoidal disturbance.

- **[dir_flow]**  (*type:* :ref:`entier(into=[0,1,2`) ] Flow direction for the initialization of the flow in a channel.  - if dir_flow=0, the flow direction is X  - if dir_flow=1, the flow direction is Y  - if dir_flow=2, the flow direction is Z  Default value for dir_flow is 0

- **[dir_wall]**  (*type:* :ref:`entier(into=[0,1,2`) ] Wall direction for the initialization of the flow in a channel.  - if dir_wall=0, the normal to the wall is in X direction  - if dir_wall=1, the normal to the wall is in Y direction  - if dir_wall=2, the normal to the wall is in Z direction  Default value for dir_flow is 1

- **[min_dir_flow]**  (*type:* double) Value of the minimum coordinate in the flow direction for the initialization  of the flow in a channel. Default value for dir_flow is 0.

- **[min_dir_wall]**  (*type:* double) Value of the minimum coordinate in the wall direction for the initialization  of the flow in a channel. Default value for dir_flow is 0.


----

**bloc_lecture**
----------------
**Inherits from:** :ref:`objet_lecture` 


to read between two braces

Parameters are:

- **bloc_lecture**  (*type:* string) not_set


----

**bloc_lecture_poro**
---------------------
**Inherits from:** :ref:`objet_lecture` 


Surface and volume porosity values.

Parameters are:

- **volumique**  (*type:* double) Volume porosity value.

- **surfacique**  (*type:* list) Surface porosity values (in X, Y, Z directions).


----

**bloc_origine_cotes**
----------------------
**Inherits from:** :ref:`objet_lecture` 


Class to create a rectangle (or a box).

Parameters are:

- **name**  (*type:* :ref:`chaine(into=["origine"`) ] Keyword to define the origin of the rectangle (or the box).

- **origin | origine**  (*type:* :ref:`listf`) Coordinates of the origin of the rectangle (or the box).

- **name2**  (*type:* :ref:`chaine(into=["cotes"`) ] Keyword to define the length along the axes.

- **cotes**  (*type:* :ref:`listf`) Length along the axes.


----

**bloc_pave**
-------------
**Inherits from:** :ref:`objet_lecture` 


Class to create a pave.

Parameters are:

- **[origine]**  (*type:* :ref:`listf`) Keyword to define the pave (block) origin, that is to say one of the 8 block  points (or 4 in a 2D coordinate system).

- **[longueurs]**  (*type:* :ref:`listf`) Keyword to define the block dimensions, that is to say knowing the origin,  length along the axes.

- **[nombre_de_noeuds]**  (*type:* int list - size is dimension) Keyword to define the discretization (nodenumber) in each direction.

- **[facteurs]**  (*type:* :ref:`listf`) Keyword to define stretching factors for mesh discretization in each direction. This is a real number which must be positive (by default 1.0). A stretching factor other than 1 allows refinement on one edge in one direction.

- **[symx]**  (*type:* flag) Keyword to define a block mesh that is symmetrical with respect to the YZ plane  (respectively Y-axis in 2D) passing through the block centre.

- **[symy]**  (*type:* flag) Keyword to define a block mesh that is symmetrical with respect to the XZ plane  (respectively X-axis in 2D) passing through the block centre.

- **[symz]**  (*type:* flag) Keyword defining a block mesh that is symmetrical with respect to the XY plane  passing through the block centre.

- **[xtanh]**  (*type:* double) Keyword to generate mesh with tanh (hyperbolic tangent) variation in the  X-direction.

- **[xtanh_dilatation]**  (*type:* :ref:`entier(into=[-1,0,1`) ] Keyword to generate mesh with tanh (hyperbolic tangent) variation  in the X-direction. xtanh_dilatation: The value may be -1,0,1 (0 by default): 0: coarse mesh at the middle  of the channel and smaller near the walls -1: coarse mesh at the left side of the  channel and smaller at the right side 1: coarse mesh at the right side of the channel  and smaller near the left side of the channel.

- **[xtanh_taille_premiere_maille]**  (*type:* double) Size of the first cell of the mesh with tanh (hyperbolic tangent) variation  in the X-direction.

- **[ytanh]**  (*type:* double) Keyword to generate mesh with tanh (hyperbolic tangent) variation in the  Y-direction.

- **[ytanh_dilatation]**  (*type:* :ref:`entier(into=[-1,0,1`) ] Keyword to generate mesh with tanh (hyperbolic tangent) variation  in the Y-direction. ytanh_dilatation: The value may be -1,0,1 (0 by default): 0: coarse mesh at the middle  of the channel and smaller near the walls -1: coarse mesh at the bottom of the channel  and smaller near the top 1: coarse mesh at the top of the channel and smaller near  the bottom.

- **[ytanh_taille_premiere_maille]**  (*type:* double) Size of the first cell of the mesh with tanh (hyperbolic tangent) variation  in the Y-direction.

- **[ztanh]**  (*type:* double) Keyword to generate mesh with tanh (hyperbolic tangent) variation in the  Z-direction.

- **[ztanh_dilatation]**  (*type:* :ref:`entier(into=[-1,0,1`) ] Keyword to generate mesh with tanh (hyperbolic tangent) variation  in the Z-direction. tanh_dilatation: The value may be -1,0,1 (0 by default): 0: coarse mesh at the middle  of the channel and smaller near the walls -1: coarse mesh at the back of the channel  and smaller near the front 1: coarse mesh at the front of the channel and smaller  near the back.

- **[ztanh_taille_premiere_maille]**  (*type:* double) Size of the first cell of the mesh with tanh (hyperbolic tangent) variation  in the Z-direction.


----

**bloc_pdf_model**
------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **eta**  (*type:* double) penalization coefficient

- **[temps_relaxation_coefficient_pdf]**  (*type:* double) time relaxation on the forcing term to help

- **[echelle_relaxation_coefficient_pdf]**  (*type:* double) time relaxation on the forcing term to help convergence

- **[local]**  (*type:* flag) rien whether the prescribed velocity is expressed in the global or local basis

- **[vitesse_imposee_data]**  (*type:* :ref:`field_base`) Prescribed velocity as a field

- **[vitesse_imposee_fonction]**  (*type:* :ref:`troismots`) Prescribed velocity as a set of ananlytical component


----

**bloc_sutherland**
-------------------
**Inherits from:** :ref:`objet_lecture` 


Sutherland law for viscosity mu(T)=mu0*((T0+C)/(T+C))*(T/T0)**1.5 and (optional) for 
conductivity lambda(T)=mu0*Cp/Prandtl*((T0+Slambda)/(T+Slambda))*(T/T0)**1.5

Parameters are:

- **problem_name**  (*type:* :ref:`pb_base`) Name of problem.

- **mu0**  (*type:* :ref:`chaine(into=["mu0"`) ] not_set

- **mu0_val**  (*type:* double) not_set

- **t0**  (*type:* :ref:`chaine(into=["t0"`) ] not_set

- **t0_val**  (*type:* double) not_set

- **[slambda]**  (*type:* :ref:`chaine(into=["slambda"`) ] not_set

- **[s]**  (*type:* double) not_set

- **c**  (*type:* :ref:`chaine(into=["c"`) ] not_set

- **c_val**  (*type:* double) not_set


----

**bloc_tube**
-------------
**Inherits from:** :ref:`objet_lecture` 


Class to create a tube (3D).

Parameters are:

- **name**  (*type:* :ref:`chaine(into=["origine"`) ] Keyword to define the center of the tube.

- **origin | origine**  (*type:* :ref:`listf`) Center of the tube.

- **name2**  (*type:* :ref:`chaine(into=["dir"`) ] Keyword to define the direction of the main axis.

- **direction**  (*type:* :ref:`chaine(into=["x","y","z"`) ] direction of the main axis X, Y or Z

- **name3**  (*type:* :ref:`chaine(into=["ri"`) ] Keyword to define the interior radius.

- **ri**  (*type:* double) Interior radius.

- **name4**  (*type:* :ref:`chaine(into=["re"`) ] Keyword to define the exterior radius.

- **re**  (*type:* double) Exterior radius.

- **name5**  (*type:* :ref:`chaine(into=["hauteur"`) ] Keyword to define the heigth of the tube.

- **h**  (*type:* double) Heigth of the tube.


----

**bord**
--------
**Inherits from:** :ref:`objet_lecture` 


The block side is not in contact with another block and boundary conditions are applied 
to it.

Parameters are:

- **nom**  (*type:* string) Name of block side.

- **defbord**  (*type:* :ref:`defbord`) Definition of block side.


----

**bord_base**
-------------
**Inherits from:** :ref:`objet_lecture` 


Basic class for block sides.
Block sides that are neither edges nor connectors are not specified.
The duplicate nodes of two blocks in contact are automatically recognized and deleted.

----

**bords_ecrire**
----------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **chaine**  (*type:* :ref:`chaine(into=["bords"`) ] not_set

- **bords**  (*type:* string list) Keyword to post-process only on some boundaries :  bords nb_bords boundary1 ... boundaryn  where  nb_bords : number of boundaries  boundary1 ... boundaryn : name of the boundaries.


----

**calcul**
----------
**Inherits from:** :ref:`objet_lecture` 


The centre of gravity will be calculated.

----

**canal**
---------
**Inherits from:** :ref:`objet_lecture` 


Keyword for statistics on a periodic plane channel.

Parameters are:

- **[dt_impr_moy_spat]**  (*type:* double) Period to print the spatial average (default value is 1e6).

- **[dt_impr_moy_temp]**  (*type:* double) Period to print the temporal average (default value is 1e6).

- **[debut_stat]**  (*type:* double) Time to start the temporal averaging (default value is 1e6).

- **[fin_stat]**  (*type:* double) Time to end the temporal averaging (default value is 1e6).

- **[pulsation_w]**  (*type:* double) Pulsation for phase averaging (in case of pulsating forcing term) (no  default value).

- **[nb_points_par_phase]**  (*type:* int) Number of samples to represent phase average all along a period (no default  value).

- **[reprise]**  (*type:* string) val_moy_temp_xxxxxx.sauv : Keyword to resume a calculation with previous  averaged quantities.  Note that for thermal and turbulent problems, averages on temperature and turbulent  viscosity are automatically calculated. To resume a calculation with phase averaging, val_moy_temp_xxxxxx.sauv_phase file  is required on the directory where the job is submitted (this last file will be then  automatically loaded by TRUST).


----

**centre_de_gravite**
---------------------
**Inherits from:** :ref:`objet_lecture` 


To specify the centre of gravity.

Parameters are:

- **point**  (*type:* :ref:`un_point`) A centre of gravity.


----

**champ_a_post**
----------------
**Inherits from:** :ref:`objet_lecture` 


Field to be post-processed.

Parameters are:

- **champ**  (*type:* string) Name of the post-processed field.

- **[localisation]**  (*type:* :ref:`chaine(into=["elem","som","faces"`) ] Localisation of post-processed field values:  The two available values are elem, som, or faces (LATA format only) used respectively  to select field values at mesh centres (CHAMPMAILLE type field in the lml file) or  at mesh nodes (CHAMPPOINT type field in the lml file). If no selection is made, localisation is set to som by default.


----

**champs_posts**
----------------
**Inherits from:** :ref:`objet_lecture` 


Field's write mode.

Parameters are:

- **[format]**  (*type:* :ref:`chaine(into=["binaire","formatte"`) ] Type of file.

- **mot**  (*type:* :ref:`chaine(into=["dt_post","nb_pas_dt_post"`) ] Keyword to set the kind of the field's  write frequency. Either a time period or a time step period.

- **period**  (*type:* string) Value of the period which can be like (2.*t).

- **champs | fields**  (*type:* :ref:`champs_a_post`) Post-processed fields.


----

**chmoy_faceperio**
-------------------
**Inherits from:** :ref:`objet_lecture` 


non documente

Parameters are:

- **bloc**  (*type:* :ref:`bloc_lecture`) not_set


----

**circle_3**
------------
**Inherits from:** :ref:`objet_lecture` 


Keyword to define several probes located on a circle (in 3-D space).

Parameters are:

- **nbr**  (*type:* int) Number of probes between teta1 and teta2 (angles given in degrees).

- **point_deb**  (*type:* :ref:`un_point`) Center of the circle.

- **direction**  (*type:* :ref:`entier(into=[0,1,2`) ] Axis normal to the circle plane (0:x axis, 1:y axis, 2:z axis).

- **radius**  (*type:* double) Radius of the circle.

- **theta1**  (*type:* double) First angle.

- **theta2**  (*type:* double) Second angle.


----

**circle**
----------
**Inherits from:** :ref:`objet_lecture` 


Keyword to define several probes located on a circle.

Parameters are:

- **nbr**  (*type:* int) Number of probes between teta1 and teta2 (angles given in degrees).

- **point_deb**  (*type:* :ref:`un_point`) Center of the circle.

- **[direction]**  (*type:* :ref:`entier(into=[0,1,2`) ] Axis normal to the circle plane (0:x axis, 1:y axis, 2:z axis).

- **radius**  (*type:* double) Radius of the circle.

- **theta1**  (*type:* double) First angle.

- **theta2**  (*type:* double) Second angle.


----

**coarsen_operator_uniform**
----------------------------
**Inherits from:** :ref:`objet_lecture` 


Object defining the uniform coarsening process of the given grid in IJK discretization

Parameters are:

- **[coarsen_operator_uniform]**  (*type:* string) not_set

- **aco**  (*type:* :ref:`chaine(into=["{"`) ] opening curly brace

- **[coarsen_i]**  (*type:* :ref:`chaine(into=["coarsen_i"`) ] not_set

- **[coarsen_i_val]**  (*type:* int) Integer indicating the number by which we will divide the number of elements  in the I direction (in order to obtain a coarser grid)

- **[coarsen_j]**  (*type:* :ref:`chaine(into=["coarsen_j"`) ] not_set

- **[coarsen_j_val]**  (*type:* int) Integer indicating the number by which we will divide the number of elements  in the J direction (in order to obtain a coarser grid)

- **[coarsen_k]**  (*type:* :ref:`chaine(into=["coarsen_k"`) ] not_set

- **[coarsen_k_val]**  (*type:* int) Integer indicating the number by which we will divide the number of elements  in the K direction (in order to obtain a coarser grid)

- **acof**  (*type:* :ref:`chaine(into=["}"`) ] closing curly brace


----

**condinit**
------------
**Inherits from:** :ref:`objet_lecture` 


Initial condition.

Parameters are:

- **nom**  (*type:* string) Name of initial condition field.

- **ch**  (*type:* :ref:`field_base`) Type field and the initial values.


----

**condlimlu**
-------------
**Inherits from:** :ref:`objet_lecture` 


Boundary condition specified.

Parameters are:

- **bord**  (*type:* string) Name of the edge where the boundary condition applies.

- **cl**  (*type:* :ref:`condlim_base`) Boundary condition at the boundary called bord (edge).


----

**convection_ale**
------------------

**Synonyms:** ale

**Inherits from:** :ref:`objet_lecture` 


A convective scheme for ALE (Arbitrary Lagrangian-Eulerian) framework.

Parameters are:

- **opconv**  (*type:* :ref:`bloc_convection`) Choice between: amont and muscl  Example: convection { ALE { amont } }


----

**convection_amont**
--------------------

**Synonyms:** amont

**Inherits from:** :ref:`objet_lecture` 


Keyword for upwind scheme for VDF or VEF discretizations.
In VEF discretization equivalent to generic amont for TRUST version 1.5 or later.
The previous upwind scheme can be used with the obsolete in future amont_old keyword.

----

**convection_amont_old**
------------------------

**Synonyms:** amont_old

**Inherits from:** :ref:`objet_lecture` 


Only for VEF discretization, obsolete keyword, see amont.

----

**convection_btd**
------------------

**Synonyms:** btd

**Inherits from:** :ref:`objet_lecture` 


Only for EF discretization.

Parameters are:

- **btd**  (*type:* double) not_set

- **facteur**  (*type:* double) not_set


----

**convection_centre4**
----------------------

**Synonyms:** centre4

**Inherits from:** :ref:`objet_lecture` 


For VDF and VEF discretizations.

----

**convection_centre**
---------------------

**Synonyms:** centre

**Inherits from:** :ref:`objet_lecture` 


For VDF and VEF discretizations.

----

**convection_centre_old**
-------------------------

**Synonyms:** centre_old

**Inherits from:** :ref:`objet_lecture` 


Only for VEF discretization.

----

**convection_deriv**
--------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

----

**convection_di_l2**
--------------------

**Synonyms:** di_l2

**Inherits from:** :ref:`objet_lecture` 


Only for VEF discretization.

----

**convection_ef**
-----------------

**Synonyms:** ef

**Inherits from:** :ref:`objet_lecture` 


For VEF calculations, a centred convective scheme based on Finite Elements formulation 
can be called through the following data:NL2

Convection { EF transportant_bar val transporte_bar val antisym val filtrer_resu 
val }NL2

This scheme is 2nd order accuracy (and get better the property of kinetic energy 
conservation).
Due to possible problems of instabilities phenomena, this scheme has to be coupled 
with stabilisation process (see Source_Qdm_lambdaup).These two last data are equivalent 
from a theoretical point of view in variationnal writing to : div(( u.
grad ub , vb) - (u.
grad vb, ub)), where vb corresponds to the filtered reference test functions.NL2

Remark:NL2 This class requires to define a filtering operator : see solveur_bar

Parameters are:

- **[mot1]**  (*type:* :ref:`chaine(into=["defaut_bar"`) ] equivalent to transportant_bar 0 transporte_bar 1 filtrer_resu  1 antisym 1

- **[bloc_ef]**  (*type:* :ref:`bloc_ef`) not_set


----

**convection_ef_stab**
----------------------

**Synonyms:** ef_stab

**Inherits from:** :ref:`objet_lecture` 


Keyword for a VEF convective scheme.

Parameters are:

- **[alpha]**  (*type:* double) To weight the scheme centering with the factor double (between 0 (full  centered) and 1 (mix between upwind and centered), by default 1). For scalar equation, it is adviced to use alpha=1 and for the momentum equation,  alpha=0.2 is adviced.

- **[test]**  (*type:* int) Developer option to compare old and new version of EF_stab

- **[tdivu]**  (*type:* flag) To have the convective operator calculated as div(TU)-TdivU(=UgradT).

- **[old]**  (*type:* flag) To use old version of EF_stab scheme (default no).

- **[volumes_etendus]**  (*type:* flag) Option for the scheme to use the extended volumes (default, yes).

- **[volumes_non_etendus]**  (*type:* flag) Option for the scheme to not use the extended volumes (default, no).

- **[amont_sous_zone]**  (*type:* :ref:`sous_zone`) Option to degenerate EF_stab scheme into Amont (upwind) scheme in  the sub zone of name sz_name. The sub zone may be located arbitrarily in the domain but the more often this option  will be activated in a zone where EF_stab scheme generates instabilities as for free  outlet for example.

- **[alpha_sous_zone]**  (*type:* :ref:`listsous_zone_valeur`) Option to change locally the alpha value on N sub-zones named  sub_zone_name_I. Generally, it is used to prevent from a local divergence by increasing locally the  alpha parameter.


----

**convection_generic**
----------------------

**Synonyms:** generic

**Inherits from:** :ref:`objet_lecture` 


Keyword for generic calling of upwind and muscl convective scheme in VEF discretization.
For muscl scheme, limiters and order for fluxes calculations have to be specified.
The available limiters are : minmod - vanleer -vanalbada - chakravarthy - superbee, 
and the order of accuracy is 1 or 2.
Note that chakravarthy is a non-symmetric limiter and superbee may engender results 
out of physical limits.
By consequence, these two limiters are not recommended.

Examples:

convection { generic amont }NL2 convection { generic muscl minmod 1 }NL2 convection 
{ generic muscl vanleer 2 }NL2

In case of results out of physical limits with muscl scheme (due for instance to 
strong non-conformal velocity flow field), user can redefine in data file a lower 
order and a smoother limiter, as : convection { generic muscl minmod 1 }

Parameters are:

- **type**  (*type:* :ref:`chaine(into=["amont","muscl","centre"`) ] type of scheme

- **[limiteur]**  (*type:* :ref:`chaine(into=["minmod","vanleer","vanalbada","chakravarthy","superbee"`) ] type of  limiter

- **[ordre]**  (*type:* :ref:`entier(into=[1,2,3`) ] order of accuracy

- **[alpha]**  (*type:* double) alpha


----

**convection_kquick**
---------------------

**Synonyms:** kquick

**Inherits from:** :ref:`objet_lecture` 


Only for VEF discretization.

----

**convection_muscl3**
---------------------

**Synonyms:** muscl3

**Inherits from:** :ref:`objet_lecture` 


Keyword for a scheme using a ponderation between muscl and center schemes in VEF.

Parameters are:

- **[alpha]**  (*type:* double) To weight the scheme centering with the factor double (between 0 (full  centered) and 1 (muscl), by default 1).


----

**convection_muscl**
--------------------

**Synonyms:** muscl

**Inherits from:** :ref:`objet_lecture` 


Keyword for muscl scheme in VEF discretization equivalent to generic muscl vanleer 
2 for the 1.5 version or later.
The previous muscl scheme can be used with the obsolete in future muscl_old keyword.

----

**convection_muscl_new**
------------------------

**Synonyms:** muscl_new

**Inherits from:** :ref:`objet_lecture` 


Only for VEF discretization.

----

**convection_muscl_old**
------------------------

**Synonyms:** muscl_old

**Inherits from:** :ref:`objet_lecture` 


Only for VEF discretization.

----

**convection_negligeable**
--------------------------

**Synonyms:** negligeable

**Inherits from:** :ref:`objet_lecture` 


For VDF and VEF discretizations.
Suppresses the convection operator.

----

**convection_quick**
--------------------

**Synonyms:** quick

**Inherits from:** :ref:`objet_lecture` 


Only for VDF discretization.

----

**convection_supg**
-------------------

**Synonyms:** supg

**Inherits from:** :ref:`objet_lecture` 


Only for EF discretization.

Parameters are:

- **facteur**  (*type:* double) not_set


----

**corps_postraitement**
-----------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **[fichier]**  (*type:* string) Name of file.

- **[format]**  (*type:* :ref:`chaine(into=["lml","lata","single_lata","lata_v2","med","med_major"`) ] This optional  parameter specifies the format of the output file. The basename used for the output file is the basename of the data file. For the fmt parameter, choices are lml or lata. A short description of each format can be found below. The default value is lml. single_lata is not compatible with 64 bits integer version.

- **[domaine]**  (*type:* string) This optional parameter specifies the domain on which the data should be  interpolated before it is written in the output file. The default is to write the data on the domain of the current problem (no interpolation).

- **[sous_domaine | sous_zone]**  (*type:* string) This optional parameter specifies the sub_domaine on which the data should  be interpolated before it is written in the output file. It is only available for sequential computation.

- **[parallele]**  (*type:* :ref:`chaine(into=["simple","multiple","mpi-io"`) ] Select simple (single file, sequential  write), multiple (several files, parallel write), or mpi-io (single file, parallel  write) for LATA format

- **[definition_champs]**  (*type:* :ref:`definition_champs`) Keyword to create new or more complex field for advanced postprocessing.

- **[definition_champs_fichier | definition_champs_file]**  (*type:* :ref:`definition_champs_fichier`) Definition_champs read from file.

- **[sondes | probes]**  (*type:* :ref:`sondes`) Probe.

- **[sondes_mobiles | mobile_probes]**  (*type:* :ref:`sondes`) Mobile probes useful for ALE, their positions will be updated in the mesh.

- **[sondes_fichier | probes_file]**  (*type:* :ref:`sondes_fichier`) Probe read in a file.

- **[deprecatedkeepduplicatedprobes]**  (*type:* int) Flag to not remove duplicated probes in .son files (1: keep duplicate probes,  0: remove duplicate probes)

- **[champs | fields]**  (*type:* :ref:`champs_posts`) Field's write mode.

- **[statistiques]**  (*type:* :ref:`stats_posts`) Statistics between two points fixed : start of integration time and  end of integration time.

- **[statistiques_en_serie]**  (*type:* :ref:`stats_serie_posts`) Statistics between two points not fixed : on period of integration.


----

**defbord_3**
-------------
**Inherits from:** :ref:`objet_lecture` 


2-D edge (plane) in the 3-D space.

Parameters are:

- **dir**  (*type:* :ref:`chaine(into=["x","y","z"`) ] Edge is perpendicular to this direction.

- **eq**  (*type:* :ref:`chaine(into=["="`) ] Equality sign.

- **pos**  (*type:* double) Position value.

- **pos2_min**  (*type:* double) Minimal value.

- **inf1**  (*type:* :ref:`chaine(into=["<="`) ] Less than or equal to sign.

- **dir2**  (*type:* :ref:`chaine(into=["x","y"`) ] Edge is parallel to this direction.

- **inf2**  (*type:* :ref:`chaine(into=["<="`) ] Less than or equal to sign.

- **pos2_max**  (*type:* double) Maximal value.

- **pos3_min**  (*type:* double) Minimal value.

- **inf3**  (*type:* :ref:`chaine(into=["<="`) ] Less than or equal to sign.

- **dir3**  (*type:* :ref:`chaine(into=["y","z"`) ] Edge is parallel to this direction.

- **inf4**  (*type:* :ref:`chaine(into=["<="`) ] Less than or equal to sign.

- **pos3_max**  (*type:* double) Maximal value.


----

**defbord**
-----------
**Inherits from:** :ref:`objet_lecture` 


Class to define an edge.

----

**definition_champ**
--------------------
**Inherits from:** :ref:`objet_lecture` 


Keyword to create new complex field for advanced postprocessing.

Parameters are:

- **name**  (*type:* string) The name of the new created field.

- **champ_generique**  (*type:* :ref:`champ_generique_base`) not_set


----

**definition_champs_fichier**
-----------------------------
**Inherits from:** :ref:`objet_lecture` 


Keyword to read definition_champs from a file

Parameters are:

- **fichier | file**  (*type:* string) name of file containing the definition of advanced fields


----

**deuxentiers**
---------------
**Inherits from:** :ref:`objet_lecture` 


Two integers.

Parameters are:

- **int1**  (*type:* int) First integer.

- **int2**  (*type:* int) Second integer.


----

**deuxmots**
------------
**Inherits from:** :ref:`objet_lecture` 


Two words.

Parameters are:

- **mot_1**  (*type:* string) First word.

- **mot_2**  (*type:* string) Second word.


----

**diffusion_deriv**
-------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

----

**diffusion_negligeable**
-------------------------

**Synonyms:** negligeable

**Inherits from:** :ref:`objet_lecture` 


the diffusivity will not taken in count

----

**diffusion_option**
--------------------

**Synonyms:** option

**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **bloc_lecture**  (*type:* :ref:`bloc_lecture`) not_set


----

**diffusion_p1ncp1b**
---------------------

**Synonyms:** p1ncp1b

**Inherits from:** :ref:`objet_lecture` 


not_set

----

**diffusion_stab**
------------------

**Synonyms:** stab

**Inherits from:** :ref:`objet_lecture` 


keyword allowing consistent and stable calculations even in case of obtuse angle meshes.

Parameters are:

- **[standard]**  (*type:* int) to recover the same results as calculations made by standard laminar diffusion  operator. However, no stabilization technique is used and calculations may be unstable when  working with obtuse angle meshes (by default 0)

- **[info]**  (*type:* int) developer option to get the stabilizing ratio (by default 0)

- **[new_jacobian]**  (*type:* int) when implicit time schemes are used, this option defines a new jacobian that  may be more suitable to get stationary solutions (by default 0)

- **[nu]**  (*type:* int) (respectively nut 1) takes the molecular viscosity (resp. eddy viscosity) into account in the velocity gradient part of the diffusion expression  (by default nu=1 and nut=1)

- **[nut]**  (*type:* int) not_set

- **[nu_transp]**  (*type:* int) (respectively nut_transp 1) takes the molecular viscosity (resp. eddy viscosity) into account in the transposed velocity gradient part of the diffusion  expression (by default nu_transp=0 and nut_transp=1)

- **[nut_transp]**  (*type:* int) not_set


----

**diffusion_standard**
----------------------

**Synonyms:** standard

**Inherits from:** :ref:`objet_lecture` 


A new keyword, intended for LES calculations, has been developed to optimise and parameterise 
each term of the diffusion operator.
Remark:NL2

1.
This class requires to define a filtering operator : see solveur_barNL2 2.
The former (original) version: diffusion { } -which omitted some of the term of the 
diffusion operator- can be recovered by using the following parameters in the new 
class :NL2 diffusion { standard grad_Ubar 0 nu 1 nut 1 nu_transp 0 nut_transp 1 filtrer_resu 
0}.

Parameters are:

- **[mot1]**  (*type:* :ref:`chaine(into=["defaut_bar"`) ] equivalent to grad_Ubar 1 nu 1 nut 1 nu_transp 1 nut_transp  1 filtrer_resu 1

- **[bloc_diffusion_standard]**  (*type:* :ref:`bloc_diffusion_standard`) not_set


----

**diffusion_turbulente_multiphase**
-----------------------------------

**Synonyms:** turbulente

**Inherits from:** :ref:`objet_lecture` 


Turbulent diffusion operator for multiphase problem

Parameters are:

- **[type]**  (*type:* :ref:`type_diffusion_turbulente_multiphase_deriv`) Turbulence model for multiphase problem


----

**difusion_p1b**
----------------

**Synonyms:** p1b

**Inherits from:** :ref:`objet_lecture` 


not_set

----

**domain**
----------
**Inherits from:** :ref:`objet_lecture` 


Class to reuse a domain.

Parameters are:

- **domain_name**  (*type:* :ref:`domaine`) Name of domain.


----

**dt_impr_ustar_mean_only**
---------------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **dt_impr**  (*type:* double) not_set

- **[boundaries]**  (*type:* string list) not_set


----

**ec**
------
**Inherits from:** :ref:`objet_lecture` 


Keyword to print total kinetic energy into the referential linked to the domain (keyword 
Ec).
In the case where the domain is moving into a Galilean referential, the keyword Ec_dans_repere_fixe 
will print total kinetic energy in the Galilean referential whereas Ec will print 
the value calculated into the moving referential linked to the domain

Parameters are:

- **[ec]**  (*type:* flag) not_set

- **[ec_dans_repere_fixe]**  (*type:* flag) not_set

- **[periode]**  (*type:* double) periode is the keyword to set the period of printing into the file datafile_Ec.son  or datafile_Ec_dans_repere_fixe.son.


----

**ecrire_fichier_xyz_valeur_param**
-----------------------------------
**Inherits from:** :ref:`objet_lecture` 


To write the values of a field for some boundaries in a text file.

The name of the files is pb_name_field_name_time.dat

Several Ecrire_fichier_xyz_valeur keywords may be written into an equation to write 
several fields.
This kind of files may be read by Champ_don_lu or Champ_front_lu for example.

Parameters are:

- **name**  (*type:* string) Name of the field to write (Champ_Inc, Champ_Fonc or a post_processed field).

- **dt_ecrire_fic**  (*type:* double) Time period for printing in the file.

- **[bords]**  (*type:* :ref:`bords_ecrire`) to post-process only on some boundaries


----

**entierfloat**
---------------
**Inherits from:** :ref:`objet_lecture` 


An integer and a real.

Parameters are:

- **the_int**  (*type:* int) Integer.

- **the_float**  (*type:* double) Real.


----

**epsilon**
-----------
**Inherits from:** :ref:`objet_lecture` 


Two points will be confused if the distance between them is less than eps.
By default, eps is set to 1e-12.
The keyword Epsilon allows an alternative value to be assigned to eps.

Parameters are:

- **eps**  (*type:* double) New value of precision.


----

**floatfloat**
--------------
**Inherits from:** :ref:`objet_lecture` 


Two reals.

Parameters are:

- **a**  (*type:* double) First real.

- **b**  (*type:* double) Second real.


----

**fonction_champ_reprise**
--------------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **mot**  (*type:* :ref:`chaine(into=["fonction"`) ] not_set

- **fonction**  (*type:* string list) n f1(val) f2(val) ... fn(val)] time


----

**form_a_nb_points**
--------------------
**Inherits from:** :ref:`objet_lecture` 


The structure fonction is calculated on nb points and we should add the 2 directions 
(0:OX, 1:OY, 2:OZ) constituting the homegeneity planes.
Example for channel flows, planes parallel to the walls.

Parameters are:

- **nb**  (*type:* :ref:`entier(into=[4`) ] Number of points.

- **dir1**  (*type:* :ref:`entier(max=2)`) First direction.

- **dir2**  (*type:* :ref:`entier(max=2)`) Second direction.


----

**format_file**
---------------
**Inherits from:** :ref:`objet_lecture` 


File formatted.

Parameters are:

- **[format]**  (*type:* :ref:`chaine(into=["binaire","formatte","xyz","single_hdf"`) ] Type of file (the file format).

- **name_file**  (*type:* string) Name of file.


----

**format_lata_to_med**
----------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **mot**  (*type:* :ref:`chaine(into=["format_post_sup"`) ] not_set

- **[format]**  (*type:* :ref:`chaine(into=["lml","lata","lata_v2","med"`) ] generated file post_med.data use format  (MED or LATA or LML keyword).


----

**fourfloat**
-------------
**Inherits from:** :ref:`objet_lecture` 


Four reals.

Parameters are:

- **a**  (*type:* double) First real.

- **b**  (*type:* double) Second real.

- **c**  (*type:* double) Third real.

- **d**  (*type:* double) Fourth real.


----

**info_med**
------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **file_med**  (*type:* string) Name of the MED file.

- **domaine**  (*type:* string) Name of domain.

- **pb_post**  (*type:* :ref:`pb_post`) not_set


----

**internes**
------------
**Inherits from:** :ref:`objet_lecture` 


To indicate that the block has a set of internal faces (these faces will be duplicated 
automatically by the program and will be processed in a manner similar to edge faces).

Two boundaries with the same boundary conditions may have the same name (whether 
or not they belong to the same block).

The keyword Internes (Internal) must be used to execute a calculation with plates, 
followed by the equation of the surface area covered by the plates.

Parameters are:

- **nom**  (*type:* string) Name of block side.

- **defbord**  (*type:* :ref:`defbord`) Definition of block side.


----

**lecture_bloc_moment_base**
----------------------------
**Inherits from:** :ref:`objet_lecture` 


Auxiliary class to compute and print the moments.

----

**longitudinale**
-----------------
**Inherits from:** :ref:`objet_lecture` 


Class to define the pressure loss in the direction of the tube bundle.

Parameters are:

- **dir**  (*type:* :ref:`chaine(into=["x","y","z"`) ] Direction.

- **dd**  (*type:* double) Tube bundle hydraulic diameter value. This value is expressed in m.

- **ch_a**  (*type:* :ref:`chaine(into=["a","cf"`) ] Keyword to be used to set law coefficient values for the  coefficient of regular pressure losses.

- **a**  (*type:* double) Value of a law coefficient for regular pressure losses.

- **[ch_b]**  (*type:* :ref:`chaine(into=["b"`) ] Keyword to be used to set law coefficient values for regular  pressure losses.

- **[b]**  (*type:* double) Value of a law coefficient for regular pressure losses.


----

**mailler_base**
----------------
**Inherits from:** :ref:`objet_lecture` 


Basic class to mesh.

----

**methode_loi_horaire**
-----------------------

**Synonyms:** loi_horaire

**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **nom_loi**  (*type:* :ref:`loi_horaire`) not_set


----

**methode_transport_deriv**
---------------------------
**Inherits from:** :ref:`objet_lecture` 


Basic class for method of transport of interface.

----

**modele_turbulence_hyd_deriv**
-------------------------------
**Inherits from:** :ref:`objet_lecture` 


Basic class for turbulence model for Navier-Stokes equations.

Parameters are:

- **[correction_visco_turb_pour_controle_pas_de_temps]**  (*type:* flag) Keyword to set a limitation to low time steps due to high values of turbulent  viscosity. The limit for turbulent viscosity is calculated so that diffusive time-step is equal  or higher than convective time-step. For a stationary flow, the correction for turbulent viscosity should apply only during  the first time steps and not when permanent state is reached. To check that, we could post process the corr_visco_turb field which is the correction  of turbulent viscosity: it should be 1. on the whole domain.

- **[correction_visco_turb_pour_controle_pas_de_temps_parametre]**  (*type:* double) Keyword to set a limitation to low time steps due to high values of turbulent  viscosity. The limit for turbulent viscosity is the ratio between diffusive time-step and convective  time-step is higher or equal to the given value [0-1]

- **[turbulence_paroi]**  (*type:* :ref:`turbulence_paroi_base`) Keyword to set the wall law.

- **[dt_impr_ustar]**  (*type:* double) This keyword is used to print the values (U +, d+, u$\star$) obtained  with the wall laws into a file named datafile_ProblemName_Ustar.face and periode refers  to the printing period, this value is expressed in seconds.

- **[dt_impr_ustar_mean_only]**  (*type:* :ref:`dt_impr_ustar_mean_only`) This keyword is used to print the mean values of u* ( obtained  with the wall laws) on each boundary, into a file named datafile_ProblemName_Ustar_mean_only.out. periode refers to the printing period, this value is expressed in seconds. If you don't use the optional keyword boundaries, all the boundaries will be considered. If you use it, you must specify nb_boundaries which is the number of boundaries on  which you want to calculate the mean values of u*, then you have to specify their  names.

- **[nut_max]**  (*type:* double) Upper limitation of turbulent viscosity (default value 1.e8).


----

**modele_turbulence_hyd_nul**
-----------------------------

**Synonyms:** null

**Inherits from:** :ref:`objet_lecture` 


Nul turbulence model (turbulent viscosity = 0) which can be used with a turbulent 
problem.

Parameters are:

- **[correction_visco_turb_pour_controle_pas_de_temps]**  (*type:* flag) Keyword to set a limitation to low time steps due to high values of turbulent  viscosity. The limit for turbulent viscosity is calculated so that diffusive time-step is equal  or higher than convective time-step. For a stationary flow, the correction for turbulent viscosity should apply only during  the first time steps and not when permanent state is reached. To check that, we could post process the corr_visco_turb field which is the correction  of turbulent viscosity: it should be 1. on the whole domain.

- **[correction_visco_turb_pour_controle_pas_de_temps_parametre]**  (*type:* double) Keyword to set a limitation to low time steps due to high values of turbulent  viscosity. The limit for turbulent viscosity is the ratio between diffusive time-step and convective  time-step is higher or equal to the given value [0-1]

- **[turbulence_paroi]**  (*type:* :ref:`turbulence_paroi_base`) Keyword to set the wall law.

- **[dt_impr_ustar]**  (*type:* double) This keyword is used to print the values (U +, d+, u$\star$) obtained  with the wall laws into a file named datafile_ProblemName_Ustar.face and periode refers  to the printing period, this value is expressed in seconds.

- **[dt_impr_ustar_mean_only]**  (*type:* :ref:`dt_impr_ustar_mean_only`) This keyword is used to print the mean values of u* ( obtained  with the wall laws) on each boundary, into a file named datafile_ProblemName_Ustar_mean_only.out. periode refers to the printing period, this value is expressed in seconds. If you don't use the optional keyword boundaries, all the boundaries will be considered. If you use it, you must specify nb_boundaries which is the number of boundaries on  which you want to calculate the mean values of u*, then you have to specify their  names.

- **[nut_max]**  (*type:* double) Upper limitation of turbulent viscosity (default value 1.e8).


----

**nom_postraitement**
---------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **nom**  (*type:* string) Name of the post-processing.

- **post**  (*type:* :ref:`postraitement_base`) the post


----

**numero_elem_sur_maitre**
--------------------------
**Inherits from:** :ref:`objet_lecture` 


Keyword to define a probe at the special element.
Useful for min/max sonde.

Parameters are:

- **numero**  (*type:* int) element number


----

**objet_lecture**
-----------------
**Inherits from:** :ref:`objet_lecture` 


Auxiliary class for reading.

----

**op_implicite**
----------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **implicite**  (*type:* :ref:`chaine(into=["implicite"`) ] not_set

- **mot**  (*type:* :ref:`chaine(into=["solveur"`) ] not_set

- **solveur**  (*type:* :ref:`solveur_sys_base`) not_set


----

**parametre_diffusion_implicite**
---------------------------------
**Inherits from:** :ref:`objet_lecture` 


To specify additional parameters for the equation when using impliciting diffusion

Parameters are:

- **[crank]**  (*type:* :ref:`entier(into=[0,1`) ] Use (1) or not (0, default) a Crank Nicholson method for the  diffusion implicitation algorithm. Setting crank to 1 increases the order of the algorithm from 1 to 2.

- **[preconditionnement_diag]**  (*type:* :ref:`entier(into=[0,1`) ] The CG used to solve the implicitation of the equation diffusion  operator is not preconditioned by default. If this option is set to 1, a diagonal preconditionning is used. Warning: this option is not necessarily more efficient, depending on the treated  case.

- **[niter_max_diffusion_implicite]**  (*type:* int) Change the maximum number of iterations for the CG (Conjugate Gradient) algorithm  when solving the diffusion implicitation of the equation.

- **[seuil_diffusion_implicite]**  (*type:* double) Change the threshold convergence value used by default for the CG resolution  for the diffusion implicitation of this equation.

- **[solveur]**  (*type:* :ref:`solveur_sys_base`) Method (different from the default one, Conjugate Gradient) to  solve the linear system.


----

**parametre_equation_base**
---------------------------
**Inherits from:** :ref:`objet_lecture` 


Basic class for parametre_equation

----

**parametre_implicite**
-----------------------
**Inherits from:** :ref:`objet_lecture` 


Keyword to change for this equation only the parameter of the implicit scheme used 
to solve the problem.

Parameters are:

- **[seuil_convergence_implicite]**  (*type:* double) Keyword to change for this equation only the value of seuil_convergence_implicite  used in the implicit scheme.

- **[seuil_convergence_solveur]**  (*type:* double) Keyword to change for this equation only the value of seuil_convergence_solveur  used in the implicit scheme

- **[solveur]**  (*type:* :ref:`solveur_sys_base`) Keyword to change for this equation only the solver used in the  implicit scheme

- **[resolution_explicite]**  (*type:* flag) To solve explicitly the equation whereas the scheme is an implicit scheme.

- **[equation_non_resolue]**  (*type:* flag) Keyword to specify that the equation is not solved.

- **[equation_frequence_resolue]**  (*type:* string) Keyword to specify that the equation is solved only every n time steps (n  is an integer or given by a time-dependent function f(t)).


----

**pave**
--------
**Inherits from:** :ref:`objet_lecture` 


Class to create a pave (block) with boundaries.

Parameters are:

- **name**  (*type:* string) Name of the pave (block).

- **bloc**  (*type:* :ref:`bloc_pave`) Definition of the pave (block).

- **list_bord**  (*type:* :ref:`list_bord`) Domain boundaries definition.


----

**penalisation_l2_ftd_lec**
---------------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **[postraiter_gradient_pression_sans_masse]**  (*type:* int) (IBM advanced) avoid mass matrix multiplication for the gradient postprocessing

- **[correction_matrice_projection_initiale]**  (*type:* int) (IBM advanced) fix matrix of initial projection for PDF

- **[correction_calcul_pression_initiale]**  (*type:* int) (IBM advanced) fix initial pressure computation for PDF

- **[correction_vitesse_projection_initiale]**  (*type:* int) (IBM advanced) fix initial velocity computation for PDF

- **[correction_matrice_pression]**  (*type:* int) (IBM advanced) fix pressure matrix for PDF

- **[matrice_pression_penalisee_h1]**  (*type:* int) (IBM advanced) fix pressure matrix for PDF

- **[correction_vitesse_modifie]**  (*type:* int) (IBM advanced) fix velocity for PDF

- **[correction_pression_modifie]**  (*type:* int) (IBM advanced) fix pressure for PDF

- **[gradient_pression_qdm_modifie]**  (*type:* int) (IBM advanced) fix pressure gradient

- **bord**  (*type:* string) not_set

- **val**  (*type:* list) not_set


----

**plan**
--------
**Inherits from:** :ref:`objet_lecture` 


Keyword to set the number of probe layout points.
The file format is type .lml

Parameters are:

- **nbr**  (*type:* int) Number of probes in the first direction.

- **nbr2**  (*type:* int) Number of probes in the second direction.

- **point_deb**  (*type:* :ref:`un_point`) First point defining the angle. This angle should be positive.

- **point_fin**  (*type:* :ref:`un_point`) Second point defining the angle. This angle should be positive.

- **point_fin_2**  (*type:* :ref:`un_point`) Third point defining the angle. This angle should be positive.


----

**point**
---------
**Inherits from:** :ref:`objet_lecture` 


Point as class-daughter of Points.

Parameters are:

- **points**  (*type:* :ref:`listpoints`) Probe points.


----

**points**
----------
**Inherits from:** :ref:`objet_lecture` 


Keyword to define the number of probe points.
The file is arranged in columns.

Parameters are:

- **points**  (*type:* :ref:`listpoints`) Probe points.


----

**position_like**
-----------------
**Inherits from:** :ref:`objet_lecture` 


Keyword to define a probe at the same position of another probe named autre_sonde.

Parameters are:

- **autre_sonde**  (*type:* string) Name of the other probe.


----

**postraitement**
-----------------

**Synonyms:** post_processing

**Inherits from:** :ref:`objet_lecture` 


An object of post-processing (without name).

Parameters are:

- **[fichier]**  (*type:* string) Name of file.

- **[format]**  (*type:* :ref:`chaine(into=["lml","lata","single_lata","lata_v2","med","med_major"`) ] This optional  parameter specifies the format of the output file. The basename used for the output file is the basename of the data file. For the fmt parameter, choices are lml or lata. A short description of each format can be found below. The default value is lml. single_lata is not compatible with 64 bits integer version.

- **[domaine]**  (*type:* string) This optional parameter specifies the domain on which the data should be  interpolated before it is written in the output file. The default is to write the data on the domain of the current problem (no interpolation).

- **[sous_domaine | sous_zone]**  (*type:* string) This optional parameter specifies the sub_domaine on which the data should  be interpolated before it is written in the output file. It is only available for sequential computation.

- **[parallele]**  (*type:* :ref:`chaine(into=["simple","multiple","mpi-io"`) ] Select simple (single file, sequential  write), multiple (several files, parallel write), or mpi-io (single file, parallel  write) for LATA format

- **[definition_champs]**  (*type:* :ref:`definition_champs`) Keyword to create new or more complex field for advanced postprocessing.

- **[definition_champs_fichier | definition_champs_file]**  (*type:* :ref:`definition_champs_fichier`) Definition_champs read from file.

- **[sondes | probes]**  (*type:* :ref:`sondes`) Probe.

- **[sondes_mobiles | mobile_probes]**  (*type:* :ref:`sondes`) Mobile probes useful for ALE, their positions will be updated in the mesh.

- **[sondes_fichier | probes_file]**  (*type:* :ref:`sondes_fichier`) Probe read in a file.

- **[deprecatedkeepduplicatedprobes]**  (*type:* int) Flag to not remove duplicated probes in .son files (1: keep duplicate probes,  0: remove duplicate probes)

- **[champs | fields]**  (*type:* :ref:`champs_posts`) Field's write mode.

- **[statistiques]**  (*type:* :ref:`stats_posts`) Statistics between two points fixed : start of integration time and  end of integration time.

- **[statistiques_en_serie]**  (*type:* :ref:`stats_serie_posts`) Statistics between two points not fixed : on period of integration.


----

**postraitement_base**
----------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

----

**raccord**
-----------
**Inherits from:** :ref:`objet_lecture` 


The block side is in contact with the block of another domain (case of two coupled 
problems).

Parameters are:

- **type1**  (*type:* :ref:`chaine(into=["local","distant"`) ] Contact type.

- **type2**  (*type:* :ref:`chaine(into=["homogene"`) ] Contact type.

- **nom**  (*type:* string) Name of block side.

- **defbord**  (*type:* :ref:`defbord`) Definition of block side.


----

**radius**
----------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **nbr**  (*type:* int) Number of probe points of the segment, evenly distributed.

- **point_deb**  (*type:* :ref:`un_point`) First outer probe segment point.

- **radius**  (*type:* double) not_set

- **teta1**  (*type:* double) not_set

- **teta2**  (*type:* double) not_set


----

**reaction**
------------
**Inherits from:** :ref:`objet_lecture` 


Keyword to describe reaction:

w =K pow(T,beta) exp(-Ea/( R T)) $\Pi$ pow(Reactif_i,activitivity_i).

If K_inv >0,

w= K pow(T,beta) exp(-Ea/( R T)) ( $\Pi$ pow(Reactif_i,activitivity_i) - Kinv/exp(-c_r_Ea/(R 
T)) $\Pi$ pow(Produit_i,activitivity_i ))

Parameters are:

- **reactifs**  (*type:* string) LHS of equation (ex CH4+2*O2)

- **produits**  (*type:* string) RHS of equation (ex CO2+2*H20)

- **[constante_taux_reaction]**  (*type:* double) constante of cinetic K

- **[coefficients_activites]**  (*type:* :ref:`bloc_lecture`) coefficients od ativity (exemple { CH4 1 O2 2 })

- **enthalpie_reaction**  (*type:* double) DH

- **energie_activation**  (*type:* double) Ea

- **exposant_beta**  (*type:* double) Beta

- **[contre_reaction]**  (*type:* double) K_inv

- **[contre_energie_activation]**  (*type:* double) c_r_Ea


----

**remove_elem_bloc**
--------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **[liste]**  (*type:* int list) not_set

- **[fonction]**  (*type:* string) not_set


----

**segment**
-----------
**Inherits from:** :ref:`objet_lecture` 


Keyword to define the number of probe segment points.
The file is arranged in columns.

Parameters are:

- **nbr**  (*type:* int) Number of probe points of the segment, evenly distributed.

- **point_deb**  (*type:* :ref:`un_point`) First outer probe segment point.

- **point_fin**  (*type:* :ref:`un_point`) Second outer probe segment point.


----

**segmentfacesx**
-----------------
**Inherits from:** :ref:`objet_lecture` 


Segment probe where points are moved to the nearest x faces

Parameters are:

- **nbr**  (*type:* int) Number of probe points of the segment, evenly distributed.

- **point_deb**  (*type:* :ref:`un_point`) First outer probe segment point.

- **point_fin**  (*type:* :ref:`un_point`) Second outer probe segment point.


----

**segmentfacesy**
-----------------
**Inherits from:** :ref:`objet_lecture` 


Segment probe where points are moved to the nearest y faces

Parameters are:

- **nbr**  (*type:* int) Number of probe points of the segment, evenly distributed.

- **point_deb**  (*type:* :ref:`un_point`) First outer probe segment point.

- **point_fin**  (*type:* :ref:`un_point`) Second outer probe segment point.


----

**segmentfacesz**
-----------------
**Inherits from:** :ref:`objet_lecture` 


Segment probe where points are moved to the nearest z faces

Parameters are:

- **nbr**  (*type:* int) Number of probe points of the segment, evenly distributed.

- **point_deb**  (*type:* :ref:`un_point`) First outer probe segment point.

- **point_fin**  (*type:* :ref:`un_point`) Second outer probe segment point.


----

**segmentpoints**
-----------------
**Inherits from:** :ref:`objet_lecture` 


This keyword is used to define a probe segment from specifics points.
The nom_champ field is sampled at ns specifics points.

Parameters are:

- **points**  (*type:* :ref:`listpoints`) Probe points.


----

**sonde**
---------
**Inherits from:** :ref:`objet_lecture` 


Keyword is used to define the probes.
Observations: the probe coordinates should be given in Cartesian coordinates (X, 
Y, Z), including axisymmetric.

Parameters are:

- **nom_sonde**  (*type:* string) Name of the file in which the values taken over time will be saved. The complete file name is nom_sonde.son.

- **[special]**  (*type:* :ref:`chaine(into=["grav","som","nodes","chsom","gravcl"`) ] Option to change the positions  of the probes. Several options are available:  grav : each probe is moved to the nearest cell center of the mesh;  som : each probe is moved to the nearest vertex of the mesh  nodes : each probe is moved to the nearest face center of the mesh;  chsom : only available for P1NC sampled field. The values of the probes are calculated according to P1-Conform corresponding field.  gravcl : Extend to the domain face boundary a cell-located segment probe in order  to have the boundary condition for the field. For this type the extreme probe point has to be on the face center of gravity.

- **nom_inco**  (*type:* string) Name of the sampled field.

- **mperiode**  (*type:* :ref:`chaine(into=["periode"`) ] Keyword to set the sampled field measurement frequency.

- **prd**  (*type:* double) Period value. Every prd seconds, the field value calculated at the previous time step is written  to the nom_sonde.son file.

- **type**  (*type:* :ref:`sonde_base`) Type of probe.


----

**sonde_base**
--------------
**Inherits from:** :ref:`objet_lecture` 


Basic probe.
Probes refer to sensors that allow a value or several points of the domain to be 
monitored over time.
The probes may be a set of points defined one by one (keyword Points) or a set of 
points evenly distributed over a straight segment (keyword Segment) or arranged according 
to a layout (keyword Plan) or according to a parallelepiped (keyword Volume).
The fields allow all the values of a physical value on the domain to be known at 
several moments in time.

----

**sonde_tble**
--------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **name**  (*type:* string) not_set

- **point**  (*type:* :ref:`un_point`) not_set


----

**sondes_fichier**
------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **fichier | file**  (*type:* string) name of file


----

**sous_zone_valeur**
--------------------
**Inherits from:** :ref:`objet_lecture` 


Two words.

Parameters are:

- **sous_zone**  (*type:* :ref:`sous_zone`) sous zone

- **valeur**  (*type:* double) value


----

**spec_pdcr_base**
------------------
**Inherits from:** :ref:`objet_lecture` 


Class to read the source term modelling the presence of a bundle of tubes in a flow.
Cf=A Re-B.

Parameters are:

- **ch_a**  (*type:* :ref:`chaine(into=["a","cf"`) ] Keyword to be used to set law coefficient values for the  coefficient of regular pressure losses.

- **a**  (*type:* double) Value of a law coefficient for regular pressure losses.

- **[ch_b]**  (*type:* :ref:`chaine(into=["b"`) ] Keyword to be used to set law coefficient values for regular  pressure losses.

- **[b]**  (*type:* double) Value of a law coefficient for regular pressure losses.


----

**stat_post_correlation**
-------------------------

**Synonyms:** correlation, champ_post_statistiques_correlation

**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **first_field**  (*type:* string) not_set

- **second_field**  (*type:* string) not_set

- **[localisation]**  (*type:* :ref:`chaine(into=["elem","som","faces"`) ] Localisation of post-processed field value


----

**stat_post_deriv**
-------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

----

**stat_post_ecart_type**
------------------------

**Synonyms:** champ_post_statistiques_ecart_type, ecart_type

**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **field**  (*type:* string) not_set

- **[localisation]**  (*type:* :ref:`chaine(into=["elem","som","faces"`) ] Localisation of post-processed field value


----

**stat_post_moyenne**
---------------------

**Synonyms:** champ_post_statistiques_moyenne, moyenne

**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **field**  (*type:* string) not_set

- **[localisation]**  (*type:* :ref:`chaine(into=["elem","som","faces"`) ] Localisation of post-processed field value


----

**stat_post_t_deb**
-------------------

**Synonyms:** t_deb

**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **val**  (*type:* double) not_set


----

**stat_post_t_fin**
-------------------

**Synonyms:** t_fin

**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **val**  (*type:* double) not_set


----

**stats_posts**
---------------
**Inherits from:** :ref:`objet_lecture` 


Field's write mode.
\input{{statistiques}}

Parameters are:

- **mot**  (*type:* :ref:`chaine(into=["dt_post","nb_pas_dt_post"`) ] Keyword to set the kind of the field's  write frequency. Either a time period or a time step period.

- **period**  (*type:* string) Value of the period which can be like (2.*t).

- **champs | fields**  (*type:* :ref:`list_stat_post`) Post-processed fields.


----

**stats_serie_posts**
---------------------
**Inherits from:** :ref:`objet_lecture` 


Post-processing for statistics.
\input{{statistiquesseries}}

Parameters are:

- **mot**  (*type:* :ref:`chaine(into=["dt_integr"`) ] Keyword is used to set the statistics period of integration  and write period.

- **dt_integr**  (*type:* double) Average on dt_integr time interval is post-processed every dt_integr seconds.

- **stat**  (*type:* :ref:`list_stat_post`) not_set


----

**temperature**
---------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **bord**  (*type:* string) not_set

- **direction**  (*type:* int) not_set


----

**thi**
-------
**Inherits from:** :ref:`objet_lecture` 


Keyword for a THI (Homogeneous Isotropic Turbulence) calculation.

Parameters are:

- **init_ec**  (*type:* int) Keyword to renormalize initial velocity so that kinetic energy equals to  the value given by keyword val_Ec.

- **[val_ec]**  (*type:* double) Keyword to impose a value for kinetic energy by velocity renormalizated  if init_Ec value is 1.

- **[facon_init]**  (*type:* :ref:`entier(into=["0","1"`) ] Keyword to specify how kinetic energy is computed (0 or 1).

- **[calc_spectre]**  (*type:* :ref:`entier(into=["0","1"`) ] Calculate or not the spectrum of kinetic energy.  Files called Sorties_THI are written with inside four columns :  time:t global_kinetic_energy:Ec enstrophy:D skewness:S  If calc_spectre is set to 1, a file Sorties_THI2_2 is written with three columns  :  time:t kinetic_energy_at_kc=32 enstrophy_at_kc=32  If calc_spectre is set to 1, a file spectre_xxxxx is written with two columns at  each time xxxxx :  frequency:k energy:E(k).

- **[periode_calc_spectre]**  (*type:* double) Period for calculating spectrum of kinetic energy

- **[spectre_3d]**  (*type:* :ref:`entier(into=["0","1"`) ] Calculate or not the 3D spectrum

- **[spectre_1d]**  (*type:* :ref:`entier(into=["0","1"`) ] Calculate or not the 1D spectrum

- **[conservation_ec]**  (*type:* flag) If set to 1, velocity field will be changed as to have a constant kinetic energy  (default 0)

- **[longueur_boite]**  (*type:* double) Length of the calculation domain


----

**traitement_particulier**
--------------------------
**Inherits from:** :ref:`objet_lecture` 


Auxiliary class to post-process particular values.

Parameters are:

- **aco**  (*type:* :ref:`chaine(into=["{"`) ] Opening curly bracket.

- **trait_part**  (*type:* :ref:`traitement_particulier_base`) Type of traitement_particulier.

- **acof**  (*type:* :ref:`chaine(into=["}"`) ] Closing curly bracket.


----

**traitement_particulier_base**
-------------------------------
**Inherits from:** :ref:`objet_lecture` 


Basic class to post-process particular values.

----

**transversale**
----------------
**Inherits from:** :ref:`objet_lecture` 


Class to define the pressure loss in the direction perpendicular to the tube bundle.

Parameters are:

- **dir**  (*type:* :ref:`chaine(into=["x","y","z"`) ] Direction.

- **dd**  (*type:* double) Value of the tube bundle step.

- **chaine_d**  (*type:* :ref:`chaine(into=["d"`) ] Keyword to be used to set the value of the tube external diameter.

- **d**  (*type:* double) Value of the tube external diameter.

- **ch_a**  (*type:* :ref:`chaine(into=["a","cf"`) ] Keyword to be used to set law coefficient values for the  coefficient of regular pressure losses.

- **a**  (*type:* double) Value of a law coefficient for regular pressure losses.

- **[ch_b]**  (*type:* :ref:`chaine(into=["b"`) ] Keyword to be used to set law coefficient values for regular  pressure losses.

- **[b]**  (*type:* double) Value of a law coefficient for regular pressure losses.


----

**troisf**
----------
**Inherits from:** :ref:`objet_lecture` 


Auxiliary class to extrude.

Parameters are:

- **lx**  (*type:* double) X direction of the extrude operation.

- **ly**  (*type:* double) Y direction of the extrude operation.

- **lz**  (*type:* double) Z direction of the extrude operation.


----

**troismots**
-------------
**Inherits from:** :ref:`objet_lecture` 


Three words.

Parameters are:

- **mot_1**  (*type:* string) First word.

- **mot_2**  (*type:* string) Snd word.

- **mot_3**  (*type:* string) Third word.


----

**twofloat**
------------
**Inherits from:** :ref:`objet_lecture` 


two reals.

Parameters are:

- **a**  (*type:* double) First real.

- **b**  (*type:* double) Second real.


----

**type_diffusion_turbulente_multiphase_deriv**
----------------------------------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

----

**type_diffusion_turbulente_multiphase_l_melange**
--------------------------------------------------

**Synonyms:** l_melange

**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **[l_melange]**  (*type:* double) not_set


----

**type_diffusion_turbulente_multiphase_sgdh**
---------------------------------------------

**Synonyms:** sgdh

**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **[pr_t | prandtl_turbulent]**  (*type:* double) not_set

- **[sigma | sigma_turbulent]**  (*type:* double) not_set

- **[no_alpha]**  (*type:* flag) not_set

- **[gas_turb]**  (*type:* flag) not_set


----

**type_perte_charge_deriv**
---------------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

----

**type_perte_charge_dp**
------------------------

**Synonyms:** dp

**Inherits from:** :ref:`objet_lecture` 


DP field should have 3 components defining dp, dDP/dQ, Q0

Parameters are:

- **dp_field**  (*type:* :ref:`field_base`) the parameters of the previous formula (DP = dp + dDP/dQ * (Q - Q0)):  uniform_field 3 dp dDP/dQ Q0 where Q0 is a mass flow rate (kg/s).


----

**type_perte_charge_dp_regul**
------------------------------

**Synonyms:** dp_regul

**Inherits from:** :ref:`objet_lecture` 


Keyword used to regulate the DP value in order to match a target flow rate.
Syntax : dp_regul { DP0 d deb d eps e }

Parameters are:

- **dp0**  (*type:* double) initial value of DP

- **deb**  (*type:* string) target flow rate in kg/s

- **eps**  (*type:* string) strength of the regulation (low values might be slow to find the target flow  rate, high values might oscillate around the target value)


----

**type_postraitement_ft_lata**
------------------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **type**  (*type:* :ref:`chaine(into=["postraitement_ft_lata","postraitement_lata"`) ] not_set

- **nom**  (*type:* string) Name of the post-processing.

- **bloc**  (*type:* string) not_set


----

**type_un_post**
----------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **type**  (*type:* :ref:`chaine(into=["postraitement","post_processing"`) ] not_set

- **post**  (*type:* :ref:`un_postraitement`) not_set


----

**un_pb**
---------
**Inherits from:** :ref:`objet_lecture` 


pour les groupes

Parameters are:

- **mot**  (*type:* :ref:`pb_base`) the string


----

**un_point**
------------
**Inherits from:** :ref:`objet_lecture` 


A point.

Parameters are:

- **pos**  (*type:* :ref:`listf`) Point coordinates.


----

**un_postraitement**
--------------------
**Inherits from:** :ref:`objet_lecture` 


An object of post-processing (with name).

Parameters are:

- **nom**  (*type:* string) Name of the post-processing.

- **post**  (*type:* :ref:`corps_postraitement`) Definition of the post-processing.


----

**un_postraitement_spec**
-------------------------
**Inherits from:** :ref:`objet_lecture` 


An object of post-processing (with type +name).

Parameters are:

- **[type_un_post]**  (*type:* :ref:`type_un_post`) not_set

- **[type_postraitement_ft_lata]**  (*type:* :ref:`type_postraitement_ft_lata`) not_set


----

**verifiercoin_bloc**
---------------------
**Inherits from:** :ref:`objet_lecture` 


not_set

Parameters are:

- **[read_file | filename | lire_fichier]**  (*type:* string) name of the *.decoupage_som file

- **[expert_only]**  (*type:* flag) to not check the mesh


----

**volume**
----------
**Inherits from:** :ref:`objet_lecture` 


Keyword to define the probe volume in a parallelepiped passing through 4 points and 
the number of probes in each direction.

Parameters are:

- **nbr**  (*type:* int) Number of probes in the first direction.

- **nbr2**  (*type:* int) Number of probes in the second direction.

- **nbr3**  (*type:* int) Number of probes in the third direction.

- **point_deb**  (*type:* :ref:`un_point`) Point of origin.

- **point_fin**  (*type:* :ref:`un_point`) Point defining the first direction (from point of origin).

- **point_fin_2**  (*type:* :ref:`un_point`) Point defining the second direction (from point of origin).

- **point_fin_3**  (*type:* :ref:`un_point`) Point defining the third direction (from point of origin).

