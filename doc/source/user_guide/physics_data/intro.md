# Introduction

**TRUST** is a High Performance Computing (HPC) thermal-hydraulic engine for Computational Fluid Dynamics (CFD) developed at the Department of System and Structure Modelling (DM2S) of the French Atomic Energy Commission (CEA).

The acronym **TRUST** stands for **TR**io\_**U** **S**oftware for **T**hermalhydraulics. This software was originally designed for conduction, incompressible single-phase, and Low Mach Number (LMN) flows with a robust Weakly-Compressible (WC) multi-species solver. However, a huge effort has been conducted recently, and now TRUST is able to simulate real compressible multi-phase flows.

TRUST is also being progressively ported to support GPU acceleration (NVidia/AMD), using the [Kokkos](https://kokkos.org/kokkos-core-wiki/) library.

The software is open source with a [BSD license](https://github.com/cea-trust-platform/trust-code/blob/master/License.txt), available on GitHub via [this link](https://github.com/cea-trust-platform/trust-code).

You can easily create new projects based on the **TRUST** platform. These projects are named **BALTIK** projects (**B**uild an **A**pplication **L**inked to **T**RUST **K**ernel).

## A bit of history: the Modular Software Named Trio_U

**TRUST** was born from the splitting of the **Trio_U** software into two pieces. **Trio_U** was a software brick based on the **Kernel** brick (which contains the equations, space discretizations, numerical schemes, parallelism, ...) and was used by other CEA applications (see Figure 1).

```{figure} images/tikz1.png
:alt: image description
:width: 600px
:align: center
:figclass: small-caption

Figure 1: Trio_U brick software
```

In 2015, **Trio_U** was divided into two parts: **TRUST** and **TrioCFD**.

- **TRUST** is a new platform; its name means: **TR**io\_**U** **S**oftware for **T**hermohydraulics.
- **TrioCFD** is an open source BALTIK project based on **TRUST**.

Here are some other selected BALTIK projects based on the TRUST platform (see Figure 2).

```{figure} images/tikz2.png
:alt: image description
:width: 700px
:align: center
:figclass: small-caption

Figure 2: Selected BALTIK projects based on the TRUST platform.
```

## Short History

**TRUST** is developed at the Laboratory of High Performance Computing and Numerical Analysis (LCAN) of the Software Engineering and Simulation Service (SGLS) in the Department of System and Structure Modeling (DM2S).

The project started in 1994 and improved versions have been built ever since:

- **1994:** Start of the project Trio_U
- **1997:** v1.0 - Finite Difference Volume (VDF) method only
- **1998:** v1.1 - Finite Element Volume (VEF) method only
- **2000:** v1.2 - Parallel MPI version
- **2001:** v1.3 - Radiation model (TrioCFD now)
- **2002:** v1.4 - LES turbulence models (TrioCFD now)
- **2006:** v1.5 - VDF/VEF Front Tracking method (TrioCFD now)
- **2009:** v1.6 - Data structure revamped
- **2015:** v1.7 - Separation TRUST & TrioCFD + switch to open source
- **2019:** v1.8 - New polyhedral discretization (PolyMAC) + Multiphase problem + Weakly Compressible model
- **2022:** v1.9.0 - Modern C++ code (templates, CRTP, ...) + remove MACROS + support GPU (NVidia/AMD)
- **2025:** v1.9.6 - Unified version to handle 32-64b integers + VEF discretization supported on GPU