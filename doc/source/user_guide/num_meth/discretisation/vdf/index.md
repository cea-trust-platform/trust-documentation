# VDF

The Finite Volume Difference (VDF) discretization (class `VDF_discretisation` and alias `VDF`) is the simplest and most efficient discretization of the TRUST platform. This discretization is compatible with conforming meshes with hexahedral type elements. Note: do not confuse a hexahedral mesh with a Cartesian mesh. The VDF mesh is not structured and does not follow the IJK indexing!

As stated by its name, the VDF is a conservative finite volume scheme of Marker-and-Cell (MAC) type, {cite:p}`HW65`. The discretization of each term of the equation is performed by integrating over a control volume. The diffusion gradient terms are approximated by a linear difference equation. All scalars are stored at the center of each control volume except the velocity field, which is defined on a staggered mesh.

This discretization **supports** 2D axi-symmetrical configurations and **is compatible** with `Pb_Multiphase`.

```{figure} ./FIGURES/VDF-cut.png
:name: fig:scheme-vdf
:align: center
:width: 600px
:alt: Staggered VDF 2D grid with detailed description

Scheme of a VDF grid: scalars are stored at the center of the elements and the normal component of the velocities at the faces of the element
```