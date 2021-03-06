/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2010, 2011, 2015 
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

#ifndef ctg_GUARD_SRC_UTILS_THREAD_POOL_HH
#define ctg_GUARD_SRC_UTILS_THREAD_POOL_HH 1

#include <ctg/utils/instantiation_policy.hh>
#include <ctg/utils/private_implementation_pattern.hh>
#include <ctg/utils/ticket.hh>

#include <functional>

namespace ctg
{
    class ThreadPool :
        public InstantiationPolicy<ThreadPool, Singleton>,
        public PrivateImplementationPattern<ThreadPool>
    {
        public:
            ThreadPool();

            ~ThreadPool();

            Ticket enqueue(const std::function<void (void)> & work);

            static ThreadPool * instance();

            void wait_for_free_capacity();

            unsigned number_of_threads() const;
    };
}

#endif
