source_base
===========

**acceleration**
----------------
**Inherits from:** :ref:`source_base` 


Momentum source term to take in account the forces due to rotation or translation 
of a non Galilean referential R' (centre 0') into the Galilean referential R (centre 
0).

Parameters are:

- **[vitesse]**  (*type:* :ref:`field_base`) Keyword for the velocity of the referential R' into the R referential  (dOO'/dt term [m.s-1]). The velocity is mandatory when you want to print the total cinetic energy into the  non-mobile Galilean referential R (see Ec_dans_repere_fixe keyword).

- **[acceleration]**  (*type:* :ref:`field_base`) Keyword for the acceleration of the referential R' into the R referential  (d2OO'/dt2 term [m.s-2]). field_base is a time dependant field (eg: Champ_Fonc_t).

- **[omega]**  (*type:* :ref:`field_base`) Keyword for a rotation of the referential R' into the R referential [rad.s-1]. field_base is a 3D time dependant field specified for example by a Champ_Fonc_t keyword. The time_field field should have 3 components even in 2D (In 2D: 0 0 omega).

- **[domegadt]**  (*type:* :ref:`field_base`) Keyword to define the time derivative of the previous rotation [rad.s-2]. Should be zero if the rotation is constant. The time_field field should have 3 components even in 2D (In 2D: 0 0 domegadt).

- **[centre_rotation]**  (*type:* :ref:`field_base`) Keyword to specify the centre of rotation (expressed in R' coordinates)  of R' into R (if the domain rotates with the R' referential, the centre of rotation  is 0'=(0,0,0)). The time_field should have 2 or 3 components according the dimension 2 or 3.

- **[option]**  (*type:* :ref:`chaine(into=["terme_complet","coriolis_seul","entrainement_seul"`) ] Keyword to specify  the kind of calculation: terme_complet (default option) will calculate both the Coriolis  and centrifugal forces, coriolis_seul will calculate the first one only, entrainement_seul  will calculate the second one only.


----

**boussinesq_concentration**
----------------------------
**Inherits from:** :ref:`source_base` 


Class to describe a source term that couples the movement quantity equation and constituent 
transport equation with the Boussinesq hypothesis.

Parameters are:

- **c0**  (*type:* list) Reference concentration field type. The only field type currently available is Champ_Uniforme (Uniform field).

- **[verif_boussinesq]**  (*type:* int) Keyword to check (1) or not (0) the reference concentration in comparison  with the mean concentration value in the domain. It is set to 1 by default.


----

**boussinesq_temperature**
--------------------------
**Inherits from:** :ref:`source_base` 


Class to describe a source term that couples the movement quantity equation and energy 
equation with the Boussinesq hypothesis.

Parameters are:

- **t0**  (*type:* string) Reference temperature value (oC or K). It can also be a time dependant function since the 1.6.6 version.

- **[verif_boussinesq]**  (*type:* int) Keyword to check (1) or not (0) the reference temperature in comparison with  the mean temperature value in the domain. It is set to 1 by default.


----

**canal_perio**
---------------
**Inherits from:** :ref:`source_base` 


Momentum source term to maintain flow rate.
The expression of the source term is:

