/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#ifndef ctg_GUARD_ctg_UTILS_CHAIN_GROUP_HH
#define ctg_GUARD_ctg_UTILS_CHAIN_GROUP_HH 1

#include <ctg/statistics/markov-chain.hh>
#include <ctg/utils/private_implementation_pattern-impl.hh>
#include <ctg/utils/wrapped_forward_iterator-impl.hh>

namespace ctg
{
    class ChainGroup :
        public PrivateImplementationPattern<ChainGroup>
    {
        public:
            typedef std::function<double (const std::vector<double> &, const std::vector<double> &, const unsigned &)> RValueFunction;

            /*!
             * Construct a cluster, which checks if two chains overlap by
             * using the R-value criterion. With only one chain, it
             * naturally overlaps with itself.
             *
             * @param rvalue_function Strict or relaxed version
             * @param max_rvalue
             * @param initial_chain
             * @param index
             * @param skip_initial Should be in [0,1]. The first portion of the chain's history is ignored when computing the R-value.
             */
            ChainGroup(const RValueFunction &, const double & max_rvalue, const HistoryPtr & initial_chain,
                    const unsigned & index, const double & skip_initial);

            ~ChainGroup();

            /*!
             * Add a chain (its history) to a cluster. Record its index.
             */
            void add(const HistoryPtr & chain, const unsigned & index);

            /*!
             * Calculate the cluster mean from the means of individual chains.
             *
             * @note Assumes that all chains have equal length.
             */
            std::vector<double> mean() const;

            const std::vector<std::vector<double>> & means() const;
            const std::vector<std::vector<double>> & variances() const;

            /*!
             * Check if chain overlaps with this cluster.
             * Internally, use the history of the chain, but to allow for burn-in,
             * the first iterations can be skipped when computing means and variances.
             *
             * @param chain
             * @param skip_initial A percentage, should be in range [0,1]
             * @return
             */
            bool overlaps(const HistoryPtr & chain) const;

            /*!
             * Set indices of parameters whose R value ought to be checked.
             * By default, all dimensions are checked.
             */
            void parameter_indices(const std::vector<unsigned> & indices);

            struct IteratorTag;
            typedef WrappedForwardIterator<IteratorTag, HistoryPtr> Iterator;
            Iterator begin() const;
            Iterator end() const;

            struct IndexIteratorTag;
            typedef WrappedForwardIterator<IndexIteratorTag, unsigned> IndexIterator;
            IndexIterator begin_indices() const;
            IndexIterator end_indices() const;
    };

    extern template class WrappedForwardIterator<ChainGroup::IteratorTag, HistoryPtr>;
    extern template class WrappedForwardIterator<ChainGroup::IndexIteratorTag, unsigned>;
}

#endif
