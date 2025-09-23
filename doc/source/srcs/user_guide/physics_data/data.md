# How to use a data file

To launch a calculation with **TRUST**, you need to write a data file which is an input file for **TRUST** and will contain all the information about your simulation. 
Data files are written following some rules as shown below. But their language is not a programming language, users can't make loops or switch.
We will now explain how to fill a data file. First you must specify some basic information like the dimension of your domain, its name, the problem type... 

## Basic Rules

There is no line concept in **TRUST** `.data` files.

Data files uses `blocks`. They may be defined using the braces:

```bash
{
   a block
}
```

## Objects Notion

**Objects** are created in the data set as follows:

```bash
[ export ] Type identificateur
```

-  **export**: if this keyword is included, *identificateur* (identifier) will have a global range, if not, its range will be applied to the block only (the associated object will be destroyed on exiting the block).

-  **Type**: must be a type of object recognised by **TRUST**, which correspond to the C++ classes. The list of recognised types is given in the file `hierarchie.dump`.

-  **identificateur**: the identifier of the created object type *Type* corresponds to an instancy of the C++ class *Type*. **TRUST** exits an error if the identifier has already been used.

There are several object types. Physical objects, for example:

-  A **Fluide_incompressible** (incompressible_Fluid) object. This type of object is defined by its physical characteristics (its dynamic viscosity $\mu$ (keyword **mu**), its density $\rho$ (keyword **rho**), etc...).

-  A **Domaine**.

More abstract object types also exist:

-  A **VDF**, **VEFPreP1B**, **PolyMAC_P0P1NC** or **PolyMAC_P0** according to the discretization type.

-  A **Scheme_euler_explicit** to indicate the time scheme type.

-  A **Solveur_pression** to denote the pressure system solver type.

-  A **Uniform_field** to define, for example, the gravity field.

## Interpretor Notion

**Interprete** (interpretor) type objects are then used to handle the created objects with the following syntax:

```bash
Type_interprete argument
```

-  **Type_interprete**: any type derived from the **Interprete** (Interpretor) type recognised by **TRUST**.

-  **argument**: an argument may comprise one or several object identifiers and/or one or several data blocks.

Interpretors allow some operations to be carried out on objects.

Currently available general interpretors include **Read**, **Read_file**, **Ecrire** (Write), **Ecrire_fichier** (Write_file), **Associate**.

## Example

A data set to write Ok on screen:

```bash
Nom a_name        # Creation of an object type. Name identifier a_name #
Read a_name Ok    # Allocates the string "Ok" to a_name #
Ecrire a_name     # Write a_name on screen #
```

## Important Remarks

- To insert *comments* in the data set, use # .. # (or /\* ... \*/), the character # must always be enclosed by blanks.

- Comma separates items in a list (a comma must be enclosed with spaces or a new line).

- Interpretor keywords are not case sensitive.

- **On the contrary, object names (identifiers) are case sensitive.**

- In the following description, items (keywords or values) enclosed by [ and ] are *optional*.

- **TRUST** keywords can be highlighted with your file editor via the command line:
   
   ```bash
   trust -config gedit|vim|emacs
   ```
-  You can search for a keyword meaning in the [](../reference/index.rst)
  
-  You can search for example of a keyword usage in the pre-existing trust cases thanks to:
```bash
source $MY_TRUST_FOLDER/env_TRUST.sh
trust -search "keyword_name"
```

## Running a Data File

To use **TRUST**, your shell must be "bash". So ensure you are in the right shell:

```bash
echo $0
/bin/bash
```

To run your data file, you must initialize the **TRUST** environment using the following command:

```bash
source $my_path_to_TRUST_installation/env_TRUST.sh
TRUST vX.Y.Z support : trust@cea.fr
Loading personal configuration /$path_to_my_home_directory/.perso_TRUST.env
```

Then, you can launch sequentially your test case by using:
```bash
trust my_test_case.data
```

For more informations regarding parallel test case, go to the [](para.rst) section.

## Data file structure

In the sequel, let's dive into the structure of a `.data` file. You will find a full template of a `.data` file at the end of this page.
### Dimension

First, you need to choose the dimension of your problem, it can be either a two or three dimension problem:
```bash
Dimension 2
```

