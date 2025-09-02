# Problem types

Depending on the type of problem you choose, **TRUST** will solve different sets of equation. It is therefore key to identify which problem corresponds to your application.

Inside the problem bloc, the user have to define first the medium he wants to consider. The **medium specified in the bloc should be coherent with the instantiated problem**, otherwise you will not be able to run your test case. For example, defining an incompressible medium in a conduction problem is not possible.

After defining the medium, the user should precise the equations he is willing to solve. The **equation should be also coherent with the instantiated problem** otherwise **TRUST** will exit with an error message. For example, defining a Navier-Stokes equation in a conduction problem is not possible.

Once the problem, medium and equations are defined, the user will have to specify the post-processing of the current case. Go check-out the [](post-processing.md) section for more informations regarding the post-processing in **TRUST**. 

In this section, the most used problems are introduced. For documentation and for complete problem sets, see the [](../reference/index).

## Conduction Problem

For this kind of problems, **TRUST** solves the heat equation:

```{math}
:label: eq:heat
\rho C_p \frac{\partial T}{\partial t} = \color{blue}{\nabla \cdot \left(\lambda \nabla T\right)} + Q
```

where:
- $\rho$: density,
- $C_p$: specific heat capacity at constant pressure,
- $\lambda$: thermal conductivity,
- $Q$ is a heat source term.

### Options of Conduction problems

| Problem type  | Possible mediums | Possible Equations |
|---------|-----------|------------------|
| Pb\_Conduction | Solide | Conduction |

### Example of a Pb\_conduction block

Here is an example of a **Pb\_conduction**, taken from the `docond_VEF.data` file:

```bash
# Read a conduction problem pb #
	Read pb 
	{
		# Read solid medium #
	    Solide
	    {
	        rho Champ_Uniforme 1 1000.
	        lambda Champ_Uniforme 1 250.
	        Cp Champ_Uniforme 1 100.
	    }
	    
		# Read conduction equation #
	    Conduction
	    {
	        diffusion { }
	        initial_conditions { temperature Champ_Uniforme 1 30. }
	        boundary_conditions 
	        {
	            paroi_a_40 paroi_temperature_imposee Champ_Front_Uniforme 1 40.
	            paroi_a_20 paroi_temperature_imposee Champ_Front_Uniforme 1 20.
	            Paroi_echange paroi_contact pb2 Paroi_echange
	        }
	    }
	    
	    # Read post-processing #
	    Post_processing
	    {
	        Probes
	        {
	            sonde_tsol temperature periode 1. points 2 0.15 0.55 0.55 0.15
	            sonde_segs temperature periode 5. segment 10 0. 0.75 0.3 0.75
	        }
	        fields dt_post 300.
	        {
	            temperature elem
	        }
	    }
	    
	    # Save the data at the end of the calculation to resume later #
	    sauvegarde formatte solide.rep
	}
```

## Hydraulic and Thermohydraulics problems

The hydraulic and thermohydraulic problems solve the **incompressible Navier-Stokes** equation with more or less terms. Complementary transport equations can also be added.

```{math}
:label: eq:NS
:name: Incompressible Navier-Stokes equation, called Navier\_Stokes\_standard in **TRUST**
\left\{
\begin{array}{c}
\nabla \cdot \vec u = 0 \\
\displaystyle{\frac{\partial \vec u}{\partial t} + \textcolor{red}{\nabla \cdot (\vec u \otimes \vec u)} + \nabla P^*= \textcolor{blue}{\nabla \cdot (\nu \nabla \vec u)} }
\end{array}
\right.
```

Incompressible Navier-Stokes equation, referred as Navier\_Stokes\_standard in **TRUST**

```{math}
:label: eq:temp
\displaystyle{\frac{\partial T}{\partial t} + \textcolor{red}{\vec u \nabla T} = \textcolor{blue}{\nabla \cdot (\alpha \nabla T)} + \frac{Q}{\rho C_p}}
```

Heat equation, referred as Convection\_Diffusion\_Temperature in **TRUST**

```{math}
:label: eq:transport
\displaystyle{\frac{\partial X}{\partial t} + \textcolor{red}{\vec u \nabla X}} = 0
```

Passive scalar transport equation, referred as Convection\_Diffusion\_Concentration in **TRUST**

Where:
$P^* = \dfrac{P}{\rho} + g z$, $Q$ is the heat source term, and:

