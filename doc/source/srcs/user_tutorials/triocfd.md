# Constituents and turbulent flow, with TrioCFD

```{figure} FIGURES/marche.png
:class: custom-image-class
:alt: marche

Geometry of the downward march case
```

**Fluid:** $\mu=3.7 \, 10^{-5} kg.m^{-1}.s^{-1}, \rho=2 \, kg.m^{-3}, Re=\frac{U_0 H_{inlet} \rho}{\mu} =54054$

**Boundary conditions:**
Inlet with imposed velocity: $U_0=1 m.s^{-1}$ and constant values of $k=10^{-2}$ and $\varepsilon=10^{-3}$ (dimensionless values)\
Outlet with constant pressure: $P_0=0$ and constant values of $k=0$ and $\varepsilon=0$\
Top and bottom walls: No-slip wall ($U=0$) and $k$ standard flux, $\varepsilon$ null.

-   Initialize TrioCFD full environment to get access to TRUST&TrioCFD tests.\

    -   On CEA Saclay computers:
        **source /home/trust\_trio-public/[full]{style="color: red"}\_env\_[TrioCFD]{style="color: blue"}-1.9.5.sh**

    -   On your own computer:
        If you don't already have TrioCFD, go {here}`https://github.com/cea-trust-platform/TrioCFD-code` to install it. Then: **source PathToTrioCFD/[full]{style="color: red"}\_env\_[TrioCFD]{style="color: blue"}.sh**

    **echo \$exec**
    **echo \$project\_directory**

-   Copy the study named **Marche** ([TrioCFD]{style="color: blue"}) using: **triocfd -copy Marche**
    in the directory Formation\_TRUST/yourname. It is also possible to use **"trust`** script since both commands have the same options and use the same \$exec executable. This test case simulates a 2D incompressible turbulent flow in the above configuration using the k-$\varepsilon$ model.

-   We will add a source of constituent's diffusion, so copy the **Constituants** (2D incompressible laminar flow) study which uses constituents.

-   Edit your data file in the Marche directory. First, rename the problem in order to add concentration equations (look for the adequate keywords in the TrioCFD Reference Manual).\
    **triocfd -index** then click on **Reference manual**

-   Add 3 constituents of equal diffusivities ($\alpha=1m/s$) after the fluid definition (in the problem block).

-   Define the concentration equation into the problem (remember that concentrations will be a vector of 3 components) with correct initial ($C_1=0, C_2=0, C_3=0$) and boundary conditions.

-   Use the Schmidt model to close the turbulence model in the concentration equation.

-   Change the sources of the Navier-Stokes turbulence model to a **Source\_Transport\_K\_Eps\_aniso\_concen { C1\_eps 1.44 C2\_eps 1.92 C3\_eps 1. }** to fit with the new concentration equation.

-   Add into the fluid definition, the volume expansion coefficient for the concentration: **beta\_co** as a uniform field set to 0.

-   You have also to add a gravity field which can be initialized to 0.

-   Run the calculation to see if it is ok.

-   Define a sub domain (in grey on the previous picture) with the keyword **Sous\_Zone** (like in **PCR** data file ([TRUST]{style="color: blue"}) ).

-   Add a source term for the second constituent only ($S_2=1m^{-3}$) applied on the sub domain thanks to the keyword **Champ\_Uniforme\_Morceaux**.

-   Add **format lata** in the post-processing block.

-   Add the keyword **concentration0, concentration1, concentration2** in the **fields** of the post-processing block to write the 3 concentrations into the .lata file.

-   Run the calculation and check the results.