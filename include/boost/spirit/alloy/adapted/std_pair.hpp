#ifndef BOOST_SPIRIT_ALLOY_ADAPTED_STD_PAIR_HPP
#define BOOST_SPIRIT_ALLOY_ADAPTED_STD_PAIR_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <utility>

namespace boost::spirit::alloy {

namespace detail {

template<auto... Vs>
struct non_type_list;

} // detail

template<class T>
struct adaptor;

template<class T, class U>
struct adaptor<std::pair<T, U>>
{
    using getters_list = detail::non_type_list<&std::pair<T, U>::first, &std::pair<T, U>::second>;
};

} // boost::spirit::alloy

#endif
