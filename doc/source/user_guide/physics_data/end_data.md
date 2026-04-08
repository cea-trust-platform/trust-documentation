# Stop and restart

An important feature when running a simulation is the ability to stop and restart it. This section explains how you can do it with **TRUST**.

## Stop a Running Calculation

When using **TRUST**, your calculation will automatically stop if it has reached:

- the end of the calculation time.
- the maximal allowed CPU time.
- the maximal number of iterations.
- the threshold of convergence.

You may use the `my_data_file.stop` file if you want to stop your running calculation properly (i.e. with all saves).

When the simulation is running, you can see the **0** value in that file. To stop it, put a **1** instead of the **0** and at the next iteration the calculation will stop properly.

When you don't change anything in that file, at the end of the calculation, you can see that it is written **Finished correctly**.

## Save

**TRUST** makes automatic backups during the calculation. The unknowns (velocity, temperature, ...) are saved in:

- one **.xyz** file, written:
  - at the end of the calculation.
  - but the user may disable it with the specific keyword **EcritureLectureSpecial 0** added just before the **Solve** keyword.

- one (or several in case of parallel calculation) **.sauv** files, written:
  - at the start of the calculation.
  - at the end of the calculation.
  - each 23 hours of CPU; to change it, use the **periode_sauvegarde_securite_en_heure** keyword (default value 23 hours).
  - the user may also specify a physical time period with the **dt_sauv** keyword.
  - periodically using the **tcpumax** keyword, for which the calculation stops after the specified time (default value $10^{30}$). Use it for calculations on CCRT/TGCC and CINES clusters for example.

:::{note}
By default, the name for the **.sauv** files is **filename_problemname.sauv** for sequential calculations, **filename_problemname_000n.sauv** for parallel calculations (one per process). The format of these files is binary and the files are completed during successive saves.
:::

You can change the behaviour using the following keywords just before the **solve** instruction:

```bash
sauvegarde binaire|xyz filename .sauv|filename .xyz
```

with **xyz**: the **.xyz** file is written instead of the **.sauv** files.

:::{note}
You can use **sauvegarde_simple** instead of **sauvegarde**, where the `.sauv` or `.xyz` file is deleted before saves, in order to save disk space:

```bash
sauvegarde_simple binaire|xyz filename .sauv|filename .xyz
```
:::

For more information, see the {doc}`../reference/index`.

## Resume

To resume your calculation, you may:

- change your initial time; the new initial time will be the real final calculation time of the previous calculation (see the `.err` file).
- change your final calculation time to the new desired value.
- add the following block just before the **Solve** keyword:

  ```bash
  reprise binaire|xyz filename .sauv|filename .xyz
  ```

  :::{note}
  Instead of the **reprise** keyword, you can use **resume_last_time** where **tinit** is automatically set to the last time of the saved files (but you may still change **tmax**):

  ```bash
  resume_last_time binaire|xyz filename .sauv|filename .xyz
  ```
  :::

You can resume your calculation:

- from `.sauv` file(s) (one file per process): you can only resume the calculation with the **same number of equations** on **the same number of processes**.
- or from a `.xyz` file: here you can resume your calculation by **changing the number of equations solved** and/or with a **different number of processes**.

:::{note}
You can run a calculation with initial conditions read from a save file (`.xyz` or `.sauv`) from a previous calculation using **Champ_Fonc_reprise**, or read from a MED file with **Champ_Fonc_MED**.
:::