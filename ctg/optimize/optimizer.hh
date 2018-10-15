/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2015, 2016 
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

#ifndef ctg_GUARD_ctg_OPTIMIZE_OPTIMIZER_HH
#define ctg_GUARD_ctg_OPTIMIZE_OPTIMIZER_HH 1

#include <ctg/utils/density.hh>
#include <ctg/utils/exception.hh>
#include <ctg/utils/parameters.hh>

#include <functional>
#include <string>
#include <vector>

namespace ctg
{
    class Optimizer;

    typedef std::shared_ptr<Optimizer> OptimizerPtr;

    /*!
     * Optimizer takes a Density and modified its parameters such that the
     * density function is optimized (maximized or minimized).
     */
    class Optimizer
    {
        public:
            virtual ~Optimizer() = 0;

            /// Maximize the density function, starting from the current parameter point.
            virtual double maximize() = 0;

            /// Minimize the density function, starting from the current parameter point.
            virtual double minimize() = 0;
    };

    /*!
     * An OptimizerError is thrown when one of the Optimizer classes encounters
     * an error.
     */
    class OptimizerError :
        public Exception
    {
        public:
            OptimizerError(const std::string & message) throw ();
    };
}

#endif
