/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2017 
 * Copyright (c) 2017 Elena Graverini
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


#ifndef ctg_GUARD_ctg_FORM_FACTORS_HQET_B_TO_C_HH
#define ctg_GUARD_ctg_FORM_FACTORS_HQET_B_TO_C_HH 1

#include <ctg/utils/diagnostics.hh>
#include <ctg/utils/options.hh>
#include <ctg/utils/parameters.hh>
#include <ctg/utils/private_implementation_pattern.hh>

namespace ctg
{
    class HQETBToC :
        public ParameterUser,
        public PrivateImplementationPattern<HQETBToC>
    {
        public:
            HQETBToC(const Parameters &, const Options &);
            ~HQETBToC();

            /*!
             * Matching coefficients for heavy-to-heavy b -> c vector currents, as
             * functions of the cusp omega.
             */
            // @{
            double c_1_vector(const double & omega) const;
            double c_2_vector(const double & omega) const;
            double c_3_vector(const double & omega) const;
            // @}

            /*!
             * Matching coefficients for heavy-to-heavy b -> c axial vector currents,
             * as functions of the cusp omega.
             */
            // @{
            double c_1_axialvector(const double & omega) const;
            double c_2_axialvector(const double & omega) const;
            double c_3_axialvector(const double & omega) const;
            // @}

            /* Diagnostics for unit tests */
            Diagnostics diagnostics() const;
    };
}

#endif
