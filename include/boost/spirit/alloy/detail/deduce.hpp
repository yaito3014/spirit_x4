#ifndef BOOST_SPIRIT_ALLOY_DETAIL_DEDUCE_HPP
#define BOOST_SPIRIT_ALLOY_DETAIL_DEDUCE_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/spirit/alloy/access.hpp>
#include <boost/spirit/alloy/tuple_like.hpp>

#include <type_traits>

#include <cstddef>

namespace boost::spirit::alloy {

template<class FromLValue, class FromXValue>
struct deduce
{
    static_assert(std::conjunction_v<std::is_lvalue_reference<FromLValue>, std::is_reference<FromXValue>,
                                     std::is_same<std::remove_reference_t<FromLValue>, std::remove_reference_t<FromXValue>>>);
};

template<class T>
struct deduce<T&, T&>
{
    using type = T&;
};

template<class T>
struct deduce<T&, T&&>
{
    using type = T;
};

template<class FromLValue, class FromXValue>
using deduce_t = typename deduce<FromLValue, FromXValue>::type;

// Gets the i-th element type for both alloy::tuple and user-defined adapted type.
template<std::size_t I, class Tuple>
    requires TupleLike<std::remove_cvref_t<Tuple>>
using tuple_like_element_t = deduce_t<result_of::get<I, std::remove_cvref_t<Tuple>&>, result_of::get<I, std::remove_cvref_t<Tuple>&&>>;

}

#endif