or

```bash
Dimension 3
```

### Problems

Then, you need to specify the type of problem you want to solve.

```bash
# Problem definition #
Pb_hydraulique my_problem
```

You can find all the available **TRUST** problems at [](pb.rst).

Here are some of the available **TRUST** problem types.

-  for Incompressible flow: **Pb\_[Thermo]Hydraulic[_Concentration]**

-  for Quasi-Compressible flow: **Pb_Thermohydraulique_QC**

-  for Weakly-Compressible flow: **Pb_Thermohydraulique_WC**

-  for Multi-Phase flow: **Pb_Multiphase**

-  for solid: **Pb_Conduction**

where:

-  **hydraulique**: means that we will solve Navier-Stokes equations without energy equation.

-  **Thermo**: means that we will solve Navier-Stokes equations with energy equation.

-  **Concentration**: that we will solve multiple constituent transportation equations.

-  **Conduction**: resolution of the heat equation.

-  **QC**: Navier-Stokes equations with energy equation for quasi-compressible fluid under low Mach approach.

-  **WC**: Navier-Stokes equations with energy equation for weakly-compressible fluid under low Mach approach.

### Domain Definition

To define the domain, you must name it. This is done thanks to the following block:

```bash
# Domain definition #
Domaine my_domain
```

Then you must add your mesh to your simulation.

### Mesh

Notice the presence of the tags

```bash
# Mesh #
# BEGIN MESH #
... ;
# END MESH #
```

This is useful for parallel calculation if well placed in the datafile (see section [](para.rst)).

#### Allowed meshes

**TRUST** allows all types of meshes if the appropriate spatial discretization is used. See the [](spatial-schemes.md) section for the list of available discretizations and some advices regarding there usage or the [](../num_meth/discretisation/discret.rst) section for more details regarding the undelying maths. 

In your `.data` file, you can either import a pre-existing mesh or build one quickly if your geometry is not that complex.

##### Import a mesh file

