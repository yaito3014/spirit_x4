#ifndef BOOST_SPIRIT_ALLOY_TUPLE_LIKE_HPP
#define BOOST_SPIRIT_ALLOY_TUPLE_LIKE_HPP

#include <boost/spirit/alloy/non_type_list.hpp>

#include <type_traits>

namespace boost::spirit::alloy {

template<class T>
struct adaptor;

template<class T>
concept TupleLike = detail::NonTypeList<typename adaptor<T>::getters>;

template<class T>
struct is_tuple_like : std::bool_constant<TupleLike<T>> {};

template<class T>
inline constexpr bool is_tuple_like_v = is_tuple_like<T>::value;

} // boost::spirit::alloy

#endif
