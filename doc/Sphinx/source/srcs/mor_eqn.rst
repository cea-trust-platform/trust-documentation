mor_eqn
=======

**conduction**
--------------
**Inherits from:** :ref:`mor_eqn` 


Heat equation.

Parameters are:

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**convection_diffusion_chaleur_qc**
-----------------------------------
**Inherits from:** :ref:`mor_eqn` 


Temperature equation for a quasi-compressible fluid.

Parameters are:

- **[mode_calcul_convection]**  (*type:* :ref:`chaine(into=["ancien","divut_moins_tdivu","divrhout_moins_tdivrhou"`) ] Option to  set the form of the convective operatorNL2 divrhouT_moins_Tdivrhou (the default since  1.6.8): rho.u.gradT = div(rho.u.T )- Tdiv(rho.u.1) NL2ancien: u.gradT = div(u.T) -  T.div(u)  divuT_moins_Tdivu : u.gradT = div(u.T) - Tdiv(u.1)

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**convection_diffusion_chaleur_turbulent_qc**
---------------------------------------------
**Inherits from:** :ref:`mor_eqn` 


Temperature equation for a quasi-compressible fluid as well as the associated turbulence 
model equations.

Parameters are:

- **[modele_turbulence]**  (*type:* :ref:`modele_turbulence_scal_base`) Turbulence model for the temperature (energy) conservation  equation.

- **[mode_calcul_convection]**  (*type:* :ref:`chaine(into=["ancien","divut_moins_tdivu","divrhout_moins_tdivrhou"`) ] Option to  set the form of the convective operatorNL2 divrhouT_moins_Tdivrhou (the default since  1.6.8): rho.u.gradT = div(rho.u.T )- Tdiv(rho.u.1) NL2ancien: u.gradT = div(u.T) -  T.div(u)  divuT_moins_Tdivu : u.gradT = div(u.T) - Tdiv(u.1)

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**convection_diffusion_chaleur_wc**
-----------------------------------
**Inherits from:** :ref:`mor_eqn` 


Temperature equation for a weakly-compressible fluid.

Parameters are:

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**convection_diffusion_concentration**
--------------------------------------
**Inherits from:** :ref:`mor_eqn` 


Constituent transport vectorial equation (concentration diffusion convection).

Parameters are:

- **[nom_inconnue]**  (*type:* string) Keyword Nom_inconnue will rename the unknown of this equation with the given  name. In the postprocessing part, the concentration field will be accessible with this  name. This is usefull if you want to track more than one concentration (otherwise, only  the concentration field in the first concentration equation can be accessed).

- **[masse_molaire]**  (*type:* double) not_set

- **[alias]**  (*type:* string) not_set

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**convection_diffusion_concentration_turbulent**
------------------------------------------------
**Inherits from:** :ref:`mor_eqn` 


Constituent transport equations (concentration diffusion convection) as well as the 
associated turbulence model equations.

Parameters are:

- **[modele_turbulence]**  (*type:* :ref:`modele_turbulence_scal_base`) Turbulence model to be used in the constituent transport  equations. The only model currently available is Schmidt.

- **[nom_inconnue]**  (*type:* string) Keyword Nom_inconnue will rename the unknown of this equation with the given  name. In the postprocessing part, the concentration field will be accessible with this  name. This is usefull if you want to track more than one concentration (otherwise, only  the concentration field in the first concentration equation can be accessed).

- **[masse_molaire]**  (*type:* double) not_set

- **[alias]**  (*type:* string) not_set

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**convection_diffusion_espece_binaire_qc**
------------------------------------------
**Inherits from:** :ref:`mor_eqn` 


Species conservation equation for a binary quasi-compressible fluid.

Parameters are:

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**convection_diffusion_espece_binaire_turbulent_qc**
----------------------------------------------------
**Inherits from:** :ref:`mor_eqn` 


Species conservation equation for a binary quasi-compressible fluid as well as the 
associated turbulence model equations.

Parameters are:

