# Validation form

As detailed in the [Workflow guidlines](../dev_guidelines/workflow_guidlines/index.rst), if you want your new and amazing developpements in TRUST to be integrated, you have to create an associated validation form. The prefered route to build a validation form in TRUST and its baltiks is to build a Jupyter notebook.

You can see an example of notebook in: `$TRUST_ROOT/Validation/Rapports_automatiques/Verification/SampleFormJupyter` or run on terminal:

```bash
Run_fiche -doc
```

This turorial will help you get started with the validation form so that you'll be able to create detailed ones for your own developpements.

First copy the validation form named Source_canal_perio:

```bash
mkdir -p $MY_TRUST_TUTORIAL_REPO/validation
cd $MY_TRUST_TUTORIAL_REPO/validation
cp -r $TRUST_ROOT/Validation/Rapports_automatiques/Verification/Verification_codage/Source_canal_perio .
cd Source_canal_perio
```

The command to launch your validation form is `Run_fiche`, you can see the command options with:

```bash
Run_fiche -help
```
One usefull option is:
```bash
Run_fiche -export_pdf
```
which will create a PDF in the local repository that replicates the results of your validation form.

Now, we are going to change the validation form. Launch it by doing: 
```
Run_fiche &
```

First, let's add the mesh plot in the report. To do so, at end of the notebook, add a new Markdown block:
```markdown
## Additional information
### Mesh visualization
```
and the following:
```markdown
fig=visit.Show(`./std.lata`, `Mesh`, `dom`, plotmesh=True, title=`Mesh`)
fig.plot()
```

You can also add the evolution of residuals in the report in log scale. You'll have to create a new Jupyter text cell and write:
```markdown
## Residual plot
```
Then, on another cell plot residual using:
```markdown
Graph = plot.Graph(`Residual plot`)
Graph.addResidu(`std.dt_ev`,label=`Residu`)
Graph.scale(yscale='log')
```

In order to visualize the pressure field of the last time step, complete the section `Additional information` with a new cell:

```markdown
## Visualizing fields
```
Then try to find how to display that field on **SampleFormJupyter** available with **Run\_fiche -doc**

Now, you are going to extract the number of cells and the simulation final time from the three `.err` files and write it in `.dat` files. 

The extraction script, called `extraction.sh`, is already available in the src directory of this validation form, you can have a look at it.

To use it from your validation form, you'll need `executeScript` from run module of trustutils (see SampleFormJupyter for help).

To a table to display the results of `.dat` files, complete the chapter `Additional information` by introducing new cells.

Tip: look at {numref}`fig:jupyter` for an example of a table plot.

```{figure} ../../user_tutorials/FIGURES/jupyter_table.png
:class: custom-image-class
:name: fig:jupyter
:alt: jupyter

Example of a Jupyter Notebook block
```

Now, we are going to add a fourth test case: `debit4` which corresponds to `std` test case with zero initial velocity and imposed flow rate to $2 m^3 \cdot s ^{-1}$ on `periox` boundary.

Add the test case using `substitute` and `addCase`

Then, re-run the form from the start. by clicking on the icone corresponding to the r̈estart of the Jupyter kernel and run of the whole notebook.

Eventually, build the pdf report with:
```bash
Run_fiche -export_pdf
```
