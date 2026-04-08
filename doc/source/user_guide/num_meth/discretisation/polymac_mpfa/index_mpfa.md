# PolyMAC_MPFA

Unlike PolyMAC, PolyMAC_MPFA does not introduce the vorticity. Moreover, no
complex dual mesh is explicitly needed. The location of the unknowns is
described in {numref}`fig:location_unknowns_p0`.

```{figure} ./FIGURES/PolyMAC_unknowns.png
:name: fig:location_unknowns_p0
:width: 300
:align: center
:alt: Unknowns location in PolyMAC_MPFA

Location of the unknowns when using PolyMAC_MPFA
```

PolyMAC_MPFA is based on the Multi Point Flux Approximation (MPFA) method.

## MPFA methods

Three MPFA methods are used in practice in PolyMAC_MPFA for computing gradients:

- The MPFA-O method presented in {cite:p}`A02`, {cite:p}`AM08`, {cite:p}`D14`

- The MPFA-O($\eta$) method presented in {cite:p}`ER98`

- The MPFA-symm method presented in {cite:p}`LP05a`, {cite:p}`LP05b`, {cite:p}`LePotier2017`

The choice of method is based on a coercivity condition. Let's briefly introduce the core ideas of gradient approximation using MPFA methods. First, a dual mesh is constructed. An example of a dual mesh for a triangular mesh is presented in {numref}`fig:scheme_mpfa`, where the red dots are the primal vertices and black lines the primal faces. The procedure to build the dual mesh in {numref}`fig:scheme_mpfa` is as follows:

- Link each cell's ($e$) gravity center (in purple) to the gravity center of each cell's face $f \subset e$ (in blue). Doing so, the faces of the mesh are cut into two sub-faces called $\hat{f}_1$ and $\hat{f}_2$. Each cell can then be subdivided into $N_i$ quadrilaterals (in orange), called $(S_{e,i})_{i\in\{ 1,\dots, N_i \} }$.

- Introduce for each sub-face $\hat{f} \subset f$ an auxiliary quantity (in green). For the MPFA-symmetric method, those auxiliary quantities are set at one third and two thirds of the face $f$. For the MPFA-O method, they are placed at the center of the face; however, the value of the auxiliary unknowns at the center is not continuous. The MPFA-O($\eta$) method can be seen as an in-between, as it tries to compute the optimum location of the auxiliary unknown.

```{figure} ./FIGURES/MPFA.png
:name: fig:scheme_mpfa
:width: 700
:align: center
:alt: Construction of a gradient using MPFA

Construction of a gradient using the MPFA method
```

On $S_1$ in {numref}`fig:scheme_mpfa` for example, the gradient of a potential $p$, $G_{S_{e,i}}([p]_e)$, is computed as:

$$
G_{S_{e,i}}([p]_e) = \frac{1}{|S_{e,i}|} \left( (p_{S_{e,1},1} - p_e) \vec{n_1} + (p_{S_{e,1},2} - p_e) \vec{n_2} \right),
$$

where $\vec{n_1}$ and $\vec{n_2}$ are the outward unit normal vectors of the respective sub-faces $\tilde{f}\subset f$ where the auxiliary elements $p_{S_{e,1}}$ and $p_{S_{e,2}}$ are located. Thus, $G^{\text{MPFA}}$ writes:

```{math}
:label: P0_Gmpfa

G^{\text{MPFA}}: [p]_e \mapsto G^{\text{MPFA}}([p]_e) \ , \quad \forall e \in E \ , \quad i \in S_e \ : \quad G^{\text{MPFA}} _{|S_{e,i}} = G_{S_{e,i}}([p]_e).
```

A core assumption of the MPFA method is to suppose that $G^{\text{MPFA}}([p]_e)$ is constant on each $S_{e,i}$. When enforcing continuity across the sub-faces that are linked by a vertex of the primal mesh, auxiliary variables can be substituted by cell unknowns.

The MPFA methods are implemented in `Domaine_PolyMAC_MPFA::fgrad`.

## Incompressible Navier-Stokes

The incompressible Navier-Stokes equations read:

```{math}
:label: P0_Navier_Stokes

\begin{aligned}
& \partial_{t} \left( u \right) + \nabla \cdot \left( u \otimes u \right) + \nabla p - \mu \Delta u = f \ , \\
& \nabla \cdot u = 0 \ .
\end{aligned}
```

