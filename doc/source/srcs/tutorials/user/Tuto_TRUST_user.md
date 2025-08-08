**Flow around an obstacle (2D, VDF, TRUST)** {#exo1}
============================================

Sequential calculation
----------------------

Geometry
--------

![Obstacle](PICTURES/3761176629c15accbcbecc5b002c7d121e748488.pdf){width="100%"}

-   Fluid: $\mu=3.7 \, 10^{-5} kg.m^{-1}.s^{-1}$, $\rho=2 kg.m^{-3}$ and $Re=\frac{U_0 H_{inlet} \rho}{\mu} = \frac{1 \times 0.22 \times 2}{3.7 \;10^{-5}} = 11 891$

-   Boundary conditions:

    -   Inlet with uniform velocity: $U_0=1 m.s^{-1}$

    -   Outlet with constant pressure: $P_0=0$

    -   Square cylinder: No-slip wall

    -   Upper and Lower walls: Symmetry

Create a study
--------------

-   First, load TRUST environment.

-   Open a terminal and create a directory for this tutorial:
    **mkdir -p Formation\_TRUST/yourname**
    **cd Formation\_TRUST/yourname**

-   [\[method\_copy\]]{#method_copy label="method_copy"} Copy a test case from TRUST's database with:
    **trust -copy Obstacle**
    **cd Obstacle**

-   Ask for trust script options:
    **trust -help**

-   Ask for help on the options of TRUST's executable:
    **trust Obstacle -help\_trust**

-   Run the test case with:
    **trust Obstacle**

Probes and parameters
---------------------

-   Edit the data file Obstacle.data and set the time step to 0.004s:
    **gedit Obstacle.data &**

-   Replace the keyword `**format lml**" with `**format lata**" inside the post-processing block in order to use VisIt post-processing tool during and/or at the end of calculation.

Visualization during the calculation
------------------------------------

-   Launch the `trust -evol` tool with:
    **trust -evol Obstacle &**
    This tool allows to launch calculation and visualize results

-   To run the calculation, click on the button `Start computation!`.

-   Visualization:

    -   Select `PRESSION(X=0.13,Y=0.105)` in the left list and click on `Plot` to draw the evolution of the pressure at the probe location.

    -   Check the velocity profile behind the square cylinder by plotting `VITESSE_X(X=0.14,Y=0.115)` and `VITESSE_Y(X=0.14,Y=0.115)`.

    -   Visualize the equation residuals on the same plot, select `$Ri = max \left| \frac{dV}{dt} \right|$` and `$residu = max \left| Ri \right|$` using the button `Plot on same` or select the two graphs with `Ctrl` button then `plot`.

VisIt
-----

-   To quit this tool, close the GUI.

-   Once the calculation is finished, visualize the results with VisIt: **visit &**
    or using `trust -evol` tool: **trust -evol Obstacle &** and click on `Visualisation` on the right menu.

    -   First, we are going to configure VisIt: In the menu File $\rightarrow$ Open file, select Off instead of Smart for File grouping option. For the Filter, specify \*.lata to list only the lata files (results). Then save your choices, in the menu Options $\rightarrow$ Save Settings.

    -   In the menu File $\rightarrow$ Open file, select the Obstacle.lata file.

    -   Visualize the mesh in the `Plots` area with `Add $\rightarrow$ Mesh $\rightarrow$ dom` then click on the button `Draw`. Zoom and move the mesh in the right window. You can un-zoom with right button (View $\rightarrow$ Reset view) or with a combination of `Ctrl` keypad and left button.

    -   Visualize the pressure field (Plots area: `Add $\rightarrow$ Pseudocolor $\rightarrow$ PRESSION\_SOM\_dom` + Draw then select the last time on the Time slider)

    -   Suppress or hide the mesh (Select Mesh then click on Delete or Hide/Show).

$\color{Blue}\circ$ Visualize the velocity field (Plots area: `Add $\rightarrow$ Vector $\rightarrow$ VITESSE\_SOM\_dom`\
+ Draw). You can change each plot attributes:
$\color{Blue}\diamond$ click once onto the small arrow `$\blacktriangleright$` then \
$\color{Blue}\diamond$ double click on the item Vector (cf the figure below). For example, change\
the number of vectors being plotted (by default 400, set it to 40000\
then click the button `Make default` and save definitively this modification with\
the menu Options $\rightarrow$ Save Settings). You need to click `Apply` to update. Then\
click `Dismiss` to close the window.\

![image](PICTURES/56056acaa30f48bc880d209bf3dc9154a8a5902d.jpg){width="45%"}

$\color{Blue}\circ$ Print your visualization (File $\rightarrow$ Save window): a PNG file is created into your\
working directory.

$\color{Blue}\circ$ Add a second screen with `Windows $\rightarrow$ Layouts $\rightarrow$ 1x2`,\
$\color{Blue}\circ$ Plot a pressure horizontal profile:
$\color{Blue}\diamond$ select the pressure field,\
$\color{Blue}\diamond$ on the visualisation, use the right click and select `Mode $\rightarrow$ Line out`,\
$\color{Blue}\diamond$ then define your profile with left button,\
$\color{Blue}\diamond$ click on the origin point, let the left button pushed, and release at the end point.\
$\color{Blue}\diamond$ The profile is shown on the second window.\
$\color{Blue}\circ$ You notice that it is necessary to update (button Draw) the right window after\
adding a new plot or changing an option. It is possible to automatically\
update by activating `Auto apply` on the top right of the VisIt's GUI.\
$\color{Blue}\circ$ You can create create new fields (expression) with `Controls $\rightarrow$ Expressions\
$\rightarrow$ New` by using existing variables and complex functions and visualize it.\
$\color{Blue}\circ$ You can animate your visualization and/or create a movie (File $\rightarrow$ Save movie)\
$\color{Blue}\circ$ You can operate calculations on variables with complex queries\
(Controls $\rightarrow$ Query),\
$\color{Blue}\circ$ You can save a complex session (File $\rightarrow$ Save session) and reopen it during a\
next analyze with VisIt (File $\rightarrow$ Restore session),

Outputs and resuming calculation
--------------------------------

$\color{Blue}\circ$ During a 3D visualization, you will use one of the available Operators\
(In Plots, `Operators $\rightarrow$ Slicing $\rightarrow$ Slice`) to create a 2D slice either in a 3D\
space, or projected to a 2D space.

-   For more information on **VisIt**, you can refer to:

    -   the **VisIt** website and its manuals: [https://wci.llnl.gov/simulation/computer-codes/visit/manuals]{style="color: blue"}

    -   the **VisIt** user community web site: [http://visitusers.org]{style="color: blue"}

    -   or send an email to the VisIt software users community at: [visit-users\@elist.ornl.gov]{style="color: blue"}

-   Edit the different output (\*.out) files to read the complete balances (mass, stress, energy, \...) on the whole domain or at the boundaries.

-   Now we want to edit the data file in order to resume the calculation. So, open it using `evol` tool: **trust -evol Obstacle &**.

-   Find the last backup time of the previous calculation in the .err file (or in the bottom right file in the `evol` tool if it is still running).

-   [\[save\_restart\]]{#save_restart label="save_restart"} Edit your data file with `Edit data`, then modify **tinit**, **tmax** values in the object `mon\_schema`.

-   Add in the problem description block just before the last `}`:
    **reprise binaire Obstacle\_pb.sauv**
    (The file `Obstacle\_pb.sauv` must have been created during the first run.)

-   Save and close the window.

-   Resume the calculation again with `Start calculation!` button. You can see that values are added to the first probes during the new calculation.

-   *Remark:* to resume your calculation, you can also use the keyword **resume\_last\_time** instead of **reprise** and only change the **tmax** value (cf Reference Manual).

Probes and fields
-----------------

-   Edit the data file Obstacle.data:
    **gedit Obstacle.data &**

-   Add to the post-processing block of Obstacle.data the following elements:

    -   A pressure probes segment (22 probes between points (0.01, 0.12) and (0.91, 0.12)).

    -   A velocity probes segment (22 probes between points (0.92, 0.00) and (0.92, 0.22)) to plot the velocity profile behind the square cylinder.

    -   Change fields post-processing period from 1s to 0.5s.

    -   Add the vorticity to the fields to the list of post-processed fields. To find the appropriate keyword, have a look to the Generic Guide:
        **trust -doc &**

    -   You have access to useful resources in the TRUST index. Take few minutes to find test cases containing a particular keyword using the [Keywords]{.underline} link:
        **trust -index &**

Parallel calculation
--------------------

The goal of this exercise is to introduce parallelism in the data file of the previous exercise.

-   Go to the previous study (should be done) and after you had suppressed the **reprise** keyword and set **tinit** to 0 again in the *Obstacle.data* file, create two new files:
    **cd Formation\_TRUST/yourname/Obstacle**
    **mkdir PARA1**
    **cd PARA1**
    **cp ../Obstacle.data DEC\_Obstacle.data**
    **cp ../Obstacle.data PAR\_Obstacle.data**
    **cp ../Obstacle.geo .**

-   Edit the first file (*DEC\_Obstacle.data*) to create the partition of the mesh.

-   In this file, uncomment the block around the **Partition** keyword.

    -   Here, the partitioning tool **Metis** is used. We cut in **nb\_parts** blocks, here in 2.

    -   The overlapping width **Larg\_joint** between two parts of the partition should be defined according to the numerical scheme higher order, generally the convective scheme. Its value is generally 1 for a second-order scheme, and 2 for third- or fourth-order schemes such as Quick scheme.

    -   In VEF, you should use **2** for **Larg\_joint** except when partitioning a domain where only the conduction equation will be solved.

    -   At least, the keyword **zones\_name** is useful to define the name of the files containing the partitioned mesh and to write these files.

    -   Notice the presence of the keyword **End** in the `Partition` block: the code will stop reading the data file at this line!

-   Run the data file: **trust DEC\_Obstacle**

-   Check that the partitioned mesh files DOM\_0000.Zones and DOM\_0001.Zones are generated inside your working directory: **ls \*.Zones**

-   Now, edit the file PAR\_Obstacle.data and comment the read of the mesh
    (using \# tags of the 'BEGIN/END MESH' comments).

-   Uncomment the **Scatter** keyword which will read the partitioned mesh.

-   Now, run a parallel calculation with TRUST:
    **trust PAR\_Obstacle 2**

-   Post-processing step is identical in sequential or parallel modes. Probes are written into .son files and fields into .lata files. Run VisIt with:
    **visit -o PAR\_Obstacle.lata &**

-   Select the last time step and visualize the blocks (with Plots: Add $\rightarrow$ Subset $\rightarrow$ blocks)
    which represent the parts of the domain partition, then the velocity fields. You can
    also visualize a field only on a selected part (block) with the menu Control $\rightarrow$ Subset.

-   Visualize probes at the end of the calculation using:
    **trust -evol PAR\_Obstacle &**

Parallel calculation on a cluster
---------------------------------

NB: On CEA Clusters, TRUST is already installed and the procedure of launching calculation is described below. Out of CEA, your cluster administrator should install and configure TRUST. In addition, submission files and procedure depend on the cluster itself and could be different from those presented below.

-   Login to the CEA cluster `orcus` and initialize the TRUST environment:
    **ssh -X yourlogin\@orcusloginint1(.intra.cea.fr)** or\
    **ssh -X yourlogin\@orcusloginamd1(.intra.cea.fr)**
    **source /home/trust\_trio-public/env\_TRUST-1.9.5.sh**

-   Copy the study Obstacle:
    **cd \$SCRATCH**
    **mkdir -p Formation\_TRUST/yourname**
    **cd Formation\_TRUST/yourname**
    **trust -copy Obstacle**
    **cd Obstacle**

-   Open Obstacle.data and set the **format** to **lata** in the post-processing block.

-   Partition mesh and create a parallel data file with:
    **trust -partition Obstacle**

-   For clusters, you have to create a submission file:
    **trust -create\_sub\_file PAR\_Obstacle 2**

-   Open the file sub\_file and rename the job. Note that we will see only the first eight characters of the job name in the submitted jobs list.

-   Submit the job with:
    **sbatch sub\_file**

-   Check job status with: **"squeue`** or **"squeue -u yourlogin`**

-   To vizualize your results, use TurboVNC as described on Users training presentation.

Heat transfer (2D, VDF/VEF)
===========================

![Heat exchange](PICTURES/f0307d4a85578e7d1d1994e8bbdab457d07e8fee.pdf){width="1.\\textwidth"}

-   Load TRUST environment as described on page

-   Create a new study Coupling\_VDF by copying the docond study:
    **cd Formation\_TRUST/yourname**
    **trust -copy docond**
    **mv docond Coupling\_VDF**
    **cd Coupling\_VDF**

-   Check the fluid and solid characteristics inside the docond.data file.

-   This coupled problem is constituted by 2 domains of calculation with a mesh of 10x10 cells ($\Delta x = \Delta y = 0.1m$).

-   Now open your data file with `evol` tool:
    **trust -evol docond &**

-   Click on `Edit data`.

-   We want to modify the data file to have the 2 domains on a mesh of 40x40 cells ($\Delta x= \Delta y=0.025m$).

-   Change the number of nodes for each block like this:
    First block (Cavite1): 4 11 $\rightarrow$ 13 41\
    Second block (Cavite2): 8 4 $\rightarrow$ 29 13\
    Third block (Cavite3): 8 8 $\rightarrow$ 29 29\

-   Change **"format lml`** to **"format lata`** into the two problems definition

-   Click on `Save` and close the window.

-   Run the calculation with `Start computation!` and check the evolution.

-   Then post-process the temperature field with VisIt tool: `Visualization` button. A natural convection cell appears.

-   Change the color tables for the temperature to have the same one on the 2 domains. Close VisIt.

-   We are going to change the discretization of the test case: triangulate the domains with the keyword **Trianguler\_H** (refer to the Reference Manual).

-   Then give an unstructured aspect to the 2 meshes using the following syntax:
    **Transformer name\_of\_domain x\*(1-0.5\*y\*y) y\*(1+0.1\*x\*y)**

-   Substitute the discretization VDF (pressure nodes at the element center) to VEFPreP1B (pressure nodes at the element's center and nodes).

-   Close the `evol` tool.

-   Run the calculation with:
    **trust docond**

-   Open the `evol` tool:
    **trust -evol docond**

-   Select 'Ri=max\_pb1$|dT/dt|$', 'Ri=max\_pb2$|dT/dt|$', 'Ri=max\_pb2$|dV/dt|$', 'residu=max$|Ri|$' with `Ctrl` button and click on 'Plot on same'.

-   To see when convergence is reached, select a probe (for example temperature) and click on 'Plot'.

-   If the calculation is too long, open the docond.stop file, put a 1 instead the 0 and save.
    The calculation will stop after the current time step and make post-process.

-   Post-process the results and compare the CPU performances with VDF discretization: the VEF calculation is running $\approx$ 10 times slower (because more pressure unknowns and shorter time steps). Check the docond.out file to see the time steps for each equation (click on `Edit .out` at the upper right corner of the GUI).

-   Accelerate the calculation by impliciting the diffusive term of each equation with **diffusion\_implicite** option in the explicit Euler scheme (check again the Generic Guide: **trust -doc &**).

-   Run the calculation without any option:
    **trust docond**

-   [\[schema\_impl\]]{#schema_impl label="schema_impl"} Now, use a fully implicit scheme (suppress **diffusion\_implicite**), by substituting **Scheme\_Euler\_Explicit** by **Scheme\_Euler\_implicit** and adding the Implicit solver `**solveur implicite**".

-   Have a look at the Reference Manual for the **gmres** options and define, according to the advice given on it, a value for **facsec, facsec\_max**.

-   Your block will look like:
    **Solveur Implicite { solveur gmres { diag seuil 1e-30 nb\_it\_max 5 impr } seuil\_convergence\_implicite 0.01 }**

-   Run the calculation:
    **trust -evol docond &**

Quasi Compressible flow (2D)
============================

-   Open a terminal and Load TRUST environment as described on page

-   Copy the study **TP\_Temp\_QC\_VEF** (it is a 2D simulation of helium gas flow from left to right between two heated walls) as follows:
    **mkdir -p Formation\_TRUST/yourname**
    **cd Formation\_TRUST/yourname**
    **trust -copy TP\_Temp\_QC\_VEF**
    **cd TP\_Temp\_QC\_VEF**

-   Open the Generic Guide with (it will be useful to search for keywords in this exercise): **trust -doc &**

-   Edit the data file with your favorite editor (**gedit** is recommended because it is configured to recognize the TRUST syntax):
    **gedit TP\_Temp\_QC\_VEF.data &**
    or\
    **trust -evol TP\_Temp\_QC\_VEF &** and `Edit data` button.

-   Edit the data file in order to:

    -   Modify the geometry and the mesh:

        ![image](PICTURES/dad56f1935c9851e4adf7345227a15f0bd6f00e9.pdf){width="50%"}

    -   Add several probes (velocity, density, temperature) near the upper right corner of the geometry at location (x,y)=(4,1).

    -   Add a probe **"segment`** (with 9 points) between the locations (x,y)=(4,0.05) and (x,y)=(4,0.95) for the temperature field.

    -   Write the results on the **lata** format and change the **dt\_post** period to 1s.

    -   We are looking for the steady state, so suppress tmax keyword and change the **seuil\_statio** $\varepsilon$ value to 10 ($|dT/dt|<\varepsilon$ and $dt \sim 0.001s$ so $|dT|<0.01$).

    -   Add the keyword **impr** into the pressure solver to print its convergence.

    -   If you use `evol` tool, save and close the editor.

-   Run the simulation with the TRUST command:
    **trust -evol TP\_Temp\_QC\_VEF &**

-   Click on `Start computation!`.

-   Check mass flow rate (absolute and relative values) in the TP\_Temp\_QC\_VEF.out file:
    **gedit TP\_Temp\_QC\_VEF.out &**
    or look at the upper small window on the right of the `evol` tool.

-   Once the calculation finishes, visualize the results by running **VisIt**:
    **visit -o TP\_Temp\_QC\_VEF.lata &**
    or\
    `Visualization` button on `evol` tool.

    -   Show the mesh (Plots: `Add $\rightarrow$ Mesh $\rightarrow$ dom $\rightarrow$ Draw`).

    -   Visualize the temperature field (Select the last Time with the slicer, then Plots: `Add $\rightarrow$ Pseudo Color $\rightarrow$ TEMPERATURE\_SOM\_dom $\rightarrow$ Draw`).

    -   Suppress or hide the mesh (Select `Mesh-dom` in the list of plots then `Delete` or `Hide/Show`).

    -   Visualize the velocity field (Add $\rightarrow$ Vector $\rightarrow$ VITESSE\_SOM\_dom $\rightarrow$ Draw).

$\color{Blue}\circ$ Select the Zoom mode with the right button of the mouse (Mode $\rightarrow$ Zoom)\
then zoom by selecting an area on the plot. To un-zoom push `Ctrl` button\
and select an area with the left button or with the right button select\
`View $\rightarrow$ Reset view`.\
$\color{Blue}\circ$ Print your visualization (File $\rightarrow$ Set Save options $\rightarrow$ File type $\rightarrow$ Select a type\
$\rightarrow$ Save): a file named visit\*\*\* is created into your working directory.

$\color{Blue}\circ$ Add a second screen with `Window $\rightarrow$ Layout $\rightarrow$ 1x2`.

$\color{Blue}\circ$ Plot a horizontal profile of temperature (Select the temperature field and\
thanks to the right button, select `Mode $\rightarrow$ Lineout`, and define your\
profile with left button): the profile is shown on the second window.

-   Substitute the time scheme by an implicit time scheme (like **scheme\_euler\_implicit**).

-   Use the **implicite** solver and specify **facsec** and **facsec\_max** parameters according to the advice given on the Reference Manual (search for the **scheme\_euler\_implicit** keyword). You can also see the instructions at the end of the Heat transfer VDF/VEF exercise on p..

-   Run the calculation with this time scheme using the `evol` tool or:
    **trust TP\_Temp\_QC\_VEF.data 1$>$TP\_Temp\_QC\_VEF.out 2$>$TP\_Temp\_QC\_VEF.err**

-   Edit the file containing information about dt (used time step), dt\_stab (stability time step), **facsec** (dt=dt\_stab\*facsec) and residuals evolution for each equation:
    **gedit TP\_Temp\_QC\_VEF.dt\_ev &**

-   If everything is OK, try to enhance the convergence speed of the implicit solver with the value of **seuil\_convergence\_implicite** keyword (look at the TP\_Temp\_QC\_VEF.out file, if the number of iterations for GMRES is comprised between 3 and 5 then it is enough to converge quickly).

-   In order to resume a calculation, you will have to change the **tinit** value within the data file (pick up the last saved time in the **.err** file) and insert into the data file, in the problem definition block, the following keywords:
    **reprise binaire TP\_Temp\_QC\_VEF\_pb.sauv**

-   Then run the calculation with:
    **trust TP\_Temp\_QC\_VEF.data 1$>$TP\_Temp\_QC\_VEF.out 2$>$TP\_Temp\_QC\_VEF.err**
    or\
    **trust -evol TP\_Temp\_QC\_VEF.data &** which automatically creates the .out file

If you are interested in the comparison between Quasi Compressible and Weakly Compressible simulations, see the validation form:

\$TRUST\_ROOT/Validation/Rapports\_automatiques/Verification/\
Verification\_codage/QC\_vs\_WC

Periodic channel flow (3D)
==========================

![image](PICTURES/0dd796e3569a4798b18d598a29075deec1f22486.png){width="45%"}

**Fluid:** $Re=2000$, $\rho=2 kg.m^{-3}$, $\mu=0.01 kg.m^{-1}.s^{-1}$, initial velocity $V0=1m/s$, periodic boundary condition following the Z-direction.

-   Copy the study named **P1toP1Bulle** as explained on page . It simulates a 3D incompressible laminar flow ($Re=2000$) with periodic boundary following the Z-direction only.

-   Open the P1toP1Bulle.data file and use **RegroupeBord** keyword to merge Entree and Sortie boundaries into a single one named periox.

-   Modify boundary conditions to apply a periodic boundary on the new boundary.

-   Change the velocity initial condition to $U_0=(1,0,0)$.

-   Set the option **diffusion\_implicite** to 1 into the Euler scheme to implicit the diffusive term in the Navier-Stokes equations.

-   You have now a 3D calculation with periodic boundary conditions on X- and Z-directions. Run the calculation for 30 time-steps (keyword **nb\_pas\_dt\_max**).

-   Have a look at the P1toP1Bulle\_pb\_Debit.out file, check the flow rate on the periox boundary. Why does it decrease?

-   Add the **Canal\_perio** source term in the Navier-Stokes equations of the data file and run again the calculation to check the flow rate evolution on 30 time steps.

-   Look at pressure and viscous forces applied on the cylinder inside the .out files.

-   Now, the calculation domain is a rotating channel according to Z direction with a constant velocity $\Omega=1 rad/s$.

-   Add the **Acceleration** source term in the Navier-Stokes equations. Suppress the **nb\_pas\_dt\_max** keyword and set **tmax** to 100s.

-   Add, if you wish, velocity or statistic calculation to the post-processing instructions.

-   Run the calculation.

-   You can create a uniformly refined mesh using, for instance, the keyword **Raffiner\_Anisotrope**.

-   Then improve the calculation speed on this mesh, you can use a coarse discretization **P1** (**Read dis { P1 }**) with less pressure unknowns. On this latter, it runs 3 times faster than on P1Bulle discretization but it is less accurate: 8452 unknowns compared to 49221 unknowns.

-   Then restart the calculation with **VEFPreP1B** discretization by reading the velocity field with **Champ\_fonc\_reprise** keyword in the initial conditions for the velocity:
    **vitesse champ\_fonc\_reprise P1toP1Bulle\_pb.xyz pb vitesse last\_time**
    [This will be useful to reach the quasi-stationary regime faster.]{.underline}

-   You can also use implicit scheme (change the scheme to **Scheme\_Euler\_implicit** scheme and use an **Implicite** solver) [only if you are looking for the stationary state]{.underline}.\
    You can also see the instructions at the end of the Heat transfer VDF/VEF exercise on p. .

Constituents and turbulent flow
===============================

![image](PICTURES/9140ed60430408ef636af9421404568645f22ab4.pdf){width="75%"}

**Fluid:** $\mu=3.7 \, 10^{-5} kg.m^{-1}.s^{-1}, \rho=2 \, kg.m^{-3}, Re=\frac{U_0 H_{inlet} \rho}{\mu} =54054$

**Boundary conditions:**
Inlet with imposed velocity: $U_0=1 m.s^{-1}$ and constant values of $k=10^{-2}$ and $\varepsilon=10^{-3}$ (dimensionless values)\
Outlet with constant pressure: $P_0=0$ and constant values of $k=0$ and $\varepsilon=0$\
Top and bottom walls: No-slip wall ($U=0$) and $k$ standard flux, $\varepsilon$ null.

-   Initialize TrioCFD full environment to get access to TRUST&TrioCFD tests.\

    -   On CEA Saclay computers:
        **source /home/trust\_trio-public/[full]{style="color: red"}\_env\_[TrioCFD]{style="color: blue"}-1.9.5.sh**

    -   On your own computer:
        **source PathToTrioCFD/[full]{style="color: red"}\_env\_[TrioCFD]{style="color: blue"}.sh**

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

Tank filling (2D, single-phase flow, TRUST)
===========================================

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

![image](PICTURES/2748d2c7d45eb5afd4457c36befcbcf0ea96b46e.pdf){width="20%"}

-   Create the corresponding mesh with 3 blocks (start with $dx=dy=0.2cm$ which gives a total nodes number $Nx=51$ and $Ny=121$).

    -   Create a first block `Block1` whose origin is (0, 0.03), $Nx=51$, $Ny=106$ (for $dx=dy=0.2cm$), $L=0.1 m$, $H=0.21 m$. Name the wall boundaries Left1, Outlet(=Top1) and Right1. (Don't forget the comma between blocks definitions.)

    -   Create the second block `Block2` whose origin is (0, 0.02), $Nx=51$, $Ny=6$ (for $dx=dy=0.2cm$), $L=0.1 m$, $H=0.01 m$. Name the wall boundaries Inlet(=Left2) and Right2.

    -   Create the third block `Block3` whose origin is (0, 0), $Nx=51$, $Ny=11$ (for $dx=dy=0.2cm$), $L=0.1 m$, $H=0.02 m$. Name the wall boundaries Left3, Bottom3 and Right3.

-   Define the boundary wall, using the keyword **"RegroupeBord`**.

-   You could also use facteurs and symx, symy keywords to define a refined mesh near the walls.

```{=html}
<!-- -->
```
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

```{=html}
<!-- -->
```
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

```{=html}
<!-- -->
```
-   Run the study and follow the time evolution with the probes:
    **trust -evol diagonale &**
    `Start computation!` button and `Plot` or `Plot on same` for probes.

-   Check the flow rate in inlet boundary in the diagonale\_pb\_Debit.out file (plotted on the right of the `evol` window). You should find a value near $6.8 \; 10^{-3} m^2.s^{-1}$.

-   Use VisIt to post-process the results at t=0.2, t=0.4s and t=0.7s. VisIt has some interesting feature for this study. It can give concentration histogram to check the numerical diffusion in the concentration equation: Add $\rightarrow$ Histogram $\rightarrow$ CONCENTRATION\_ELEM\_dom.
    The volume of colored water (in $m^3$) is given by $Vol(t)= 6.66.10^{-3} t$ before $t=0.5s$ and $Vol(t)=3.33.10^{-3}$ after.

```{=html}
<!-- -->
```
-   Copy diagonale.data to diagonale\_VEF.data.

-   Triangulate your mesh (**trianguler** keyword).

-   In this new file, change the discretization (**VEFPreP1B** instead of **VDF**).

-   Use **muscl** instead of **quick** scheme.

-   And you can switch **GCP** solver by **Cholesky** solver of the Petsc library (direct method which may need large amount of RAM memory) to increase the speed resolution of the pressure linear system:
    **GCP { precond ssor { omega 1.5 } seuil 1.e-6 } $\rightarrow$ Petsc Cholesky { }**

-   Run the calculation. You must have an error, and TRUST stop the calculation.

```{=html}
<!-- -->
```
-   As TRUST indicates, to avoid this problem, you can:

    -   change the **trianguler** keyword to **trianguler\_h**,

    -   or use the **VerifierCoin** keyword. For this, after this first error you must find a `diagonale\_VEF.decoupage\_som` file in your directory, so you can use it by adding:
        **VerifierCoin dom { read\_file diagonale\_VEF.decoupage\_som }**
        just after `trianguler dom`. This will subdivides inconsistent 2D/3D cells used with VEFPreP1B discretization (cf Reference Manual).

-   Run the calculation and compare the results between **VDF/quick** and **VEFPreP1B/muscl** which must take much more time!

Validation form[\[exo\_validation\]]{#exo_validation label="exo_validation"}
============================================================================

The prefered route to build a validation form in TRUST and its baltiks is to build a Jupyter notebook.\

See an example of notebook in\
\$TRUST\_ROOT/Validation/Rapports\_automatiques/Verification/SampleFormJupyter/\
or run on terminal:
Run\_fiche -doc

-   First copy the validation form named Source\_canal\_perio:
    **mkdir -p Formation\_TRUST/yourname/validation**
    **cd Formation\_TRUST/yourname/validation**
    **VERIF=\$TRUST\_ROOT/Validation/Rapports\_automatiques/Verification**
    **cp -r \$VERIF/Verification\_codage/Source\_canal\_perio   .**
    **cd Source\_canal\_perio**
    \

-   Display Run\_fiche script options:
    **Run\_fiche -help**

-   Build the PDF report with:
    **Run\_fiche -export\_pdf**
    then, open the report with:
    **evince build/rapport.pdf**

-   Now, we are going to change the validation form (Examples are given in SampleFormJupyter Validation form):
    **Run\_fiche &**

    -   Add the mesh plot in the report. For this, at end of the notebook, add a new Markdown cell for a title:
        **#\#Additional information\
        \#\#\#Mesh visualization**

    -   Add a new code cell to plot mesh\
        fig=visit.Show(`./std.lata`, `Mesh`, `dom`, plotmesh=True,title=`Mesh`)\
        fig.plot()

-   Add the evolution of residuals in the report in log scale (see .dt\_ev file). For this, introduce a new Jupyter text cell and write:
    **#\# Residual plot**
    then, on another cell plot residual using:
    **Graph = plot.Graph(`Residual plot`)**
    **Graph.addResidu(`std.dt\_ev`,label=`Residu`)**
    **Graph.scale(yscale='log')**

$\color{Blue}\circ$ Visualize the pressure field at the last time: complete the section `Additional information` with a new cell `Visualizing fields`

$\color{Blue}\circ$ Then try to find how to display that field on **SampleFormJupyter** available with **Run\_fiche -doc**

-   Now, we are going to extract the number of cells and the simulation final time from three .err files and write it in .dat files. Extraction script (extraction.sh) is already available in the src directory of this validation form (you can have a look at it).

    -   from your validation form, run this script using `executeScript` from run module of trustutils (see SampleFormJupyter for help).

    -   Add a table to display the results of .dat files: complete the chapter `Additional information` by introducing new cells.\
        Tip: look on the next slide for an example of table plot.

Here is an example of a Jupyter cell for displaying a table.

![image](PICTURES/c3b113b06c37f75f1f190d57cfc0278108395105.png){width="1.\\textwidth"}

-   Now we are going to add a fourth test case: `debit4`

    -   `debit4` corresponds to `std` test case with zero initial velocity and imposed flow rate to $2 m^3/s$ on `periox` boundary.

    -   Add the test case using `substitute` and `addCase`

-   We are going to rerun the validation form.

    -   Re-build the whole validation form by clicking on the icone corresponding to the r̈estart of the Jupyter kernel and run of the whole notebook:̈

    -   build the pdf report using:
        **Run\_fiche -export\_pdf**

    -   NB: You can add the results of this test case to your `visualization` and to the `table`.
