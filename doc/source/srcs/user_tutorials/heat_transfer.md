# Heat transfer

This tutorial will help you play with an Heat transfer between liquid and solid case.

```{figure} FIGURES/heat_exchange.png
:class: custom-image-class
:alt: heat_transfer

Geometry of the heat transfer case
```

As always when you use TRUST, start by loading your **TRUST** environment, [see](../index.rst).

The case we will play with in this tutorial is called `docond` in the **TRUST** repository. Start by copying it in your folder:

```
trust -copy docond
mv docond Coupling_VDF
cd Coupling_VDF
```
Then edit the `.data` file and check the fluid and solid characteristics.

This coupled problem is constituted by 2 domains of calculation. Those two domains span a mesh of 10x10 cells, with $\Delta x = \Delta y = 0.1m$.

Now open your data file with `evol` tool:
```
trust -evol docond &
```

Click on `Edit data` and modify the data file to have the 2 domains on a mesh of 40x40 cells ($\Delta x= \Delta y=0.025m$).
Change the number of nodes for each block like this:
- First block (Cavite1): 4 11 $\rightarrow$ 13 41
- Second block (Cavite2): 8 4 $\rightarrow$ 29 13
- Third block (Cavite3): 8 8 $\rightarrow$ 29 29

When you are at it, change **format lml** to **format lata** into the **two** problems definition

Click on `Save` and close the window. You could have done the same by directly editing the `docond.data` file

Run the calculation with `Start computation!` and check the evolution.

Then post-process the temperature field with **VisIt** tool: `Visualization` button. A natural convection cell appears.

Change the color tables for the temperature to have the same one on the 2 domains. Close **VisIt**.

We are going to change the discretization of the test case from VDF to VEF. However, the VEF discretisation only works on tetrahedron, you therfore need first to triangulate the domains with the keyword **Trianguler\_H** in your `.data` file (see the [Reference Manual](../../reference/index.rst)).

Then, give an unstructured aspect to the 2 meshes using the following syntax in you `.data` file:
```
Transformer name_of_domain x*(1-0.5*y*y) y*(1+0.1*x*y)
```

Substitute the keyword VDF to VEFPreP1B.

Close the `evol` tool and run the calculation with:
```
trust docond
```

Now, open again the `evol` tool:
```
trust -evol docond
```

Select $Ri=\max_{pb1}(|dT/dt|)$, $Ri=\max_{pb2} (|dT/dt|)$, $Ri=\max_{pb2}(|dV/dt|)$, $residu=max|Ri|$ with `Ctrl` button and click on `Plot on same`.

To see when convergence is reached, select a probe, for example temperature, and click on `Plot`.

If the calculation is too long, open the `docond.stop` file, put a 1 instead the 0 and save. The calculation will stop after the current time step and make post-process.

Post-process the results and compare the CPU performances with the VDF discretization by checking the `docond.TU`. Computation in VEF $\approx$ 10 times slower in this case. 

Check `the docond.out` file to see the time steps for each equation: click on `Edit .out` at the upper right corner of the GUI.

In order to accelerate the calculation, by implicit the diffusive term of each equation with the  **diffusion\_implicite** options in the explicit Euler scheme, check the [User Guide](../../user_guide/index.rst) for help.

Run again the calculation without any option:
```
trust docond
```

Eventually, use a fully implicit scheme by suppressing **diffusion\_implicite**), then substituting **Scheme\_Euler\_Explicit** by **Scheme\_Euler\_implicit** and adding the Implicit solver `**solveur implicite**".

Have a look at the [Reference Manual](../../reference/index.rst) for the **gmres** options and define, according to the advice given on it, a value for **facsec** and **facsec\_max**.

Your block should look like:

**Solveur Implicite**
**{ solveur gmres { diag seuil 1e-30 nb\_it\_max 5 impr } seuil\_convergence\_implicite 0.01 }**

Run again the calculation:

```
trust -evol docond
```
