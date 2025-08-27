# Quick Guide

**The following tutorials requires a Linux based computer.**

## How to install TRUST

**First method, with git:**

```bash
git clone https://github.com/cea-trust-platform/trust-code.git TRUST-1.9.6
# Move to the cloned TRUST folder
cd TRUST-1.9.6
# Download the required external packages
wget ftp://ftp.cea.fr/pub/TRUST/externalpackages/externalpackages-1.9.6.tar
# or:
# curl ftp://ftp.cea.fr/pub/TRUST/externalpackages/externalpackages-1.9.6.tar > externalpackages-1.9.6.tar
# or:
# wget "https://drive.usercontent.google.com/download?id=1LAbrUO0at7eN_nwg28F92SF4SS_Qw4K5&export=download&authuser=4&confirm=t" -O externalpackages-1.9.6.tar
# Unzip the downloaded external packages folder
```

**Second method, from an archive:**
```bash
wget ftp://ftp.cea.fr/pub/TRUST/TRUST/Version1.9.6/TRUST-1.9.6.tar.gz
# or:
# curl ftp://ftp.cea.fr/pub/TRUST/TRUST/Version1.9.6/TRUST-1.9.6.tar.gz > TRUST-1.9.6.tar.gz
# Unzip the downloaded folder
tar xzf TRUST-1.9.6.tar.gz
# Move to the unziped TRUST folder
cd TRUST-1.9.6
```

Then, you will need to configure TRUST with the good options. To have the option's list, run:
```bash
./configure -help
```

As you can see, if you want to run GPU simulations and you have a Nvidia GPU, you need to use the option `-cuda`.

**After choosing the options you need, run:**

```bash
./configure $MY_OPTIONS
```

Then, source the TRUST environnement:

```bash
source env_TRUST.sh
```

To check if it worked, try:

```bash
echo $TRUST_ROOT
```

Eventually, you can compile:
```bash
make
```

This will take some times but afterwards you should have an up-and-running TRUST. You can use other make options, see `make help`.

As you will see in the following, TRUST use `.data` files. In order too have a more readable `.data`, we recommand the user to run:

```bash
trust -config gedit|vim|emacs
```
## Flow around an obstacle


This first case aims at giving you the basis for launching numerical simulation with TRUST. The test case is therefore quite simple, so you can get started with TRUST smoothly.


### Geometry and simulation parameters

You can see in {numref}`fig:obstacle` the geometry of the test case.

```{figure} ./user_tutorials/FIGURES/Obstacle.png
:class: custom-image-class
:name: fig:obstacle
:alt: obstacle

Geometry of the Obstacle case
```

The following table summarises the parameters of the simulation:

| **Fluid Properties** | **Value** |
|:---------------:|:---------------:|
| Dynamic viscosity ($\mu$) | $3.7 \times 10^{-5}$ $kg \cdot m^{-1} \cdot s^{-1}$ |
| Density ($\rho$) | $2$ $kg \cdot m^{-3}$ |
| Reynolds number ($Re$) | $11,891$ | 

| **Boundary Conditions** | **Value** |
|:---------------:|:---------------:|
| Inlet velocity ($U_0$) | $1$ $m \cdot s^{-1}$ | 
| Outlet pressure ($P_0$) | $0$ $Pa$ |
| Square cylinder | No-slip wall |
| Upper and lower walls | Symmetry boundary condition |

### Get your test case

When you want to use TRUST, the first thing to do is to load your environment:

```
cd $MY_TRUST_REPO
source env_TRUST.sh
```

If you use TRUST regularly, we recommend you to create a command that load your TRUST environment.

Inside your TRUST repository, you can find several, already existing, test cases. You can copy those test cases by using:
```
trust -copy case_name
```

For this tutorial, we will play with the Obstacle test case. 
Therefore, create first a copy of this test case:
```
cd TRUST_tutorials
trust -copy Obstacle
```

The following command will give you a list of the TRUST options
```
trust -help
```

You can now run the test case:
```
trust Obstacle
```

### Probes and parameters

Let us now play with the data file, that drives the simulations. For more details regarding `.data` files go to the [TRUST user guide](../_srcs_processed/user_guide/data.rst).

First, edit the data file `Obstacle.data` and set the time step to 0.004s:
```
gedit Obstacle.data &
```

Then, replace the keyword **format lml** with **format lata** inside the post-processing block in order to use the post-processing tool **VisIt** during and/or at the end of calculation.

