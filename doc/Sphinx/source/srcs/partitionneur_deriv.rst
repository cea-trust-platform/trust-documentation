partitionneur_deriv
===================

**partitionneur_deriv**
-----------------------
**Inherits from:** :ref:`partitionneur_deriv` 


not_set

Parameters are:

- **[nb_parts]**  (*type:* int) The number of non empty parts that must be generated (generally equal to  the number of processors in the parallel run).


----

**partitionneur_fichier_decoupage**
-----------------------------------

**Synonyms:** fichier_decoupage

**Inherits from:** :ref:`partitionneur_deriv` 


This algorithm reads an array of integer values on the disc, one value for each mesh 
element.
Each value is interpreted as the target part number n>=0 for this element.
The number of parts created is the highest value in the array plus one.
Empty parts can be created if some values are not present in the array.

The file format is ASCII, and contains space, tab or carriage-return separated integer 
values.
The first value is the number nb_elem of elements in the domain, followed by nb_elem 
integer values (positive or zero).

This algorithm has been designed to work together with the 'ecrire_decoupage' option.
You can generate a partition with any other algorithm, write it to disc, modify it, 
and read it again to generate the .Zone files.

Contrary to other partitioning algorithms, no correction is applied by default to 
the partition (eg.
element 0 on processor 0 and corrections for periodic boundaries).
If 'corriger_partition' is specified, these corrections are applied.

Parameters are:

- **fichier**  (*type:* string) FILENAME

- **[corriger_partition]**  (*type:* flag) not_set

- **[nb_parts]**  (*type:* int) The number of non empty parts that must be generated (generally equal to  the number of processors in the parallel run).


----

**partitionneur_fichier_med**
-----------------------------

**Synonyms:** fichier_med

**Inherits from:** :ref:`partitionneur_deriv` 


Partitioning a domain using a MED file containing an integer field providing for each 
element the processor number on which the element should be located.

Parameters are:

- **file**  (*type:* string) file name of the MED file to load

- **field**  (*type:* string) field name of the integer field to load

- **[nb_parts]**  (*type:* int) The number of non empty parts that must be generated (generally equal to  the number of processors in the parallel run).


----

**partitionneur_metis**
-----------------------

**Synonyms:** metis

**Inherits from:** :ref:`partitionneur_deriv` 


Metis is an external partitionning library.
It is a general algorithm that will generate a partition of the domain.

Parameters are:

- **[kmetis]**  (*type:* flag) The default values are pmetis, default parameters are automatically chosen  by Metis. 'kmetis' is faster than pmetis option but the last option produces better partitioning  quality. In both cases, the partitioning quality may be slightly improved by increasing the  nb_essais option (by default N=1). It will compute N partitions and will keep the best one (smallest edge cut number). But this option is CPU expensive, taking N=10 will multiply the CPU cost of partitioning  by 10.  Experiments show that only marginal improvements can be obtained with non default  parameters.

- **[use_weights]**  (*type:* flag) If use_weights is specified, weighting of the element-element links in the  graph is used to force metis to keep opposite periodic elements on the same processor. This option can slightly improve the partitionning quality but it consumes more memory  and takes more time. It is not mandatory since a correction algorithm is always applied afterwards to  ensure a correct partitionning for periodic boundaries.

- **[nb_parts]**  (*type:* int) The number of non empty parts that must be generated (generally equal to  the number of processors in the parallel run).


----

**partitionneur_partition**
---------------------------

**Synonyms:** decouper, partition

**Inherits from:** :ref:`partitionneur_deriv` 


This algorithm re-use the partition of the domain named DOMAINE_NAME.
It is useful to partition for example a post processing domain.
The partition should match with the calculation domain.

Parameters are:

- **domaine**  (*type:* :ref:`domaine`) domain name

- **[nb_parts]**  (*type:* int) The number of non empty parts that must be generated (generally equal to  the number of processors in the parallel run).


----

**partitionneur_sous_dom**
--------------------------

**Synonyms:** sous_dom

**Inherits from:** :ref:`partitionneur_deriv` 


Given a global partition of a global domain, 'sous-domaine' allows to produce a conform 
partition of a sub-domain generated from the bigger one using the keyword create_domain_from_sous_domaine.
The sub-domain will be partitionned in a conform fashion with the global domain.

