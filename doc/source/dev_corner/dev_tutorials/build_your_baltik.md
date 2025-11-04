# Create a Baltik project

When using TRUST code, you can create a module named Baltik for your own applications that will be based on TRUST. That is what we will do here.

First create a directory for your project:
    `cd MY_FIRST_BALTIK`

Then create your project from a basic project template using TRUST
    commands:
    `trust -baltik my_project`
    `cd my_project`
    `ls -l`

You can see that you have now:

- three directories: share, src and tests, and

- one `project.cfg` file.

- one `README.BALTIK` file.

- one `configure` script.

You have now to add source to your Baltik. To do so, copy the following TRUST .cpp file into your baltik project:
```
mkdir -p src/Trust_fixes
cp $TRUST_ROOT/src/MAIN/mon_main.cpp src/Trust_fixes/
```

For versionning purpose, you will have to create a git repository:

-   Initialize an empty git repository:
```
git init
```

-   Display your working tree status:
```
git status
```

-   You can see 3 file and src directory on the `untracked` files section. It means that they are not yet followed by the git repository.

-   Add src and project.cfg to your git repository in order to prepare a commit:
```
git add src project.cfg
```

-   Now, you can commit your files to add it to your git repository:
```
git commit -m "Initial commit"
```
    
Remark: If you are not able to commit files, you should first configure your username and email in git with :
```
git config - -global user.name `Your Name`\
git config - -global user.email you@example.com
```

-   Display your working tree status:
    `git status`

Only README.BALTIK and configure script (automatically generated) are not added to your git repository.

-   Display the list of commits:
    `git log`

Edit your project file `project.cfg` to specify name, author and executable.

Then configure your project: `baltik_build_configure -execute` this command launches both scripts: the `./baltik_build_configure` and `./configure`.

Check the status of your git repository with the `- -ignored` option to see the status of all files:
```
git status
```
You can see that :

- `project.cfg` has been modified.

- there are new untracked files: these files are not on the git
        repository

- To see only the changes on the git repository files:
```
git status -uno
```
- Track changes via gitk (GUI interface of Git):
```
gitk &
```

You can see information about your first commit and actual untracked changes.

## Builds your Baltik

You will now to make a basic build of your Baltik:

- To make a basic build, first go to your associated repository:
```
cd MY_FIRST_BALTIK/my_project
```

- Then configure your project:
```
./configure
```

- Afterwards, build your project in different modes:

   - Build an optimized (-03 option) version:
      ```
      make optim
      ```

   - Build a debug (-g -O0 option with asserts) version:
      ```
      make debug
      ```

-   Initialize your baltik project environment:
    `source env_my_project.sh`

-   Check that executables are available:
    ```
    echo $exec
    ls $exec_opt
    ls $exec_debug
    ```
Other possible builds, use 
```
make help
```
to see the other options.

Try to build build the following versions:

- semi-optimized -O3 option and assert enabled mode:
```
make semi_optim
ls $exec_semi_optim
```

- optimized binary for profiling (option -pg -O3):
```
make prof
ls $exec_pg
```

- optimized binary for test coverage (option -gcov -O3):
```
make gcov
ls $exec_gcov
```

Notice that TRUST optimized binary for profiling or a TRUST optimized binary for test coverage must exist in order to be able to compile your baltik's profiling or test coverage executable.\

Now you have to initialize your baltik environnement:
```
source env_my_project.sh 
```

For the sequel, we recommand you the Eclipse IDE editor linked to your TRUST repository, {see}`lin_eclipse.md`.

You can now launch a first computation:

- From the `Project Explorer` tab, right click MY_BALTIK $\rightarrow$ `Debug As` $\rightarrow$ `Debug Configurations\...` $\Rightarrow$ C/C++ Application $\rightarrow$ Select the configuration containing your baltik's name

- In the `Main` tab: $\Rightarrow$ Project: MY_BALTIK\ $\Rightarrow$ C/C++ Application: contains path to `$exec_debug` $\Rightarrow$ `Apply`

- In the `Arguments` tab: 
$\Rightarrow$ Program arguments: contains datafile's name (upwind) 
$\Rightarrow$ Working directory: path to datafile's directory
$\Rightarrow$ `Apply` $\Rightarrow$ Debug


## Create a new cpp class

Now we will start to do some modifications of the C++. Let's start by creating a new class:

- First, create a new folder for your own classes:
```
mkdir -p $project_directory/src/my_module
cd $project_directory/src/my_module
```

- Then, import the template `my_first_class`:
```
baltik_gen_class my_first_class
```

