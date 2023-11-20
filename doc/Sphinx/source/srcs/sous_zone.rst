sous_zone
=========

**sous_zone**
-------------

**Synonyms:** sous_domaine

**Inherits from:** :ref:`sous_zone` 


It is an object type describing a domain sub-set.

A Sous_Zone (Sub-area) type object must be associated with a Domaine type object.
The Read (Lire) interpretor is used to define the items comprising the sub-area.

Caution: The Domain type object nom_domaine must have been meshed (and triangulated 
or tetrahedralised in VEF) prior to carrying out the Associate (Associer) nom_sous_zone 
nom_domaine instruction; this instruction must always be preceded by the read instruction.

Parameters are:

- **[restriction]**  (*type:* :ref:`sous_zone`) The elements of the sub-area nom_sous_zone must be included into the  other sub-area named nom_sous_zone2. This keyword should be used first in the Read keyword.

- **[rectangle]**  (*type:* :ref:`bloc_origine_cotes`) The sub-area will include all the domain elements whose centre  of gravity is within the Rectangle (in dimension 2).

- **[segment]**  (*type:* :ref:`bloc_origine_cotes`) not_set

- **[boite | box]**  (*type:* :ref:`bloc_origine_cotes`) The sub-area will include all the domain elements whose centre  of gravity is within the Box (in dimension 3).

- **[liste]**  (*type:* int list) The sub-area will include n domain items, numbers No. 1 No. i No. n.

- **[fichier | filename]**  (*type:* string) The sub-area is read into the file filename.

- **[intervalle]**  (*type:* :ref:`deuxentiers`) The sub-area will include domain items whose number is between n1 and  n2 (where n1<=n2).

- **[polynomes]**  (*type:* :ref:`bloc_lecture`) A REPRENDRE

- **[couronne]**  (*type:* :ref:`bloc_couronne`) In 2D case, to create a couronne.

- **[tube]**  (*type:* :ref:`bloc_tube`) In 3D case, to create a tube.

- **[fonction_sous_zone | fonction_sous_domaine]**  (*type:* string) Keyword to build a sub-area with the the elements included into the area  defined by fonction>0.

- **[union | union_with]**  (*type:* :ref:`sous_zone`) The elements of the sub-area nom_sous_zone3 will be added to the sub-area  nom_sous_zone. This keyword should be used last in the Read keyword.

