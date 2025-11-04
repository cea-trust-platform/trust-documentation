# Post-Processing

Do you know that CFD refers to Colors For Directors ? It sure is a bad joke but it emphasis the importance of beautiful post-processing when you are running a fluid mecanics simulation. The aim of this section is to give you the key to create beautiful pictures and videos from your amazing **TRUST** simulations. 


Before trying to post-processing something, make sure that the information has not already been printed out in one of the files creted by a **TRUST** run.

## Automatically outpouted files

After running, you will find different files in your directory. Here is a short explaination of what you will find in each type of file depending on its extension.

Even if you don't post-process anything, you will have output files which are listed here:

| File | Contents |
|---|---|
| *my_data_file***.dt_ev** | Time steps, facsec, equation residuals |
| *my_data_file***.stop** | Stop file ('0', '1' or 'Finished correctly') |
| *my_data_file***.log** | Journal logging |
| *my_data_file***.TU** | CPU/GPU performances |
| *my_data_file***_csv.TU** | CPU/GPU performance formatted as a CSV file |
| *my_data_file_problem_name***.sauv** or **.xyz** | Saving 2D/3D results for resume |
| or *specified_name***.sauv** or **.xyz** | (binary files) |

and the listing of boundary fluxes where:

- *my_data_file***_Contrainte_visqueuse.out** correspond to the friction drag exerted by the fluid.

- *my_data_file***_Convection_qdm.out** contains the momentum flow rate.

- *my_data_file***_Debit.out** is the volumetric flow rate.

- *my_data_file***_Force_pression.out** correspond to the pressure drag exerted by the fluid.

If you add post-processings in your data files, you will find:

| File | Contents |
|---|---|
| *my_data_file***.sons** | 1D probes list |
| *my_data_file_probe_name***.son** | 1D results with probes |
| *my_data_file_probe_name***.plan** | 3D results with probes |
| *my_data_file***.lml** *(default format)* | |
| *my_data_file***.lata** *(with all \*.lata.\* files)* | |
| *my_data_file***.med** | 2D/3D results |
| or *specified_name***.lml** or **.lata** or **.med** | |

The sceen outputs are automatically redirected in *my_data_file***.out** and *my_data_file***.err** files if you run a parallel calculation or if you use the "**-evol**" option of the "trust" script.

You can also redirect them in two files with the following command:

```bash
# Source TRUST env if not already done
source $my_path_to_TRUST_installation/env_TRUST.sh

# then
trust my_data_file 1>file_out.out 2>file_err.err
```

In the .out file, you will find the listing of physical infos with mass balance and in the .err file, the listing of warnings, errors and domain infos.

## Post-processing block
Several keywords can be used to create a post-processing block, into a problem. First, you can create a single post-processing task (**Post_processing** keyword). Generally, in this block, results will be printed with a specified format at a specified time period.

```bash
Post_processing
{
   Postraitement_definition
   ...
}
```

But you can also create a list of post-processings with **Post_processings** keyword (named with Post_name1, Post_name2, etc...), in order to print results into several formats or with different time periods, or into different results files:

```bash
Post_processings
{
   Post_name1 { Postraitement_definition }
   Post_name2 { Postraitement_definition }
   ...
}
```

### Probes

Probes refer to sensors that allow a value or several points of the domain to be monitored over time. The probes are a set of points defined:

- one by one: **Points** keyword

  or

- by a set of points evenly 

  - distributed over a straight segment: **Segment** keyword 

     or

  - arranged according to a layout: **Plan** keyword 

     or

  - arranged according to a parallelepiped **Volume** keyword.

Here is an example of 2D **Probes** block:

```bash
Probes 
{
   pressure_probe [loc] pressure Periode 0.5 Points 3 1. 0. 1. 1. 1. 2.
   velocity_probe [loc] velocity Periode 0.5 Segment 10 1. 0. 1. 4.
}
```

where the use of *loc* option allow to specify the wanted location of the probes. The available values are **grav** for gravity center of the element, **nodes** for faces and **som** for vertices. There is not default location. If the point does not coincide with a calculation node, the value is extrapolated linearly according to neighbouring node values.

For complete syntax, see the [Keyword Reference Manual](../reference/index.rst).

### Fields

This keyword allows to post-process fields on the whole domain, specifying the name of the backup file, its format, the post-processing time step and the name (and location) of the post-processed fields.

Here is an example of **Fields** block:

```bash
Fichier results
Format lata
Fields dt_post 1. 
{
   velocity [faces] [som] [elem]
   pressure [elem] [som]
   temperature [elem] [som]
}
```

where **faces**, **elem** and **som** are keywords allowed to specify the location of the field.

