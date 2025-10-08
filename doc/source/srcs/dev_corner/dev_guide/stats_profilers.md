# Measuring performance in TRUST

A key feature for code optimisation is performance measurement. **TRUST** offer different solutions, using home-coded features or external libraries.

## Home coded counters

In order to obtain statistics on the performance of a test case, TRUST uses counters. This counters are managed by the Perf_counters class. The Perf_counters class follows a singleton pattern. The unique instance of Perf_counters can be called inside the code by using:

```
statistics()
```

Counters are seperated in two types:
- the standard counters used default in **TRUST** and identified by a `STD_COUNTERS` key (`STD_COUNTERS` is an enum class),
- custom counters that can be created inside the code and that are identified by a `std::string`. 

The basic API for counters in **TRUST** is as follows:

### Standard counters
Here is the list of the standard **TRUST** counters:

| Key | Description | Family | Is_communication | Is_gpu |
|-----|-------------|--------|------------------|--------|
| total_execution_time | Total time | None | False | False |
| computation_start_up | Computation start-up | None | False | False |
| timeloop | Time loop | None | False | False |
| backup_file | Back-up operations | None | False | False |
| system_solver | Linear solver resolutions Ax=B | None | False | False |
| petsc_solver | Petsc solver | None | False | False |
| implicit_diffusion | Solver for implicit diffusion: | None | False | False |
| compute_dt | Computation of the time step dt | None | False | False |
| turbulent_viscosity | Turbulence model::update | None | False | False |
| convection | Convection operator | None | False | False |
| diffusion | Diffusion operator | None | False | False |
| gradient | Gradient operator | None | False | False |
| divergence | Divergence operator | None | False | False |
| rhs | Source_terms | None | False | False |
| postreatment | Post-treatment operations | None | False | False |
| restart | Read file for restart | None | False | False |
| matrix_assembly | Nb matrix assembly for implicit scheme: | None | False | False |
| update_variables | Update ::mettre_a_jour | None | False | False |
| mpi_sendrecv | MPI_send_recv | MPI_sendrecv | true | False |
| mpi_send | MPI_send | MPI_sendrecv | true | False |
| mpi_recv | MPI_recv | MPI_sendrecv | true | False |
| mpi_bcast | MPI_broadcast | MPI_sendrecv | true | False |
| mpi_alltoall | MPI_alltoall | MPI_sendrecv | true | False |
| mpi_allgather | MPI_allgather | MPI_sendrecv | true | False |
| mpi_gather | MPI_gather | MPI_sendrecv | true | False |
| mpi_partialsum | MPI_partialsum | MPI_allreduce | true | False |
| mpi_sumdouble | MPI_sumdouble | MPI_allreduce | true | False |
| mpi_mindouble | MPI_mindouble | MPI_allreduce | true | False |
| mpi_maxdouble | MPI_maxdouble | MPI_allreduce | true | False |
| mpi_sumfloat | MPI_sumfloat | MPI_allreduce | true | False |
| mpi_minfloat | MPI_minfloat | MPI_allreduce | true | False |
| mpi_maxfloat | MPI_maxfloat | MPI_allreduce | true | False |
| mpi_sumint | MPI_sumint | MPI_allreduce | true | False |
| mpi_minint | MPI_minint | MPI_allreduce | true | False |
| mpi_maxint | MPI_maxint | MPI_allreduce | true | False |
| mpi_barrier | MPI_barrier | MPI_allreduce | true | False |
| gpu_library | GPU_library | GPU_library | false | true |
| gpu_kernel | GPU_kernel | GPU_kernel | false | true |
| gpu_copytodevice | GPU_copyToDevice | GPU_copy | false | true |
| gpu_copyfromdevice | GPU_copyFromDevice | GPU_copy | false | true |
| gpu_malloc_free | GPU_allocations | GPU_alloc | false | true |
| interprete_scatter | Scatter_interprete | None | true | false |
| virtual_swap | DoubleVect/IntVect::virtual_swap | None | true | False |
| read_scatter | Scatter::read_domaine | None | true | False |
| parallel_meshing | Parallel meshing | None | False | False |
| IO_EcrireFicPartageBin | write | IO | False | False |
| IO_EcrireFicPartageMPIIO | MPI_File_write_all | IO | False | False |

You can use them whenerver you need to.

### Custom counters



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



