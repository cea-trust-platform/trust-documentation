# Parallel calculation

The goal of this exercise is to introduce parallelism in the data file Obstacle.data of [](../quick_start.md).

First, load TRUST environment and copy the test case Obstacle.

Then copy this directory, called `PARA`, open it and copy the necessary files as follows:
```
mkdir PARA
cd PARA
cp ../Obstacle.data DEC_Obstacle.data
cp ../Obstacle.data PAR_Obstacle.data
cp ../Obstacle.geo .
```
The file `DEC_Obstacle.data` will be used for partioniing the mesh. To do so, uncomment the block around the **Partition** keyword.

        # BEGIN PARTITION #
        Partition dom
        {
           Partition_tool metis { nb_parts 2 }
           Larg_joint 2
           zones_name DOM
        }
        End
        # END PARTITION #

Here, the partitioning tool **Metis** will be used. We cut the domain into **nb\_parts = 2** parts.

In the general case, the overlapping width **Larg\_joint** between two parts of the partition have to be defined accordingly with the numerical scheme. For exemple, if you use a VEF discretisation (see [](../user_guide/num_meth/discretisation/vef/index.rst) for more details regarding this discretisation), you should use **2** for **Larg\_joint** except when partitioning a domain where only the upwind (first-order) discretization scheme will be solved.

The keyword **zones\_name** is useful to define the name of the files containing the partitioned mesh that will be written.

**Remark**: notice the presence of the keyword **End** in the `Partition` block: the code will stop reading the data file at this line! This also means that everything coming after this line can be deleted since it is not interpreted by the code.

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

or better, if you want to keep the outputs of your run which may serve later:
```
trust PAR_Obstacle 2 1>PAR_Obstacle.out 2>PAR_Obstacle.err
```

The post-processing step is identical in sequential or parallel modes. Probes are written into .son files and fields into .lata files. Check by yourself using **Visit**:

```
visit -o PAR_Obstacle.lata &
```

Select the last time step and visualize the blocks with:

`Plots` $\rightarrow$ `Add` $\rightarrow$ `Subset` $\rightarrow$ `blocks`.

Those blocks represent the partition of the domain. Fields are defined by block.

You can visualize a field only on a selected (block) with the menu `Control` $\rightarrow$ `Subset`.

Finally, visualize probes at the end of the calculation using:
```
trust -evol PAR_Obstacle &
```

