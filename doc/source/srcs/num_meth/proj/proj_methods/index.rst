

Chorin algorithm 
~~~~~~~~~~~~~~~~~~~~~~~~


The first projection method was proposed by :cite:`C67` and :cite:`T69`. In this algorithm, the pressure is not taken for the intermediate velocity.


Step 1 : velocity prediction 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

We call :math:`U^*` the intermediate velocity vector, which verifies the following equation :

.. math::

    \mathbb{M} \frac{U^{*} - U^n}{\delta t^n} + \mathbb{A}U^* = F^{n+1}

The boundary conditions of the unknown :math:`U^*` is the same as the one imposed for :math:`U^{n+1}`. Note that :math:`U^*` has no reason to be divergence-free. 

The goal of step 2 is to find the pressure unknown which can correct the intermediate velocity :math:`U^*` to be divergence-free.



Step 2 : pressure correction 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In this step, the convection matrix and the laplacian matrix are volontary avoided (because the mass matrix is easy to inverse). We find the pressure :math:`P^{n+1}` which verifies: 

.. math::

    \begin{aligned}
    \mathbb{M} \frac{U^{n+1} - U^*}{\delta t^n}  + \mathbb{B}^{T}P^{n+1} = 0,\\
    \mathbb{B} U^{n+1} = 0.
    \end{aligned}

Left multiplying the momentum conservation equation by :math:`\mathbb{B} \mathbb{M}^{-1}`, because of the divergence-free of :math:`U^{n+1}`, we obtain a linear system on :math:`P^{n+1}` which is comparable with a 
Poisson system on pressure : 

.. math::

    \delta t^n \mathbb{B} \mathbb{M}^{-1}\mathbb{B}^{T}P^{n+1} = \mathbb{B}U^*

*Note that this manipulation can not be done with a weak formulation as we usually do in finite elements methods. 
With more regularity, we can directly consider* :math:`\delta t^{n} \Delta p^{n+1} = \nabla\cdot u^*` *for the analysis.*

The boundary condition for the pressure is modified at this step. 

Step 3 : update 
^^^^^^^^^^^^^^^
Once the pressure has been solved, the velocity can be updated with the momentum conservation equation coming from step 2. It comes:

.. math:: 

    U^{n+1} = U^* + \delta t^n \mathbb{M}^{-1}\mathbb{B}^{T}P^{n+1}

Note that if we sum the system from step 1 and 2, we obtain the following reconstructed system: 

.. math::

    \begin{aligned}
    \mathbb{M} \frac{U^{n+1} - U^n}{\delta t^n}  + \mathbb{A}U^* + \mathbb{B}^{T}P^{n+1} = F^{n+1},\\
    \mathbb{B} U^{n+1} = 0.
    \end{aligned}

Remark that the velocity :math:`U^*` is present in the final system behind the convection and the laplacian (matrix :math:`\mathbb{A}`). 
It introduces a small error so-called a *splitting error* (find REF). 

In TRUST, this method is used for explicit scheme.

.. to verify this remark with PL or ABN


Chorin algorithm with pressure increment
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

A small modification of Chorin projection can be done for the pressure. It consists in taking the pressure at previous time at step 1, and solve an increment of pressure at step 2.
This method is used for semi-implicited schemes (explicit schemes with diffusion implicited) or implicit schemes. 

Step 1 : velocity prediction 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The idea of this step is considerably the same as the Chorin algorithm, excepted the addition of the gradient of pressure solved at time 
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

    \delta t^n \mathbb{B} \mathbb{M}^{-1}\mathbb{B}^{T} \delta P = \mathbb{B}U^*


Step 3 : update 
^^^^^^^^^^^^^^^

Once the pressure increment solved, the velocity and the pressure at time :math:`t^{n+1}` are updated: 


.. math:: 

    U^{n+1} = U^* + \delta t^n \mathbb{M}^{-1} \mathbb{B}^{T} \delta P^{n+1}\\
    P^{n+1} = P^n + \delta P.

Note that the reconstructed system is the same as the Chorin algorithm, but the approximation of :math:`U^*` is closer to :math:`U^{n+1}` due to the system proposed in step 1. 





SIMPLE algorithm 
~~~~~~~~~~~~~~~~

Semi-Implicit Method for Pressure Linked Equations (SIMPLE) is a second projection method proposed by :cite:`PS72`, it is quite similar to Chorin projection 
method with pressure increment, except that the mass matrix :math:`\mathbb{M}/\delta t^n` at step 2 and 3 is replaced by the addition of  :math:`\mathbb{M}/\delta t^n` and the diagonal matrix of the convection diffusion matrix. We note:

.. math:: 

    \mathbb{D} := diag(\mathbb{A} + \frac{\mathbb{M}}{\delta t^n})  

Thus, the pressure correction becomes: 
   
.. math:: 
    \mathbb{B} \mathbb{D}^{-1}\mathbb{B}^{T} \delta P = \mathbb{B}U^*

and the update:

.. math:: 

    U^{n+1} = U^* + \delta t^n \mathbb{D}^{-1} \mathbb{B}^{T} \delta P^{n+1}\\
    P^{n+1} = P^n + \delta P.

A relaxation can be done at the update step for the pressure (or the velocity). 

The reconstructed system obtain by summing the two steps is quite similar to the Chorin reconstructed system, except that the intermediate velocity :math:`U^*` has less importance here. If we note :math:`\mathbb{D_A}` the diagonal part of :math:`\mathbb{A}` and :math:`\mathbb{E_A}` its non diagonal, it comes:

.. math::

    \begin{aligned}
    \mathbb{M} \frac{U^{n+1} - U^n}{\delta t^n}  + \mathbb{D_A}U^{n+1} + \mathbb{E_A}U^* + \mathbb{B}^{T}P^{n+1} = F^{n+1},\\
    \mathbb{B} U^{n+1} = 0.
    \end{aligned}

Implementations details can be found in Simple.h

To reduce the importance of the intermediate velocity has been proposed a pre-compute pressure step with the SIMPLER algorithm. 


SIMPLER algorithm 
~~~~~~~~~~~~~~~~~
SIMPLE Revised algorithm (SIMPLER) consists in applying SIMPLE algorithm with a pre-computed pressure, which consider the non-diagonal term of :math:`\mathbb{A} + \mathbb{M}/\delta t^n`. 

Step 0 :  pre-compute the pressure
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The goal of this step is to find a pre-computed pressure :math:`P^{n+1}` in which we apply the SIMPLE algorithm.


Let's define the non diagonal term of :math:`\mathbb{A} + \mathbb{M}/\delta t^n` such that : 

.. math::

    \mathbb{E} :=  \mathbb{A} + \mathbb{M}/\delta t^n -  \mathbb{D}

To find the pre-computed pressure, an intermediate velocity :math:`U^p` is find, resolving the following system:

.. math:: 
     \mathbb{D}(U_{n}) U^p - \mathbb{E}U^n = F^{n+1}


Note that this system looks like the velocity prediction step for Chorin projection without pressure increment which would be semi-implicited (the diagonal part is implicited and the non-diagonal is explicited).
This system is easy do solve because :math:`\mathbb{D}` is diagonal. Once :math:`U^p` is determined, the pre-computed pressure is solved, verifying 

.. math:: 

    \mathbb{B} \mathbb{D}^{-1} \mathbb{B}^t P^{n+1} = \mathbb{B}U^p. 

The system comes from the continuity equation 

.. math:: 
    \mathbb{D}(U^n) (U^{n+1} - U^p) + \mathbb{B}^t P^{n+1} = 0,\\
    \mathbb{B} U^{n+1} = 0. 

.. *Note that the reconstructed system becomes*

.. math

..    \mathbb{D}(U^n) U^{n+1} - E(U^n)U^n + \mathbb{B}^t P^{n+1} = F^{n+1}. 

Implementations details can be found in Simpler.h


Step 1 : SIMPLE algorithm on :math:`(U^{n+1}, P^{n+1})` 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The rest of the algorithm is the same that SIMPLE algorithm i.e.: 

- velicity prediction : find the intermediate velocity :math:`U^*`, solution of the following system:

.. math:: 

    \mathbb{M} \frac{U^{*} - U^n}{\delta t^n} + \mathbb{A}U^* + \mathbb{B}^{T}P^{n+1} = F^{n+1}.

- pressure correction : correct the velocity to respect the divergence-free constraint: 

.. math::

    \mathbb{B} \mathbb{D}^{-1}\mathbb{B}^{T} \delta P = \mathbb{B}U^*


- update the field with the intermediate velocity:

.. math:: 

    U^{n+1} = U^* + \delta t^n \mathbb{D}^{-1} \mathbb{B}^{T} \delta P^{n+1}\\

Note that the pressure is not updated between step 0 and step 1, only the velocity is corrected here!

PISO algorithm 
~~~~~~~~~~~~~~~
The Pressure-Implicit with Splitting of Operators algorithm (PISO) was proposed in :cite:`I83`. It is a two steps projection method which is a SIMPLE algorithm with a 
second step which consider the non diagonal part of the convection-diffusion matrix :math:`\mathbb{A}`.
 
Step 1 : SIMPLE algorithm
^^^^^^^^^^^^^^^^^^^^^^^^^

As the Chorin projection method with pressure increment, the velicity prediction consists in finding the first intermediate :math:`U^*` which satisfies the momentum equation 

.. math:: 
    \mathbb{M} \frac{U^{*} - U^n}{\delta t^n} + \mathbb{A}U^* + \mathbb{B}^{T}P^{n} = F^{n+1}.


Then, find the first pressure increment :math:`\delta P^{p1}`, by solving the first Poisson equation:

.. math:: 
    \mathbb{B} \mathbb{D}^{-1}\mathbb{B}^{T} \delta P^{p1} = \mathbb{B}U^*


Then, update the first pressure :math:`P^{p1}` and velocity fields :math:`U^{p1}`. :

.. math:: 
    U^{p1} = U^* + \mathbb{D}^{-1} \mathbb{B}^{T} \delta P^{p1}\\
    P^{p1} = P^n + \delta P^{p1}.

Step 2 : Second pressure correction
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The diagonal term of the convection-diffusion matrix has been considered in the system at the SIMPLE step, the second pressure correction considers the non diagonal part. 

The poisson system is:

.. math:: 
    \mathbb{B} \mathbb{D}^{-1}\mathbb{B}^t \delta P^{p2} = \mathbb{B} \mathbb{D}^{-1} \mathbb{E_A} U^{p1}



Finally, update the velocity and the pressure fields at the next time step. 

.. math:: 
    U^{n+1} = \mathbb{E_A}U^{p1} - \mathbb{B}^t \delta P^{p2}\\
    P^{n+1} =   P^{p1} + \delta P^{p2}

Algebraic details are presented in :cite:`I83` or in Piso.h

.. Uzawa algorithm ? 
.. ~~~~~~~~~~~~~~~~~