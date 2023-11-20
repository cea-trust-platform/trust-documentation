milieu_base
===========

**constituant**
---------------
**Inherits from:** :ref:`milieu_base` 


Constituent.

Parameters are:

- **[rho]**  (*type:* :ref:`field_base`) Density (kg.m-3).

- **[cp]**  (*type:* :ref:`field_base`) Specific heat (J.kg-1.K-1).

- **[Lambda | lambda_u]**  (*type:* :ref:`field_base`) Conductivity (W.m-1.K-1).

- **[coefficient_diffusion]**  (*type:* :ref:`field_base`) Constituent diffusion coefficient value (m2.s-1). If a multi-constituent problem is being processed, the diffusivite will be a vectorial  and each components will be the diffusion of the constituent.

- **[gravite]**  (*type:* :ref:`field_base`) Gravity field (optional).

- **[porosites_champ]**  (*type:* :ref:`field_base`) The porosity is given at each element and the porosity at each face,  Psi(face), is calculated by the average of the porosities of the two neighbour elements  Psi(elem1), Psi(elem2) : Psi(face)=2/(1/Psi(elem1)+1/Psi(elem2)). This keyword is optional.

- **[diametre_hyd_champ]**  (*type:* :ref:`field_base`) Hydraulic diameter field (optional).

- **[porosites]**  (*type:* :ref:`porosites`) Porosities.


----

**fluide_base**
---------------
**Inherits from:** :ref:`milieu_base` 


Basic class for fluids.

Parameters are:

- **[indice]**  (*type:* :ref:`field_base`) Refractivity of fluid.

- **[kappa]**  (*type:* :ref:`field_base`) Absorptivity of fluid (m-1).

- **[gravite]**  (*type:* :ref:`field_base`) Gravity field (optional).

- **[porosites_champ]**  (*type:* :ref:`field_base`) The porosity is given at each element and the porosity at each face,  Psi(face), is calculated by the average of the porosities of the two neighbour elements  Psi(elem1), Psi(elem2) : Psi(face)=2/(1/Psi(elem1)+1/Psi(elem2)). This keyword is optional.

- **[diametre_hyd_champ]**  (*type:* :ref:`field_base`) Hydraulic diameter field (optional).

- **[porosites]**  (*type:* :ref:`porosites`) Porosities.


----

**fluide_dilatable_base**
-------------------------
**Inherits from:** :ref:`milieu_base` 


Basic class for dilatable fluids.

Parameters are:

- **[indice]**  (*type:* :ref:`field_base`) Refractivity of fluid.

- **[kappa]**  (*type:* :ref:`field_base`) Absorptivity of fluid (m-1).

- **[gravite]**  (*type:* :ref:`field_base`) Gravity field (optional).

- **[porosites_champ]**  (*type:* :ref:`field_base`) The porosity is given at each element and the porosity at each face,  Psi(face), is calculated by the average of the porosities of the two neighbour elements  Psi(elem1), Psi(elem2) : Psi(face)=2/(1/Psi(elem1)+1/Psi(elem2)). This keyword is optional.

- **[diametre_hyd_champ]**  (*type:* :ref:`field_base`) Hydraulic diameter field (optional).

- **[porosites]**  (*type:* :ref:`porosites`) Porosities.


----

**fluide_incompressible**
-------------------------
**Inherits from:** :ref:`milieu_base` 


Class for non-compressible fluids.

Parameters are:

- **[beta_th]**  (*type:* :ref:`field_base`) Thermal expansion (K-1).

- **[mu]**  (*type:* :ref:`field_base`) Dynamic viscosity (kg.m-1.s-1).

- **[beta_co]**  (*type:* :ref:`field_base`) Volume expansion coefficient values in concentration.

- **[rho]**  (*type:* :ref:`field_base`) Density (kg.m-3).

- **[cp]**  (*type:* :ref:`field_base`) Specific heat (J.kg-1.K-1).

- **[Lambda | lambda_u]**  (*type:* :ref:`field_base`) Conductivity (W.m-1.K-1).

