/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2016, 2017 
 *
 * Copied from the Paludis package manager, which is
 * Copyright (c) 2007 Ciaran McCreesh
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

#ifndef ctg_GUARD_ctg_UTILS_INDIRECT_ITERATOR_FWD_HH
#define ctg_GUARD_ctg_UTILS_INDIRECT_ITERATOR_FWD_HH 1

#include <iterator>

namespace ctg
{
    template <typename>
    struct IndirectIteratorValueType;

    template <typename Iter_, typename Value_ = typename IndirectIteratorValueType<
        typename std::iterator_traits<Iter_>::value_type>::Type>
    class IndirectIterator;

    template <typename Iter_>
    IndirectIterator<Iter_> indirect_iterator(const Iter_ &);

    template <typename Iter_, typename Value_>
    bool operator== (const IndirectIterator<Iter_, Value_> &, const IndirectIterator<Iter_, Value_> &);

    template <typename Iter_, typename Value_>
    bool operator!= (const IndirectIterator<Iter_, Value_> &, const IndirectIterator<Iter_, Value_> &);

    template <typename Iter_, typename Value_>
    bool operator< (const IndirectIterator<Iter_, Value_> &, const IndirectIterator<Iter_, Value_> &);

    template <typename Iter_, typename Value_>
    bool operator> (const IndirectIterator<Iter_, Value_> &, const IndirectIterator<Iter_, Value_> &);
}

#endif
