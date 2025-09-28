#ifndef BOOST_SPIRIT_ALLOY_DETAIL_PREPROCESSED_TUPLE_IMPL_HPP
#define BOOST_SPIRIT_ALLOY_DETAIL_PREPROCESSED_TUPLE_IMPL_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/spirit/config.hpp>

#include <boost/spirit/alloy/detail/combine_cvref.hpp>
#include <boost/spirit/alloy/detail/forward_like_t.hpp>
#include <boost/spirit/alloy/detail/pack_indexing.hpp>

#include <boost/spirit/alloy/value_initialize.hpp>

#include <type_traits>

#include <cstddef>

namespace boost::spirit::alloy::detail {
template<class... Ts>
class tuple_impl;
template<>
class tuple_impl<>
{
public:
    tuple_impl() = default;
    tuple_impl(tuple_impl const&) = default;
    tuple_impl(tuple_impl&&) = default;
    constexpr tuple_impl(value_initialize_t) noexcept {}
};
template<class T0>
class tuple_impl<T0>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(std::conjunction_v<std::is_nothrow_default_constructible<T0>>) : _0{} {}
    template<class U0>
    constexpr explicit tuple_impl(U0&& u0) noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>>) : _0(static_cast<U0>(u0))
    {
    }
    template<class U0>
    constexpr explicit tuple_impl(tuple_impl<U0>& other) noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>>) : _0(other._0)
    {
    }
    template<class U0>
    constexpr explicit tuple_impl(tuple_impl<U0> const& other) noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&>>) : _0(other._0)
    {
    }
    template<class U0>
    constexpr explicit tuple_impl(tuple_impl<U0>&& other) noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>>)
        : _0(static_cast<decltype(other)>(other)._0)
    {
    }
    template<class U0>
    constexpr explicit tuple_impl(tuple_impl<U0> const&& other) noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other) noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
    }
};
template<class T0, class T1>
class tuple_impl<T0, T1>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t)
        noexcept(std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>>)
        : _0{}, _1{}
    {
    }
    template<class U0, class U1>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1) noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1))
    {
    }
    template<class U0, class U1>
    constexpr explicit tuple_impl(tuple_impl<U0, U1>& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>>)
        : _0(other._0), _1(other._1)
    {
    }
    template<class U0, class U1>
    constexpr explicit tuple_impl(tuple_impl<U0, U1> const& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>>)
        : _0(other._0), _1(other._1)
    {
    }
    template<class U0, class U1>
    constexpr explicit tuple_impl(tuple_impl<U0, U1>&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1)
    {
    }
    template<class U0, class U1>
    constexpr explicit tuple_impl(tuple_impl<U0, U1> const&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other) noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
    }
};
template<class T0, class T1, class T2>
class tuple_impl<T0, T1, T2>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>>)
        : _0{}, _1{}, _2{}
    {
    }
    template<class U0, class U1, class U2>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2))
    {
    }
    template<class U0, class U1, class U2>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2>& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>>)
        : _0(other._0), _1(other._1), _2(other._2)
    {
    }
    template<class U0, class U1, class U2>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2> const& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>,
                                    std::is_nothrow_constructible<T2, U2 const&>>)
        : _0(other._0), _1(other._1), _2(other._2)
    {
    }
    template<class U0, class U1, class U2>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2>&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2)
    {
    }
    template<class U0, class U1, class U2>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2> const&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>,
                                    std::is_nothrow_constructible<T2, U2 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
    }
};
template<class T0, class T1, class T2, class T3>
class tuple_impl<T0, T1, T2, T3>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t)
        noexcept(std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>,
                                    std::is_nothrow_default_constructible<T2>, std::is_nothrow_default_constructible<T3>>)
        : _0{}, _1{}, _2{}, _3{}
    {
    }
    template<class U0, class U1, class U2, class U3>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3))
    {
    }
    template<class U0, class U1, class U2, class U3>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3>& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                                    std::is_nothrow_constructible<T3, U3&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3)
    {
    }
    template<class U0, class U1, class U2, class U3>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3> const& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>,
                                    std::is_nothrow_constructible<T2, U2 const&>, std::is_nothrow_constructible<T3, U3 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3)
    {
    }
    template<class U0, class U1, class U2, class U3>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3>&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                                    std::is_nothrow_constructible<T3, U3&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3)
    {
    }
    template<class U0, class U1, class U2, class U3>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3> const&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>,
                                    std::is_nothrow_constructible<T2, U2 const&&>, std::is_nothrow_constructible<T3, U3 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other) noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>,
                                                                                    std::is_nothrow_move_assignable<T2>, std::is_nothrow_move_assignable<T3>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
    }
};
template<class T0, class T1, class T2, class T3, class T4>
class tuple_impl<T0, T1, T2, T3, T4>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4>& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                                    std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4> const& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>,
                                    std::is_nothrow_constructible<T2, U2 const&>, std::is_nothrow_constructible<T3, U3 const&>,
                                    std::is_nothrow_constructible<T4, U4 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4>&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                                    std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4> const&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>,
                                    std::is_nothrow_constructible<T2, U2 const&&>, std::is_nothrow_constructible<T3, U3 const&&>,
                                    std::is_nothrow_constructible<T4, U4 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5>
