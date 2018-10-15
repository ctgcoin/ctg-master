CLEANFILES = \
	*~ \
	references_TEST
MAINTAINERCLEANFILES = Makefile.in

SUBDIRS = constraints parameters utils optimize statistics form-factors rare-b-decays b-decays .

AM_CXXFLAGS = @AM_CXXFLAGS@

lib_LTLIBRARIES = libctg.la
libctg_la_SOURCES = \
	constraint.cc constraint.hh \
	decays.hh \
	observable.cc observable.hh \
	signal-pdf.cc signal-pdf.hh
libctg_la_LIBADD = \
	$(top_builddir)/ctg/utils/libctgutils.la \
	$(top_builddir)/ctg/statistics/libctgstatistics.la \
	$(top_builddir)/ctg/form-factors/libctgformfactors.la \
	$(top_builddir)/ctg/b-decays/libctgbdecays.la \
	$(top_builddir)/ctg/rare-b-decays/libctgrarebdecays.la

include_ctgdir = $(includedir)/ctg
include_ctg_HEADERS = \
	constraint.hh \
	decays.hh \
	observable.hh \
	signal-pdf.hh

AM_TESTS_ENVIRONMENT = \
	export ctg_TESTS_CONSTRAINTS="$(top_srcdir)/ctg/constraints"; \
	export ctg_TESTS_PARAMETERS="$(top_srcdir)/ctg/parameters";

TESTS = \
	constraint_TEST \
	references_TEST
LDADD = \
	$(top_builddir)/test/libctgtest.a \
	$(top_builddir)/ctg/utils/libctgutils.la \
	$(top_builddir)/ctg/b-decays/libctgbdecays.la \
	$(top_builddir)/ctg/form-factors/libctgformfactors.la \
	$(top_builddir)/ctg/rare-b-decays/libctgrarebdecays.la \
	$(top_builddir)/ctg/statistics/libctgstatistics.la \
	$(top_builddir)/ctg/libctg.la

check_PROGRAMS = \
	constraint_TEST \
	references_TEST

constraint_TEST_SOURCES = constraint_TEST.cc

references_TEST_SOURCES = references_TEST.in

pkgdata_DATA = references.yaml
EXTRA_DIST = \
	references.yaml \
	references_TEST.in

references_TEST$(EXEEXT): references_TEST.in Makefile
	sed \
	    -e "s#@TOPSRCDIR@#$(top_srcdir)#g" \
	    $< \
	    > $@
	chmod a+x $@
