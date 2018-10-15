/* vim: set sw=4 sts=4 et foldmethod=syntax : */
/*
 * Copyright (c) 2011 
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

#include <ctg/utils/memoise.hh>

namespace ctg
{
    MemoisationControl::MemoisationControl() :
        _mutex(new Mutex)
    {
    }

    MemoisationControl::~MemoisationControl()
    {
        delete _mutex;
    }

    void
    MemoisationControl::register_clear_function(const std::function<void ()> & clear_function)
    {
        Lock l(*_mutex);

        _clear_functions.push_back(clear_function);
    }

    void
    MemoisationControl::clear()
    {
        Lock l(*_mutex);

        for (auto c = _clear_functions.begin(), c_end = _clear_functions.end() ; c != c_end ; ++c)
        {
            (*c)();
        }
    }
}
