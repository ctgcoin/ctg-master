/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2013, 2015 
 * Copyright (c) 2013 Frederik Beaujean
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

#ifndef ctg_GUARD_ctg_UTILS_DENSITY_HH
#define ctg_GUARD_ctg_UTILS_DENSITY_HH 1

#include <ctg/utils/density-fwd.hh>
#include <ctg/utils/hdf5-fwd.hh>
#include <ctg/utils/mutable-fwd.hh>
#include <ctg/utils/parameters.hh> // todo move ParameterDescription elsewhere and remove include
#include <ctg/utils/wrapped_forward_iterator.hh>

namespace ctg
{
    /*!
     * A multivariate scalar function
     */
    class Density
    {
        public:
            virtual ~Density() = 0;

            /*!
             * Evaluate the density function at the current parameter point
             * on the _log_ scale.
             */
            virtual double evaluate() const = 0;

            /// Create an independent copy of this density function.
            virtual DensityPtr clone() const = 0;

            /// Iterate over the parameters relevant to this density function.
            ///@{
            struct IteratorTag;
            typedef WrappedForwardIterator<IteratorTag, const ParameterDescription> Iterator;

            virtual Iterator begin() const = 0;
            virtual Iterator end() const = 0;
            ///@}

            /*!
             * Write parameter descriptions into the hdf5 file under the given data set name.
             */
            virtual void dump_descriptions(hdf5::File & file, const std::string & data_set_base) const;

            struct Output;
    };

    extern template class WrappedForwardIterator<Density::IteratorTag, const ParameterDescription>;

    /*!
     * Boilerplate code to handle I/O to HDF5 files
     */
    struct Density::Output
    {
        typedef hdf5::Composite<hdf5::Scalar<const char *>, hdf5::Scalar<double>, hdf5::Scalar<double>,
                                hdf5::Scalar<int>> DescriptionType;
        static DescriptionType description_type();
        static std::tuple<const char *, double, double, int> description_record();
    };

    /*!
     * A product of two multivariate scalar functions
     */
    class ProductDensity :
        public Density,
        public PrivateImplementationPattern<ProductDensity>
    {
        public:
            ProductDensity(const DensityPtr & x, const DensityPtr & y);
            virtual ~ProductDensity();

            /// Evaluate the density function at the current parameter point on the log scale.
            virtual double evaluate() const;

            /// Create an independent copy of this density function.
            virtual DensityPtr clone() const;

            /// Iterate over the parameters relevant to this density function.
            ///@{
            virtual Density::Iterator begin() const;
            virtual Density::Iterator end() const;
            ///@}
    };

}

#endif