- **[porosites]**  (*type:* :ref:`bloc_lecture`) Porosity (optional)

- **[indice]**  (*type:* :ref:`field_base`) Refractivity of fluid.

- **[kappa]**  (*type:* :ref:`field_base`) Absorptivity of fluid (m-1).

- **[gravite]**  (*type:* :ref:`field_base`) Gravity field (optional).

- **[porosites_champ]**  (*type:* :ref:`field_base`) The porosity is given at each element and the porosity at each face,  Psi(face), is calculated by the average of the porosities of the two neighbour elements  Psi(elem1), Psi(elem2) : Psi(face)=2/(1/Psi(elem1)+1/Psi(elem2)). This keyword is optional.

- **[diametre_hyd_champ]**  (*type:* :ref:`field_base`) Hydraulic diameter field (optional).


----

**fluide_ostwald**
------------------
**Inherits from:** :ref:`milieu_base` 


Non-Newtonian fluids governed by Ostwald's law.
The law applicable to stress tensor is:

tau=K(T)*(D:D/2)**((n-1)/2)*D Where:

D refers to the deformation tensor

K refers to fluid consistency (may be a function of the temperature T)

n refers to the fluid structure index n=1 for a Newtonian fluid, n<1 for a rheofluidifier 
fluid, n>1 for a rheothickening fluid.

Parameters are:

- **[k]**  (*type:* :ref:`field_base`) Fluid consistency.

- **[n]**  (*type:* :ref:`field_base`) Fluid structure index.

- **[beta_th]**  (*type:* :ref:`field_base`) Thermal expansion (K-1).

- **[mu]**  (*type:* :ref:`field_base`) Dynamic viscosity (kg.m-1.s-1).

- **[beta_co]**  (*type:* :ref:`field_base`) Volume expansion coefficient values in concentration.

- **[rho]**  (*type:* :ref:`field_base`) Density (kg.m-3).

- **[cp]**  (*type:* :ref:`field_base`) Specific heat (J.kg-1.K-1).

- **[Lambda | lambda_u]**  (*type:* :ref:`field_base`) Conductivity (W.m-1.K-1).

- **[porosites]**  (*type:* :ref:`bloc_lecture`) Porosity (optional)

- **[indice]**  (*type:* :ref:`field_base`) Refractivity of fluid.

- **[kappa]**  (*type:* :ref:`field_base`) Absorptivity of fluid (m-1).

- **[gravite]**  (*type:* :ref:`field_base`) Gravity field (optional).

- **[porosites_champ]**  (*type:* :ref:`field_base`) The porosity is given at each element and the porosity at each face,  Psi(face), is calculated by the average of the porosities of the two neighbour elements  Psi(elem1), Psi(elem2) : Psi(face)=2/(1/Psi(elem1)+1/Psi(elem2)). This keyword is optional.

- **[diametre_hyd_champ]**  (*type:* :ref:`field_base`) Hydraulic diameter field (optional).


----

**fluide_quasi_compressible**
-----------------------------
**Inherits from:** :ref:`milieu_base` 


Quasi-compressible flow with a low mach number assumption; this means that the thermo-dynamic 
pressure (used in state law) is uniform in space.

Parameters are:

- **[sutherland]**  (*type:* :ref:`bloc_sutherland`) Sutherland law for viscosity and for conductivity.

- **[pression]**  (*type:* double) Initial thermo-dynamic pressure used in the assosciated state law.

- **[loi_etat]**  (*type:* :ref:`loi_etat_base`) The state law that will be associated to the Quasi-compressible fluid.

- **[traitement_pth]**  (*type:* :ref:`chaine(into=["edo","constant","conservation_masse"`) ] Particular treatment for the  thermodynamic pressure Pth ; there are three possibilities:  1) with the keyword 'edo' the code computes Pth solving an O.D.E. ; in this case, the mass is not strictly conserved (it is the default case for quasi  compressible computation):  2) the keyword 'conservation_masse' forces the conservation of the mass (closed geometry  or with periodic boundaries condition)  3) the keyword 'constant' makes it possible to have a constant Pth ; it's the good  choice when the flow is open (e.g. with pressure boundary conditions).  It is possible to monitor the volume averaged value for temperature and density,  plus Pth evolution in the .evol_glob file.

