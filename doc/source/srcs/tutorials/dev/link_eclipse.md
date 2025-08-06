# Using ECLIPSE IDE editor with TRUST

To get started with Eclipse IDE for TRUST development, you'll need to download and install the appropriate version:

- Visit the Eclipse Foundation website: http://www.eclipse.org/downloads/eclipse-packages/
- Select **Eclipse IDE for C/C++ Developers** → **Linux 64-bits**
- Download the **Linux x86_64** package in the repositery of your choice: `$MY_ECLIPSE_PATH`

Once downloaded, extract the archive and navigate to the Eclipse directory and launch it:

```bash
$ cd $MY_ECLIPSE_PATH
$ mkdir workspace
$ tar xfz eclipse-*.tar.gz
$ cd eclipse
$ ./eclipse &

```
When Eclipse starts:
- **Workspace**: Browse and select the directory `$MY_ECLIPSE_PATH/workspace`
- **Welcome screen**: Close it using the x button

Go to the root of your trust repository and do:

```bash
$ source env_TRUST.sh
$ trust -eclipse-trust
```

After running this command, follow the instructions displayed on the terminal to import TRUST sources into your Eclipse workspace.

Once your TRUST project is imported, you can configure it to run computations:

- From the **"Project Explorer"** tab, right-click on your TRUST project
- Select **"Debug As"** → **"Debug Configurations..."**
- Click on the triangle next to **"C/C++ Application"**
- Select the debug configuration that was automatically created by `trust -eclipse-trust`

The debug configuration consists of several important tabs:

**Main Tab:**
- **Project**: Your project's name
- **C/C++ Application**: Points to the TRUST `$exec_debug` executable

**Arguments Tab:**
- **Program arguments**: Specifies the datafile name (e.g., "upwind")
- **Working directory**: Contains the path to your datafile

Once everything is configured:
- Click **"Debug"** to run your datafile with the specified executable
- Eclipse will launch the computation and allow you to debug your TRUST application

With Eclipse now configured for TRUST development, you can:
- Edit TRUST source files with syntax highlighting and code completion
- Debug your applications using Eclipse's debugging tools
- Manage multiple datafiles and configurations
- Take advantage of Eclipse's integrated development features

Your TRUST development environment is now ready for use!

We recommand you to take some time to learn the shortcuts and functionalities of ECLIPSE IDE. Here are some usefull shortcuts:
::: exampleblock

-   Open a cpp file from Project Explorer tab:\
    Double click on TRUST $\rightarrow$ Kernel $\rightarrow$ Framework
    $\rightarrow$ Probleme_base.cpp\
    or : Ctrl+shift+R then type Probleme_base.cpp\

-   In the cpp file: Right click on method \"postraiter()\"\
    $\Rightarrow$ F3: Opens Declaration\
    $\Rightarrow$ F4: Open Type Hierarchy\
    $\Rightarrow$ Ctrl+Alt+H: Open Call Hierarchy\
    $\Rightarrow$ \"Ctrl+PageUp\" and \"Ctrl+PageDown\": Move from a tab
    to another

-   you can also:\
    $\Rightarrow$ search files by name using: \"Ctrl+shift+R\"\
    $\Rightarrow$ serach attributes/methods/functions/\... using:
    \"Ctrl+shift+T\"
:::