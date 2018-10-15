/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2007  <>
 *
 * Based upon 'condition_variable.hh' from Paludis, which is:
 *     Copyright (c) 2007 Ciaran McCreesh
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

#ifndef ctg_GUARD_SRC_UTILS_CONDITION_VARIABLE_HH
#define ctg_GUARD_SRC_UTILS_CONDITION_VARIABLE_HH 1

#include <ctg/utils/instantiation_policy.hh>
#include <ctg/utils/mutex.hh>

#include <pthread.h>

namespace ctg
{
    class ConditionVariable :
        public InstantiationPolicy<ConditionVariable, NonCopyable>
    {
        private:
            /// Our pthread condition variable.
            pthread_cond_t * const _cond;

        public:
            /// Constructor.
            ConditionVariable();

            /// Destructor.
            ~ConditionVariable();

            /// Broadcast a wake-up to all waiting threads.
            void broadcast();

            /// Sign a wake-up to the waiting thread.
            void signal();

            /// Acquire a lock for signaling.
            void acquire_then_signal(Mutex &);

            /// Wait until condition is met.
            void wait(Mutex &);
    };
}

#endif