- Make sure your changes have been accounted for:
```
git status 
```

- Add your new class to your git repository to follow your modifications:
```
git add my_first_class.*
git commit -m "Add my_first_class src"
```

- Have a look at the two files `my_first_class.h` and `my_first_class.cpp`

**Important remark:** each time a source file is added to the project, you need to reconfigure your project to take new files into account when building the exectuable:
```
cd $project_directory
./configure
```

You can now build your project with Eclipse or in the terminal. Edit the two files with your favorite editor.

**Note:** If you are using Eclispe, you have to refresh your project to see your new files.

Now, we want to change the inheritance of the class in order that it inherits from the `Interprete` class instead of `Objet_U`.
`Interprete` class is the base class of all the keywords doing tasks when read from the datafile, example (read, associate, solve, \...).
You 'll have to:

- add an `#include <Interprete.h>` in my_first_class.h,

- replace `Objet_U` to `Interprete` in the .h and .cpp files,

- Interprete class is an abstact class, it contains a pure virtual
        method which should be implemented!

- rebuild your application and an error will occur!

- Look at the `Interprete` class.

In Eclipse: highlight the string `Interprete` and push the F3 button of your keyboard to open the declaration file of this class.

- Look at `interpreter()` method. This method is called each time a keyword is read from the datafile (eg: `Read_file dom dom.geom`, `Solve pb`, ...).

- Define the public method `interpreter(Entree&)` in the include file and implement it (just print a message with `Cerr` like `- My first keyword!`) into the cpp file. `Entree` is a TRUST class to read an input stream (from a file for example):
Entree& interpreter(Entree&) override;

- Rebuild your project and fix errors until the debug binary of your project is generated

You can now test you new class:

- Copy a test case to the build folder of your Baltik project:
```
cd $project_directory/build/
trust -copy Cx
```

You will have the following message:
```
ERROR
```

The error occurs because this test case is not in your baltik but in TRUST project. To be able to copy it, you have to load the full environment (TRUST+your baltik).
```
source ../full_env_my_project.sh
trust -copy Cx
cd Cx
```

You can now edit the data file:
```
gedit Cx.data &
```

Add the keywords `my_first_class` and `End` after the line where the problem is discretized.

You can eventually run this datafile with your baltik binary and check that this new keyword is recognized:

- With Eclipse: 

$\rightarrow$ In the project explorer, right click on `my_project` and select `Debug As/Debug configurations\...` 

$\rightarrow$ In `Main` tab, check `Disable auto build` then click on `Apply`

$\rightarrow$ In `Arguments` tab, fill `Program arguments:" with `Cx` 

$\rightarrow$ `Working directory:" Copy the path to datafile matching \$project_directory/build/Cx\ $\rightarrow$ `Apply` and `Debug` $\rightarrow$ Click on `Yes` to switch to the debug view $\rightarrow$ Click on `Resume` button (or F8) to run the calculation until the end.

- On a terminal, you can only run: 
```
cd $project_directory/build/Cx/
exec=$exec_debug trust Cx
```

### Modify your cpp class

Now, we want you to read this syntax from the datafile:
```
my_new_keyword { domain dom_name option 0 }
```

The recommended way is to use **Param** objects.

As an example, this is how it is done for 
```
my_new_keyword { problem pb_name option 1 }
```

```cpp
#include <Param.h>
Entree& Class::interpreter(Entree& is)
{
int opt = 0;
Nom pb_name;
Cerr << "Reading parameters of A from a stream (cin or file)" << finl;
Param param(que_suis_je());
// Register parameters to be read:
param.ajouter("option",&opt);
param.ajouter("problem",&pb_name,Param::REQUIRED);
// Read now the parameters from the stream is and produces an error
// if unknown keyword is read or if braces are not found at the
// beginning and the end:
param.lire_avec_accolades_depuis(is);
return is;
}

```
- Fix your implementation of `interpreter()` method (add missing includes).

- Add a print at the end of the method `interpreter(Entree&)` and find how to print the domain name:

```cpp
Cerr << "Option number " << option_number << " has been read on the domain named " << ??? << finl;
```

Then build et run your case in debug:

**With Eclipse:**

   - Build/fix/re-build your project:  $\rightarrow$ `Project` and `Build project`\

   - Run the test case: $\rightarrow$ `Run` and `Debug`\

**Or in a terminal:**

   - Build/fix/re-build your project:
   ```
   cd $project_directory
   make debug
   ```

   - Run the test case:
   ```
   cd $project_directory/build/Cx/
   export exec=$exec_debug
   trust Cx
   ```
