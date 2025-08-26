# Validation form


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

```{figure} FIGURES/jupyter_table.png
:class: custom-image-class
:alt: jupyter

Example of a Jupyter Notebook block
```
-   Now we are going to add a fourth test case: `debit4`

    -   `debit4` corresponds to `std` test case with zero initial velocity and imposed flow rate to $2 m^3/s$ on `periox` boundary.

    -   Add the test case using `substitute` and `addCase`

-   We are going to rerun the validation form.

    -   Re-build the whole validation form by clicking on the icone corresponding to the r̈estart of the Jupyter kernel and run of the whole notebook:̈

    -   build the pdf report using:
        **Run\_fiche -export\_pdf**

    -   NB: You can add the results of this test case to your `visualization` and to the `table`.
