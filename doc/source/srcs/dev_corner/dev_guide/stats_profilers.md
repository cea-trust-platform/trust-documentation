# Measuring performance in TRUST

A key feature for code optimisation is performance measurement. **TRUST** offers different solutions, using **TRUST** internal features or external libraries.

## TRUST counters

In order to obtain statistics on the performance of a test case, **TRUST** uses counters. Counters are C++ objects. 

Their main purpose is to serve as time watches for parts of the code you deem important. They also track additional metrics:

**Timing statistics:**
- Minimum, maximum, average and standard deviation of the measured time per time step

**Usage metrics:**
- An integer called `count` tracking the number of times the counter has been started and stopped
- A custom integer called `quantity`, mainly used to measure the quantity of bytes exchanged during communication operations, or to store the number of iterations of the linear solver

**Identification:**
- `std::string` attributes `description` and `family`. A description is mandatory for each counter. The family attribute is by default set to `"None"` but can be used as a key for regrouping the counters you want to parse together after your computation.

**Level management:**
Counters also have a certain level. The level of a counter is represented by an integer. It makes sure that you know when you open your counter. Indeed, if a counter of level 1 is running, you can only start a counter of level 2. Otherwise, the code will stop. In the same logic, you can only close the most recently opened counter. Because of this interlock structure, counters also have another interesting metric called **alone_time**. It is the elapsed time where the considered counter is the last opened one (i.e., excluding time spent in nested counters). This metric is printed in the CSV output file and helps identify the intrinsic cost of each code section.

**Example of the level hierarchy:**
```cpp
statistics().begin_count(STD_COUNTERS::total_execution_time, -1);                   // Level -1 - reserved to the total execution time counter
    statistics().begin_count(STD_COUNTERS::timeloop, 0);                            // Level 0  - reserved to counters of the global steps
        statistics().begin_count(STD_COUNTERS::convection, 1);                      // Level 1  - only possible while Level 0 is running
            statistics().begin_count(STD_COUNTERS::mpi_recv, 2);                    // Level 2  - only possible while Level 1 is running
            statistics().end_count(STD_COUNTERS::mpi_recv, 1 , nb_exchanged_bytes);
        statistics().end_count(STD_COUNTERS::convection);
    statistics().end_count(STD_COUNTERS::timeloop);
statistics().end_count(STD_COUNTERS::total_execution_time);
```
This ensures proper nesting and helps track where time is spent in your code hierarchy.

Those counter objects are managed by the Perf_counters class. In practice, you will only need to interact with the Perf_counters class (not with individual counter objects directly). The Perf_counters class follows a singleton pattern and a Pimpl pattern, such that the implementation of the class is hidden in the Perf_counters.cpp file. The unique instance of Perf_counters can be called inside the code by using:

```cpp
statistics()
```

The unique instance of Perf_counters will be created at the first `statistics()` call.  

The counters managed by the Perf_counters instance are separated in two types:
- the standard counters used by default in **TRUST** and identified by a `STD_COUNTERS` key (`STD_COUNTERS` is an enum class),
- custom counters that can be created inside the code and that are identified by a `std::string`. 

The basic API for counters in **TRUST** is as follows:

```cpp
#include <Perf_counters.h>

statistics().begin_count(MY_COUNTER_KEY, level);
{
    // The block of code I want to have statistics about
}
statistics().end_count(MY_COUNTER_KEY, count, quantity);
```

MY_COUNTER_KEY is either a `STD_COUNTERS` if you want to open a standard **TRUST** counter or the `std::string` that corresponds to the description of the custom counter you try to open. In the `statistics().begin_count()` function, the `level` parameter is optional. If omitted, the counter will automatically use the one defined at the creation of the counter. If you are having trouble determining the level of your counter, you can use the function `statistics().get_last_opened_counter_level()` to know the level of the last opened counter. The `count` parameter specifies how much to increment the counter's total count (i.e., how many times to record this begin/end cycle). It is set by default to 1. The `quantity` parameter specifies how much to increment the quantity attribute of your counter and is by default set to 0.