S(t) = (2*(Q(0) - Q(t))-(Q(0)-Q(t-dt))/(coeff*dt*area)

NL2 Where:

coeff=damping coefficient

area=area of the periodic boundary

Q(t)=flow rate at time t

dt=time step

NL2 Three files will be created during calculation on a datafile named DataFile.data.
The first file contains the flow rate evolution.
The second file is useful for resuming a calculation with the flow rate of the previous 
stopped calculation, and the last one contains the pressure gradient evolution:

-DataFile_Channel_Flow_Rate_ProblemName_BoundaryName

-DataFile_Channel_Flow_Rate_repr_ProblemName_BoundaryName

-DataFile_Pressure_Gradient_ProblemName_BoundaryName

Parameters are:

- **bord**  (*type:* string) The name of the (periodic) boundary normal to the flow direction.

- **[h]**  (*type:* double) Half heigth of the channel.

- **[coeff]**  (*type:* double) Damping coefficient (optional, default value is 10).

- **[debit_impose]**  (*type:* double) Optional option to specify the aimed flow rate Q(0). If not used, Q(0) is computed by the code after the projection phase, where velocity  initial conditions are slighlty changed to verify incompressibility.


----

**coriolis**
------------
**Inherits from:** :ref:`source_base` 


Keyword for a Coriolis term in hydraulic equation.
Warning: Only available in VDF.

Parameters are:

- **omega**  (*type:* string) Value of omega.


----

**correction_antal**
--------------------
**Inherits from:** :ref:`source_base` 


Antal correction source term for multiphase problem

----

**darcy**
---------
**Inherits from:** :ref:`source_base` 


Class for calculation in a porous media with source term of Darcy -nu/K*V.
This keyword must be used with a permeability model.
For the moment there are two models : permeability constant or Ergun's law.
Darcy source term is available for quasi compressible calculation.
A new keyword is aded for porosity (porosite).

Parameters are:

- **bloc**  (*type:* :ref:`bloc_lecture`) Description.


----

**dirac**
---------
**Inherits from:** :ref:`source_base` 


Class to define a source term corresponding to a volume power release in the energy 
equation.

Parameters are:

- **position**  (*type:* list) not_set

- **ch**  (*type:* :ref:`field_base`) Thermal power field type. To impose a volume power on a domain sub-area, the Champ_Uniforme_Morceaux (partly_uniform_field)  type must be used.  Warning : The volume thermal power is expressed in W.m-3.


----

**dispersion_bulles**
---------------------
**Inherits from:** :ref:`source_base` 


Base class for source terms of bubble dispersion in momentum equation.

Parameters are:

- **[beta]**  (*type:* double) Mutliplying factor for the output of the bubble dispersion source term.


----

**dp_impose**
-------------
**Inherits from:** :ref:`source_base` 


Source term to impose a pressure difference according to the formula : DP = dp + dDP/dQ 
* (Q - Q0)

Parameters are:

- **aco**  (*type:* :ref:`chaine(into=["{"`) ] Opening curly bracket.

- **dp_type**  (*type:* :ref:`type_perte_charge_deriv`) mass flow rate (kg/s).

- **surface**  (*type:* :ref:`chaine(into=["surface"`) ] not_set

- **bloc_surface**  (*type:* :ref:`bloc_lecture`) Three syntaxes are possible for the surface definition block:  For VDF and VEF: { X|Y|Z = location subzone_name }  Only for VEF: { Surface surface_name }.  For polymac { Surface surface_name Orientation champ_uniforme }.

- **acof**  (*type:* :ref:`chaine(into=["}"`) ] Closing curly bracket.


----

**flux_interfacial**
--------------------
**Inherits from:** :ref:`source_base` 


Source term of mass transfer between phases connected by the saturation object defined 
in saturation_xxxx

----

**forchheimer**
---------------
**Inherits from:** :ref:`source_base` 


Class to add the source term of Forchheimer -Cf/sqrt(K)*V2 in the Navier-Stokes equations.
We must precise a permeability model : constant or Ergun's law.
Moreover we can give the constant Cf : by default its value is 1.
Forchheimer source term is available also for quasi compressible calculation.
A new keyword is aded for porosity (porosite).

Parameters are:

- **bloc**  (*type:* :ref:`bloc_lecture`) Description.


----

**frottement_interfacial**
--------------------------
**Inherits from:** :ref:`source_base` 


Source term which corresponds to the phases friction at the interface

Parameters are:

- **[a_res]**  (*type:* double) void fraction at which the gas velocity is forced to approach liquid velocity  (default alpha_evanescence*100)

- **[dv_min]**  (*type:* double) minimal relative velocity used to linearize interfacial friction at low  velocities

