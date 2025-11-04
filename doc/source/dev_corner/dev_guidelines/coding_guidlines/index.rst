Coding guidlines
================

Naming conventions
------------------

* Class members are suffixed with an underscore 
* Static methods start with an upper case

Bracketing
----------
* Do not use unnecessary brackets

One-liners
----------

* For loops and if statement should be on separate lines 

Comments
--------

* A doxygen type comment must be added at the beginning of each method, so that the automaticaly generated documentation stays up to date. Here is an example:

.. code-block:: cpp

	/*! @brief Computes field gradient interpolation at faces while preserving constant fields
 	*
 	* This method computes the interpolation [n_f.grad T]_f (if nu_grad = 0) or [n_f.nu.grad T]_f
 	* while exactly preserving fields satisfying [nu grad T]_e = constant.
 	* It uses MPFA (Multi-Point Flux Approximation) methods with three strategies:
 	*       - Attempt 0: Standard MPFA-O
 	*       - Attempt 1: MPFA-eta: variant of MPFA-O where auxiliary variables are not in the barycenter of the face
 	*       - Attempt 2: Symmetric MPFA if previous attempts fail (coercive but not always consistent, especially on complex meshes)
 	*
 	* @param N             Number of field components
 	* @param is_p          Pressure field indicator (1 for pressure, 0 otherwise)
 	*                      Controls Neumann/Dirichlet inversion for boundary conditions
 	* @param cls           Domain boundary conditions
 	* @param fcl           Boundary condition data
 	*                      fcl(f, 0/1/2): (BC type, BC index, index within BC)
 	*                      See Champ_{P0,Face}_PolyMAC_P0 for format
 	* @param nu            Element diffusivity (optional, can be nullptr)
 	*                      Array nu(e, n, ..) for element e and component n
 	* @param som_ext       List of vertices to exclude from processing (optional)
 	*                      Example: direct treatment of Echange_Contact in Op_Diff_PolyMAC_P0_Elem
 	* @param virt          Virtual faces indicator (1 to include, 0 otherwise)
 	* @param full_stencil  Complete stencil indicator (1 for full dimensioning)
 	*
 	* @param[out] phif_d   Start/end indices in phif_{e,c} / phif_{pe,pc}
	*                      phif_d(f, 0/1): flux indices at face f in interval
 	*                      [phif_d(f, 0/1), phif_d(f + 1, 0/1)[
 	* @param[out] phif_e   Element indices in stencil for each contribution
 	*                      phif_e(i): element index for i-th contribution
 	* @param[out] phif_c   Stencil coefficients
 	*                      phif_c(i, n, c): coefficient for element i, component n, contribution c
 	*                      Contains local indices/coefficients (without Echange_contact)
 	*                      and diagonal terms (independent components)
 	*
 	* @note The method checks positivity of bilinear form eigenvalues to ensure scheme stability and choose the MPFA method accordingly
 	*
 	* @note The method returns also a percentage of which MPFA method is used. Be careful of the validity of the solution if the percentage of MPFA-sym is high
 	*
 	* @note Special handling for different boundary condition types:
 	*       - Dirichlet/Neumann
 	*       - Imposed global/external friction
 	*       - Imposed global/external exchange
 	*
 	*/
	void Domaine_PolyMAC_P0::fgrad(int N, int is_p, const Conds_lim& cls, const IntTab& fcl, const DoubleTab *nu, const IntTab *som_ext, int virt, int full_stencil, IntTab& phif_d, IntTab& phif_e, DoubleTab& phif_c) const
	


Doxygen Commands Reference
^^^^^^^^^^^^^^^^^^^^^^^^^^

Common Doxygen commands that work well with Sphinx:

.. list-table:: Doxygen Commands
   :header-rows: 1
   :widths: 20 80

   * - Command
     - Description
   * - ``@brief``
     - Short description (one line)
   * - ``@param[in]``
     - Input parameter description
   * - ``@param[out]``
     - Output parameter description
   * - ``@param[in,out]``
     - Input/output parameter description
   * - ``@return`` / ``@returns``
     - Return value description
   * - ``@retval``
     - Specific return value meaning
   * - ``@throw`` / ``@throws``
     - Exception that may be thrown
   * - ``@pre``
     - Precondition
   * - ``@post``
     - Postcondition
   * - ``@note``
     - Important note
   * - ``@warning``
     - Warning message
   * - ``@see``
     - Reference to related items
   * - ``@since``
     - Version information
   * - ``@deprecated``
     - Deprecation notice
   * - ``@code`` / ``@endcode``
     - Code example block
   * - ``@author``
     - Author information
   * - ``@date``
     - Date information
   * - ``@version``
     - Version information

Best Practices
^^^^^^^^^^^^^^

1. **Always use @brief**: Start with a concise one-line description
2. **Document all parameters**: you can also use @param[in/out/in,out] tags for a more precise doxygen
3. **Specify return values**: Use @return and @retval for clarity
4. **Add cross-references if needed**: Use @see to link related functions/classes
