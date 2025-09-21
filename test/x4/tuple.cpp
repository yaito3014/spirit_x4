/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include "test.hpp"

#include <boost/spirit/alloy/access.hpp>
#include <boost/spirit/alloy/adapted.hpp>
#include <boost/spirit/alloy/tuple.hpp>
#include <boost/spirit/alloy/utility.hpp>

#include <tuple>
#include <type_traits>
#include <utility>

int main()
{
    {
        struct NonAdaptedStruct {};

        static_assert(!boost::spirit::alloy::TupleLike<NonAdaptedStruct>);
    }

    {
        using Pair = std::pair<int, double>;

        static_assert(boost::spirit::alloy::TupleLike<Pair>);

        static_assert(boost::spirit::alloy::result_of::size<Pair> == 2);

        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Pair&>, int&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Pair const&>, int const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Pair&&>, int&&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Pair const&&>, int const&&>);

        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Pair&>, double&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Pair const&>, double const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Pair&&>, double&&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Pair const&&>, double const&&>);

        constexpr Pair p(42, 3.14);

        static_assert(boost::spirit::alloy::size(p) == 2);

        static_assert(boost::spirit::alloy::get<0>(p) == 42);
        static_assert(boost::spirit::alloy::get<1>(p) == 3.14);
    }
    
    {
        using Tuple = std::tuple<int, double, char>;

        static_assert(boost::spirit::alloy::TupleLike<Tuple>);

        static_assert(boost::spirit::alloy::result_of::size<Tuple> == 3);

        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&>, int&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&>, int const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&&>, int&&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&&>, int const&&>);

        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&>, double&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&>, double const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&&>, double&&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&&>, double const&&>);

        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&>, char&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&>, char const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&&>, char&&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&&>, char const&&>);

        constexpr Tuple p(42, 3.14, 'A');

        static_assert(boost::spirit::alloy::size(p) == 3);

        static_assert(boost::spirit::alloy::get<0>(p) == 42);
        static_assert(boost::spirit::alloy::get<1>(p) == 3.14);
        static_assert(boost::spirit::alloy::get<2>(p) == 'A');
    }

    {
        static_assert(std::is_trivially_default_constructible_v<boost::spirit::alloy::tuple<>>);

        using Tuple = boost::spirit::alloy::tuple<int, double, char>;

        static_assert(boost::spirit::alloy::TupleLike<Tuple>);

        static_assert(boost::spirit::alloy::result_of::size<Tuple> == 3);

        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&>, int&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&>, int const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&&>, int&&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&&>, int const&&>);

        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&>, double&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&>, double const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&&>, double&&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&&>, double const&&>);

        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&>, char&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&>, char const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&&>, char&&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&&>, char const&&>);

        constexpr Tuple t(42, 3.14, 'A');

        static_assert(boost::spirit::alloy::get<0>(t) == 42);
        static_assert(boost::spirit::alloy::get<1>(t) == 3.14);
        static_assert(boost::spirit::alloy::get<2>(t) == 'A');
    }

    {
        using Tuple = boost::spirit::alloy::tuple<int&, double&, char&>;

        static_assert(boost::spirit::alloy::TupleLike<Tuple>);

        static_assert(boost::spirit::alloy::result_of::size<Tuple> == 3);

        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&>, int&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&>, int&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&&>, int&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&&>, int&>);

        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&>, double&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&>, double&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&&>, double&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&&>, double&>);

        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&>, char&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&>, char&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&&>, char&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&&>, char&>);

        int x = 42;
        double y = 3.14;
        char z = 'A';
        Tuple const t(x, y, z);

        BOOST_TEST(boost::spirit::alloy::get<0>(t) == 42);
        BOOST_TEST(boost::spirit::alloy::get<1>(t) == 3.14);
        BOOST_TEST(boost::spirit::alloy::get<2>(t) == 'A');
    }

    {
        using Tuple = boost::spirit::alloy::tuple<int const&, double const&, char const&>;

        static_assert(boost::spirit::alloy::TupleLike<Tuple>);

        static_assert(boost::spirit::alloy::result_of::size<Tuple> == 3);

        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&>, int const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&>, int const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&&>, int const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&&>, int const&>);

        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&>, double const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&>, double const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&&>, double const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&&>, double const&>);

        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&>, char const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&>, char const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&&>, char const&>);
        static_assert(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&&>, char const&>);

        int const x = 42;
        double const y = 3.14;
        char const z = 'A';
        Tuple const t(x, y, z);

        BOOST_TEST(boost::spirit::alloy::get<0>(t) == 42);
        BOOST_TEST(boost::spirit::alloy::get<1>(t) == 3.14);
        BOOST_TEST(boost::spirit::alloy::get<2>(t) == 'A');
    }

    {
        constexpr boost::spirit::alloy::tuple<int> a(42);
        constexpr boost::spirit::alloy::tuple<double> b(3.14);
        constexpr auto c = boost::spirit::alloy::tuple_cat(a, b);
        static_assert(boost::spirit::alloy::get<0>(c) == 42);
        static_assert(boost::spirit::alloy::get<1>(c) == 3.14);
    }

    return boost::report_errors();
}
