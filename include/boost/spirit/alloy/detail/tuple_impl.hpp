/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_SPIRIT_ALLOY_DETAIL_TUPLE_IMPL_HPP
#define BOOST_SPIRIT_ALLOY_DETAIL_TUPLE_IMPL_HPP

#include <boost/spirit/config.hpp>

#include <boost/spirit/alloy/detail/combine_ref.hpp>
#include <boost/spirit/alloy/detail/forward_like_t.hpp>
#include <boost/spirit/alloy/detail/pack_indexing.hpp>

#include <boost/spirit/alloy/value_initialize.hpp>

#include <type_traits>

#include <cstddef>

namespace boost::spirit::alloy::detail
{
    template <typename... Ts>
    class tuple_impl;

    template <>
    class tuple_impl<> {
    public:
        tuple_impl() = default;
        
        tuple_impl(tuple_impl const&) = default;

        tuple_impl(tuple_impl&&) = default;

        constexpr tuple_impl(value_initialize_t) noexcept {}
    };

    template <typename T0, typename... Ts>
    class tuple_impl<T0, Ts...>
    {
    public:
        BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
        BOOST_SPIRIT_NO_UNIQUE_ADDRESS tuple_impl<Ts...> rest;

        explicit tuple_impl() = default;
        
        explicit tuple_impl(tuple_impl const&) = default;

        explicit tuple_impl(tuple_impl&&) = default;

        constexpr explicit tuple_impl(value_initialize_t vi)
            noexcept(std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<Ts>...>)
            : _0{}, rest(vi) {}
        
        template <typename U0, typename... Us>
        constexpr explicit tuple_impl(U0&& u0, Us&&... us)
            noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<Ts, Us>...>)
            : _0(static_cast<U0&&>(u0)), rest(static_cast<Us&&>(us)...) {}
        
        template <std::size_t I, typename Self>
        constexpr combine_ref_t<Self&&, type_pack_indexing_t<I, T0, Ts...>> get(this Self&& self) noexcept
        {
            if constexpr (I == 0) return ((forward_like_t<Self, tuple_impl>)self)._0;
            else return ((forward_like_t<Self, tuple_impl>)self).rest.template get<I - 1>();
        }
    };
} // boost::spirit::alloy::detail

#endif
