/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_SPIRIT_ALLOY_DETAIL_INTEGER_SEQ_TRANSFORM_HPP
#define BOOST_SPIRIT_ALLOY_DETAIL_INTEGER_SEQ_TRANSFORM_HPP

#include <boost/spirit/alloy/non_type_list.hpp>

#include <utility>

namespace boost::spirit::alloy::detail
{
    template <typename IntegerSeq, template <typename IntegerSeq::value_type> typename F>
    struct integer_seq_transform;
    
    template <typename T, T... Is, template <T> typename F>
    struct integer_seq_transform<std::integer_sequence<T, Is...>, F>
    {
        using type = non_type_list<F<Is>::value...>;
    };

    template <typename IntegerSeq, template <typename IntegerSeq::value_type> typename F>
    using integer_seq_transform_t = typename integer_seq_transform<IntegerSeq, F>::type;
} // boost::spirit::alloy::detail

#endif
