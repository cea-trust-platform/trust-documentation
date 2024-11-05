Introduction
============

In the TRUST code, different numerical schemes are availabe to the user : VDF, VEF and the PolyMAC family.

-  The VDF discretisation is based on the Marker and Cell scheme presented in **[HW65]**.

-  The VEF discretisation is based on the Crouzeix-Raviart element method.

The PolyMAC discretisation family has been developped since 2018. Three PolyMAC are usable in TRUST. They have been built using a Finite Volume (FV) framework on a staggered mesh so as to extend the MAC scheme developped in **[HW65]** to complex grids:

-  PolyMAC : based on a Compact Discrete Operator (CDO) approach, such as the one presented in **[B14]** and **[M20]**. 

-  PolyMACP0 : based on MPFA approach, such as the one presented in **[AM08]**, **[D14]** and **[lP17]**.

-  PolyMACP0P1NC : based on a Hybrid Finite Volmue (HFV) approach, such as the one presented in **[EGH07]** and **[EGH10]**.

Thereafter, for each method the core ideas and the main steps for the discretisation of the incompressible Navier-Stokes equation are presented. For now, the PolyMAC and PolyMAC_P0 parts are completed, the others are a work in progress.

Notations
=========

Let’s consider a space :math:`\Omega` and a certain grid :math:`\mathcal{M}` of non-overlapping polyhedrons that map :math:`\Omega`. 

In the following:

-  A polyhedron of the grid will be called a cell : :math:`e`.

-  A face :math:`f` is defined as the intersection of two cells or one face and a boundary. Faces of the grid are supposed to be planar.

-  An edge :math:`\sigma` is defined as the intersection of faces or faces and boundary. This entity only exists in the 3D framework.

-  A vertex :math:`v` is defined as the intersection of edges or edges and a boundary.

The set of cells will be called :math:`E`. The set of faces of a peculiar cell :math:`e` will be denoted :math:`F_e`. In the same fashion, the set of edges of a peculiar face :math:`f` will be noted as :math:`\Sigma _f` and finally, the two vertices of an edge :math:`\sigma` will be denoted :math:`V_{\sigma}`. In the rest of the document, the measure of an unknown :math:`x` at a control volume :math:`cv` will be denoted:

.. math:: [x]_{cv} = \frac{1}{|cv|} \int_{cv} x \, \text{d}\, (cv)

where :math:`|\cdot|` will be a global measure operator over the considered control volume. For example, :math:`|e|` refers to the volume of the cell :math:`e`, :math:`|f|` to the surface of the face :math:`f` and :math:`|\sigma|` to the length of the edge :math:`\sigma`. Unknown :math:`u` refers to the velocity and :math:`p` refers to the pressure.
