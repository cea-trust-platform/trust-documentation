Projection methods
==================

Initially introduced in [C67]_ - [T69]_, pressure projection methods are a way to separate pressure and velocity unknowns. 
These methods are usefull to improve calculation performances, especially when the degrees of freedom are high.

The idea of these methods has two steps:

* The velocity prediction : we want to try predicting an intermediate velocity without divergence-free constraint and whithout solving the pressure.  
* The pressure correction : find the pressure which corrects the intermediate velocity to be divergence-free again. 

In TRUST code, several projection methods have been implemented: 

* The Chorin-Temam projection method 
* The SIMPLE algorithm
* The SIMPLER algorithm
* The PISO algorithm

Note these methods introduce a splitting error, which can be neglected comparing to the error due to monolitical resolution of the velocity-presure sytem with bad condition number with a lot of degrees of freedom.
An overview of projection method for incompressible flows is well presented in [GMS06]_.   


Initial system 
~~~~~~~~~~~~~~

These methods do not depend on the spacial discretization (EF, VDF, VEF in TRUST). Considering the matricial problem such that :


.. math:: 

    \begin{aligned}
    \mathbb{M} \frac{U^{n+1} - U^n}{\delta t^n} + \mathbb{L}U^m + C(U^m)U^m + \mathbb{B}^{T}P^{n+1} = F^{m} \\
    \mathbb{B} U^{n+1} = 0
    \end{aligned}


For the Navier-Stokes equation, :math:`\mathbb{L}` represents the Laplacian matrix, :math:`\mathbb{C}(.)` the convection matrix, :math:`\mathbb{B}^T` the pressure gradient matrix, and :math:`\mathbb{B}` the diffusion matrix.
The unknowns are :math:`U` for the velocity vector, :math:`P` the pressure and the source term is :math:`F` for the momentum conservation equation. 
 
The Laplacian and the convective operators can be etiher explicit or implicit (:math:`m\in \{n, n+1\}`). 

For the presentation and we take the source term implicitely, we replace 

.. math::
    \mathbb{L}U^m + C(U^m)U^m
    
by 
 
.. math::
    \mathbb{L}U^{n+1} + C(U^n)U^{n+1} =:\mathbb{A}U^{n+1}.
    

Initial projection
~~~~~~~~~~~~~~~~~~

This part is work in progress right now, I am not sure for every methods. 



Chorin - Temam algorithm 
~~~~~~~~~~~~~~~~~~~~~~~~


The first projection method was proposed by [C67]_ and [T69]_. In this aligorithm, the pressure is not taken for the intermediate velocity.


Step 1 : velocity prediction 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

We call :math:`U^*` the intermediate velocity vector, which verifies the following equation :

.. math::

    \mathbb{M} \frac{U^{*} - U^n}{\delta t^n} + \mathbb{A}U^* = F^{n+1}

The boundary conditions of the unknown :math:`U^*` is the same as the one imposed for :math:`U^{n+1}`. Note that :math:`U^*` has no reason to be divergence-free. 

The goal of step 2 is to find the pressure unknown which can correct the intermediate velocity :math:`U^*` to be divergence-free.



Step 2 : pressure correction 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In this step, the convection matrix and the Laplacian matrix are volontary avoided. We find the pressure :math:`P^{n+1}` which verifies: 

.. math::

    \begin{aligned}
    \mathbb{M} \frac{U^{n+1} - U^*}{\delta t^n}  + \mathbb{B}^{T}P^{n+1} = 0,\\
    \mathbb{B} U^{n+1} = 0.
    \end{aligned}

Left multiplying the momentum conservation equation by :math:`\mathbb{B} \mathbb{M}^{-1}`, because of the divergence-free of :math:`U^{n+1}`, we obtain a linear system on :math:`P^{n+1}`` which is comparable with a 
Poisson system on pressure : 

.. math::

    \mathbb{B} \mathbb{M}^{-1}\mathbb{B}^{T}P^{n+1} = \mathbb{B}U^*

*Note that this manipulation can not be done with a weak formulation as we usually do in finite elements methods. 
With more regularity, we can directly consider* :math:`\Delta p^{n+1} = \nabla\cdot u^*` *for the analysis.*

The boundary condition for the pressure is modified at this step. 

Step 3 : update 
^^^^^^^^^^^^^^^
Once the pressure has been solved, the velocity can be updated with the momentum conservation equation coming from Step 2. It comes:

.. math:: 

    U^{n+1} = U^* + \delta t^n \mathbb{M}^{-1}\mathbb{B}^{T}P^{n+1}

Note that if we sum the system from step 1 and 2, we obtain the following reconstructed system: 

.. math::

    \begin{aligned}
    \mathbb{M} \frac{U^{n+1} - U^n}{\delta t^n}  + \mathbb{A}U^* + \mathbb{B}^{T}P^{n+1} = F^{n+1},\\
    \mathbb{B} U^{n+1} = 0.
    \end{aligned}

Remark that the velocity :math:`U^*` is present in the final system behind the convection and the Laplacian (matrix :math:`\mathbb{A}`). 
It introduces a small error so-called a *splitting error* (find REF). 



SIMPLE algorithm 
~~~~~~~~~~~~~~~~

Semi-Implicit Method for Pressure Linked Equations (SIMPLE) is a second projection method proposed by [PS72]_.It consists in taking the pressure at previous time at step 1, and solve an increment of pressure at step 2.


Step 1 : velocity prediction 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The idea of this step is considerably the same as the Chorin-Temam algorithm, excepted the addition of the gradient of pressure solved at time 
:math:`t^{n}`. We write:

.. math::

    \mathbb{M} \frac{U^{*} - U^n}{\delta t^n} + \mathbb{A}U^* + \mathbb{B}^{T}P^{n} = F^{n+1}.

With this addition, the intermediate velocity :math:`U^*` solves a semi-implicited Navier-Stokes equation, with no divergence-free constraint. 



Step 2 : pressure correction 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Adding the pressure at the previous times step for the velocity prediction implies that we need to substract it for the pressure correction system. It comes:  

.. math::

    \begin{aligned}
    \mathbb{M} \frac{U^{n+1} - U^*}{\delta t^n}  + \mathbb{B}^{T} \delta P = 0,\\
    \mathbb{B} U^{n+1} = 0,
    \end{aligned}

with the pressure increment :math:`\delta P:= P^{n+1} - P^n`. With the same manipulation presented for the Chorin algorithm, we obtain the following system on pressure increment: 

.. math::

    \mathbb{B} \mathbb{M}^{-1}\mathbb{B}^{T} \delta P = \mathbb{B}U^*


Step 3 : update 
^^^^^^^^^^^^^^^

Once the pressure increment solved, the velocity and the pressure at time :math:`t^{n+1}` are updated: 


.. math:: 

    U^{n+1} = U^* + \delta t^n \mathbb{M}^{-1} \mathbb{B}^{T} \delta P^{n+1}\\
    P^{n+1} = P^n + \delta P.

Note that the reconstructed system is the same as the Chorin-Temam algorithm, but the approximation of :math:`U^*` is closer to :math:`U^{n+1}` due to the system proposed in step 1. 


SIMPLER algorithm 
~~~~~~~~~~~~~~~~~
SIMPLE Revised algorithm (SIMPLER)



PISO algorithm 
~~~~~~~~~~~~~~~
Pressure-Implicit with Splitting of Operators



PISO [I83]_



Uzawa algorithm ? 
~~~~~~~~~~~~~~~~~