- **[exp_res]**  (*type:* int) exponent that callibrates intensity of velocity convergence (default 2)


----

**perte_charge_anisotrope**
---------------------------
**Inherits from:** :ref:`source_base` 


Anisotropic pressure loss.

Parameters are:

- **Lambda | lambda_u**  (*type:* string) Function for loss coefficient which may be Reynolds dependant (Ex: 64/Re).

- **lambda_ortho**  (*type:* string) Function for loss coefficient in transverse direction which may be Reynolds  dependant (Ex: 64/Re).

- **diam_hydr**  (*type:* :ref:`champ_don_base`) Hydraulic diameter value.

- **direction**  (*type:* :ref:`champ_don_base`) Field which indicates the direction of the pressure loss.

- **[sous_zone]**  (*type:* string) Optional sub-area where pressure loss applies.


----

**perte_charge_circulaire**
---------------------------
**Inherits from:** :ref:`source_base` 


New pressure loss.

Parameters are:

- **Lambda | lambda_u**  (*type:* string) Function f(Re_tot, Re_long, t, x, y, z) for loss coefficient in the longitudinal  direction

- **lambda_ortho**  (*type:* string) function: Function f(Re_tot, Re_ortho, t, x, y, z) for loss coefficient in  transverse direction

- **diam_hydr**  (*type:* :ref:`champ_don_base`) Hydraulic diameter value.

- **diam_hydr_ortho**  (*type:* :ref:`champ_don_base`) Transverse hydraulic diameter value.

- **direction**  (*type:* :ref:`champ_don_base`) Field which indicates the direction of the pressure loss.

- **[sous_zone]**  (*type:* string) Optional sub-area where pressure loss applies.


----

**perte_charge_directionnelle**
-------------------------------
**Inherits from:** :ref:`source_base` 


Directional pressure loss.

Parameters are:

- **Lambda | lambda_u**  (*type:* string) Function for loss coefficient which may be Reynolds dependant (Ex: 64/Re).

- **diam_hydr**  (*type:* :ref:`champ_don_base`) Hydraulic diameter value.

- **direction**  (*type:* :ref:`champ_don_base`) Field which indicates the direction of the pressure loss.

- **[sous_zone]**  (*type:* string) Optional sub-area where pressure loss applies.


----

**perte_charge_isotrope**
-------------------------
**Inherits from:** :ref:`source_base` 


Isotropic pressure loss.

Parameters are:

- **Lambda | lambda_u**  (*type:* string) Function for loss coefficient which may be Reynolds dependant (Ex: 64/Re).

- **diam_hydr**  (*type:* :ref:`champ_don_base`) Hydraulic diameter value.

- **[sous_zone]**  (*type:* string) Optional sub-area where pressure loss applies.


----

**perte_charge_reguliere**
--------------------------
**Inherits from:** :ref:`source_base` 


Source term modelling the presence of a bundle of tubes in a flow.

Parameters are:

- **spec**  (*type:* :ref:`spec_pdcr_base`) Description of longitudinale or transversale type.

- **zone_name | name_of_zone**  (*type:* string) Name of the sub-area occupied by the tube bundle. A Sous_Zone (Sub-area) type object called zone_name should have been previously created.


----

**perte_charge_singuliere**
---------------------------
**Inherits from:** :ref:`source_base` 


Source term that is used to model a pressure loss over a surface area (transition 
through a grid, sudden enlargement) defined by the faces of elements located on the 
intersection of a subzone named subzone_name and a X,Y, or Z plane located at X,Y 
or Z = location.

Parameters are:

- **dir**  (*type:* :ref:`chaine(into=["kx","ky","kz","k"`) ] KX, KY or KZ designate directional pressure loss  coefficients for respectively X, Y or Z direction. Or in the case where you chose a target flow rate with regul. Use K for isotropic pressure loss coefficient

- **[coeff]**  (*type:* double) Value (float) of friction coefficient (KX, KY, KZ).

