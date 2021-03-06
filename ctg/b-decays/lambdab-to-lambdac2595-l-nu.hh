/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2017 Elena Graverini
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

#ifndef ctg_GUARD_ctg_B_DECAYS_LAMBDAB_TO_LAMBDAC2595_L_NU_HH
#define ctg_GUARD_ctg_B_DECAYS_LAMBDAB_TO_LAMBDAC2595_L_NU_HH 1

#include <ctg/utils/options.hh>
#include <ctg/utils/parameters.hh>
#include <ctg/utils/private_implementation_pattern.hh>

namespace ctg
{
    /*
     * Decay: Lambda_b -> Lambda_c(2595) l nu
     */
    class LambdaBToLambdaC2595LeptonNeutrino :
        public ParameterUser,
        public PrivateImplementationPattern<LambdaBToLambdaC2595LeptonNeutrino>
    {
        public:
            LambdaBToLambdaC2595LeptonNeutrino(const Parameters & parameters, const Options & options);
            ~LambdaBToLambdaC2595LeptonNeutrino();

            // Angular coefficients
            double a_l(const double & s) const;
            double b_l(const double & s) const;
            double c_l(const double & s) const;
            double gamma_0(const double & s) const;

            // Differential Observables
            double differential_branching_ratio(const double & s) const;
            double double_differential_branching_ratio(const double & s, const double & theta_l) const;

            // Integrated Observables
            double integrated_branching_ratio(const double & s_min, const double & s_max) const;
            double integrated_forward_backward_asymmetry(const double & s_min, const double & s_max) const;

            // Integrated Observables (normalized to 1)
            double normalized_integrated_branching_ratio(const double & s_min, const double & s_max) const;

            // R_Lambda_c_2595
            double differential_r_lambdac2595(const double & s) const;
            double integrated_r_lambdac2595() const;

            /*!
             * Descriptions of the process and its kinematics.
             */
            static const std::string description;
            static const std::string kinematics_description_s;
            static const std::string kinematics_description_c_theta_l;
    };
}

#endif
