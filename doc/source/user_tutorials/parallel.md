# Parallel calculation (Flow around an obstacle)

The goal of this exercise is to introduce parallelism into the `Obstacle.data` file from {ref}`seq-obstacle-target`.

First, load the TRUST environment and copy the Obstacle test case.

Then create a directory called `PARA`, open it, and copy the necessary files as follows:
```
source $my_path_to_TRUST_installation/env_TRUST.sh
mkdir -p TRUST_tutorials
cd TRUST_tutorials
trust -copy Obstacle
cd Obstacle
mkdir PARA
cd PARA
cp ../Obstacle.data DEC_Obstacle.data
cp ../Obstacle.data PAR_Obstacle.data
cp ../Obstacle.geo .
```
The file `DEC_Obstacle.data` will be used for partitioning the mesh. To do so, uncomment the block around the **Partition** keyword.

        # BEGIN PARTITION #
        Partition dom
        {
           Partition_tool metis { nb_parts 2 }
           Larg_joint 2
           zones_name DOM
        }
        End
        # END PARTITION #

Here, the partitioning tool **Metis** will be used to cut the domain into **nb\_parts = 2** parts.

In general, the overlapping width **Larg\_joint** between two parts of the partition must be defined according to the numerical scheme. For example, if you use a VEF discretization (see [](../user_guide/num_meth/discretisation/vef/index.rst) for more details), you should use **2** for **Larg\_joint**, except when partitioning a domain where only the upwind (first-order) discretization scheme will be used.

The keyword **zones\_name** defines the name of the files that will contain the partitioned mesh.

```{note}
Notice the presence of the keyword **End** in the `Partition` block: the code will stop reading the data file at this line. This means that everything after this line can be deleted, as it will not be interpreted by the code.
```

Now, run this edited data file: 
```
trust DEC_Obstacle
```

Check that the partitioned mesh files `DOM_0000.Zones` and `DOM_0001.Zones` were generated in your working directory: 
```
ls *.Zones
```

Now that the domain has been partitioned, edit the file `PAR_Obstacle.data`, which will be run in parallel, and remove the mesh reading part of the `.data` file.

Then, uncomment the **Scatter** keyword, which will read the partitioned mesh, and run a parallel calculation with TRUST:

```
trust PAR_Obstacle 2
```

or, if you want to keep the outputs for later use:
```
trust PAR_Obstacle 2 1>PAR_Obstacle.out 2>PAR_Obstacle.err
```

The post-processing step is identical in sequential and parallel modes (except for the name of the lata file, which corresponds to the data file's name). Probes are written to `.son` files and fields to `.lata` files. You can check this yourself using **VisIt**:

```
visit -o PAR_Obstacle.lata &
```

Select the last time step and visualize the blocks with:

`Plots` $\rightarrow$ `Add` $\rightarrow$ `Subset` $\rightarrow$ `blocks`.

These blocks represent the partitioning of the domain. Fields are defined block by block.

You can visualize a field on a selected block only via the menu `Control` $\rightarrow$ `Subset`.

Finally, visualize the probes at the end of the calculation using:
```
trust -evol PAR_Obstacle &
```
Note that sequential calculations can only be launched with the `evol` tool.
