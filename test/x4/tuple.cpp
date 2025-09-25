/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include "test.hpp"

#include <boost/spirit/alloy/access.hpp>
#include <boost/spirit/alloy/adapted.hpp>
#include <boost/spirit/alloy/non_type_list.hpp>
#include <boost/spirit/alloy/tuple.hpp>
#include <boost/spirit/alloy/tuple_like.hpp>
#include <boost/spirit/alloy/tuple_like_view.hpp>
#include <boost/spirit/alloy/utility.hpp>

#include <tuple>
#include <type_traits>
#include <utility>

struct NonAdaptedStruct {};

struct AdaptedStruct {
    int x;
    double y;
};

template<>
struct boost::spirit::alloy::adaptor<AdaptedStruct>
{
    using getters = non_type_list<&AdaptedStruct::x, &AdaptedStruct::y>;
};

TEST_CASE("tuple")
{
    {
        STATIC_CHECK(!boost::spirit::alloy::TupleLike<NonAdaptedStruct>);
    }

    {
        STATIC_CHECK(boost::spirit::alloy::TupleLike<AdaptedStruct>);
        
        STATIC_CHECK(boost::spirit::alloy::result_of::size<AdaptedStruct> == 2);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, AdaptedStruct&>, int&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, AdaptedStruct const&>, int const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, AdaptedStruct&&>, int&&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, AdaptedStruct const&&>, int const&&>);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, AdaptedStruct&>, double&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, AdaptedStruct const&>, double const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, AdaptedStruct&&>, double&&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, AdaptedStruct const&&>, double const&&>);

        constexpr AdaptedStruct a{ 42, 3.14 };

        STATIC_CHECK(boost::spirit::alloy::size(a) == 2);

        STATIC_CHECK(boost::spirit::alloy::get<0>(a) == 42);
        STATIC_CHECK(boost::spirit::alloy::get<1>(a) == 3.14);
    }

    {
        using Pair = std::pair<int, double>;

        STATIC_CHECK(boost::spirit::alloy::TupleLike<Pair>);

        STATIC_CHECK(boost::spirit::alloy::result_of::size<Pair> == 2);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Pair&>, int&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Pair const&>, int const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Pair&&>, int&&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Pair const&&>, int const&&>);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Pair&>, double&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Pair const&>, double const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Pair&&>, double&&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Pair const&&>, double const&&>);

        constexpr Pair p(42, 3.14);

        STATIC_CHECK(boost::spirit::alloy::size(p) == 2);

        STATIC_CHECK(boost::spirit::alloy::get<0>(p) == 42);
        STATIC_CHECK(boost::spirit::alloy::get<1>(p) == 3.14);
    }

    {
        using Tuple = std::tuple<int, double, char>;

        STATIC_CHECK(boost::spirit::alloy::TupleLike<Tuple>);

        STATIC_CHECK(boost::spirit::alloy::result_of::size<Tuple> == 3);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&>, int&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&>, int const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&&>, int&&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&&>, int const&&>);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&>, double&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&>, double const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&&>, double&&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&&>, double const&&>);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&>, char&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&>, char const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&&>, char&&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&&>, char const&&>);

        constexpr Tuple p(42, 3.14, 'A');

        STATIC_CHECK(boost::spirit::alloy::size(p) == 3);

        STATIC_CHECK(boost::spirit::alloy::get<0>(p) == 42);
        STATIC_CHECK(boost::spirit::alloy::get<1>(p) == 3.14);
        STATIC_CHECK(boost::spirit::alloy::get<2>(p) == 'A');
    }

    {
        STATIC_CHECK(std::is_trivially_default_constructible_v<boost::spirit::alloy::tuple<>>);

        using Tuple = boost::spirit::alloy::tuple<int, double, char>;

        STATIC_CHECK(boost::spirit::alloy::TupleLike<Tuple>);

        STATIC_CHECK(boost::spirit::alloy::result_of::size<Tuple> == 3);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&>, int&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&>, int const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&&>, int&&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&&>, int const&&>);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&>, double&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&>, double const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&&>, double&&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&&>, double const&&>);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&>, char&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&>, char const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&&>, char&&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&&>, char const&&>);

        constexpr Tuple t(42, 3.14, 'A');

        STATIC_CHECK(boost::spirit::alloy::get<0>(t) == 42);
        STATIC_CHECK(boost::spirit::alloy::get<1>(t) == 3.14);
        STATIC_CHECK(boost::spirit::alloy::get<2>(t) == 'A');
    }

    {
        using Tuple = boost::spirit::alloy::tuple<int&, double&, char&>;

        STATIC_CHECK(boost::spirit::alloy::TupleLike<Tuple>);
        STATIC_CHECK(boost::spirit::alloy::TupleLikeView<Tuple>);

        STATIC_CHECK(boost::spirit::alloy::result_of::size<Tuple> == 3);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&>, int&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&>, int&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&&>, int&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&&>, int&>);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&>, double&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&>, double&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&&>, double&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&&>, double&>);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&>, char&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&>, char&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&&>, char&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&&>, char&>);

        int x = 42;
        double y = 3.14;
        char z = 'A';
        Tuple const t(x, y, z);

        CHECK(boost::spirit::alloy::get<0>(t) == 42);
        CHECK(boost::spirit::alloy::get<1>(t) == 3.14);
        CHECK(boost::spirit::alloy::get<2>(t) == 'A');
    }

    {
        using Tuple = boost::spirit::alloy::tuple<int const&, double const&, char const&>;

        STATIC_CHECK(boost::spirit::alloy::TupleLike<Tuple>);
        STATIC_CHECK(boost::spirit::alloy::TupleLikeView<Tuple>);

        STATIC_CHECK(boost::spirit::alloy::result_of::size<Tuple> == 3);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&>, int const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&>, int const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple&&>, int const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<0, Tuple const&&>, int const&>);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&>, double const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&>, double const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple&&>, double const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<1, Tuple const&&>, double const&>);

        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&>, char const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&>, char const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple&&>, char const&>);
        STATIC_CHECK(std::is_same_v<boost::spirit::alloy::result_of::get<2, Tuple const&&>, char const&>);

        int const x = 42;
        double const y = 3.14;
        char const z = 'A';
        Tuple const t(x, y, z);

        CHECK(boost::spirit::alloy::get<0>(t) == 42);
        CHECK(boost::spirit::alloy::get<1>(t) == 3.14);
        CHECK(boost::spirit::alloy::get<2>(t) == 'A');
    }

    {
        STATIC_CHECK(std::is_constructible_v<boost::spirit::alloy::tuple<int, float>, boost::spirit::alloy::tuple<float, int>&>);
        STATIC_CHECK(std::is_constructible_v<boost::spirit::alloy::tuple<int, float>, boost::spirit::alloy::tuple<float, int> const&>);
        STATIC_CHECK(std::is_constructible_v<boost::spirit::alloy::tuple<int, float>, boost::spirit::alloy::tuple<float, int>&&>);
        STATIC_CHECK(std::is_constructible_v<boost::spirit::alloy::tuple<int, float>, boost::spirit::alloy::tuple<float, int> const&&>);

        STATIC_CHECK(std::is_convertible_v<boost::spirit::alloy::tuple<float, int>&, boost::spirit::alloy::tuple<int, float>>);
        STATIC_CHECK(std::is_convertible_v<boost::spirit::alloy::tuple<float, int> const&, boost::spirit::alloy::tuple<int, float>>);
        STATIC_CHECK(std::is_convertible_v<boost::spirit::alloy::tuple<float, int>&&, boost::spirit::alloy::tuple<int, float>>);
        STATIC_CHECK(std::is_convertible_v<boost::spirit::alloy::tuple<float, int> const&&, boost::spirit::alloy::tuple<int, float>>);

        struct NeedExplicitConversion {
            explicit NeedExplicitConversion(int) {}
        };

        STATIC_CHECK(std::is_constructible_v<boost::spirit::alloy::tuple<NeedExplicitConversion>, boost::spirit::alloy::tuple<int>&>);
        STATIC_CHECK(std::is_constructible_v<boost::spirit::alloy::tuple<NeedExplicitConversion>, boost::spirit::alloy::tuple<int> const&>);
        STATIC_CHECK(std::is_constructible_v<boost::spirit::alloy::tuple<NeedExplicitConversion>, boost::spirit::alloy::tuple<int>&&>);
        STATIC_CHECK(std::is_constructible_v<boost::spirit::alloy::tuple<NeedExplicitConversion>, boost::spirit::alloy::tuple<int>const &&>);
        
        STATIC_CHECK(!std::is_convertible_v<boost::spirit::alloy::tuple<int>&, boost::spirit::alloy::tuple<NeedExplicitConversion>>);
        STATIC_CHECK(!std::is_convertible_v<boost::spirit::alloy::tuple<int> const&, boost::spirit::alloy::tuple<NeedExplicitConversion>>);
        STATIC_CHECK(!std::is_convertible_v<boost::spirit::alloy::tuple<int>&&, boost::spirit::alloy::tuple<NeedExplicitConversion>>);
        STATIC_CHECK(!std::is_convertible_v<boost::spirit::alloy::tuple<int>const &&, boost::spirit::alloy::tuple<NeedExplicitConversion>>);

        boost::spirit::alloy::tuple<int, float> a(42, 3.14f);
        boost::spirit::alloy::tuple<float, int> b(a);
        CHECK(boost::spirit::alloy::get<0>(b) == float{42});
        CHECK(boost::spirit::alloy::get<1>(b) == 3);
    }

    {
        STATIC_CHECK(std::is_constructible_v<boost::spirit::alloy::tuple<int, double>, AdaptedStruct>);

        constexpr AdaptedStruct a{42, 3.14};
        constexpr boost::spirit::alloy::tuple<int, double> t(a);
        STATIC_CHECK(boost::spirit::alloy::get<0>(t) == 42);
        STATIC_CHECK(boost::spirit::alloy::get<1>(t) == 3.14);
    }

    {
        constexpr boost::spirit::alloy::tuple<int> a(42);
        constexpr boost::spirit::alloy::tuple<double> b(3.14);
        constexpr auto c = boost::spirit::alloy::tuple_cat(a, b);
        STATIC_CHECK(boost::spirit::alloy::get<0>(c) == 42);
        STATIC_CHECK(boost::spirit::alloy::get<1>(c) == 3.14);
    }
    {
        constexpr boost::spirit::alloy::tuple<int, float, double> a(42, 3.14f, 2.18);
        constexpr auto b = boost::spirit::alloy::tuple_split<1, 2>(a);
        STATIC_CHECK(boost::spirit::alloy::get<0>(boost::spirit::alloy::get<0>(b)) == 42);
        STATIC_CHECK(boost::spirit::alloy::get<0>(boost::spirit::alloy::get<1>(b)) == 3.14f);
        STATIC_CHECK(boost::spirit::alloy::get<1>(boost::spirit::alloy::get<1>(b)) == 2.18);
    }
}
