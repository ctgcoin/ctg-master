/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2010, 2011, 2012 
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

#ifndef ctg_GUARD_SRC_RARE_B_DECAYS_EXCLUSIVE_B_TO_S_GAMMA_HH
#define ctg_GUARD_SRC_RARE_B_DECAYS_EXCLUSIVE_B_TO_S_GAMMA_HH 1

#include <ctg/decays.hh>
#include <ctg/utils/complex.hh>
#include <ctg/utils/options.hh>
#include <ctg/utils/parameters.hh>
#include <ctg/utils/private_implementation_pattern.hh>

namespace ctg
{
    /*!
     * Calculates observables in B->K^*gamma decays
     */
    class BToKstarGamma :
        public ParameterUser,
        public PrivateImplementationPattern<BToKstarGamma>
    {
        public:
            BToKstarGamma(const Parameters & parameters, const Options & options);
            ~BToKstarGamma();

            /// Branching Ratio
            double branching_ratio() const;

            /// Branching Ratio (CP averaged)
            double branching_ratio_cp_averaged() const;

            /// Direct CP asymmetry A_CP
            double cp_asymmetry() const;

            /// Time dependent CP asymmetry S_K^*gamma
            double s_kstar_gamma() const;

            /// Time dependent CP asymmetry C_K^*gamma
            double c_kstar_gamma() const;

            /// Isospin asymmetry
            double isospin_asymmetry() const;
    };
}

#endif
