#ifndef BOOST_SPIRIT_ALLOY_TUPLE_LIKE_ELEMENT_HPP
#define BOOST_SPIRIT_ALLOY_TUPLE_LIKE_ELEMENT_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/spirit/alloy/detail/deduce.hpp>

#include <boost/spirit/alloy/tuple_like.hpp>

#include <type_traits>

#include <cstddef>

namespace boost::spirit::alloy {

// Gets the i-th element type for both alloy::tuple and user-defined adapted type.

template<std::size_t I, class Tuple>
    requires TupleLike<std::remove_cvref_t<Tuple>>
struct tuple_like_element
{
    using type = detail::deduce_t<detail::tuple_get_t<I, std::remove_cvref_t<Tuple>&>&&, detail::tuple_get_t<I, std::remove_cvref_t<Tuple>&&>&&>;
};

template<std::size_t I, class Tuple>
    requires TupleLike<std::remove_cvref_t<Tuple>>
using tuple_like_element_t = typename tuple_like_element<I, Tuple>::type;

} // boost::spirit::alloy

#endif
