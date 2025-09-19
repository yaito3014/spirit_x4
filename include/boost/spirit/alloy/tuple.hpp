/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_SPIRIT_ALLOY_TUPLE_HPP
#define BOOST_SPIRIT_ALLOY_TUPLE_HPP

#include <boost/spirit/alloy/detail/combine_ref.hpp>
#include <boost/spirit/alloy/detail/forward_like_t.hpp>
#include <boost/spirit/alloy/detail/integer_seq_transform.hpp>
#include <boost/spirit/alloy/detail/pack_indexing.hpp>
#include <boost/spirit/alloy/detail/tuple_impl.hpp>

#include <boost/spirit/alloy/value_initialize.hpp>

namespace boost::spirit::alloy
{
    template <typename... Ts>
    class tuple : public detail::tuple_impl<Ts...>
    {
    private:
        static_assert(!std::disjunction_v<std::is_rvalue_reference<Ts>...>, "alloy::tuple must not be instantiated with rvalue reference type");
        using base_type = detail::tuple_impl<Ts...>;

        template <typename... Us>
        static constexpr bool disambiguating_constraint = [](){
            if constexpr (sizeof...(Ts) == 1) {
              return !std::is_same_v<std::remove_cvref_t<detail::type_pack_indexing_t<0, Us...>>, tuple>;
            } else {
              return true;
            }
        }();

    public:
        tuple() = default;

        tuple(tuple const&) = default;

        tuple(tuple&&)
            requires std::conjunction_v<std::is_move_constructible<Ts>...>
        = default;

        constexpr explicit tuple(value_initialize_t vi) : base_type(vi) {}

        constexpr explicit(!std::conjunction_v<std::is_convertible<Ts const&, Ts>...>) tuple(Ts const&... ts)
            noexcept(std::conjunction_v<std::is_nothrow_copy_constructible<Ts>...>)
            requires requires {
                requires (sizeof...(Ts) > 0);
                requires std::conjunction_v<std::is_copy_constructible<Ts>...>;
            }
            : base_type(ts...) {}

        template <typename... Us>
            requires requires {
                requires (sizeof...(Ts) == sizeof...(Us));
                requires disambiguating_constraint<Us...>;
                requires std::conjunction_v<std::is_constructible<Ts, Us>...>;
            }
        constexpr explicit(!std::conjunction_v<std::is_convertible<Us, Ts>...>) tuple(Us&&... us) noexcept(std::conjunction_v<std::is_nothrow_constructible<Ts, Us>...>)
            : base_type(static_cast<Us&&>(us)...) {}

        template <std::size_t I, typename Self>
        constexpr detail::combine_ref_t<Self&&, detail::type_pack_indexing_t<I, Ts...>> get(this Self&& self) noexcept
        {
            static_assert(I < sizeof...(Ts));
            return ((detail::forward_like_t<Self, tuple>)self).base_type::template get<I>();
        }
    };

    template <std::size_t I, typename... Ts>
    constexpr detail::type_pack_indexing_t<I, Ts...>& get(tuple<Ts...>& t) noexcept
    {
        static_assert(I < sizeof...(Ts));
        return t.template get<I>();
    }
    
    template <std::size_t I, typename... Ts>
    constexpr detail::type_pack_indexing_t<I, Ts...> const& get(tuple<Ts...> const& t) noexcept
    {
        static_assert(I < sizeof...(Ts));
        return t.template get<I>();
    }
    
    template <std::size_t I, typename... Ts>
    constexpr detail::type_pack_indexing_t<I, Ts...>&& get(tuple<Ts...>&& t) noexcept
    {
        static_assert(I < sizeof...(Ts));
        return static_cast<tuple<Ts...>&&>(t).template get<I>();
    }
    
    template <std::size_t I, typename... Ts>
    constexpr detail::type_pack_indexing_t<I, Ts...> const&& get(tuple<Ts...> const&& t) noexcept
    {   
        static_assert(I < sizeof...(Ts));
        return static_cast<tuple<Ts...> const&&>(t).template get<I>();
    }

    namespace detail
    {
        template <std::size_t I>
        struct call_alloy_get
        {
            template <typename Tuple>
            static constexpr decltype(auto) operator()(Tuple&& t) noexcept
            {
                return alloy::get<I>(static_cast<Tuple&&>(t));
            }
        };

        template <std::size_t I>
        struct make_call_alloy_get
        {
            static constexpr auto value = call_alloy_get<I>{};
        };
    } // detail

    template <typename T>
    struct adaptor;

    template <typename... Ts>
    struct adaptor<tuple<Ts...>>
    {
        using getters = detail::integer_seq_transform_t<std::make_index_sequence<sizeof...(Ts)>, detail::make_call_alloy_get>;
    };
} // boost::spirit::alloy

#endif