You will have then to display information about domain boundaries. First, edit the `my_first_class.cpp` file and add into the `interpreter()` method a loop on the boundaries.

Look for help inside the `Domaine`, `Bord`, `Frontiere` classes in Eclipse or in the HTML documentation to access to the:

- Number of boundaries (**nb_bords()** method)

- Boundaries (**bord(int)** method)

- Name of the boundaries (**le_nom()** method)

- Number of faces of each boundary (**nb_faces()** method)

Print these information in the terminal:
```cpp
Cerr << "The boundary named " << ??? << " has " << ??? << "faces." << finl;
```

Afterwards, compute the sum of the control volumes of a domain discretized in VEF. Information about control volumes is in the `Domaine_VF` class (discretized domain) which can't be accessed from the domain, but only from the problem.
So, you need to read another parameter from your datafile:
```
my_first_class { domain dom option 0 problem pb }
```

- Add the read of a new parameter problem into `my_first_class.cpp` file (see the example at the beggining of this part).

- Remember the `equation` or `problem` UML diagram of the presentation's slides.

- Look for help inside the `Domaine_VF`, `Probleme_base` and `Domaine_dis_base` in Eclipse or the HTML documentation to access to the discretized domain (`domaine_dis()` method) and the control volumes (`volumes_entrelaces()` method)

- You will need to cast the discretized domain returned by the `domaine_dis()` method into a `Domaine_VF` object.

- Print the size of the control volumes array with something like:

```cpp
Cerr << control_volumes.size() << finl;
```

Where `control_volumes` is a **DoubleVect** returned by the `Domaine_VF::volumes_entrelaces()` method.

**Now, compute and print the sum of the control volumes with a `for` loop.**


## Add XD tags (keyword documentation)

We want now to add XD tags to create the automated documentation of your new code.

First, we have to create this documentation for the first time.
```
cd $project_directory
make gui
```

Open the documentation file:
```
evince $project_directory/build/xdata/XTriou/doc.pdf &
```

Now will add XD tags (keyword documentation) in cpp files. For this open the help of the TRAD_2 syntaxe:
```
gedit $project_directory/build/xdata/XTriou/doc_TRAD_2 &
```
Add a first tag (in comments) into your cpp file just after the openning brace of the 'interpreter\_()' method:
`// XD english_class_name base_class_name TRUST_class_name mode description`

where `english_class_name` and `TRUST_class_name` can be `my_first_class`. The `base_class_name` is the name of the section in which will appear the information of your new class in the 'doc.pdf' file.
The `mode` is to choose with the help of the doc\_TRAD\_2 file. Here set it to `-3`.

You can then add at the end of the lines of type `param.ajouter\...`, an XD comment like:
    `param.ajouter(...); // XD_ADD_P type description`
where `type` can be (cf 'doc\_TRAD\_2' file): 'int', 'floattant','chaine', 'rien'...

You can no rebuild the documentation:
```
make gui
```

And check that the documentation of your new class is in the new doc:
```
evince $project_directory/build/xdata/XTriou/doc.pdf &
```
You can also use the following to check that the GUI is validated:
```
make check_gui
```
Notice that you must have XD commands in all your cpp classes.

## Add doxygen comments 

TRUST uses also doxygen in order to build a C++ API documentation. Therefore, you need to add doxygen markers. Here are the classical markers:

| Command | Description |
|---------|-------------|
| `@brief` | Short description (one line) |
| `@param[in]` | Input parameter description |
| `@param[out]` | Output parameter description |
| `@param[in,out]` | Input/output parameter description |
| `@return` / `@returns` | Return value description |
| `@retval` | Specific return value meaning |
| `@throw` / `@throws` | Exception that may be thrown |
| `@pre` | Precondition |
| `@post` | Postcondition |
| `@note` | Important note |
| `@warning` | Warning message |
| `@see` | Reference to related items |
| `@since` | Version information |
| `@deprecated` | Deprecation notice |
| `@code` / `@endcode` | Code example block |
| `@author` | Author information |
| `@date` | Date information |
| `@version` | Version information |

The best doxygen practices in TRUST are quite light:

1. **Always use @brief**: Start with a concise one-line description
2. **Document all parameters**: you can also use @param[in/out/in,out] tags for a more precise doxygen
3. **Specify return values**: Use @return and @retval for clarity
4. **Add cross-references if needed**: Use @see to link related functions/classes


## Adding prints

You can also add some more printings, and here is how:

- Edit the `\$project_directory/src/Trust_fixes/mon_main.cpp` file of your baltik project using text editor or Eclipse.

