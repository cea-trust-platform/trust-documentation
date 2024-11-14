VDF discretisation
==================

The VDF discretisation is based on the Marker And Cell approach proposed in [HW65]_ and [HA68]_. This discretisation can only be used on Cartesian mesh.

When using VDF, the pressure is located at the cell :math:`e` whereas the normal component of the velocity is located at the face :math:`f`, see Figure :numref:`fig:scheme_VDF`

.. figure:: ./FIGURES/VDF-cut.png
        :name: fig:scheme_VDF
        :width: 400
	:align: center
	:alt: Unknowns in VDF
	
	Location of the unknowns in VDF
	 