```{note}
When you don't specify the location of the field, the default value is **som** for values at the vertices. So fields are post-processed at the vertices of the mesh.
```

To visualize your post-processed fields, you can use open source softwares like:

[VisIt](https://wci.llnl.gov/simulation/computer-codes/visit) (included in **TRUST** package) or [SALOME](http://www.salome-platform.org).

For complete syntax, see the [Keyword Reference Manual](../reference/index.rst).

### Statistics

Using this keyword, you will compute statistics on your unknows. You must specify the begining and ending time for the statistics, the post-processing time step, the statistic method, the name (and location) of your post-processed field.

Here is an example of **Statistiques** block:

```bash
Statistiques dt_post 0.1 
{
   t_deb 1. t_fin 5.
   moyenne velocity [faces] [elem] [som]
   ecart_type pressure [elem] [som]
   correlation pressure velocity [elem] [som]
}
```

This block will write at every **dt_post** the average of the velocity $\overline{V(t)}$:

$$\overline{V(t)}=\left\{ \begin{array}{ll}
0 & ,\mbox{ for }t\leq t_{deb}\\
\frac{1}{t-t_{deb}}{\displaystyle \int_{t_{deb}}^{t}V(t)dt} & ,\mbox{ for }t_{deb}<t\leq t_{fin}\\
\frac{1}{t_{fin}-t_{deb}}{\displaystyle \int_{t_{deb}}^{t_{fin}}V(t)dt} & ,\mbox{ for }t>t_{fin}
\end{array}\right.$$

the standard deviation of the pressure $\left\langle P(t)\right\rangle$:

$$\left\langle P(t)\right\rangle=\left\{ \begin{array}{ll}
0 & ,\mbox{ for }t\leq t_{deb}\\
\frac{1}{t-t_{deb}}{\displaystyle \sqrt{\int_{t_{deb}}^{t}\left[P(t)-\overline{P(t)}\right]^{2}dt}} & ,\mbox{ for }t_{deb}<t\leq t_{fin}\\
\frac{1}{t_{fin}-t_{deb}}{\displaystyle \sqrt{\int_{t_{deb}}^{t_{fin}}\left[P(t)-\overline{P(t)}\right]^{2}dt}} & ,\mbox{ for }t>t_{fin}
\end{array}\right.$$

and correlation between the pressure and the velocity $\left\langle P(t).V(t)\right\rangle$ like:

$$\left\langle P(t).V(t)\right\rangle=\left\{ \begin{array}{ll}
0 & ,\mbox{ for }t\leq t_{deb}\\
\frac{1}{t-t_{deb}}{\displaystyle \int_{t_{deb}}^{t}\left[P(t)-\overline{P(t)}\right]\cdot\left[V(t)-\overline{V(t)}\right]dt} & ,\mbox{ for }t_{deb}<t\leq t_{fin}\\
\frac{1}{t_{fin}-t_{deb}}{\displaystyle \int_{t_{deb}}^{t_{fin}}\left[P(t)-\overline{P(t)}\right]\cdot\left[V(t)-\overline{V(t)}\right]dt} & ,\mbox{ for }t>t_{fin}
\end{array}\right.$$

**Remark:** Statistical fields can be plotted with probes with the keyword "operator_field_name" like for example: Moyenne_Vitesse or Ecart_Type_Pression or Correlation_Vitesse_Vitesse. For that, it is mandatory to have the statistical calculation of this fields defined with the keyword **Statistiques**.

For complete syntax, see the [Keyword Reference Manual](../reference/index.rst).

### Field names

#### Existing & predefined fields

You can post-process predefined fields and already existing fields. Here is a list of post-processable fields, but it is not the only ones.

| Physical values | Keyword for field_name | Unit |
|---|---|---|
| Velocity | Vitesse or Velocity | m.s⁻¹ |
| Velocity residual | Vitesse_residu | m.s⁻² |
| Kinetic energy per elements | Energie_cinetique_elem | kg.m⁻¹.s⁻² |
| Total kinetic energy | Energie_cinetique_totale | kg.m⁻¹.s⁻² |
| Vorticity | Vorticite | s⁻¹ |
| Pressure in incompressible flow (P/ρ + gz) | Pression | Pa.m³.kg⁻¹ |
| Pressure in incompressible flow (P+ρgz) | Pression_pa or Pressure | Pa |
| Pressure in compressible flow | Pression | Pa |
| Hydrostatic pressure (ρgz) | Pression_hydrostatique | Pa |
| Total pressure | Pression_tot | Pa |
| Pressure gradient | Gradient_pression | m.s⁻² |
| Velocity gradient | gradient_vitesse | s⁻¹ |
| Temperature | Temperature | C or K |
| Temperature residual | Temperature_residu | C.s⁻¹ or K.s⁻¹ |
| Temperature variance | Variance_Temperature | K² |
| Temperature dissipation rate | Taux_Dissipation_Temperature | K².s⁻¹ |
| Temperature gradient | Gradient_temperature | K.m⁻¹ |
| Heat exchange coefficient | H_echange_Tref | W.m⁻².K⁻¹ |
| Turbulent viscosity | Viscosite_turbulente | m².s⁻¹ |
| Turbulent dynamic viscosity | Viscosite_dynamique_turbulente | kg.m.s⁻¹ |
| Turbulent kinetic | Energy | K m².s⁻² |
| Turbulent dissipation rate | Eps | m³.s⁻¹ |
| Constituent concentration | Concentration | - |
| Constituent concentration residual | Concentration_residu | - |
| Component velocity along X | VitesseX | m.s⁻¹ |
| Component velocity along Y | VitesseY | m.s⁻¹ |
| Component velocity along Z | VitesseZ | m.s⁻¹ |
| Mass balance on each cell | Divergence_U | m³.s⁻¹ |
| Irradiancy | Irradiance | W.m⁻² |
| Q-criteria | Critere_Q | s⁻¹ |
| Distance to the wall Y + | Y_plus | - |
| Friction velocity | U_star | m.s⁻¹ |
| Void fraction | Alpha | - |
| Cell volumes | Volume_maille | m³ |
| Source term in non Galinean referential | Acceleration_terme_source | m.s⁻² |
| Stability time steps | Pas_de_temps | s |
| Volumetric porosity | Porosite_volumique | - |
| Distance to the wall | Distance_Paroi | m |
| Volumic thermal power | Puissance_volumique | W.m⁻³ |
| Local shear strain rate | Taux_cisaillement | s⁻¹ |
| Cell Courant number (VDF only) | Courant_maille | - |
| Cell Reynolds number (VDF only) | Reynolds_maille | - |
| Viscous force | Viscous_force | kg.m².s⁻¹ |
| Pressure force | Pressure_force | kg.m².s⁻¹ |
| Total force | Total_force | kg.m².s⁻¹ |
| Viscous force along X | Viscous_force_x | kg.m².s⁻¹ |
| Viscous force along Y | Viscous_force_y | kg.m².s⁻¹ |
| Viscous force along Z | Viscous_force_z | kg.m².s⁻¹ |
| Pressure force along X | Pressure_force_x | kg.m².s⁻¹ |
| Pressure force along Y | Pressure_force_y | kg.m².s⁻¹ |
| Pressure force along Z | Pressure_force_z | kg.m².s⁻¹ |
| Total force along X | Total_force_x | kg.m².s⁻¹ |
| Total force along Y | Total_force_y | kg.m².s⁻¹ |
| Total force along Z | Total_force_z | kg.m².s⁻¹ |

```{note}
Physical properties (conductivity, diffusivity,...) can also be post-processed.
```

```{note}
The name of the fields and components available for post-processing is displayed in the error file after the following message: "Reading of fields to be postprocessed". Of course, this list depends of the problem being solved.
```

#### Creating new fields

The **Definition_champs** keyword is used to create new or more complex fields for advanced post-processing.

```bash
Definition_champs { field_name_post field_type { ... } }
```

*field_name_post* is the name of the new created field and **field_type** is one of the following possible type:

- **refChamp** 

- **Reduction_0D** using for example the **min**, **max** or **somme** methods 

- **Transformation** 

Refer to the [Keyword Reference Manual](../reference/index.rst) for more information.

```{note}
You can combine several **field_type** keywords to create your field and then use your new fields to create other ones.
```

Here is an example of new field named *max_temperature*:

```bash
Read my_problem 
{
   ...
   Postraitement 
   {
      Definition_champs 
      {
         # Creation of a 0D field: maximal temperature of the domain #
         max_temperature Reduction_0D 
         {
            methode max
            source refChamp { Pb_champ my_problem temperature }
         }
      }

      Probes 
      {
         # Print max(temperature) into the datafile_TMAX.son file #
         tmax max_temperature periode 0.01 point 1 0. 0.
      }

      Champs dt_post 1.0 { ... }
   }
}
```

### Complete Post-Processing Example

Here is a complete post-processing example taken from the TRUST's `upwind` test case.

    Post_processing
    {
        Probes
        {
            sonde_pression pression periode 0.005 points 2 0.13 0.105 0.13 0.115
            sonde_vitesse vitesse periode 0.005 points 2 0.14 0.105 0.14 0.115
            sonde_vitesse_bis vitesse periode 0.005 position_like sonde_vitesse
            sonde_vitesse_ter vitesse periode 1e-5 position_like sonde_vitesse
        }

        Definition_champs
        {
            # Calcul du produit scalaire grad(Pression).Vitesse #
            pscal_gradP_vit Transformation {
                methode produit_scalaire
                sources {
                    Interpolation { localisation elem source refChamp { Pb_champ pb gradient_pression } } ,
                    Interpolation { localisation elem source refChamp { Pb_champ pb vitesse } }
                }
            }
            # Calcul du produit scalaire Vitesse.Vitesse #
            pscal_vit_vit_elem Transformation {
                methode produit_scalaire
                sources {
                    refChamp { Pb_champ pb vitesse } ,
                    refChamp { Pb_champ pb vitesse }
                }
                localisation elem
            }

            pscal_vit_vit_elem_interp Transformation {
                methode produit_scalaire
                sources {
                    Interpolation { localisation elem source refChamp { Pb_champ pb vitesse } } ,
                    Interpolation { localisation elem source refChamp { Pb_champ pb vitesse } }
                }
            }

            pscal_vit_vit_som Interpolation { localisation som sources_reference { pscal_vit_vit_elem_interp } }

            pscal_vit_vit_faces Interpolation { localisation faces sources_reference { pscal_vit_vit_elem_interp } }

            norme_transfo_vit Transformation {
                methode norme
                source Interpolation {
                    localisation elem
                    source refChamp { Pb_champ pb vitesse }
                }
            }

            vecteur_unitairex transformation { methode vecteur expression 2 1. 0. localisation faces }

            vecteur_transfo transformation { methode vecteur  expression 2 x t localisation faces }

            vecteur_source_elem Transformation {
                methode vecteur  expression 2 pression_natif_dom y
                source refChamp { Pb_champ pb pression }
                localisation elem
            }
            vecteur_source_faces Transformation {
                methode vecteur expression  2 pression_natif_dom y
                source refChamp { Pb_champ pb pression }
                localisation Faces
            }

            compo_vitessex Transformation {
                methode composante numero 0
                source refChamp { Pb_champ pb vitesse }
                localisation elem
            }

            compo_vitessex_elem Interpolation { localisation elem sources_reference { compo_vitessex } }

            # Calcul de la composante selon X du gradient de pression #
            compo_graPx Transformation {
                methode composante numero 0
                source refChamp { Pb_champ pb gradient_pression }
                localisation elem
            }
            # Interpolation de cette composante aux elements #
            compo_graPx_elem Interpolation { localisation elem sources_reference { compo_graPx } }
        }
        Format Lata
        fields dt_post 1.3 /* physical time */
        {
            pression elem
            vitesse elem
            masse_volumique elem
            gradient_pression elem
            pscal_gradP_vit elem
            pscal_vit_vit_elem
            pscal_vit_vit_elem_interp
            pscal_vit_vit_som
            norme_transfo_vit elem
            vecteur_unitairex elem
            vecteur_transfo elem
            vecteur_source_elem
            compo_vitessex_elem
            compo_graPx_elem
        }
    }

    liste_de_postraitements {
        test1 Post_processing {
            Definition_champs {
                test_nom reduction_0D {
                    methode weighted_average
                    sources { refchamp { pb_champ pb pression } }
                }
            }
            format lata
            fields dt_post 1.3
            {
                pression elem
                test_nom
            }
        }

        test2 Post_processing {
            format lata
            fields dt_post 1.3e9
            {
                pression elem
            }
        }
    }


## Visualisation Tools

To open your 3D results in **lata** format, you can use [VisIt](https://wci.llnl.gov/simulation/computer-codes/visit) which is an open source software included in **TRUST** package. For that you may "source" **TRUST** environment and launch VisIt:

```bash
# Source TRUST env if not already done
source $my_path_to_TRUST_installation/env_TRUST.sh
# then
visit -o my_data_file.lata &
```

To learn how to use it, you can do the [](../../quick_start.md).

To open your 3D results in **med** format, you can also use [VisIt](https://wci.llnl.gov/simulation/computer-codes/visit), [SALOME](http://www.salome-platform.org) or [Paraview](http://www.paraview.org).

Here are some actions that you can perform when your simulation is finished:

- To visualize the positions of your probes in function of the 2D/3D mesh, you can open your .son files at the same time of the .lata file in VisIt.

- If you need more probes, you can create them with VisIt (if you have post-processed the good fields) or with MEDCoupling.

- You can use the option **-evol** of the trust script, like:

  ```bash
  trust -evol my_data_file
  ```

  and access to the probes or open VisIt for 2D/3D visualizations via this tool.