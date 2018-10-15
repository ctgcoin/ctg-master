CLEANFILES = \
	*~ \
	ctg-list-references

MAINTAINERCLEANFILES = Makefile.in

if ctg_ENABLE_PYTHON

bin_SCRIPTS = \
	ctg-list-references \
	ctg-make-constraint \
	ctg-merge-mcmc \
	ctg-plot \
	ctg-plot-1d \
	ctg-plot-2d \
	ctg-print-uncertainty

endif

EXTRA_DIST = \
	ctg-list-references.in \
	ctg-make-constraint \
	ctg-merge-mcmc \
	ctg-plot \
	ctg-plot-1d \
	ctg-plot-2d \
	ctg-print-uncertainty

ctg-list-references: ctg-list-references.in Makefile
	sed \
	    -e "s#@PKGDATADIR@#$(pkgdatadir)#g" \
	    $< \
	    > $@
	chmod a+x $@
