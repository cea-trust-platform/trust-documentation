# Quasi Compressible flow 

As always when you use TRUST, start by loading your **TRUST** environment, [see](../quick_start.md).

The case we will play with in this tutorial is called `TP_Temp_QC_VEF` in the **TRUST** non-regression database. It is a 2D simulation of helium gas flow in a rectangular channed from left to right between two heated walls.

Start by copying it in your folder:
```
source $my_path_to_TRUST_installation/env_TRUST.sh
mkdir -p TRUST_tutorials
cd TRUST_tutorials
trust -copy TP_Temp_QC_VEF
```

Then, open the [](../user_guide/reference/index.rst) in another tab, as it will be useful to search for keywords in this exercise.

Edit the data file with your favorite editor, or using gedit:
```
gedit TP_Temp_QC_VEF.data &
```

You will make several changes in the `.data` file:

- First, modify the geometry and the mesh as shown in {numref}`fig:lowmach`.

```{figure} FIGURES/low_mach.png
:class: custom-image-class
:name: fig:lowmach
:alt: low_mach

Geometry modification for the Low-Mach case
```

- Then, add several probes (velocity, density, temperature) near the upper right corner of the geometry at location (x,y)=(4,1).

- Add a **segment** of probes (with 9 points) between the locations (x,y)=(4,0.05) and (x,y)=(4,0.95) for the temperature field.

- Write the results in **lata** format and change the **dt\_post** period to 1s.

- The aim of the calculation is to reach steady state, so suppress **tmax** keyword and change the **seuil\_statio** $\varepsilon$ value to 10. $|dT/dt|<\varepsilon$ and $dt \sim 0.001s$ so $|dT|<0.01$).

- Now add the keyword **impr** into the pressure solver to print residuals convergence of the solver.

- Save and close your `.data` file.

- Run the simulation with the `evol` tool (or using command lines):

       trust -evol TP_Temp_QC_VEF &

- Check the mass flow rate (absolute and relative values) in the `TP_Temp_QC_VEF.out` file.

- Once the calculation finished, visualize the results using **VisIt**:

       visit -o TP_Temp_QC_VEF.lata &

   - Print out the mesh and visualize the temperature field by selecting the last time with the slicer, then plot it: `Add` $\rightarrow$ `Pseudo Color` $\rightarrow$ `TEMPERATURE_SOM_dom` $\rightarrow$ `Draw`.

   - Hide the mesh and visualize the velocity field: `Add` $\rightarrow$ `Vector` $\rightarrow$ `VITESSE_SOM_dom` $\rightarrow$ `Draw`.

   - Save a screenshot of your visualization: `File` $\rightarrow$ `Set Save options` $\rightarrow$ `File type` $\rightarrow$ `Select a type` $\rightarrow$ `Save`. An image file named visit\*\*\* is created into your working directory.

   - Add a second screen with `Window` $\rightarrow$ `Layout` $\rightarrow$ `1x2` and plot a horizontal profile of temperature. To do so, select the temperature field and thanks to the right button, select `Mode` $\rightarrow$ `Lineout`, and define your profile with left button. The new profile should appear on the second window.

   - Close **VisIt**.

Coming back to you `.data` file, substitute the time scheme by an implicit time scheme, like {ref}`schema_euler_implicite`.

Use the **implicite** solver and specify **facsec** and **facsec\_max** parameters according to the advice given in the {ref}`facsec_expert`.

Run again the calculation with this time scheme using the `evol` tool or with:
```
trust TP_Temp_QC_VEF.data 1>TP_Temp_QC_VEF.out 2>TP_Temp_QC_VEF.err
```

You can edit the files containing information about the time steps and residuals evolution for each equation:
```
gedit TP_Temp_QC_VEF.dt_ev &
```

If everything seems working, try to enhance the convergence speed of the implicit solver with the value of **seuil\_convergence\_implicite** keyword. 
If the number of iterations for GMRES is comprised between 3 and 5 then it is enough to converge quickly. You can access this information in the `TP_Temp_QC_VEF.out` file.

We want to resume the calculation. To do so, change the **tinit** value within the data file to the one saved in the `.err` file. Moreover, you have to insert in the problem definition block of your `.data` file, the keyword **reprise binaire TP\_Temp\_QC\_VEF\_pb.sauv**.

Then, restart the calculation with:
```
trust TP_Temp_QC_VEF.data 1>TP_Temp_QC_VEF.out 2>TP_Temp_QC_VEF.err
```
or
```
trust -evol TP_Temp_QC_VEF.data &
```
The `evol` option automatically creates the TP\_Temp\_QC\_VEF.out and TP\_Temp\_QC\_VEF.err files.


# Weakly Compressible flows

If you are interested in the comparison between Quasi Compressible and Weakly Compressible simulations, see the validation form:
```
cd $TRUST_ROOT/Validation/Rapports_automatiques/Verification/Verification_codage/QC_vs_WC
Run_fiche
```
