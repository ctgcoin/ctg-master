CLEANFILES = *~

EXTRA_DIST = \
	ctg/__init__.py \
	ctg/ipython.py \
	ctg/data/__init__.py \
	ctg/plot/__init__.py \
	ctg/plot/config.py \
	ctg/plot/plotter.py

AM_TESTS_ENVIRONMENT = \
			 export ctg_TESTS_CONSTRAINTS="$(top_srcdir)/ctg/constraints"; \
			 export ctg_TESTS_PARAMETERS="$(top_srcdir)/ctg/parameters"; \
			 export PYTHONPATH="$(top_builddir)/python/.libs/:$(top_builddir)/python";

TEST_EXTENSIONS = .py
PY_LOG_COMPILER = $(PYTHON)
AM_PY_LOG_FLAGS =

if ctg_ENABLE_PYTHON

ctgdir = $(pkgpythondir)
ctg_PYTHON =
ctg_SCRIPTS = \
	ctg/__init__.py \
	ctg/ipython.py

ctgdatadir = $(pkgpythondir)/data
ctgdata_SCRIPTS = \
	ctg/data/__init__.py

ctgplotdir = $(pkgpythondir)/plot
ctgplot_SCRIPTS = \
	ctg/plot/__init__.py \
	ctg/plot/config.py \
	ctg/plot/plotter.py

_ctgdir = $(pythondir)
_ctg_LTLIBRARIES = _ctg.la
_ctg_la_SOURCES = _ctg.cc
_ctg_la_CXXFLAGS = $(PYTHON_CXXFLAGS) @AM_CXXFLAGS@
_ctg_la_LDFLAGS = -module -avoid-version -export-symbols-regex PyInit__ctg
_ctg_la_LIBADD = $(top_builddir)/ctg/libctg.la $(top_builddir)/ctg/utils/libctgutils.la -lboost_python$(BOOST_PYTHON_SUFFIX)

TESTS = \
	ctg_TEST.py

EXTRA_DIST += $(TESTS)

endif
