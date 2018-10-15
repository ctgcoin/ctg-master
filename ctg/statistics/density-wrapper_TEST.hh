/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2013 Frederik Beaujean
 *
 * This file is part of the ctg project. ctg is free software;
 * you can redistribute it and/or modify it under the terms of the GNU General
 * Public License version 2, as published by the Free Software Foundation.
 *
 * ctg is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef ctg_GUARD_ctg_STATISTICS_DENSITY_TEST_HH
#define ctg_GUARD_ctg_STATISTICS_DENSITY_TEST_HH

#include <ctg/statistics/density-wrapper.hh>
#include <ctg/utils/private_implementation_pattern.hh>
#include <ctg/utils/wrapped_forward_iterator.hh>

#include <vector>

namespace ctg
{
    DensityWrapper make_multivariate_unit_normal(const unsigned & ndim);
}

#endif // ctg_GUARD_ctg_STATISTICS_DENSITY_TEST_HH