- **[modele_turbulence]**  (*type:* :ref:`modele_turbulence_scal_base`) Turbulence model for the species conservation equation.

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**convection_diffusion_espece_binaire_wc**
------------------------------------------
**Inherits from:** :ref:`mor_eqn` 


Species conservation equation for a binary weakly-compressible fluid.

Parameters are:

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**convection_diffusion_espece_multi_qc**
----------------------------------------
**Inherits from:** :ref:`mor_eqn` 


Species conservation equation for a multi-species quasi-compressible fluid.

Parameters are:

- **[espece]**  (*type:* :ref:`espece`) Assosciate a species (with its properties) to the equation

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**convection_diffusion_espece_multi_turbulent_qc**
--------------------------------------------------
**Inherits from:** :ref:`mor_eqn` 


not_set

Parameters are:

- **[modele_turbulence]**  (*type:* :ref:`modele_turbulence_scal_base`) Turbulence model to be used.

- **espece**  (*type:* :ref:`espece`) not_set

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**convection_diffusion_espece_multi_wc**
----------------------------------------
**Inherits from:** :ref:`mor_eqn` 


Species conservation equation for a multi-species weakly-compressible fluid.

Parameters are:

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**convection_diffusion_temperature**
------------------------------------
**Inherits from:** :ref:`mor_eqn` 


Energy equation (temperature diffusion convection).

Parameters are:

- **[penalisation_l2_ftd]**  (*type:* :ref:`penalisation_l2_ftd`) to activate or not (the default is Direct Forcing method) the  Penalized Direct Forcing method to impose the specified temperature on the solid-fluid  interface.

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**convection_diffusion_temperature_turbulent**
----------------------------------------------
**Inherits from:** :ref:`mor_eqn` 


Energy equation (temperature diffusion convection) as well as the associated turbulence 
model equations.

Parameters are:

- **[modele_turbulence]**  (*type:* :ref:`modele_turbulence_scal_base`) Turbulence model for the energy equation.

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**echelle_temporelle_turbulente**
---------------------------------
**Inherits from:** :ref:`mor_eqn` 


Turbulent Dissipation time scale equation for a turbulent mono/multi-phase problem 
(available in TrioCFD)

Parameters are:

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**energie_cinetique_turbulente**
--------------------------------
**Inherits from:** :ref:`mor_eqn` 


Turbulent kinetic Energy conservation equation for a turbulent mono/multi-phase problem 
(available in TrioCFD)

Parameters are:

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**energie_cinetique_turbulente_wit**
------------------------------------
**Inherits from:** :ref:`mor_eqn` 


Bubble Induced Turbulent kinetic Energy equation for a turbulent multi-phase problem 
(available in TrioCFD)

Parameters are:

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**energie_multiphase**
----------------------
**Inherits from:** :ref:`mor_eqn` 


Internal energy conservation equation for a multi-phase problem where the unknown 
is the temperature

Parameters are:

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**eqn_base**
------------
**Inherits from:** :ref:`mor_eqn` 


Basic class for equations.

Parameters are:

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**masse_multiphase**
--------------------
**Inherits from:** :ref:`mor_eqn` 


Mass consevation equation for a multi-phase problem where the unknown is the alpha 
(void fraction)

Parameters are:

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**mor_eqn**
-----------
**Inherits from:** :ref:`mor_eqn` 


Class of equation pieces (morceaux d'equation).

----

**navier_stokes_qc**
--------------------
**Inherits from:** :ref:`mor_eqn` 


Navier-Stokes equation for a quasi-compressible fluid.

Parameters are:

- **[methode_calcul_pression_initiale]**  (*type:* :ref:`chaine(into=["avec_les_cl","avec_sources","avec_sources_et_operateurs","sans_rien"`) ]  Keyword to select an option for the pressure calculation before the fist time step. Options are : avec_les_cl (default option lapP=0 is solved with Neuman boundary conditions  on pressure if any), avec_sources (lapP=f is solved with Neuman boundaries conditions  and f integrating the source terms of the Navier-Stokes equations) and avec_sources_et_operateurs  (lapP=f is solved as with the previous option avec_sources but f integrating also  some operators of the Navier-Stokes equations). The two last options are useful and sometime necessary when source terms are implicited  when using an implicit time scheme to solve the Navier-Stokes equations.

