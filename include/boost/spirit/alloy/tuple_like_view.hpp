#ifndef BOOST_SPIRIT_ALLOY_TUPLE_LIKE_VIEW_HPP
#define BOOST_SPIRIT_ALLOY_TUPLE_LIKE_VIEW_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/spirit/alloy/tuple_like.hpp>
#include <boost/spirit/alloy/tuple_like_element.hpp>

#include <type_traits>
#include <utility>

namespace boost::spirit::alloy {

namespace detail {

template<TupleLike T, class IndexSeq = std::make_index_sequence<result_of::size<T>>>
struct is_view;

template<TupleLike T, std::size_t... Is>
struct is_view<T, std::index_sequence<Is...>> : std::conjunction<std::is_lvalue_reference<tuple_like_element_t<Is, T>>...> {};

} // detail

template<class T>
concept TupleLikeView = TupleLike<T> && detail::is_view<T>::value;

template<class T>
struct is_tuple_like_view : std::bool_constant<TupleLikeView<T>> {};

template<class T>
inline constexpr bool is_tuple_like_view_v = is_tuple_like<T>::value;

} // boost::spirit::alloy

#endif
