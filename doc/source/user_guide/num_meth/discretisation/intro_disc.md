# Introduction

In the **TRUST** code, different numerical schemes are available to the user: VDF, VEF and the PolyMAC family.

- The VDF discretization is based on the Marker and Cell scheme presented in {cite:p}`HW65`.

- The VEF discretization is based on the Crouzeix-Raviart element method {cite:p}`Emonot1992`.

The PolyMAC discretization family has been developed since 2018. Three PolyMAC variants are available in **TRUST**. They have been built using a Finite Volume (FV) framework on a staggered mesh so as to extend the MAC scheme developed in {cite:p}`HW65` to complex grids:

- **PolyMAC**: based on a Compatible Discrete Operator (CDO) approach, such as the one presented in {cite:p}`Bonelle2014` and {cite:p}`Milani2020`.

- **PolyMAC_MPFA**: based on a Multi Point Flux Approximation (MPFA) approach, such as the one presented in {cite:p}`AM08`, {cite:p}`D14` and {cite:p}`LePotier2017`.

- **PolyMAC_HFV**: based on a Hybrid Finite Volume (HFV) approach, such as the one presented in {cite:p}`EGH07` and {cite:p}`DEGH10`.

Thereafter, for each method the core ideas and the main steps for the discretization of the incompressible Navier-Stokes equations are presented. For now, the PolyMAC and PolyMAC_MPFA parts are completed; the others are a work in progress.

# Notations

Let's consider a space $\Omega$ and a certain grid $\mathcal{M}$ of non-overlapping polyhedra that map $\Omega$.

In the following:

- A polyhedron of the grid will be called a cell: $e$.

- A face $f$ is defined as the intersection of two cells or one cell and a boundary. Faces of the grid are supposed to be planar.

- An edge $\sigma$ is defined as the intersection of faces or faces and a boundary. This entity only exists in the 3D framework.

- A vertex $v$ is defined as the intersection of edges or edges and a boundary.

The set of cells will be called $E$. The set of faces of a particular cell $e$ will be denoted $F_e$. In the same fashion, the set of edges of a particular face $f$ will be noted as $\Sigma_f$ and finally, the two vertices of an edge $\sigma$ will be denoted $V_{\sigma}$. In the rest of the document, the measure of an unknown $x$ at a control volume $cv$ will be denoted:

$$
[x]_{cv} = \frac{1}{|cv|} \int_{cv} x \, \text{d}\, (cv)
$$

where $|\cdot|$ will be a global measure operator over the considered control volume. For example, $|e|$ refers to the volume of the cell $e$, $|f|$ to the surface of the face $f$ and $|\sigma|$ to the length of the edge $\sigma$. Unknown $u$ refers to the velocity and $p$ refers to the pressure.

## Bibliography

```{bibliography}
:filter: docname == env.docname
```