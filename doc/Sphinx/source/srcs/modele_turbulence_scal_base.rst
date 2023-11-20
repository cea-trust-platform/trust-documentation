modele_turbulence_scal_base
===========================

**modele_turbulence_scal_base**
-------------------------------
**Inherits from:** :ref:`modele_turbulence_scal_base` 


Basic class for turbulence model for energy equation.

Parameters are:

- **turbulence_paroi**  (*type:* :ref:`turbulence_paroi_scalaire_base`) Keyword to set the wall law.

- **[dt_impr_nusselt]**  (*type:* double) Keyword to print local values of Nusselt number and temperature near a  wall during a turbulent calculation. The values will be printed in the _Nusselt.face file each dt_impr_nusselt time period. The local Nusselt expression is as follows : Nu = ((lambda+lambda_t)/lambda)*d_wall/d_eq  where d_wall is the distance from the first mesh to the wall and d_eq is given by  the wall law. This option also gives the value of d_eq and h = (lambda+lambda_t)/d_eq and the fluid  temperature of the first mesh near the wall.  For the Neumann boundary conditions (flux_impose), the <<equivalent>> wall temperature  given by the wall law is also printed (Tparoi equiv.) preceded for VEF calculation  by the edge temperature <<T face de bord>>.


----

**modele_turbulence_scal_nul**
------------------------------

**Synonyms:** null

**Inherits from:** :ref:`modele_turbulence_scal_base` 


Nul scalar turbulence model (turbulent diffusivity = 0) which can be used with a turbulent 
problem.

Parameters are:

- **[dt_impr_nusselt]**  (*type:* double) Keyword to print local values of Nusselt number and temperature near a  wall during a turbulent calculation. The values will be printed in the _Nusselt.face file each dt_impr_nusselt time period. The local Nusselt expression is as follows : Nu = ((lambda+lambda_t)/lambda)*d_wall/d_eq  where d_wall is the distance from the first mesh to the wall and d_eq is given by  the wall law. This option also gives the value of d_eq and h = (lambda+lambda_t)/d_eq and the fluid  temperature of the first mesh near the wall.  For the Neumann boundary conditions (flux_impose), the <<equivalent>> wall temperature  given by the wall law is also printed (Tparoi equiv.) preceded for VEF calculation  by the edge temperature <<T face de bord>>.

