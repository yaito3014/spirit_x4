#ifndef BOOST_SPIRIT_ALLOY_NON_TYPE_LIST_HPP
#define BOOST_SPIRIT_ALLOY_NON_TYPE_LIST_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/spirit/alloy/detail/pack_indexing.hpp>

#include <type_traits>

#include <cstddef>

namespace boost::spirit::alloy {

template<auto... Vs>
struct non_type_list
{
    static constexpr std::size_t size = sizeof...(Vs);

    template<std::size_t I>
    static constexpr auto get = detail::non_type_pack_indexing_v<I, Vs...>;
};

namespace detail {

template<class T>
struct is_non_type_list : std::false_type {};

template<auto... Vs>
struct is_non_type_list<non_type_list<Vs...>> : std::true_type {};

} // detail

} // boost::spirit::alloy

#endif
