/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if BOOST_SPIRIT_CI_IS_B2
# include "catch_amalgamated.hpp"
#else
# include <catch2/catch_test_macros.hpp>
#endif

#include <boost/spirit/alloy/access.hpp>
#include <boost/spirit/alloy/adapted.hpp>
#include <boost/spirit/alloy/io.hpp>
#include <boost/spirit/alloy/detail/non_type_list.hpp>
#include <boost/spirit/alloy/tuple.hpp>
#include <boost/spirit/alloy/tuple_like.hpp>
#include <boost/spirit/alloy/tuple_like_view.hpp>
#include <boost/spirit/alloy/utility.hpp>

#include <sstream>
#include <tuple>
#include <type_traits>
#include <utility>

struct NonAdaptedStruct {};

struct AdaptedStruct
{
    int x;
    double y;
};

template<>
struct boost::spirit::alloy::adaptor<AdaptedStruct>
{
    using getters = detail::non_type_list<&AdaptedStruct::x, &AdaptedStruct::y>;
};

void swap(); // poison-pill

TEST_CASE("tuple")
{
    namespace alloy = boost::spirit::alloy;

    {
        STATIC_CHECK(!alloy::TupleLike<NonAdaptedStruct>);
    }

    {
        STATIC_CHECK(alloy::TupleLike<AdaptedStruct>);

        STATIC_CHECK(alloy::result_of::size<AdaptedStruct> == 2);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, AdaptedStruct&>, int&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, AdaptedStruct const&>, int const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, AdaptedStruct&&>, int&&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, AdaptedStruct const&&>, int const&&>);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, AdaptedStruct&>, double&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, AdaptedStruct const&>, double const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, AdaptedStruct&&>, double&&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, AdaptedStruct const&&>, double const&&>);

        constexpr AdaptedStruct a{42, 3.14};

        STATIC_CHECK(alloy::size(a) == 2);

        STATIC_CHECK(alloy::get<0>(a) == 42);
        STATIC_CHECK(alloy::get<1>(a) == 3.14);
    }

    {
        using Pair = std::pair<int, double>;

        STATIC_CHECK(alloy::TupleLike<Pair>);

        STATIC_CHECK(alloy::result_of::size<Pair> == 2);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Pair&>, int&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Pair const&>, int const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Pair&&>, int&&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Pair const&&>, int const&&>);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Pair&>, double&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Pair const&>, double const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Pair&&>, double&&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Pair const&&>, double const&&>);

        constexpr Pair p(42, 3.14);

        STATIC_CHECK(alloy::size(p) == 2);

        STATIC_CHECK(alloy::get<0>(p) == 42);
        STATIC_CHECK(alloy::get<1>(p) == 3.14);
    }

    {
        using Tuple = std::tuple<int, double, char>;

        STATIC_CHECK(alloy::TupleLike<Tuple>);

        STATIC_CHECK(alloy::result_of::size<Tuple> == 3);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple&>, int&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple const&>, int const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple&&>, int&&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple const&&>, int const&&>);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple&>, double&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple const&>, double const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple&&>, double&&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple const&&>, double const&&>);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple&>, char&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple const&>, char const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple&&>, char&&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple const&&>, char const&&>);

        constexpr Tuple p(42, 3.14, 'A');

        STATIC_CHECK(alloy::size(p) == 3);

        STATIC_CHECK(alloy::get<0>(p) == 42);
        STATIC_CHECK(alloy::get<1>(p) == 3.14);
        STATIC_CHECK(alloy::get<2>(p) == 'A');
    }

    {
        STATIC_CHECK(std::is_trivially_default_constructible_v<alloy::tuple<>>);

        using Tuple = alloy::tuple<int, double, char>;

        STATIC_CHECK(alloy::TupleLike<Tuple>);

        STATIC_CHECK(alloy::result_of::size<Tuple> == 3);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple&>, int&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple const&>, int const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple&&>, int&&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple const&&>, int const&&>);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple&>, double&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple const&>, double const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple&&>, double&&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple const&&>, double const&&>);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple&>, char&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple const&>, char const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple&&>, char&&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple const&&>, char const&&>);

        constexpr Tuple t(42, 3.14, 'A');

        STATIC_CHECK(alloy::get<0>(t) == 42);
        STATIC_CHECK(alloy::get<1>(t) == 3.14);
        STATIC_CHECK(alloy::get<2>(t) == 'A');
    }

    {
        using Tuple = alloy::tuple<int&, double&, char&>;

        STATIC_CHECK(alloy::TupleLike<Tuple>);
        STATIC_CHECK(alloy::TupleLikeView<Tuple>);

        STATIC_CHECK(alloy::result_of::size<Tuple> == 3);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple&>, int&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple const&>, int&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple&&>, int&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple const&&>, int&>);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple&>, double&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple const&>, double&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple&&>, double&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple const&&>, double&>);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple&>, char&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple const&>, char&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple&&>, char&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple const&&>, char&>);

        int x = 42;
        double y = 3.14;
        char z = 'A';
        Tuple const t(x, y, z);

        CHECK(alloy::get<0>(t) == 42);
        CHECK(alloy::get<1>(t) == 3.14);
        CHECK(alloy::get<2>(t) == 'A');
    }

    {
        using Tuple = alloy::tuple<int const&, double const&, char const&>;

        STATIC_CHECK(alloy::TupleLike<Tuple>);
        STATIC_CHECK(alloy::TupleLikeView<Tuple>);

        STATIC_CHECK(alloy::result_of::size<Tuple> == 3);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple&>, int const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple const&>, int const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple&&>, int const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<0, Tuple const&&>, int const&>);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple&>, double const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple const&>, double const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple&&>, double const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<1, Tuple const&&>, double const&>);

        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple&>, char const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple const&>, char const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple&&>, char const&>);
        STATIC_CHECK(std::is_same_v<alloy::result_of::get<2, Tuple const&&>, char const&>);

        int const x = 42;
        double const y = 3.14;
        char const z = 'A';
        Tuple const t(x, y, z);

        CHECK(alloy::get<0>(t) == 42);
        CHECK(alloy::get<1>(t) == 3.14);
        CHECK(alloy::get<2>(t) == 'A');
    }

    {
        STATIC_CHECK(std::is_constructible_v<alloy::tuple<int, float>, alloy::tuple<float, int>&>);
        STATIC_CHECK(std::is_constructible_v<alloy::tuple<int, float>, alloy::tuple<float, int> const&>);
        STATIC_CHECK(std::is_constructible_v<alloy::tuple<int, float>, alloy::tuple<float, int>&&>);
        STATIC_CHECK(std::is_constructible_v<alloy::tuple<int, float>, alloy::tuple<float, int> const&&>);

        STATIC_CHECK(std::is_convertible_v<alloy::tuple<float, int>&, alloy::tuple<int, float>>);
        STATIC_CHECK(std::is_convertible_v<alloy::tuple<float, int> const&, alloy::tuple<int, float>>);
        STATIC_CHECK(std::is_convertible_v<alloy::tuple<float, int>&&, alloy::tuple<int, float>>);
        STATIC_CHECK(std::is_convertible_v<alloy::tuple<float, int> const&&, alloy::tuple<int, float>>);

        struct NeedExplicitConversion
        {
            explicit NeedExplicitConversion(int) {}
        };

        STATIC_CHECK(std::is_constructible_v<alloy::tuple<NeedExplicitConversion>, alloy::tuple<int>&>);
        STATIC_CHECK(std::is_constructible_v<alloy::tuple<NeedExplicitConversion>, alloy::tuple<int> const&>);
        STATIC_CHECK(std::is_constructible_v<alloy::tuple<NeedExplicitConversion>, alloy::tuple<int>&&>);
        STATIC_CHECK(std::is_constructible_v<alloy::tuple<NeedExplicitConversion>, alloy::tuple<int> const&&>);

        STATIC_CHECK(!std::is_convertible_v<alloy::tuple<int>&, alloy::tuple<NeedExplicitConversion>>);
        STATIC_CHECK(!std::is_convertible_v<alloy::tuple<int> const&, alloy::tuple<NeedExplicitConversion>>);
        STATIC_CHECK(!std::is_convertible_v<alloy::tuple<int>&&, alloy::tuple<NeedExplicitConversion>>);
        STATIC_CHECK(!std::is_convertible_v<alloy::tuple<int> const&&, alloy::tuple<NeedExplicitConversion>>);

        alloy::tuple<int, float> a(42, 3.14f);
        alloy::tuple<float, int> b(a);
        CHECK(alloy::get<0>(b) == float{42});
        CHECK(alloy::get<1>(b) == 3);
    }

    {
        STATIC_CHECK(std::is_constructible_v<alloy::tuple<int, double>, AdaptedStruct>);

        constexpr AdaptedStruct a{42, 3.14};
        constexpr alloy::tuple<int, double> t(a);
        STATIC_CHECK(alloy::get<0>(t) == 42);
        STATIC_CHECK(alloy::get<1>(t) == 3.14);
    }

    {
        constexpr alloy::tuple<int> a(42);
        constexpr alloy::tuple<double> b(3.14);
        constexpr auto c = alloy::tuple_cat(a, b);
        STATIC_CHECK(alloy::get<0>(c) == 42);
        STATIC_CHECK(alloy::get<1>(c) == 3.14);
    }

    {
        constexpr alloy::tuple<int, float, double> a(42, 3.14f, 2.18);
        constexpr auto b = alloy::tuple_split<1, 2>(a);
        STATIC_CHECK(alloy::get<0>(alloy::get<0>(b)) == 42);
        STATIC_CHECK(alloy::get<0>(alloy::get<1>(b)) == 3.14f);
        STATIC_CHECK(alloy::get<1>(alloy::get<1>(b)) == 2.18);
    }

    {
        alloy::tuple<int, double> const from(33, 3.14);
        alloy::tuple<int, double> to(4, 2.18);
        alloy::tuple_assign(from, to);
        CHECK(alloy::get<0>(to) == 33);
        CHECK(alloy::get<1>(to) == 3.14);
    }
    
    {
        alloy::tuple<int, double> from(33, 3.14);
        alloy::tuple<int, double> to(4, 2.18);
        alloy::tuple_assign(std::move(from), to);
        CHECK(alloy::get<0>(to) == 33);
        CHECK(alloy::get<1>(to) == 3.14);
    }

    {
        alloy::tuple<int, double> tuple(42, 3.14);
        auto view = alloy::make_tuple_view(tuple);
        CHECK(alloy::get<0>(view) == 42);
        CHECK(alloy::get<1>(view) == 3.14);
    }

    {
        alloy::tuple<int, double> tuple(42, 3.14);
        alloy::tuple_for_each(tuple, [](auto& elem){ elem = 33 - 4; });
        CHECK(alloy::get<0>(tuple) == 29);
        CHECK(alloy::get<1>(tuple) == 29.);
    }

    {
        {
            std::stringstream ss;
            ss << alloy::tuple<>();
            CHECK(ss.str() == "()");
        }
        {
            std::stringstream ss;
            ss << alloy::tuple<int>(42);
            CHECK(ss.str() == "(42)");
        }
        {
            std::stringstream ss;
            ss << alloy::tuple<int, double>(42, 3.14);
            CHECK(ss.str() == "(42, 3.14)");
        }
    }

    {
        STATIC_CHECK(std::is_copy_assignable_v<alloy::tuple<int>>);
        STATIC_CHECK(std::is_nothrow_move_assignable_v<alloy::tuple<int>>);

        alloy::tuple<int> a(33), b(4);
        a = b;
        a = std::move(b);
        CHECK(alloy::get<0>(a) == 4);
    }

    {
        STATIC_CHECK(std::is_copy_assignable_v<alloy::tuple<int&>>);
        STATIC_CHECK(std::is_nothrow_move_assignable_v<alloy::tuple<int&>>);

        int x = 33, y = 4;
        alloy::tuple<int&> a(x);
        alloy::tuple<int&> b(y);
        a = b;
        a = std::move(b);
        CHECK(alloy::get<0>(a) == 4);
    }

    {
        STATIC_CHECK(std::is_assignable_v<alloy::tuple<int>&, alloy::tuple<float> const&>);
        STATIC_CHECK(std::is_assignable_v<alloy::tuple<int>&, alloy::tuple<float>&&>);
        STATIC_CHECK(std::is_nothrow_assignable_v<alloy::tuple<int>&, alloy::tuple<float> const&>);
        STATIC_CHECK(std::is_nothrow_assignable_v<alloy::tuple<int>&, alloy::tuple<float>&&>);

        alloy::tuple<int> a(33);
        alloy::tuple<float> b(4.f);
        a = b;
        a = std::move(b);
        CHECK(alloy::get<0>(a) == 4);
    }

    {
        STATIC_CHECK(std::is_assignable_v<alloy::tuple<int, double>&, AdaptedStruct const&>);
        STATIC_CHECK(std::is_assignable_v<alloy::tuple<int, double>&, AdaptedStruct&&>);

        alloy::tuple<int, double> a(33, 3.14);
        AdaptedStruct b{4, 2.18};
        a = b;
        a = std::move(b);
        CHECK(alloy::get<0>(a) == 4);
        CHECK(alloy::get<1>(a) == 2.18);
    }

    {
        alloy::tuple<int> a(33), b(4);
        a.swap(b);
        swap(a, b);
        CHECK(alloy::get<0>(a) == 33);
        CHECK(alloy::get<0>(b) == 4);
    }

    {
        alloy::tuple<int, double> a(42, 3.14), b = a;
        CHECK(a == b);
    }

    {
        struct Empty {};
        struct OnlyChar { char c; };
        [[maybe_unused]] constexpr alloy::tuple<Empty, OnlyChar> a = {{}, {'A'}};
        [[maybe_unused]] constexpr alloy::tuple<OnlyChar, Empty> b = {{'A'}, {}};
        STATIC_CHECK(sizeof(a) == sizeof(OnlyChar));
        STATIC_CHECK(sizeof(b) == sizeof(OnlyChar));
    }
}
