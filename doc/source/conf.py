import sys
import os
sys.path.insert(0, os.path.abspath('..'))
# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#

# for trust utils python docstrings
sys.path.insert(0, os.path.abspath('./srcs/trustutils/python_cloned_srcs/'))

# -- Project information -----------------------------------------------------

project = 'TRUST'
author = 'TRUST team'
# copyright = f'{datetime.now().year}, CEA'

# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
pygments_style = 'sphinx'
extensions = [
    # Core documentation generation
    'sphinx.ext.autodoc',          # Auto-generate docs from Python docstrings
    'sphinx.ext.autosummary',      # Generate summary tables for modules/packages
    'sphinx.ext.napoleon',         # Parse Google/NumPy style docstrings
    'sphinx.ext.mathjax',          # For math environments based on latex
    # 'numpydoc',                  # Alternative NumPy docstring parser 
    # Cross-referencing and linking
    'sphinx.ext.intersphinx',      # Link to other Sphinx documentation projects
    'sphinx.ext.autosectionlabel', # Auto-generate labels for all sections
    # Code testing and quality
    'sphinx.ext.doctest',          # Test code examples in docstrings
    'sphinx.ext.coverage',         # Generate documentation coverage reports
    # Visualization and diagrams
    'sphinx.ext.graphviz',         # Embed Graphviz diagrams in documentation
    # Conditional content
    'sphinx.ext.ifconfig',         # Include/exclude content based on configuration
    # Markup and formatting
    'myst_parser',                 # Support for Markdown (MyST) syntax
    # Bibliography and citations
    'sphinxcontrib.bibtex',        # Handle bibliographic references and citations
]

numfig = True
numfig_secnum_depth = 2
numfig_format = {
    'figure': 'Figure %s',
    'table': 'Table %s',
    'code-block': 'Code %s',
}

htmlhelp_basename = 'TRUST Documentation'

autosectionlabel_prefix_document = True

# To show or not private members -
autodoc_default_options = {"members": True, "undoc-members": True, "private-members": False}

# For math formula 
mathjax3_config = {
    'tex': {
        'packages': ['base', 'ams', 'amsfonts', 'amssymb', 'noerrors', 'noundefined', 'autoload'],
    }
}

# generate autosummary even if no references
numpydoc_show_class_members = False
autosummary_generate = False
autosummary_imported_members = False

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
# The sources that will effectively be used are in 'srcs_processed' where the substitution of the :code: tags has been done:
exclude_patterns = ["srcs"]

master_doc = 'index'
# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#

#html_theme = 'press'
# html_theme = 'alabaster'
#html_theme = 'sphinx_rtd_theme'
# html_theme = 'default'
#html_theme = 'sphinx_material'
html_theme = 'sphinx_book_theme'
#html_theme = 'pydata_sphinx_theme'

html_theme_options = {
    "show_toc_level": 2,
    "navigation_depth": 4,
    "collapse_navigation": False, 
    "navigation_with_keys": True,  
    "show_navbar_depth": 2,
    "show_prev_next": True,
    "home_page_in_toc": True,
    "logo": {
        "image_light": "_static/FIGURES/logo_trust.gif",
        "text":"Documentation",
        }
    ,
    "repository_url": "https://github.com/cea-trust-platform/trust-code",
    "repository_branch": "master",
    "use_repository_button": True,
    "use_edit_page_button": False,  # True si tu veux permettre l'édition directe
    "use_issues_button": True,      # True pour afficher un lien vers les issues
    "use_download_button": True,    # True pour permettre le téléchargement
    
    # Search and content options
    "use_sidenotes": True,          # Pour de meilleures annotations
    "show_toc_level": 2,           # Profondeur d'affichage dans la TOC
}

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']
html_css_files = ['custom.css']

# Nice little icon in tab header
html_favicon = 'favicon.ico'

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# Bibliography
bibtex_bibfiles = [os.path.join(os.path.dirname(__file__), 'biblio.bib')]
bibtex_default_style = 'alpha'  # Bib style
bibtex_reference_style = 'author_year'

# To avoid cache error
suppress_warnings = ["config.cache"]

# To allow markdown pages
source_suffix = {
    '.rst': 'restructuredtext',
    '.md': 'markdown',
}

# Myst configuration
myst_enable_extensions = [
    "colon_fence",
    "deflist", 
    "dollarmath",
    "html_admonition",
    "html_image",
    "substitution",
    "tasklist",
    "attrs_inline",
    "attrs_block"
]
myst_heading_anchors = 1

extlinks = {
    'github': ('https://github.com/cea-trust-platform/trust-code/%s', 'GitHub: %s'),
    'trust': ('https://trust-platform.org/%s', 'TRUST: %s'),
}

rst_prolog = """
.. role:: blue
   :class: blue-text
"""

# Generating doxygen from here - this will run first, before RST processing from sphinx:
import subprocess as sp

if 1:
    build_dir = os.environ.get("READTHEDOCS_OUTPUT", "")
    import pathlib
    pth = pathlib.Path(__file__)
    if build_dir == "":  # Local build
        # Compute coherent output path:
        build_dir = pth.parents[1] / "build"
    else:
        build_dir = pathlib.Path(build_dir)
    print("@@@ About to generate doxygen!!")
    sp.call("cd srcs/doxy; doxygen", shell=True)    
    # Output directory must be created since this will run before Sphinx ...
    print(f"@@@ Creating output directory: {str(build_dir)}/html ...")
    sp.call(f"mkdir -p {str(build_dir)}/html", shell=True)
    print(f"@@@ Copying doxygen result to proper directory ...")
    sp.call(f"cp -a srcs/doxy/html {str(build_dir)}/html/doxy", shell=True)
    sp.call(f"cp -a srcs/doxy/favicon.ico {str(build_dir)}/html/doxy", shell=True)
    print("@@@ Done generating doxygen!!")
    # Processing source RST files to handle ':code:' tags
    import sys
    sp.call(f"rm -rf _srcs_processed; cp -a srcs _srcs_processed", shell=True)
    print("@@@ About to process RST files to replace code tags ...") 
    sys.path.append(str(pth.parents[0]))
    import deref_code
    deref_code.do_the_job(build_dir)
    print("@@@ Done processing RST files!")
