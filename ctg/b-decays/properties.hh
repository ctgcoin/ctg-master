/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2012 
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

#ifndef ctg_GUARD_ctg_B_DECAYS_PROPERTIES_HH
#define ctg_GUARD_ctg_B_DECAYS_PROPERTIES_HH 1

#include <ctg/utils/options.hh>
#include <ctg/utils/parameters.hh>
#include <ctg/utils/private_implementation_pattern.hh>

namespace ctg
{
    /*
     * Properties of B_q mesons
     */
    class BMesonProperties :
        public ParameterUser,
        public PrivateImplementationPattern<BMesonProperties>
    {
        public:
            BMesonProperties(const Parameters & parameters, const Options & options);
            ~BMesonProperties();

            // Properties
            double mass_splitting_j1_j0() const;
    };
}

#endif
