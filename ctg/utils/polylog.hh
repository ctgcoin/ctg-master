/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#ifndef ctg_GUARD_ctg_UTILS_POLYLOG_HH
#define ctg_GUARD_ctg_UTILS_POLYLOG_HH 1

#include <ctg/utils/complex.hh>

namespace ctg
{
    complex<double> dilog(const complex<double> & z) __attribute__ ((pure));

    complex<double> trilog(const complex<double> & z) __attribute__ ((pure));
}

#endif
