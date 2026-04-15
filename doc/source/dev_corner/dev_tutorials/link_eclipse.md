# Using Eclipse IDE with TRUST

To get started with Eclipse IDE for TRUST development, you will need to download and install the appropriate version:

- Visit the [Eclipse Foundation website](https://www.eclipse.org/downloads/packages/).
- Select [**Eclipse IDE for C/C++ Developers**](https://www.eclipse.org/downloads/packages/release/2026-03/r/eclipse-ide-cc-developers)
- Download the [**Linux x86_64**](https://www.eclipse.org/downloads/download.php?file=/technology/epp/downloads/release/2026-03/R/eclipse-cpp-2026-03-R-linux-gtk-x86_64.tar.gz) package.

Once downloaded, extract the archive and navigate to the Eclipse directory and launch it:

```bash
tar xfz eclipse-*.tar.gz
cd eclipse
./eclipse &

```

The first step is to load TRUST environment and then generate a configuration for TRUST under eclipse:

```bash
source $my_path_to_TRUST_installation/env_TRUST.sh
trust -eclipse-trust
```

Follow the instructions displayed on the terminal to import TRUST sources into your Eclipse workspace.

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
- **Program arguments**: Specifies the datafile name (e.g., `upwind` or `upwind.data` or another datafile)
- **Working directory**: Contains the path to your datafile specified in the Program arguments.

Once everything is configured:
- Click **"Debug"** to run your datafile with the specified executable
- Eclipse will launch the computation and allow you to debug your TRUST application

With Eclipse now configured for TRUST development, you can:
- Edit TRUST source files with syntax highlighting and code completion
- Debug your applications using Eclipse's debugging tools
- Manage multiple datafiles and configurations
- Take advantage of Eclipse's integrated development features

Your TRUST development environment is now ready for use!
```{tip}
We recommand you to take some time to learn the shortcuts and functionalities of Eclipse IDE.
```
 Here are some usefull shortcuts:
::: exampleblock

-   Open a cpp file from Project Explorer tab (Probleme_base.cpp for example):\
    Double click on TRUST $\rightarrow$ Kernel $\rightarrow$ Framework\
    $\rightarrow$ Probleme_base.cpp\
    or : Ctrl+shift+R then type Probleme_base.cpp

-   In the cpp file: Right click on method \"postraiter()\"\
    $\Rightarrow$ F3: Opens Declaration\
    $\Rightarrow$ F4: Open Type Hierarchy\
    $\Rightarrow$ Ctrl+Alt+H: Open Call Hierarchy\
    $\Rightarrow$ \"Ctrl+PageUp\" and \"Ctrl+PageDown\": Move from a tab
    to another

-   You can also:\
    $\Rightarrow$ search files by name using: \"Ctrl+shift+R\"\
    $\Rightarrow$ search attributes/methods/functions/\... using:
    \"Ctrl+shift+T\"
:::
