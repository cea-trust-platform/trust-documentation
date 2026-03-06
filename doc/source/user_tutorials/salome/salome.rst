Salome tutorials
================

The `SALOME <https://www.salome-platform.org/>`_ platform provides engineers, researchers, and practitioners with a solution that integrates high-level modules covering: CAD, meshing, coupling of phenomena, visualization, calculation supervision, uncertainty quantification, and more, supporting the full pipeline of a numerical simulation. 
These modules can be used directly through SALOME's intuitive GUI or via Python scripts. If desired, users can build domain-specific applications by assembling these modules to suit the needs of their numerical simulation.
Developed collaboratively, SALOME is available under the GNU Lesser General Public License (LGPL). Its continuous evolution ensures optimal use of computing resources: clusters, HPC, and graphics hardware. SALOME is widely used by EDF and CEA, both in France, to carry out studies required for the proper functioning of their facilities and to support research in their respective fields.
This set of tutorials demonstrates how to use SALOME to create 3D meshes suitable for the VEF discretization available in the TRUST code. It covers several practical examples, from simple geometries to complex coupled problems.

In addition to these tutorials, you can visit the SALOME `User's Documentation <https://docs.salome-platform.org/latest/main/gui.html>`_


.. toctree::
   :maxdepth: 1
   
   cylinder.md 
   revolution.md
   tshape.md
   coupled_pb.md
   mesh_python.md


