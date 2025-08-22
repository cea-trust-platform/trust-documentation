Boundary conditions
===================

Blabla BC

    ** Specificities
    ** Periodicity 
       - quand possible et quand pas possible
       - modification maillage
       - modification matrices

       

Robin boudary conditions
------------------------

Note that this boundary condition is only valid with the VEF Pnc/P0 discretization. 

Robin boundary conditions consist in a linear combination between one flux :math:`\boldsymbol{F}` term and the variables term. This type of boundary condition can be usefull for Fluid structures interactions or domain decomposition for instance. 
The one implemented in TRUST is decomposed between the normal and the tangential part. Let's define the outward normal vector :math:`\boldsymbol{n}`. 


The flux term becomes:

.. math::
    \boldsymbol{F} = F_n \boldsymbol{n} + \boldsymbol{F_t}
    
with :math:`F_n` the normal part of the flux term and :math:`\boldsymbol{F_t}` the tangential part of the flux term. 

For the Navier-Stokes equations, the flux terms can be written like that:

.. math:: 
    \begin{aligned}
    F_n &= \nu \nabla_n \boldsymbol{u} \cdot \boldsymbol{n} + \chi (\boldsymbol{u}\cdot \boldsymbol{n})(\boldsymbol{u}\cdot  \boldsymbol{n})- p \\
    \boldsymbol{F_t} &= \nu \nabla_n \boldsymbol{u} \times \boldsymbol{n} + \chi (\boldsymbol{u}\cdot \boldsymbol{n})(\boldsymbol{u}\times \boldsymbol{n})
    \end{aligned}

with :math:`\nu` the viscosity, and :math:`\chi\in \{0,1\}`. In 2D, we use the tangential vector :math:`\boldsymbol{t} = (-n_y, n_x)` instead of the cross product :math:`\times \boldsymbol{n}` to replace the tangential plan with one tangential vector. 

Then, let's define the Robin parameters :math:`\alpha` for the normal part and :math:`\beta` for the tangential part and the Robin data:
    - a normal data :math:`g_N` which is scalar,
    - a tangential data :math:`\boldsymbol{g_T}` which is scalar is 2D and vectorial in 3D. 

The Robin boundary conditions which have been implemented in TRUST are: 

.. math:: 

    \begin{aligned}
    \alpha F_n + \boldsymbol{u}\cdot \boldsymbol{n} &= g_N\\
    \beta \boldsymbol{F_t}  + \boldsymbol{u}\times \boldsymbol{n} &=\boldsymbol{g_T}
    \end{aligned}

In TRUST, we use the keyword Robin\_VEF for the Robin boundary condition, with the following parameters: 

    - alpha, beta, defined bellow. 
    - the keyword champ\_front\_normal\_et\_tangentiel followed by the field data associated (consider that the followed field is a concatenation with :math:`g_N` and :math:`\boldsymbol{n}\times \boldsymbol{g_T}` ) 

There is a 2D example of a Navier-Stokes problem for :math:`\boldsymbol{u}=(y,-x)`, :math:`p=0.5(x^2+y^2)-1/3`, and :math:`\boldsymbol{n}=(1,0)`.
::
    Robin_VEF {
            alpha 3
            beta 4
            champ_front_normal_et_tangentiel_robin champ_front_fonc_txyz 2 -1.5*x^2-4.5*y^2+y+1.0 4*x*y-x-4         
    }

In 3D, the field champ\_front\_normal\_et\_tangentiel will have 4 components (one for :math:`g_N` and three for :math:`\boldsymbol{n}\times\boldsymbol{g_T}`). 

Note that we use :math:`\boldsymbol{n}\times\boldsymbol{g_T}` because we want to write the real tangential component of :math:`\boldsymbol{u}`. 