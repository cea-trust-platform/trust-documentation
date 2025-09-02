Problem definition
==================

Set of Equations
----------------



Incompressible problems
^^^^^^^^^^^^^^^^^^^^^^^

**TRUST** solves Navier-Stokes equations with/without the heat equation for an incompressible fluid:

.. math::

   \left\{
   \begin{array}{c}
   \nabla \cdot \vec u =0 \\
   \displaystyle{\frac{\partial \vec u }{\partial t} + \textcolor{red}{\nabla \cdot (\vec u \otimes \vec u)} = \textcolor{blue}{\nabla \cdot (\nu \nabla \vec u)} - \nabla P^* } \\
   \displaystyle{\frac{\partial T}{\partial t} + \textcolor{red}{\vec u \nabla T} = \textcolor{blue}{\nabla \cdot (\alpha \nabla T)} + \frac{Q}{\rho C_p}}
   \end{array}
   \right.

where: :math:`\displaystyle{P^*=\frac{P}{\rho} + g z}`, :math:`Q` is the
heat source term, and:

-  :math:`\rho`: density,

-  :math:`\mu`: dynamic viscosity,

-  :math:`\displaystyle{\nu=\frac{\mu}{\rho}}`: kinematic viscosity,

-  :math:`\vec g=g z`: gravity vector in cartesian coordinates,

-  :math:`\displaystyle{\alpha=\frac{\lambda}{\rho C_p}}`: thermal
   diffusivity.

-  :math:`C_p`: specific heat capacity at constant pressure,

-  :math:`\lambda`: thermal conductivity,

.. note::

   Red terms are convective terms and blue terms are diffusive terms.

In your data file, you will have:

.. code-block:: bash

   Pb_Thermohydraulique_Concentration my_problem
   ...
   Read my_problem
   {
      # Define medium and its properties + gravity if any #
      Fluide_incompressible { ... }

      # Navier Stokes equations #
      Navier_Stokes_Standard
      {
         Solveur_Pression my_solver { ... }
         Diffusion { ... }
         Convection { ... }
         Initial_conditions { ... }
         Boundary_conditions { ... }
         Sources { ... }
         ...
      }

      # Energy equation #
      Convection_Diffusion_Temperature
      {
         Diffusion { ... }
         Convection { ... }
         Initial_conditions { ... }
         Boundary_conditions { ... }
         Sources { ... }
         ...
      }

      # Constituent transportation equations #
      Convection_Diffusion_Concentration
      {
         Diffusion { ... }
         Convection { ... }
         Initial_conditions { ... }
         Boundary_conditions { ... }
         Sources { ... }
         ...
      }
   }

Quasi-Compressible problem
^^^^^^^^^^^^^^^^^^^^^^^^^^

**TRUST** solves Navier-Stokes equations with/without heat equation for quasi-compressible fluid:

.. math::

   \left\{
   \begin{array}{c}
   \displaystyle{\frac{\partial \rho }{\partial t} + \nabla \cdot (\rho \vec u) =0 }\\
   \displaystyle{ \frac{\partial \rho \vec u}{\partial t} + \textcolor{red}{\nabla \cdot (\rho \vec u \vec u)} =  \textcolor{blue}{\nabla \cdot \left(\mu \nabla \vec u \right)} - \nabla P -\rho \vec g }\\
   \displaystyle{ \rho C_p \left( \frac{\partial T}{\partial t} + \textcolor{red}{\vec u \nabla T} \right) = \textcolor{blue}{\nabla \cdot \left(\lambda \nabla T\right)} + \frac{dP_0}{dt} + Q }
   \end{array}
   \right.

where: :math:`P_0=\rho R T`, :math:`Q` is a heat source term, and:

-  :math:`\rho`: density,

-  :math:`\mu`: dynamic viscosity,

-  :math:`\vec g=g z`: gravity vector in cartesian coordinates,

-  :math:`C_p`: specific heat capacity at constant pressure,

-  :math:`\lambda`: thermal conductivity.

.. note::

   Red terms are convective terms and blue terms are diffusive terms.

In your data file, you will have:

.. code-block:: bash

   Pb_Thermohydraulique_QC my_problem
   ...
   Read my_problem
   {
      # Define medium and its properties + gravity if any #
      Fluide_Quasi_compressible { ... }

      # Navier Stokes equations for quasi-compressible fluid under low Mach numbers #
      Navier_Stokes_Turbulent_QC
      {
         Solveur_Pression my_solver { ... }
         Diffusion { ... }
         Convection { ... }
         Initial_conditions { ... }
         Boundary_conditions { ... }
         Sources { ... }
         ...
      }

      # Energy equation for quasi-compressible fluid under low Mach numbers #
      Convection_Diffusion_Chaleur_QC
      {
         Diffusion { ... }
         Convection { ... }
         Initial_conditions { ... }
         Boundary_conditions { ... }
         Sources { ... }
         ...
      }
   }

Weakly-Compressible problem
^^^^^^^^^^^^^^^^^^^^^^^^^^^

**TRUST** solves Navier-Stokes equations with/without heat equation for weakly-compressible fluid:

.. math::

   \left\{
   \begin{array}{c}
   \displaystyle{\frac{\partial \rho }{\partial t} + \nabla \cdot (\rho \vec u) =0 }\\
   \displaystyle{ \frac{\partial \rho \vec u}{\partial t} + \textcolor{red}{\nabla \cdot (\rho \vec u \vec u)} =  \textcolor{blue}{\nabla \cdot \left(\mu \nabla \vec u \right)} - \nabla P -\rho \vec g }\\
   \displaystyle{ \rho C_p \left( \frac{\partial T}{\partial t} + \textcolor{red}{\vec u \nabla T} \right) = \textcolor{blue}{\nabla \cdot \left(\lambda \nabla T\right)} + \frac{dP_{tot}}{dt} + Q }
   \end{array}
   \right.

where: :math:`P_{tot}=\rho R T`, :math:`Q` is a heat source term, and:

-  :math:`\rho`: density,

-  :math:`\mu`: dynamic viscosity,

-  :math:`\vec g=g z`: gravity vector in cartesian coordinates,

-  :math:`C_p`: specific heat capacity at constant pressure,

-  :math:`\lambda`: thermal conductivity.

.. note::

   Red terms are convective terms and blue terms are diffusive terms.

In your data file, you will have:

.. code-block:: bash

   Pb_Thermohydraulique_WC my_problem
   ...
   Read my_problem
   {
      # Define medium and its properties + gravity if any #
      Fluide_Weakly_compressible { ... }

      # Navier Stokes equations for weakly-compressible fluid under low Mach numbers #
      Navier_Stokes_Turbulent_WC
      {
         Solveur_Pression my_solver { ... }
         Diffusion { ... }
         Convection { ... }
         Initial_conditions { ... }
         Boundary_conditions { ... }
         Sources { ... }
         ...
      }

      # Energy equation for weakly-compressible fluid under low Mach numbers #
      Convection_Diffusion_Chaleur_WC
      {
         Diffusion { ... }
         Convection { ... }
         Initial_conditions { ... }
         Boundary_conditions { ... }
         Sources { ... }
         ...
      }
   }

Conduction problem
^^^^^^^^^^^^^^^^^^

For this kind of problems, **TRUST** solves the heat equation:

.. math:: \rho C_p \frac{\partial T}{\partial t} = \textcolor{blue}{\nabla \cdot \left(\lambda \nabla T\right)} + Q

where:

-  :math:`\rho`: density,

-  :math:`C_p`: specific heat capacity at constant pressure,

-  :math:`\lambda`: thermal conductivity,

-  :math:`Q` is a heat source term.

.. note::
   The term in blue is the diffusive term.

In your data file, you will have:

.. code-block:: bash

   Pb_Conduction my_problem
   ...
   Read my_problem
   {
      # Define medium and its properties #
      Solide { ... }

      # Resolution of the heat equation #
      Conduction
      {
         Diffusion { ... }
         Convection { ... }
         Initial_conditions { ... }
         Boundary_conditions { ... }
         Sources { ... }
         ...
      }
   }

Coupled problems
^^^^^^^^^^^^^^^^

With **TRUST**, we can couple problems. We will explain here the method for two problems but you can couple as many problems as you want.

To couple two problems, we define two problems *my_problem_1* and *my_problem_2* each one associated to a separate domain *my_domain_1* and *my_domain_2*, and to a separate medium *my_medium_1* and *my_medium_2* (associated or not to the gravity).

.. code-block:: bash

   Dimension 2
   Pb_ThermoHydraulique my_problem_1
   Pb_ThermoHydraulique my_problem_2

   Domaine my_domain_1
   Read_file my_mesh_1.geo ;

   Domaine my_domain_2
   Read_file my_mesh_2.geo ;

   Associate my_problem_1 my_domain_1
   Associate my_problem_2 my_domain_2

Then we define a coupled problem associated to a single time scheme like for example:

.. code-block:: bash

   Probleme_Couple my_coupled_problem

   VEFPreP1B my_discretization

   Scheme_euler_explicit my_scheme
   Read my_scheme { ... }

   Associate my_coupled_problem my_problem_1
   Associate my_coupled_problem my_problem_2
   Associate my_coupled_problem my_scheme

Then we discretize and solve everything:

.. code-block:: bash

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

You can see the documentation of this kind of problem in the `TRUST Reference Manual <https://raw.githubusercontent.com/cea-trust-platform/trust-code/next/doc/TRUST/TRUST_Reference_Manual.pdf#coupledproblem>`__.