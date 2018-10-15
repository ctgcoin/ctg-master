/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2008  <>
 *
 * Based upon 'instantiation_policy-impl.hh' from Paludis, which is:
 *     Copyright (c) 2005, 2006, 2007 Ciaran McCreesh
 *
 * This file is part of the ctg program. ctg is free software;
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

#ifndef ctg_GUARD_SRC_UTILS_INSTANTIATION_POLICY_IMPL_HH
#define ctg_GUARD_SRC_UTILS_INSTANTIATION_POLICY_IMPL_HH 1

#include <ctg/utils/instantiation_policy.hh>
#include <ctg/utils/lock.hh>
#include <ctg/utils/mutex.hh>

namespace ctg
{
    template <typename T_>
    void
    InstantiationPolicy<T_, Singleton>::_delete(T_ * ptr)
    {
        delete ptr;
    }

    template <typename T_>
    class InstantiationPolicy<T_, Singleton>::DeleteOnDestruction
    {
        private:
            T_ * * const _ptr;

        public:
            DeleteOnDestruction(T_ * * const ptr) :
                _ptr(ptr)
            {
            }

            ~DeleteOnDestruction()
            {
                InstantiationPolicy<T_, Singleton>::_delete(*_ptr);

                *_ptr = 0;
            }
    };

    template <typename T_>
    T_ * *
    InstantiationPolicy<T_, Singleton>::_instance_ptr()
    {
        static T_ * instance(0);
        static DeleteOnDestruction delete_instance(&instance);

        return &instance;
    }

    template <typename T_>
    T_ *
    InstantiationPolicy<T_, Singleton>::instance()
    {
        T_ * * instance_ptr(_instance_ptr());

        if (0 == *instance_ptr)
        {
            static Mutex m;
            Lock l(m);

            instance_ptr = _instance_ptr();

            if (0 == *instance_ptr)
            {
                *instance_ptr = new T_;
            }
        }

        return *instance_ptr;
    }
}

#endif