- **[traitement_rho_gravite]**  (*type:* :ref:`chaine(into=["standard","moins_rho_moyen"`) ] It may be :1) \`standard\` : the gravity  term is evaluted with rho*g (It is the default). 2) \`moins_rho_moyen\` : the gravity term is evaluated with (rho-rhomoy) *g. Unknown pressure is then P*=P+rhomoy*g*z. It is useful when you apply uniforme pressure boundary condition like P*=0.

- **[temps_debut_prise_en_compte_drho_dt]**  (*type:* double) While time<value, dRho/dt is set to zero (Rho, volumic mass). Useful for some calculation during the first time steps with big variation of temperature  and volumic mass.

- **[omega_relaxation_drho_dt]**  (*type:* double) Optional option to have a relaxed algorithm to solve the mass equation. value is used (1 per default) to specify omega.

- **[Lambda | lambda_u]**  (*type:* :ref:`field_base`) Conductivity (W.m-1.K-1).

- **[mu]**  (*type:* :ref:`field_base`) Dynamic viscosity (kg.m-1.s-1).

- **[indice]**  (*type:* :ref:`field_base`) Refractivity of fluid.

- **[kappa]**  (*type:* :ref:`field_base`) Absorptivity of fluid (m-1).

- **[gravite]**  (*type:* :ref:`field_base`) Gravity field (optional).

- **[porosites_champ]**  (*type:* :ref:`field_base`) The porosity is given at each element and the porosity at each face,  Psi(face), is calculated by the average of the porosities of the two neighbour elements  Psi(elem1), Psi(elem2) : Psi(face)=2/(1/Psi(elem1)+1/Psi(elem2)). This keyword is optional.

- **[diametre_hyd_champ]**  (*type:* :ref:`field_base`) Hydraulic diameter field (optional).

- **[porosites]**  (*type:* :ref:`porosites`) Porosities.


----

**fluide_reel_base**
--------------------
**Inherits from:** :ref:`milieu_base` 


Class for real fluids.

Parameters are:

- **[indice]**  (*type:* :ref:`field_base`) Refractivity of fluid.

- **[kappa]**  (*type:* :ref:`field_base`) Absorptivity of fluid (m-1).

- **[gravite]**  (*type:* :ref:`field_base`) Gravity field (optional).

- **[porosites_champ]**  (*type:* :ref:`field_base`) The porosity is given at each element and the porosity at each face,  Psi(face), is calculated by the average of the porosities of the two neighbour elements  Psi(elem1), Psi(elem2) : Psi(face)=2/(1/Psi(elem1)+1/Psi(elem2)). This keyword is optional.

- **[diametre_hyd_champ]**  (*type:* :ref:`field_base`) Hydraulic diameter field (optional).

- **[porosites]**  (*type:* :ref:`porosites`) Porosities.


----

**fluide_sodium_gaz**
---------------------
**Inherits from:** :ref:`milieu_base` 


Class for Fluide_sodium_liquide

Parameters are:

- **[p_ref]**  (*type:* double) Use to set the pressure value in the closure law. If not specified, the value of the pressure unknown will be used

- **[t_ref]**  (*type:* double) Use to set the temperature value in the closure law. If not specified, the value of the temperature unknown will be used

- **[indice]**  (*type:* :ref:`field_base`) Refractivity of fluid.

- **[kappa]**  (*type:* :ref:`field_base`) Absorptivity of fluid (m-1).

- **[gravite]**  (*type:* :ref:`field_base`) Gravity field (optional).

- **[porosites_champ]**  (*type:* :ref:`field_base`) The porosity is given at each element and the porosity at each face,  Psi(face), is calculated by the average of the porosities of the two neighbour elements  Psi(elem1), Psi(elem2) : Psi(face)=2/(1/Psi(elem1)+1/Psi(elem2)). This keyword is optional.

- **[diametre_hyd_champ]**  (*type:* :ref:`field_base`) Hydraulic diameter field (optional).

- **[porosites]**  (*type:* :ref:`porosites`) Porosities.


----

**fluide_sodium_liquide**
-------------------------
**Inherits from:** :ref:`milieu_base` 


Class for Fluide_sodium_liquide

Parameters are:

- **[p_ref]**  (*type:* double) Use to set the pressure value in the closure law. If not specified, the value of the pressure unknown will be used

- **[t_ref]**  (*type:* double) Use to set the temperature value in the closure law. If not specified, the value of the temperature unknown will be used

- **[indice]**  (*type:* :ref:`field_base`) Refractivity of fluid.

- **[kappa]**  (*type:* :ref:`field_base`) Absorptivity of fluid (m-1).

- **[gravite]**  (*type:* :ref:`field_base`) Gravity field (optional).

- **[porosites_champ]**  (*type:* :ref:`field_base`) The porosity is given at each element and the porosity at each face,  Psi(face), is calculated by the average of the porosities of the two neighbour elements  Psi(elem1), Psi(elem2) : Psi(face)=2/(1/Psi(elem1)+1/Psi(elem2)). This keyword is optional.

- **[diametre_hyd_champ]**  (*type:* :ref:`field_base`) Hydraulic diameter field (optional).

- **[porosites]**  (*type:* :ref:`porosites`) Porosities.


----

**fluide_stiffened_gas**
------------------------
**Inherits from:** :ref:`milieu_base` 


Class for Stiffened Gas

Parameters are:

- **[gamma]**  (*type:* double) Heat capacity ratio (Cp/Cv)

- **[pinf]**  (*type:* double) Stiffened gas pressure constant (if set to zero, the state law becomes  identical to that of perfect gases)

- **[mu]**  (*type:* double) Dynamic viscosity

- **[Lambda]**  (*type:* double) Thermal conductivity

- **[cv]**  (*type:* double) Thermal capacity at constant volume

- **[q]**  (*type:* double) Reference energy

- **[q_prim]**  (*type:* double) Model constant

- **[indice]**  (*type:* :ref:`field_base`) Refractivity of fluid.

- **[kappa]**  (*type:* :ref:`field_base`) Absorptivity of fluid (m-1).

- **[gravite]**  (*type:* :ref:`field_base`) Gravity field (optional).

- **[porosites_champ]**  (*type:* :ref:`field_base`) The porosity is given at each element and the porosity at each face,  Psi(face), is calculated by the average of the porosities of the two neighbour elements  Psi(elem1), Psi(elem2) : Psi(face)=2/(1/Psi(elem1)+1/Psi(elem2)). This keyword is optional.

- **[diametre_hyd_champ]**  (*type:* :ref:`field_base`) Hydraulic diameter field (optional).

- **[porosites]**  (*type:* :ref:`porosites`) Porosities.


----

**fluide_weakly_compressible**
------------------------------
**Inherits from:** :ref:`milieu_base` 


Weakly-compressible flow with a low mach number assumption; this means that the thermo-dynamic 
pressure (used in state law) can vary in space.

Parameters are:

- **[loi_etat]**  (*type:* :ref:`loi_etat_base`) The state law that will be associated to the Weakly-compressible fluid.

- **[sutherland]**  (*type:* :ref:`bloc_sutherland`) Sutherland law for viscosity and for conductivity.

- **[traitement_pth]**  (*type:* :ref:`chaine(into=["constant"`) ] Particular treatment for the thermodynamic pressure Pth  ; there is currently one possibility:  1) the keyword 'constant' makes it possible to have a constant Pth but not uniform  in space ; it's the good choice when the flow is open (e.g. with pressure boundary conditions).

- **[Lambda | lambda_u]**  (*type:* :ref:`field_base`) Conductivity (W.m-1.K-1).

- **[mu]**  (*type:* :ref:`field_base`) Dynamic viscosity (kg.m-1.s-1).

- **[pression_thermo]**  (*type:* double) Initial thermo-dynamic pressure used in the assosciated state law.

- **[pression_xyz]**  (*type:* :ref:`field_base`) Initial thermo-dynamic pressure used in the assosciated state law. It should be defined with as a Champ_Fonc_xyz.

- **[use_total_pressure]**  (*type:* int) Flag (0 or 1) used to activate and use the total pressure in the assosciated  state law. The default value of this Flag is 0.

- **[use_hydrostatic_pressure]**  (*type:* int) Flag (0 or 1) used to activate and use the hydro-static pressure in the assosciated  state law. The default value of this Flag is 0.

- **[use_grad_pression_eos]**  (*type:* int) Flag (0 or 1) used to specify whether or not the gradient of the thermo-dynamic  pressure will be taken into account in the source term of the temperature equation  (case of a non-uniform pressure). The default value of this Flag is 1 which means that the gradient is used in the  source.

- **[time_activate_ptot]**  (*type:* double) Time (in seconds) at which the total pressure will be used in the assosciated  state law.

- **[indice]**  (*type:* :ref:`field_base`) Refractivity of fluid.

- **[kappa]**  (*type:* :ref:`field_base`) Absorptivity of fluid (m-1).

- **[gravite]**  (*type:* :ref:`field_base`) Gravity field (optional).

- **[porosites_champ]**  (*type:* :ref:`field_base`) The porosity is given at each element and the porosity at each face,  Psi(face), is calculated by the average of the porosities of the two neighbour elements  Psi(elem1), Psi(elem2) : Psi(face)=2/(1/Psi(elem1)+1/Psi(elem2)). This keyword is optional.

- **[diametre_hyd_champ]**  (*type:* :ref:`field_base`) Hydraulic diameter field (optional).

- **[porosites]**  (*type:* :ref:`porosites`) Porosities.


----

**milieu_base**
---------------
**Inherits from:** :ref:`milieu_base` 


Basic class for medium (physics properties of medium).

Parameters are:

- **[gravite]**  (*type:* :ref:`field_base`) Gravity field (optional).

- **[porosites_champ]**  (*type:* :ref:`field_base`) The porosity is given at each element and the porosity at each face,  Psi(face), is calculated by the average of the porosities of the two neighbour elements  Psi(elem1), Psi(elem2) : Psi(face)=2/(1/Psi(elem1)+1/Psi(elem2)). This keyword is optional.

- **[diametre_hyd_champ]**  (*type:* :ref:`field_base`) Hydraulic diameter field (optional).

- **[porosites]**  (*type:* :ref:`porosites`) Porosities.


----

**solide**
----------
**Inherits from:** :ref:`milieu_base` 


Solid with cp and/or rho non-uniform.

Parameters are:

- **[rho]**  (*type:* :ref:`field_base`) Density (kg.m-3).

- **[cp]**  (*type:* :ref:`field_base`) Specific heat (J.kg-1.K-1).

- **[Lambda | lambda_u]**  (*type:* :ref:`field_base`) Conductivity (W.m-1.K-1).

- **[user_field]**  (*type:* :ref:`field_base`) user defined field.

- **[gravite]**  (*type:* :ref:`field_base`) Gravity field (optional).

- **[porosites_champ]**  (*type:* :ref:`field_base`) The porosity is given at each element and the porosity at each face,  Psi(face), is calculated by the average of the porosities of the two neighbour elements  Psi(elem1), Psi(elem2) : Psi(face)=2/(1/Psi(elem1)+1/Psi(elem2)). This keyword is optional.

- **[diametre_hyd_champ]**  (*type:* :ref:`field_base`) Hydraulic diameter field (optional).

- **[porosites]**  (*type:* :ref:`porosites`) Porosities.

