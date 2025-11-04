# Periodic channel flow 

This tutorial aims at computing numerical solution of a 3D incompressible laminar flow with periodic boundary conditions in the Z direction. The geometry is presented in {numref}`fig:periodicchannel`.

```{figure} FIGURES/periodic3D.png
:class: custom-image-class
:name: fig:periodicchannel
:alt: periodic3D

Geometry of the 3D periodic case
```

| **Fluid Properties** | **Value** |
|:---------------:|:---------------:|
| $Re$ | 2000|
| $\rho$ | $2 kg \cdot m^{-3}$|
| $\mu$ | $0.01 kg \cdot m^{-1} \cdot s^{-1}$|
| Initial velocity $V0$| $1m/s$|

As always when you use TRUST, start by loading your **TRUST** environment, [see](../index.rst).

The case we will play with in this tutorial is called `P1toP1Bulle` in the **TRUST** repository. It is a 2D simulation of helium gas flow from left to right between two heated walls. Start by copying it in your folder:
```
trust -copy P1toP1Bulle
```

Open the P1toP1Bulle.data file and use **RegroupeBord** keyword to merge Entree and Sortie boundaries into a single one named periox.

Then, modify the boundary conditions to apply a periodic boundary on the wanted boundaries.

Afterwards, change the velocity initial condition to $U_0=(1,0,0)$.

To make the calculation faster, set the option **diffusion\_implicite** to 1 into the Euler scheme in order implicit the diffusive term in the Navier-Stokes equations.

Change your **nb\_pas\_dt\_max** to 30, close your `.data` file and run the calculation.

Edit the `P1toP1Bulle_pb_Debit.out` file and check the flow rate on the periox boundary.

Open the `.data` file and add the **Canal\_perio** source term in the Navier-Stokes equations.

Run again the calculation to check the flow rate evolution on 30 time steps. Look also at pressure and viscous forces applied on the cylinder inside the `.out` files.

Now, the calculation domain is a rotating channel according to Z direction with a constant velocity $\Omega=1 rad/s$.

Add the **Acceleration** source term in the Navier-Stokes equations. Suppress the **nb\_pas\_dt\_max** keyword and set **tmax** to 100s.

If you wish to practice, add velocity or statistic calculation to the post-processing instructions.

Run the calculation.

Afterwards, create a uniformly refined mesh using, for instance, the keyword **Raffiner\_Anisotrope**.

Then, in order to improve the calculation speed on this mesh, use a coarse discretization **P1** (**Read dis { P1 }**) which embarks less pressure unknowns. 
The calculation, should be around three times faster than with the **P1Bulle** discretization but it is less accurate: 8452 unknowns compared to 49221 unknowns.

Try another discretisation: **VEFPreP1B** and re-run the computation by reading the velocity field with **Champ\_fonc\_reprise** keyword in the initial conditions for the velocity:
    **vitesse champ\_fonc\_reprise P1toP1Bulle\_pb.xyz pb vitesse last\_time**

You can also use an implicit scheme to fasten the computation: change the scheme to **Scheme\_Euler\_implicit** scheme and use an **Implicite** solver. This only works if you are looking for the stationary state.
