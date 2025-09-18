#ifndef BOOST_SPIRIT_X4_ALLOY_ADAPTED_STD_PAIR_HPP
#define BOOST_SPIRIT_X4_ALLOY_ADAPTED_STD_PAIR_HPP

#include <boost/spirit/x4/alloy/non_type_list.hpp>

#include <utility>

namespace boost::spirit::x4::alloy
{
    template <typename T>
    struct adaptor;

    template <typename T, typename U>
    struct adaptor<std::pair<T, U>>
    {
        using getters = non_type_list<&std::pair<T, U>::first, &std::pair<T, U>::second>;
    };
} // boost::spirit::x4::alloy

#endif
