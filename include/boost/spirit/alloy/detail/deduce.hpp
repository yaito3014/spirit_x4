#ifndef BOOST_SPIRIT_ALLOY_DETAIL_DEDUCE_HPP
#define BOOST_SPIRIT_ALLOY_DETAIL_DEDUCE_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <type_traits>

namespace boost::spirit::alloy::detail {

template<class FromLValue, class FromXValue>
struct deduce
{
    static_assert(std::conjunction_v<std::is_reference<FromLValue>, std::is_reference<FromXValue>,
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

template<class T>
struct deduce<T&&, T&&>
{
    using type = T;
};

template<class FromLValue, class FromXValue>
using deduce_t = typename deduce<FromLValue, FromXValue>::type;

} // boost::spirit::alloy::detail

#endif