- **[projection_initiale]**  (*type:* int) Keyword to suppress, if boolean equals 0, the initial projection which checks  DivU=0. By default, boolean equals 1.

- **[solveur_pression]**  (*type:* :ref:`solveur_sys_base`) Linear pressure system resolution method.

- **[solveur_bar]**  (*type:* :ref:`solveur_sys_base`) This keyword is used to define when filtering operation is called  (typically for EF convective scheme, standard diffusion operator and Source_Qdm_lambdaup  ). A file (solveur.bar) is then created and used for inversion procedure. Syntax is the same then for pressure solver (GCP is required for multi-processor  calculations and, in a general way, for big meshes).

- **[dt_projection]**  (*type:* :ref:`deuxmots`) nb value : This keyword checks every nb time-steps the equality of velocity  divergence to zero. value is the criteria convergency for the solver used.

- **[seuil_divu]**  (*type:* :ref:`floatfloat`) value factor : this keyword is intended to minimise the number of iterations  during the pressure system resolution. The convergence criteria during this step ('seuil' in solveur_pression) is dynamically  adapted according to the mass conservation. At tn , the linear system Ax=B is considered as solved if the residual ||Ax-B||<seuil(tn). For tn+1, the threshold value seuil(tn+1) will be evualated as:  If ( |max(DivU)*dt|<value )  Seuil(tn+1)= Seuil(tn)*factor  Else  Seuil(tn+1)= Seuil(tn)*factor  Endif  The first parameter (value) is the mass evolution the user is ready to accept per  timestep, and the second one (factor) is the factor of evolution for 'seuil' (for  example 1.1, so 10% per timestep). Investigations has to be lead to know more about the effects of these two last parameters  on the behaviour of the simulations.

- **[traitement_particulier]**  (*type:* :ref:`traitement_particulier`) Keyword to post-process particular values.

- **[correction_matrice_projection_initiale]**  (*type:* int) (IBM advanced) fix matrix of initial projection for PDF

- **[correction_calcul_pression_initiale]**  (*type:* int) (IBM advanced) fix initial pressure computation for PDF

- **[correction_vitesse_projection_initiale]**  (*type:* int) (IBM advanced) fix initial velocity computation for PDF

- **[correction_matrice_pression]**  (*type:* int) (IBM advanced) fix pressure matrix for PDF

- **[correction_vitesse_modifie]**  (*type:* int) (IBM advanced) fix velocity for PDF

- **[gradient_pression_qdm_modifie]**  (*type:* int) (IBM advanced) fix pressure gradient

- **[correction_pression_modifie]**  (*type:* int) (IBM advanced) fix pressure for PDF

- **[postraiter_gradient_pression_sans_masse]**  (*type:* flag) (IBM advanced) avoid mass matrix multiplication for the gradient postprocessing

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**navier_stokes_standard**
--------------------------
**Inherits from:** :ref:`mor_eqn` 


Navier-Stokes equations.

Parameters are:

- **[methode_calcul_pression_initiale]**  (*type:* :ref:`chaine(into=["avec_les_cl","avec_sources","avec_sources_et_operateurs","sans_rien"`) ]  Keyword to select an option for the pressure calculation before the fist time step. Options are : avec_les_cl (default option lapP=0 is solved with Neuman boundary conditions  on pressure if any), avec_sources (lapP=f is solved with Neuman boundaries conditions  and f integrating the source terms of the Navier-Stokes equations) and avec_sources_et_operateurs  (lapP=f is solved as with the previous option avec_sources but f integrating also  some operators of the Navier-Stokes equations). The two last options are useful and sometime necessary when source terms are implicited  when using an implicit time scheme to solve the Navier-Stokes equations.

- **[projection_initiale]**  (*type:* int) Keyword to suppress, if boolean equals 0, the initial projection which checks  DivU=0. By default, boolean equals 1.

- **[solveur_pression]**  (*type:* :ref:`solveur_sys_base`) Linear pressure system resolution method.