If your mesh was generated with an external tool like [SALOME](http://www.salome-platform.org) (open source software), [ICEM](http://resource.ansys.com/Products/Other+Products/ANSYS+ICEM+CFD) (commercial software), [Gmsh](http://gmsh.info/) (open source software, included in **TRUST** package) or [Cast3M](http://www-cast3m.cea.fr/) (CEA software), then you must use one of the following keywords into your data file:

-  **Read_MED** for a MED file from SALOME or Gmsh.

-  **Read_File** for a binary mesh file from ICEM. 

-  for another format, see the [](../reference/index.rst).

You can have a look too at the [](post-processing.md) section.

##### Quickly create a mesh

Here is an example of a simple geometry (of non complex channel type) using the internal tool of **TRUST**:

```bash
Mailler my_domain
{
   # Define the domain with one cavity #
   # cavity 1m*2m with 5*22 cells #
   Pave box
   {
      Origine 0. 0.
      Longueurs 1 2

      # Cartesian grid #
      Nombre_de_Noeuds 6 23

      # Uniform mesh #
      Facteurs 1. 1.
   }
   {
      # Definition and names of boundary conditions #
      bord Inlet  X = 0.   0. <= Y <= 2.
      bord Outlet X = 1.   0. <= Y <= 2.
      bord Upper  Y = 2.   0. <= X <= 1.
      bord Lower  Y = 0.   0. <= X <= 1.
   }
}
```

To use this mesh in your data file, you just have to add the previous block in your data file or save it in a file named for example `my_mesh.geo` and add the line:

```bash
Read_file my_mesh.geo ;
```
**Do not forget the semicolon at the end of the line!**


##### Transform mesh within the data file

You can also make transformations on your mesh after the **"Mailler"** or **"Read_"** command, using the following keywords:

-  **Trianguler** to triangulate your 2D cells and create an unstructured mesh 

-  **Tetraedriser** to tetrahedralise 3D cells and create an unstructured mesh 

-  **Raffiner_anisotrope** or **Raffiner_isotrope** to triangulate/tetrahedralise elements of an untructured mesh 

-  **ExtrudeBord** to generate an extruded mesh from a boundary of a tetrahedral or an hexahedral mesh ([doc here]

**Note:** ExtrudeBord in VEF generates 3 or 14 tetrahedra from extruded prisms.

-  **RegroupeBord** to build a new boundary with several boundaries of the domain 

-  **Transformer** to transform the coordinates of the geometry 

For more details regarding this commande, go find them in the [](../reference/index.rst). There, you will also find other commands, under the `interprete` section.

All theses keywords work on all mesh file formats (i.e. also for **\*.geo** or **\*.bin** or **\*.med** files).

#### Test your mesh

The keyword **Discretiser_domaine** is useful to discretize the domain (faces will be created) without defining a problem. Indeed, you can create a minimal data file, in order to create and post-process your mesh in, for example, the lata format and visualize it with VisIt.


**Note:** you must name all the boundaries to descretize!

Here is an example of this kind of data file:

```bash
dimension 3
Domaine my_domain

Mailler my_domain
{
   Pave box
   {
      Origine 0. 0. 0.
      Longueurs 1 2 1
      Nombre_de_Noeuds 6 23 6
      Facteurs 1. 1. 1.
   }
   {
      bord Inlet X = 0. 0. <= Y <= 2. 0. <= Z <= 1.
      bord Outlet X = 1. 0. <= Y <= 2. 0. <= Z <= 1.
      bord Upper Y = 2. 0. <= X <= 1. 0. <= Z <= 1.
      bord Lower Y = 0. 0. <= X <= 1. 0. <= Z <= 1.
      bord Front Z = 0. 0. <= X <= 1. 0. <= Y <= 2.
      bord Back Z = 1. 0. <= X <= 1. 0. <= Y <= 2.
   }
}

discretiser_domaine my_domain
postraiter_domaine { domaine my_domain fichier file format lata }
End
```

To use it, launch in a bash terminal:

```bash
# Initialize TRUST env if not already done
source $my_path_to_TRUST_installation/env_TRUST.sh
# Run you data file
trust my_data_file
visit -o file.lata &
```

To see how to use VisIt, look at the first [](../../quick_start.md).

### Spatial Discretization

You have to specify a discretization type to run a simulation. See the [](spatial-schemes.md). For example, if you want to use the **VDF** discretisation:
```bash
# Discretization on hexa or tetra mesh #
VDF my_discretization
```
### Time Schemes

Now you can choose your time scheme to solve your problem. For this you must specify the time scheme type wanted and give it a name. then you have to specify its parameters by filling the associated **Read** block.

```bash
# Time scheme explicit or implicit #
Scheme_euler_explicit my_scheme
Read my_scheme
{
  # Initial time #
  # Time step #
  # Output criteria #
  # Stop Criteria #
}
```

#### Some available time schemes

The time schemes available in the **TRUST** platform are summarized in the [](temporal-schemes.md) section.

Here are some available types of explicit schemes:

-  **Scheme_Euler_explicit** 

-  **Schema_Adams_Bashforth_order_2** 

-  **Runge_Kutta_ordre_3** 

And also some available types of implicit schemes:

-  **Scheme_Euler_implicit** 

-  **Schema_Adams_Moulton_order_3** 

For other schemes, see the `schematempsbas` section of the [](../reference/index.rst).

**Note:** you can treat implicitly the diffusion/viscous operators in a **TRUST** calculation. For that, you should activate the **diffusion_implicite** keyword in your explicit time scheme.

#### Calculation stopping condition

You must specify at least one stopping condition for you simulation in your time scheme block. It can be:

-  the final time: **tmax**

-  the maximal allowed cpu time: **tcpumax**

-  the number of time step: **nb_pas_dt_max**

-  the convergency treshold: **seuil_statio**

**Note**: if the time step reaches the minimal time step **dt_min**, **TRUST** will stop the calculation.

If you want to stop properly your running calculation (i.e. with all saves), you may use the `my_data_file.stop` file. When the simulation is running, you can see the **0** value in that file. To stop it, put a **1** instead of the **0**, save the file and at the next iteration the calculation will stop properly. When you don't change anything in that file, at the end of the calculation, you can see that it is writen **Finished correctly**.

### Objects association and discretization

#### Association

Until now, we have created some objects, now we must associate them together. For this, we must use the **Associate** interpretor:

```bash
# Association between the different objects #
Associate my_problem my_domain
Associate my_problem my_time_scheme
```
### Discretization

Then you must discretize your domain using the **Discretize** interpretor:

```bash
Discretize my_problem my_discretization
```
The problem *my_problem* is discretized according to the *my_discretization* discretization.

**IMPORTANT:**  A number of objects must be already associated (a domain, time scheme, ...) prior to invoking the **Discretize** keyword.
**Note:** when the discretization step succeeds, the mesh is validated by the code.

### Read problem block

Now that you have the create and associate your object, and discrtised your equations, you will need to specify your problem:

```bash
# Problem description #
Read my_problem
{
```

More information regarding this block are given in the [](pb.rst).

First, in this block, you will have to specify the type of equations you will solve. Your choices here depend on you problem choice, see the [](../reference/index.rst):
```bash
   # hydraulic problem #
   Navier_Stokes_standard
   {
```

#### Medium/Type of Fluide

Then you will specify the medium or fluid, you must add the following block.

```bash
      # Physical characteristics of medium #
      Fluide_Type { ... }
```

**Fluid_type** can be one of the following:

-  **Fluide_incompressible** 

-  **Fluide_Quasi_compressible** 

-  **Fluide_Weakly_Compressible** 

-  **Solide** 

- **Constituant** 

- **Milieu_Composite** 

For other types and more information see the [](../reference/index.rst).

**Note:** if you want to solve a coupled problem, each medium should be read in the corresponding problem.

#### Add Gravity

If needed, you can add a gravity term to your simulation. This is done by adding a uniform field, in the medium block since V1.9.1. 

For example in 2D:

```bash
# Gravity vector definition #
Gravity Uniform_field 2 0 -9.81
```

#### Pressure solver

The, you need to specify your pressure solver:
```bash
# Choice of the pressure matrix solver #
            Solveur_Pression solver { ... }
```

Go check the [](solvers.md) section to see the options you may use.

#### Diffusion, convection and sources

Now you will specify how you will treat the diffusion operator, the convection operator and the source terms.
``` bash
      # Diffusion operator #
      Diffusion { ... }

      # Convection operator #
      Convection { ... }

      # Sources #
      Sources { ... }
```
In the Diffusion block, you can but **negligeable** to deactivate the diffusion terme. 

In the convection block, you need to specify a spatial scheme. Have a look at the [](spatial-schemes.md) section for a list of the available schemes in **TRUST**.

In the sources block, you will define your source terms. You will need to go check the [](../reference/index.rst) to pick up the good keyword for your case. Here are some available source terms:
-  **Perte_Charge_Reguliere** type_perte_charge bloc_definition_pertes_charges 

-  **Perte_Charge_Singuliere** **KX \| KY \| KZ** coefficient_value { ... } 

-  **Canal_perio** { ... } 

-  **Boussinesq_temperature** { ... }, defined as $\rho(T)=\rho(T_0)(1-\beta_{th}(T-T_0))$

-  **Boussinesq_concentration** { ... }
-  
-  **Puissance_thermique** field_type bloc_lecture_champ 

#### Initial and boundary conditions

To define the initial and boundary conditions, make sure to add the following in your **# hydraulic problem # Navier_Stokes_standard** block:
```bash
     # Initial conditions #
      Initial_conditions { ... }

      # Boundary conditions #
      Boundary_conditions { ... }
   }
```
This should conclude this block.

Here is a list of the most used boundary conditions:

-  Bord **Frontiere_ouverte_vitesse_imposee** boundary_field_type *bloc_lecture_champ* 

-  Bord **Frontiere_ouverte_pression_imposee** boundary_field_type *bloc_lecture_champ* 

-  Bord **Paroi_fixe** 

-  Bord **Symetrie** 

-  Bord **Periodique** 

-  Bord **Frontiere_ouverte_temperature_imposee** boundary_field_type *bloc_lecture_champ* 

-  Bord **Frontiere_ouverte T_ext** boundary_field_type *bloc_lecture_champ* 

-  Bord **Paroi_adiabatique** 

-  Bord **Paroi_flux_impose** boundary_field_type *bloc_lecture_champ* 

To choose your *boundary_field_type* parameters, refer to the [](../reference/index.rst).

#### Post-processing

Still in your **Read my_problem** block, you will need to add a postprocessing block in order to specify your post-processing parameters:
``` bash
# Post_processing description #
# To know domains that can be treated directly, search in .err #
# output file: "Creating a surface domain named" #
# To know fields that can be treated directly, search in .err #
# output file: "Reading of fields to be postprocessed" #

Post_processing
{
   # Definition of new fields #
   Definition_Champs { ... }

   # Probes #
   Probes { ... }

   # Fields #
   # format default value: lml #
   # select ’lata’ for VisIt tool or ’MED’ for Salomé #
   format lata
   fields dt_post 1. { ... }

   # Statistical fields #
   Statistiques dt_post 1. { ... }
}
```
The post-processing options are listed in the [](post-processing.md)

#### Stop and restart 
If you want to stop or restart your computation, add the following after your post-processing block:
```bash
# Saving and restarting process #
[sauvegarde binaire datafile .sauv]
[resume_last_time binaire datafile .sauv]
# Don't forget to close your Read my_problem block #
} 
```
Some more details regarding this step are given in [](end_data.rst).
### Solve the problem

When you have specified everything else, you need to put the solving keyword at the end of your computation:

```bash
# The problem is solved with #
Solve my_problem
```

**This is mandatory, if you forgot to put it, TRUST will not run the simulation.**

## Template of a `.data` file
Here is the template of a basic sequential data file:

```bash
# Dimension 2D or 3D #
Dimension 2

# Problem definition #
Pb_hydraulique my_problem

# Domain definition #
Domaine my_domain

# Mesh #
# BEGIN MESH #
Read_file my_mesh.geo ;
# END MESH #

# For parallel calculation only! #
# For the first run: partitioning step #
# Partition my_domain
{
   Partition_tool partitioner_name { option1 option2 ... }
   Larg_joint 2
   zones_name DOM
   ...
}
End #

# For parallel calculation only! #
# For the second run: read of the sub-domains #
# Scatter DOM .Zones my_domain #

# Discretization on hexa or tetra mesh #
VDF my_discretization

# Time scheme explicit or implicit #
Scheme_euler_explicit my_scheme
Read my_scheme
{
   # Initial time #
   # Time step #
   # Output criteria #
   # Stop Criteria #
}

# Association between the different objects #
Associate my_problem my_domain
Associate my_problem my_scheme

# Discretization of the problem #
Discretize my_problem my_discretization

# New domains for post-treatment #
# By default each boundary condition of the domain is already extracted #
# with names such as "my_dom"_boundaries_"my_BC" #
Domaine plane
extraire_surface
{
   domaine plane
   probleme my_probleme
   condition_elements (x>0.5)
   condition_faces (1)
}

# Problem description #
Read my_problem
{

   {
      # hydraulic problem #
      Navier_Stokes_standard
      {
         # Physical characteristics of medium #
         Fluide_Incompressible
         {
         ...
         # Gravity vector definition #
         gravity Uniform_field 2 0 -9.81
         }

         # Choice of the pressure matrix solver #
         Solveur_Pression solver { ... }

         # Diffusion operator #
         Diffusion { ... }

         # Convection operator #
         Convection { ... }

         # Sources #
         Sources { ... }

         # Initial conditions #
         Initial_conditions { ... }

         # Boundary conditions #
         Boundary_conditions { ... }
      }

      # Post_processing description #
      # To know domains that can be treated directly, search in .err #
      # output file: "Creating a surface domain named" #

      # To know fields that can be treated directly, search in .err #
      # output file: "Reading of fields to be postprocessed" #

      Post_processing
      {
         # Definition of new fields #
         Definition_Champs { ... }

         # Probes #
         Probes { ... }

         # Fields #
         # format default value: lml #
         # select 'lata' for VisIt tool or 'MED' for Salomé #
         format lata
         fields dt_post 1. { ... }

         # Statistical fields #
         Statistiques dt_post 1. { ... }
      }

      # Saving and restarting process #
      [sauvegarde binaire datafile .sauv]
      [resume_last_time binaire datafile .sauv]

   # End of the problem description block #
   }

# The problem is solved with #
Solve my_problem

# Not necessary keyword to finish #
End
```


