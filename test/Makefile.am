CLEANFILES = *~
MAINTAINERCLEANFILES = Makefile.in

AM_CXXFLAGS = -I$(top_srcdir) -std=c++0x -Wall -Wextra -pedantic

noinst_LIBRARIES = libctgtest.a

libctgtest_a_SOURCES = \
	test.cc test.hh

TESTS = \
	test_TEST
LDADD = libctgtest.a \
	$(top_builddir)/ctg/utils/libctgutils.la \
	$(top_builddir)/ctg/libctg.la

check_PROGRAMS = $(TESTS)

test_TEST_SOURCES = test_TEST.cc
