#ifndef BOOST_SPIRIT_ALLOY_TUPLE_LIKE_HPP
#define BOOST_SPIRIT_ALLOY_TUPLE_LIKE_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/spirit/core/type_traits.hpp>

#include <type_traits>

namespace boost::spirit::alloy {

template<class... Ts>
class tuple;

template<class T>
struct adaptor;

template<class T>
concept TupleLike = is_ttp_specialization_of_v<T, tuple> || requires { typename adaptor<T>::getters_list; };

template<class T>
struct is_tuple_like : std::bool_constant<TupleLike<T>> {};

template<class T>
inline constexpr bool is_tuple_like_v = is_tuple_like<T>::value;

} // boost::spirit::alloy

#endif
