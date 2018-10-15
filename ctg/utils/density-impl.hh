/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2016 
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

#ifndef ctg_GUARD_ctg_UTILS_DENSITY_IMPL_HH
#define ctg_GUARD_ctg_UTILS_DENSITY_IMPL_HH 1

#include <ctg/utils/density.hh>
#include <ctg/utils/wrapped_forward_iterator-impl.hh>

#include <vector>

namespace ctg
{
    template <>
    struct WrappedForwardIteratorTraits<Density::IteratorTag>
    {
        typedef std::vector<ParameterDescription>::const_iterator UnderlyingIterator;
    };
}

#endif
