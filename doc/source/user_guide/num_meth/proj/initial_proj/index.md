Description of the initial projection
-------------------------------------

In TRUST, initial pressure is not required. The determination of the initial pressure is done in `Navier_Stokes_std::preparer_calcul`. 
The idea is similar to the correction step of the Chorin algorithm. 

We need to find the inital pressure which corrects the initial velocity to be divergence free. Ideed, even if the initial velocity in globally divergence free, it does not imply that the initial velocity is divergence free at each cells of the mesh. Let's define $U^{ini}$ as the initial velocity given by the user and $U^0$ the real velocity used to lauch the algorithm in TRUST. The velocity $U^0$ verifies the following system: 

$$
	\begin{aligned}
	\mathbb{M}\frac{U^0-U^{ini}}{\delta t^0} + \mathbb{B}^t P^0 = 0\\
	\mathbb{B}U^0 = 0
	\end{aligned}
$$

Multiplying by $\mathbb{B}\mathbb{M}^{-1}$, the initial pressure can be computed solving the following system: 

$$
	\delta t^0 \mathbb{B} \mathbb{M}^{-1} \mathbb{B}^t P^0 = \mathbb{B}U^{ini}
$$

Than, we can compute the initial velocity $U^0= U^{ini} - \delta t^0 \mathbb{B}^t P^0$. Some keywords can be set in order to modify the initial pressure system (we can impose an initial pressure or use the source term to find the right pressure). 

Once the initial values of velocity and pressure have been determined, we can compute the projection algorithms. 