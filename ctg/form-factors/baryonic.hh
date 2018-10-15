/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2014, 2015, 2016 
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

#ifndef ctg_GUARD_ctg_FORM_FACTORS_BARYONIC_HH
#define ctg_GUARD_ctg_FORM_FACTORS_BARYONIC_HH 1

#include <ctg/form-factors/form-factors-fwd.hh>
#include <ctg/utils/diagnostics.hh>
#include <ctg/utils/options.hh>
#include <ctg/utils/parameters.hh>

#include <memory>
#include <string>

namespace ctg
{
    /* Baryonic Tags */

    /*
     * J=1/2^+ -> J=1/2^+ transitions
     */
    struct OneHalfPlusToOneHalfPlus { };

    /*
     * J=1/2^+ -> J=1/2^- transitions
     */
    struct OneHalfPlusToOneHalfMinus { };

    /*
     * J=1/2^+ -> J=3/2^- transitions
     */
    struct OneHalfPlusToThreeHalfMinus { };

    template <>
    class FormFactors<OneHalfPlusToOneHalfPlus> :
        public ParameterUser
    {
        public:
            virtual ~FormFactors();

            virtual double f_time_v(const double & s) const = 0;
            virtual double f_long_v(const double & s) const = 0;
            virtual double f_perp_v(const double & s) const = 0;

            virtual double f_time_a(const double & s) const = 0;
            virtual double f_long_a(const double & s) const = 0;
            virtual double f_perp_a(const double & s) const = 0;

            virtual double f_long_t(const double & s) const = 0;
            virtual double f_perp_t(const double & s) const = 0;

            virtual double f_long_t5(const double & s) const = 0;
            virtual double f_perp_t5(const double & s) const = 0;
    };

    template <>
    class FormFactorFactory<OneHalfPlusToOneHalfPlus>
    {
        public:
            static std::shared_ptr<FormFactors<OneHalfPlusToOneHalfPlus>> create(const std::string & label, const Parameters & parameters, const Options & options = Options{ });
    };

    template <>
    class FormFactors<OneHalfPlusToOneHalfMinus> :
        public ParameterUser
    {
        public:
            virtual ~FormFactors();

            virtual double f_time_v(const double & s) const = 0;
            virtual double f_long_v(const double & s) const = 0;
            virtual double f_perp_v(const double & s) const = 0;

            virtual double f_time_a(const double & s) const = 0;
            virtual double f_long_a(const double & s) const = 0;
            virtual double f_perp_a(const double & s) const = 0;

            virtual Diagnostics diagnostics() const;
    };

    template <>
    class FormFactorFactory<OneHalfPlusToOneHalfMinus>
    {
        public:
            static std::shared_ptr<FormFactors<OneHalfPlusToOneHalfMinus>> create(const std::string & label, const Parameters & parameters, const Options & options = Options{ });
    };

    template <>
    class FormFactors<OneHalfPlusToThreeHalfMinus> :
        public ParameterUser
    {
        public:
            virtual ~FormFactors();

            virtual double f_time12_v(const double & s) const = 0;
            virtual double f_long12_v(const double & s) const = 0;
            virtual double f_perp12_v(const double & s) const = 0;
            virtual double f_perp32_v(const double & s) const = 0;

            virtual double f_time12_a(const double & s) const = 0;
            virtual double f_long12_a(const double & s) const = 0;
            virtual double f_perp12_a(const double & s) const = 0;
            virtual double f_perp32_a(const double & s) const = 0;

            virtual Diagnostics diagnostics() const;
    };

    template <>
    class FormFactorFactory<OneHalfPlusToThreeHalfMinus>
    {
        public:
            static std::shared_ptr<FormFactors<OneHalfPlusToThreeHalfMinus>> create(const std::string & label, const Parameters & parameters, const Options & options = Options{ });
    };
}

#endif
