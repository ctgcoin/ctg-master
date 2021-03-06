/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2016 
 *
 * Copied from the Paludis package manager, which is
 * Copyright (c) 2008-2010 Ciaran McCreesh
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

#ifndef ctg_GUARD_ctg_UTILS_TYPE_LIST_HH
#define ctg_GUARD_ctg_UTILS_TYPE_LIST_HH 1

#include <ctg/utils/type-list-fwd.hh>

namespace ctg
{
    struct TypeListTail
    {
    };

    template <typename Item_, typename Tail_>
    struct TypeListEntry
    {
        typedef Item_ Item;
        typedef Tail_ Tail;
    };

    template <>
    struct MakeTypeList<>
    {
        typedef TypeListTail Type;
    };

    template <typename H_, typename... T_>
    struct MakeTypeList<H_, T_...>
    {
        typedef TypeListEntry<H_, typename MakeTypeList<T_...>::Type> Type;
    };

    template <>
    struct MakeTypeListConstEntry<TypeListTail>
    {
        typedef TypeListTail Type;
    };

    template <typename Item_, typename Tail_>
    struct MakeTypeListConstEntry<TypeListEntry<Item_, Tail_> >
    {
        typedef TypeListEntry<const Item_, typename MakeTypeListConstEntry<Tail_>::Type> Type;
    };

    template <typename TypeList_>
    struct MakeTypeListConst
    {
        typedef typename MakeTypeListConstEntry<TypeList_>::Type Type;
    };

    template <typename Item_>
    struct TypeListContains<TypeListTail, Item_>
    {
        enum { value = 0 };
    };

    template <typename Item_, typename Tail_>
    struct TypeListContains<TypeListEntry<Item_, Tail_>, Item_>
    {
        enum { value = 1 };
    };

    template <typename NotItem_, typename Item_, typename Tail_>
    struct TypeListContains<TypeListEntry<NotItem_, Tail_>, Item_>
    {
        enum { value = TypeListContains<Tail_, Item_>::value };
    };
}

#endif
