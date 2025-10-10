#ifndef BOOST_SPIRIT_ALLOY_COMMON_DEF_HPP
#define BOOST_SPIRIT_ALLOY_COMMON_DEF_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/spirit/alloy/detail/pack_indexing.hpp>

#include <boost/spirit/alloy/tuple_like.hpp>

#include <functional>
#include <type_traits>

#include <cstddef>

namespace boost::spirit::alloy {

struct value_initialize_t {};

inline constexpr value_initialize_t value_initialize{};

template<class... Ts>
class tuple;

namespace detail {

template<std::size_t I, class NonTypeList>
struct non_type_list_indexing {};

template<std::size_t I, template<auto...> class TList, auto... Vs>
struct non_type_list_indexing<I, TList<Vs...>> : non_type_pack_indexing<I, Vs...> {};

} // detail

namespace detail {

template<class T>
struct non_type_list_size {};

template<template<auto...> class TList, auto... Vs>
struct non_type_list_size<TList<Vs...>> : std::integral_constant<std::size_t, sizeof...(Vs)> {};

} // detail

template<class T>
struct tuple_size;

template<class T>
struct tuple_size<T const> : tuple_size<T> {};

template<class... Ts>
struct tuple_size<tuple<Ts...>> : std::integral_constant<std::size_t, sizeof...(Ts)> {};

template<TupleLike T>
    requires (!is_ttp_specialization_of_v<T, tuple>)
struct tuple_size<T> : detail::non_type_list_size<typename adaptor<T>::getters_list> {};

template<class T>
inline constexpr std::size_t tuple_size_v = tuple_size<T>::value;

namespace detail {

template<std::size_t I, class T>
inline constexpr auto getter_of = non_type_list_indexing<I, typename adaptor<T>::getters_list>::value;

} // detail

// gets i-th element in tuple-like object
template<std::size_t I, class T>
    requires TupleLike<std::remove_cvref_t<T>>
[[nodiscard]] constexpr decltype(auto) get(T&& x)
    noexcept(std::is_nothrow_invocable_v<decltype(detail::getter_of<I, std::remove_cvref_t<T>>), T>)
{
    return std::invoke(detail::getter_of<I, std::remove_cvref_t<T>>, std::forward<T>(x));
}

template<std::size_t I, class Tuple>
struct tuple_element {};

template<std::size_t I, class... Ts>
struct tuple_element<I, tuple<Ts...>> {
    using type = detail::type_pack_indexing_t<I, Ts...>;
};

template<std::size_t I, class Tuple>
using tuple_element_t = typename tuple_element<I, Tuple>::type;

template<std::size_t I, class... Ts>
[[nodiscard]] constexpr tuple_element_t<I, tuple<Ts...>>& get(tuple<Ts...>& t) noexcept;

template<std::size_t I, class... Ts>
[[nodiscard]] constexpr tuple_element_t<I, tuple<Ts...>> const& get(tuple<Ts...> const& t) noexcept;

template<std::size_t I, class... Ts>
[[nodiscard]] constexpr tuple_element_t<I, tuple<Ts...>>&& get(tuple<Ts...>&& t) noexcept;

template<std::size_t I, class... Ts>
[[nodiscard]] constexpr tuple_element_t<I, tuple<Ts...>> const&& get(tuple<Ts...> const&& t) noexcept;

} // boost::spirit::alloy

#endif
