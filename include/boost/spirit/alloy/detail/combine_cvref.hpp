#ifndef BOOST_SPIRIT_ALLOY_DETAIL_COMBINE_CVREF_HPP
#define BOOST_SPIRIT_ALLOY_DETAIL_COMBINE_CVREF_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <type_traits>

namespace boost::spirit::alloy::detail {

template<class From, class To>
struct combine_cvref {
    static_assert(std::is_reference_v<From>);
};

template<class T, class To>
struct combine_cvref<T&, To>
{
    using type = To&;
};

template<class T, class To>
struct combine_cvref<T const&, To>
{
    using type = To const&;
};

template<class T, class To>
struct combine_cvref<T&&, To>
{
    using type = To&&;
};

template<class T, class To>
struct combine_cvref<T const&&, To>
{
    using type = To const&&;
};

template<class From, class To>
using combine_cvref_t = typename combine_cvref<From, To>::type;

} // boost::spirit::alloy::detail

#endif
