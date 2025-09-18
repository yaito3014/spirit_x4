#include <boost/spirit/x4/alloy/access.hpp>
#include <boost/spirit/x4/alloy/adapted.hpp>

#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

int main()
{
    {
        struct NonAdaptedStruct {};

        static_assert(!boost::spirit::x4::alloy::TupleLike<NonAdaptedStruct>);
    }
    {
        using Pair = std::pair<int, double>;

        static_assert(boost::spirit::x4::alloy::TupleLike<Pair>);

        static_assert(boost::spirit::x4::alloy::result_of::size<Pair> == 2);
        
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<0, Pair&>, int&>);
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<0, Pair const&>, int const&>);
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<0, Pair&&>, int&&>);
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<0, Pair const&&>, int const&&>);
        
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<1, Pair&>, double&>);
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<1, Pair const&>, double const&>);
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<1, Pair&&>, double&&>);
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<1, Pair const&&>, double const&&>);

        constexpr Pair p(42, 3.14);

        static_assert(boost::spirit::x4::alloy::size(p) == 2);

        static_assert(boost::spirit::x4::alloy::get<0>(p) == 42);
        static_assert(boost::spirit::x4::alloy::get<1>(p) == 3.14);
    }
    
    {
        using Tuple = std::tuple<int, double, char>;

        static_assert(boost::spirit::x4::alloy::TupleLike<Tuple>);

        static_assert(boost::spirit::x4::alloy::result_of::size<Tuple> == 3);
        
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<0, Tuple&>, int&>);
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<0, Tuple const&>, int const&>);
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<0, Tuple&&>, int&&>);
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<0, Tuple const&&>, int const&&>);
        
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<1, Tuple&>, double&>);
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<1, Tuple const&>, double const&>);
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<1, Tuple&&>, double&&>);
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<1, Tuple const&&>, double const&&>);
        
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<2, Tuple&>, char&>);
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<2, Tuple const&>, char const&>);
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<2, Tuple&&>, char&&>);
        static_assert(std::is_same_v<boost::spirit::x4::alloy::result_of::get<2, Tuple const&&>, char const&&>);

        constexpr Tuple p(42, 3.14, 'A');

        static_assert(boost::spirit::x4::alloy::size(p) == 3);

        static_assert(boost::spirit::x4::alloy::get<0>(p) == 42);
        static_assert(boost::spirit::x4::alloy::get<1>(p) == 3.14);
        static_assert(boost::spirit::x4::alloy::get<2>(p) == 'A');
    }
}