Parameters are:

- **fichier**  (*type:* string) fichier

- **fichier_ssz**  (*type:* string) fichier sous zonne

- **[nb_parts]**  (*type:* int) The number of non empty parts that must be generated (generally equal to  the number of processors in the parallel run).


----

**partitionneur_sous_domaines**
-------------------------------

**Synonyms:** partitionneur_sous_zones

**Inherits from:** :ref:`partitionneur_deriv` 


This algorithm will create one part for each specified subdomaine/domain.
All elements contained in the first subdomaine/domain are put in the first part, 
all remaining elements contained in the second subdomaine/domain in the second part, 
etc...

If all elements of the current domain are contained in the specified subdomaines/domain, 
then N parts are created, otherwise, a supplemental part is created with the remaining 
elements.

If no subdomaine is specified, all subdomaines defined in the domain are used to 
split the mesh.

Parameters are:

- **[sous_zones]**  (*type:* string list) N SUBZONE_NAME_1 SUBZONE_NAME_2 ...

- **[domaines]**  (*type:* string list) N DOMAIN_NAME_1 DOMAIN_NAME_2 ...

- **[nb_parts]**  (*type:* int) The number of non empty parts that must be generated (generally equal to  the number of processors in the parallel run).


----

**partitionneur_sous_zones**
----------------------------

**Synonyms:** partitionneur_sous_domaines, sous_zones

**Inherits from:** :ref:`partitionneur_deriv` 


This algorithm will create one part for each specified subzone.
All elements contained in the first subzone are put in the first part, all remaining 
elements contained in the second subzone in the second part, etc...

If all elements of the domain are contained in the specified subzones, then N parts 
are created, otherwise, a supplemental part is created with the remaining elements.

If no subzone is specified, all subzones defined in the domain are used to split 
the mesh.

Parameters are:

- **sous_zones**  (*type:* string list) N SUBZONE_NAME_1 SUBZONE_NAME_2 ...

- **[nb_parts]**  (*type:* int) The number of non empty parts that must be generated (generally equal to  the number of processors in the parallel run).


----

**partitionneur_tranche**
-------------------------

**Synonyms:** tranche

**Inherits from:** :ref:`partitionneur_deriv` 


This algorithm will create a geometrical partitionning by slicing the mesh in the 
two or three axis directions, based on the geometric center of each mesh element.
nz must be given if dimension=3.
Each slice contains the same number of elements (slices don't have the same geometrical 
width, and for VDF meshes, slice boundaries are generally not flat except if the number 
of mesh elements in each direction is an exact multiple of the number of slices).
First, nx slices in the X direction are created, then each slice is split in ny slices 
in the Y direction, and finally, each part is split in nz slices in the Z direction.
The resulting number of parts is nx*ny*nz.
If one particular direction has been declared periodic, the default slicing (0, 1, 
2, ..., n-1)is replaced by (0, 1, 2, ...
n-1, 0), each of the two '0' slices having twice less elements than the other slices.

Parameters are:

- **[tranches]**  (*type:* int list - size is dimension) Partitioned by nx in the X direction, ny in the Y direction, nz in the  Z direction. Works only for structured meshes. No warranty for unstructured meshes.

- **[nb_parts]**  (*type:* int) The number of non empty parts that must be generated (generally equal to  the number of processors in the parallel run).


----

**partitionneur_union**
-----------------------

**Synonyms:** union

**Inherits from:** :ref:`partitionneur_deriv` 


Let several local domains be generated from a bigger one using the keyword create_domain_from_sous_domaine, 
and let their partitions be generated in the usual way.
Provided the list of partition files for each small domain, the keyword 'union' will 
partition the global domain in a conform fashion with the smaller domains.

Parameters are:

- **liste**  (*type:* :ref:`bloc_lecture`) List of the partition files with the following syntaxe: {sous_domaine1  decoupage1 ... sous_domaineim decoupageim } where sous_domaine1 ... sous_zomeim are small domains names and decoupage1 ... decoupageim are partition files.

- **[nb_parts]**  (*type:* int) The number of non empty parts that must be generated (generally equal to  the number of processors in the parallel run).