- **[regul]**  (*type:* :ref:`bloc_lecture`) option to have adjustable K with flowrate target  { K0 valeur_initiale_de_k deb debit_cible eps intervalle_variation_mutiplicatif}.

- **surface**  (*type:* :ref:`bloc_lecture`) Three syntaxes are possible for the surface definition block:  For VDF and VEF: { X|Y|Z = location subzone_name }  Only for VEF: { Surface surface_name }.  For polymac { Surface surface_name Orientation champ_uniforme }


----

**portance_interfaciale**
-------------------------
**Inherits from:** :ref:`source_base` 


Base class for source term of lift force in momentum equation.

Parameters are:

- **[beta]**  (*type:* double) Multiplying factor for the bubble lift force source term.


----

**puissance_thermique**
-----------------------
**Inherits from:** :ref:`source_base` 


Class to define a source term corresponding to a volume power release in the energy 
equation.

Parameters are:

- **ch**  (*type:* :ref:`field_base`) Thermal power field type. To impose a volume power on a domain sub-area, the Champ_Uniforme_Morceaux (partly_uniform_field)  type must be used.  Warning : The volume thermal power is expressed in W.m-3 in 3D (in W.m-2 in 2D). It is a power per volume unit (in a porous media, it is a power per fluid volume  unit).


----

**radioactive_decay**
---------------------
**Inherits from:** :ref:`source_base` 


Radioactive decay source term of the form $-\lambda_i c_i$, where $0 \leq i \leq N$, 
N is the number of component of the constituent, $c_i$ and $\lambda_i$ are the concentration 
and the decay constant of the i-th component of the constituant.

Parameters are:

- **val**  (*type:* list) n is the number of decay constants to read (int), and val1, val2... are the decay constants (double)


----

**source_base**
---------------
**Inherits from:** :ref:`source_base` 


Basic class of source terms introduced in the equation.

----

**source_constituant**
----------------------
**Inherits from:** :ref:`source_base` 


Keyword to specify source rates, in [[C]/s], for each one of the nb constituents.
[C] is the concentration unit.

Parameters are:

- **ch**  (*type:* :ref:`field_base`) Field type.


----

**source_generique**
--------------------
**Inherits from:** :ref:`source_base` 


to define a source term depending on some discrete fields of the problem and (or) 
analytic expression.
It is expressed by the way of a generic field usually used for post-processing.

Parameters are:

- **champ**  (*type:* :ref:`champ_generique_base`) the source field


----

**source_pdf**
--------------
**Inherits from:** :ref:`source_base` 


Source term for Penalised Direct Forcing (PDF) method.

Parameters are:

- **aire**  (*type:* :ref:`field_base`) volumic field: a boolean for the cell (0 or 1) indicating if the obstacle  is in the cell

- **rotation**  (*type:* :ref:`field_base`) volumic field with 9 components representing the change of basis on cells  (local to global). Used for rotating cases for example.

- **[transpose_rotation]**  (*type:* flag) whether to transpose the basis change matrix.

- **modele**  (*type:* :ref:`bloc_pdf_model`) model used for the Penalized Direct Forcing

- **[interpolation]**  (*type:* :ref:`interpolation_ibm_base`) interpolation method


----

**source_pdf_base**
-------------------
**Inherits from:** :ref:`source_base` 


Base class of the source term for the Immersed Boundary Penalized Direct Forcing method 
(PDF)

Parameters are:

- **aire**  (*type:* :ref:`field_base`) volumic field: a boolean for the cell (0 or 1) indicating if the obstacle  is in the cell

- **rotation**  (*type:* :ref:`field_base`) volumic field with 9 components representing the change of basis on cells  (local to global). Used for rotating cases for example.

- **[transpose_rotation]**  (*type:* flag) whether to transpose the basis change matrix.

- **modele**  (*type:* :ref:`bloc_pdf_model`) model used for the Penalized Direct Forcing

- **[interpolation]**  (*type:* :ref:`interpolation_ibm_base`) interpolation method


