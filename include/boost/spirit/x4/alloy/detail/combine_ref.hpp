/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_SPIRIT_X4_ALLOY_DETAIL_COMBINE_REF_HPP
#define BOOST_SPIRIT_X4_ALLOY_DETAIL_COMBINE_REF_HPP

#include <type_traits>

namespace boost::spirit::x4::alloy::detail
{
    template <typename From, typename To>
    struct combine_ref {
        static_assert(std::is_reference_v<From>);
    };

    template <typename T, typename To>
    struct combine_ref<T&, To>
    {
        using type = To&;
    };
    
    template <typename T, typename To>
    struct combine_ref<T const&, To>
    {
        using type = To const&;
    };
    
    template <typename T, typename To>
    struct combine_ref<T&&, To>
    {
        using type = To&&;
    };
    
    template <typename T, typename To>
    struct combine_ref<T const&&, To>
    {
        using type = To const&&;
    };

    template <typename From, typename To>
    using combine_ref_t = typename combine_ref<From, To>::type;
} // boost::spirit::x4::alloy::detail

#endif
