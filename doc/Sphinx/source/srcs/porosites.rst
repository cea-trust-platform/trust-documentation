porosites
=========

**porosites**
-------------
**Inherits from:** :ref:`porosites` 


To define the volume porosity and surface porosity that are uniform in every direction 
in space on a sub-area.

Porosity was only usable in VDF discretization, and now available for VEF P1NC/P0.

Observations :

- Surface porosity values must be given in every direction in space (set this value 
to 1 if there is no porosity),

- Prior to defining porosity, the problem must have been discretized.NL2 Can 't be 
used in VEF discretization, use Porosites_champ instead.

Parameters are:

- **aco**  (*type:* :ref:`chaine(into=["{"`) ] Opening curly bracket.

- **sous_zone | sous_zone1**  (*type:* string) Name of the sub-area to which porosity are allocated.

- **bloc**  (*type:* :ref:`bloc_lecture_poro`) Surface and volume porosity values.

- **[sous_zone2]**  (*type:* string) Name of the 2nd sub-area to which porosity are allocated.

- **[bloc2]**  (*type:* :ref:`bloc_lecture_poro`) Surface and volume porosity values.

- **acof**  (*type:* :ref:`chaine(into=["}"`) ] Closing curly bracket.

