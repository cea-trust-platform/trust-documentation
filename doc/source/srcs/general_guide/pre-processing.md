## Pre-Processing

It is not possible to perform a TRUST simulation **without** defining a domain on which an Eulerian mesh is hosted. The Domaine object is so easy to instantiate, thanks to the C++ class `Domaine`. 

Click **[here](https://cea-trust-platform.github.io/TRUST_Doxygen.github.io/html/classDomaine.html)** to see the Doxygen documentation of the `Domaine` class.

The famous classes that can be used to read/construct a mesh in a TRUST calculation are the classes `Mailler`, `Read_File` and `Read_MED`. Here is a short documentation of the three classes. You are kindly invited to check out the TRUST generic documentation for a complete description of all possible methods.

TRUST offers the user the possibility to post-process the domain/mesh before running the calculation. This can help in detecting if the mesh to be used in the simulation has some issues. In order to visualize the domain, you can use the class `Postrtaiter_domaine`. The arguments passed to this class are the domain's name, the output file name (to visualize) and the format. See the Post-Processing section for more information regarding the available formats. Click **[here](https://cea-trust-platform.github.io/TRUST_Doxygen.github.io/html/classPostraiter__domaine.html)** to see the Doxygen documentation of this class.

**Attention:** The names given at the boundaries of the mesh should be exactly used in the boundary conditions of each equation, otherwise TRUST will throw an error.

### Mailler

The C++ class `Mailler` is a basic home-made mesh generator that can be used for simple geometries. The algorithm works by assembling hexa-hedral blocs inside a user defined domain limits. The border of the mesh should be explicitly and carefuly defined otherwise TRUST will throw an error. Click **[here](https://cea-trust-platform.github.io/TRUST_Doxygen.github.io/html/classMailler.html)** to see the Doxygen documentation of this class.

Inside the `Mailler` block, at least one instance of the `Pave` class should be created. In this block, the user should define the limts of his domain; basically the origin, the length and the number of nodes per direction. Click **[here](https://cea-trust-platform.github.io/TRUST_Doxygen.github.io/html/classPave.html)** to see the Doxygen documentation of this class.

The generated mesh is by default uniform in all directions (see next figure for example). However, it is possible to generate a non-uniform mesh, basically via a hyperbolic-tangent distribution. This is done by adding additional parameters in the `Pave` bloc. 

<style>
td, th {
   border: none!important;
}
</style>

| |
| :---: |
| <img src="https://github.com/cea-trust-platform/cea-trust-platform.github.io/blob/master/images/illustrations/mesh_gamelan.png?raw=true" alt="GAMELAN" width="600"/> | 
|*Example of a 2D geometry meshed with the TRUST Mailler class. Here, 6 blocks (Pave class) are used: 3 cavities, 2 vents and a pipe. Mailler class merges and raccords the 6 blocs.* |

TRUST offers the possibility to modify the generated mesh and to perform specific operations. For example, it is possible to merge or rename the boundaries, create groups, clean nodes, refine the mesh, dilate, rotate, transform, etc ... It is also possible to polyhedrise the elemnts (change the type of the hexas to be able to use the PolyMAC discretization for example). Since certain discretizations accept only tetrahedral elements (triangles in 2D), TRUST offers the possibility to split the hexas into tetras (see the next figure for example).

| |
| :---: |
| <img src="https://github.com/cea-trust-platform/cea-trust-platform.github.io/blob/master/images/illustrations/mesh_gamelan2.png?raw=true" alt="GAMELAN" width="600"/> | 
|*Example of a 2D geometry meshed with the TRUST Mailler class followed by splitting the rectangles to triangles.* |

Detailed information can be found in the TRUST documentation. Have a look to all the classes that inherits from `Interprete_geometrique_base` and `Interprete` (the second is a bit more general).

Here is an example illustrating the use of the `Mailler` and `Pave` classes.

	# Define the dimension of the desired simulation #
	Dimension 2
	
	# Define a domain #
	Domaine dom
	
	# Mesh the defined domain #
	Mailler dom
	{
	    Pave carre
	    {
	        origine  0.0  0.0
	        nombre_de_noeuds  50 35
	        longueurs 1 1
	    }
	    
	    {
			# Define 4 BC : bas, haut, gauche and droite #
	        bord  bas       Y = 0.0    0.0 <= X <= 1.0
	        bord  haut      Y = 1.0    0.0 <= X <= 1.0
	        bord  gauche    X = 0.0    0.0 <= Y <= 1.0
	        bord  droite    X = 1.0    0.0 <= Y <= 1.0
	    }
	}
	
	# Apply a transformation #
	Transformer dom x*0.5 y
	
### Read_MED

The C++ class is `Read_MED` (or `Lire_MED`). This keyword allows reading a mesh from a MED file (MED is a format) defined on a domain. Click **[here](https://cea-trust-platform.github.io/TRUST_Doxygen.github.io/html/classLireMED.html)** to see the Doxygen documentation of this class.

Such a MED file can be generated by the platform **[SALOME](https://www.salome-platform.org/?lang=fr)**, **[MEDCoupling](https://docs.salome-platform.org/latest/dev/MEDCoupling/developer/index.html)** or **[GMSH](https://gmsh.info/)** for example. The syntax is thus the following

	Read_MED { domain dom file mesh.med }

**Attention:** Note about naming your boundaries. When reading a MED file, TRUST will detect boundaries between domains (`Raccord`) when the name of the boundary begins by `type_raccord_`. For example, a boundary named `type_raccord_wall`  will be considered by TRUST as a boundary named **wall** between two domains. Or, you can apply keyword `modifie_bord_to_raccord`

### Read_File

The C++ class is `Read_File` (or `Lire_Fichier`). This keyword allows reading the object name_obj contained in the file filename (name_obj is the name of the meshed domain). This class is notably used when the calculation domain has already been meshed and the mesh contains the file filename. Click **[here](https://cea-trust-platform.github.io/TRUST_Doxygen.github.io/html/classLire__Fichier.html)** to see the Doxygen documentation of this class.


The syntax is thus the following

	Read_file name_obj filename ;
