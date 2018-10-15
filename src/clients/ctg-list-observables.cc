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

#include <ctg/observable.hh>
#include <ctg/utils/destringify.hh>
#include <ctg/utils/instantiation_policy-impl.hh>
#include <ctg/utils/log.hh>
#include <ctg/utils/parameters.hh>
#include <ctg/utils/stringify.hh>

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace ctg;

class DoUsage
{
    private:
        std::string _what;

    public:
        DoUsage(const std::string & what) :
            _what(what)
        {
        }

        const std::string & what() const
        {
            return _what;
        }
};

class CommandLine :
    public InstantiationPolicy<CommandLine, Singleton>
{
    public:
        CommandLine()
        {
        }

        void parse(int argc, char ** argv)
        {
            Log::instance()->set_program_name("ctg-list-observables");

            std::shared_ptr<Kinematics> kinematics(new Kinematics);

            for (char ** a(argv + 1), ** a_end(argv + argc) ; a != a_end ; ++a)
            {
                std::string argument(*a);

                throw DoUsage("Unknown command line argument: " + argument);
            }
        }
};

int
main(int argc, char * argv[])
{
    try
    {
        CommandLine::instance()->parse(argc, argv);

        Observables observables;

        for (auto o : observables)
        {
            std::cout
                << o.first << ":\n"
                << *o.second << "\n"
                << std::endl;
        }
    }
    catch(DoUsage & e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "Usage: ctg-list-observables" << std::endl;

        std::cout << "Print the database of implemented observables." << std::endl;
    }
    catch(Exception & e)
    {
        std::cerr << "Caught exception: '" << e.what() << "'" << std::endl;
        return EXIT_FAILURE;
    }
    catch(...)
    {
        std::cerr << "Aborting after unknown exception" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
