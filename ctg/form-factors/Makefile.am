CLEANFILES = *~
MAINTAINERCLEANFILES = Makefile.in

AM_CXXFLAGS = @AM_CXXFLAGS@

lib_LTLIBRARIES = libctgformfactors.la
libctgformfactors_la_SOURCES = \
	analytic-b-to-kstar.hh analytic-b-to-kstar.cc \
	analytic-b-to-pi.hh analytic-b-to-pi.cc \
	analytic-b-to-pi-pi.hh analytic-b-to-pi-pi.cc \
	baryonic.cc baryonic.hh baryonic-impl.hh \
	b-lcdas.cc b-lcdas.hh \
	form-factor-adapter.hh \
	form-factors.cc form-factors.hh form-factors-fwd.hh \
	hqet-b-to-c.hh hqet-b-to-c.cc \
	kstar-lcdas.cc kstar-lcdas.hh \
	mesonic.cc mesonic.hh mesonic-impl.hh \
	pi-lcdas.cc pi-lcdas.hh \
	zero-recoil-sum-rule.cc zero-recoil-sum-rule.hh
libctgformfactors_la_LIBADD = \
	$(top_builddir)/ctg/utils/libctgutils.la \
	-lgslcblas \
	-lgsl \
	-lyaml-cpp

include_ctg_rarebdecaysdir = $(includedir)/ctg/form-factors
include_ctg_rarebdecays_HEADERS = \
	analytic-b-to-kstar.hh \
	analytic-b-to-pi.hh \
	analytic-b-to-pi-pi.hh \
	b-lcdas.hh \
	form-factor-adapter.hh \
	form-factors.hh \
	pi-lcdas.hh

AM_TESTS_ENVIRONMENT = \
	export ctg_TESTS_PARAMETERS="$(top_srcdir)/ctg/parameters";

TESTS = \
	analytic-b-to-kstar_TEST \
	analytic-b-to-pi_TEST \
	analytic-b-to-pi-pi_TEST \
	baryonic_TEST \
	b-lcdas_TEST \
	hqet-b-to-c_TEST \
	kstar-lcdas_TEST \
	mesonic_TEST \
	pi-lcdas_TEST
LDADD = \
	$(top_builddir)/test/libctgtest.a \
	libctgformfactors.la \
	$(top_builddir)/ctg/utils/libctgutils.la \
	$(top_builddir)/ctg/libctg.la

check_PROGRAMS = $(TESTS)
analytic_b_to_kstar_TEST_SOURCES = analytic-b-to-kstar_TEST.cc

analytic_b_to_pi_TEST_SOURCES = analytic-b-to-pi_TEST.cc

analytic_b_to_pi_pi_TEST_SOURCES = analytic-b-to-pi-pi_TEST.cc

baryonic_TEST_SOURCES = baryonic_TEST.cc

b_lcdas_TEST_SOURCES = b-lcdas_TEST.cc

hqet_b_to_c_TEST_SOURCES = hqet-b-to-c_TEST.cc

kstar_lcdas_TEST_SOURCES = kstar-lcdas_TEST.cc

mesonic_TEST_SOURCES = mesonic_TEST.cc

pi_lcdas_TEST_SOURCES = pi-lcdas_TEST.cc
