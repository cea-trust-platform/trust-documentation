VEF discretisation
==================

The VEF discretisation is based on Finite Elements methods. Three VEF are available in TRUST :

 - VEF_P0 : the full velocity vector is discretised at the face :math:`f` and the pressure at the cell :math:`e`
 - VEF_P1 : the full velocity vector is discretised at the face :math:`f` and the pressure at the vertexes :math:`v`
 - VEF_P0+P1 : the full velocity vector is discretised at the face :math:`f` and the pressure at the cell :math:`e` and at the vertexes :math:`v`.

.. _scheme_VDF:
.. figure:: ./FIGURES/VEF.png
        :width: 400
	:align: center
	:alt: Unknowns in VEF 
	
	Figure B: Location of the unknowns in VEF_P0+P1


