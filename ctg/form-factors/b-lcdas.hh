/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2017 
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

#ifndef ctg_GUARD_ctg_FORM_FACTORS_B_LCDAS_HH
#define ctg_GUARD_ctg_FORM_FACTORS_B_LCDAS_HH 1

#include <ctg/utils/diagnostics.hh>
#include <ctg/utils/parameters.hh>
#include <ctg/utils/options.hh>

namespace ctg
{
    /*!
     * Decomposition of B-meson to vacuum matrix elements of light-cone
     * dominated operators.
     *
     * For the two-particle decomposition, we use the parametrization as
     * defined in [KMO2006], eq. (17), p. 7.
     *
     * For the three-particle decomposition, we use the parametrization
     * as defined in [KMO2006], eq. (28), p. 10.
     */
    class BMesonLCDAs :
        public ParameterUser,
        public PrivateImplementationPattern<BMesonLCDAs>
    {
        public:
            BMesonLCDAs(const Parameters &, const Options &);
            ~BMesonLCDAs();

            /*!
             * Leading power two-particle LCDAs
             *
             * omega: plus-component of the spectator momentum
             */
            double phi_plus(const double & omega) const;
            double phi_minus(const double & omega) const;
            double Phibar(const double & omega) const;

            /*!
             * Pseudo observables for the two-particle LCDAs
             */
            double inverse_lambda_plus() const;

            /*!
             * Leading power three-particle LCDAs
             *
             * omega: plus-component of the spectator momentum
             * xi:    plus-component of the gluon momentum
             * */
            double psi_A(const double & omega, const double & xi) const;
            double psi_V(const double & omega, const double & xi) const;
            double X_A(const double & omega, const double & xi) const;
            double Y_A(const double & omega, const double & xi) const;

            /*!
             * Auxiliary functions for the three-particle LCDAs
             *
             * See [KMO2006], below eq. (72), p. 28 for their definition.
             */
            double Xbar_A(const double & omega, const double & xi) const;
            double Ybar_A(const double & omega, const double & xi) const;

            /* Internal diagnostics */
            Diagnostics diagnostics() const;
    };
}

#endif
