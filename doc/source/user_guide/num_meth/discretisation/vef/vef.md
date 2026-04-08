# VEF

Initially introduced in {cite:p}`LM89`, *Volume Element Finis -VEF-* (Finite Volume Element) method is a variant of the standard finite element
and finite volume methods. The formalism developed in {cite:p}`Emonot1992` was subsequently used for the implementation of
this method in the **TRUST** code.

## Finite Volume Element method

### Core Idea

First, let's consider the following instationary problem, with the velocity $\boldsymbol{u}$, a flux term
$\boldsymbol{F}$ and a source term $\boldsymbol{S}$.

```{math}
:label: Flux_continu

\partial_t \boldsymbol{u} + \nabla \cdot \boldsymbol{F} = \boldsymbol{S}
```

We also introduce the control volume $\omega_f$ (see {numref}`fig:control_volume_velocity`) in which we want to evaluate the velocity $\boldsymbol{u}$. We integrate on $\omega_f$ between the times $t^n$ and $t^{n+1}$, regardless of the regularity of $\boldsymbol{u}$ and $\boldsymbol{F}$. We also introduce a pressure $p$.

$$
\int_{\omega_f} (\boldsymbol{u}^{n+1} - \boldsymbol{u}^n)\mathrm{d}\boldsymbol{V} + \int_{\partial\omega_f} \int_{t^n}^{t^{n+1}} \boldsymbol{F} \cdot \boldsymbol{n} \mathrm{d}\boldsymbol{s} =  \int_{\omega_f}  \int_{t^n}^{t^{n+1}} \boldsymbol{S} \mathrm{d}\boldsymbol{V}
$$

The expression of the flux term depends on the equation: $\boldsymbol{F} = \mu \nabla \boldsymbol{u} - p\boldsymbol{I}$ for the Stokes equation and $\boldsymbol{F} = \mu \nabla \boldsymbol{u} - p\boldsymbol{I} + \rho \boldsymbol{u} \otimes \boldsymbol{u}$ for the Navier-Stokes equation.

```{figure} FIGURES/control_volume_velocity.png
:alt: Control volume for velocity
:name: fig:control_volume_velocity
:height: 8cm

Control volume for velocity
```

### Finite Volume Approach

Given a tetrahedral mesh $\mathcal{T}_h$, we define the points $\boldsymbol{x}_f$ as the barycentric center of the face $f$. The control volume $\omega_f$ is the polygon which links the vertex of the face $\boldsymbol{f}$ with the barycenters of the two tetrahedra that share the face $\boldsymbol{f}$. Let $\boldsymbol{u}_f^m$ be the approximation of the velocity $\boldsymbol{u}$ at the node $\boldsymbol{x}_f$ and $\Delta t^{n,n+1} \boldsymbol{S}_f^{n, n+1}$ the approximation of the right-hand side term. Let's discretize the evolution term such that:

$$
\int_{\omega_f} \boldsymbol{u}^{m} \mathrm{d}\boldsymbol{V} \approx |\omega_f|  \boldsymbol{u}_f^m \qquad m \in \{n, n+1\}
$$

Let's set $\boldsymbol{F}^m = \boldsymbol{F}(t^n)$ or
$\boldsymbol{F}(t^{n+1})$, or a combination of the two depending
on the time scheme chosen. The discretization of the flux term leads to
the following equation.

$$
\int_{\partial\omega_f}  \int_{t^n}^{t^{n+1}} \boldsymbol{F} \cdot \boldsymbol{n} \mathrm{d}\boldsymbol{s} \approx \Delta t^{n,n+1} \int_{\partial\omega_f}  \boldsymbol{F}^m \cdot \boldsymbol{n} \mathrm{d}\boldsymbol{s} = \Delta t^{n,n+1} |l_f| (\boldsymbol{F}^m_{T_R} - \boldsymbol{F}^m_{T_L} )\boldsymbol{n}_{T_L,T_R}
$$

The discretization of equation {eq}`Flux_continu` becomes:

$$
|\omega_f|(\boldsymbol{u}_f^{n+1} - \boldsymbol{u}_f) + \Delta t^{n,n+1} |l_f| (\boldsymbol{F}^m_{T_R} - \boldsymbol{F}^m_{T_L} )\boldsymbol{n}_{T_L,T_R} = \Delta t^{n,n+1} \boldsymbol{S}_f^{n, n+1}
$$

At this point, the discretization method looks like a Finite Volume
scheme. The main difference comes from the way the term
$\boldsymbol{F}^m_{T}$ is discretized with the help of
Finite Element basis functions.

### Finite Element Basis

