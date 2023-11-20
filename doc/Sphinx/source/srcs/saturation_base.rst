saturation_base
===============

**saturation_base**
-------------------
**Inherits from:** :ref:`saturation_base` 


Basic class for a liquid-gas interface (used in pb_multiphase)

----

**saturation_constant**
-----------------------
**Inherits from:** :ref:`saturation_base` 


Class for saturation constant

Parameters are:

- **[p_sat]**  (*type:* double) Define the saturation pressure value (this is a required parameter)

- **[t_sat]**  (*type:* double) Define the saturation temperature value (this is a required parameter)

- **[lvap]**  (*type:* double) Latent heat of vaporization

- **[hlsat]**  (*type:* double) Liquid saturation enthalpy

- **[hvsat]**  (*type:* double) Vapor saturation enthalpy


----

**saturation_sodium**
---------------------
**Inherits from:** :ref:`saturation_base` 


Class for saturation sodium

Parameters are:

- **[p_ref]**  (*type:* double) Use to fix the pressure value in the closure law. If not specified, the value of the pressure unknown will be used

- **[t_ref]**  (*type:* double) Use to fix the temperature value in the closure law. If not specified, the value of the temperature unknown will be used

