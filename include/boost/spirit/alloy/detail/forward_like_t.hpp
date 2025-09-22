#ifndef BOOST_SPIRIT_ALLOY_DETAIL_FORWARD_LIKE_T_HPP
#define BOOST_SPIRIT_ALLOY_DETAIL_FORWARD_LIKE_T_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <utility>

namespace boost::spirit::alloy::detail {

template <class T, class U>
using forward_like_t = decltype(std::forward_like<T>(std::declval<U>()));

} // boost::spirit::alloy::detail

#endif
