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

template<std::size_t N, class TIndexSeq, class UIndexSeq>
struct index_sequence_split_impl;

template<std::size_t N, std::size_t... Is, std::size_t J, std::size_t... Js>
    requires (sizeof...(Is) < N)
struct index_sequence_split_impl<N, std::index_sequence<Is...>, std::index_sequence<J, Js...>>
    : index_sequence_split_impl<N, std::index_sequence<Is..., J>, std::index_sequence<Js...>> {};

template<std::size_t N, std::size_t... Is, std::size_t... Js>
    requires (sizeof...(Is) == N)
struct index_sequence_split_impl<N, std::index_sequence<Is...>, std::index_sequence<Js...>>
{
    using head = std::index_sequence<Is...>;
    using tail = std::index_sequence<Js...>;
};

template<std::size_t N, class IndexSeq>
struct index_sequence_split : index_sequence_split_impl<N, std::index_sequence<>, IndexSeq> {};

template<std::size_t N, class IndexSeq>
struct index_sequence_take
{
    using type = typename index_sequence_split<N, IndexSeq>::head;
};

template<std::size_t N, class IndexSeq>
using index_sequence_take_t = typename index_sequence_take<N, IndexSeq>::type;

template<std::size_t N, class IndexSeq>
struct index_sequence_drop
{
    using type = typename index_sequence_split<N, IndexSeq>::tail;
};

template<std::size_t N, class IndexSeq>
using index_sequence_drop_t = typename index_sequence_drop<N, IndexSeq>::type;

template<std::size_t From, std::size_t To, class IndexSeq>
struct index_sequence_subrange
{
    using type = index_sequence_take_t<To - From, index_sequence_drop_t<From, IndexSeq>>;
};

template<std::size_t From, std::size_t To, class IndexSeq>
using index_sequence_subrange_t = typename index_sequence_subrange<From, To, IndexSeq>::type;

template<class IndexSeq>
struct index_sequence_sum;

template<std::size_t... Is>
struct index_sequence_sum<std::index_sequence<Is...>> : std::integral_constant<std::size_t, (0 + ... + Is)> {};

template<class IndexSeq>
inline constexpr std::size_t index_sequence_sum_v = index_sequence_sum<IndexSeq>::value;

template<class IdxIndexSeq, class ValIndexSeq>
struct index_sequence_cumulative_sum_impl;

template<std::size_t... Idxs, class ValIndexSeq>
struct index_sequence_cumulative_sum_impl<std::index_sequence<Idxs...>, ValIndexSeq>
{
    using type = std::index_sequence<0, index_sequence_sum_v<index_sequence_take_t<Idxs + 1, ValIndexSeq>>...>;
};

template<class IndexSeq>
struct index_sequence_cumulative_sum;

template<std::size_t... Is>
struct index_sequence_cumulative_sum<std::index_sequence<Is...>>
    : index_sequence_cumulative_sum_impl<std::make_index_sequence<sizeof...(Is)>, std::index_sequence<Is...>> {};

template<class IndexSeq>
using index_sequence_cumulative_sum_t = typename index_sequence_cumulative_sum<IndexSeq>::type;

template<class IndexSeq, class FromIndexSeq, class ToIndexSeq>
struct index_sequence_segment_impl;

template<class IndexSeq, std::size_t... Froms, std::size_t... Tos>
struct index_sequence_segment_impl<IndexSeq, std::index_sequence<Froms...>, std::index_sequence<Tos...>> {
    using type = type_list<index_sequence_subrange_t<Froms, Tos, IndexSeq>...>;
};

template<class IndexSeq, std::size_t... Sizes>
struct index_sequence_segment;

template<std::size_t... Is, std::size_t... Sizes>
struct index_sequence_segment<std::index_sequence<Is...>, Sizes...> {
    using CumSumIndexSeq = index_sequence_cumulative_sum_t<std::index_sequence<Sizes...>>;

    using type = typename index_sequence_segment_impl0<
        std::index_sequence<Is...>, index_sequence_take_t<sizeof...(Sizes), CumSumIndexSeq>, index_sequence_drop_t<1, CumSumIndexSeq>>::type;
};

