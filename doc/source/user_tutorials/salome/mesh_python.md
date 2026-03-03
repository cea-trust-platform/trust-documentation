# Editing and Building Meshes with Python Scripts

## Overview

SALOME can save all GUI operations as a Python script. This allows you to:
- Modify geometry and mesh parameters without rebuilding from scratch
- Automate mesh generation
- Version-control your meshing workflow

## Setup

```bash
mkdir -p TRUST_TUTORIALS/salome/exo5
cd TRUST_TUTORIALS/salome/exo5
```

## Copying the Python Script

Copy the Python script from the previous exercise:

```bash
cp ../exo4/Mesh_1.py .
cp $TRUST_ROOT/doc/TRUST/exercices/salome/Coupled_pb.data .
```

**Note:** If you have not completed the previous exercise:

```bash
path=$TRUST_ROOT/doc/TRUST/exercices/salome
cp $path/Coupled_pb.py Mesh_1.py
```

## Editing the Python Script

Open `Mesh_1.py` in a text editor and make the following changes:

- **Add a mesh export command** at the end of the script:
   ```python
   Mesh_1.ExportMED("Mesh_1.med", 0)
   ```

- **Modify the geometry parameters:**
  - Change box and cylinder height: `400` → `300`
  - Change cylinder radius: `40` → `70`

- **Modify the mesh parameters in `NETGEN_3D_Parameters_1`:**
  - MaxSize: `48.9898` → `9.`
  - MinSize: `6.97246` → `2.`

- **Save and close** the file

## Generating the New Mesh

Run the Python script in SALOME's terminal mode:

```bash
$PathToSALOME/salome -t Mesh_1.py
```

The file `Mesh_1.med` will be generated in your folder. You will notice:
- The box is smaller in the z-direction
- The cylinder is thicker
- The mesh is finer

## Running the Calculation

Run TRUST with the new mesh:

```bash
trust Coupled_pb
```

## Advantages of the Python Workflow

- **Reproducibility:** Scripts document your exact meshing process
- **Parametric studies:** Parameters can be easily modified for sensitivity analyses
- **Automation:** Can be integrated into larger workflows
- **Version control:** Scripts can be tracked with Git or other VCS tools
- **Batch processing:** Multiple meshes with different parameters can be generated automatically