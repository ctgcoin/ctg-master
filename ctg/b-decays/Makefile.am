CLEANFILES = *~
MAINTAINERCLEANFILES = Makefile.in

AM_CXXFLAGS = @AM_CXXFLAGS@

lib_LTLIBRARIES = libctgbdecays.la
libctgbdecays_la_SOURCES = \
	b-to-d-l-nu.cc b-to-d-l-nu.hh \
	b-to-dstar-l-nu.cc b-to-dstar-l-nu.hh \
	b-to-d-l-x-nu.cc b-to-d-l-x-nu.hh \
	b-to-l-nu.cc b-to-l-nu.hh \
	b-to-pi-l-nu.cc b-to-pi-l-nu.hh \
	b-to-pi-pi-l-nu.cc b-to-pi-pi-l-nu.hh \
	b-to-pi-l-x-nu.cc b-to-pi-l-x-nu.hh \
	b-to-v-l-nu.hh \
	bs-to-kstar-l-nu.cc bs-to-kstar-l-nu.hh \
	lambdab-to-lambdac2595-l-nu.cc lambdab-to-lambdac2595-l-nu.hh \
	lambdab-to-lambdac2625-l-nu.cc lambdab-to-lambdac2625-l-nu.hh \
	inclusive-b-to-u.cc inclusive-b-to-u.hh \
	properties.cc properties.hh
libctgbdecays_la_LIBADD = \
	$(top_builddir)/ctg/utils/libctgutils.la \
	$(top_builddir)/ctg/form-factors/libctgformfactors.la \
	-lgslcblas \
	-lgsl

include_ctg_bdecaysdir = $(includedir)/ctg/b-decays
include_ctg_bdecays_HEADERS = \
	b-to-d-l-nu.hh \
	b-to-dstar-l-nu.hh \
	b-to-d-l-x-nu.hh \
	b-to-l-nu.hh \
	b-to-pi-l-nu.hh \
	b-to-pi-pi-l-nu.hh \
	b-to-pi-l-x-nu.hh \
	b-to-v-l-nu.hh \
	bs-to-kstar-l-nu.hh \
	inclusive-b-to-u.hh \
	properties.hh

EXTRA_DIST =

AM_TESTS_ENVIRONMENT = \
	export ctg_TESTS_PARAMETERS="$(top_srcdir)/ctg/parameters";

TESTS = \
	b-to-pi-l-nu_TEST \
	b-to-d-l-nu_TEST \
	b-to-dstar-l-nu_TEST \
	b-to-pi-pi-l-nu_TEST \
	bs-to-kstar-l-nu_TEST \
	lambdab-to-lambdac2595-l-nu_TEST \
	lambdab-to-lambdac2625-l-nu_TEST \
	properties_TEST

LDADD = \
	$(top_builddir)/test/libctgtest.a \
	libctgbdecays.la \
	$(top_builddir)/ctg/form-factors/libctgformfactors.la \
	$(top_builddir)/ctg/utils/libctgutils.la \
	$(top_builddir)/ctg/libctg.la

check_PROGRAMS = $(TESTS)
b_to_d_l_nu_TEST_SOURCES = b-to-d-l-nu_TEST.cc

b_to_dstar_l_nu_TEST_SOURCES = b-to-dstar-l-nu_TEST.cc

b_to_pi_l_nu_TEST_SOURCES = b-to-pi-l-nu_TEST.cc

b_to_pi_pi_l_nu_TEST_SOURCES = b-to-pi-pi-l-nu_TEST.cc

bs_to_kstar_l_nu_TEST_SOURCES = bs-to-kstar-l-nu_TEST.cc

lambdab_to_lambdac2595_l_nu_TEST_SOURCES = lambdab-to-lambdac2595-l-nu_TEST.cc

lambdab_to_lambdac2625_l_nu_TEST_SOURCES = lambdab-to-lambdac2625-l-nu_TEST.cc

properties_TEST_SOURCES = properties_TEST.cc
