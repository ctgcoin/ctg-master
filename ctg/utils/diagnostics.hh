/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2013 
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

#ifndef ctg_GUARD_ctg_UTILS_DIAGNOSTICS_HH
#define ctg_GUARD_ctg_UTILS_DIAGNOSTICS_HH 1

#include <ctg/utils/private_implementation_pattern.hh>
#include <ctg/utils/wrapped_forward_iterator.hh>

#include <string>

namespace ctg
{
    /*!
     * Container for diagnostic values and corresponding metadata.
     * Used as part of the unit tests.
     */
    class Diagnostics :
        public PrivateImplementationPattern<Diagnostics>
    {
        public:
            struct Entry;

            ///@name Basic Operations.
            ///@{
            /// Constructor.
            Diagnostics();

            /// Destructor.
            ~Diagnostics();
            ///@}

            ///@name Access to Diagnostic Entries
            ///@{
            /// Add an entry to the container.
            void add(const Entry &);

            struct IteratorTag;
            /// Iterator over entries.
            typedef WrappedForwardIterator<IteratorTag, const Entry> Iterator;

            /// Returns Iterator pointing to the first entry.
            Iterator begin() const;

            /// Returns Iterator pointing beyond the last entry.
            Iterator end() const;

            /// Return the total number of entries.
            unsigned size() const;
            ///@}
    };

    extern template class WrappedForwardIterator<Diagnostics::IteratorTag, const Diagnostics::Entry>;

    /*!
     * Data structure representing one entry of several diagnostic
     * evaluations. Used as part of the unit tests.
     */
    struct Diagnostics::Entry
    {
        /// Numeric value for this entry.
        double value;

        /// Description for this entry, e.g. a reference to the underlying formula.
        std::string description;
    };
}

#endif
