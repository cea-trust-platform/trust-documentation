# TRUST documentation on GitHub & Read the Docs !

<img src="https://github.com/cea-trust-platform/trust-code/blob/master/bin/HTML/logo_trust.gif?raw=true" style="width:12cm;">

Hi there 👋 and welcome to the **[TRUST Documentation](https://cea-trust-platform.readthedocs.io/en/latest/)** page!

To build locally the website, follow the following steps:

- First, clone this repository:

``` bash
$ git clone https://github.com/cea-trust-platform/trust-documentation.git ./trust_documentation
```
- Create a conda environment based on the `environment.yml` file.
``` bash
$ cd trust_documentation/doc
$ conda env create -f environment.yml
$ conda activate trust-doc
```
Then you can build the documentation:
```bash
$ ./build_documentation
```

The documentation uses a MyST parser. You can therefore use .rst and .md files.

You might need to clean your project if you do a massive change:
``` bash
$ cd trust_documentation/doc
$ make clean html
```

Credits for the open-source **[Sphinx Book Theme](https://github.com/executablebooks/sphinx-book-theme)**, **[Doxygen Awesome Theme](https://jothepro.github.io/doxygen-awesome-css/)**, **[Read The Docs](https://blog.readthedocs.com/website-migration/)** projects and [MyST](https://github.com/executablebooks/MyST-Parser) parser.

Enjoy TRUST 🍻🍻 !!
