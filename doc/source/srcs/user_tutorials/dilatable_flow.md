# Quasi Compressible flow 

As always when you use TRUST, start by loading your **TRUST** environment, [see](../index.rst).

The case we will play with in this tutorial is called `TP_Temp_QC_VEF` in the **TRUST** repository. It is a 2D simulation of helium gas flow from left to right between two heated walls. Start by copying it in your folder:
```
trust -copy TP_Temp_QC_VEF
```

Then, open the [TRUST Reference](../../reference/index.rst) in another tab, as it will be useful to search for keywords in this exercise.

Edit the data file with your favorite editor. **Gedit** is recommended because you can [configure](../index.rst) it to recognize the **TRUST** syntax:
```
gedit TP_Temp_QC_VEF.data &
```

You will make several changes in the `.data` file:

- First, modify the geometry and the mesh so that it resembles to {numref}`fig:lowmach`.

```{figure} FIGURES/low_mach.png
:class: custom-image-class
:name: fig:lowmach
:alt: low_mach

Geometry modification the Low Mach case
```

- Then, add several probes (velocity, density, temperature) near the upper right corner of the geometry at location (x,y)=(4,1).

- Add a **segment** probe  (with 9 points) between the locations (x,y)=(4,0.05) and (x,y)=(4,0.95) for the temperature field.

- Write the results on the **lata** format and change the **dt\_post** period to 1s.

- The aim of the calculation is to find the steady state, so suppress **tmax** keyword and change the **seuil\_statio** $\varepsilon$ value to 10. $|dT/dt|<\varepsilon$ and $dt \sim 0.001s$ so $|dT|<0.01$).

- Now add the keyword **impr** into the pressure solver to print its convergence.

Save and close your `.data` file.

You can now run the numerical simulation with the **TRUST** command:
```
trust -evol TP_Temp_QC_VEF &
```
and pressing on `Start computation!`.

Check the mass flow rate (absolute and relative values) in the `TP_Temp_QC_VEF.out` file, or look at the upper small window on the right of the `evol` tool.

Once the calculation stopped, visualize the results by using **VisIt**:
```
visit -o TP_Temp_QC_VEF.lata &
```
Print out the mesh and visualize the temperature field by selecting the last time with the slicer, then plot it: 

`Add` $\rightarrow$ `Pseudo Color` $\rightarrow$ `TEMPERATURE_SOM_dom` $\rightarrow$ `Draw`.

Hide the mesh and visualize the velocity field:

`Add` $\rightarrow$ `Vector` $\rightarrow$ `VITESSE_SOM_dom` $\rightarrow$ `Draw`.

Afterwards, select the Zoom mode with the right button of the mouse: 
`Mode` $\rightarrow$ `Zoom` and then zoom by selecting an area on the plot. To un-zoom push `Ctrl` button and select an area with the left button. Or with the right button select
`View` $\rightarrow$ `Reset view`.

Now, print your visualization: `File` $\rightarrow$ `Set Save options` $\rightarrow$ `File type` $\rightarrow$ `Select a type` $\rightarrow$ `Save`.

A file named visit\*\*\* is created into your working directory.

Then, add a second screen with `Window` $\rightarrow$ `Layout` $\rightarrow$ `1x2` and plot a horizontal profile of temperature. To do so, select the temperature field and thanks to the right button, select `Mode` $\rightarrow$ `Lineout`, and define your profile with left button. The new profile should appear on the second window.

You can close **VisIt** for now.

Coming back to you `.data` file, substitute the time scheme by an implicit time scheme, like **scheme\_euler\_implicit**.

Use the **implicite** solver and specify **facsec** and **facsec\_max** parameters according to the advice given in the [Reference Manual](../../reference/index.rst) by searching for the **scheme\_euler\_implicit** keyword.

Run again the calculation with this time scheme using the `evol` tool or with:
```
trust TP_Temp_QC_VEF.data 1$>$TP_Temp_QC_VEF.out 2$>$TP_Temp_QC_VEF.err
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
trust TP_Temp_QC_VEF.data 1$>$TP_Temp_QC_VEF.out 2$>$TP_Temp_QC_VEF.err
```
or
```
trust -evol TP_Temp_QC_VEF.data &
``` 
The `evol` option automatically creates the .out file.

If you are interested in the comparison between Quasi Compressible and Weakly Compressible simulations, see the validation form:
```
cd $TRUST_ROOT/Validation/Rapports_automatiques/Verification/Verification_codage/QC_vs_WC
Run_fiche
```