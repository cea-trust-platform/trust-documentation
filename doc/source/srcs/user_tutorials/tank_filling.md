# Tank filling 


cl
& **Fluid**: Colored water
& diffusion $D=10^{-9}m^{2}.s^{-1}$,
& $\rho=1000kg.m^{-3}$, $\mu=10^{-3}kg.m^{-1}.s^{-1}$

&

& **Boundary conditions**:

& *Inlet*: Velocity: $(V_{x},V_{y})=(V(t),0)$
& with $V(t)=
    \begin{cases}
    1-(y-0.025/0.005)^{2} & ,\; t\leq0.5s\\
    0 & ,\; t>0.5s
    \end{cases}$

& Concentration: $C=
    \begin{cases}
    1 & ,\; t\leq0.5s\\
    0 & ,\; t>0.5s
    \end{cases}$
& *Outlet*: Pressure $P=0$
& *Wall*: Velocity $V_{x}=0$, $V_{y}=0$

&

& **Initial conditions**: Concentration $C_0=0$,
& Velocity $V=0$

-   Load TRUST environment as described on page

-   Copy the study named **diagonale**. This test case deals with a 2D flow with Navier-Stokes and the equation for one constituent.

-   Edit the data file and modify the fluid characteristics to the previous ones ($\mu, \rho, D$).

-   We want to modify the geometry of this problem to the previous picture. So we want to create 3 blocks like:

```{figure} FIGURES/tank2D.png
:class: custom-image-class
:alt: tank2D

Geometry of the 2D tank case
```

-   Create the corresponding mesh with 3 blocks (start with $dx=dy=0.2cm$ which gives a total nodes number $Nx=51$ and $Ny=121$).

    -   Create a first block `Block1` whose origin is (0, 0.03), $Nx=51$, $Ny=106$ (for $dx=dy=0.2cm$), $L=0.1 m$, $H=0.21 m$. Name the wall boundaries Left1, Outlet(=Top1) and Right1. (Don't forget the comma between blocks definitions.)

    -   Create the second block `Block2` whose origin is (0, 0.02), $Nx=51$, $Ny=6$ (for $dx=dy=0.2cm$), $L=0.1 m$, $H=0.01 m$. Name the wall boundaries Inlet(=Left2) and Right2.

    -   Create the third block `Block3` whose origin is (0, 0), $Nx=51$, $Ny=11$ (for $dx=dy=0.2cm$), $L=0.1 m$, $H=0.02 m$. Name the wall boundaries Left3, Bottom3 and Right3.

-   Define the boundary wall, using the keyword **"RegroupeBord`**.

-   You could also use facteurs and symx, symy keywords to define a refined mesh near the walls.


-   In the data file, change the values in the time scheme to stop the calculation at 1
    second, and modify **dt\_min** and **dt\_max** values to let TRUST compute time step.

-   Change values for the gravity to $-9.81 m.s^{-2}$ following y-axis.

-   Note that the **beta\_co** keyword may be useful in order to have a Boussinesq coupling between momentum and concentration equations ($\beta C_0 g(C-C_0$) source term added to the Navier-Stokes equations).

-   Change the initial and boundary conditions for Navier-Stokes equations:

    -   for the Outlet boundary, you have to impose $P=0$,

    -   for the Wall boundary, you have to impose $V_x=V_y=0$ with **"paroi\_fixe`** keyword.,

    -   for the Inlet boundary, you have to impose $(V_{x},V_{y})=(V(t),0)$ with
        $V(t)=
            \begin{cases}
            1-(y-0.025/0.005)^{2} & ,\; t\leq0.5s\\
            0 & ,\; t>0.5s
            \end{cases}$. You will use the **Champ\_Front\_Fonc\_txyz** keyword for the velocity, to write something like:
        **Champ\_Front\_Fonc\_txyz $2$ $(1-((y-0.025)/0.005)^2)*(t<0.5)$ $0.$**
        Note: Use ($t[0.5)$ syntax if you prefer ($t<=0.5$)


-   Change the initial and boundary conditions for the constituent equation.

    -   You will also use **Champ\_Front\_Fonc\_txyz** field for the Inlet boundary condition for concentration.

    -   For the Outlet, use the following keywords to insure the external concentration is 0:
        **Frontiere\_ouverte C\_ext Champ\_front\_uniforme 1 0.**

    -   For the Wall, the keyword for impermeable boundary condition for concentration is **paroi**.

-   Check you have high-order schemes (i.e. **"Quick`** scheme) used in both equations to reduce numerical diffusion.

-   Notice you could have suppressed diffusion term in concentration equation rather than using a small diffusion coefficient with:
    **Diffusion { negligeable }**

-   Add a concentration probe near the inlet (e.g.: at (0,0.025)).

-   Add a velocity segment probe (with 5 points between (0,0.021) and (0,0.029)) at the inlet boundary to see the time evolution of these two quantities (period 0.01s).

-   Run the study and follow the time evolution with the probes:
    **trust -evol diagonale &**
    `Start computation!` button and `Plot` or `Plot on same` for probes.

-   Check the flow rate in inlet boundary in the diagonale\_pb\_Debit.out file (plotted on the right of the `evol` window). You should find a value near $6.8 \; 10^{-3} m^2.s^{-1}$.

-   Use VisIt to post-process the results at t=0.2, t=0.4s and t=0.7s. VisIt has some interesting feature for this study. It can give concentration histogram to check the numerical diffusion in the concentration equation: Add $\rightarrow$ Histogram $\rightarrow$ CONCENTRATION\_ELEM\_dom.
    The volume of colored water (in $m^3$) is given by $Vol(t)= 6.66.10^{-3} t$ before $t=0.5s$ and $Vol(t)=3.33.10^{-3}$ after.

-   Copy diagonale.data to diagonale\_VEF.data.

-   Triangulate your mesh (**trianguler** keyword).

-   In this new file, change the discretization (**VEFPreP1B** instead of **VDF**).

-   Use **muscl** instead of **quick** scheme.

-   And you can switch **GCP** solver by **Cholesky** solver of the Petsc library (direct method which may need large amount of RAM memory) to increase the speed resolution of the pressure linear system:
    **GCP { precond ssor { omega 1.5 } seuil 1.e-6 } $\rightarrow$ Petsc Cholesky { }**

-   Run the calculation. You must have an error, and TRUST stop the calculation.

-   As TRUST indicates, to avoid this problem, you can:

    -   change the **trianguler** keyword to **trianguler\_h**,

    -   or use the **VerifierCoin** keyword. For this, after this first error you must find a `diagonale\_VEF.decoupage\_som` file in your directory, so you can use it by adding:
        **VerifierCoin dom { read\_file diagonale\_VEF.decoupage\_som }**
        just after `trianguler dom`. This will subdivides inconsistent 2D/3D cells used with VEFPreP1B discretization (cf Reference Manual).

-   Run the calculation and compare the results between **VDF/quick** and **VEFPreP1B/muscl** which must take much more time!