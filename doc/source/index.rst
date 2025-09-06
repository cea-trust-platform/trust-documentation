###################
TRUST Documentation
###################

Hi there 👋 and welcome to the **TRUST** documentation page ! 

**TRUST** is a High Performance Computing (HPC) thermohydraulic engine for Computational Fluid Dynamics (CFD) developed at the Department of System and Structure Modelisation (DM2S) of the French Atomic Energy Commission (CEA).

**TRUST** in an open source software under the `BSD license <https://github.com/cea-trust-platform/trust-code/blob/master/License.txt>`_, available on GitHub via `this link <https://github.com/cea-trust-platform/trust-code>`__. 
The software was primarily designed for solving incompressible single-phase flows, but you can now also use it for solving multiphase flow problems.

**TRUST** is also progressively ported to support GPU acceleration, using the `Kokkos <https://kokkos.org/kokkos-core-wiki/>`_ library. It has been selected to be a demonstrator of the `CExA <https://cexa-project.org/>`_ project. 

When speaking of the **TRUST** code, we use the world platform as it serves as a base for other CEA code, called BALTIKS. Those codes have various applications around thermohydraulic problems. `TrioCFD <https://triocfd-documentation.readthedocs.io/en/latest/>`_ is one of those BALTIKS. 

If you want to use **TRUST** for a specific application, you can create your own BALTIK by following this tutorial: :doc:`_srcs_processed/dev_corner/dev_tutorials/build_your_baltik`. We do not recommand newcommers to start with that, make sure first to check-out the :doc:`_srcs_processed/quick_start` that will help you set up **TRUST** and run a first test case.

If you need help to navigate between the different options for creating, running and, post-processing a test case, make sure to check out the :doc:`_srcs_processed/user_guide/index`. 
This guide lists the available options in **TRUST** and gives you some advice depending on your applications, but also helps you better understand what is under each keyword you will need to use.

If you want a more active introduction to **TRUST**, feel free to try the different :doc:`_srcs_processed/user_tutorials/index`.

Eventually, if you want to join the adventure and develop in **TRUST**, check out the :doc:`_srcs_processed/dev_corner/index`.

Here are some useful links that you can visit too:

- :**TRUST** Code: https://github.com/cea-trust-platform/trust-code

- :**TRUST** Website: https://cea-trust-platform.github.io

- :**TRUST** Support: trust@cea.fr

Do not forget to `cite <https://cea-trust-platform.github.io/cite_us/>`_ TRUST.

.. toctree::
   :hidden:
   :maxdepth: 2

   _srcs_processed/quick_start.md
   _srcs_processed/user_guide/index
   _srcs_processed/user_tutorials/index
   _srcs_processed/dev_corner/index
   references

