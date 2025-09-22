#ifndef BOOST_SPIRIT_ALLOY_UTILITY_HPP
#define BOOST_SPIRIT_ALLOY_UTILITY_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/spirit/alloy/access.hpp>
#include <boost/spirit/alloy/tuple.hpp>

#include <type_traits>
#include <utility>

#include <cstddef>

namespace boost::spirit::alloy {

namespace detail {

template<class FromLValue, class FromXValue>
struct deduce
{
    static_assert(std::conjunction_v<std::is_lvalue_reference<FromLValue>, std::is_reference<FromXValue>,
                                     std::is_same<std::remove_reference_t<FromLValue>, std::remove_reference_t<FromXValue>>>);
};

template<class T>
struct deduce<T&, T&>
{
    using type = T&;
};

template<class T>
struct deduce<T&, T&&>
{
    using type = T;
};

template<class FromLValue, class FromXValue>
using deduce_t = typename deduce<FromLValue, FromXValue>::type;

template<std::size_t I, class Tuple>
using tuple_deduce_t = deduce_t<result_of::get<I, std::remove_cvref_t<Tuple>&>, result_of::get<I, std::remove_cvref_t<Tuple>&&>>;

template<class... Ts>
struct type_list;

template<class ResultTypeList, class IndexSeqList, class... Tuples>
struct tuple_cat_result_impl;

template<class... ResultTypes>
struct tuple_cat_result_impl<type_list<ResultTypes...>, type_list<>>
{
    using type = tuple<ResultTypes...>;
};

template<class... ResultTypes, std::size_t... Is, class... IndexSeqs, class Tuple, class... Tuples>
struct tuple_cat_result_impl<type_list<ResultTypes...>, type_list<std::index_sequence<Is...>, IndexSeqs...>, Tuple, Tuples...>
    : tuple_cat_result_impl<type_list<ResultTypes..., tuple_deduce_t<Is, Tuple>...>, type_list<IndexSeqs...>, Tuples...> {};

template<class... Tuples>
struct tuple_cat_result : tuple_cat_result_impl<type_list<>, type_list<std::make_index_sequence<result_of::size<Tuples>>...>, Tuples...> {};

template<class... Tuples>
using tuple_cat_result_t = typename tuple_cat_result<Tuples...>::type;

template<class ResultTuple, class IndexSeqList, class... Tuples>
struct tuple_cat_impl;

template<class ResultTuple>
struct tuple_cat_impl<ResultTuple, type_list<>>
{
    template<class... Args>
    static constexpr ResultTuple apply(Args&&... args)
    {
        return ResultTuple(std::forward<Args>(args)...);
    }
};

template<class ResultTuple, std::size_t... Is, class... IndexSeqs, class Tuple, class... Tuples>
struct tuple_cat_impl<ResultTuple, type_list<std::index_sequence<Is...>, IndexSeqs...>, Tuple, Tuples...>
{
    template<class... Args>
    static constexpr ResultTuple apply(Tuple&& tuple, Tuples&&... tuples, Args&&... args)
    {
        return tuple_cat_impl<ResultTuple, type_list<IndexSeqs...>, Tuples...>::apply(std::forward<Tuples>(tuples)..., std::forward<Args>(args)...,
                                                                                      alloy::get<Is>(std::forward<Tuple>(tuple))...);
    }
};

} // detail

template<class... Tuples>
    requires (TupleLike<std::remove_cvref_t<Tuples>> && ...)
constexpr detail::tuple_cat_result_t<Tuples...> tuple_cat(Tuples&&... tuples)
{
    using impl = detail::tuple_cat_impl<detail::tuple_cat_result_t<Tuples...>, detail::type_list<std::make_index_sequence<result_of::size<Tuples>>...>, Tuples...>;
    return impl::apply(std::forward<Tuples>(tuples)...);
}

} // boost::spirit::alloy

#endif
