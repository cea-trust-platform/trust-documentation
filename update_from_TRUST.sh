#!/bin/bash

[ "$TRUST_ROOT" = "" ] && echo "TRUST root not defined! Exiting." && exit -1

orig_dir=$TRUST_ROOT/Outils/trustify
install_dir=$orig_dir/install/doc

if ! [ -d  $doc_dir ]; then
  echo "Trustify documentation is not generated? Directory $orig_dir does not exist"
  echo "Run 'make doc' in the $TRUST_ROOT/Outils/trustify directory"
  exit -1
fi

echo "Copying files ..."
cp $install_dir/all.rst doc/source/srcs/reference
cp $orig_dir/doc/extra_rst/parser.rst doc/source/srcs/reference
cp $orig_dir/doc/images/* doc/source/srcs/reference/images

echo "All done! Do not forget to 'git add/rm' any new/deleted file ..."

