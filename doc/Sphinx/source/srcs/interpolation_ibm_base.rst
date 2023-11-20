interpolation_ibm_base
======================

**interpolation_ibm_aucune**
----------------------------

**Synonyms:** ibm_aucune

**Inherits from:** :ref:`interpolation_ibm_base` 


Immersed Boundary Method (IBM): no interpolation.

Parameters are:

- **[impr]**  (*type:* flag) To print IBM-related data

- **[nb_histo_boxes_impr]**  (*type:* int) number of histogram boxes for printed data


----

**interpolation_ibm_base**
--------------------------
**Inherits from:** :ref:`interpolation_ibm_base` 


Base class for all the interpolation methods available in the Immersed Boundary Method 
(IBM).

Parameters are:

- **[impr]**  (*type:* flag) To print IBM-related data

- **[nb_histo_boxes_impr]**  (*type:* int) number of histogram boxes for printed data


----

**interpolation_ibm_elem_fluid**
--------------------------------

**Synonyms:** ibm_element_fluide, interpolation_ibm_element_fluide

**Inherits from:** :ref:`interpolation_ibm_base` 


Immersed Boundary Method (IBM): fluid element interpolation.

Parameters are:

- **points_fluides**  (*type:* :ref:`field_base`) Node field giving the projection of the point below (points_solides)  falling into the pure cell fluid

- **points_solides**  (*type:* :ref:`field_base`) Node field giving the projection of the node on the immersed boundary

- **elements_fluides**  (*type:* :ref:`field_base`) Node field giving the number of the element (cell) containing the pure  fluid point

- **correspondance_elements**  (*type:* :ref:`field_base`) Cell field giving the SALOME cell number

- **[impr]**  (*type:* flag) To print IBM-related data

- **[nb_histo_boxes_impr]**  (*type:* int) number of histogram boxes for printed data


----

**interpolation_ibm_hybride**
-----------------------------

**Synonyms:** ibm_hybride

**Inherits from:** :ref:`interpolation_ibm_base` 


Immersed Boundary Method (IBM): hybrid (fluid/mean gradient) interpolation.

Parameters are:

- **est_dirichlet**  (*type:* :ref:`field_base`) Node field of booleans indicating whether the node belong to an element  where the interface is

- **elements_solides**  (*type:* :ref:`field_base`) Node field giving the element number containing the solid point

- **points_fluides**  (*type:* :ref:`field_base`) Node field giving the projection of the point below (points_solides)  falling into the pure cell fluid

- **points_solides**  (*type:* :ref:`field_base`) Node field giving the projection of the node on the immersed boundary

- **elements_fluides**  (*type:* :ref:`field_base`) Node field giving the number of the element (cell) containing the pure  fluid point

- **correspondance_elements**  (*type:* :ref:`field_base`) Cell field giving the SALOME cell number

- **[impr]**  (*type:* flag) To print IBM-related data

- **[nb_histo_boxes_impr]**  (*type:* int) number of histogram boxes for printed data


----

**interpolation_ibm_mean_gradient**
-----------------------------------

**Synonyms:** interpolation_ibm_gradient_moyen, ibm_gradient_moyen

**Inherits from:** :ref:`interpolation_ibm_base` 


Immersed Boundary Method (IBM): mean gradient interpolation.

Parameters are:

- **points_solides**  (*type:* :ref:`field_base`) Node field giving the projection of the node on the immersed boundary

- **est_dirichlet**  (*type:* :ref:`field_base`) Node field of booleans indicating whether the node belong to an element  where the interface is

- **correspondance_elements**  (*type:* :ref:`field_base`) Cell field giving the SALOME cell number

- **elements_solides**  (*type:* :ref:`field_base`) Node field giving the element number containing the solid point

- **[impr]**  (*type:* flag) To print IBM-related data

- **[nb_histo_boxes_impr]**  (*type:* int) number of histogram boxes for printed data


----

**interpolation_ibm_power_law_tbl**
-----------------------------------

**Synonyms:** ibm_power_law_tbl

**Inherits from:** :ref:`interpolation_ibm_base` 


Immersed Boundary Method (IBM): power law interpolation.

Parameters are:

- **[formulation_linear_pwl]**  (*type:* int) Choix formulation lineaire ou non

- **points_fluides**  (*type:* :ref:`field_base`) Node field giving the projection of the point below (points_solides)  falling into the pure cell fluid

- **points_solides**  (*type:* :ref:`field_base`) Node field giving the projection of the node on the immersed boundary

- **elements_fluides**  (*type:* :ref:`field_base`) Node field giving the number of the element (cell) containing the pure  fluid point

- **correspondance_elements**  (*type:* :ref:`field_base`) Cell field giving the SALOME cell number

- **[impr]**  (*type:* flag) To print IBM-related data

- **[nb_histo_boxes_impr]**  (*type:* int) number of histogram boxes for printed data


----

**interpolation_ibm_power_law_tbl_u_star**
------------------------------------------

**Synonyms:** ibm_power_law_tbl_u_star

**Inherits from:** :ref:`interpolation_ibm_base` 


Immersed Boundary Method (IBM): law u star.

Parameters are:

- **points_solides**  (*type:* :ref:`field_base`) Node field giving the projection of the node on the immersed boundary

- **est_dirichlet**  (*type:* :ref:`field_base`) Node field of booleans indicating whether the node belong to an element  where the interface is

- **correspondance_elements**  (*type:* :ref:`field_base`) Cell field giving the SALOME cell number

- **elements_solides**  (*type:* :ref:`field_base`) Node field giving the element number containing the solid point

- **[impr]**  (*type:* flag) To print IBM-related data

- **[nb_histo_boxes_impr]**  (*type:* int) number of histogram boxes for printed data