- Add these lines after `Process::imprimer_ram_totale(1);` :
```cpp
std::cout << "Hello World to cout." << std::endl;
std::cerr << "Hello World to cerr." << std::endl;
Cout << "Hello World to Cout." << finl;
Cerr << "Hello World to Cerr." << finl;
Process::Journal() << "Hello World to Journal." << finl;
```

Then, in a terminal, rebuild the code:
```
cd $project_directory
make debug optim
```
To test your last developpements:

- Create an empty data file:
```
mkdir -p $project_directory/build/hello
cd $project_directory/build/hello
touch hello.data
```

- And run the code:

First sequentially:
```
trust hello
```

Then in parallel:
```
trust hello 4
```

and see the differences.

Here are the explanations:

- `Cout` is equivalent to `std::cout` on the master process only. Use this output for infos about the physics (convergence,fluxes,...).

- `Cerr` is equivalent to `std::cerr` on the master process only. Use this output for warning/errors only.

- `finl` is equivalent to `std::endl` + `flush()` on the master process.

- `Journal()` prints to `datafile_000n.log` files. Use this output during parallel development to print plumbing infos which would be hidden during production runs.

**Remark:** during a parallel run, the `Journal()` output can be disabled. To try it, first clean your folder:
```
ls *.log
trust -clean
```
and run computation with `-journal=0 option`:
```
trust hello 4 -journal=0
ls *.log
```

In practice, other options are available. To get the list, run:
```
trust hello.data -help_trust
```

Let's suppose that you now want to print something inside a file, let's say the volume of the sum of every control volumes.
You would want to write a file with a name close to `DataFileName_result.txt` where `DataFileName` is the name of the data file.

To do so, you have to:

- create an object of the class **Nom** and fill it by collecting the datafile's name using **Objet_U::nom_du_cas()** method.

- complete the datafile's name with the string `_result.txt` thanks to the `operator` += method of the class **Nom**.

- create the output file with the **SFichier** class and print the sum into it.

When this is done, compile your project and run the Cx datafile:
```
cd $project_directory/build/Cx/
exec=$exec_debug trust Cx
```

You should find in `$project_directory/build/Cx/` your new file with the wanted information in it.


## Parallel exercise

Now let's try to do the same for a parallel computation. Run your test case Cx in parallel mode:
```
cd $project_directory/build/Cx/
trust -partition Cx 2 
trust PAR_Cx 2 
```

and ompare the files: Cx_result.txt, PAR_Cx_result.txt.
Differences come from the fact that the 2 processors write into the file one after the other one. So the final content will be the value calculated on the last processor which will acces to the file.

You can try to launch one more time the calculation, the result may even differ.

A first fixo could be to apply the **mp_sum()** method on the sum obtained and add the print in the .txt file.

If you compare it to the sum obtained in the sequential run, the result is closer but we counted several times faces that belongs to the joint and to the virtual zones.

To completly parallelize the algorithm, rewrite it with the help of the **mp_somme_vect(DoubleVect&)** method. Add this print in the .txt file, you should now find the same value for the sequential and parallel calculation.

**Remark:** To validate parallelization in TRUST, you can use the command `compare_lata`:
```
ls *lata 
compare_lata Cx.lata PAR_Cx.lata 
```
You can see that there is no now differences and the maximal relative error encountered is about 4.e-12.

To see the performances, you can check the `.TU` files:
```
ls *TU 
meld Cx.TU PAR_Cx.TU & 
meld Cx_csv.TU PAR_Cx_csv.TU & 
```

### Debog test cases

In TRUST, there are also deog test cases, such as `Debog_VEF`. Copy this test case to see what it does:
```
cd $project_directory/build 
trust -copy Debog_VEF 
cd Debog_VEF 
```

The, open `the Debog_VEF.data` file and search the `Debog` command. You can also try it by running a sequential calculation:
```
trust Debog_VEF 
```

You should get two new files: `seq` and `faces`.

Then let's try a parallel run to see the differences:
```
trust -partition Debog_VEF 2 
trust PAR_Debog_VEF 2
```
Verifyr the data file, you should have now:
```
Debog pb seq faces 1.e-6 **1**
```

Moreover, you should also get a debog\*.log and other DEBOG files netx to your data file.

Inside the log file, you will have the message `ERROR`  if the difference of an array value between you sequential and parallel run is greater than 1.e-6. Otherwise, you will have read `OK`.

You can add a debog instruction in your file mon_main.cpp located in `\$project_directory/Trust_fixes`. After the `Hello world` prints put:
```cpp
double var = 2.5;
Debog::verifier("- Debog test message",var);
```
**Do not forget to add the `#include \<Debog.h\>`!**