- **[solveur_bar]**  (*type:* :ref:`solveur_sys_base`) This keyword is used to define when filtering operation is called  (typically for EF convective scheme, standard diffusion operator and Source_Qdm_lambdaup  ). A file (solveur.bar) is then created and used for inversion procedure. Syntax is the same then for pressure solver (GCP is required for multi-processor  calculations and, in a general way, for big meshes).

- **[dt_projection]**  (*type:* :ref:`deuxmots`) nb value : This keyword checks every nb time-steps the equality of velocity  divergence to zero. value is the criteria convergency for the solver used.

- **[seuil_divu]**  (*type:* :ref:`floatfloat`) value factor : this keyword is intended to minimise the number of iterations  during the pressure system resolution. The convergence criteria during this step ('seuil' in solveur_pression) is dynamically  adapted according to the mass conservation. At tn , the linear system Ax=B is considered as solved if the residual ||Ax-B||<seuil(tn). For tn+1, the threshold value seuil(tn+1) will be evualated as:  If ( |max(DivU)*dt|<value )  Seuil(tn+1)= Seuil(tn)*factor  Else  Seuil(tn+1)= Seuil(tn)*factor  Endif  The first parameter (value) is the mass evolution the user is ready to accept per  timestep, and the second one (factor) is the factor of evolution for 'seuil' (for  example 1.1, so 10% per timestep). Investigations has to be lead to know more about the effects of these two last parameters  on the behaviour of the simulations.

- **[traitement_particulier]**  (*type:* :ref:`traitement_particulier`) Keyword to post-process particular values.

- **[correction_matrice_projection_initiale]**  (*type:* int) (IBM advanced) fix matrix of initial projection for PDF

- **[correction_calcul_pression_initiale]**  (*type:* int) (IBM advanced) fix initial pressure computation for PDF

- **[correction_vitesse_projection_initiale]**  (*type:* int) (IBM advanced) fix initial velocity computation for PDF

- **[correction_matrice_pression]**  (*type:* int) (IBM advanced) fix pressure matrix for PDF

- **[correction_vitesse_modifie]**  (*type:* int) (IBM advanced) fix velocity for PDF

- **[gradient_pression_qdm_modifie]**  (*type:* int) (IBM advanced) fix pressure gradient

- **[correction_pression_modifie]**  (*type:* int) (IBM advanced) fix pressure for PDF

- **[postraiter_gradient_pression_sans_masse]**  (*type:* flag) (IBM advanced) avoid mass matrix multiplication for the gradient postprocessing

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**navier_stokes_turbulent**
---------------------------
**Inherits from:** :ref:`mor_eqn` 


Navier-Stokes equations as well as the associated turbulence model equations.

Parameters are:

- **[modele_turbulence]**  (*type:* :ref:`modele_turbulence_hyd_deriv`) Turbulence model for Navier-Stokes equations.

- **[methode_calcul_pression_initiale]**  (*type:* :ref:`chaine(into=["avec_les_cl","avec_sources","avec_sources_et_operateurs","sans_rien"`) ]  Keyword to select an option for the pressure calculation before the fist time step. Options are : avec_les_cl (default option lapP=0 is solved with Neuman boundary conditions  on pressure if any), avec_sources (lapP=f is solved with Neuman boundaries conditions  and f integrating the source terms of the Navier-Stokes equations) and avec_sources_et_operateurs  (lapP=f is solved as with the previous option avec_sources but f integrating also  some operators of the Navier-Stokes equations). The two last options are useful and sometime necessary when source terms are implicited  when using an implicit time scheme to solve the Navier-Stokes equations.

- **[projection_initiale]**  (*type:* int) Keyword to suppress, if boolean equals 0, the initial projection which checks  DivU=0. By default, boolean equals 1.

- **[solveur_pression]**  (*type:* :ref:`solveur_sys_base`) Linear pressure system resolution method.

- **[solveur_bar]**  (*type:* :ref:`solveur_sys_base`) This keyword is used to define when filtering operation is called  (typically for EF convective scheme, standard diffusion operator and Source_Qdm_lambdaup  ). A file (solveur.bar) is then created and used for inversion procedure. Syntax is the same then for pressure solver (GCP is required for multi-processor  calculations and, in a general way, for big meshes).