During a **TRUST** computation, **TRUST** statistics are measured through 3 main steps: 
- Computation start-up 
- Time loop
- Post-resolution

At the end of each step, the counters are reset and statistics are printed in the two files:
- `MY_TRUST_CASE_NAME.TU` 
- `MY_TRUST_CASE_NAME_csv.TU`

The first file contains aggregated stats that are the most commonly used alongside some information regarding the environment of your computation (date, OS, CPU model, GPU model if you run a GPU computation, number of CPU processors used, ...). It has been designed to be human readable, but it is not easy to parse it informatically.
The second file has been created for easily parsing each and every counter's data with your favorite csv parsing tool, for example [pandas](https://pandas.pydata.org/).

The first time steps can take more time thant the rest, if you want to discard them of your stats, add the following line of code right before the time loop:
```cpp
statistics().set_nb_time_steps_elapsed(int n) ;
```

### Standard TRUST counters
Here is the list of the standard **TRUST** counters:

| Key | Description | Family | Is_communication | Is_gpu |
|-----|-------------|--------|------------------|--------|
| total_execution_time | Total time | None | False | False |
| computation_start_up | Computation start-up | None | False | False |
| timeloop | Time loop | None | False | False |
| backup_file | Back-up operations | None | False | False |
| system_solver | Linear solver resolutions Ax=B | None | False | False |
| petsc_solver | Petsc solver | None | False | False |
| implicit_diffusion | Solver for implicit diffusion | None | False | False |
| compute_dt | Computation of the time step dt | None | False | False |
| turbulent_viscosity | Turbulence model::update | None | False | False |
| convection | Convection operator | None | False | False |
| diffusion | Diffusion operator | None | False | False |
| gradient | Gradient operator | None | False | False |
| divergence | Divergence operator | None | False | False |
| rhs | Source terms | None | False | False |
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
   

You can use them whenever you need to.

### Custom TRUST counters

As explained above, on top of standard counters, you can also create and use custom counters. To create a new custom counter, you just need to add the following in your code:
```cpp
statistics().create_custom_counter(std::string counter_description, int counter_level,  std::string counter_family = "None", bool is_comm=false, bool is_gpu=false);
```
Then, you can open and close your new counter, using `std::string counter_description` as your new counter key. All of the custom counters will be printed in both TU files.

:::{note}
Warning: if a custom counter already has your `std::string counter_description`, the function `statistics().create_custom_counter()` will not create another counter.
:::

## External profilers

Some external profilers can be directly used on a **TRUST** data file. To find the appropriate option to use them, run: 
```bash 
trust -h
```
Below, we present the three most useful ones.

### Perf 

First, install the [Perf](https://perfwiki.github.io/main/) library if you don't have it yet. 

Then, you just need to:
```
trust -perf MY_DATA_FILE.data
```

Perf is dedicated to CPU profiling. It will enable you to locate the main performance bottlenecks inside your code. 

### Heaptrack

First, make sure the [Heaptrack](https://github.com/KDE/heaptrack) package is installed on your computer. 

Then, you just need to:
```
trust -heaptrack MY_DATA_FILE.data
```

Heaptrack is dedicated to monitor memory usage (allocations: their number and size). It will enable you to find excessive allocations and possibly memory leaks. 

:::note
Perf and Heaptrack work best with [Hotspot](https://github.com/KDAB/hotspot), a GUI for visualizing profiling data.
:::

### Nsight system

Normally, [Nsight system](https://developer.nvidia.com/nsight-systems) is already available in **TRUST**. You can also install it alone or alongside the [Cuda Toolkit](https://developer.nvidia.com/cuda-toolkit). 

Then, you just need to:
```
trust -nsys MY_DATA_FILE.data
```

Nsight system is dedicated to GPU profiling. It will enable you to locate the main performance bottlenecks inside your code. It detects the code not yet ported on GPU, and helps you visualize the data copy between host and device memory. Nsight system is also useful with CPU-only runs thanks to the rich labeling of the code.







