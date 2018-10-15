/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2016 
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

#ifndef ctg_GUARD_ctg_B_DECAYS_B_TO_PI_L_X_NU_HH
#define ctg_GUARD_ctg_B_DECAYS_B_TO_PI_L_X_NU_HH 1

#include <ctg/utils/options.hh>
#include <ctg/utils/parameters.hh>
#include <ctg/utils/private_implementation_pattern.hh>

namespace ctg
{
    /*
     * Decay: B -> pi l X_nu
     */
    class BToPiLeptonInclusiveNeutrinos :
        public ParameterUser,
        public PrivateImplementationPattern<BToPiLeptonInclusiveNeutrinos>
    {
        public:
            BToPiLeptonInclusiveNeutrinos(const Parameters & parameters, const Options & options);
            ~BToPiLeptonInclusiveNeutrinos();

            double normalized_differential_decay_width_1nu(const double & s, const double & c_theta_tau) const;

            double normalized_differential_decay_width_3nu(const double & s, const double & snunubar,
                    const double & c_theta_tau, const double & phi, const double & c_theta_mu_star) const;

            /*!
             * Descriptions of the process and its kinematics.
             */
            static const std::string description;
            static const std::string kinematics_description_s;
            static const std::string kinematics_description_snunubar;
            static const std::string kinematics_description_c_theta;
            static const std::string kinematics_description_c_theta_tau;
            static const std::string kinematics_description_c_theta_mu_star;
            static const std::string kinematics_description_phi;
    };
}

#endif
