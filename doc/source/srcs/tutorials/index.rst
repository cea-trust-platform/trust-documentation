TRUST Tutorials
***************

**The following tutorials require a Linux based computer.**

Getting started
===============

Make sure you have installed TRUST in your wanted repo: $MY_TRUST. Don't forget the externalpackages repository. If you need help, go to `this page <https://github.com/cea-trust-platform/trust-code>`_.

First source the TRUST environnement:

.. code-block:: bash

   source $MY_TRUST/env_TRUST.sh

To check if it worked, try:

.. code-block:: bash

   echo $TRUST_ROOT

**Make sure you have the externalpackages repository at the root of your TRUST repository**. A good pratice is to use a symbolic link:

.. code-block:: bash

   cd $TRUST_ROOT
   ln -s $YOUR_EXTERNALPACKAGES_PATH .

Then come the part where you need to build TRUST locally. You first need to start by:

.. code-block:: bash

   cd $TRUST_ROOT
   ./configure -help

This will give you the configure options you may used, for example, if you want to run GPU simulations, you need to use the option ``-cuda`` if you have a Nvidia GPU.

**After choosing the options you need, run:**

.. code-block:: bash

   ./configure $MY_OPTIONS
   make

This will take some times but afterwards you should have an up-and-running TRUST. You can use other make options, see ``make help``.

As you will see in the following, TRUST use ``.data`` files. In order too have a more readable ``.data``, we recommand the user to run:

.. code-block:: bash

   trust -config gedit|vim|emacs

You are now set up for the tutorials.

.. toctree::
   :maxdepth: 1

   user/index
   dev/index
   








   