class tuple_impl<T0, T1, T2, T3, T4, T5>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5>& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                                    std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5> const& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>,
                                    std::is_nothrow_constructible<T2, U2 const&>, std::is_nothrow_constructible<T3, U3 const&>,
                                    std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5>&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                                    std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5> const&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>,
                                    std::is_nothrow_constructible<T2, U2 const&&>, std::is_nothrow_constructible<T3, U3 const&&>,
                                    std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6>& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                                    std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                                    std::is_nothrow_constructible<T6, U6&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6> const& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>,
                                    std::is_nothrow_constructible<T2, U2 const&>, std::is_nothrow_constructible<T3, U3 const&>,
                                    std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                                    std::is_nothrow_constructible<T6, U6 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6>&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                                    std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                                    std::is_nothrow_constructible<T6, U6&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6> const&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>,
                                    std::is_nothrow_constructible<T2, U2 const&&>, std::is_nothrow_constructible<T3, U3 const&&>,
                                    std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                                    std::is_nothrow_constructible<T6, U6 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7>& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                                    std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                                    std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7> const& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>,
                                    std::is_nothrow_constructible<T2, U2 const&>, std::is_nothrow_constructible<T3, U3 const&>,
                                    std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                                    std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7>&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                                    std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                                    std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7> const&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>,
                                    std::is_nothrow_constructible<T2, U2 const&&>, std::is_nothrow_constructible<T3, U3 const&&>,
                                    std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                                    std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8>& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                                    std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                                    std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8>&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                                    std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                                    std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8> const&& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
                 std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                 std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9>& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                                    std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                                    std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                                    std::is_nothrow_constructible<T9, U9&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9> const& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>,
                                    std::is_nothrow_constructible<T2, U2 const&>, std::is_nothrow_constructible<T3, U3 const&>,
                                    std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                                    std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>,
                                    std::is_nothrow_constructible<T8, U8 const&>, std::is_nothrow_constructible<T9, U9 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9>&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                                    std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                                    std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                                    std::is_nothrow_constructible<T9, U9&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9> const&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>,
                                    std::is_nothrow_constructible<T2, U2 const&&>, std::is_nothrow_constructible<T3, U3 const&&>,
                                    std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                                    std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>,
                                    std::is_nothrow_constructible<T8, U8 const&&>, std::is_nothrow_constructible<T9, U9 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10>& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                                    std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                                    std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                                    std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10>&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                                    std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                                    std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                                    std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10> const&& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
                 std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                 std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
                 std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11>& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                                    std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                                    std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                                    std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11>&& other) noexcept(
        std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                           std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                           std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                           std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11> const&& other) noexcept(
        std::conjunction_v<
            std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
            std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
            std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
            std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>, std::is_nothrow_constructible<T11, U11 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12>& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                                    std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                                    std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                                    std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                                    std::is_nothrow_constructible<T12, U12&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                 std::is_nothrow_constructible<T12, U12 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12>&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                                    std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                                    std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                                    std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>,
                                    std::is_nothrow_constructible<T11, U11&&>, std::is_nothrow_constructible<T12, U12&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12> const&& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
                 std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                 std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
                 std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>,
                 std::is_nothrow_constructible<T11, U11 const&&>, std::is_nothrow_constructible<T12, U12 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13>& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                                    std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                                    std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                                    std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                                    std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                 std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13>&& other) noexcept(
        std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                           std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                           std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                           std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                           std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13> const&& other) noexcept(
        std::conjunction_v<
            std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
            std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
            std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
            std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>, std::is_nothrow_constructible<T11, U11 const&&>,
            std::is_nothrow_constructible<T12, U12 const&&>, std::is_nothrow_constructible<T13, U13 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14>& other) noexcept(
        std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                           std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                           std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                           std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                           std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14> const& other) noexcept(
        std::conjunction_v<
            std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
            std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
            std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
            std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
            std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14>&& other) noexcept(
        std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                           std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                           std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                           std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                           std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14> const&& other) noexcept(
        std::conjunction_v<
            std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
            std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
            std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
            std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>, std::is_nothrow_constructible<T11, U11 const&&>,
            std::is_nothrow_constructible<T12, U12 const&&>, std::is_nothrow_constructible<T13, U13 const&&>, std::is_nothrow_constructible<T14, U14 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15>& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                                    std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                                    std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                                    std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                                    std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>,
                                    std::is_nothrow_constructible<T14, U14&>, std::is_nothrow_constructible<T15, U15&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                 std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                 std::is_nothrow_constructible<T15, U15 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15>&& other) noexcept(
        std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                           std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                           std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                           std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                           std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                           std::is_nothrow_constructible<T15, U15&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15> const&& other) noexcept(
        std::conjunction_v<
            std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
            std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
            std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
            std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>, std::is_nothrow_constructible<T11, U11 const&&>,
            std::is_nothrow_constructible<T12, U12 const&&>, std::is_nothrow_constructible<T13, U13 const&&>, std::is_nothrow_constructible<T14, U14 const&&>,
            std::is_nothrow_constructible<T15, U15 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16>& other) noexcept(
        std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                           std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                           std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                           std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                           std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                           std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                 std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                 std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16>&& other) noexcept(
        std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                           std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                           std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                           std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                           std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                           std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16> const&& other) noexcept(
        std::conjunction_v<
            std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
            std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
            std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
            std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>, std::is_nothrow_constructible<T11, U11 const&&>,
            std::is_nothrow_constructible<T12, U12 const&&>, std::is_nothrow_constructible<T13, U13 const&&>, std::is_nothrow_constructible<T14, U14 const&&>,
            std::is_nothrow_constructible<T15, U15 const&&>, std::is_nothrow_constructible<T16, U16 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16, class T17>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T17 _17;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>, std::is_nothrow_default_constructible<T17>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}, _17{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16, U17&& u17)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>, std::is_nothrow_constructible<T17, U17>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16)), _17(static_cast<U17>(u17))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17>& other) noexcept(
        std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                           std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                           std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                           std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                           std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                           std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>, std::is_nothrow_constructible<T17, U17&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17> const& other) noexcept(
        std::conjunction_v<
            std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
            std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
            std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
            std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
            std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
            std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>, std::is_nothrow_constructible<T17, U17 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17>&& other) noexcept(
        std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                           std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                           std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                           std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                           std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                           std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>, std::is_nothrow_constructible<T17, U17&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17> const&& other) noexcept(
        std::conjunction_v<
            std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
            std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
            std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
            std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>, std::is_nothrow_constructible<T11, U11 const&&>,
            std::is_nothrow_constructible<T12, U12 const&&>, std::is_nothrow_constructible<T13, U13 const&&>, std::is_nothrow_constructible<T14, U14 const&&>,
            std::is_nothrow_constructible<T15, U15 const&&>, std::is_nothrow_constructible<T16, U16 const&&>, std::is_nothrow_constructible<T17, U17 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        _17 = other._17;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>, std::is_nothrow_move_assignable<T17>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        _17 = static_cast<decltype(other)>(other)._17;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
        else if constexpr (I == 17)
            return ((forward_like_t<Self, tuple_impl>)self)._17;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16, class T17, class T18>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T17 _17;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T18 _18;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>, std::is_nothrow_default_constructible<T17>,
                           std::is_nothrow_default_constructible<T18>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}, _17{}, _18{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16, U17&& u17, U18&& u18)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>, std::is_nothrow_constructible<T17, U17>,
                                    std::is_nothrow_constructible<T18, U18>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16)), _17(static_cast<U17>(u17)), _18(static_cast<U18>(u18))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18>& other) noexcept(
        std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                           std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                           std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                           std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                           std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                           std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>, std::is_nothrow_constructible<T17, U17&>,
                           std::is_nothrow_constructible<T18, U18&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                 std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                 std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>, std::is_nothrow_constructible<T17, U17 const&>,
                 std::is_nothrow_constructible<T18, U18 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18>&& other) noexcept(
        std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                           std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                           std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                           std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                           std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                           std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>, std::is_nothrow_constructible<T17, U17&&>,
                           std::is_nothrow_constructible<T18, U18&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18> const&& other) noexcept(
        std::conjunction_v<
            std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
            std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
            std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
            std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>, std::is_nothrow_constructible<T11, U11 const&&>,
            std::is_nothrow_constructible<T12, U12 const&&>, std::is_nothrow_constructible<T13, U13 const&&>, std::is_nothrow_constructible<T14, U14 const&&>,
            std::is_nothrow_constructible<T15, U15 const&&>, std::is_nothrow_constructible<T16, U16 const&&>, std::is_nothrow_constructible<T17, U17 const&&>,
            std::is_nothrow_constructible<T18, U18 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        _17 = other._17;
        _18 = other._18;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>, std::is_nothrow_move_assignable<T17>,
                                    std::is_nothrow_move_assignable<T18>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        _17 = static_cast<decltype(other)>(other)._17;
        _18 = static_cast<decltype(other)>(other)._18;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
        else if constexpr (I == 17)
            return ((forward_like_t<Self, tuple_impl>)self)._17;
        else if constexpr (I == 18)
            return ((forward_like_t<Self, tuple_impl>)self)._18;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16, class T17, class T18, class T19>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T17 _17;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T18 _18;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T19 _19;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>, std::is_nothrow_default_constructible<T17>,
                           std::is_nothrow_default_constructible<T18>, std::is_nothrow_default_constructible<T19>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}, _17{}, _18{}, _19{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16, U17&& u17, U18&& u18, U19&& u19)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>, std::is_nothrow_constructible<T17, U17>,
                                    std::is_nothrow_constructible<T18, U18>, std::is_nothrow_constructible<T19, U19>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16)), _17(static_cast<U17>(u17)), _18(static_cast<U18>(u18)), _19(static_cast<U19>(u19))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19>& other) noexcept(
        std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                           std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                           std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                           std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                           std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                           std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>, std::is_nothrow_constructible<T17, U17&>,
                           std::is_nothrow_constructible<T18, U18&>, std::is_nothrow_constructible<T19, U19&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                 std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                 std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>, std::is_nothrow_constructible<T17, U17 const&>,
                 std::is_nothrow_constructible<T18, U18 const&>, std::is_nothrow_constructible<T19, U19 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19>&& other) noexcept(
        std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                           std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                           std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                           std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                           std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                           std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>, std::is_nothrow_constructible<T17, U17&&>,
                           std::is_nothrow_constructible<T18, U18&&>, std::is_nothrow_constructible<T19, U19&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19> const&& other) noexcept(
        std::conjunction_v<
            std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
            std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
            std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
            std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>, std::is_nothrow_constructible<T11, U11 const&&>,
            std::is_nothrow_constructible<T12, U12 const&&>, std::is_nothrow_constructible<T13, U13 const&&>, std::is_nothrow_constructible<T14, U14 const&&>,
            std::is_nothrow_constructible<T15, U15 const&&>, std::is_nothrow_constructible<T16, U16 const&&>, std::is_nothrow_constructible<T17, U17 const&&>,
            std::is_nothrow_constructible<T18, U18 const&&>, std::is_nothrow_constructible<T19, U19 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        _17 = other._17;
        _18 = other._18;
        _19 = other._19;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>, std::is_nothrow_move_assignable<T17>,
                                    std::is_nothrow_move_assignable<T18>, std::is_nothrow_move_assignable<T19>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        _17 = static_cast<decltype(other)>(other)._17;
        _18 = static_cast<decltype(other)>(other)._18;
        _19 = static_cast<decltype(other)>(other)._19;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
        else if constexpr (I == 17)
            return ((forward_like_t<Self, tuple_impl>)self)._17;
        else if constexpr (I == 18)
            return ((forward_like_t<Self, tuple_impl>)self)._18;
        else if constexpr (I == 19)
            return ((forward_like_t<Self, tuple_impl>)self)._19;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16, class T17, class T18, class T19, class T20>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T17 _17;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T18 _18;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T19 _19;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T20 _20;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>, std::is_nothrow_default_constructible<T17>,
                           std::is_nothrow_default_constructible<T18>, std::is_nothrow_default_constructible<T19>, std::is_nothrow_default_constructible<T20>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}, _17{}, _18{}, _19{}, _20{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16, U17&& u17, U18&& u18, U19&& u19, U20&& u20)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>, std::is_nothrow_constructible<T17, U17>,
                                    std::is_nothrow_constructible<T18, U18>, std::is_nothrow_constructible<T19, U19>, std::is_nothrow_constructible<T20, U20>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16)), _17(static_cast<U17>(u17)), _18(static_cast<U18>(u18)), _19(static_cast<U19>(u19)), _20(static_cast<U20>(u20))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20>& other) noexcept(
        std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                           std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                           std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                           std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                           std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                           std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>, std::is_nothrow_constructible<T17, U17&>,
                           std::is_nothrow_constructible<T18, U18&>, std::is_nothrow_constructible<T19, U19&>, std::is_nothrow_constructible<T20, U20&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20> const& other)
        noexcept(
            std::conjunction_v<
                std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>, std::is_nothrow_constructible<T17, U17 const&>,
                std::is_nothrow_constructible<T18, U18 const&>, std::is_nothrow_constructible<T19, U19 const&>, std::is_nothrow_constructible<T20, U20 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20>&& other) noexcept(
        std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                           std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                           std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                           std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                           std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                           std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>, std::is_nothrow_constructible<T17, U17&&>,
                           std::is_nothrow_constructible<T18, U18&&>, std::is_nothrow_constructible<T19, U19&&>, std::is_nothrow_constructible<T20, U20&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20> const&& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
                 std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                 std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
                 std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>,
                 std::is_nothrow_constructible<T11, U11 const&&>, std::is_nothrow_constructible<T12, U12 const&&>,
                 std::is_nothrow_constructible<T13, U13 const&&>, std::is_nothrow_constructible<T14, U14 const&&>,
                 std::is_nothrow_constructible<T15, U15 const&&>, std::is_nothrow_constructible<T16, U16 const&&>,
                 std::is_nothrow_constructible<T17, U17 const&&>, std::is_nothrow_constructible<T18, U18 const&&>,
                 std::is_nothrow_constructible<T19, U19 const&&>, std::is_nothrow_constructible<T20, U20 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        _17 = other._17;
        _18 = other._18;
        _19 = other._19;
        _20 = other._20;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>, std::is_nothrow_move_assignable<T17>,
                                    std::is_nothrow_move_assignable<T18>, std::is_nothrow_move_assignable<T19>, std::is_nothrow_move_assignable<T20>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        _17 = static_cast<decltype(other)>(other)._17;
        _18 = static_cast<decltype(other)>(other)._18;
        _19 = static_cast<decltype(other)>(other)._19;
        _20 = static_cast<decltype(other)>(other)._20;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
        else if constexpr (I == 17)
            return ((forward_like_t<Self, tuple_impl>)self)._17;
        else if constexpr (I == 18)
            return ((forward_like_t<Self, tuple_impl>)self)._18;
        else if constexpr (I == 19)
            return ((forward_like_t<Self, tuple_impl>)self)._19;
        else if constexpr (I == 20)
            return ((forward_like_t<Self, tuple_impl>)self)._20;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16, class T17, class T18, class T19, class T20, class T21>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T17 _17;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T18 _18;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T19 _19;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T20 _20;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T21 _21;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>, std::is_nothrow_default_constructible<T17>,
                           std::is_nothrow_default_constructible<T18>, std::is_nothrow_default_constructible<T19>, std::is_nothrow_default_constructible<T20>,
                           std::is_nothrow_default_constructible<T21>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}, _17{}, _18{}, _19{}, _20{}, _21{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16, U17&& u17, U18&& u18, U19&& u19, U20&& u20, U21&& u21)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>, std::is_nothrow_constructible<T17, U17>,
                                    std::is_nothrow_constructible<T18, U18>, std::is_nothrow_constructible<T19, U19>, std::is_nothrow_constructible<T20, U20>,
                                    std::is_nothrow_constructible<T21, U21>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16)), _17(static_cast<U17>(u17)), _18(static_cast<U18>(u18)), _19(static_cast<U19>(u19)), _20(static_cast<U20>(u20)),
          _21(static_cast<U21>(u21))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21>& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                               std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                               std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                               std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                               std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                               std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>, std::is_nothrow_constructible<T17, U17&>,
                               std::is_nothrow_constructible<T18, U18&>, std::is_nothrow_constructible<T19, U19&>, std::is_nothrow_constructible<T20, U20&>,
                               std::is_nothrow_constructible<T21, U21&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                 std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                 std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>, std::is_nothrow_constructible<T17, U17 const&>,
                 std::is_nothrow_constructible<T18, U18 const&>, std::is_nothrow_constructible<T19, U19 const&>, std::is_nothrow_constructible<T20, U20 const&>,
                 std::is_nothrow_constructible<T21, U21 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21>&& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                               std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                               std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                               std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                               std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                               std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>, std::is_nothrow_constructible<T17, U17&&>,
                               std::is_nothrow_constructible<T18, U18&&>, std::is_nothrow_constructible<T19, U19&&>, std::is_nothrow_constructible<T20, U20&&>,
                               std::is_nothrow_constructible<T21, U21&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21> const&& other)
        noexcept(
            std::conjunction_v<
                std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
                std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
                std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>, std::is_nothrow_constructible<T11, U11 const&&>,
                std::is_nothrow_constructible<T12, U12 const&&>, std::is_nothrow_constructible<T13, U13 const&&>,
                std::is_nothrow_constructible<T14, U14 const&&>, std::is_nothrow_constructible<T15, U15 const&&>,
                std::is_nothrow_constructible<T16, U16 const&&>, std::is_nothrow_constructible<T17, U17 const&&>,
                std::is_nothrow_constructible<T18, U18 const&&>, std::is_nothrow_constructible<T19, U19 const&&>,
                std::is_nothrow_constructible<T20, U20 const&&>, std::is_nothrow_constructible<T21, U21 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        _17 = other._17;
        _18 = other._18;
        _19 = other._19;
        _20 = other._20;
        _21 = other._21;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>, std::is_nothrow_move_assignable<T17>,
                                    std::is_nothrow_move_assignable<T18>, std::is_nothrow_move_assignable<T19>, std::is_nothrow_move_assignable<T20>,
                                    std::is_nothrow_move_assignable<T21>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        _17 = static_cast<decltype(other)>(other)._17;
        _18 = static_cast<decltype(other)>(other)._18;
        _19 = static_cast<decltype(other)>(other)._19;
        _20 = static_cast<decltype(other)>(other)._20;
        _21 = static_cast<decltype(other)>(other)._21;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&,
                              type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
        else if constexpr (I == 17)
            return ((forward_like_t<Self, tuple_impl>)self)._17;
        else if constexpr (I == 18)
            return ((forward_like_t<Self, tuple_impl>)self)._18;
        else if constexpr (I == 19)
            return ((forward_like_t<Self, tuple_impl>)self)._19;
        else if constexpr (I == 20)
            return ((forward_like_t<Self, tuple_impl>)self)._20;
        else if constexpr (I == 21)
            return ((forward_like_t<Self, tuple_impl>)self)._21;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16, class T17, class T18, class T19, class T20, class T21, class T22>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T17 _17;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T18 _18;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T19 _19;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T20 _20;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T21 _21;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T22 _22;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>, std::is_nothrow_default_constructible<T17>,
                           std::is_nothrow_default_constructible<T18>, std::is_nothrow_default_constructible<T19>, std::is_nothrow_default_constructible<T20>,
                           std::is_nothrow_default_constructible<T21>, std::is_nothrow_default_constructible<T22>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}, _17{}, _18{}, _19{}, _20{}, _21{}, _22{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16, U17&& u17, U18&& u18, U19&& u19, U20&& u20, U21&& u21, U22&& u22)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>, std::is_nothrow_constructible<T17, U17>,
                                    std::is_nothrow_constructible<T18, U18>, std::is_nothrow_constructible<T19, U19>, std::is_nothrow_constructible<T20, U20>,
                                    std::is_nothrow_constructible<T21, U21>, std::is_nothrow_constructible<T22, U22>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16)), _17(static_cast<U17>(u17)), _18(static_cast<U18>(u18)), _19(static_cast<U19>(u19)), _20(static_cast<U20>(u20)),
          _21(static_cast<U21>(u21)), _22(static_cast<U22>(u22))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22>& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                               std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                               std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                               std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                               std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                               std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>, std::is_nothrow_constructible<T17, U17&>,
                               std::is_nothrow_constructible<T18, U18&>, std::is_nothrow_constructible<T19, U19&>, std::is_nothrow_constructible<T20, U20&>,
                               std::is_nothrow_constructible<T21, U21&>, std::is_nothrow_constructible<T22, U22&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                 std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                 std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>, std::is_nothrow_constructible<T17, U17 const&>,
                 std::is_nothrow_constructible<T18, U18 const&>, std::is_nothrow_constructible<T19, U19 const&>, std::is_nothrow_constructible<T20, U20 const&>,
                 std::is_nothrow_constructible<T21, U21 const&>, std::is_nothrow_constructible<T22, U22 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22>&& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                               std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                               std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                               std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                               std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                               std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>, std::is_nothrow_constructible<T17, U17&&>,
                               std::is_nothrow_constructible<T18, U18&&>, std::is_nothrow_constructible<T19, U19&&>, std::is_nothrow_constructible<T20, U20&&>,
                               std::is_nothrow_constructible<T21, U21&&>, std::is_nothrow_constructible<T22, U22&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22> const&& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
                 std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                 std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
                 std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>,
                 std::is_nothrow_constructible<T11, U11 const&&>, std::is_nothrow_constructible<T12, U12 const&&>,
                 std::is_nothrow_constructible<T13, U13 const&&>, std::is_nothrow_constructible<T14, U14 const&&>,
                 std::is_nothrow_constructible<T15, U15 const&&>, std::is_nothrow_constructible<T16, U16 const&&>,
                 std::is_nothrow_constructible<T17, U17 const&&>, std::is_nothrow_constructible<T18, U18 const&&>,
                 std::is_nothrow_constructible<T19, U19 const&&>, std::is_nothrow_constructible<T20, U20 const&&>,
                 std::is_nothrow_constructible<T21, U21 const&&>, std::is_nothrow_constructible<T22, U22 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        _17 = other._17;
        _18 = other._18;
        _19 = other._19;
        _20 = other._20;
        _21 = other._21;
        _22 = other._22;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>, std::is_nothrow_move_assignable<T17>,
                                    std::is_nothrow_move_assignable<T18>, std::is_nothrow_move_assignable<T19>, std::is_nothrow_move_assignable<T20>,
                                    std::is_nothrow_move_assignable<T21>, std::is_nothrow_move_assignable<T22>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        _17 = static_cast<decltype(other)>(other)._17;
        _18 = static_cast<decltype(other)>(other)._18;
        _19 = static_cast<decltype(other)>(other)._19;
        _20 = static_cast<decltype(other)>(other)._20;
        _21 = static_cast<decltype(other)>(other)._21;
        _22 = static_cast<decltype(other)>(other)._22;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&,
                              type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
        else if constexpr (I == 17)
            return ((forward_like_t<Self, tuple_impl>)self)._17;
        else if constexpr (I == 18)
            return ((forward_like_t<Self, tuple_impl>)self)._18;
        else if constexpr (I == 19)
            return ((forward_like_t<Self, tuple_impl>)self)._19;
        else if constexpr (I == 20)
            return ((forward_like_t<Self, tuple_impl>)self)._20;
        else if constexpr (I == 21)
            return ((forward_like_t<Self, tuple_impl>)self)._21;
        else if constexpr (I == 22)
            return ((forward_like_t<Self, tuple_impl>)self)._22;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16, class T17, class T18, class T19, class T20, class T21, class T22, class T23>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T17 _17;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T18 _18;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T19 _19;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T20 _20;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T21 _21;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T22 _22;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T23 _23;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>, std::is_nothrow_default_constructible<T17>,
                           std::is_nothrow_default_constructible<T18>, std::is_nothrow_default_constructible<T19>, std::is_nothrow_default_constructible<T20>,
                           std::is_nothrow_default_constructible<T21>, std::is_nothrow_default_constructible<T22>, std::is_nothrow_default_constructible<T23>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}, _17{}, _18{}, _19{}, _20{}, _21{}, _22{},
          _23{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16, U17&& u17, U18&& u18, U19&& u19, U20&& u20, U21&& u21, U22&& u22, U23&& u23)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>, std::is_nothrow_constructible<T17, U17>,
                                    std::is_nothrow_constructible<T18, U18>, std::is_nothrow_constructible<T19, U19>, std::is_nothrow_constructible<T20, U20>,
                                    std::is_nothrow_constructible<T21, U21>, std::is_nothrow_constructible<T22, U22>, std::is_nothrow_constructible<T23, U23>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16)), _17(static_cast<U17>(u17)), _18(static_cast<U18>(u18)), _19(static_cast<U19>(u19)), _20(static_cast<U20>(u20)),
          _21(static_cast<U21>(u21)), _22(static_cast<U22>(u22)), _23(static_cast<U23>(u23))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23>& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                               std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                               std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                               std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                               std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                               std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>, std::is_nothrow_constructible<T17, U17&>,
                               std::is_nothrow_constructible<T18, U18&>, std::is_nothrow_constructible<T19, U19&>, std::is_nothrow_constructible<T20, U20&>,
                               std::is_nothrow_constructible<T21, U21&>, std::is_nothrow_constructible<T22, U22&>, std::is_nothrow_constructible<T23, U23&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23> const& other)
        noexcept(
            std::conjunction_v<
                std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>, std::is_nothrow_constructible<T17, U17 const&>,
                std::is_nothrow_constructible<T18, U18 const&>, std::is_nothrow_constructible<T19, U19 const&>, std::is_nothrow_constructible<T20, U20 const&>,
                std::is_nothrow_constructible<T21, U21 const&>, std::is_nothrow_constructible<T22, U22 const&>, std::is_nothrow_constructible<T23, U23 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23>&& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                               std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                               std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                               std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                               std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                               std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>, std::is_nothrow_constructible<T17, U17&&>,
                               std::is_nothrow_constructible<T18, U18&&>, std::is_nothrow_constructible<T19, U19&&>, std::is_nothrow_constructible<T20, U20&&>,
                               std::is_nothrow_constructible<T21, U21&&>, std::is_nothrow_constructible<T22, U22&&>, std::is_nothrow_constructible<T23, U23&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23> const&& other)
        noexcept(
            std::conjunction_v<
                std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
                std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
                std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>, std::is_nothrow_constructible<T11, U11 const&&>,
                std::is_nothrow_constructible<T12, U12 const&&>, std::is_nothrow_constructible<T13, U13 const&&>,
                std::is_nothrow_constructible<T14, U14 const&&>, std::is_nothrow_constructible<T15, U15 const&&>,
                std::is_nothrow_constructible<T16, U16 const&&>, std::is_nothrow_constructible<T17, U17 const&&>,
                std::is_nothrow_constructible<T18, U18 const&&>, std::is_nothrow_constructible<T19, U19 const&&>,
                std::is_nothrow_constructible<T20, U20 const&&>, std::is_nothrow_constructible<T21, U21 const&&>,
                std::is_nothrow_constructible<T22, U22 const&&>, std::is_nothrow_constructible<T23, U23 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        _17 = other._17;
        _18 = other._18;
        _19 = other._19;
        _20 = other._20;
        _21 = other._21;
        _22 = other._22;
        _23 = other._23;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>, std::is_nothrow_move_assignable<T17>,
                                    std::is_nothrow_move_assignable<T18>, std::is_nothrow_move_assignable<T19>, std::is_nothrow_move_assignable<T20>,
                                    std::is_nothrow_move_assignable<T21>, std::is_nothrow_move_assignable<T22>, std::is_nothrow_move_assignable<T23>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        _17 = static_cast<decltype(other)>(other)._17;
        _18 = static_cast<decltype(other)>(other)._18;
        _19 = static_cast<decltype(other)>(other)._19;
        _20 = static_cast<decltype(other)>(other)._20;
        _21 = static_cast<decltype(other)>(other)._21;
        _22 = static_cast<decltype(other)>(other)._22;
        _23 = static_cast<decltype(other)>(other)._23;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<
        Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
        else if constexpr (I == 17)
            return ((forward_like_t<Self, tuple_impl>)self)._17;
        else if constexpr (I == 18)
            return ((forward_like_t<Self, tuple_impl>)self)._18;
        else if constexpr (I == 19)
            return ((forward_like_t<Self, tuple_impl>)self)._19;
        else if constexpr (I == 20)
            return ((forward_like_t<Self, tuple_impl>)self)._20;
        else if constexpr (I == 21)
            return ((forward_like_t<Self, tuple_impl>)self)._21;
        else if constexpr (I == 22)
            return ((forward_like_t<Self, tuple_impl>)self)._22;
        else if constexpr (I == 23)
            return ((forward_like_t<Self, tuple_impl>)self)._23;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16, class T17, class T18, class T19, class T20, class T21, class T22, class T23, class T24>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T17 _17;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T18 _18;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T19 _19;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T20 _20;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T21 _21;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T22 _22;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T23 _23;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T24 _24;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>, std::is_nothrow_default_constructible<T17>,
                           std::is_nothrow_default_constructible<T18>, std::is_nothrow_default_constructible<T19>, std::is_nothrow_default_constructible<T20>,
                           std::is_nothrow_default_constructible<T21>, std::is_nothrow_default_constructible<T22>, std::is_nothrow_default_constructible<T23>,
                           std::is_nothrow_default_constructible<T24>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}, _17{}, _18{}, _19{}, _20{}, _21{}, _22{},
          _23{}, _24{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16, U17&& u17, U18&& u18, U19&& u19, U20&& u20, U21&& u21, U22&& u22, U23&& u23,
                                  U24&& u24)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>, std::is_nothrow_constructible<T17, U17>,
                                    std::is_nothrow_constructible<T18, U18>, std::is_nothrow_constructible<T19, U19>, std::is_nothrow_constructible<T20, U20>,
                                    std::is_nothrow_constructible<T21, U21>, std::is_nothrow_constructible<T22, U22>, std::is_nothrow_constructible<T23, U23>,
                                    std::is_nothrow_constructible<T24, U24>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16)), _17(static_cast<U17>(u17)), _18(static_cast<U18>(u18)), _19(static_cast<U19>(u19)), _20(static_cast<U20>(u20)),
          _21(static_cast<U21>(u21)), _22(static_cast<U22>(u22)), _23(static_cast<U23>(u23)), _24(static_cast<U24>(u24))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24>& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                               std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                               std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                               std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                               std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                               std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>, std::is_nothrow_constructible<T17, U17&>,
                               std::is_nothrow_constructible<T18, U18&>, std::is_nothrow_constructible<T19, U19&>, std::is_nothrow_constructible<T20, U20&>,
                               std::is_nothrow_constructible<T21, U21&>, std::is_nothrow_constructible<T22, U22&>, std::is_nothrow_constructible<T23, U23&>,
                               std::is_nothrow_constructible<T24, U24&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                 std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                 std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>, std::is_nothrow_constructible<T17, U17 const&>,
                 std::is_nothrow_constructible<T18, U18 const&>, std::is_nothrow_constructible<T19, U19 const&>, std::is_nothrow_constructible<T20, U20 const&>,
                 std::is_nothrow_constructible<T21, U21 const&>, std::is_nothrow_constructible<T22, U22 const&>, std::is_nothrow_constructible<T23, U23 const&>,
                 std::is_nothrow_constructible<T24, U24 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24>&& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                               std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                               std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                               std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                               std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                               std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>, std::is_nothrow_constructible<T17, U17&&>,
                               std::is_nothrow_constructible<T18, U18&&>, std::is_nothrow_constructible<T19, U19&&>, std::is_nothrow_constructible<T20, U20&&>,
                               std::is_nothrow_constructible<T21, U21&&>, std::is_nothrow_constructible<T22, U22&&>, std::is_nothrow_constructible<T23, U23&&>,
                               std::is_nothrow_constructible<T24, U24&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24> const&& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
                 std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                 std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
                 std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>,
                 std::is_nothrow_constructible<T11, U11 const&&>, std::is_nothrow_constructible<T12, U12 const&&>,
                 std::is_nothrow_constructible<T13, U13 const&&>, std::is_nothrow_constructible<T14, U14 const&&>,
                 std::is_nothrow_constructible<T15, U15 const&&>, std::is_nothrow_constructible<T16, U16 const&&>,
                 std::is_nothrow_constructible<T17, U17 const&&>, std::is_nothrow_constructible<T18, U18 const&&>,
                 std::is_nothrow_constructible<T19, U19 const&&>, std::is_nothrow_constructible<T20, U20 const&&>,
                 std::is_nothrow_constructible<T21, U21 const&&>, std::is_nothrow_constructible<T22, U22 const&&>,
                 std::is_nothrow_constructible<T23, U23 const&&>, std::is_nothrow_constructible<T24, U24 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        _17 = other._17;
        _18 = other._18;
        _19 = other._19;
        _20 = other._20;
        _21 = other._21;
        _22 = other._22;
        _23 = other._23;
        _24 = other._24;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>, std::is_nothrow_move_assignable<T17>,
                                    std::is_nothrow_move_assignable<T18>, std::is_nothrow_move_assignable<T19>, std::is_nothrow_move_assignable<T20>,
                                    std::is_nothrow_move_assignable<T21>, std::is_nothrow_move_assignable<T22>, std::is_nothrow_move_assignable<T23>,
                                    std::is_nothrow_move_assignable<T24>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        _17 = static_cast<decltype(other)>(other)._17;
        _18 = static_cast<decltype(other)>(other)._18;
        _19 = static_cast<decltype(other)>(other)._19;
        _20 = static_cast<decltype(other)>(other)._20;
        _21 = static_cast<decltype(other)>(other)._21;
        _22 = static_cast<decltype(other)>(other)._22;
        _23 = static_cast<decltype(other)>(other)._23;
        _24 = static_cast<decltype(other)>(other)._24;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<
        Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
        else if constexpr (I == 17)
            return ((forward_like_t<Self, tuple_impl>)self)._17;
        else if constexpr (I == 18)
            return ((forward_like_t<Self, tuple_impl>)self)._18;
        else if constexpr (I == 19)
            return ((forward_like_t<Self, tuple_impl>)self)._19;
        else if constexpr (I == 20)
            return ((forward_like_t<Self, tuple_impl>)self)._20;
        else if constexpr (I == 21)
            return ((forward_like_t<Self, tuple_impl>)self)._21;
        else if constexpr (I == 22)
            return ((forward_like_t<Self, tuple_impl>)self)._22;
        else if constexpr (I == 23)
            return ((forward_like_t<Self, tuple_impl>)self)._23;
        else if constexpr (I == 24)
            return ((forward_like_t<Self, tuple_impl>)self)._24;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16, class T17, class T18, class T19, class T20, class T21, class T22, class T23, class T24, class T25>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T17 _17;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T18 _18;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T19 _19;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T20 _20;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T21 _21;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T22 _22;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T23 _23;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T24 _24;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T25 _25;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>, std::is_nothrow_default_constructible<T17>,
                           std::is_nothrow_default_constructible<T18>, std::is_nothrow_default_constructible<T19>, std::is_nothrow_default_constructible<T20>,
                           std::is_nothrow_default_constructible<T21>, std::is_nothrow_default_constructible<T22>, std::is_nothrow_default_constructible<T23>,
                           std::is_nothrow_default_constructible<T24>, std::is_nothrow_default_constructible<T25>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}, _17{}, _18{}, _19{}, _20{}, _21{}, _22{},
          _23{}, _24{}, _25{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16, U17&& u17, U18&& u18, U19&& u19, U20&& u20, U21&& u21, U22&& u22, U23&& u23,
                                  U24&& u24, U25&& u25)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>, std::is_nothrow_constructible<T17, U17>,
                                    std::is_nothrow_constructible<T18, U18>, std::is_nothrow_constructible<T19, U19>, std::is_nothrow_constructible<T20, U20>,
                                    std::is_nothrow_constructible<T21, U21>, std::is_nothrow_constructible<T22, U22>, std::is_nothrow_constructible<T23, U23>,
                                    std::is_nothrow_constructible<T24, U24>, std::is_nothrow_constructible<T25, U25>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16)), _17(static_cast<U17>(u17)), _18(static_cast<U18>(u18)), _19(static_cast<U19>(u19)), _20(static_cast<U20>(u20)),
          _21(static_cast<U21>(u21)), _22(static_cast<U22>(u22)), _23(static_cast<U23>(u23)), _24(static_cast<U24>(u24)), _25(static_cast<U25>(u25))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25>& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                               std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                               std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                               std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                               std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                               std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>, std::is_nothrow_constructible<T17, U17&>,
                               std::is_nothrow_constructible<T18, U18&>, std::is_nothrow_constructible<T19, U19&>, std::is_nothrow_constructible<T20, U20&>,
                               std::is_nothrow_constructible<T21, U21&>, std::is_nothrow_constructible<T22, U22&>, std::is_nothrow_constructible<T23, U23&>,
                               std::is_nothrow_constructible<T24, U24&>, std::is_nothrow_constructible<T25, U25&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24), _25(other._25)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                 std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                 std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>, std::is_nothrow_constructible<T17, U17 const&>,
                 std::is_nothrow_constructible<T18, U18 const&>, std::is_nothrow_constructible<T19, U19 const&>, std::is_nothrow_constructible<T20, U20 const&>,
                 std::is_nothrow_constructible<T21, U21 const&>, std::is_nothrow_constructible<T22, U22 const&>, std::is_nothrow_constructible<T23, U23 const&>,
                 std::is_nothrow_constructible<T24, U24 const&>, std::is_nothrow_constructible<T25, U25 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24), _25(other._25)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25>&& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                               std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                               std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                               std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                               std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                               std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>, std::is_nothrow_constructible<T17, U17&&>,
                               std::is_nothrow_constructible<T18, U18&&>, std::is_nothrow_constructible<T19, U19&&>, std::is_nothrow_constructible<T20, U20&&>,
                               std::is_nothrow_constructible<T21, U21&&>, std::is_nothrow_constructible<T22, U22&&>, std::is_nothrow_constructible<T23, U23&&>,
                               std::is_nothrow_constructible<T24, U24&&>, std::is_nothrow_constructible<T25, U25&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24), _25(static_cast<decltype(other)>(other)._25)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25> const&& other)
        noexcept(
            std::conjunction_v<
                std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
                std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
                std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>, std::is_nothrow_constructible<T11, U11 const&&>,
                std::is_nothrow_constructible<T12, U12 const&&>, std::is_nothrow_constructible<T13, U13 const&&>,
                std::is_nothrow_constructible<T14, U14 const&&>, std::is_nothrow_constructible<T15, U15 const&&>,
                std::is_nothrow_constructible<T16, U16 const&&>, std::is_nothrow_constructible<T17, U17 const&&>,
                std::is_nothrow_constructible<T18, U18 const&&>, std::is_nothrow_constructible<T19, U19 const&&>,
                std::is_nothrow_constructible<T20, U20 const&&>, std::is_nothrow_constructible<T21, U21 const&&>,
                std::is_nothrow_constructible<T22, U22 const&&>, std::is_nothrow_constructible<T23, U23 const&&>,
                std::is_nothrow_constructible<T24, U24 const&&>, std::is_nothrow_constructible<T25, U25 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24), _25(static_cast<decltype(other)>(other)._25)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        _17 = other._17;
        _18 = other._18;
        _19 = other._19;
        _20 = other._20;
        _21 = other._21;
        _22 = other._22;
        _23 = other._23;
        _24 = other._24;
        _25 = other._25;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>, std::is_nothrow_move_assignable<T17>,
                                    std::is_nothrow_move_assignable<T18>, std::is_nothrow_move_assignable<T19>, std::is_nothrow_move_assignable<T20>,
                                    std::is_nothrow_move_assignable<T21>, std::is_nothrow_move_assignable<T22>, std::is_nothrow_move_assignable<T23>,
                                    std::is_nothrow_move_assignable<T24>, std::is_nothrow_move_assignable<T25>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        _17 = static_cast<decltype(other)>(other)._17;
        _18 = static_cast<decltype(other)>(other)._18;
        _19 = static_cast<decltype(other)>(other)._19;
        _20 = static_cast<decltype(other)>(other)._20;
        _21 = static_cast<decltype(other)>(other)._21;
        _22 = static_cast<decltype(other)>(other)._22;
        _23 = static_cast<decltype(other)>(other)._23;
        _24 = static_cast<decltype(other)>(other)._24;
        _25 = static_cast<decltype(other)>(other)._25;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<
        Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
        else if constexpr (I == 17)
            return ((forward_like_t<Self, tuple_impl>)self)._17;
        else if constexpr (I == 18)
            return ((forward_like_t<Self, tuple_impl>)self)._18;
        else if constexpr (I == 19)
            return ((forward_like_t<Self, tuple_impl>)self)._19;
        else if constexpr (I == 20)
            return ((forward_like_t<Self, tuple_impl>)self)._20;
        else if constexpr (I == 21)
            return ((forward_like_t<Self, tuple_impl>)self)._21;
        else if constexpr (I == 22)
            return ((forward_like_t<Self, tuple_impl>)self)._22;
        else if constexpr (I == 23)
            return ((forward_like_t<Self, tuple_impl>)self)._23;
        else if constexpr (I == 24)
            return ((forward_like_t<Self, tuple_impl>)self)._24;
        else if constexpr (I == 25)
            return ((forward_like_t<Self, tuple_impl>)self)._25;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16, class T17, class T18, class T19, class T20, class T21, class T22, class T23, class T24, class T25, class T26>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T17 _17;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T18 _18;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T19 _19;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T20 _20;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T21 _21;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T22 _22;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T23 _23;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T24 _24;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T25 _25;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T26 _26;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>, std::is_nothrow_default_constructible<T17>,
                           std::is_nothrow_default_constructible<T18>, std::is_nothrow_default_constructible<T19>, std::is_nothrow_default_constructible<T20>,
                           std::is_nothrow_default_constructible<T21>, std::is_nothrow_default_constructible<T22>, std::is_nothrow_default_constructible<T23>,
                           std::is_nothrow_default_constructible<T24>, std::is_nothrow_default_constructible<T25>, std::is_nothrow_default_constructible<T26>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}, _17{}, _18{}, _19{}, _20{}, _21{}, _22{},
          _23{}, _24{}, _25{}, _26{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16, U17&& u17, U18&& u18, U19&& u19, U20&& u20, U21&& u21, U22&& u22, U23&& u23,
                                  U24&& u24, U25&& u25, U26&& u26)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>, std::is_nothrow_constructible<T17, U17>,
                                    std::is_nothrow_constructible<T18, U18>, std::is_nothrow_constructible<T19, U19>, std::is_nothrow_constructible<T20, U20>,
                                    std::is_nothrow_constructible<T21, U21>, std::is_nothrow_constructible<T22, U22>, std::is_nothrow_constructible<T23, U23>,
                                    std::is_nothrow_constructible<T24, U24>, std::is_nothrow_constructible<T25, U25>, std::is_nothrow_constructible<T26, U26>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16)), _17(static_cast<U17>(u17)), _18(static_cast<U18>(u18)), _19(static_cast<U19>(u19)), _20(static_cast<U20>(u20)),
          _21(static_cast<U21>(u21)), _22(static_cast<U22>(u22)), _23(static_cast<U23>(u23)), _24(static_cast<U24>(u24)), _25(static_cast<U25>(u25)),
          _26(static_cast<U26>(u26))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26>& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                               std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                               std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                               std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                               std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                               std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>, std::is_nothrow_constructible<T17, U17&>,
                               std::is_nothrow_constructible<T18, U18&>, std::is_nothrow_constructible<T19, U19&>, std::is_nothrow_constructible<T20, U20&>,
                               std::is_nothrow_constructible<T21, U21&>, std::is_nothrow_constructible<T22, U22&>, std::is_nothrow_constructible<T23, U23&>,
                               std::is_nothrow_constructible<T24, U24&>, std::is_nothrow_constructible<T25, U25&>, std::is_nothrow_constructible<T26, U26&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24), _25(other._25), _26(other._26)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26> const& other)
        noexcept(
            std::conjunction_v<
                std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>, std::is_nothrow_constructible<T17, U17 const&>,
                std::is_nothrow_constructible<T18, U18 const&>, std::is_nothrow_constructible<T19, U19 const&>, std::is_nothrow_constructible<T20, U20 const&>,
                std::is_nothrow_constructible<T21, U21 const&>, std::is_nothrow_constructible<T22, U22 const&>, std::is_nothrow_constructible<T23, U23 const&>,
                std::is_nothrow_constructible<T24, U24 const&>, std::is_nothrow_constructible<T25, U25 const&>, std::is_nothrow_constructible<T26, U26 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24), _25(other._25), _26(other._26)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26>&& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                               std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                               std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                               std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                               std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                               std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>, std::is_nothrow_constructible<T17, U17&&>,
                               std::is_nothrow_constructible<T18, U18&&>, std::is_nothrow_constructible<T19, U19&&>, std::is_nothrow_constructible<T20, U20&&>,
                               std::is_nothrow_constructible<T21, U21&&>, std::is_nothrow_constructible<T22, U22&&>, std::is_nothrow_constructible<T23, U23&&>,
                               std::is_nothrow_constructible<T24, U24&&>, std::is_nothrow_constructible<T25, U25&&>, std::is_nothrow_constructible<T26, U26&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24), _25(static_cast<decltype(other)>(other)._25), _26(static_cast<decltype(other)>(other)._26)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26> const&& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
                 std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                 std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
                 std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>,
                 std::is_nothrow_constructible<T11, U11 const&&>, std::is_nothrow_constructible<T12, U12 const&&>,
                 std::is_nothrow_constructible<T13, U13 const&&>, std::is_nothrow_constructible<T14, U14 const&&>,
                 std::is_nothrow_constructible<T15, U15 const&&>, std::is_nothrow_constructible<T16, U16 const&&>,
                 std::is_nothrow_constructible<T17, U17 const&&>, std::is_nothrow_constructible<T18, U18 const&&>,
                 std::is_nothrow_constructible<T19, U19 const&&>, std::is_nothrow_constructible<T20, U20 const&&>,
                 std::is_nothrow_constructible<T21, U21 const&&>, std::is_nothrow_constructible<T22, U22 const&&>,
                 std::is_nothrow_constructible<T23, U23 const&&>, std::is_nothrow_constructible<T24, U24 const&&>,
                 std::is_nothrow_constructible<T25, U25 const&&>, std::is_nothrow_constructible<T26, U26 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24), _25(static_cast<decltype(other)>(other)._25), _26(static_cast<decltype(other)>(other)._26)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        _17 = other._17;
        _18 = other._18;
        _19 = other._19;
        _20 = other._20;
        _21 = other._21;
        _22 = other._22;
        _23 = other._23;
        _24 = other._24;
        _25 = other._25;
        _26 = other._26;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>, std::is_nothrow_move_assignable<T17>,
                                    std::is_nothrow_move_assignable<T18>, std::is_nothrow_move_assignable<T19>, std::is_nothrow_move_assignable<T20>,
                                    std::is_nothrow_move_assignable<T21>, std::is_nothrow_move_assignable<T22>, std::is_nothrow_move_assignable<T23>,
                                    std::is_nothrow_move_assignable<T24>, std::is_nothrow_move_assignable<T25>, std::is_nothrow_move_assignable<T26>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        _17 = static_cast<decltype(other)>(other)._17;
        _18 = static_cast<decltype(other)>(other)._18;
        _19 = static_cast<decltype(other)>(other)._19;
        _20 = static_cast<decltype(other)>(other)._20;
        _21 = static_cast<decltype(other)>(other)._21;
        _22 = static_cast<decltype(other)>(other)._22;
        _23 = static_cast<decltype(other)>(other)._23;
        _24 = static_cast<decltype(other)>(other)._24;
        _25 = static_cast<decltype(other)>(other)._25;
        _26 = static_cast<decltype(other)>(other)._26;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20,
                                                           T21, T22, T23, T24, T25, T26>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
        else if constexpr (I == 17)
            return ((forward_like_t<Self, tuple_impl>)self)._17;
        else if constexpr (I == 18)
            return ((forward_like_t<Self, tuple_impl>)self)._18;
        else if constexpr (I == 19)
            return ((forward_like_t<Self, tuple_impl>)self)._19;
        else if constexpr (I == 20)
            return ((forward_like_t<Self, tuple_impl>)self)._20;
        else if constexpr (I == 21)
            return ((forward_like_t<Self, tuple_impl>)self)._21;
        else if constexpr (I == 22)
            return ((forward_like_t<Self, tuple_impl>)self)._22;
        else if constexpr (I == 23)
            return ((forward_like_t<Self, tuple_impl>)self)._23;
        else if constexpr (I == 24)
            return ((forward_like_t<Self, tuple_impl>)self)._24;
        else if constexpr (I == 25)
            return ((forward_like_t<Self, tuple_impl>)self)._25;
        else if constexpr (I == 26)
            return ((forward_like_t<Self, tuple_impl>)self)._26;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16, class T17, class T18, class T19, class T20, class T21, class T22, class T23, class T24, class T25, class T26,
         class T27>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T17 _17;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T18 _18;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T19 _19;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T20 _20;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T21 _21;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T22 _22;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T23 _23;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T24 _24;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T25 _25;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T26 _26;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T27 _27;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>, std::is_nothrow_default_constructible<T17>,
                           std::is_nothrow_default_constructible<T18>, std::is_nothrow_default_constructible<T19>, std::is_nothrow_default_constructible<T20>,
                           std::is_nothrow_default_constructible<T21>, std::is_nothrow_default_constructible<T22>, std::is_nothrow_default_constructible<T23>,
                           std::is_nothrow_default_constructible<T24>, std::is_nothrow_default_constructible<T25>, std::is_nothrow_default_constructible<T26>,
                           std::is_nothrow_default_constructible<T27>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}, _17{}, _18{}, _19{}, _20{}, _21{}, _22{},
          _23{}, _24{}, _25{}, _26{}, _27{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16, U17&& u17, U18&& u18, U19&& u19, U20&& u20, U21&& u21, U22&& u22, U23&& u23,
                                  U24&& u24, U25&& u25, U26&& u26, U27&& u27)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>, std::is_nothrow_constructible<T17, U17>,
                                    std::is_nothrow_constructible<T18, U18>, std::is_nothrow_constructible<T19, U19>, std::is_nothrow_constructible<T20, U20>,
                                    std::is_nothrow_constructible<T21, U21>, std::is_nothrow_constructible<T22, U22>, std::is_nothrow_constructible<T23, U23>,
                                    std::is_nothrow_constructible<T24, U24>, std::is_nothrow_constructible<T25, U25>, std::is_nothrow_constructible<T26, U26>,
                                    std::is_nothrow_constructible<T27, U27>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16)), _17(static_cast<U17>(u17)), _18(static_cast<U18>(u18)), _19(static_cast<U19>(u19)), _20(static_cast<U20>(u20)),
          _21(static_cast<U21>(u21)), _22(static_cast<U22>(u22)), _23(static_cast<U23>(u23)), _24(static_cast<U24>(u24)), _25(static_cast<U25>(u25)),
          _26(static_cast<U26>(u26)), _27(static_cast<U27>(u27))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27>& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                               std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                               std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                               std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                               std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                               std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>, std::is_nothrow_constructible<T17, U17&>,
                               std::is_nothrow_constructible<T18, U18&>, std::is_nothrow_constructible<T19, U19&>, std::is_nothrow_constructible<T20, U20&>,
                               std::is_nothrow_constructible<T21, U21&>, std::is_nothrow_constructible<T22, U22&>, std::is_nothrow_constructible<T23, U23&>,
                               std::is_nothrow_constructible<T24, U24&>, std::is_nothrow_constructible<T25, U25&>, std::is_nothrow_constructible<T26, U26&>,
                               std::is_nothrow_constructible<T27, U27&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24), _25(other._25), _26(other._26), _27(other._27)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                 std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                 std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>, std::is_nothrow_constructible<T17, U17 const&>,
                 std::is_nothrow_constructible<T18, U18 const&>, std::is_nothrow_constructible<T19, U19 const&>, std::is_nothrow_constructible<T20, U20 const&>,
                 std::is_nothrow_constructible<T21, U21 const&>, std::is_nothrow_constructible<T22, U22 const&>, std::is_nothrow_constructible<T23, U23 const&>,
                 std::is_nothrow_constructible<T24, U24 const&>, std::is_nothrow_constructible<T25, U25 const&>, std::is_nothrow_constructible<T26, U26 const&>,
                 std::is_nothrow_constructible<T27, U27 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24), _25(other._25), _26(other._26), _27(other._27)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27>
    constexpr explicit tuple_impl(
        tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27>&& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                               std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                               std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                               std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                               std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                               std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>, std::is_nothrow_constructible<T17, U17&&>,
                               std::is_nothrow_constructible<T18, U18&&>, std::is_nothrow_constructible<T19, U19&&>, std::is_nothrow_constructible<T20, U20&&>,
                               std::is_nothrow_constructible<T21, U21&&>, std::is_nothrow_constructible<T22, U22&&>, std::is_nothrow_constructible<T23, U23&&>,
                               std::is_nothrow_constructible<T24, U24&&>, std::is_nothrow_constructible<T25, U25&&>, std::is_nothrow_constructible<T26, U26&&>,
                               std::is_nothrow_constructible<T27, U27&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24), _25(static_cast<decltype(other)>(other)._25), _26(static_cast<decltype(other)>(other)._26),
          _27(static_cast<decltype(other)>(other)._27)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27> const&& other)
        noexcept(
            std::conjunction_v<
                std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
                std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
                std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>, std::is_nothrow_constructible<T11, U11 const&&>,
                std::is_nothrow_constructible<T12, U12 const&&>, std::is_nothrow_constructible<T13, U13 const&&>,
                std::is_nothrow_constructible<T14, U14 const&&>, std::is_nothrow_constructible<T15, U15 const&&>,
                std::is_nothrow_constructible<T16, U16 const&&>, std::is_nothrow_constructible<T17, U17 const&&>,
                std::is_nothrow_constructible<T18, U18 const&&>, std::is_nothrow_constructible<T19, U19 const&&>,
                std::is_nothrow_constructible<T20, U20 const&&>, std::is_nothrow_constructible<T21, U21 const&&>,
                std::is_nothrow_constructible<T22, U22 const&&>, std::is_nothrow_constructible<T23, U23 const&&>,
                std::is_nothrow_constructible<T24, U24 const&&>, std::is_nothrow_constructible<T25, U25 const&&>,
                std::is_nothrow_constructible<T26, U26 const&&>, std::is_nothrow_constructible<T27, U27 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24), _25(static_cast<decltype(other)>(other)._25), _26(static_cast<decltype(other)>(other)._26),
          _27(static_cast<decltype(other)>(other)._27)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        _17 = other._17;
        _18 = other._18;
        _19 = other._19;
        _20 = other._20;
        _21 = other._21;
        _22 = other._22;
        _23 = other._23;
        _24 = other._24;
        _25 = other._25;
        _26 = other._26;
        _27 = other._27;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>, std::is_nothrow_move_assignable<T17>,
                                    std::is_nothrow_move_assignable<T18>, std::is_nothrow_move_assignable<T19>, std::is_nothrow_move_assignable<T20>,
                                    std::is_nothrow_move_assignable<T21>, std::is_nothrow_move_assignable<T22>, std::is_nothrow_move_assignable<T23>,
                                    std::is_nothrow_move_assignable<T24>, std::is_nothrow_move_assignable<T25>, std::is_nothrow_move_assignable<T26>,
                                    std::is_nothrow_move_assignable<T27>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        _17 = static_cast<decltype(other)>(other)._17;
        _18 = static_cast<decltype(other)>(other)._18;
        _19 = static_cast<decltype(other)>(other)._19;
        _20 = static_cast<decltype(other)>(other)._20;
        _21 = static_cast<decltype(other)>(other)._21;
        _22 = static_cast<decltype(other)>(other)._22;
        _23 = static_cast<decltype(other)>(other)._23;
        _24 = static_cast<decltype(other)>(other)._24;
        _25 = static_cast<decltype(other)>(other)._25;
        _26 = static_cast<decltype(other)>(other)._26;
        _27 = static_cast<decltype(other)>(other)._27;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20,
                                                           T21, T22, T23, T24, T25, T26, T27>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
        else if constexpr (I == 17)
            return ((forward_like_t<Self, tuple_impl>)self)._17;
        else if constexpr (I == 18)
            return ((forward_like_t<Self, tuple_impl>)self)._18;
        else if constexpr (I == 19)
            return ((forward_like_t<Self, tuple_impl>)self)._19;
        else if constexpr (I == 20)
            return ((forward_like_t<Self, tuple_impl>)self)._20;
        else if constexpr (I == 21)
            return ((forward_like_t<Self, tuple_impl>)self)._21;
        else if constexpr (I == 22)
            return ((forward_like_t<Self, tuple_impl>)self)._22;
        else if constexpr (I == 23)
            return ((forward_like_t<Self, tuple_impl>)self)._23;
        else if constexpr (I == 24)
            return ((forward_like_t<Self, tuple_impl>)self)._24;
        else if constexpr (I == 25)
            return ((forward_like_t<Self, tuple_impl>)self)._25;
        else if constexpr (I == 26)
            return ((forward_like_t<Self, tuple_impl>)self)._26;
        else if constexpr (I == 27)
            return ((forward_like_t<Self, tuple_impl>)self)._27;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16, class T17, class T18, class T19, class T20, class T21, class T22, class T23, class T24, class T25, class T26,
         class T27, class T28>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T17 _17;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T18 _18;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T19 _19;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T20 _20;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T21 _21;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T22 _22;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T23 _23;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T24 _24;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T25 _25;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T26 _26;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T27 _27;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T28 _28;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>, std::is_nothrow_default_constructible<T17>,
                           std::is_nothrow_default_constructible<T18>, std::is_nothrow_default_constructible<T19>, std::is_nothrow_default_constructible<T20>,
                           std::is_nothrow_default_constructible<T21>, std::is_nothrow_default_constructible<T22>, std::is_nothrow_default_constructible<T23>,
                           std::is_nothrow_default_constructible<T24>, std::is_nothrow_default_constructible<T25>, std::is_nothrow_default_constructible<T26>,
                           std::is_nothrow_default_constructible<T27>, std::is_nothrow_default_constructible<T28>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}, _17{}, _18{}, _19{}, _20{}, _21{}, _22{},
          _23{}, _24{}, _25{}, _26{}, _27{}, _28{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16, U17&& u17, U18&& u18, U19&& u19, U20&& u20, U21&& u21, U22&& u22, U23&& u23,
                                  U24&& u24, U25&& u25, U26&& u26, U27&& u27, U28&& u28)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>, std::is_nothrow_constructible<T17, U17>,
                                    std::is_nothrow_constructible<T18, U18>, std::is_nothrow_constructible<T19, U19>, std::is_nothrow_constructible<T20, U20>,
                                    std::is_nothrow_constructible<T21, U21>, std::is_nothrow_constructible<T22, U22>, std::is_nothrow_constructible<T23, U23>,
                                    std::is_nothrow_constructible<T24, U24>, std::is_nothrow_constructible<T25, U25>, std::is_nothrow_constructible<T26, U26>,
                                    std::is_nothrow_constructible<T27, U27>, std::is_nothrow_constructible<T28, U28>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16)), _17(static_cast<U17>(u17)), _18(static_cast<U18>(u18)), _19(static_cast<U19>(u19)), _20(static_cast<U20>(u20)),
          _21(static_cast<U21>(u21)), _22(static_cast<U22>(u22)), _23(static_cast<U23>(u23)), _24(static_cast<U24>(u24)), _25(static_cast<U25>(u25)),
          _26(static_cast<U26>(u26)), _27(static_cast<U27>(u27)), _28(static_cast<U28>(u28))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28>& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                               std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                               std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                               std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                               std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                               std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>, std::is_nothrow_constructible<T17, U17&>,
                               std::is_nothrow_constructible<T18, U18&>, std::is_nothrow_constructible<T19, U19&>, std::is_nothrow_constructible<T20, U20&>,
                               std::is_nothrow_constructible<T21, U21&>, std::is_nothrow_constructible<T22, U22&>, std::is_nothrow_constructible<T23, U23&>,
                               std::is_nothrow_constructible<T24, U24&>, std::is_nothrow_constructible<T25, U25&>, std::is_nothrow_constructible<T26, U26&>,
                               std::is_nothrow_constructible<T27, U27&>, std::is_nothrow_constructible<T28, U28&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24), _25(other._25), _26(other._26), _27(other._27),
          _28(other._28)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                 std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                 std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>, std::is_nothrow_constructible<T17, U17 const&>,
                 std::is_nothrow_constructible<T18, U18 const&>, std::is_nothrow_constructible<T19, U19 const&>, std::is_nothrow_constructible<T20, U20 const&>,
                 std::is_nothrow_constructible<T21, U21 const&>, std::is_nothrow_constructible<T22, U22 const&>, std::is_nothrow_constructible<T23, U23 const&>,
                 std::is_nothrow_constructible<T24, U24 const&>, std::is_nothrow_constructible<T25, U25 const&>, std::is_nothrow_constructible<T26, U26 const&>,
                 std::is_nothrow_constructible<T27, U27 const&>, std::is_nothrow_constructible<T28, U28 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24), _25(other._25), _26(other._26), _27(other._27),
          _28(other._28)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28>&& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                               std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                               std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                               std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                               std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                               std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>, std::is_nothrow_constructible<T17, U17&&>,
                               std::is_nothrow_constructible<T18, U18&&>, std::is_nothrow_constructible<T19, U19&&>, std::is_nothrow_constructible<T20, U20&&>,
                               std::is_nothrow_constructible<T21, U21&&>, std::is_nothrow_constructible<T22, U22&&>, std::is_nothrow_constructible<T23, U23&&>,
                               std::is_nothrow_constructible<T24, U24&&>, std::is_nothrow_constructible<T25, U25&&>, std::is_nothrow_constructible<T26, U26&&>,
                               std::is_nothrow_constructible<T27, U27&&>, std::is_nothrow_constructible<T28, U28&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24), _25(static_cast<decltype(other)>(other)._25), _26(static_cast<decltype(other)>(other)._26),
          _27(static_cast<decltype(other)>(other)._27), _28(static_cast<decltype(other)>(other)._28)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28> const&& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
                 std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                 std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
                 std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>,
                 std::is_nothrow_constructible<T11, U11 const&&>, std::is_nothrow_constructible<T12, U12 const&&>,
                 std::is_nothrow_constructible<T13, U13 const&&>, std::is_nothrow_constructible<T14, U14 const&&>,
                 std::is_nothrow_constructible<T15, U15 const&&>, std::is_nothrow_constructible<T16, U16 const&&>,
                 std::is_nothrow_constructible<T17, U17 const&&>, std::is_nothrow_constructible<T18, U18 const&&>,
                 std::is_nothrow_constructible<T19, U19 const&&>, std::is_nothrow_constructible<T20, U20 const&&>,
                 std::is_nothrow_constructible<T21, U21 const&&>, std::is_nothrow_constructible<T22, U22 const&&>,
                 std::is_nothrow_constructible<T23, U23 const&&>, std::is_nothrow_constructible<T24, U24 const&&>,
                 std::is_nothrow_constructible<T25, U25 const&&>, std::is_nothrow_constructible<T26, U26 const&&>,
                 std::is_nothrow_constructible<T27, U27 const&&>, std::is_nothrow_constructible<T28, U28 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24), _25(static_cast<decltype(other)>(other)._25), _26(static_cast<decltype(other)>(other)._26),
          _27(static_cast<decltype(other)>(other)._27), _28(static_cast<decltype(other)>(other)._28)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        _17 = other._17;
        _18 = other._18;
        _19 = other._19;
        _20 = other._20;
        _21 = other._21;
        _22 = other._22;
        _23 = other._23;
        _24 = other._24;
        _25 = other._25;
        _26 = other._26;
        _27 = other._27;
        _28 = other._28;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>, std::is_nothrow_move_assignable<T17>,
                                    std::is_nothrow_move_assignable<T18>, std::is_nothrow_move_assignable<T19>, std::is_nothrow_move_assignable<T20>,
                                    std::is_nothrow_move_assignable<T21>, std::is_nothrow_move_assignable<T22>, std::is_nothrow_move_assignable<T23>,
                                    std::is_nothrow_move_assignable<T24>, std::is_nothrow_move_assignable<T25>, std::is_nothrow_move_assignable<T26>,
                                    std::is_nothrow_move_assignable<T27>, std::is_nothrow_move_assignable<T28>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        _17 = static_cast<decltype(other)>(other)._17;
        _18 = static_cast<decltype(other)>(other)._18;
        _19 = static_cast<decltype(other)>(other)._19;
        _20 = static_cast<decltype(other)>(other)._20;
        _21 = static_cast<decltype(other)>(other)._21;
        _22 = static_cast<decltype(other)>(other)._22;
        _23 = static_cast<decltype(other)>(other)._23;
        _24 = static_cast<decltype(other)>(other)._24;
        _25 = static_cast<decltype(other)>(other)._25;
        _26 = static_cast<decltype(other)>(other)._26;
        _27 = static_cast<decltype(other)>(other)._27;
        _28 = static_cast<decltype(other)>(other)._28;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20,
                                                           T21, T22, T23, T24, T25, T26, T27, T28>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
        else if constexpr (I == 17)
            return ((forward_like_t<Self, tuple_impl>)self)._17;
        else if constexpr (I == 18)
            return ((forward_like_t<Self, tuple_impl>)self)._18;
        else if constexpr (I == 19)
            return ((forward_like_t<Self, tuple_impl>)self)._19;
        else if constexpr (I == 20)
            return ((forward_like_t<Self, tuple_impl>)self)._20;
        else if constexpr (I == 21)
            return ((forward_like_t<Self, tuple_impl>)self)._21;
        else if constexpr (I == 22)
            return ((forward_like_t<Self, tuple_impl>)self)._22;
        else if constexpr (I == 23)
            return ((forward_like_t<Self, tuple_impl>)self)._23;
        else if constexpr (I == 24)
            return ((forward_like_t<Self, tuple_impl>)self)._24;
        else if constexpr (I == 25)
            return ((forward_like_t<Self, tuple_impl>)self)._25;
        else if constexpr (I == 26)
            return ((forward_like_t<Self, tuple_impl>)self)._26;
        else if constexpr (I == 27)
            return ((forward_like_t<Self, tuple_impl>)self)._27;
        else if constexpr (I == 28)
            return ((forward_like_t<Self, tuple_impl>)self)._28;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16, class T17, class T18, class T19, class T20, class T21, class T22, class T23, class T24, class T25, class T26,
         class T27, class T28, class T29>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T17 _17;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T18 _18;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T19 _19;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T20 _20;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T21 _21;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T22 _22;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T23 _23;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T24 _24;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T25 _25;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T26 _26;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T27 _27;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T28 _28;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T29 _29;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>, std::is_nothrow_default_constructible<T17>,
                           std::is_nothrow_default_constructible<T18>, std::is_nothrow_default_constructible<T19>, std::is_nothrow_default_constructible<T20>,
                           std::is_nothrow_default_constructible<T21>, std::is_nothrow_default_constructible<T22>, std::is_nothrow_default_constructible<T23>,
                           std::is_nothrow_default_constructible<T24>, std::is_nothrow_default_constructible<T25>, std::is_nothrow_default_constructible<T26>,
                           std::is_nothrow_default_constructible<T27>, std::is_nothrow_default_constructible<T28>, std::is_nothrow_default_constructible<T29>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}, _17{}, _18{}, _19{}, _20{}, _21{}, _22{},
          _23{}, _24{}, _25{}, _26{}, _27{}, _28{}, _29{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28, class U29>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16, U17&& u17, U18&& u18, U19&& u19, U20&& u20, U21&& u21, U22&& u22, U23&& u23,
                                  U24&& u24, U25&& u25, U26&& u26, U27&& u27, U28&& u28, U29&& u29)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>, std::is_nothrow_constructible<T17, U17>,
                                    std::is_nothrow_constructible<T18, U18>, std::is_nothrow_constructible<T19, U19>, std::is_nothrow_constructible<T20, U20>,
                                    std::is_nothrow_constructible<T21, U21>, std::is_nothrow_constructible<T22, U22>, std::is_nothrow_constructible<T23, U23>,
                                    std::is_nothrow_constructible<T24, U24>, std::is_nothrow_constructible<T25, U25>, std::is_nothrow_constructible<T26, U26>,
                                    std::is_nothrow_constructible<T27, U27>, std::is_nothrow_constructible<T28, U28>, std::is_nothrow_constructible<T29, U29>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16)), _17(static_cast<U17>(u17)), _18(static_cast<U18>(u18)), _19(static_cast<U19>(u19)), _20(static_cast<U20>(u20)),
          _21(static_cast<U21>(u21)), _22(static_cast<U22>(u22)), _23(static_cast<U23>(u23)), _24(static_cast<U24>(u24)), _25(static_cast<U25>(u25)),
          _26(static_cast<U26>(u26)), _27(static_cast<U27>(u27)), _28(static_cast<U28>(u28)), _29(static_cast<U29>(u29))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28, class U29>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28, U29>& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                               std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                               std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                               std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                               std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                               std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>, std::is_nothrow_constructible<T17, U17&>,
                               std::is_nothrow_constructible<T18, U18&>, std::is_nothrow_constructible<T19, U19&>, std::is_nothrow_constructible<T20, U20&>,
                               std::is_nothrow_constructible<T21, U21&>, std::is_nothrow_constructible<T22, U22&>, std::is_nothrow_constructible<T23, U23&>,
                               std::is_nothrow_constructible<T24, U24&>, std::is_nothrow_constructible<T25, U25&>, std::is_nothrow_constructible<T26, U26&>,
                               std::is_nothrow_constructible<T27, U27&>, std::is_nothrow_constructible<T28, U28&>, std::is_nothrow_constructible<T29, U29&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24), _25(other._25), _26(other._26), _27(other._27),
          _28(other._28), _29(other._29)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28, class U29>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28, U29> const& other)
        noexcept(
            std::conjunction_v<
                std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>, std::is_nothrow_constructible<T17, U17 const&>,
                std::is_nothrow_constructible<T18, U18 const&>, std::is_nothrow_constructible<T19, U19 const&>, std::is_nothrow_constructible<T20, U20 const&>,
                std::is_nothrow_constructible<T21, U21 const&>, std::is_nothrow_constructible<T22, U22 const&>, std::is_nothrow_constructible<T23, U23 const&>,
                std::is_nothrow_constructible<T24, U24 const&>, std::is_nothrow_constructible<T25, U25 const&>, std::is_nothrow_constructible<T26, U26 const&>,
                std::is_nothrow_constructible<T27, U27 const&>, std::is_nothrow_constructible<T28, U28 const&>, std::is_nothrow_constructible<T29, U29 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24), _25(other._25), _26(other._26), _27(other._27),
          _28(other._28), _29(other._29)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28, class U29>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28, U29>&& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                               std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                               std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                               std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                               std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                               std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>, std::is_nothrow_constructible<T17, U17&&>,
                               std::is_nothrow_constructible<T18, U18&&>, std::is_nothrow_constructible<T19, U19&&>, std::is_nothrow_constructible<T20, U20&&>,
                               std::is_nothrow_constructible<T21, U21&&>, std::is_nothrow_constructible<T22, U22&&>, std::is_nothrow_constructible<T23, U23&&>,
                               std::is_nothrow_constructible<T24, U24&&>, std::is_nothrow_constructible<T25, U25&&>, std::is_nothrow_constructible<T26, U26&&>,
                               std::is_nothrow_constructible<T27, U27&&>, std::is_nothrow_constructible<T28, U28&&>, std::is_nothrow_constructible<T29, U29&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24), _25(static_cast<decltype(other)>(other)._25), _26(static_cast<decltype(other)>(other)._26),
          _27(static_cast<decltype(other)>(other)._27), _28(static_cast<decltype(other)>(other)._28), _29(static_cast<decltype(other)>(other)._29)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28, class U29>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28, U29> const&& other)
        noexcept(
            std::conjunction_v<
                std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
                std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
                std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>, std::is_nothrow_constructible<T11, U11 const&&>,
                std::is_nothrow_constructible<T12, U12 const&&>, std::is_nothrow_constructible<T13, U13 const&&>,
                std::is_nothrow_constructible<T14, U14 const&&>, std::is_nothrow_constructible<T15, U15 const&&>,
                std::is_nothrow_constructible<T16, U16 const&&>, std::is_nothrow_constructible<T17, U17 const&&>,
                std::is_nothrow_constructible<T18, U18 const&&>, std::is_nothrow_constructible<T19, U19 const&&>,
                std::is_nothrow_constructible<T20, U20 const&&>, std::is_nothrow_constructible<T21, U21 const&&>,
                std::is_nothrow_constructible<T22, U22 const&&>, std::is_nothrow_constructible<T23, U23 const&&>,
                std::is_nothrow_constructible<T24, U24 const&&>, std::is_nothrow_constructible<T25, U25 const&&>,
                std::is_nothrow_constructible<T26, U26 const&&>, std::is_nothrow_constructible<T27, U27 const&&>,
                std::is_nothrow_constructible<T28, U28 const&&>, std::is_nothrow_constructible<T29, U29 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24), _25(static_cast<decltype(other)>(other)._25), _26(static_cast<decltype(other)>(other)._26),
          _27(static_cast<decltype(other)>(other)._27), _28(static_cast<decltype(other)>(other)._28), _29(static_cast<decltype(other)>(other)._29)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        _17 = other._17;
        _18 = other._18;
        _19 = other._19;
        _20 = other._20;
        _21 = other._21;
        _22 = other._22;
        _23 = other._23;
        _24 = other._24;
        _25 = other._25;
        _26 = other._26;
        _27 = other._27;
        _28 = other._28;
        _29 = other._29;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>, std::is_nothrow_move_assignable<T17>,
                                    std::is_nothrow_move_assignable<T18>, std::is_nothrow_move_assignable<T19>, std::is_nothrow_move_assignable<T20>,
                                    std::is_nothrow_move_assignable<T21>, std::is_nothrow_move_assignable<T22>, std::is_nothrow_move_assignable<T23>,
                                    std::is_nothrow_move_assignable<T24>, std::is_nothrow_move_assignable<T25>, std::is_nothrow_move_assignable<T26>,
                                    std::is_nothrow_move_assignable<T27>, std::is_nothrow_move_assignable<T28>, std::is_nothrow_move_assignable<T29>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        _17 = static_cast<decltype(other)>(other)._17;
        _18 = static_cast<decltype(other)>(other)._18;
        _19 = static_cast<decltype(other)>(other)._19;
        _20 = static_cast<decltype(other)>(other)._20;
        _21 = static_cast<decltype(other)>(other)._21;
        _22 = static_cast<decltype(other)>(other)._22;
        _23 = static_cast<decltype(other)>(other)._23;
        _24 = static_cast<decltype(other)>(other)._24;
        _25 = static_cast<decltype(other)>(other)._25;
        _26 = static_cast<decltype(other)>(other)._26;
        _27 = static_cast<decltype(other)>(other)._27;
        _28 = static_cast<decltype(other)>(other)._28;
        _29 = static_cast<decltype(other)>(other)._29;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20,
                                                           T21, T22, T23, T24, T25, T26, T27, T28, T29>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
        else if constexpr (I == 17)
            return ((forward_like_t<Self, tuple_impl>)self)._17;
        else if constexpr (I == 18)
            return ((forward_like_t<Self, tuple_impl>)self)._18;
        else if constexpr (I == 19)
            return ((forward_like_t<Self, tuple_impl>)self)._19;
        else if constexpr (I == 20)
            return ((forward_like_t<Self, tuple_impl>)self)._20;
        else if constexpr (I == 21)
            return ((forward_like_t<Self, tuple_impl>)self)._21;
        else if constexpr (I == 22)
            return ((forward_like_t<Self, tuple_impl>)self)._22;
        else if constexpr (I == 23)
            return ((forward_like_t<Self, tuple_impl>)self)._23;
        else if constexpr (I == 24)
            return ((forward_like_t<Self, tuple_impl>)self)._24;
        else if constexpr (I == 25)
            return ((forward_like_t<Self, tuple_impl>)self)._25;
        else if constexpr (I == 26)
            return ((forward_like_t<Self, tuple_impl>)self)._26;
        else if constexpr (I == 27)
            return ((forward_like_t<Self, tuple_impl>)self)._27;
        else if constexpr (I == 28)
            return ((forward_like_t<Self, tuple_impl>)self)._28;
        else if constexpr (I == 29)
            return ((forward_like_t<Self, tuple_impl>)self)._29;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16, class T17, class T18, class T19, class T20, class T21, class T22, class T23, class T24, class T25, class T26,
         class T27, class T28, class T29, class T30>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29,
                 T30>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T17 _17;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T18 _18;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T19 _19;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T20 _20;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T21 _21;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T22 _22;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T23 _23;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T24 _24;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T25 _25;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T26 _26;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T27 _27;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T28 _28;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T29 _29;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T30 _30;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t) noexcept(
        std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                           std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                           std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                           std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                           std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                           std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>, std::is_nothrow_default_constructible<T17>,
                           std::is_nothrow_default_constructible<T18>, std::is_nothrow_default_constructible<T19>, std::is_nothrow_default_constructible<T20>,
                           std::is_nothrow_default_constructible<T21>, std::is_nothrow_default_constructible<T22>, std::is_nothrow_default_constructible<T23>,
                           std::is_nothrow_default_constructible<T24>, std::is_nothrow_default_constructible<T25>, std::is_nothrow_default_constructible<T26>,
                           std::is_nothrow_default_constructible<T27>, std::is_nothrow_default_constructible<T28>, std::is_nothrow_default_constructible<T29>,
                           std::is_nothrow_default_constructible<T30>>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}, _17{}, _18{}, _19{}, _20{}, _21{}, _22{},
          _23{}, _24{}, _25{}, _26{}, _27{}, _28{}, _29{}, _30{}
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28, class U29, class U30>
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16, U17&& u17, U18&& u18, U19&& u19, U20&& u20, U21&& u21, U22&& u22, U23&& u23,
                                  U24&& u24, U25&& u25, U26&& u26, U27&& u27, U28&& u28, U29&& u29, U30&& u30)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>, std::is_nothrow_constructible<T17, U17>,
                                    std::is_nothrow_constructible<T18, U18>, std::is_nothrow_constructible<T19, U19>, std::is_nothrow_constructible<T20, U20>,
                                    std::is_nothrow_constructible<T21, U21>, std::is_nothrow_constructible<T22, U22>, std::is_nothrow_constructible<T23, U23>,
                                    std::is_nothrow_constructible<T24, U24>, std::is_nothrow_constructible<T25, U25>, std::is_nothrow_constructible<T26, U26>,
                                    std::is_nothrow_constructible<T27, U27>, std::is_nothrow_constructible<T28, U28>, std::is_nothrow_constructible<T29, U29>,
                                    std::is_nothrow_constructible<T30, U30>>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16)), _17(static_cast<U17>(u17)), _18(static_cast<U18>(u18)), _19(static_cast<U19>(u19)), _20(static_cast<U20>(u20)),
          _21(static_cast<U21>(u21)), _22(static_cast<U22>(u22)), _23(static_cast<U23>(u23)), _24(static_cast<U24>(u24)), _25(static_cast<U25>(u25)),
          _26(static_cast<U26>(u26)), _27(static_cast<U27>(u27)), _28(static_cast<U28>(u28)), _29(static_cast<U29>(u29)), _30(static_cast<U30>(u30))
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28, class U29, class U30>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28, U29, U30>& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                               std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                               std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                               std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                               std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                               std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>, std::is_nothrow_constructible<T17, U17&>,
                               std::is_nothrow_constructible<T18, U18&>, std::is_nothrow_constructible<T19, U19&>, std::is_nothrow_constructible<T20, U20&>,
                               std::is_nothrow_constructible<T21, U21&>, std::is_nothrow_constructible<T22, U22&>, std::is_nothrow_constructible<T23, U23&>,
                               std::is_nothrow_constructible<T24, U24&>, std::is_nothrow_constructible<T25, U25&>, std::is_nothrow_constructible<T26, U26&>,
                               std::is_nothrow_constructible<T27, U27&>, std::is_nothrow_constructible<T28, U28&>, std::is_nothrow_constructible<T29, U29&>,
                               std::is_nothrow_constructible<T30, U30&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24), _25(other._25), _26(other._26), _27(other._27),
          _28(other._28), _29(other._29), _30(other._30)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28, class U29, class U30>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28, U29, U30> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                 std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                 std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>, std::is_nothrow_constructible<T17, U17 const&>,
                 std::is_nothrow_constructible<T18, U18 const&>, std::is_nothrow_constructible<T19, U19 const&>, std::is_nothrow_constructible<T20, U20 const&>,
                 std::is_nothrow_constructible<T21, U21 const&>, std::is_nothrow_constructible<T22, U22 const&>, std::is_nothrow_constructible<T23, U23 const&>,
                 std::is_nothrow_constructible<T24, U24 const&>, std::is_nothrow_constructible<T25, U25 const&>, std::is_nothrow_constructible<T26, U26 const&>,
                 std::is_nothrow_constructible<T27, U27 const&>, std::is_nothrow_constructible<T28, U28 const&>, std::is_nothrow_constructible<T29, U29 const&>,
                 std::is_nothrow_constructible<T30, U30 const&>>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24), _25(other._25), _26(other._26), _27(other._27),
          _28(other._28), _29(other._29), _30(other._30)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28, class U29, class U30>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28, U29, U30>&& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                               std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                               std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                               std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                               std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                               std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>, std::is_nothrow_constructible<T17, U17&&>,
                               std::is_nothrow_constructible<T18, U18&&>, std::is_nothrow_constructible<T19, U19&&>, std::is_nothrow_constructible<T20, U20&&>,
                               std::is_nothrow_constructible<T21, U21&&>, std::is_nothrow_constructible<T22, U22&&>, std::is_nothrow_constructible<T23, U23&&>,
                               std::is_nothrow_constructible<T24, U24&&>, std::is_nothrow_constructible<T25, U25&&>, std::is_nothrow_constructible<T26, U26&&>,
                               std::is_nothrow_constructible<T27, U27&&>, std::is_nothrow_constructible<T28, U28&&>, std::is_nothrow_constructible<T29, U29&&>,
                               std::is_nothrow_constructible<T30, U30&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24), _25(static_cast<decltype(other)>(other)._25), _26(static_cast<decltype(other)>(other)._26),
          _27(static_cast<decltype(other)>(other)._27), _28(static_cast<decltype(other)>(other)._28), _29(static_cast<decltype(other)>(other)._29),
          _30(static_cast<decltype(other)>(other)._30)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28, class U29, class U30>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28, U29, U30> const&& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
                 std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                 std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
                 std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>,
                 std::is_nothrow_constructible<T11, U11 const&&>, std::is_nothrow_constructible<T12, U12 const&&>,
                 std::is_nothrow_constructible<T13, U13 const&&>, std::is_nothrow_constructible<T14, U14 const&&>,
                 std::is_nothrow_constructible<T15, U15 const&&>, std::is_nothrow_constructible<T16, U16 const&&>,
                 std::is_nothrow_constructible<T17, U17 const&&>, std::is_nothrow_constructible<T18, U18 const&&>,
                 std::is_nothrow_constructible<T19, U19 const&&>, std::is_nothrow_constructible<T20, U20 const&&>,
                 std::is_nothrow_constructible<T21, U21 const&&>, std::is_nothrow_constructible<T22, U22 const&&>,
                 std::is_nothrow_constructible<T23, U23 const&&>, std::is_nothrow_constructible<T24, U24 const&&>,
                 std::is_nothrow_constructible<T25, U25 const&&>, std::is_nothrow_constructible<T26, U26 const&&>,
                 std::is_nothrow_constructible<T27, U27 const&&>, std::is_nothrow_constructible<T28, U28 const&&>,
                 std::is_nothrow_constructible<T29, U29 const&&>, std::is_nothrow_constructible<T30, U30 const&&>>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24), _25(static_cast<decltype(other)>(other)._25), _26(static_cast<decltype(other)>(other)._26),
          _27(static_cast<decltype(other)>(other)._27), _28(static_cast<decltype(other)>(other)._28), _29(static_cast<decltype(other)>(other)._29),
          _30(static_cast<decltype(other)>(other)._30)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        _17 = other._17;
        _18 = other._18;
        _19 = other._19;
        _20 = other._20;
        _21 = other._21;
        _22 = other._22;
        _23 = other._23;
        _24 = other._24;
        _25 = other._25;
        _26 = other._26;
        _27 = other._27;
        _28 = other._28;
        _29 = other._29;
        _30 = other._30;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>, std::is_nothrow_move_assignable<T17>,
                                    std::is_nothrow_move_assignable<T18>, std::is_nothrow_move_assignable<T19>, std::is_nothrow_move_assignable<T20>,
                                    std::is_nothrow_move_assignable<T21>, std::is_nothrow_move_assignable<T22>, std::is_nothrow_move_assignable<T23>,
                                    std::is_nothrow_move_assignable<T24>, std::is_nothrow_move_assignable<T25>, std::is_nothrow_move_assignable<T26>,
                                    std::is_nothrow_move_assignable<T27>, std::is_nothrow_move_assignable<T28>, std::is_nothrow_move_assignable<T29>,
                                    std::is_nothrow_move_assignable<T30>>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        _17 = static_cast<decltype(other)>(other)._17;
        _18 = static_cast<decltype(other)>(other)._18;
        _19 = static_cast<decltype(other)>(other)._19;
        _20 = static_cast<decltype(other)>(other)._20;
        _21 = static_cast<decltype(other)>(other)._21;
        _22 = static_cast<decltype(other)>(other)._22;
        _23 = static_cast<decltype(other)>(other)._23;
        _24 = static_cast<decltype(other)>(other)._24;
        _25 = static_cast<decltype(other)>(other)._25;
        _26 = static_cast<decltype(other)>(other)._26;
        _27 = static_cast<decltype(other)>(other)._27;
        _28 = static_cast<decltype(other)>(other)._28;
        _29 = static_cast<decltype(other)>(other)._29;
        _30 = static_cast<decltype(other)>(other)._30;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20,
                                                           T21, T22, T23, T24, T25, T26, T27, T28, T29, T30>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
        else if constexpr (I == 17)
            return ((forward_like_t<Self, tuple_impl>)self)._17;
        else if constexpr (I == 18)
            return ((forward_like_t<Self, tuple_impl>)self)._18;
        else if constexpr (I == 19)
            return ((forward_like_t<Self, tuple_impl>)self)._19;
        else if constexpr (I == 20)
            return ((forward_like_t<Self, tuple_impl>)self)._20;
        else if constexpr (I == 21)
            return ((forward_like_t<Self, tuple_impl>)self)._21;
        else if constexpr (I == 22)
            return ((forward_like_t<Self, tuple_impl>)self)._22;
        else if constexpr (I == 23)
            return ((forward_like_t<Self, tuple_impl>)self)._23;
        else if constexpr (I == 24)
            return ((forward_like_t<Self, tuple_impl>)self)._24;
        else if constexpr (I == 25)
            return ((forward_like_t<Self, tuple_impl>)self)._25;
        else if constexpr (I == 26)
            return ((forward_like_t<Self, tuple_impl>)self)._26;
        else if constexpr (I == 27)
            return ((forward_like_t<Self, tuple_impl>)self)._27;
        else if constexpr (I == 28)
            return ((forward_like_t<Self, tuple_impl>)self)._28;
        else if constexpr (I == 29)
            return ((forward_like_t<Self, tuple_impl>)self)._29;
        else if constexpr (I == 30)
            return ((forward_like_t<Self, tuple_impl>)self)._30;
    }
};
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13,
         class T14, class T15, class T16, class T17, class T18, class T19, class T20, class T21, class T22, class T23, class T24, class T25, class T26,
         class T27, class T28, class T29, class T30, class T31, class... Ts>