----

**source_qdm**
--------------
**Inherits from:** :ref:`source_base` 


Momentum source term in the Navier-Stokes equations.

Parameters are:

- **ch | champ**  (*type:* :ref:`field_base`) Field type.


----

**source_qdm_lambdaup**
-----------------------
**Inherits from:** :ref:`source_base` 


This source term is a dissipative term which is intended to minimise the energy associated 
to non-conformscales u' (responsible for spurious oscillations in some cases).
The equation for these scales can be seen as: du'/dt= -lambda.
u' + grad P' where -lambda.
u' represents the dissipative term, with lambda = a/Delta t For Crank-Nicholson temporal 
scheme, recommended value for a is 2.

Remark : This method requires to define a filtering operator.

Parameters are:

- **Lambda | lambda_u**  (*type:* double) value of lambda

- **[lambda_min]**  (*type:* double) value of lambda_min

- **[lambda_max]**  (*type:* double) value of lambda_max

- **[ubar_umprim_cible]**  (*type:* double) value of ubar_umprim_cible


----

**source_robin**
----------------
**Inherits from:** :ref:`source_base` 


This source term should be used when a Paroi_decalee_Robin boundary condition is set 
in a hydraulic equation.
The source term will be applied on the N specified boundaries.
To post-process the values of tauw, u_tau and Reynolds_tau into the files tauw_robin.dat, 
reynolds_tau_robin.dat and u_tau_robin.dat, you must add a block Traitement_particulier 
{ canal { } }

Parameters are:

- **bords**  (*type:* :ref:`vect_nom`) not_set


----

**source_robin_scalaire**
-------------------------
**Inherits from:** :ref:`source_base` 


This source term should be used when a Paroi_decalee_Robin boundary condition is set 
in a an energy equation.
The source term will be applied on the N specified boundaries.
The values temp_wall_valueI are the temperature specified on the Ith boundary.
The last value dt_impr is a printing period which is mandatory to specify in the 
data file but has no effect yet.

Parameters are:

- **bords**  (*type:* :ref:`listdeuxmots_sacc`) not_set


----

**source_th_tdivu**
-------------------
**Inherits from:** :ref:`source_base` 


This term source is dedicated for any scalar (called T) transport.
Coupled with upwind (amont) or muscl scheme, this term gives for final expression 
of convection : div(U.T)-T.div (U)=U.grad(T) This ensures, in incompressible flow 
when divergence free is badly resolved, to stay in a better way in the physical boundaries.

Warning: Only available in VEF discretization.

----

**source_travail_pression_elem_base**
-------------------------------------
**Inherits from:** :ref:`source_base` 


Source term which corresponds to the additional pressure work term that appears when 
dealing with compressible multiphase fluids

----

**terme_puissance_thermique_echange_impose**
--------------------------------------------
**Inherits from:** :ref:`source_base` 


Source term to impose thermal power according to formula : P = himp * (T - Text).
Where T is the Trust temperature, Text is the outside temperature with which energy 
is exchanged via an exchange coefficient himp

Parameters are:

- **himp**  (*type:* :ref:`field_base`) the exchange coefficient

- **text**  (*type:* :ref:`field_base`) the outside temperature

- **[pid_controler_on_targer_power]**  (*type:* :ref:`bloc_lecture`) PID_controler_on_targer_power bloc with parameters target_power (required),  Kp, Ki and Kd (at least one of them should be provided)


----

**travail_pression**
--------------------
**Inherits from:** :ref:`source_base` 


Source term which corresponds to the additional pressure work term that appears when 
dealing with compressible multiphase fluids

----

**vitesse_derive_base**
-----------------------
**Inherits from:** :ref:`source_base` 


Source term which corresponds to the drift-velocity between a liquid and a gas phase

----

**vitesse_relative_base**
-------------------------
**Inherits from:** :ref:`source_base` 


Basic class for drift-velocity source term between a liquid and a gas phase
