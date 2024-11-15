VEF discretisation
==================

The VEF discretisation is based on a Finite Volumue Elements method, see [H03]_ and [LM05]_ . Three VEF are available in TRUST :

 - VEF_P0 : the full velocity vector is discretised at the face :math:`f` and the pressure at the cell :math:`e`
 - VEF_P1 : the full velocity vector is discretised at the face :math:`f` and the pressure at the vertexes :math:`v`
 - VEF_P0+P1 : the full velocity vector is discretised at the face :math:`f` and the pressure at the cell :math:`e` and at the vertexes :math:`v`.

.. figure:: ./FIGURES/VEF.png
        :name: fig:scheme_VEF
        :width: 400
	:align: center
	:alt: Unknowns in VEF 
	
	Location of the unknowns in VEF_P0+P1


