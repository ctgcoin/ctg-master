/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2017, 2018 
 * Copyright (c) 2018 Ahmet Kokulu
 * Copyright (c) 2018 Christoph Bobeth
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

#ifndef ctg_GUARD_ctg_UTILS_OPTIONS_IMPL_HH
#define ctg_GUARD_ctg_UTILS_OPTIONS_IMPL_HH 1

#include <ctg/utils/join.hh>
#include <ctg/utils/options.hh>

#include <algorithm>

namespace ctg
{
    class SwitchOption
    {
        public:
            std::string _value;

        public:
            SwitchOption(const Options & options, const std::string & key,
                    const std::initializer_list<std::string> & allowed_values)
            {
                if (allowed_values.begin() == allowed_values.end())
                {
                    throw InternalError("SwitchOption: The list of allowed_values is empty");
                }

                if (! options.has(key))
                {
                    throw UnspecifiedOptionError(key, join(allowed_values.begin(), allowed_values.end()));
                }

                _value = options[key];

                if (std::find(allowed_values.begin(), allowed_values.end(), _value) == allowed_values.end())
                {
                    throw InvalidOptionValueError(key, _value, join(allowed_values.begin(), allowed_values.end()));
                }
            }

            SwitchOption(const Options & options, const std::string & key,
                    const std::initializer_list<std::string> & allowed_values,
                    const std::string & default_value) :
                _value(options.get(key, default_value))
            {
                if (allowed_values.begin() == allowed_values.end())
                {
                    throw InternalError("SwitchOption: The list of allowed_values is empty");
                }

                if (std::find(allowed_values.begin(), allowed_values.end(), default_value) == allowed_values.end())
                {
                    throw InternalError("SwitchOption: The default value '" + default_value + "'is not in the list of allowed values: '" + join(allowed_values.begin(), allowed_values.end()) + "'");
                }

                if (std::find(allowed_values.begin(), allowed_values.end(), _value) == allowed_values.end())
                {
                    throw InvalidOptionValueError(key, _value, join(allowed_values.begin(), allowed_values.end()));
                }
            }

            ~SwitchOption() = default;

            const std::string & value() const { return _value; };
    };
}

#endif
