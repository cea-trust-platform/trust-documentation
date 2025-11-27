###################
TRUST Documentation
###################

Hi there 👋 and welcome to the **TRUST** documentation page !

**TRUST** is a High Performance Computing (HPC) thermohydraulic engine for Computational Fluid Dynamics (CFD) and is developed at the Department of System and Structure Modelisation (DM2S) of the French Atomic Energy Commission (CEA).

**TRUST** in an open-source software under the `BSD license <https://github.com/cea-trust-platform/trust-code/blob/master/License.txt>`_, available on `Github <https://github.com/cea-trust-platform/trust-code>`__.
Although the software was primarily designed for solving incompressible single-phase flows, you can now use it for solving multiphase flow problems.

**TRUST** is also progressively ported to support GPU acceleration, using the `Kokkos <https://kokkos.org/kokkos-core-wiki/>`_ library. It has been selected to be a demonstrator of the `CExA <https://cexa-project.org/>`_ project.

When speaking of the **TRUST** code, we use the world platform as it serves as a base for other research and industrial CEA codes, called BALTIKS. `TrioCFD <https://triocfd-documentation.readthedocs.io/en/latest/>`_ is one of those BALTIKS.

If you need help to navigate between the different options for creating, running and, post-processing a test case, make sure to check out the :doc:`user_guide/index`.
This guide lists the available options in **TRUST** and gives you some advice depending on your applications, but also helps you better understand what is under each keyword you will need to use.

Here are some useful links that you can visit too:

- :**TRUST** Code: https://github.com/cea-trust-platform/trust-code

- :**TRUST** Website: https://cea-trust-platform.github.io

- :**TRUST** Support: trust@cea.fr

Do not forget to `cite <https://cea-trust-platform.github.io/cite_us/>`_ TRUST.

.. toctree::
   :hidden:
   :maxdepth: 2

   user_guide/index
   references