- $\rho$: density
- $\mu$: dynamic viscosity
- $\nu = \dfrac{\mu}{\rho}$: kinematic viscosity
  $\vec{g} = g z$: gravity vector in cartesian coordinates
- $\alpha = \dfrac{\lambda}{\rho C_p}$: thermic diffusivity
- $C_p$: specific heat capacity at constant pressure
- $\lambda$: thermic conductivity
- $X$: a transported scalar quantity

```{note}
Red terms corresponds to convective terms and blue terms to diffusive terms.
```
### Options of Hydraulic and Thermohydraulics problems

| Problem type  | Possible mediums | Possible Equations |
|---------|-----------|------------------|
| Pb\_Hydraulique | Fuilde\_Incompressible or Fluide\_Ostwald | Navier\_Stokes\_standard |
| Pb\_Hydraulique_Concentration | Fuilde\_Incompressible or Fluide\_Ostwald | Navier\_Stokes\_standard + Convection\_Diffusion\_Concentration |
| Pb\_Hydraulique\_Concentration\_Scalaires\_Passifs | Fuilde\_Incompressible or Fluide\_Ostwald | Navier\_Stokes\_standard + N additional Convection\_Diffusion\_Concentration |
| Pb\_Thermohydraulique | Fuilde\_Incompressible or Fluide\_Ostwald | Navier\_Stokes\_standard + Convection\_Diffusion\_Temperature |
| Pb\_Thermohydraulique\_Concentration | Fuilde\_Incompressible or Fluide\_Ostwald | Navier\_Stokes\_standard + Convection\_Diffusion\_Temperature + Convection\_Diffusion\_Concentration |
| Pb\_Thermohydraulique\_Concentration\_Scalaires\_Passifs | Fuilde\_Incompressible or Fluide\_Ostwald | Navier\_Stokes\_standard + Convection\_Diffusion\_Temperature + N additional Convection\_Diffusion\_Concentration |

**Important remarks**: 
- for Hydraulique or Thermohydraulique problems, an additional `Constituant` medium should be **secondly** defined if you ask for a problem with concentration.

### Example of a Pb\_Thermohydraulique block

Here is an example of Pb\_Thermohydraulique, taken from the `Source_Generique_PolyMAC` test case:
```bash
# Read a thermal hydraulic problem pb #
Read pb
{
	# Read incompressible medium #
	fluide_incompressible 
	{
	    gravite champ_uniforme 2 0 -9.81
	    mu Champ_Uniforme 1 1.85e-5
	    rho Champ_Uniforme 1 1.17
	    lambda Champ_Uniforme 1 0.0262
	    Cp Champ_Uniforme 1 1006
	    beta_th Champ_Uniforme 1 3.41e-3
	}
	
	# Read NS equation #
	Navier_Stokes_standard
	{
	    solveur_pression petsc gcp { precond null { } seuil 1e30 }
	    convection { negligeable }
	    diffusion { negligeable }
	    initial_conditions { vitesse Champ_Uniforme 2 0. 0. }
	    boundary_conditions 
	    {
	        Obstacle paroi_fixe
	        Symetrie symetrie
	        Sortie frontiere_ouverte_pression_imposee Champ_front_Uniforme 1 0.
	        Entree frontiere_ouverte_vitesse_imposee  Champ_front_Uniforme 2  1. 0.
	    }
	    sources 
	    {
	        Source_Qdm Champ_fonc_xyz dom 2 x y
	    }
	}
		 
	# Read Temperature equation #
	Convection_Diffusion_Temperature
	{
	    diffusion { negligeable }
        convection { negligeable }
        boundary_conditions
        {
            Symetrie 	paroi_adiabatique
            Obstacle 	paroi_adiabatique
            Entree  	frontiere_ouverte_temperature_imposee Champ_front_Fonc_xyz 1 1
            Sortie	frontiere_ouverte_temperature_imposee Champ_front_Fonc_xyz 1 0
        }
        initial_conditions { Temperature Champ_Fonc_xyz dom 1 0 }
        sources 
        {
            Puissance_Thermique champ_fonc_xyz dom 1 50+x+y
        }
    }
	
	 # Read post-processings #
    Postraitement
    {
        fields dt_post 1e10
        {
            temperature elem
            vitesse elem
            pressure elem
        }
    }
}
```	

## Low Mach Number Problems

