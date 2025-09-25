#ifndef BOOST_SPIRIT_ALLOY_DETAIL_TUPLE_IMPL_HPP
#define BOOST_SPIRIT_ALLOY_DETAIL_TUPLE_IMPL_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/spirit/config.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repeat.hpp>
#include <boost/preprocessor/repeat_from_to.hpp>

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

#define BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_1 T
#define BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_2 U
#define BOOST_SPIRIT_ALLOY_DETAIL_FUNCTION_PARAM_1 t
#define BOOST_SPIRIT_ALLOY_DETAIL_FUNCTION_PARAM_2 u
#define BOOST_SPIRIT_ALLOY_DETAIL_MEMBER_PREFIX _

#define BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAMS(z, n, name) BOOST_PP_COMMA_IF(n) class BOOST_PP_CAT(name, n)
#define BOOST_SPIRIT_ALLOY_DETAIL_ARGS(z, n, name) BOOST_PP_COMMA_IF(n) BOOST_PP_CAT(name, n)

#define BOOST_SPIRIT_ALLOY_DETAIL_MEM_DEFS(z, n, ) \
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS BOOST_PP_CAT(BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_1, n) BOOST_PP_CAT(BOOST_SPIRIT_ALLOY_DETAIL_MEMBER_PREFIX, n);

#define BOOST_SPIRIT_ALLOY_DETAIL_FWD_PARAMS(z, n, )                           \
    BOOST_PP_COMMA_IF(n)                                                       \
        BOOST_PP_CAT(BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_2, n) &&         \
        BOOST_PP_CAT(BOOST_SPIRIT_ALLOY_DETAIL_FUNCTION_PARAM_2, n)

#define BOOST_SPIRIT_ALLOY_DETAIL_FWD_INITS(z, n, )                            \
    BOOST_PP_COMMA_IF(n)                                                       \
    BOOST_PP_CAT(BOOST_SPIRIT_ALLOY_DETAIL_MEMBER_PREFIX, n)(                  \
        static_cast<BOOST_PP_CAT(BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_2,   \
                                 n)>(                                          \
            BOOST_PP_CAT(BOOST_SPIRIT_ALLOY_DETAIL_FUNCTION_PARAM_2, n)))

#define BOOST_SPIRIT_ALLOY_DETAIL_LVALUE_INITS(z, n, other)                    \
    BOOST_PP_COMMA_IF(n)                                                       \
    BOOST_PP_CAT(BOOST_SPIRIT_ALLOY_DETAIL_MEMBER_PREFIX, n)(                  \
        other.BOOST_PP_CAT(BOOST_SPIRIT_ALLOY_DETAIL_MEMBER_PREFIX, n))

#define BOOST_SPIRIT_ALLOY_DETAIL_XVALUE_INITS(z, n, other)                    \
    BOOST_PP_COMMA_IF(n)                                                       \
    BOOST_PP_CAT(BOOST_SPIRIT_ALLOY_DETAIL_MEMBER_PREFIX,                      \
                 n)(static_cast<decltype(other)>(other).BOOST_PP_CAT(          \
        BOOST_SPIRIT_ALLOY_DETAIL_MEMBER_PREFIX, n))

#define BOOST_SPIRIT_ALLOY_DETAIL_NOTHROW_DEFAULT_CONSTRUCTIBLE(z, n, ) \
    BOOST_PP_COMMA_IF(n) std::is_nothrow_default_constructible<BOOST_PP_CAT(BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_1, n)>

#define BOOST_SPIRIT_ALLOY_DETAIL_NOTHROW_CONSTRUCTIBLE(z, n, suffix) \
  BOOST_PP_COMMA_IF(n)                                                \
  std::is_nothrow_default_constructible<                              \
      BOOST_PP_CAT(BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_1, n), BOOST_PP_CAT(BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_2, n) suffix>

#define BOOST_SPIRIT_ALLOY_DETAIL_VALUE_INITS(z, n, ) \
    BOOST_PP_COMMA_IF(n) BOOST_PP_CAT(BOOST_SPIRIT_ALLOY_DETAIL_MEMBER_PREFIX, n) {}