## Visualization during the calculation

You can manage you numerical simulation with:
```
trust -evol Obstacle &
``` 
This tool allows to launch calculation and visualize results "one the flight".

To launch the calculation, click on the button `Start computation!`.

You can now vizualise some values, depeding on you `.data` file:

- Select `PRESSION(X=0.13,Y=0.105)` in the left list and click on `Plot` to draw the evolution of the pressure at the probe location.

- Check the velocity profile behind the square cylinder by plotting `VITESSE_X(X=0.14,Y=0.115)` and `VITESSE_Y(X=0.14,Y=0.115)`.

- You can also visualize the residuals on the same plot, select $Ri = max \left| \frac{dV}{dt} \right|$ and $residu = max \left| Ri \right|$ using the button `Plot on same` or select the two graphs with `Ctrl` button then `plot`.

Close the GUI to quit the ```trust -evol ``` tool.

### The post processing tool Visit

Clean your results by using:
```
trust -clean
```
Then, relaunch your computation. Once the calculation is finished, visualize the results with VisIt:
```
 visit &
```
Or by using the `trust -evol` tool and clicking on `Visualisation` on the right menu.

Now, let's configure Visit. First, in the menu File $\rightarrow$ Open file, select Off instead of Smart for File grouping option. For the Filter, specify \*.lata to list only the lata files (results). Then save your choices, in the menu Options $\rightarrow$ Save Settings.

You can now open the file `Obstacle.lata` with: File $\rightarrow$ Open file.

Start by first visualizing the mesh in the `Plots` area with `Add` $\rightarrow$ `Mesh` $\rightarrow$ `dom` then click on the button `Draw`. Zoom and move the mesh in the right window. You can un-zoom with right button (View $\rightarrow$ Reset view) or with a combination of `Ctrl` keypad and left button.

Now we can vsualize the pressure field (Plots area: `Add` $\rightarrow$ `Pseudocolor` $\rightarrow$ `PRESSION_SOM_dom` + Draw then select the last time on the Time slider)

You can suppress or hide the mesh (Select Mesh then click on Delete or Hide/Show).

Then, visualize the velocity field:
 `Add` $\rightarrow$ `Vector` $\rightarrow$ `VITESSE_SOM_dom + Draw`. 
 
You can change each plot attributes: 
- First, click once onto the small arrow $\blacktriangleright$ then on
$\diamond$ double click on the item Vector (cf the figure below). 

- Then, you can, for example, change the number of vectors being plotted (by default 400, set it to 40000 then click the button `Make default` and save definitively this modification with the menu Options $\rightarrow$ Save Settings). Click `Apply` to update. Then click `Dismiss` to close the window.

```{figure} ./user_tutorials/FIGURES/visit3.jpg
:class: custom-image-class
:alt: visit

Visit screenshots
```

To print your visualization, go to `File` $\rightarrow$ `Save window`. A PNG file is created into your working directory.

Now, you can add a second screen with `Windows` $\rightarrow$ `Layouts` $\rightarrow$ `1x2`

In this screen you want to plot a horizontal pressure profile. To do so, then select the pressure field you want to plot, right click on the visualisation, use the right click and select `Mode` $\rightarrow$ `Line out`. 

You can then define your profile with left button. Click on the origin point, let the left button pushed, and release at the end point
 
The profile should be shown on the second window.

You can notice that it is necessary to update (button `Draw`) the right window after adding a new plot or changing an option. It is possible to automatically update by activating `Auto apply` on the top right of the VisIt's GUI.

You can now create create new fields (expression based) with `Controls` $\rightarrow$ `Expressions`.

Visit enable you to animate your visualization and/or create a movie: `File` $\rightarrow$ `Save movie`.

Another usefull tool in **VisIt** are queries that enable you to do operations on your varaibles: `Controls` $\rightarrow$ `Query`

Eventually, save your work with: File $\rightarrow$ Save session

To reopen it during a next analyze with VisIt, use: `File` $\rightarrow$ `Restore session`.


During a 3D visualization, you may want to see a slice of your numerical simulation. To do so, use one of the available operators in `Plots` $\rightarrow$ `Operators` $\rightarrow$ `Slicing` $\rightarrow$ `Slice`.

