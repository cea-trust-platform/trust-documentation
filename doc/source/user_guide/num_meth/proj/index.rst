Projection methods
==================

Initially introduced in :cite:`C67` - :cite:`T69`,
pressure projection methods are a way to separate pressure and velocity
unknowns for incompressible flows. These methods are usefull to improve calculation performances,
especially when the degrees of freedom are high.

The idea of these methods has two main steps:


1. **a velocity prediction**: we want to try predicting an intermediate velocity without divergence-free constraint and without solving the pressure.

2. **a pressure correction**: find the pressure which corrects the intermediate velocity to be divergence-free again.

In TRUST code, several projection methods have been implemented:

* The Chorin projection method (with or without pressure increment)
* The SIMPLE algorithm
* The SIMPLER algorithm
* The PISO algorithm

In the litterature, projection methods are presented in two opposite ways: 


* *the functional formulation*: considering a good regularity for the pressure and the velocity, we take the diffential original systems with the strong formulation and manipulate the differential operators in order to enounce PDEs for the prediction and the correction steps. It often involves homogeneous Neumann conditions on Pressure for the correction step. This approach is popular in the FE community. 

* *the algebraic formulation*: once the prediction and the correction steps have been discretized, we do algebraic manipulations on matrix forms to create the linear systems involved. The homogeneous Neumann conditions on pressure is replaced by homogeneous Dirichlet or normal homogeneous Dirichlet for the velocity on correction step in order to prove convergence of projection methods. This approach is often associated with Uzawa algorithm for saddle-point problems. 


The convergence proof with the functional and the algebraic formulation has been done in :cite:`G96` for the Chorin algorithm and an overview of projection methods for incompressible flows is
well presented in :cite:`GMS06`. A performance comparison between the differents projections methods is proposed in :cite:`JJA07`.


Because of the low order discretization methods used in TRUST, we present projection methods with the algebraic formulation.



Initial system 
~~~~~~~~~~~~~~

These methods do not depend on the spacial discretization (EF, VDF, VEF in TRUST). Considering the matricial problem such that :


.. math:: 

    \begin{aligned}
    \mathbb{M} \frac{U^{n+1} - U^n}{\delta t^n} + \mathbb{L}U^m + C(U^m)U^m + \mathbb{B}^{T}P^{n+1} = F^{m} \\
    \mathbb{B} U^{n+1} = 0
    \end{aligned}


For the Navier-Stokes equation, :math:`\mathbb{L}` represents the laplacian matrix, :math:`\mathbb{C}(.)` the convection matrix, :math:`\mathbb{B}^T` the pressure gradient matrix, and :math:`\mathbb{B}` the diffusion matrix.
The unknowns are :math:`U` for the velocity vector, :math:`P` the pressure and the source term is :math:`F` for the momentum conservation equation. 
 
The laplacian and the convective operators can be etiher explicit or implicit (:math:`m\in \{n, n+1\}`). 

For the presentation and we take the source term implicitely, we replace 

.. math::
    \mathbb{L}U^m + C(U^m)U^m
    
by 
 
.. math::
    \mathbb{L}U^{n+1} + C(U^n)U^{n+1} =:\mathbb{A}U^{n+1}.


Note that the pressure projection algorithm also exists with the vorticity unknown (see :cite:`Bonelle2014`)
    
Initial projection
~~~~~~~~~~~~~~~~~~

.. toctree::
    :maxdepth: 2

    initial_proj/index



List of the available projection methods in TRUST
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
.. toctree::
    :maxdepth: 2

    proj_methods/index