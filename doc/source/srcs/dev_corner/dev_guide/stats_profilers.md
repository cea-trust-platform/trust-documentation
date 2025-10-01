# Measuring performance in TRUST

A key feature for code optimisation is performance measurement. **TRUST** offer different solutions, using home-coded features or external libraries.

## Home coded counters

In order to obtain statistics on the performance of a test case, TRUST uses counters. This counters are managed by the Perf_counters class. The Perf_counters class follows a singleton pattern. The unique instance of Perf_counters can be called inside the code by using:

```
statistics()
```

Counters are seperated in two types:
- the standard counters used default in **TRUST** and identified by a `STD_COUNTERS` key,
- custom counters that can be created inside the code and that are identified by a `std::string`. 

`STD_COUNTERS` is an enum class.

| Key | Level | Description | Family | Is_communication | Is_gpu |
|-----|-------|-------------|--------|------------------|--------|
| total_execution_time | -1 | Total time | | | |
| computation_start_up | 0 | Computation start-up | | | |
| timeloop | 0 | Time loop | | | |
| backup_file | 0 | Back-up operations | | | |
| system_solver | 1 | Linear solver resolutions Ax=B | | | |
| petsc_solver | 2 | Petsc solver | | | |
| implicit_diffusion | 1 | Solver for implicit diffusion: | | | |
| compute_dt | 1 | Computation of the time step dt | | | |
| turbulent_viscosity | 1 | Turbulence model::update | | | |
| convection | 1 | Convection operator | | | |
| diffusion | 1 | Diffusion operator | | | |
| gradient | 1 | Gradient operator | | | |
| divergence | 1 | Divergence operator | | | |
| rhs | 1 | Source_terms | | | |
| postreatment | 1 | Post-treatment operations | | | |
| restart | 1 | Read file for restart | | | |
| matrix_assembly | 1 | Nb matrix assembly for implicit scheme: | | | |
| update_variables | 1 | Update ::mettre_a_jour | | | |
| mpi_sendrecv | 2 | MPI_send_recv | MPI_sendrecv | true | |
| mpi_send | 2 | MPI_send | MPI_sendrecv | true | |
| mpi_recv | 2 | MPI_recv | MPI_sendrecv | true | |
| mpi_bcast | 2 | MPI_broadcast | MPI_sendrecv | true | |
| mpi_alltoall | 2 | MPI_alltoall | MPI_sendrecv | true | |
| mpi_allgather | 2 | MPI_allgather | MPI_sendrecv | true | |
| mpi_gather | 2 | MPI_gather | MPI_sendrecv | true | |
| mpi_partialsum | 2 | MPI_partialsum | MPI_allreduce | true | |
| mpi_sumdouble | 2 | MPI_sumdouble | MPI_allreduce | true | |
| mpi_mindouble | 2 | MPI_mindouble | MPI_allreduce | true | |
| mpi_maxdouble | 2 | MPI_maxdouble | MPI_allreduce | true | |
| mpi_sumfloat | 2 | MPI_sumfloat | MPI_allreduce | true | |
| mpi_minfloat | 2 | MPI_minfloat | MPI_allreduce | true | |
| mpi_maxfloat | 2 | MPI_maxfloat | MPI_allreduce | true | |
| mpi_sumint | 2 | MPI_sumint | MPI_allreduce | true | |
| mpi_minint | 2 | MPI_minint | MPI_allreduce | true | |
| mpi_maxint | 2 | MPI_maxint | MPI_allreduce | true | |
| mpi_barrier | 2 | MPI_barrier | MPI_allreduce | true | |
| gpu_library | 2 | GPU_library | GPU_library | false | true |
| gpu_kernel | 2 | GPU_kernel | GPU_kernel | false | true |
| gpu_copytodevice | 2 | GPU_copyToDevice | GPU_copy | false | true |
| gpu_copyfromdevice | 2 | GPU_copyFromDevice | GPU_copy | false | true |
| gpu_malloc_free | 2 | GPU_allocations | GPU_alloc | false | true |
| interprete_scatter | 2 | Scatter_interprete | None | true | false |
| virtual_swap | 2 | DoubleVect/IntVect::virtual_swap | None | true | |
| read_scatter | 2 | Scatter::read_domaine | None | true | |
| parallel_meshing | 0 | Parallel meshing | | | |
| IO_EcrireFicPartageBin | 2 | write | IO | | |
| IO_EcrireFicPartageMPIIO | 2 | MPI_File_write_all | IO | | |

The basic API for counters in **TRUST** is as follows:


## External profilers

All of the presented profilers can be launch directly on a data file. To find the appropriate option to use them, run: 
```bash 
trust -h
```
The two following tools need [Hotspot](https://github.com/KDAB/hotspot) (gui) to be more effiently used. 

### Perf 

First, install the [Perf](https://perfwiki.github.io/main/) library if you don't have it yet. This tools is dedicated to CPU profiling. It will enable you to locate the main performance bottelnecks inside your code. 

### Heaptrack

First, install the [Heaptrack](https://github.com/KDE/heaptrack). This tool is dedicated to monitor memory usage (allocations: their number and size). It will enable you to find exessive allocations and possibly memory leaks. 

### Nsight system

Normally, [Nsight system](https://developer.nvidia.com/nsight-systems) is already available in **TRUST**. You can also install it alone or alongside the [Cuda Toolkit](https://developer.nvidia.com/cuda-toolkit). This tools is dedicated to GPU profiling. It will enable you to locate the main performance bottlenecks inside your code. It dedects the code not yet ported on GPU, and helps you vizualise the data copy between host and device memory. 