- **[dt_projection]**  (*type:* :ref:`deuxmots`) nb value : This keyword checks every nb time-steps the equality of velocity  divergence to zero. value is the criteria convergency for the solver used.

- **[seuil_divu]**  (*type:* :ref:`floatfloat`) value factor : this keyword is intended to minimise the number of iterations  during the pressure system resolution. The convergence criteria during this step ('seuil' in solveur_pression) is dynamically  adapted according to the mass conservation. At tn , the linear system Ax=B is considered as solved if the residual ||Ax-B||<seuil(tn). For tn+1, the threshold value seuil(tn+1) will be evualated as:  If ( |max(DivU)*dt|<value )  Seuil(tn+1)= Seuil(tn)*factor  Else  Seuil(tn+1)= Seuil(tn)*factor  Endif  The first parameter (value) is the mass evolution the user is ready to accept per  timestep, and the second one (factor) is the factor of evolution for 'seuil' (for  example 1.1, so 10% per timestep). Investigations has to be lead to know more about the effects of these two last parameters  on the behaviour of the simulations.

- **[traitement_particulier]**  (*type:* :ref:`traitement_particulier`) Keyword to post-process particular values.

- **[correction_matrice_projection_initiale]**  (*type:* int) (IBM advanced) fix matrix of initial projection for PDF

- **[correction_calcul_pression_initiale]**  (*type:* int) (IBM advanced) fix initial pressure computation for PDF

- **[correction_vitesse_projection_initiale]**  (*type:* int) (IBM advanced) fix initial velocity computation for PDF

- **[correction_matrice_pression]**  (*type:* int) (IBM advanced) fix pressure matrix for PDF

- **[correction_vitesse_modifie]**  (*type:* int) (IBM advanced) fix velocity for PDF

- **[gradient_pression_qdm_modifie]**  (*type:* int) (IBM advanced) fix pressure gradient

- **[correction_pression_modifie]**  (*type:* int) (IBM advanced) fix pressure for PDF

- **[postraiter_gradient_pression_sans_masse]**  (*type:* flag) (IBM advanced) avoid mass matrix multiplication for the gradient postprocessing

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**navier_stokes_turbulent_qc**
------------------------------
**Inherits from:** :ref:`mor_eqn` 


Navier-Stokes equations under low Mach number as well as the associated turbulence 
model equations.

Parameters are:

- **[modele_turbulence]**  (*type:* :ref:`modele_turbulence_hyd_deriv`) Turbulence model for Navier-Stokes equations.

- **[methode_calcul_pression_initiale]**  (*type:* :ref:`chaine(into=["avec_les_cl","avec_sources","avec_sources_et_operateurs","sans_rien"`) ]  Keyword to select an option for the pressure calculation before the fist time step. Options are : avec_les_cl (default option lapP=0 is solved with Neuman boundary conditions  on pressure if any), avec_sources (lapP=f is solved with Neuman boundaries conditions  and f integrating the source terms of the Navier-Stokes equations) and avec_sources_et_operateurs  (lapP=f is solved as with the previous option avec_sources but f integrating also  some operators of the Navier-Stokes equations). The two last options are useful and sometime necessary when source terms are implicited  when using an implicit time scheme to solve the Navier-Stokes equations.

- **[projection_initiale]**  (*type:* int) Keyword to suppress, if boolean equals 0, the initial projection which checks  DivU=0. By default, boolean equals 1.

- **[solveur_pression]**  (*type:* :ref:`solveur_sys_base`) Linear pressure system resolution method.

- **[solveur_bar]**  (*type:* :ref:`solveur_sys_base`) This keyword is used to define when filtering operation is called  (typically for EF convective scheme, standard diffusion operator and Source_Qdm_lambdaup  ). A file (solveur.bar) is then created and used for inversion procedure. Syntax is the same then for pressure solver (GCP is required for multi-processor  calculations and, in a general way, for big meshes).

