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

#include <test/test.hh>
#include <ctg/utils/join.hh>

#include <list>
#include <vector>

#include <iostream>

using namespace test;
using namespace ctg;

class JoinTest :
    public TestCase
{
    public:
        JoinTest() :
            TestCase("join_test")
        {
        }

        virtual void run() const
        {
            // filled vector
            {
                std::vector<int> items{ 1, 4, 7 };

                std::cout << join(items.begin(), items.end()) << std::endl;
                TEST_CHECK_EQUAL("1, 4, 7", join(items.begin(), items.end()));
                TEST_CHECK_EQUAL("1, 4, 7", join(items.begin(), items.end(), ", "));
                TEST_CHECK_EQUAL("1:4:7",   join(items.begin(), items.end(), ":"));
            }

            // empty list
            {
                std::list<int> items;

                TEST_CHECK_EQUAL("", join(items.begin(), items.end()));
                TEST_CHECK_EQUAL("", join(items.begin(), items.end(), ", "));
                TEST_CHECK_EQUAL("", join(items.begin(), items.end(), ":"));
            }
        }
} join_test;
