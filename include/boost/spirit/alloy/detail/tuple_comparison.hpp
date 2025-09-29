#ifndef BOOST_SPIRIT_ALLOY_DETAIL_TUPLE_COMPARISON_HPP
#define BOOST_SPIRIT_ALLOY_DETAIL_TUPLE_COMPARISON_HPP

#include <concepts>
#include <type_traits>

namespace boost::spirit::alloy {

template<class... Ts>
class tuple;

namespace detail {

template<class T>
concept boolean_testable_impl = std::convertible_to<T, bool>;

template<class T>
concept boolean_testable = boolean_testable_impl<T> && requires(T&& x) {
    { !static_cast<T&&>(x) } -> boolean_testable_impl;
};

namespace equality_operator_adl_barrier {

bool operator==(auto, auto) = delete;  // poison-pill

template<class T, class U>
concept has_equality_operator = requires(T&& x, U&& y) {
    { static_cast<T&&>(x) == static_cast<U&&>(y) } -> boolean_testable;
};

}  // equality_operator_adl_barrier

using equality_operator_adl_barrier::has_equality_operator;

template<class TTuple, class UTuple>
struct do_tuple_all_elements_have_equality_operator : std::false_type {};

template<class... Ts, class... Us>
struct do_tuple_all_elements_have_equality_operator<tuple<Ts...>, tuple<Us...>>
    : std::bool_constant<(has_equality_operator<Ts const&, Us const&> && ...)> {};

template<class TTuple, class UTuple>
inline constexpr bool do_tuple_all_elements_have_equality_operator_v = do_tuple_all_elements_have_equality_operator<TTuple, UTuple>::value;

template<class TTuple, class UTuple>
concept tuple_all_elements_have_equality_operator = do_tuple_all_elements_have_equality_operator_v<TTuple, UTuple>;

} // detail

} // boost::spirit::alloy

#endif
