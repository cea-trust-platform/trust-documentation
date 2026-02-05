# Minimal makefile for Sphinx documentation
#

# You can set these variables from the command line, and also
# from the environment for the first two.
SPHINXOPTS    ?=
SPHINXBUILD   ?= sphinx-build
SOURCEDIR     = source
BUILDDIR      = build

# Put it first so that "make" without argument is like "make help".
help:
	@$(SPHINXBUILD) -M help "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)
	@echo ""
	@echo "Custom targets:"
	@echo "  html-quick    Build HTML without C++ API documentation (faster)"
	@echo "  clean-build   Clean then build HTML with full documentation"
	@echo "  clean-quick   Clean then build HTML without C++ API"

.PHONY: help Makefile html-quick clean-build clean-quick

# Build HTML without C++ API (quick mode)
html-quick:
	@echo "Building documentation WITHOUT C++ API (quick mode)..."
	SPHINX_RUN_EXHALE=0 $(SPHINXBUILD) -M html "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)

# Clean then build with full documentation
clean-build: clean html

# Clean then build without C++ API
clean-quick: clean html-quick

# Catch-all target: route all unknown targets to Sphinx using the new
# "make mode" option.  $(O) is meant as a shortcut for $(SPHINXOPTS).
%: Makefile
	@SPHINX_RUN_EXHALE=1 $(SPHINXBUILD) -M $@ "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)