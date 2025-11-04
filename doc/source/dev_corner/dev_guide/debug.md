# Debugging in TRUST

First, a general tip regarding debugging: try to find the smallest test case that reproduces your bug before debugging it, it will help you a lot.

If you have compiled your code in debug mode, you can use directly from the trust wrapper the following debugging tools.


## GDB

```bash
exec=$exec_debug
trust -gdb my_data_file.data (nb_proc)
```

When you use gdb in parallel, you will attach each process on a gdb instance. Thus, make sure to debug with a small number of processes if possible.

## Valgrind

```bash
exec=$exec_debug
trust -valgrind my_data_file.data (nb_proc)
```

Valgrind is a useful tool to detect weird behaviour of a code once you are done with gdb. Typically, uninitialized variables in the code may give non-deterministic behaviour or lead to crash. This type of error can almost only be detected by valgrind. As **TRUST** possesses a garbage collector for **TRUST** objects, valgrind will not be that helpful to find memory leaks (only for plain C++ objects). The best tool to spot them is Heaptrack, see the [](stats_profilers.md) section. 
