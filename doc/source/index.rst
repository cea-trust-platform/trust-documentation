###################
TRUST Documentation
###################

.. figure:: https://github.com/cea-trust-platform/trust-code/blob/master/bin/HTML/logo_trust.gif?raw=true
   :alt: image description
   :width: 600px
   :align: center

Hi there 👋 and welcome to the **TRUST documentation** page ! 

TRUST is a High Performance Computing (HPC) thermohydraulic engine for Computational Fluid Dynamics (CFD) developed at the Departement of System and Structure Modelisation (DM2S) of the French Atomic Energy Commission (CEA).

The software was primaly design for solving incompressible single phase flows. You can now also use it for solving mutltiphase flow problems.

TRUST is also progessively ported to support GPU accelearation, using the `Kokkos <https://kokkos.org/kokkos-core-wiki/>` library. It has been selected to be a demonstrator of the `CExA <https://cexa-project.org/>` project. 

When speaking of the TRUST code, we use the world plateform as it is the base of other CEA code, called BALTIKS. Those codes have various applications around thermohydraulic problems. `TrioCFD<https://triocfd.cea.fr/>` is one of those BALTIKS. 
If you want to use TRUST for a specific application, you can create your own BALTIK by following this tutorial :doc:`_srcs_processed/tutorials/dev/build_your_baltik.md`

After this brief introduction, it is time for you to get started with trust. Go to the quick start guide :doc:`_srcs_processed\quick_start\index.rst` that will help you set up TRUST and run first test case.

You can then find the :doc:`_srcs_processed\user_guide\index.rst` that will help you navigate between the different options you will need for creating, running and post-processing a test case. It lists the available options in TRUST and give you some advice depending on your application.

If you want a more active introduction to TRUST, feel free to try the different user tutorials :doc:`_srcs_processed\user_tutorials\index.rst`.

Eventually, if you want to join the adventure and developp in TRUST, you can find some help and guidlines in the Develloper Corner :doc:`_srcs_processed\dev_corner\index.rst`.

Here are some useful links that you can visit too:

- :TRUST Code: https://github.com/cea-trust-platform/trust-code

- :TRUST Website: https://cea-trust-platform.github.io

- :TRUST Support: trust@cea.fr

Do not forget to cite TRUST if you use it, see: https://cea-trust-platform.github.io/cite.html

.. toctree::
   :hidden:
   :maxdepth: 2

   _srcs_processed/quick_start/index
   _srcs_processed/general_guide/index
   _srcs_processed/user_tutorials/index
   _srcs_processed/dev_corner/index
   references

