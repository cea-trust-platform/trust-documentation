# Spatial schemes

The spatial discretization of each term in a given equation is carried out in the **TRUST** platform by what we call the **operators** (operators for convective terms, diffusion, gradient, divergence, ...) It is important to keep in mind that all these operators are **dependent** of the employed discretization; in particular on the variables localisation.


In what follows, the available convective operator schemes are summarized.

**Attention:** The diffusion term is more or less a Laplacien operator and is thus always discretized by a centered difference scheme.

**Attention:** TRUST allows the user to neglect the operator contribution. This can be done by using the keyword **negligeable** in the concevtion and/or diffusion bloc.


## Finite Volume Difference (VDF) Schemes

| Scheme | Keyword | Description |
|--------|-----------|-------------|
| Upwind scheme | Amont | This is a first order upwind scheme. |
| Centered scheme | Centre or Centre4 | They correspond respectively to a second and fourth order cetered schemes. |
| QUICK scheme | Quick | This is the third order Quadratic Upstream Interpolation for Convective Kinematics (Quick) scheme. |

## Finite Element Volume (VEF) Schemes

| Scheme | Keyword | Description |
|--------|-----------|-------------|
| Upwind scheme | Amont | This is a first order upwind scheme. |
| Centered scheme | Centre or KCentre | This is a second order cetered scheme. |
| QUICK scheme | KQuick | This is the third order Quadratic Upstream Interpolation for Convective Kinematics (Quick) scheme. |
| EF-Stab scheme | EF_Stab | This scheme is an upwind/centered mixed schemes. The behavior is controlled by a parameter, alpha, where the scheme behaves as a pure upwind with alpha = 1 and centered with alpha = 0. |
| MUSCL scheme | Muscl | This is the second order Monotonic Upstream-centered Scheme for Conservation Laws (MUSCL) scheme. |

## PolyMAC-series Schemes

| Scheme | Keyword | Description |
|--------|-----------|-------------|
| Upwind scheme | Amont | This is a first order upwind scheme. |
| Centered scheme | Centre | This is a second order cetered scheme. |
| EF-Stab scheme | EF_Stab | This scheme is an upwind/centered mixed schemes. The behavior is controlled by a parameter, alpha, where the scheme behaves as a pure upwind with alpha = 1 and centered with alpha = 0. |