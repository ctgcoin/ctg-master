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

#ifndef ctg_GUARD_ctg_FORM_FACTORS_ANALYTIC_B_TO_KSTAR_HH
#define ctg_GUARD_ctg_FORM_FACTORS_ANALYTIC_B_TO_KSTAR_HH 1

#include <ctg/form-factors/mesonic.hh>
#include <ctg/utils/diagnostics.hh>
#include <ctg/utils/parameters.hh>
#include <ctg/utils/options.hh>

namespace ctg
{
    class AnalyticFormFactorBToKstarKMO2006 :
        public FormFactors<PToV>,
        PrivateImplementationPattern<AnalyticFormFactorBToKstarKMO2006>
    {
        public:
            AnalyticFormFactorBToKstarKMO2006(const Parameters &, const Options &);

            ~AnalyticFormFactorBToKstarKMO2006();

            static FormFactors<PToV> * make(const Parameters &, unsigned);

            /* Form factors */
            virtual double v(const double & s) const;

            virtual double a_0(const double & s) const;
            virtual double a_1(const double & s) const;
            virtual double a_2(const double & s) const;
            virtual double a_12(const double & s) const;

            virtual double t_1(const double & s) const;
            virtual double t_2(const double & s) const;
            virtual double t_3(const double & s) const;
            virtual double t_23(const double & s) const;

            /* Diagnostics for unit tests */
            Diagnostics diagnostics() const;
    };
}

#endif
