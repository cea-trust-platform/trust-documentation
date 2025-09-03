# Solver and Preconditioners 

Linear matricial systems appear basically with a form of **AX = B** at two stages in the code resolution algorithm: when dealing with the Elliptic pressure Poisson equation at first, and when dealing with the implicit resolution at second (either diffusion implicit or a full implicit time integration scheme).

The platform TRUST allows the use of a wide range of solvers/preconditioners in order to solve such linear systems. Ttwo types of solvers are mainly available: either home-coded ones or called from external libraries, for example from the open source **[PETSc](https://petsc.org/release/install/license/#doc-license)** library. As stated previously, TRUST has been ported recently to support GPU acceleration (NVidia/AMD). The solvers are the main candidates that benefit from this new advantage.

In cases where the user asks to treat implicitly the diffusion operator in an explicit time integration scheme, a Preconditioned Conjugate Gradient (GCP) solver will be used (by default) to solve the implicit matrix. However, it is possible to select a specific solver. These instances are optional and can be inserted in the bloc of each equation.

If a pure implicit scheme is used in a TRUST calculation, an implicit solver **must** be defined too. This is done via the keyword **Solveur**.

## Linear Solvers

### External solvers

| External Library | Solver | Description |
|------------------|--------|-------------|
| PETSc | GCP | Preconditioned Conjugate Gradient. |
| PETSc | GMRES | Generalized Minimal Residual. |
| PETSc | BICGSTAB | Stabilized Bi-Conjugate Gradient. |
| PETSc | CHOLESKY | Parallel LU or Cholesky decomposition |
| PETSc | CHOLESKY_UMFPACK | Sequential Cholesky from UMFPACK library (seems fast). |
| PETSc | CLI | Command Line Interface. Should be used only by advanced users, to access the whole solver/preconditioners from the PETSC API. To find all the available options, run your calculation with the -ksp_view -help options (Krylov Method Options). |
| AmgX | AMGX | GPU solver via AmgX API, for Nvidia only. |
| PETSc GPU | PETSc_GPU | GPU solver via PETSc API. |
| cuDSS | Cholesky or LU | GPU direct solver for Nvidia only. |

### Direct home-coded solvers

| Solver | Description |
|--------|-------------|
| Cholesky | Cholesky direct method. |

### Iterative home-coded solvers

| Solver | Description |
|--------|-------------|
| GCP | Preconditioned Conjugate Gradient. |
| GMRES | Gmres method (for non symetric matrix). |
| GEN | Generic solver. |


## Pre-Conditioners

### External pre-conditioners

| Pre-conditioner | Parameters | Description |
|-----------------|------------|-------------|
| NULL { } | - | No preconditioner used. |
| DIAG { } | - | Diagonal (Jacobi) preconditioner. |
| BOOMERAMG { } | - | Multigrid preconditioner (no option is available yet, look at CLI command and Petsc documentation to try other options). |
| BLOCK_JACOBI_ICC { level k ordering natural \| rcm } | level k (default: 1), ordering: natural or rcm | Incomplete Cholesky factorization for symmetric matrix with the PETSc implementation. The integer k is the factorization level (default value, 1). In parallel, the factorization is done by block (one per processor by default). The ordering of the local matrix is natural by default, but rcm ordering, which reduces the bandwith of the local matrix, may interestingly improves the quality of the decomposition and reduces the number of iterations. |
| SSOR { omega double } | omega (default: 1.5) | Symmetric Successive Over Relaxation algorithm. omega (default value, 1.5) defines the relaxation factor. |


### Home-coded pre-conditioners

| Pre-conditioner | Description |
|-----------------|-------------|
| ILU | Can be only used with the generic GEN solver. |
| SSOR | Symmetric successive over-relaxation algorithm. |

## Implicit Solvers

### Linear Solvers

| Solver | Description |
|--------|-------------|
| Solveur_lineaire_std | Standard linear solver. |

### Non-Linear Solvers

| Solver | Full Name | Description |
|--------|-----------|-------------|
| Implicite | - | Similar to PISO, but as it looks like a simplified solver, it will use fewer timesteps. But it may run faster because the pressure matrix is not re-assembled and thus provides CPU gains. |
| Simple | Semi-Implicit Method for Pressure Linked Equations (SIMPLE) | Type algorithm, see **[CT Shaw](https://onlinelibrary.wiley.com/doi/pdf/10.1002/fld.1650120106)**. |
| Simpler | Semi-Implicit Method for Pressure Linked Equations Revised (SIMPLER) | Method for incompressible systems, see **[DS Jang](https://www.tandfonline.com/doi/abs/10.1080/10407788608913517)**. |
| Piso | Pressure Implicit with Split Operator (PISO) | A method to solve the implicit Navier-Stokes equation, see **[RI Issa](https://www.sciencedirect.com/science/article/pii/0021999186900999)**. |
| SETS | Stability-Enhancing Two-Step (SETS) | Solver which is useful for a multiphase problem, see **[JH Mahaffy](https://www.sciencedirect.com/science/article/pii/0021999182900195)**. |
| ICE | Implicit Continuous-fluid Eulerian | Solver which is useful for a multiphase problem. Robust pressure reduction resolution. See **[FH Harlow](https://www.sciencedirect.com/science/article/pii/0021999171900027)**. |
| Solveur_U_P | - | Similar to simple. |

### Advices

Here are some general advices regarding **TRUST** solvers:

**For constant sparse symmetric matices**, such as the one of the pressure linear system of incompressible flow:
	
- use GCP with Algebric Multigrid (AMG GCP) preconditioning.

**For non-constant sparse symmetric matices**, such as the one of the pressure linear system of quasi compressible flow or two-phase
flow  solved by front tracking models:

- use GCP with SSOR preconditioning from PETSc (PETSc GCP).


**For non-constant sparse non-symmetric matices**, solved during implicit time schemes:

- use GMRES or BICGSTAB with Jacobi preconditioner (diag).

**For non-constant sparse potentially ill-conditioned matrices**, for instance the one obtained from multiphase flow:

- use direct method, typically PETSc Cholesky, that will either use LU or Cholesky according to the matrix conditioning.

### Selected Examples

**Pressure solver examples**
```bash
Solveur_pression PETSc GCP { precond SSOR { omega 1.6 }  seuil 1.e-12 impr   }

Solveur_pression AMG GCP {  atol 1.e-12 impr   }	

Solveur_pression PETSc Cholesky { }

solveur Gen { seuil 1e-8 solv_elem BiCGStab precond ILU { type 2 filling 20 }  }
```
**Diffusion implicit solver example**
```bash
Parametre_equation Parametre_diffusion_implicite
{
	Solveur PETSc GCP { precond block_jacobi_ilu { level 0 } rtol 1.e-13 impr }
}
```
**Implicit solver example**
```bash		
Solveur Implicite
{
	Solveur PETCs GMRES { precond DIAG { } rtol 1e-3 impr }
}
```

```bash		
Solveur Implicite
{
	solveur gmres { diag seuil 1.e-8 nb_it_max 3 impr }
}
```

```bash		
Solveur Implicite
{
	Solveur PETSc CLI
	{
		-pc_type hypre
		-pc_hypre_type boomeramg
		-pc_hypre_boomeramg_strong_threshold 0.8
		-pc_hypre_boomeramg_agg_nl 4
		-pc_hypre_boomeramg_agg_num_paths 5
		-pc_hypre_boomeramg_max_levels 25
		-pc_hypre_boomeramg_coarsen_type PMIS
		-pc_hypre_boomeramg_interp_type ext+i
		-pc_hypre_boomeramg_P_max 2
		-pc_hypre_boomeramg_truncfactor 0.5
		-ksp_type fgmres
	}
}
```
```bash	
	Solveur Sets
	{
		criteres_convergence { alpha 1e-5 pression 1. vitesse 1e-5 temperature 1e8 k 1e-5 omega 1e-5 }
		iter_min 2
		Solveur PETSc CLI { }
		seuil_convergence_implicite 1e30
	}
```
```bash	    
	Solveur Implicite 
	{
		seuil_convergence_implicite 1e+0
		seuil_convergence_solveur  1e-4
		Solveur Gen { seuil 1e-8 solv_elem BiCGStab precond ILU { type 2 filling 20 }  }
		# Solveur GMRES { diag seuil 1e-8 impr } #
	}
```
