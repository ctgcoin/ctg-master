CLEANFILES = *~
MAINTAINERCLEANFILES = Makefile.in

AM_CXXFLAGS = -I$(top_srcdir) -std=c++14 -Wall -Wextra -pedantic

noinst_LIBRARIES = libcli.a

libcli_a_SOURCES = \
	cli_dumper.cc cli_dumper.hh \
	cli_error.cc cli_error.hh \
	cli_group.cc cli_group.hh \
	cli_handler.cc cli_handler.hh \
	cli_section.cc cli_section.hh \
	cli_option.cc cli_option.hh \
	cli_visitor.cc cli_visitor.hh

bin_PROGRAMS = \
	ctg-evaluate \
	ctg-find-mode \
	ctg-list-constraints \
	ctg-list-observables \
	ctg-list-parameters \
	ctg-list-signal-pdfs \
	ctg-print-polynomial \
	ctg-propagate-uncertainty \
	ctg-sample-mcmc \
	ctg-sample-events-mcmc \
	ctg-scan-mc
noinst_PROGRAMS = \
	integrated \
	observables

LDADD = \
	$(top_builddir)/ctg/statistics/libctgstatistics.la \
	$(top_builddir)/ctg/optimize/libctgoptimize.la \
	$(top_builddir)/ctg/utils/libctgutils.la \
	$(top_builddir)/ctg/form-factors/libctgformfactors.la \
	$(top_builddir)/ctg/b-decays/libctgbdecays.la \
	$(top_builddir)/ctg/rare-b-decays/libctgrarebdecays.la \
	$(top_builddir)/ctg/libctg.la \
	libcli.a \
	-lboost_filesystem -lboost_system \
	-lMinuit2 \
	-lyaml-cpp

if ctg_ENABLE_PMC
bin_PROGRAMS += \
	ctg-sample-pmc

LDADD += \
	-lpmc -ldl

ctg_sample_pmc_SOURCES = ctg-sample-pmc.cc
ctg_sample_pmc_CXXFLAGS = $(AM_CXXFLAGS) $(HDF5_CXXFLAGS)
ctg_sample_pmc_LDADD = $(LDADD) $(HDF5_LDFLAGS) -lpmc -ldl
endif

ctg_evaluate_SOURCES = ctg-evaluate.cc

ctg_find_mode_SOURCES = ctg-find-mode.cc
ctg_find_mode_CXXFLAGS = $(AM_CXXFLAGS) $(MINUIT2_CXXFLAGS)
ctg_find_mode_LDADD = $(LDADD) $(MINUIT2_LDFLAGS)

ctg_list_constraints_SOURCES = ctg-list-constraints.cc

ctg_list_observables_SOURCES = ctg-list-observables.cc

ctg_list_parameters_SOURCES = ctg-list-parameters.cc

ctg_list_signal_pdfs_SOURCES = ctg-list-signal-pdfs.cc

ctg_print_polynomial_SOURCES = ctg-print-polynomial.cc

ctg_propagate_uncertainty_SOURCES = ctg-propagate-uncertainty.cc
ctg_propagate_uncertainty_CXXFLAGS = $(AM_CXXFLAGS) $(HDF5_CXXFLAGS)
ctg_propagate_uncertainty_LDADD = $(LDADD) $(HDF5_LDFLAGS)

ctg_sample_mcmc_SOURCES = ctg-sample-mcmc.cc

ctg_sample_events_mcmc_SOURCES = ctg-sample-events-mcmc.cc
ctg_sample_events_mcmc_CXXFLAGS = $(AM_CXXFLAGS) $(HDF5_CXXFLAGS)
ctg_sample_events_mcmc_LDADD = $(LDADD) $(HDF5_LDFLAGS)

ctg_scan_mc_SOURCES = ctg-scan-mc.cc
ctg_scan_mc_CXXFLAGS = $(AM_CXXFLAGS) $(HDF5_CXXFLAGS) $(MINUIT2_CXXFLAGS)
ctg_scan_mc_LDADD = $(LDADD) $(HDF5_LDFLAGS) $(MINUIT2_LDFLAGS)

integrated_SOURCES = integrated.cc

observables_SOURCES = observables.cc