Then re-compile and do run sequential calculation and a parallel calculation and check thedebog.log file. Becarefull the debog instruction in the data file must be between the `Discretize` and `Read pb` lines.

For more information, go check the {TRUST Reference Manual}`../../reference/index.rst` and search for the Debog Keyword.


## Validation form and test cases

For each of your new deceloppement in TRUST, if you want them to be integrated, tt is mandatory to create a validation form. They are based on Jupyter Notebooks. Let's try to create one.

First, go the the directory where to notekook are stored:
```
cd $project_directory
cd share/Validation/Rapports_automatiques
```
Now, create a new directory for your new validation form:
```
mkdir -p upwind/src
```
Then, add the following files:
```
cp MY_FIRST_BALTIK/upwind/upwind.data upwind/src
cp MY_FIRST_BALTIK/upwind/upwind.geo upwind/src
```
To create the Jupyter Notebook, run the following:
```
cd upwind
trust -jupyter
```

Now you should have a upwind.ipynb file, i.e. a new Jupyter notebook. Do not forget to add it to your git repository.

You can now run the validation for by doing:
```
cd upwind
Run_fiche
```
Or even build directly a PDF report from the notebook:
```
Run_fiche -export_pdf
```

You can now add it to the non-regression test case base:
```
cd $project_directory
make check_optim
```

Howevern you can see error occuring in  PAR_upwind_jdd1. Let us fix that error.

First, copy the test case:
```
cd $project_directory/build
trust -copy upwind_jdd1
```

An error should occur. It is because it has not been taken into account in the `./configure`, so you need to do it again and do again the previous step.

Now, you have to re-run the configure script to take into account the newtest case:
```
cd $project_directory
./configure
cd build
trust -copy upwind_jdd1
```
And analyse the error:
```
cd upwind_jdd1
trust -partition upwind_jdd1
trust PAR_upwind_jdd1 2
```
Correct the data file PAR_upwind_jdd1.data and re-run it.

If it works, update the data file in `\$project_directory/share/Validation/Rapports_automatiques/upwind/src\`: (`Scatter ../upwind/DOM.Zones dom` $\rightarrow$ `ScatterDOM.Zones dom`)

Then, relaunch the last test cases which did not run:
```
cd $project_directory
make check_last_pb_optim
```
Do not forget to add it to you git project.

Eventually, run all the non regression tests with a optimized binary:
```
make check_all_optim
```
You can also do it in debug:
```
make check_all_debug
```

## Tools

### Debug with GDB

GDB is a vital tool for each and every TRUST developper. It will help you a lot for debugging. You can use it from Eclipse or with th terminal:

- Run a test case with GDB using Eclipse IDE:
$\rightarrow$ `Debug As` and `Debug configurations\...` from `my_project`

$\rightarrow$ in `Arguments`, `Program arguments:" upwind

$\rightarrow$ `Working directory:" MY_FIRST_BALTIK/upwind/

$\rightarrow$ `Apply` and `Debug`

For more information about GDB commands, refer to the help menu.

- GDB with a terminal:

Run a test case with GDB:
```
cd MY_FIRST_BALTIK/upwind/
exec=$exec_debug trust -gdb upwind
```
You are now in GDB.


### Find memory bugs with valgrind

An other usefull tool is valgrind. It will help you find memory leaks. To use valgrind with TRUST, you need to do as follows:
```
cd $project_directory
source env_my_project.sh
cd build/Cx/
trust -valgrind Cx
```
The Valgrind messages appear on the screen with the beginning of each line the same number. For example:
```
==26645== ...
```
The simulation will take way more time. The last line indicates if errors have occurred. An example with 0 error:
```
==26645== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Now we will modify the sources in your baltik project to generate a Valgrind error on the Cx test case:

-   Edit the `my_first_class.cpp` file and remove the following line (before computing the sum of control volumes):
```cpp
    double sum = 0;
```
-   Edit `my_first_class.h` and add in protected:
``` cpp
    double sum; // do not initialize it to 0
```
-   Rebuild your project and run the test case in optim, debug and with valgrind. The two first run will not spot any error, but valgrind will find one.


## Solutions and going further


You can find the commented solution of the exercise:
```
cd $TRUST_ROOT/doc/TRUST/exercices/my_first_class
```

You can practice on another tutorial:
```
cd $TRUST_ROOT/doc/TRUST/exercices/
evince equation_convection_diffusion/rapport.pdf &
```



