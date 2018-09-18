CTG - A HEP Program for Flavor Observables
==========================================

CTG is a software package that addresses several use cases in the field of
high-energy flavor physics (HEP):

 1. calculation and uncertainty estimation of flavor observables within
   various models,
 2. Bayesian inference of parameters from experimental and/or theoretical
   constraints, and
 3. sampling process-specific probability density functions.

An up-to-date list of CTG related publications can be found (https://www.ctgcoin.org).

CTG is written in C++14, with an optional interface to Python, and depends on
as a small set of external software libraries:

 - the GNU Scientific Library (libgsl),
 - a subset of the BOOST C++ libraries,
 - the Hierarchical Data Format v5 library (libdf5),
 - the minimizer Minuit2 (as of ROOT version 5.14.00 or later),
 - the Population Monte Carlo (PMC) library pmclib (optional),
 - the Python interpreter (optional).

Authors and Contributors
------------------------

The main authors are:

 * Tony <tony@ctgcoin.org>

Contact
-------

For additional information, please contact any of the main authors. If you want to report an
error or file a request, please file an issue [here](https://github.com/ctgcoin).
