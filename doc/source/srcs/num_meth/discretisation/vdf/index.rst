rst
The Finite Volume Difference (VDF) Discretization
=================================================

The VDF discretization (class ``VDF_discretisation`` and alias ``VDF``) is the simplest and most efficient discretization of the TRUST platform. This discretization is compatible with conform mesh with hexahedral type of elements. Attention: do not confuse between a hexahedral mesh and a cartesian mesh. The VDF mesh is not structured and does not follow the IJK indexing!

As stated by its name, the VDF is a conservative finite volume scheme of Marker-and-Cell (MAC) type. The discretization of each term of the equation is performed by integrating over a control volume. The diffusion gradient terms are approximated by a linear difference equation. All scalars are stored at the center of each control volume except the velocity field which is defined on a staggered mesh.

This discretization **supports** 2D axi-symmetrical configurations and **is compatible** with ``Pb_Multiphase``.


.. figure:: ./FIGURES/vdf_staggered_grid.png
   :align: center
   :width: 600px
   :alt: Grille décalée VDF 2D avec description détaillée
   
   *Grille décalée 2D zoomée - Description VDF : scalaires stockés au centre des cellules (points noirs), composante de vitesse x-horizontale aux faces horizontales de la cellule (point vert), composante de vitesse y-horizontale aux faces verticales de la cellule (point rouge). Les volumes de contrôle pointillés verts et rouges sont utilisés pour résoudre les équations des composantes de vitesse horizontale (verte) et verticale (rouge).*
