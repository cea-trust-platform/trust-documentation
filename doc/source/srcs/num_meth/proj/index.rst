Projection methods
==================

Initially introduced in :cite:`C67` - :cite:`T69`, pressure projection methods are a way to separate pressure and velocity unknowns. 
These methods are usefull to improve calculation performances, especially when the degrees of freedom are high.

The idea of these methods has two main steps:

* a velocity prediction : we want to try predicting an intermediate velocity without divergence-free constraint and without solving the pressure.  
* a pressure correction : find the pressure which corrects the intermediate velocity to be divergence-free again. 

In TRUST code, several projection methods have been implemented: 

* The Chorin projection method (with or without pressure increment)
* The SIMPLE algorithm
* The SIMPLER algorithm
* The PISO algorithm

Note these methods introduce a splitting error, which can be neglected comparing to the error due to monolitical resolution of the velocity-presure sytem with bad condition number with a lot of degrees of freedom.
An overview of projection method for incompressible flows is well presented in :cite:`GMS06` and performance comparison is presented in :cite:`JJA07`.   


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


*Note that the pressure projection algorithm also exists with the vorticity unknown (see FINDREFPOLYMAC)*
    
.. Initial projection
.. ~~~~~~~~~~~~~~~~~~

.. .. toctree::
    :maxdepth: 2

    initial_proj/index



List of the available projection methods in TRUST
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
.. toctree::
    :maxdepth: 2

    proj_methods/index