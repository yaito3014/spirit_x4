#ifndef BOOST_SPIRIT_ALLOY_COMMON_DEF_HPP
#define BOOST_SPIRIT_ALLOY_COMMON_DEF_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/spirit/alloy/detail/deduce.hpp>
#include <boost/spirit/alloy/detail/pack_indexing.hpp>

#include <boost/spirit/core/type_traits.hpp>

#include <functional>
#include <type_traits>

#include <cstddef>

namespace boost::spirit::alloy {

template<class T>
struct adaptor;

namespace detail {

template<class T>
struct non_type_list_size {};

template<template<auto...> class TList, auto... Vs>
struct non_type_list_size<TList<Vs...>> : std::integral_constant<std::size_t, sizeof...(Vs)> {};

template<std::size_t I, class NonTypeList>
struct non_type_list_indexing {};

template<std::size_t I, template<auto...> class TList, auto... Vs>
struct non_type_list_indexing<I, TList<Vs...>> : non_type_pack_indexing<I, Vs...> {};

template<std::size_t I, class T>
inline constexpr auto getter_of = non_type_list_indexing<I, typename adaptor<T>::getters_list>::value;

} // detail

struct value_initialize_t {};

inline constexpr value_initialize_t value_initialize{};

template<class... Ts>
class tuple;

template<class T>
struct adaptor;

template<class T>
concept Adapted = requires { typename adaptor<T>::getters_list; };

template<class T>
concept TupleLike = is_ttp_specialization_of_v<T, tuple> || Adapted<T>;

template<class T>
struct is_tuple_like : std::bool_constant<TupleLike<T>> {};

template<class T>
inline constexpr bool is_tuple_like_v = is_tuple_like<T>::value;

template<class T>
struct tuple_size {};

template<class T>
struct tuple_size<T const> : tuple_size<T> {};

template<class... Ts>
struct tuple_size<tuple<Ts...>> : std::integral_constant<std::size_t, sizeof...(Ts)> {};

template<Adapted T>
struct tuple_size<T> : detail::non_type_list_size<typename adaptor<T>::getters_list> {};

template<class T>
inline constexpr std::size_t tuple_size_v = tuple_size<T>::value;

template<std::size_t I, class Tuple>
struct tuple_element {};

template<std::size_t I, class... Ts>
struct tuple_element<I, tuple<Ts...>>
{
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

template<std::size_t I, class T>
    requires Adapted<std::remove_cvref_t<T>>
[[nodiscard]] constexpr auto get(T&& x)
    noexcept(std::is_nothrow_invocable_v<decltype(detail::getter_of<I, std::remove_cvref_t<T>>), T>)
    -> std::invoke_result_t<decltype(detail::getter_of<I, std::remove_cvref_t<T>>), T>
{
    return std::invoke(detail::getter_of<I, std::remove_cvref_t<T>>, std::forward<T>(x));
}

namespace detail {

template<std::size_t I, class T>
using tuple_get_t = decltype(alloy::get<I>(std::declval<T>()));

template<std::size_t I, class T>
struct is_nothrow_gettable : std::bool_constant<noexcept(alloy::get<I>(std::declval<T>()))> {};

template<std::size_t I, class T>
inline constexpr bool is_nothrow_gettable_v = is_nothrow_gettable<I, T>::value;

} // detail

template<std::size_t I, Adapted T>
struct tuple_element<I, T>
{
    using type = detail::deduce_t<detail::tuple_get_t<I, std::remove_cvref_t<T>&>&&, detail::tuple_get_t<I, std::remove_cvref_t<T>&&>&&>;
};

namespace detail {

template<TupleLike T, class IndexSeq = std::make_index_sequence<tuple_size_v<T>>>
struct is_view;

template<TupleLike T, std::size_t... Is>
struct is_view<T, std::index_sequence<Is...>> : std::conjunction<std::is_lvalue_reference<tuple_element_t<Is, T>>...> {};

} // detail

template<class T>
concept TupleLikeView = TupleLike<T> && detail::is_view<T>::value;

template<class T>
struct is_tuple_like_view : std::bool_constant<TupleLikeView<T>> {};

template<class T>
inline constexpr bool is_tuple_like_view_v = is_tuple_like<T>::value;

} // boost::spirit::alloy

#endif
