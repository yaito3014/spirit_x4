#ifndef BOOST_SPIRIT_X4_ALLOY_PACK_INDEXING_HPP
#define BOOST_SPIRIT_X4_ALLOY_PACK_INDEXING_HPP

#include <version>

#include <cstddef>

namespace boost::spirit::x4::alloy::detail
{
    template <std::size_t I, typename... Ts>
    struct type_pack_indexing;

    template <std::size_t I, typename... Ts>
    using type_pack_indexing_t = typename type_pack_indexing<I, Ts...>::type;

#if __cpp_pack_indexing >= 202311L
    template <std::size_t I, typename... Ts>
    struct type_pack_indexing
    {
        using type = Ts...[I];
    };
#else
    template <typename T, typename... Ts>
    struct type_pack_indexing<0, T, Ts...>
    {
        using type = T;
    };

    template <std::size_t I, typename T, typename... Ts>
    struct type_pack_indexing<I, T, Ts...> : type_pack_indexing<I - 1, Ts...> {};
#endif

    template <std::size_t I, auto... Vs>
    struct non_type_pack_indexing;

    template <std::size_t I, auto... Vs>
    inline constexpr auto non_type_pack_indexing_v = non_type_pack_indexing<I, Vs...>::value;
    
#if __cpp_pack_indexing >= 202311L
    template <std::size_t I, auto... Vs>
    struct non_type_pack_indexing
    {
        static constexpr auto value = Vs...[I];
    };
#else
    template <auto V, auto... Vs>
    struct non_type_pack_indexing<0, V, Vs...>
    {
        static constexpr auto value = V;
    };

    template <std::size_t I, auto V, auto... Vs>
    struct non_type_pack_indexing<I, V, Vs...> : non_type_pack_indexing<I - 1, Vs...> {};
#endif
} // boost::spirit::x4::alloy::detail

#endif
