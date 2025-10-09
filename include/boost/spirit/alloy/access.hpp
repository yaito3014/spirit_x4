#ifndef BOOST_SPIRIT_ALLOY_ACCESS_HPP
#define BOOST_SPIRIT_ALLOY_ACCESS_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/spirit/alloy/detail/pack_indexing.hpp>

#include <boost/spirit/alloy/tuple_like.hpp>

#include <functional>
#include <type_traits>
#include <utility>

#include <cstddef>

namespace boost::spirit::alloy {

namespace detail {

template<class NonTypeList>
struct non_type_list_size {};

template<template<auto...> class TList, auto... Vs>
struct non_type_list_size<TList<Vs...>> : std::integral_constant<std::size_t, sizeof...(Vs)> {};

template<std::size_t I, class NonTypeList>
struct non_type_list_indexing {};

template<std::size_t I, template<auto...> class TList, auto... Vs>
struct non_type_list_indexing<I, TList<Vs...>> : non_type_pack_indexing<I, Vs...> {};

} // detail

namespace result_of {

template<class T>
    requires TupleLike<std::remove_cvref_t<T>>
inline constexpr std::size_t size = detail::non_type_list_size<typename adaptor<std::remove_cvref_t<T>>::getters_list>::value;

} // result_of

template<class T>
    requires TupleLike<std::remove_cvref_t<T>>
constexpr std::size_t size(T&&) noexcept
{
    return result_of::size<T>;
}

namespace result_of {

// `std::invoke_result_t` MUST NOT be used here due to its side effects:
// <https://eel.is/c++draft/meta.trans.other#tab:meta.trans.other-row-11-column-2-note-2>
template<std::size_t I, class T>
    requires TupleLike<std::remove_cvref_t<T>>
using get = decltype(std::invoke(detail::non_type_list_indexing<I, typename adaptor<std::remove_cvref_t<T>>::getters_list>::value, std::declval<T>()));

} // result_of

template<std::size_t I, class T>
    requires TupleLike<std::remove_cvref_t<T>>
constexpr result_of::get<I, T> get(T&& x)
    noexcept(noexcept(std::is_nothrow_invocable_v<decltype(detail::non_type_list_indexing<I, typename adaptor<std::remove_cvref_t<T>>::getters_list>::value), T>))
{
    return std::invoke(detail::non_type_list_indexing<I, typename adaptor<std::remove_cvref_t<T>>::getters_list>::value, std::forward<T>(x));
}

} // boost::spirit::alloy

#endif
