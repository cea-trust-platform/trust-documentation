# Debugging in TRUST

If you have compiled your code in debug mode you can use direclty from the trust wrapper the following debugging tools.

First, a general advice regarding debugging: try to find the smallest case that still recreate your bug before trying to debug it, it will help you a lot.

## GDB

```bash
exec=$exec_debug
trust -gdb my_data_file.data (nb_proc)
```

When tou use gdb in parallel, you will attached each process on a gdb instance. Thus, make sure to debug on a small amount of proc if possible.

## Valgrind

```bash
exec=$exec_debug
trust -valgrind my_data_file.data (nb_proc)
```

Valgrind is a usefull tool to detect weird behaviour of a code once you are done with gdb. Typically, un-initiallized varaibles in the code may give non-deterministic behaviour or lead to crash. This type of error will only be spotted by valgrind. As **TRUST** posses garbadge collector for **TRUST** objects, valgrind will not be that helpfull to find memory leaks (only on based C++ objects). The best tool to spot them is Heaptrack, see the [](stat_profilers) section. 