- **[dt_projection]**  (*type:* :ref:`deuxmots`) nb value : This keyword checks every nb time-steps the equality of velocity  divergence to zero. value is the criteria convergency for the solver used.

- **[seuil_divu]**  (*type:* :ref:`floatfloat`) value factor : this keyword is intended to minimise the number of iterations  during the pressure system resolution. The convergence criteria during this step ('seuil' in solveur_pression) is dynamically  adapted according to the mass conservation. At tn , the linear system Ax=B is considered as solved if the residual ||Ax-B||<seuil(tn). For tn+1, the threshold value seuil(tn+1) will be evualated as:  If ( |max(DivU)*dt|<value )  Seuil(tn+1)= Seuil(tn)*factor  Else  Seuil(tn+1)= Seuil(tn)*factor  Endif  The first parameter (value) is the mass evolution the user is ready to accept per  timestep, and the second one (factor) is the factor of evolution for 'seuil' (for  example 1.1, so 10% per timestep). Investigations has to be lead to know more about the effects of these two last parameters  on the behaviour of the simulations.

- **[traitement_particulier]**  (*type:* :ref:`traitement_particulier`) Keyword to post-process particular values.

- **[correction_matrice_projection_initiale]**  (*type:* int) (IBM advanced) fix matrix of initial projection for PDF

- **[correction_calcul_pression_initiale]**  (*type:* int) (IBM advanced) fix initial pressure computation for PDF

- **[correction_vitesse_projection_initiale]**  (*type:* int) (IBM advanced) fix initial velocity computation for PDF

- **[correction_matrice_pression]**  (*type:* int) (IBM advanced) fix pressure matrix for PDF

- **[correction_vitesse_modifie]**  (*type:* int) (IBM advanced) fix velocity for PDF

- **[gradient_pression_qdm_modifie]**  (*type:* int) (IBM advanced) fix pressure gradient

- **[correction_pression_modifie]**  (*type:* int) (IBM advanced) fix pressure for PDF

- **[postraiter_gradient_pression_sans_masse]**  (*type:* flag) (IBM advanced) avoid mass matrix multiplication for the gradient postprocessing

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**navier_stokes_wc**
--------------------
**Inherits from:** :ref:`mor_eqn` 


Navier-Stokes equation for a weakly-compressible fluid.

Parameters are:

- **[methode_calcul_pression_initiale]**  (*type:* :ref:`chaine(into=["avec_les_cl","avec_sources","avec_sources_et_operateurs","sans_rien"`) ]  Keyword to select an option for the pressure calculation before the fist time step. Options are : avec_les_cl (default option lapP=0 is solved with Neuman boundary conditions  on pressure if any), avec_sources (lapP=f is solved with Neuman boundaries conditions  and f integrating the source terms of the Navier-Stokes equations) and avec_sources_et_operateurs  (lapP=f is solved as with the previous option avec_sources but f integrating also  some operators of the Navier-Stokes equations). The two last options are useful and sometime necessary when source terms are implicited  when using an implicit time scheme to solve the Navier-Stokes equations.

- **[projection_initiale]**  (*type:* int) Keyword to suppress, if boolean equals 0, the initial projection which checks  DivU=0. By default, boolean equals 1.

- **[solveur_pression]**  (*type:* :ref:`solveur_sys_base`) Linear pressure system resolution method.

- **[solveur_bar]**  (*type:* :ref:`solveur_sys_base`) This keyword is used to define when filtering operation is called  (typically for EF convective scheme, standard diffusion operator and Source_Qdm_lambdaup  ). A file (solveur.bar) is then created and used for inversion procedure. Syntax is the same then for pressure solver (GCP is required for multi-processor  calculations and, in a general way, for big meshes).

- **[dt_projection]**  (*type:* :ref:`deuxmots`) nb value : This keyword checks every nb time-steps the equality of velocity  divergence to zero. value is the criteria convergency for the solver used.

