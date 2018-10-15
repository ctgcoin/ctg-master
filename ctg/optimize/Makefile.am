MAINTAINERCLEANFILES = Makefile.in

lib_LTLIBRARIES = libctgoptimize.la
libctgoptimize_la_SOURCES = \
	optimizer.cc optimizer.hh \
	optimizer-gsl.cc optimizer-gsl.hh
libctgoptimize_la_CXXFLAGS = $(AM_CXXFLAGS)
libctgoptimize_la_LIBADD =

include_ctg_optimizedir = $(includedir)/ctg/optimize
include_ctg_optimize_HEADERS = \
	optimizer.hh

TESTS = \
	optimizer-gsl_TEST
LDADD = \
	$(top_builddir)/test/libctgtest.a \
	$(top_builddir)/ctg/statistics/libctgstatistics.la \
	$(top_builddir)/ctg/utils/libctgutils.la \
	libctgoptimize.la \
	$(top_builddir)/ctg/libctg.la

check_PROGRAMS = $(TESTS)

optimizer_gsl_TEST_SOURCES = optimizer-gsl_TEST.cc
