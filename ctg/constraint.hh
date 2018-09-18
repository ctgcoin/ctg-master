/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2011-2018 Danny van Dyk
 *
 * This file is part of the EOS project. EOS is free software;
 * you can redistribute it and/or modify it under the terms of the GNU General
 * Public License version 2, as published by the Free Software Foundation.
 *
 * EOS is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA  02111-1307  USA
 */


#ifndef EOS_GUARD_SRC_CONSTRAINT_HH
#define EOS_GUARD_SRC_CONSTRAINT_HH 1

#include <eos/observable.hh>
#include <eos/statistics/log-likelihood-fwd.hh>
#include <eos/utils/iterator-range.hh>
#include <eos/utils/observable_cache.hh>
#include <eos/utils/private_implementation_pattern.hh>
#include <eos/utils/wrapped_forward_iterator.hh>

#include <vector>

// forward declaration
namespace YAML
{
    class Emitter;
    class Node;
}

namespace eos
{
    /*!
     * Constraint models experimental constraints via one or more LogLikelihoodBlock objects that
     * depend on one more Observable objects.
     */
    class Constraint :
        public PrivateImplementationPattern<Constraint>
    {
        public:
            /// Constructor.
            Constraint(const QualifiedName & name, const std::vector<ObservablePtr> & observable,
                    const std::vector<LogLikelihoodBlockPtr> & blocks);

            /// Destructor.
            ~Constraint();

            ///@name Access
            ///@{
            const QualifiedName & name() const;
            ///@}

            ///@name Iteration over Observables
            ///@{
            struct ObservableIteratorTag;
            typedef WrappedForwardIterator<ObservableIteratorTag, ObservablePtr> ObservableIterator;

            ObservableIterator begin_observables() const;
            ObservableIterator end_observables() const;
            ///@}

            ///@name Iteration over Blocks
            ///@{
            struct BlockIteratorTag;
            typedef WrappedForwardIterator<BlockIteratorTag, LogLikelihoodBlockPtr> BlockIterator;

            BlockIterator begin_blocks() const;
            BlockIterator end_blocks() const;
            ///@}

            /*!
             * Create one of the builtin constraints from a qualified name.
             *
             * @note You need to clone each LogLikelihoodBlock of a Constraint
             * to actually be able to use it.
             */
            static Constraint make(const QualifiedName & name, const Options & options);
    };
    extern template class WrappedForwardIterator<Constraint::BlockIteratorTag, LogLikelihoodBlockPtr>;
    extern template class WrappedForwardIterator<Constraint::ObservableIteratorTag, ObservablePtr>;

    /*!
     * ConstraintEntry is internally used to keep track of the Constraint and the factory method
     * for any given Constraint. This includes handling its construction (via the make() method), and
     * describing it (via the ostream & operator<<).
     */
    class ConstraintEntry
    {
        public:
            /*!
             * Create a new ConstraintEntry by deserializing a YAML node.
             */
            static ConstraintEntry * FromYAML(const QualifiedName & name, const YAML::Node &);

            /// Destructor
            virtual ~ConstraintEntry();

            /// Make a new constraint based on this entry.
            virtual Constraint make(const QualifiedName &, const Options &) const = 0;

            /// Return the entry's name
            virtual const QualifiedName & name() const = 0;

            /// Return the entry's type description
            virtual const std::string & type() const = 0;

            ///@name Iteration over our Observables
            ///@{
            struct ObservableNameIteratorTag;
            typedef WrappedForwardIterator<ObservableNameIteratorTag, const QualifiedName> ObservableNameIterator;

            virtual ObservableNameIterator begin_observable_names() const = 0;
            virtual ObservableNameIterator end_observable_names() const = 0;

            inline IteratorRange<ObservableNameIterator> observable_names() const
            {
                return IteratorRange<ObservableNameIterator>(begin_observable_names(), end_observable_names());
            }
            ///@}

            /// Serialize to YAML
            virtual void serialize(YAML::Emitter &) const = 0;
    };

    extern template class WrappedForwardIterator<ConstraintEntry::ObservableNameIteratorTag, const QualifiedName>;

    /*!
     * Container around the known and implemented constraints
     */
    class Constraints :
        public PrivateImplementationPattern<Constraints>
    {
    public:
        /// Constructor.
        Constraints();

        /// Destructor.
        ~Constraints();

        ///@name Iteration over known constraints
        ///@{
        struct ConstraintIteratorTag;
        typedef WrappedForwardIterator<ConstraintIteratorTag, const std::pair<const QualifiedName, const ConstraintEntry *>> ConstraintIterator;

        ConstraintIterator begin() const;
        ConstraintIterator end() const;
        ///@}
    };

    extern template class WrappedForwardIterator<Constraints::ConstraintIteratorTag, const std::pair<const QualifiedName, const ConstraintEntry *>>;

    /*!
     * UnknownConstraintError is thrown when Constraint::make encounters an unknown constraint name.
     */
    struct UnknownConstraintError :
        public Exception
    {
        ///@name Basic Functions
        ///@{
        /*!
         * Constructor.
         *
         * @param name The offending constraint name.
         */
        UnknownConstraintError(const QualifiedName & name);
        ///@}
    };

    /*!
     * ConstrainDeserializationError is thrown when ConstraintEntry::FromYAML or ConstrainEntry::deserialize
     * encounters an invalid YAML input.
     */
    struct ConstraintDeserializationError :
        public Exception
    {
        ///@name Basic Functions
        ///@{
        /*!
         * Constructor.
         *
         * @param type The name of the entry for which the error occured during deserialization.
         * @param msg  The error message.
         */
        ConstraintDeserializationError(const QualifiedName & name, const std::string & msg);
        ///@}
    };

    /*!
     * ConstrainInputFileParseError is thrown when an error occurs while parsing the constraint input files.
     */
    struct ConstraintInputFileParseError :
        public Exception
    {
        ///@name Basic Functions
        ///@{
        /*!
         * Constructor.
         *
         * @param filename The name of the constraint input file for which the error occured during deserialization.
         * @param msg      The error message.
         */
        ConstraintInputFileParseError(const std::string & filename, const std::string & msg);
        ///@}
    };
}

#endif