For more information on **VisIt**, you can refer to:

 - the **VisIt** website and [its manuals](https://wci.llnl.gov/simulation/computer-codes/visit/manuals)

 - the **VisIt** user community [web site](http://visitusers.org)

 - or send an email to the **VisIt** software users community at: visit-users@elist.ornl.gov

#### Outputs and resuming calculation

Start by editing the different output (\*.out) files to read the complete balances (mass, stress, energy, ...) on the whole domain or at the boundaries.

The, we want to edit the data file in order to resume the calculation from where it stopped. So, open it using the `evol` tool: 
```
trust -evol Obstacle &
```
Find the last backup time of the previous calculation in the .err file, or in the bottom right file in the `evol` tool.

Edit your data file with `Edit data`, then modify **tinit**, **tmax** values in the object `mon_schema`.

Then, add in the problem description block just before the last `}`:
**reprise binaire Obstacle\_pb.sauv**

(The file `Obstacle_pb.sauv` must have been created during the first run.)

Save and close the window.

Resume the calculation again with `Start calculation!` button. You can see that values are added to the first probes during the new calculation.

**Remark:** to resume your calculation, you can also use the keyword **resume\_last\_time** instead of **reprise** and only change the **tmax** value (cf [Reference Manual](index.rst)).

### Probes and fields

In this part, we will se how to add and modify probes and post-processed fields.

Start by editting the data file Obstacle.data:
```
gedit Obstacle.data &
```

Then add to the post-processing block of Obstacle.data the following elements:

- A pressure probes segment (22 probes between points (0.01, 0.12) and (0.91, 0.12)).

-   A velocity probes segment (22 probes between points (0.92, 0.00) and (0.92, 0.22)) to plot the velocity profile behind the square cylinder.

-   Change fields post-processing period from 1s to 0.5s.

-   Add the vorticity to the fields to the list of post-processed fields. To find the appropriate keyword, have a look to the [User Guide](../../user_guide/index.rst):
        
-   You can also access locally to useful resources in the TRUST index. Take few minutes to find test cases containing a particular keyword using the [Keywords]{.underline} link in:
```
trust -index &
```

## Parallel calculation

The goal of this exercise is to introduce parallelism in the data file of the previous exercise.

In your Obstacle repository, delete the **reprise** keyword and set **tinit** to 0 again in the `Obstacle.data` file.

Then create a new repository, called `PARA1`, open it and copy the necessary files:
```
mkdir PARA1
cd PARA1
cp ../Obstacle.data DEC_Obstacle.data
cp ../Obstacle.data PAR_Obstacle.data
cp ../Obstacle.geo .
```
The file (`DEC_Obstacle.data`) will be used for partioniing the mesh. To do so, uncomment the block around the **Partition** keyword.

In this case, the partitioning tool **Metis** is used. We cut in **nb\_parts = 2** blocks.

In the general case, the overlapping width **Larg\_joint** between two parts of the partition have to be defined accordingly with the numerical scheme. For exemple, if you use a VEF discretisation (see [TRUST Numerical Methods](../../num_meth/discretisation/vef/index.rst) for more details regarding this discretisation), you should use **2** for **Larg\_joint** except when partitioning a domain where only the conduction equation will be solved.

The keyword **zones\_name** is useful to define the name of the files containing the partitioned mesh and to write these files.

**Remark**: notice the presence of the keyword **End** in the `Partition` block: the code will stop reading the data file at this line!

Now, run this edited data file: 
```
trust DEC_Obstacle
```

Check that the partitioned mesh files `DOM_0000.Zones` and `DOM_0001.Zones` were generated inside your working directory: 
```
ls *.Zones
```

Now that you have finished your partition, edit the file `PAR_Obstacle.data` and comment the mesh reading part of you `.data` file, using \# tags of the 'BEGIN/END MESH' comments. Note that you need your \# character to be encircled to other by blank spaces, otherwise your `.data` file will not be functional.

Then, uncomment the **Scatter** keyword which will read the partitioned mesh and run a parallel calculation with TRUST:

```
trust PAR_Obstacle 2
```

The post-processing step is identical in sequential or parallel modes. Probes are written into .son files and fields into .lata files. Check by yourself using **Visit**:

```
**VisIt** -o PAR_Obstacle.lata &
```

Select the last time step and visualize the blocks with:

`Plots` $\rightarrow$ `Add` $\rightarrow$ `Subset` $\rightarrow$ `blocks`.

 Those blocks represent the partition of the domain. Fields are defined by block.

You can visualize a field only on a selected (block) with the menu `Control` $\rightarrow$ `Subset`.

Eventually, visualize probes at the end of the calculation using:
```
trust -evol PAR_Obstacle &
```