The Mach number Ma = u / c measures the ratio of the bulk velocity to the local speed of sound. Typically for Ma < 0.1, the compressibility effects can be neglected and the physical problem may be reduced by using a Low Mach Number formulation. In such cases, the aspect of the problem orients towards simulating a mass variation rather than capturing and solving for the acoustic waves. This is basically the main hypothesis of a Low Mach Number approximation where all acoustic waves are filtered out.

Following a single scale asymptotic analysis referring to the Mach number, the zero Mach order equations are considered where the total pressure is decomposed into a thermodynamic pressure and a hydrodynamic pressure that fluctuates in an order of Ma2. Note that the hydrodynamic pressure is much smaller than the thermodynamic one. The hydrodynamic pressure alone is used in the momentum equation, while the thermodynamic is used in the equation of state.

TRUST offers two Low Mach Number modelisations; either a Weakly-Compressible (WC) or a Quasi-Compressible (QC) models. The main difference between both models is that the QC model considers a space-uniform thermodynamic pressure. This is not the case in th WC model where the total pressure, which is space/time varying, is used in the equation of state. The last can have a great impact in some situations as the pressure drop and/or the hydro-static pressure can influence significantly the density variation.

The system of equation associated with Low Mach number problem writes:

```{math}
\left\{
\begin{array}{c}
\displaystyle{\frac{\partial \rho }{\partial t} + \nabla \cdot (\rho \vec u) =0 }\\
\displaystyle{ \frac{\partial \rho \vec u}{\partial t} + \textcolor{red}{\nabla \cdot (\rho \vec u \vec u)} =  \textcolor{blue}{\nabla \cdot \left(\mu \nabla \vec u \right)} - \nabla P -\rho \vec g }\\
\displaystyle{ \rho C_p \left( \frac{\partial T}{\partial t} + \textcolor{red}{\vec u \nabla T} \right) = \textcolor{blue}{\nabla \cdot \left(\lambda \nabla T\right)} + \frac{dP_{tot}}{dt} + Q }
\end{array}
\right.
```

where: $P_{tot}=\rho R T$, $Q$ is a heat source term, and:

- $\rho$: density,

- $\mu$: dynamic viscosity,

- $\vec g=g z$: gravity vector in cartesian coordinates,

- $C_p$: specific heat capacity at constant pressure,

- $\lambda$: thermal conductivity.

```{note}
Red terms are convective terms and blue terms are diffusive terms.
```

**Remark:** The difference between *Hydraulique* and *Thermohydraulique* type of problem is whether the last equation of the system (that drive the temperature) is taken into account or not. If it is taken into account you'll have to use a *Thermohydraulique* type of problem.


### Options of WC and QC problems

| Problem type  | Possible mediums | Possible Equations |
|---------|-----------|------------------|
| Pb\_Hydraulique\_Melange\_Binaire\_QC | Fluide\_Quasi\_Compressible | Navier\_Stokes\_QC + Convection\_Diffusion\_Espece\_Binaire\_QC |
| Pb\_Hydraulique\_Melange\_Binaire\_WC | Fluide\_Quasi\_Compressible | Navier\_Stokes\_WC + Convection\_Diffusion\_Espece\_Binaire\_WC |
| Pb\_Thermohydraulique\_QC | Fluide\_Quasi\_Compressible | Navier\_Stokes\_QC + Convection\_Diffusion\_Chaleur\_QC |
| Pb\_Thermohydraulique\_WC | Fluide\_Quasi\_Compressible | Navier\_Stokes\_WC + Convection\_Diffusion\_Chaleur\_WC |
| Pb\_Thermohydraulique\_Especes\_QC | Fluide\_Quasi\_Compressible | Navier\_Stokes\_QC + Convection\_Diffusion\_Chaleur\_QC + N additional Convection\_Diffusion\_Espece\_Multi\_QC|
| Pb\_Thermohydraulique\_Especes\_WC | Fluide\_Quasi\_Compressible | Navier\_Stokes\_WC + Convection\_Diffusion\_Chaleur\_WC + N additional Convection\_Diffusion\_Espece\_Multi\_WC |

### Example of a Pb\_Thermohydraulique block

Here is an example of **Pb\_thermohydraulique_qc**, taken from the `DarcyFlow_QC_VDF` test case:

```bash
Read pb
{

    fluide_quasi_compressible {
        pression 111582.205714
        loi_etat gaz_parfait_QC
        {
            Cp 1006.8
            gamma 1.4
            Prandtl 0.494112177122
            rho_constant_pour_debug champ_uniforme 1 1.293
        }
        traitement_pth constant
        traitement_rho_gravite moins_rho_moyen
        mu champ_uniforme 1 1.33e-05
    }

    Navier_stokes_qc
    {
        solveur_pression petsc Cholesky { }
        convection { negligeable }
        diffusion { negligeable }
        initial_conditions
        {
            vitesse champ_uniforme 3 0.0 0.2 0.0
        }
        boundary_conditions
        {
            Entree frontiere_ouverte_vitesse_imposee champ_front_uniforme 3 0.0 0.2 0.0
            Sortie frontiere_ouverte_pression_imposee champ_front_uniforme 1 0.0
            Bord paroi_fixe
        }
        sources
        {
            darcy { porosite 0.4 modele_K ErgunDarcy { diametre 1.5e-3 } } ,
            forchheimer { porosite 0.4 Cf 1. modele_K ErgunForchheimer { diametre 1.5e-3 } }
        }
    }
    convection_diffusion_chaleur_qc
    {
        convection { negligeable }
        diffusion { negligeable }
        initial_conditions
        {
            temperature champ_uniforme 1 300.0
        }
        boundary_conditions
        {
            Entree frontiere_ouverte_temperature_imposee champ_front_uniforme 1 300.0
            Sortie frontiere_ouverte T_ext champ_front_uniforme 1 300.0
            Bord paroi_adiabatique
        }
    }
    Post_processing
    {
        Probes
        {
            sonde_vitesse 		nodes 	vitesse periode 0.0001 point 1 0.08 0.10 0.08
            segment_pression 	grav 	pression_pa periode 0.0001 segment 50 0.08 0.05 0.08 0.08 0.20 0.08
        }
        Format lata fields dt_post 0.1
        {
            pression_pa elem
        }
    }
}
```

## Multi-Phase Problem

The multiphase type of prblem is simply called `Pb_Multiphase`. This problem allows the resolution of N-phases via a model of 3N equations, based on a Ishii types of model :cite:`I75`.

An instance of the medium `Milieu_composite` is required at the begining of the problem's bloc. Inside the medium bloc, you can define any medium. For exmaple, you can define a `Fluide_Incompressible` or any child class of the `Fluide_reel_base` class (cf [](../../dev_corner/cpp_api.rst)).

An additional `Correlations` bloc should be **secondly** defined. Each and every correlations derive from the base class `Corellation_base`. Check the [](../../dev_corner/cpp_api.rst) to see the list of available correlations.

Afterwards, the reading of the equations starts. In `Pb_Multiphase`, the equations solved for each phase are the momentum, mass and energy equations; respectively `QDM_Multiphase`, `Masse_Multiphase` and `Energie_Multiphase`.

The coupling between all equations is done in a strong way: a single matrix for all equations is used to solve the problem. Available discrtisation for this type of problem are **VDF**, **PolyMAC** and **PolyMAC\_P0**. 