template<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAMS, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_1)>
class tuple_impl<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_ARGS, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_1)>
{
    template<class... BOOST_PP_CAT(BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_2, s)>
    friend class tuple_impl;

public:
    BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_MEMS, )

    explicit tuple_impl() = default;

    explicit tuple_impl(tuple_impl const&) = default;

    explicit tuple_impl(tuple_impl&&) = default;

    constexpr explicit tuple_impl(value_initialize_t)
        noexcept(std::conjunction_v<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_NOTHROW_DEFAULT_CONSTRUCTIBLE,)>)
        : BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_VALUE_INITS, )
    {}

    template<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAMS, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_2)>
    constexpr explicit tuple_impl(BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_FWD_PARAMS,))
        noexcept(BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_NOTHROW_CONSTRUCTIBLE,))
        : BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_FWD_INITS,)
    {}
    
    template<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAMS, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_2)>
    constexpr explicit tuple_impl(tuple_impl<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_ARGS, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_2)>& other)
        noexcept(std::conjunction_v<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_NOTHROW_CONSTRUCTIBLE, &)>)
        : BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_LVALUE_INITS, other)
    {}
    
    template<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAMS, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_2)>
    constexpr explicit tuple_impl(tuple_impl<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_ARGS, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_2)> const& other)
        noexcept(std::conjunction_v<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_NOTHROW_CONSTRUCTIBLE, const&)>)
        : BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_LVALUE_INITS, other)
    {}
    
    template<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAMS, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_2)>
    constexpr explicit tuple_impl(tuple_impl<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_ARGS, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_2)>&& other)
        noexcept(std::conjunction_v<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_NOTHROW_CONSTRUCTIBLE, &&)>)
        : BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_XVALUE_INITS, other)
    {}
    
    template<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAMS, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_2)>
    constexpr explicit tuple_impl(tuple_impl<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_ARGS, BOOST_SPIRIT_ALLOY_DETAIL_TEMPLATE_PARAM_2)> const&& other)
        noexcept(std::conjunction_v<BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_NOTHROW_CONSTRUCTIBLE, const&&)>)
        : BOOST_PP_REPEAT(n, BOOST_SPIRIT_ALLOY_DETAIL_XVALUE_INITS, other)
    {}
};


template<class T0, class... Ts>
class tuple_impl<T0, Ts...>
{
    template<class... Us>
    friend class tuple_impl;
public:
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS T0 _0;
    BOOST_SPIRIT_NO_UNIQUE_ADDRESS tuple_impl<Ts...> rest;

    explicit tuple_impl() = default;

    explicit tuple_impl(tuple_impl const&) = default;

    explicit tuple_impl(tuple_impl&&) = default;

    constexpr explicit tuple_impl(value_initialize_t vi)
        noexcept(std::conjunction_v<std::is_nothrow_default_constructible<T0>, std::is_nothrow_default_constructible<Ts>...>)
        : _0{}, rest(vi)
    {}

    template<class U0, class... Us>
        requires (sizeof...(Ts) == sizeof...(Us))
    constexpr explicit tuple_impl(U0&& u0, Us&&... us)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0>, std::is_nothrow_constructible<Ts, Us>...>)
        : _0(static_cast<U0&&>(u0)), rest(static_cast<Us&&>(us)...)
    {}

    template<class U0, class... Us>
    constexpr explicit tuple_impl(tuple_impl<U0, Us...>& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&>, std::is_nothrow_constructible<Ts, Us&>...>)
        : _0(other._0), rest(other.rest) {}
    
    template<class U0, class... Us>
    constexpr explicit tuple_impl(tuple_impl<U0, Us...> const& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&>, std::is_nothrow_constructible<Ts, Us const&>...>)
        : _0(other._0), rest(other.rest) {}
    
    template<class U0, class... Us>
    constexpr explicit tuple_impl(tuple_impl<U0, Us...>&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0&&>, std::is_nothrow_constructible<Ts, Us&&>...>)
        : _0(static_cast<tuple_impl<U0, Us...>&&>(other)._0), rest(static_cast<tuple_impl<U0, Us...>&&>(other).rest) {}
    
    template<class U0, class... Us>
    constexpr explicit tuple_impl(tuple_impl<U0, Us...> const&& other)
        noexcept(std::conjunction_v<std::is_nothrow_constructible<T0, U0 const&&>, std::is_nothrow_constructible<Ts, Us const&&>...>)
        : _0(static_cast<tuple_impl<U0, Us...>&&>(other)._0), rest(static_cast<tuple_impl<U0, Us...>&&>(other).rest) {}

    template<std::size_t I, class Self>
    constexpr combine_cvref_t<Self&&, type_pack_indexing_t<I, T0, Ts...>> get(this Self&& self) noexcept
    {
        if constexpr (I == 0)
            return ((forward_like_t<Self, tuple_impl>)self)._0;
        else
            return ((forward_like_t<Self, tuple_impl>)self).rest.template get<I - 1>();
    }
};

} // boost::spirit::alloy::detail

#endif