class tuple_impl<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29,
                 T30, T31, Ts...>
{
    template<class... Us>
    friend class tuple_impl;

public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T1 _1;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T2 _2;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T3 _3;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T4 _4;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T5 _5;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T6 _6;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T7 _7;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T8 _8;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T9 _9;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T10 _10;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T11 _11;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T12 _12;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T13 _13;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T14 _14;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T15 _15;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T16 _16;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T17 _17;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T18 _18;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T19 _19;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T20 _20;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T21 _21;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T22 _22;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T23 _23;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T24 _24;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T25 _25;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T26 _26;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T27 _27;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T28 _28;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T29 _29;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T30 _30;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T31 _31;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS tuple_impl<Ts...> rest;
    explicit tuple_impl() = default;
    explicit tuple_impl(tuple_impl const&) = default;
    explicit tuple_impl(tuple_impl&&) = default;
    constexpr explicit tuple_impl(value_initialize_t vi)
        noexcept(std::conjunction_v<
                 std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<T1>, std::is_nothrow_default_constructible<T2>,
                 std::is_nothrow_default_constructible<T3>, std::is_nothrow_default_constructible<T4>, std::is_nothrow_default_constructible<T5>,
                 std::is_nothrow_default_constructible<T6>, std::is_nothrow_default_constructible<T7>, std::is_nothrow_default_constructible<T8>,
                 std::is_nothrow_default_constructible<T9>, std::is_nothrow_default_constructible<T10>, std::is_nothrow_default_constructible<T11>,
                 std::is_nothrow_default_constructible<T12>, std::is_nothrow_default_constructible<T13>, std::is_nothrow_default_constructible<T14>,
                 std::is_nothrow_default_constructible<T15>, std::is_nothrow_default_constructible<T16>, std::is_nothrow_default_constructible<T17>,
                 std::is_nothrow_default_constructible<T18>, std::is_nothrow_default_constructible<T19>, std::is_nothrow_default_constructible<T20>,
                 std::is_nothrow_default_constructible<T21>, std::is_nothrow_default_constructible<T22>, std::is_nothrow_default_constructible<T23>,
                 std::is_nothrow_default_constructible<T24>, std::is_nothrow_default_constructible<T25>, std::is_nothrow_default_constructible<T26>,
                 std::is_nothrow_default_constructible<T27>, std::is_nothrow_default_constructible<T28>, std::is_nothrow_default_constructible<T29>,
                 std::is_nothrow_default_constructible<T30>, std::is_nothrow_default_constructible<T31>, std::is_nothrow_default_constructible<Ts>...>)
        : _0{}, _1{}, _2{}, _3{}, _4{}, _5{}, _6{}, _7{}, _8{}, _9{}, _10{}, _11{}, _12{}, _13{}, _14{}, _15{}, _16{}, _17{}, _18{}, _19{}, _20{}, _21{}, _22{},
          _23{}, _24{}, _25{}, _26{}, _27{}, _28{}, _29{}, _30{}, _31{}, rest(vi)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28, class U29, class U30, class U31, class... Us>
        requires (sizeof...(Ts) == sizeof...(Us))
    constexpr explicit tuple_impl(U0&& u0, U1&& u1, U2&& u2, U3&& u3, U4&& u4, U5&& u5, U6&& u6, U7&& u7, U8&& u8, U9&& u9, U10&& u10, U11&& u11, U12&& u12,
                                  U13&& u13, U14&& u14, U15&& u15, U16&& u16, U17&& u17, U18&& u18, U19&& u19, U20&& u20, U21&& u21, U22&& u22, U23&& u23,
                                  U24&& u24, U25&& u25, U26&& u26, U27&& u27, U28&& u28, U29&& u29, U30&& u30, U31&& u31, Us&&... us)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<T1, U1>, std::is_nothrow_constructible<T2, U2>,
                                    std::is_nothrow_constructible<T3, U3>, std::is_nothrow_constructible<T4, U4>, std::is_nothrow_constructible<T5, U5>,
                                    std::is_nothrow_constructible<T6, U6>, std::is_nothrow_constructible<T7, U7>, std::is_nothrow_constructible<T8, U8>,
                                    std::is_nothrow_constructible<T9, U9>, std::is_nothrow_constructible<T10, U10>, std::is_nothrow_constructible<T11, U11>,
                                    std::is_nothrow_constructible<T12, U12>, std::is_nothrow_constructible<T13, U13>, std::is_nothrow_constructible<T14, U14>,
                                    std::is_nothrow_constructible<T15, U15>, std::is_nothrow_constructible<T16, U16>, std::is_nothrow_constructible<T17, U17>,
                                    std::is_nothrow_constructible<T18, U18>, std::is_nothrow_constructible<T19, U19>, std::is_nothrow_constructible<T20, U20>,
                                    std::is_nothrow_constructible<T21, U21>, std::is_nothrow_constructible<T22, U22>, std::is_nothrow_constructible<T23, U23>,
                                    std::is_nothrow_constructible<T24, U24>, std::is_nothrow_constructible<T25, U25>, std::is_nothrow_constructible<T26, U26>,
                                    std::is_nothrow_constructible<T27, U27>, std::is_nothrow_constructible<T28, U28>, std::is_nothrow_constructible<T29, U29>,
                                    std::is_nothrow_constructible<T30, U30>, std::is_nothrow_constructible<T31, U31>, std::is_nothrow_constructible<Ts, Us>...>)
        : _0(static_cast<U0>(u0)), _1(static_cast<U1>(u1)), _2(static_cast<U2>(u2)), _3(static_cast<U3>(u3)), _4(static_cast<U4>(u4)), _5(static_cast<U5>(u5)),
          _6(static_cast<U6>(u6)), _7(static_cast<U7>(u7)), _8(static_cast<U8>(u8)), _9(static_cast<U9>(u9)), _10(static_cast<U10>(u10)),
          _11(static_cast<U11>(u11)), _12(static_cast<U12>(u12)), _13(static_cast<U13>(u13)), _14(static_cast<U14>(u14)), _15(static_cast<U15>(u15)),
          _16(static_cast<U16>(u16)), _17(static_cast<U17>(u17)), _18(static_cast<U18>(u18)), _19(static_cast<U19>(u19)), _20(static_cast<U20>(u20)),
          _21(static_cast<U21>(u21)), _22(static_cast<U22>(u22)), _23(static_cast<U23>(u23)), _24(static_cast<U24>(u24)), _25(static_cast<U25>(u25)),
          _26(static_cast<U26>(u26)), _27(static_cast<U27>(u27)), _28(static_cast<U28>(u28)), _29(static_cast<U29>(u29)), _30(static_cast<U30>(u30)),
          _31(static_cast<U31>(u31)), rest(static_cast<Us&&>(us)...)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28, class U29, class U30, class U31, class... Us>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28, U29, U30, U31, Us...>& other)
        noexcept(
            std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<T1, U1&>, std::is_nothrow_constructible<T2, U2&>,
                               std::is_nothrow_constructible<T3, U3&>, std::is_nothrow_constructible<T4, U4&>, std::is_nothrow_constructible<T5, U5&>,
                               std::is_nothrow_constructible<T6, U6&>, std::is_nothrow_constructible<T7, U7&>, std::is_nothrow_constructible<T8, U8&>,
                               std::is_nothrow_constructible<T9, U9&>, std::is_nothrow_constructible<T10, U10&>, std::is_nothrow_constructible<T11, U11&>,
                               std::is_nothrow_constructible<T12, U12&>, std::is_nothrow_constructible<T13, U13&>, std::is_nothrow_constructible<T14, U14&>,
                               std::is_nothrow_constructible<T15, U15&>, std::is_nothrow_constructible<T16, U16&>, std::is_nothrow_constructible<T17, U17&>,
                               std::is_nothrow_constructible<T18, U18&>, std::is_nothrow_constructible<T19, U19&>, std::is_nothrow_constructible<T20, U20&>,
                               std::is_nothrow_constructible<T21, U21&>, std::is_nothrow_constructible<T22, U22&>, std::is_nothrow_constructible<T23, U23&>,
                               std::is_nothrow_constructible<T24, U24&>, std::is_nothrow_constructible<T25, U25&>, std::is_nothrow_constructible<T26, U26&>,
                               std::is_nothrow_constructible<T27, U27&>, std::is_nothrow_constructible<T28, U28&>, std::is_nothrow_constructible<T29, U29&>,
                               std::is_nothrow_constructible<T30, U30&>, std::is_nothrow_constructible<T31, U31&>, std::is_nothrow_constructible<Ts, Us&>...>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24), _25(other._25), _26(other._26), _27(other._27),
          _28(other._28), _29(other._29), _30(other._30), _31(other._31), rest(other.rest)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28, class U29, class U30, class U31, class... Us>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28, U29, U30, U31, Us...> const& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<T1, U1 const&>, std::is_nothrow_constructible<T2, U2 const&>,
                 std::is_nothrow_constructible<T3, U3 const&>, std::is_nothrow_constructible<T4, U4 const&>, std::is_nothrow_constructible<T5, U5 const&>,
                 std::is_nothrow_constructible<T6, U6 const&>, std::is_nothrow_constructible<T7, U7 const&>, std::is_nothrow_constructible<T8, U8 const&>,
                 std::is_nothrow_constructible<T9, U9 const&>, std::is_nothrow_constructible<T10, U10 const&>, std::is_nothrow_constructible<T11, U11 const&>,
                 std::is_nothrow_constructible<T12, U12 const&>, std::is_nothrow_constructible<T13, U13 const&>, std::is_nothrow_constructible<T14, U14 const&>,
                 std::is_nothrow_constructible<T15, U15 const&>, std::is_nothrow_constructible<T16, U16 const&>, std::is_nothrow_constructible<T17, U17 const&>,
                 std::is_nothrow_constructible<T18, U18 const&>, std::is_nothrow_constructible<T19, U19 const&>, std::is_nothrow_constructible<T20, U20 const&>,
                 std::is_nothrow_constructible<T21, U21 const&>, std::is_nothrow_constructible<T22, U22 const&>, std::is_nothrow_constructible<T23, U23 const&>,
                 std::is_nothrow_constructible<T24, U24 const&>, std::is_nothrow_constructible<T25, U25 const&>, std::is_nothrow_constructible<T26, U26 const&>,
                 std::is_nothrow_constructible<T27, U27 const&>, std::is_nothrow_constructible<T28, U28 const&>, std::is_nothrow_constructible<T29, U29 const&>,
                 std::is_nothrow_constructible<T30, U30 const&>, std::is_nothrow_constructible<T31, U31 const&>,
                 std::is_nothrow_constructible<Ts, Us const&>...>)
        : _0(other._0), _1(other._1), _2(other._2), _3(other._3), _4(other._4), _5(other._5), _6(other._6), _7(other._7), _8(other._8), _9(other._9),
          _10(other._10), _11(other._11), _12(other._12), _13(other._13), _14(other._14), _15(other._15), _16(other._16), _17(other._17), _18(other._18),
          _19(other._19), _20(other._20), _21(other._21), _22(other._22), _23(other._23), _24(other._24), _25(other._25), _26(other._26), _27(other._27),
          _28(other._28), _29(other._29), _30(other._30), _31(other._31), rest(other.rest)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28, class U29, class U30, class U31, class... Us>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28, U29, U30, U31, Us...>&& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<T1, U1&&>, std::is_nothrow_constructible<T2, U2&&>,
                 std::is_nothrow_constructible<T3, U3&&>, std::is_nothrow_constructible<T4, U4&&>, std::is_nothrow_constructible<T5, U5&&>,
                 std::is_nothrow_constructible<T6, U6&&>, std::is_nothrow_constructible<T7, U7&&>, std::is_nothrow_constructible<T8, U8&&>,
                 std::is_nothrow_constructible<T9, U9&&>, std::is_nothrow_constructible<T10, U10&&>, std::is_nothrow_constructible<T11, U11&&>,
                 std::is_nothrow_constructible<T12, U12&&>, std::is_nothrow_constructible<T13, U13&&>, std::is_nothrow_constructible<T14, U14&&>,
                 std::is_nothrow_constructible<T15, U15&&>, std::is_nothrow_constructible<T16, U16&&>, std::is_nothrow_constructible<T17, U17&&>,
                 std::is_nothrow_constructible<T18, U18&&>, std::is_nothrow_constructible<T19, U19&&>, std::is_nothrow_constructible<T20, U20&&>,
                 std::is_nothrow_constructible<T21, U21&&>, std::is_nothrow_constructible<T22, U22&&>, std::is_nothrow_constructible<T23, U23&&>,
                 std::is_nothrow_constructible<T24, U24&&>, std::is_nothrow_constructible<T25, U25&&>, std::is_nothrow_constructible<T26, U26&&>,
                 std::is_nothrow_constructible<T27, U27&&>, std::is_nothrow_constructible<T28, U28&&>, std::is_nothrow_constructible<T29, U29&&>,
                 std::is_nothrow_constructible<T30, U30&&>, std::is_nothrow_constructible<T31, U31&&>, std::is_nothrow_constructible<Ts, Us&&>...>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24), _25(static_cast<decltype(other)>(other)._25), _26(static_cast<decltype(other)>(other)._26),
          _27(static_cast<decltype(other)>(other)._27), _28(static_cast<decltype(other)>(other)._28), _29(static_cast<decltype(other)>(other)._29),
          _30(static_cast<decltype(other)>(other)._30), _31(static_cast<decltype(other)>(other)._31), rest(static_cast<decltype(other)>(other).rest)
    {
    }
    template<class U0, class U1, class U2, class U3, class U4, class U5, class U6, class U7, class U8, class U9, class U10, class U11, class U12, class U13,
             class U14, class U15, class U16, class U17, class U18, class U19, class U20, class U21, class U22, class U23, class U24, class U25, class U26,
             class U27, class U28, class U29, class U30, class U31, class... Us>
    constexpr explicit tuple_impl(tuple_impl<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24,
                                             U25, U26, U27, U28, U29, U30, U31, Us...> const&& other)
        noexcept(std::conjunction_v<
                 std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<T1, U1 const&&>, std::is_nothrow_constructible<T2, U2 const&&>,
                 std::is_nothrow_constructible<T3, U3 const&&>, std::is_nothrow_constructible<T4, U4 const&&>, std::is_nothrow_constructible<T5, U5 const&&>,
                 std::is_nothrow_constructible<T6, U6 const&&>, std::is_nothrow_constructible<T7, U7 const&&>, std::is_nothrow_constructible<T8, U8 const&&>,
                 std::is_nothrow_constructible<T9, U9 const&&>, std::is_nothrow_constructible<T10, U10 const&&>,
                 std::is_nothrow_constructible<T11, U11 const&&>, std::is_nothrow_constructible<T12, U12 const&&>,
                 std::is_nothrow_constructible<T13, U13 const&&>, std::is_nothrow_constructible<T14, U14 const&&>,
                 std::is_nothrow_constructible<T15, U15 const&&>, std::is_nothrow_constructible<T16, U16 const&&>,
                 std::is_nothrow_constructible<T17, U17 const&&>, std::is_nothrow_constructible<T18, U18 const&&>,
                 std::is_nothrow_constructible<T19, U19 const&&>, std::is_nothrow_constructible<T20, U20 const&&>,
                 std::is_nothrow_constructible<T21, U21 const&&>, std::is_nothrow_constructible<T22, U22 const&&>,
                 std::is_nothrow_constructible<T23, U23 const&&>, std::is_nothrow_constructible<T24, U24 const&&>,
                 std::is_nothrow_constructible<T25, U25 const&&>, std::is_nothrow_constructible<T26, U26 const&&>,
                 std::is_nothrow_constructible<T27, U27 const&&>, std::is_nothrow_constructible<T28, U28 const&&>,
                 std::is_nothrow_constructible<T29, U29 const&&>, std::is_nothrow_constructible<T30, U30 const&&>,
                 std::is_nothrow_constructible<T31, U31 const&&>, std::is_nothrow_constructible<Ts, Us const&&>...>)
        : _0(static_cast<decltype(other)>(other)._0), _1(static_cast<decltype(other)>(other)._1), _2(static_cast<decltype(other)>(other)._2),
          _3(static_cast<decltype(other)>(other)._3), _4(static_cast<decltype(other)>(other)._4), _5(static_cast<decltype(other)>(other)._5),
          _6(static_cast<decltype(other)>(other)._6), _7(static_cast<decltype(other)>(other)._7), _8(static_cast<decltype(other)>(other)._8),
          _9(static_cast<decltype(other)>(other)._9), _10(static_cast<decltype(other)>(other)._10), _11(static_cast<decltype(other)>(other)._11),
          _12(static_cast<decltype(other)>(other)._12), _13(static_cast<decltype(other)>(other)._13), _14(static_cast<decltype(other)>(other)._14),
          _15(static_cast<decltype(other)>(other)._15), _16(static_cast<decltype(other)>(other)._16), _17(static_cast<decltype(other)>(other)._17),
          _18(static_cast<decltype(other)>(other)._18), _19(static_cast<decltype(other)>(other)._19), _20(static_cast<decltype(other)>(other)._20),
          _21(static_cast<decltype(other)>(other)._21), _22(static_cast<decltype(other)>(other)._22), _23(static_cast<decltype(other)>(other)._23),
          _24(static_cast<decltype(other)>(other)._24), _25(static_cast<decltype(other)>(other)._25), _26(static_cast<decltype(other)>(other)._26),
          _27(static_cast<decltype(other)>(other)._27), _28(static_cast<decltype(other)>(other)._28), _29(static_cast<decltype(other)>(other)._29),
          _30(static_cast<decltype(other)>(other)._30), _31(static_cast<decltype(other)>(other)._31), rest(static_cast<decltype(other)>(other).rest)
    {
    }
    constexpr tuple_impl& operator=(tuple_impl const& other)
    {
        _0 = other._0;
        _1 = other._1;
        _2 = other._2;
        _3 = other._3;
        _4 = other._4;
        _5 = other._5;
        _6 = other._6;
        _7 = other._7;
        _8 = other._8;
        _9 = other._9;
        _10 = other._10;
        _11 = other._11;
        _12 = other._12;
        _13 = other._13;
        _14 = other._14;
        _15 = other._15;
        _16 = other._16;
        _17 = other._17;
        _18 = other._18;
        _19 = other._19;
        _20 = other._20;
        _21 = other._21;
        _22 = other._22;
        _23 = other._23;
        _24 = other._24;
        _25 = other._25;
        _26 = other._26;
        _27 = other._27;
        _28 = other._28;
        _29 = other._29;
        _30 = other._30;
        _31 = other._31;
        rest = other.rest;
        return *this;
    }
    constexpr tuple_impl& operator=(tuple_impl&& other)
        noexcept(std::conjunction_v<std::is_nothrow_move_assignable<T0>, std::is_nothrow_move_assignable<T1>, std::is_nothrow_move_assignable<T2>,
                                    std::is_nothrow_move_assignable<T3>, std::is_nothrow_move_assignable<T4>, std::is_nothrow_move_assignable<T5>,
                                    std::is_nothrow_move_assignable<T6>, std::is_nothrow_move_assignable<T7>, std::is_nothrow_move_assignable<T8>,
                                    std::is_nothrow_move_assignable<T9>, std::is_nothrow_move_assignable<T10>, std::is_nothrow_move_assignable<T11>,
                                    std::is_nothrow_move_assignable<T12>, std::is_nothrow_move_assignable<T13>, std::is_nothrow_move_assignable<T14>,
                                    std::is_nothrow_move_assignable<T15>, std::is_nothrow_move_assignable<T16>, std::is_nothrow_move_assignable<T17>,
                                    std::is_nothrow_move_assignable<T18>, std::is_nothrow_move_assignable<T19>, std::is_nothrow_move_assignable<T20>,
                                    std::is_nothrow_move_assignable<T21>, std::is_nothrow_move_assignable<T22>, std::is_nothrow_move_assignable<T23>,
                                    std::is_nothrow_move_assignable<T24>, std::is_nothrow_move_assignable<T25>, std::is_nothrow_move_assignable<T26>,
                                    std::is_nothrow_move_assignable<T27>, std::is_nothrow_move_assignable<T28>, std::is_nothrow_move_assignable<T29>,
                                    std::is_nothrow_move_assignable<T30>, std::is_nothrow_move_assignable<T31>, std::is_nothrow_move_assignable<Ts>...>)
    {
        _0 = static_cast<decltype(other)>(other)._0;
        _1 = static_cast<decltype(other)>(other)._1;
        _2 = static_cast<decltype(other)>(other)._2;
        _3 = static_cast<decltype(other)>(other)._3;
        _4 = static_cast<decltype(other)>(other)._4;
        _5 = static_cast<decltype(other)>(other)._5;
        _6 = static_cast<decltype(other)>(other)._6;
        _7 = static_cast<decltype(other)>(other)._7;
        _8 = static_cast<decltype(other)>(other)._8;
        _9 = static_cast<decltype(other)>(other)._9;
        _10 = static_cast<decltype(other)>(other)._10;
        _11 = static_cast<decltype(other)>(other)._11;
        _12 = static_cast<decltype(other)>(other)._12;
        _13 = static_cast<decltype(other)>(other)._13;
        _14 = static_cast<decltype(other)>(other)._14;
        _15 = static_cast<decltype(other)>(other)._15;
        _16 = static_cast<decltype(other)>(other)._16;
        _17 = static_cast<decltype(other)>(other)._17;
        _18 = static_cast<decltype(other)>(other)._18;
        _19 = static_cast<decltype(other)>(other)._19;
        _20 = static_cast<decltype(other)>(other)._20;
        _21 = static_cast<decltype(other)>(other)._21;
        _22 = static_cast<decltype(other)>(other)._22;
        _23 = static_cast<decltype(other)>(other)._23;
        _24 = static_cast<decltype(other)>(other)._24;
        _25 = static_cast<decltype(other)>(other)._25;
        _26 = static_cast<decltype(other)>(other)._26;
        _27 = static_cast<decltype(other)>(other)._27;
        _28 = static_cast<decltype(other)>(other)._28;
        _29 = static_cast<decltype(other)>(other)._29;
        _30 = static_cast<decltype(other)>(other)._30;
        _31 = static_cast<decltype(other)>(other)._31;
        rest = static_cast<decltype(other)>(other).rest;
        return *this;
    }
    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20,
                                                           T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, Ts...>>
    get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else if constexpr (I == 1)
            return ((forward_like_t<Self, tuple_impl>)self)._1;
        else if constexpr (I == 2)
            return ((forward_like_t<Self, tuple_impl>)self)._2;
        else if constexpr (I == 3)
            return ((forward_like_t<Self, tuple_impl>)self)._3;
        else if constexpr (I == 4)
            return ((forward_like_t<Self, tuple_impl>)self)._4;
        else if constexpr (I == 5)
            return ((forward_like_t<Self, tuple_impl>)self)._5;
        else if constexpr (I == 6)
            return ((forward_like_t<Self, tuple_impl>)self)._6;
        else if constexpr (I == 7)
            return ((forward_like_t<Self, tuple_impl>)self)._7;
        else if constexpr (I == 8)
            return ((forward_like_t<Self, tuple_impl>)self)._8;
        else if constexpr (I == 9)
            return ((forward_like_t<Self, tuple_impl>)self)._9;
        else if constexpr (I == 10)
            return ((forward_like_t<Self, tuple_impl>)self)._10;
        else if constexpr (I == 11)
            return ((forward_like_t<Self, tuple_impl>)self)._11;
        else if constexpr (I == 12)
            return ((forward_like_t<Self, tuple_impl>)self)._12;
        else if constexpr (I == 13)
            return ((forward_like_t<Self, tuple_impl>)self)._13;
        else if constexpr (I == 14)
            return ((forward_like_t<Self, tuple_impl>)self)._14;
        else if constexpr (I == 15)
            return ((forward_like_t<Self, tuple_impl>)self)._15;
        else if constexpr (I == 16)
            return ((forward_like_t<Self, tuple_impl>)self)._16;
        else if constexpr (I == 17)
            return ((forward_like_t<Self, tuple_impl>)self)._17;
        else if constexpr (I == 18)
            return ((forward_like_t<Self, tuple_impl>)self)._18;
        else if constexpr (I == 19)
            return ((forward_like_t<Self, tuple_impl>)self)._19;
        else if constexpr (I == 20)
            return ((forward_like_t<Self, tuple_impl>)self)._20;
        else if constexpr (I == 21)
            return ((forward_like_t<Self, tuple_impl>)self)._21;
        else if constexpr (I == 22)
            return ((forward_like_t<Self, tuple_impl>)self)._22;
        else if constexpr (I == 23)
            return ((forward_like_t<Self, tuple_impl>)self)._23;
        else if constexpr (I == 24)
            return ((forward_like_t<Self, tuple_impl>)self)._24;
        else if constexpr (I == 25)
            return ((forward_like_t<Self, tuple_impl>)self)._25;
        else if constexpr (I == 26)
            return ((forward_like_t<Self, tuple_impl>)self)._26;
        else if constexpr (I == 27)
            return ((forward_like_t<Self, tuple_impl>)self)._27;
        else if constexpr (I == 28)
            return ((forward_like_t<Self, tuple_impl>)self)._28;
        else if constexpr (I == 29)
            return ((forward_like_t<Self, tuple_impl>)self)._29;
        else if constexpr (I == 30)
            return ((forward_like_t<Self, tuple_impl>)self)._30;
        else if constexpr (I == 31)
            return ((forward_like_t<Self, tuple_impl>)self)._31;
        else
            return ((forward_like_t<Self, tuple_impl>)self).rest.template get<I - 32>();
    }
};
}

#endif
