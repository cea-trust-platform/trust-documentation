loi_etat_base
=============

**binaire_gaz_parfait_qc**
--------------------------
**Inherits from:** :ref:`loi_etat_base` 


Class for perfect gas binary mixtures state law used with a quasi-compressible fluid 
under the iso-thermal and iso-bar assumptions.

Parameters are:

- **molar_mass1**  (*type:* double) Molar mass of species 1 (in kg/mol).

- **molar_mass2**  (*type:* double) Molar mass of species 2 (in kg/mol).

- **mu1**  (*type:* double) Dynamic viscosity of species 1 (in kg/m.s).

- **mu2**  (*type:* double) Dynamic viscosity of species 2 (in kg/m.s).

- **temperature**  (*type:* double) Temperature (in Kelvin) which will be constant during the simulation since  this state law only works for iso-thermal conditions.

- **diffusion_coeff**  (*type:* double) Diffusion coefficient assumed the same for both species (in m2/s).


----

**binaire_gaz_parfait_wc**
--------------------------
**Inherits from:** :ref:`loi_etat_base` 


Class for perfect gas binary mixtures state law used with a weakly-compressible fluid 
under the iso-thermal and iso-bar assumptions.

Parameters are:

- **molar_mass1**  (*type:* double) Molar mass of species 1 (in kg/mol).

- **molar_mass2**  (*type:* double) Molar mass of species 2 (in kg/mol).

- **mu1**  (*type:* double) Dynamic viscosity of species 1 (in kg/m.s).

- **mu2**  (*type:* double) Dynamic viscosity of species 2 (in kg/m.s).

- **temperature**  (*type:* double) Temperature (in Kelvin) which will be constant during the simulation since  this state law only works for iso-thermal conditions.

- **diffusion_coeff**  (*type:* double) Diffusion coefficient assumed the same for both species (in m2/s).


----

**loi_etat_base**
-----------------
**Inherits from:** :ref:`loi_etat_base` 


Basic class for state laws used with a dilatable fluid.

----

**loi_etat_gaz_parfait_base**
-----------------------------
**Inherits from:** :ref:`loi_etat_base` 


Basic class for perfect gases state laws used with a dilatable fluid.

----

**loi_etat_gaz_reel_base**
--------------------------
**Inherits from:** :ref:`loi_etat_base` 


Basic class for real gases state laws used with a dilatable fluid.

----

**multi_gaz_parfait_qc**
------------------------
**Inherits from:** :ref:`loi_etat_base` 


Class for perfect gas multi-species mixtures state law used with a quasi-compressible 
fluid.

Parameters are:

- **sc**  (*type:* double) Schmidt number of the gas Sc=nu/D (D: diffusion coefficient of the mixing).

- **prandtl**  (*type:* double) Prandtl number of the gas Pr=mu*Cp/lambda

- **[cp]**  (*type:* double) Specific heat at constant pressure of the gas Cp.

- **[dtol_fraction]**  (*type:* double) Delta tolerance on mass fractions for check testing (default value 1.e-6).

- **[correction_fraction]**  (*type:* flag) To force mass fractions between 0. and 1.

- **[ignore_check_fraction]**  (*type:* flag) Not to check if mass fractions between 0. and 1.


----

**multi_gaz_parfait_wc**
------------------------
**Inherits from:** :ref:`loi_etat_base` 


Class for perfect gas multi-species mixtures state law used with a weakly-compressible 
fluid.

Parameters are:

- **species_number**  (*type:* int) Number of species you are considering in your problem.

- **diffusion_coeff**  (*type:* :ref:`field_base`) Diffusion coefficient of each species, defined with a Champ_uniforme  of dimension equals to the species_number.

- **molar_mass**  (*type:* :ref:`field_base`) Molar mass of each species, defined with a Champ_uniforme of dimension  equals to the species_number.

- **mu**  (*type:* :ref:`field_base`) Dynamic viscosity of each species, defined with a Champ_uniforme of dimension  equals to the species_number.

- **cp**  (*type:* :ref:`field_base`) Specific heat at constant pressure of the gas Cp, defined with a Champ_uniforme  of dimension equals to the species_number..

- **prandtl**  (*type:* double) Prandtl number of the gas Pr=mu*Cp/lambda.


----

**perfect_gaz_qc**
------------------

**Synonyms:** gaz_parfait_qc

**Inherits from:** :ref:`loi_etat_base` 


Class for perfect gas state law used with a quasi-compressible fluid.

Parameters are:

- **cp**  (*type:* double) Specific heat at constant pressure (J/kg/K).

- **[cv]**  (*type:* double) Specific heat at constant volume (J/kg/K).

- **[gamma]**  (*type:* double) Cp/Cv

- **prandtl**  (*type:* double) Prandtl number of the gas Pr=mu*Cp/lambda

- **[rho_constant_pour_debug]**  (*type:* :ref:`field_base`) For developers to debug the code with a constant rho.


----

**perfect_gaz_wc**
------------------

**Synonyms:** gaz_parfait_wc

**Inherits from:** :ref:`loi_etat_base` 


Class for perfect gas state law used with a weakly-compressible fluid.

Parameters are:

- **cp**  (*type:* double) Specific heat at constant pressure (J/kg/K).

- **[cv]**  (*type:* double) Specific heat at constant volume (J/kg/K).

- **[gamma]**  (*type:* double) Cp/Cv

- **prandtl**  (*type:* double) Prandtl number of the gas Pr=mu*Cp/lambda


----

**rhot_gaz_parfait_qc**
-----------------------
**Inherits from:** :ref:`loi_etat_base` 


Class for perfect gas used with a quasi-compressible fluid where the state equation 
is defined as rho = f(T).

Parameters are:

- **cp**  (*type:* double) Specific heat at constant pressure of the gas Cp.

- **[prandtl]**  (*type:* double) Prandtl number of the gas Pr=mu*Cp/lambda

- **[rho_xyz]**  (*type:* :ref:`field_base`) Defined with a Champ_Fonc_xyz to define a constant rho with time (space  dependent)

- **[rho_t]**  (*type:* string) Expression of T used to calculate rho. This can lead to a variable rho, both in space and in time.

- **[t_min]**  (*type:* double) Temperature may, in some cases, locally and temporarily be very small  (and negative) even though computation converges. T_min keyword allows to set a lower limit of temperature (in Kelvin, -1000 by default). WARNING: DO NOT USE THIS KEYWORD WITHOUT CHECKING CAREFULY YOUR RESULTS!


----

**rhot_gaz_reel_qc**
--------------------
**Inherits from:** :ref:`loi_etat_base` 


Class for real gas state law used with a quasi-compressible fluid.

Parameters are:

- **bloc**  (*type:* :ref:`bloc_lecture`) Description.