- **[seuil_divu]**  (*type:* :ref:`floatfloat`) value factor : this keyword is intended to minimise the number of iterations  during the pressure system resolution. The convergence criteria during this step ('seuil' in solveur_pression) is dynamically  adapted according to the mass conservation. At tn , the linear system Ax=B is considered as solved if the residual ||Ax-B||<seuil(tn). For tn+1, the threshold value seuil(tn+1) will be evualated as:  If ( |max(DivU)*dt|<value )  Seuil(tn+1)= Seuil(tn)*factor  Else  Seuil(tn+1)= Seuil(tn)*factor  Endif  The first parameter (value) is the mass evolution the user is ready to accept per  timestep, and the second one (factor) is the factor of evolution for 'seuil' (for  example 1.1, so 10% per timestep). Investigations has to be lead to know more about the effects of these two last parameters  on the behaviour of the simulations.

- **[traitement_particulier]**  (*type:* :ref:`traitement_particulier`) Keyword to post-process particular values.

- **[correction_matrice_projection_initiale]**  (*type:* int) (IBM advanced) fix matrix of initial projection for PDF

- **[correction_calcul_pression_initiale]**  (*type:* int) (IBM advanced) fix initial pressure computation for PDF

- **[correction_vitesse_projection_initiale]**  (*type:* int) (IBM advanced) fix initial velocity computation for PDF

- **[correction_matrice_pression]**  (*type:* int) (IBM advanced) fix pressure matrix for PDF

- **[correction_vitesse_modifie]**  (*type:* int) (IBM advanced) fix velocity for PDF

- **[gradient_pression_qdm_modifie]**  (*type:* int) (IBM advanced) fix pressure gradient

- **[correction_pression_modifie]**  (*type:* int) (IBM advanced) fix pressure for PDF

- **[postraiter_gradient_pression_sans_masse]**  (*type:* flag) (IBM advanced) avoid mass matrix multiplication for the gradient postprocessing

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**qdm_multiphase**
------------------
**Inherits from:** :ref:`mor_eqn` 


Momentum conservation equation for a multi-phase problem where the unknown is the 
velocity

Parameters are:

- **[solveur_pression]**  (*type:* :ref:`solveur_sys_base`) Linear pressure system resolution method.

- **[evanescence]**  (*type:* :ref:`bloc_lecture`) Management of the vanishing phase (when alpha tends to 0 or 1)

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }


----

**taux_dissipation_turbulent**
------------------------------
**Inherits from:** :ref:`mor_eqn` 


Turbulent Dissipation frequency equation for a turbulent mono/multi-phase problem 
(available in TrioCFD)

Parameters are:

- **[disable_equation_residual]**  (*type:* string) The equation residual will not be used for the problem residual used when  checking time convergence or computing dynamic time-step

- **[convection]**  (*type:* :ref:`bloc_convection`) Keyword to alter the convection scheme.

- **[diffusion]**  (*type:* :ref:`bloc_diffusion`) Keyword to specify the diffusion operator.

- **[conditions_limites | boundary_conditions]**  (*type:* :ref:`condlims`) Boundary conditions.

- **[conditions_initiales | initial_conditions]**  (*type:* :ref:`condinits`) Initial conditions.

- **[sources]**  (*type:* :ref:`sources`) To introduce a source term into an equation (in case of several source terms  into the same equation, the blocks corresponding to the various terms need to be separated  by a comma)

- **[ecrire_fichier_xyz_valeur_bin]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a binary file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[ecrire_fichier_xyz_valeur]**  (*type:* :ref:`ecrire_fichier_xyz_valeur_param`) This keyword is used to write the values of a field  only for some boundaries in a text file with the following format: n_valeur  x_1 y_1 [z_1] val_1  ...  x_n y_n [z_n] val_n  The created files are named : pbname_fieldname_[boundaryname]_time.dat

- **[parametre_equation]**  (*type:* :ref:`parametre_equation_base`) Keyword used to specify additional parameters for the equation

- **[equation_non_resolue]**  (*type:* string) The equation will not be solved while condition(t) is verified if equation_non_resolue  keyword is used. Exemple: The Navier-Stokes equations are not solved between time t0 and t1.  Navier_Sokes_Standard  { equation_non_resolue (t>t0)*(t<t1) }

