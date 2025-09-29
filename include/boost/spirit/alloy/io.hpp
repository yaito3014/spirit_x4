#ifndef BOOST_SPIRIT_ALLOY_IO_HPP
#define BOOST_SPIRIT_ALLOY_IO_HPP

#include <boost/spirit/alloy/access.hpp>
#include <boost/spirit/alloy/tuple.hpp>

#include <ostream>
#include <utility>

#include <cstddef>

namespace boost::spirit::alloy {

namespace detail {

template<class IndexSeq>
struct tuple_ostream_impl;

template<std::size_t... Is>
struct tuple_ostream_impl<std::index_sequence<Is...>>
{
    template<class... Ts>
    static constexpr std::ostream& apply(std::ostream& os, tuple<Ts...> const& t)
    {
        os << '(';
        [[maybe_unused]] bool first = true;
        ((std::exchange(first, false) ? os << alloy::get<Is>(t) : os << ", " << alloy::get<Is>(t)), ...);
        os << ')';
        return os;
    }
};

} // detail

template<class... Ts>
std::ostream& operator<<(std::ostream& os, tuple<Ts...> const& t)
{
    return detail::tuple_ostream_impl<std::make_index_sequence<sizeof...(Ts)>>::apply(os, t);
}

} // boost::spirit::alloy

#endif
