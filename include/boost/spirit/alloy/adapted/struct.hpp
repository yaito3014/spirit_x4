#ifndef BOOST_SPIRIT_ALLOY_ADAPTED_STRUCT_HPP
#define BOOST_SPIRIT_ALLOY_ADAPTED_STRUCT_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

namespace boost::spirit::alloy {

namespace detail {

template<auto... Vs>
struct non_type_list;

} // detail

template<class T>
struct adaptor;

template<auto... Getters>
using make_getters_list = detail::non_type_list<Getters...>;

} // boost::spirit::alloy

#endif