Historically, the VEF method was presented with the Crouzeix-Raviart basis.
The full velocity vector is evaluated at the center of the faces of each tetrahedron. Within each cell, the pressure is a constant evaluated by its value at the center of the cell. Let's denote
$(\phi_f)_{f\in \mathcal{I}_{\text{f}}}$ the velocity basis (i.e. $\phi_f(\boldsymbol{x_{f'}}) = \delta_{f,f'}$) and $(\mathbb{I}_{K_k})_{k\in {\mathcal{I}_K}}$ the pressure basis (see {numref}`fig:triangle_vef`). Each discrete velocity vector
$\boldsymbol{u}_h$ and pressure $p_h$ can be expressed with the following linear combination.

$$
\begin{aligned}
    \boldsymbol{u}_h = \sum_{f\in \mathcal{I}_{\text{f}}}{}\boldsymbol{u}_f \phi_f\\
    p_h = \sum_{k\in {\mathcal{I}_K}}{} p_k \mathbb{I}_{K_k}
\end{aligned}
$$

```{figure} ./FIGURES/triangle.png
:name: fig:triangle_vef
:align: center
:alt: Control volume for pressure P0
:height: 10cm

Control volumes for VEF-P0
```

### Discretization of the flux term in the Stokes equation

For the Stokes equation, the flux term is
$\boldsymbol{F} = \mu \nabla \boldsymbol{u} - p\boldsymbol{I}$.
Integrating on $\partial\omega_f$, the discretization can be
written with the finite element basis:

$$
\int_{\partial\omega_f} \boldsymbol{F} = \underset{f' \in \mathcal{I}_{\text{f}}}{\sum} \boldsymbol{u}_{f'} \int_{\partial\omega_{f}} \boldsymbol{\nabla} \phi_{f'} \cdot \boldsymbol{n} d\boldsymbol{s}
    + \underset{k \in \mathcal{I}_K}{\sum} p_k \int_{\partial\omega_f \cap K_k}  \boldsymbol{n} d\boldsymbol{s}
$$

Note that the finite element basis $(\phi_f)_{f\in \mathcal{I}_f}$ can be expressed with the help of barycentric coordinates (see {cite:p}`CR73`) and its gradient is constant per tetrahedron: $(\nabla\phi_f)_T = \frac{1}{|T|}\int_{\partial T} \boldsymbol{n}d\boldsymbol{s}$ (see {cite:p}`Emonot1992`, p27).

Thus, the discrete gradient of the velocity writes:

$$
\begin{aligned}
\int_{\partial\omega_f} \boldsymbol{\nabla} \phi_{f'} \cdot {\boldsymbol{n}}d\boldsymbol{s}
&= \sum_{T \in \mathcal{T}_h} (\nabla \phi_{f'})_T \cdot \int_{\omega_f \cap T } \boldsymbol{n}d\boldsymbol{s}\\
&= - \sum_{T \in \mathcal{T}_h} \frac{1}{|T|} S_T^{f'} \cdot S_T^f,
\end{aligned}
$$

with:

$$
\int_{\omega_f\cap T} \boldsymbol{n}d\boldsymbol{s} = - \int_{\partial T} \boldsymbol{n}d\boldsymbol{s} = S_T^f
$$

and the pressure part:

$$
\underset{k \in \mathcal{I}_K}{\sum} p_k \int_{\partial\omega_f \cap K_k}  \boldsymbol{n} d\boldsymbol{s} =  |l_f|(p_{T_R} - p_{T_L}) \boldsymbol{n}_{T_L, T_R}
$$

### Variational Formulation of the Stokes problem

Let us introduce $\mathbb{X}_h$ the finite element space for discrete velocities $\boldsymbol{u}_f$ and $\mathring{\mathbb{N}}_h$ for the discrete pressure.
Then, we obtain the following *VEF* variational formulation by multiplying the mass conservation equation by a *test* pressure function
$q_h = \underset{k \in \mathcal{I}_K}{\sum} q_k \mathbb{I}_{K_k}$ and the momentum conservation equation by a *test* velocity function
$\boldsymbol{v}_h = \underset{f \in \mathcal{I}_{\text{f}}}{\sum} \boldsymbol{v}_f \phi_f$.

Find
$(\boldsymbol{u}_h, p_h) \in \mathbb{X}_h \times \mathring{\mathbb{N}}_h$
such that:

```{math}
:label: variational_form

    \left\{
    \begin{aligned}
    \partial_t m_h^V(\boldsymbol{u}_h,\boldsymbol{v}_h) + a_h^V(\boldsymbol{u}_h, \boldsymbol{v}_h) + b_h^V(\boldsymbol{v}_h, p_h) &= L_h^V(\boldsymbol{v}_h) \qquad & \forall \boldsymbol{v}_h \in \mathbb{X}_h, \\
    c_h^V(\boldsymbol{u}_h, q_h) &= 0 \qquad & \forall q_h \in \mathring{\mathbb{N}}_h.
    \end{aligned}
    \right.
```

with:

$$
m_h^V :=
    \left\{
    \begin{aligned}
    \mathbb{X}_h \times \mathbb{X}_h &\to \mathbb{R}, \\
    (\boldsymbol{u}_h, \boldsymbol{v}_h) &\mapsto   \underset{f,f' \in \mathcal{I}_{\text{f}}}{\sum} \boldsymbol{u}_{f'} \cdot \boldsymbol{v}_{f}
    |\omega_f|\delta_f(\boldsymbol{x}_{f'})
    \end{aligned}
\right.
$$

$$
a_h^V :=
\left\{
    \begin{aligned}
    \mathbb{X}_h \times \mathbb{X}_h &\to \mathbb{R}, \\
    (\boldsymbol{u}_h, \boldsymbol{v}_h) &\mapsto    \underset{f,f' \in \mathcal{I}_{\text{f}}}{\sum} \boldsymbol{u}_{f'} \boldsymbol{v}_{f}  \int_{\partial\omega_{f}} \boldsymbol{\nabla} \phi_{f'} \cdot \boldsymbol{n} d\boldsymbol{s}.
    \end{aligned}
\right.
$$

$$
b_h^V :=
\left\{
    \begin{aligned}
    \mathbb{X}_h \times \mathring{\mathbb{N}}_h &\to \mathbb{R}, \\
    (\boldsymbol{v}_h, p_h) &\mapsto    \underset{f \in \mathcal{I}_{\text{f}}}{\sum} \underset{k \in \mathcal{I}_K}{\sum} \boldsymbol{v}_{f} p_k \int_{\partial\omega_f \cap K_k} \boldsymbol{n} d\boldsymbol{s}.
    \end{aligned}
\right.
$$

$$
c_h^V :=
\left\{
    \begin{aligned}
    \mathbb{X}_h \times \mathring{\mathbb{N}}_h &\to \mathbb{R}, \\
    (\boldsymbol{u}_h, q_h) &\mapsto    \underset{k \in \mathcal{I}_K}{\sum} \underset{f \in \mathcal{I}_{\text{f}}}{\sum} \boldsymbol{u}_f q_k \int_{\partial K_k} \phi_f \cdot \boldsymbol{n} d \boldsymbol{s}.
    \end{aligned}
\right.
$$

$$
L_h^V :=
\left\{
    \begin{aligned}
    \mathbb{X}_h &\to \mathbb{R}, \\
    \boldsymbol{v}_h &\mapsto     \underset{f \in \mathcal{I}_{\text{f}}}{\sum} \boldsymbol{v}_{f} \int_{\omega_f} \boldsymbol{f} d\boldsymbol{V}.
    \end{aligned}
\right.
$$

This formulation resembles a finite element variational formulation.

## Mathematical properties

According to {cite:p}`Heib2003`, there are two methods for analyzing the scheme based on the formulation {eq}`variational_form`:

- The first involves directly analyzing the scheme. It enables one to prove the uniform continuity of the bilinear forms, the ellipticity of $a_h^V$, and to establish the inf-sup conditions.

- The second involves demonstrating the equivalence of assembly
  matrices derived from FEM and VEF for the same given functional
  spaces. Thus, the numerical scheme can be analyzed with the FEM formalism, which is well-known for the Navier-Stokes equation with Crouzeix-Raviart elements (see {cite:p}`CR73`).

Using these equivalence properties, the Finite Volume Element scheme satisfies the following FEM properties:

- **Inf-sup condition**: Ensures the stability of the numerical scheme.
- **Continuity at edge midpoints**: Implies weak continuity of velocity and enforces local mass conservation, leading to a divergence-free condition in each cell.
- **Well-posedness of the discrete problem**: Guarantees the existence and uniqueness of the discrete solution.
- **Convergence rate for pressure**: The pressure approximation converges with order 1 in the $L^2$ norm.
- **Convergence rate for velocity**: The velocity approximation converges with order 2 in the $\boldsymbol{L^2}$ norm, provided that $\Omega$ is convex.

A summary of the Crouzeix-Raviart FEM properties is presented in {cite:p}`B14`. However, spurious currents for low velocities can appear when using the VEF approach, see {cite:p}`Fortin2006`.

## New Finite Element Basis

In order to reduce spurious currents (useful for low viscosities), a pressure-enriched basis was studied in {cite:p}`Heib2003` and {cite:p}`Fortin2006` and implemented in the **TRUST** code under the name VEF - $\mathbb{P}^{nc}/\mathbb{P}^0+\mathbb{P}^1$.
The idea is to add pressure unknowns $\mathbb{P}^1$ at the vertices of each cell.
This adds a new control volume for the mass conservation. {numref}`fig:triangle_vef` represents the two control volumes for the two pressure unknowns:

- $K_k$ for the constant part of the pressure, which is $\mathbb{P}^0$
- $\Pi_{S^i}$ for the $\mathbb{P}^1$ part associated with the unknown located at the center of vertex $S^i$.

```{figure} FIGURES/pi_si_kl.png
:alt: Control volume for pressure P0 and P1
:name: fig:pi_f
:height: 10cm

Control volume for pressure P0 and P1
```

The stability of this new finite element basis is proved in {cite:p}`JCS23` and the inf-sup condition in {cite:p}`Fortin2006`. This scheme is the most widely used VEF discretization in **TRUST**.