The mass equation is discretized at the cell using the Green-Ostrogradski theorem:

$$
|e|[\nabla \cdot u]_e = |f| \sum_{F_e} [u]_f
$$

The momentum equation is discretized at the face:

- For the convective term:

  - Approximate the value of the velocity at the cell:

    $$
    [u]_e = \frac{1}{|e|} \sum_{f \in F_e} |f| [u]_f \, x_{e \rightarrow f}.
    $$

  - Discretize the convective terms at the cell centers:

    $$
    \begin{aligned}
    {[\nabla \cdot ( u \otimes u)]}_{e} &= \frac{1}{|e|} \sum_{f \in F_e} |f| [{u} \otimes {u}]_f \\
    &\simeq \frac{1}{|e|} \sum_{f \in F_e} |f| [u]_f \left( \beta \left( \gamma [u]_{e_{up}} + \left(1-\gamma \right) [u]_{e_{down}} \right) \right.
    \\ & \quad \left. + (1-\beta) \left( \frac{[u]_{e_{up}} + [u]_{e_{down}}}{2} \right) \right),
    \end{aligned}
    $$

    with $\beta \in [0,1]$ and $\gamma \in \{0,1\}$ such that $\gamma = 1$ if $[u_f] \geq 0$ and $0$ otherwise.

- The convective terms:

  - Interpolate convective terms to the face:

    $$
    [\nabla \cdot (u \otimes u)]_{f} = \lambda_{e,f} [\nabla \cdot (u \otimes u)]_{e} + \lambda_{e',f} [\nabla \cdot (u \otimes u)]_{e'}
    $$

    with the penalty coefficient $\lambda_{e,f} = \frac{|\vec{x}_{e' \rightarrow f}|}{|\vec{x}_{e' \rightarrow f}| + |\vec{x}_{e \rightarrow f}|}$, with $e'$ the neighbouring cell of $e$ sharing the face $f$.

- The gradient of $p$ is computed using an MPFA scheme {eq}`P0_Gmpfa`.

- The diffusive term is rewritten as:

  $$
  \Delta u = \nabla \cdot \left( \nabla u + (\nabla u)^{\intercal} \right)
  $$

- Then a second-order interpolation is used to compute the velocity at the cell:

  - First, introducing $n_f$ the outward normal of face $f$, one can write the series expansion:

    $$
    u_f \cdot n_f \approx \left( u_e + (\nabla u)_e \cdot (x_f - x_e) \right) \cdot n_f
    $$

  - Then, considering the stencil composed of the faces that share a vertex of $e$, called $\mathcal{F}^v_e$, one can obtain the following system:

    $$
    A \cdot U_e = U_{\mathcal{F}^v_e}
    $$

    where each row $i$ corresponds to the equation for the $i^{th}$ face of $\mathcal{F}^v_e$. $A$ is a matrix of geometrical quantities, $U_e$ stores the components of $u_e$ and $(\nabla u)_e$, and $U_{\mathcal{F}^v_e}$ the value of $u_f$ at the face.

  - However, there is a large number of equations relative to the number of unknowns. To solve this problem, we use a least-squares method to find the solution that minimizes:

    $$
    \min_{U_e} \sum_{f \in \mathcal{F}^v_e} \frac{1}{\|x_e - x_f\|} \left( A(f) \, U_e - u_f \right)^2
    $$

    where $A(f)$ corresponds to the row of $A$ associated with face $f$. This equation is solved using the `dgelsy` method of the **LAPACK** library.

- Afterwards, we compute:

  $$
  \left[\nabla \cdot \left( \mu_e \left((\nabla u) + (\nabla u)^{\intercal}\right)\right)\right]_e = \sum_{f} |f| \left(G^{\text{MPFA}} ([u]_e) + \left(G^{\text{MPFA}} ([u]_e)\right)^{\intercal}\right) \cdot \vec{n}_f.
  $$

- Eventually, we interpolate the diffusion term at the face in the same fashion as for the convective term.

Some details regarding the discretization of a two-phase flow model of the Ishii family {cite:p}`I75` are given in {cite:p}`GG22`.

# PolyMAC_HFV

PolyMAC_HFV is based on a Hybrid Finite Volume (HFV) approach, such as the one presented in {cite:p}`EGH07` and {cite:p}`EGH10`. PolyMAC_HFV is mathematically close to PolyMAC, as HFV and CDO methods are equivalent, see {cite:p}`DEGH10`.