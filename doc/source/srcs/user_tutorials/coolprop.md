### CoolProp

CoolProp is an open source ([MIT License](https://github.com/CoolProp/CoolProp/blob/master/LICENSE)) library useful to compute thermo-physical properties for the masses.

A pre-compiled static library of CoolProp is mandatory if a **TRUST** user wants to use its interface via **TRUST**.
**Warning: On a cluster, if you want to install TRUST with CoolProp, you should install both with the same compilers.**

Follow those steps in order to obtain a libcoolprop.a:

```bash
# Get the sources archive (version 6.6.0)
wget https://sourceforge.net/projects/coolprop/files/CoolProp/6.6.0/source/CoolProp_sources.zip
unzip CoolProp_sources.zip
mv source CoolProp
# or download CoolProp (attention recursive, beta version that may have issues with TRUST !!!)
git clone https://github.com/CoolProp/CoolProp --recursive
# Move into the folder you just created
cd CoolProp
# Make a build folder
mkdir -p build && cd build
# Build the makefile using CMake
cmake .. -DCOOLPROP_STATIC_LIBRARY=ON -DCOOLPROP_FPIC=ON
# Make the static library
cmake --build .
# Instead, you can do : make -j all ...
```

Once done, **you need to configure TRUST** with the following (maybe additional) option:

```bash
./configure $OPTIONS -with-coolprop=YOUR_PATH_COOLPROP
make
```
This configure option make it also possible to access CoolProp via a python module. You can try it:

```bash
source env_TRUST.sh
python
from CoolProp.CoolProp import PropsSI
```
**ATTENTION:** `YOUR_PATH_COOLPROP` is the path towards the cloned CoolProp repository and not the build. It is recommended to verify first that the folder `include` exists in `YOUR_PATH_COOLPROP` and that the library `libCoolProp.a` exists in `YOUR_PATH_COOLPROP/build`.