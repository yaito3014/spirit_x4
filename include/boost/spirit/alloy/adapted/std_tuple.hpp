#ifndef BOOST_SPIRIT_ALLOY_ADAPTED_STD_TUPLE_HPP
#define BOOST_SPIRIT_ALLOY_ADAPTED_STD_TUPLE_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/spirit/alloy/detail/integer_seq_transform.hpp>

#include <tuple>
#include <utility>

#include <cstddef>

namespace boost::spirit::alloy
{
    template <typename T>
    struct adaptor;

    template <auto... Vs>
    struct non_type_list;

    namespace detail
    {
        template <std::size_t I>
        struct call_std_get
        {
            template <typename Tuple>
            static constexpr decltype(auto) operator()(Tuple&& t)
            {
                return std::get<I>(static_cast<Tuple&&>(t));
            }
        };

        template <std::size_t I>
        struct make_call_std_get
        {
            static constexpr auto value = call_std_get<I>{};
        };
    } // detail

    template <typename... Ts>
    struct adaptor<std::tuple<Ts...>>
    {
        using getters = detail::integer_seq_transform_t<std::make_index_sequence<sizeof...(Ts)>, detail::make_call_std_get>;
    };
} // boost::spirit::alloy

#endif