template<class IndexSeq, std::size_t... Sizes>
using index_sequence_segment_t = typename index_sequence_segment<IndexSeq, Sizes...>::type;

template<class Tuple, class IndexSeq>
struct tuple_from_tuple_and_index_sequence;

template<class Tuple, std::size_t... Is>
struct tuple_from_tuple_and_index_sequence<Tuple, std::index_sequence<Is...>>
{
    using type = tuple<tuple_deduce_t<Is, Tuple>...>;
};

template<class Tuple, class IndexSeq>
using tuple_from_tuple_and_index_sequence_t = typename tuple_from_tuple_and_index_sequence<Tuple, IndexSeq>::type;

template<class Tuple, class SegmentedIndexSeqList>
struct tuple_split_result_impl;

template<class Tuple, class... SegmentedIndexSeqs>
struct tuple_split_result_impl<Tuple, type_list<SegmentedIndexSeqs...>>
{
    using type = tuple<tuple_from_tuple_and_index_sequence_t<Tuple, SegmentedIndexSeqs>...>;
};

template<class Tuple, std::size_t... Sizes>
struct tuple_split_result
{
    using type = typename tuple_split_result_impl<Tuple, index_sequence_segment_t<std::make_index_sequence<result_of::size<Tuple>>, Sizes...>>::type;
};

template<class Tuple, std::size_t... Sizes>
using tuple_split_result_t = typename tuple_split_result<Tuple, Sizes...>::type;

template<class IndexSeq>
struct tuple_split_make_inner;

template<std::size_t... Is>
struct tuple_split_make_inner<std::index_sequence<Is...>>
{
    template<class Tuple>
    using ResultInnerTuple = tuple_from_tuple_and_index_sequence_t<Tuple, std::index_sequence<Is...>>;

    template<class Tuple>
    static constexpr ResultInnerTuple<Tuple> apply(Tuple&& t)
    {
        return ResultInnerTuple<Tuple> (alloy::get<Is>(std::forward<Tuple>(t))...);
    }
};

template<class ResultTuple, class SegmentedIndexSeqList>
struct tuple_split_make_outer;

template<class... ResultInnerTuples, class... SegmentedIndexSeqs>
struct tuple_split_make_outer<tuple<ResultInnerTuples...>, type_list<SegmentedIndexSeqs...>>
{
    template<class Tuple>
    static constexpr tuple<ResultInnerTuples...> apply(Tuple&& t)
    {
        return tuple<ResultInnerTuples...>(tuple_split_make_inner<SegmentedIndexSeqs>::apply(std::forward<Tuple>(t))...);
    }
};

template<class ResultTuple, class Tuple, std::size_t... Sizes>
struct tuple_split_impl : tuple_split_make_outer<ResultTuple, index_sequence_segment_t<std::make_index_sequence<result_of::size<Tuple>>, Sizes...>> {};

} // detail

template<class... Tuples>
    requires (TupleLike<std::remove_cvref_t<Tuples>> && ...)
constexpr detail::tuple_cat_result_t<Tuples...> tuple_cat(Tuples&&... tuples)
{
    using Impl = detail::tuple_cat_impl<detail::tuple_cat_result_t<Tuples...>, detail::type_list<std::make_index_sequence<result_of::size<Tuples>>...>, Tuples...>;
    return Impl::apply(std::forward<Tuples>(tuples)...);
}

template<std::size_t... Sizes, class Tuple>
    requires TupleLike<std::remove_cvref_t<Tuple>>
constexpr detail::tuple_split_result_t<Tuple, Sizes...> tuple_split(Tuple&& t)
{
    static_assert((0 + ... + Sizes) == result_of::size<Tuple>);
    using Impl = detail::tuple_split_impl<detail::tuple_split_result_t<Tuple, Sizes...>, Tuple, Sizes...>;
    return Impl::apply(std::forward<Tuple>(t));
}

} // boost::spirit::alloy

#endif