You can also call the **EOS** (private CEA/EDF project) and the **[CoolProp](http://www.coolprop.org/)** library to compute the Thermo-Physical Properties via the `TPPI` interface. Check this [tutorial](../../user_tutorials/coolprop.md) for a guide to link CoolProp with **TRUST**.

### Example of a Pb\_Multiphase block

Here is an example of **Pb\_Multiphase**, taken from the `CoolProp_water_BICUBIC_HEOS_with_sat` test case. Attention this test case needs a TRUST version linked with the CoolProp library.
```bash
# Read a multiphase problem pb #
Read pb
{
	# Read the multi-phase + saturation medium #
	Milieu_composite
	{
		liquide_eau Fluide_generique_coolprop { model BICUBIC&heos fluid Water phase liquid } 
		gaz_eau Fluide_generique_coolprop { model BICUBIC&heos fluid Water }
		saturation_eau saturation_generique_coolprop { model BICUBIC&heos fluid Water phase liquid }
	}

	# Read the correlations #
	correlations
	{
	flux_interfacial coef_constant { liquide_eau 1.0e10 gaz_eau 1.0e10 }
	}
    
    # Read the momentum equation #
    QDM_Multiphase
    {   
        evanescence { homogene { alpha_res 1 alpha_res_min 0.5 } } 
        solveur_pression petsc cli_quiet { -pc_type hypre -pc_hypre_type boomeramg }
        convection { amont }
        diffusion  { negligeable } 
        initial_conditions
        {
           vitesse  Champ_fonc_xyz dom 4 2.0*(x>0.5)-2.0*(x[0.5) 2.0*(x>0.5)-2.0*(x[0.5) 0.0 0.0
           pression Champ_fonc_xyz dom 1 1.0e5 
        }
        boundary_conditions
        {
            haut symetrie
            bas symetrie
             gauche frontiere_ouverte_pression_imposee champ_front_uniforme 1 100000.0
            droite frontiere_ouverte_pression_imposee champ_front_uniforme 1 100000.0
        }
    }
	    
    # Read the mass equuation #
    Masse_Multiphase
    {
        initial_conditions { alpha Champ_Fonc_xyz dom 2 0.95 0.05 }
        convection { amont }
        boundary_conditions
        {
            haut paroi
            bas paroi
            gauche frontiere_ouverte a_ext Champ_Front_Uniforme 2 0.95 0.05
            droite frontiere_ouverte a_ext Champ_Front_Uniforme 2 0.95 0.05
        }
          sources { flux_interfacial }
    }
	    
    # Read the energy equation #
	Energie_Multiphase
    {
        diffusion { negligeable }
        convection { amont }
        initial_conditions { temperature Champ_fonc_xyz dom 2 10. 10. }
        boundary_conditions
        {
            haut paroi_adiabatique
            bas paroi_adiabatique
            gauche frontiere_ouverte T_ext Champ_Front_uniforme 2 81.578 61.578
            droite frontiere_ouverte T_ext Champ_Front_uniforme 2 71.578 51.578
        }
         sources { flux_interfacial }
    }
    
    # Read the post-processing #
    Post_processing
    {
        probes
        {
             rho grav masse_volumique periode 1e8 segment 1000 0 0.5 1 0.5
	           v grav         vitesse periode 1e8 segment 1000 0 0.5 1 0.5
	           p grav        pression periode 1e8 segment 1000 0 0.5 1 0.5
            eint grav energie_interne periode 1e8 segment 1000 0 0.5 1 0.5
        }
        
        Format lml
        fields dt_post 1e-4
        {
            alpha elem
            vitesse elem
            pression elem
            temperature elem
            energie_interne elem
            vitesse_liquide_eau elem
            vitesse_gaz_eau elem
            alpha_gaz_eau elem
            masse_volumique elem
        }
    }
}
```

## Coupled Problems

There are two ways to solve coupled problems with TRUST: either using `Probleme_Couple` or via the Interface of Code Coupling **([ICoCo](https://github.com/cea-trust-platform/icoco-coupling))** and `ProblemeTrio`.

### With Probleme_Couple

In `Probleme_Couple`, the user has to define the contact boundary/volume between several domains where a **TRUST** problem (one of the above) is to be defined on each domain. The coupling is managed by **TRUST** where a point-fixed algorithm is used to converge the coupled simulation.

Here is an example:

- First two problems *my_problem_1* and *my_problem_2* are defined. Each one associated with a separate domain *my_domain_1* and *my_domain_2*, and each one having a different medium *my_medium_1* and *my_medium_2*:

```bash
Dimension 2
Pb_ThermoHydraulique my_problem_1
Pb_ThermoHydraulique my_problem_2

Domaine my_domain_1
Read_file my_mesh_1.geo ;

Domaine my_domain_2
Read_file my_mesh_2.geo ;

Associate my_problem_1 my_domain_1
Associate my_problem_2 my_domain_2
```

- Then a coupled problem associated to a single time scheme is defined:

```bash
Probleme_Couple my_coupled_problem

VEFPreP1B my_discretization

Scheme_euler_explicit my_scheme
Read my_scheme { ... }

Associate my_coupled_problem my_problem_1
Associate my_coupled_problem my_problem_2
Associate my_coupled_problem my_scheme
```

- Eventually the coupled problem is discretized, the two separated problems specified and the coupled problem is solved:

```bash
Discretize my_coupled_problem my_discretization

Read my_problem_1
{
   Fluide_Incompressible { ... }
   ...
}

Read my_problem_2
{
   Fluide_Incompressible { ... }
   ...
}

Solve my_coupled_problem
End
```


### With ICoCo
On the other hand, the user have to write his own coupling algorithm when using ICoCo. In practice, this can be done either by writing a C++ supervisor to manage the coupling, or via its python interface available in **TRUST**, thanks to the swig wrapper !


