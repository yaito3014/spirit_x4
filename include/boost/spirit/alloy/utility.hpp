#ifndef BOOST_SPIRIT_ALLOY_UTILITY_HPP
#define BOOST_SPIRIT_ALLOY_UTILITY_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/spirit/alloy/detail/deduce.hpp>

#include <boost/spirit/alloy/access.hpp>
#include <boost/spirit/alloy/tuple.hpp>

#include <type_traits>
#include <utility>

#include <cstddef>

namespace boost::spirit::alloy {

namespace detail {

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
    : tuple_cat_result_impl<type_list<ResultTypes..., tuple_like_element_t<Is, Tuple>...>, type_list<IndexSeqs...>, Tuples...> {};

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
struct index_sequence_segment_impl<IndexSeq, std::index_sequence<Froms...>, std::index_sequence<Tos...>>
{
    using type = type_list<index_sequence_subrange_t<Froms, Tos, IndexSeq>...>;
};

template<class IndexSeq, std::size_t... Sizes>
struct index_sequence_segment;

template<std::size_t... Is, std::size_t... Sizes>
struct index_sequence_segment<std::index_sequence<Is...>, Sizes...>
{
    using CumSumIndexSeq = index_sequence_cumulative_sum_t<std::index_sequence<Sizes...>>;

    using type = typename index_sequence_segment_impl<std::index_sequence<Is...>, index_sequence_take_t<sizeof...(Sizes), CumSumIndexSeq>,
                                                      index_sequence_drop_t<1, CumSumIndexSeq>>::type;
};

template<class IndexSeq, std::size_t... Sizes>
using index_sequence_segment_t = typename index_sequence_segment<IndexSeq, Sizes...>::type;

template<class Tuple, class IndexSeq>
struct tuple_from_tuple_and_index_sequence;

template<class Tuple, std::size_t... Is>
struct tuple_from_tuple_and_index_sequence<Tuple, std::index_sequence<Is...>>
{
    using type = tuple<tuple_like_element_t<Is, Tuple>...>;
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
        return ResultInnerTuple<Tuple>(alloy::get<Is>(std::forward<Tuple>(t))...);
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

template<class FromTypeList, class ToTypeList>
struct are_all_nothrow_assignable;

template<class... Froms, class... Tos>
struct are_all_nothrow_assignable<type_list<Froms...>, type_list<Tos...>>
    : std::conjunction<std::is_nothrow_assignable<Tos, Froms>...> {};

template<class From, class To, class IndexSeq>
struct tuple_assign_noexcept_impl;

template<class From, class To, std::size_t... Is>
struct tuple_assign_noexcept_impl<From, To, std::index_sequence<Is...>>
    : are_all_nothrow_assignable<type_list<tuple_like_element_t<Is, From>...>, type_list<tuple_like_element_t<Is, To>...>> {};

template<class From, class To>
struct tuple_assign_noexcept
    : tuple_assign_noexcept_impl<From, To, std::make_index_sequence<result_of::size<From>>> {};

template<class From, class To>
inline constexpr bool tuple_assign_noexcept_v = tuple_assign_noexcept<From, To>::value;

template<class IndexSeq>
struct tuple_assign_impl;

template<std::size_t... Is>
struct tuple_assign_impl<std::index_sequence<Is...>>
{
    template<class From, class To>
    static constexpr void apply(From&& from, To&& to)
    {
        ((void)(alloy::get<Is>(std::forward<To>(to)) = alloy::get<Is>(std::forward<From>(from))), ...);
    }
};

template<class Tuple, class IndexSeq>
struct make_tuple_view_result_impl;

template<class Tuple, std::size_t... Is>
struct make_tuple_view_result_impl<Tuple, std::index_sequence<Is...>>
{
    using type = tuple<tuple_like_element_t<Is, Tuple>&...>;
};

template<class Tuple>
struct make_tuple_view_result : make_tuple_view_result_impl<Tuple, std::make_index_sequence<result_of::size<Tuple>>> {};

template<class Tuple>
using make_tuple_view_result_t = typename make_tuple_view_result<Tuple>::type;

} // detail

namespace result_of {

template<class... Tuples>
using tuple_cat = detail::tuple_cat_result_t<Tuples...>;

template<class Tuple, std::size_t... Sizes>
using tuple_split = detail::tuple_split_result_t<Tuple, Sizes...>;

template<class Tuple>
using make_tuple_view = detail::make_tuple_view_result_t<Tuple>;

} // result_of

template<class... Tuples>
    requires (TupleLike<std::remove_cvref_t<Tuples>> && ...)
constexpr result_of::tuple_cat<Tuples...> tuple_cat(Tuples&&... tuples)
{
    using Impl = detail::tuple_cat_impl<detail::tuple_cat_result_t<Tuples...>, detail::type_list<std::make_index_sequence<result_of::size<Tuples>>...>, Tuples...>;
    return Impl::apply(std::forward<Tuples>(tuples)...);
}

template<std::size_t... Sizes, class Tuple>
    requires TupleLike<std::remove_cvref_t<Tuple>>
constexpr result_of::tuple_split<Tuple, Sizes...> tuple_split(Tuple&& t)
{
    static_assert((0 + ... + Sizes) == result_of::size<Tuple>);
    using Impl = detail::tuple_split_impl<detail::tuple_split_result_t<Tuple, Sizes...>, Tuple, Sizes...>;
    return Impl::apply(std::forward<Tuple>(t));
}

template<class From, class To>
    requires TupleLike<std::remove_cvref_t<From>> && TupleLike<std::remove_cvref_t<To>>
constexpr void tuple_assign(From&& from, To&& to) noexcept(detail::tuple_assign_noexcept_v<From, To>)
{
    static_assert(result_of::size<From> == result_of::size<To>);
    using Impl = detail::tuple_assign_impl<std::make_index_sequence<result_of::size<From>>>;
    Impl::apply(std::forward<From>(from), std::forward<To>(to));
}

template<class Tuple>
    requires TupleLike<std::remove_cvref_t<Tuple>>
constexpr result_of::make_tuple_view<Tuple> make_tuple_view(Tuple& t) noexcept
{
    return result_of::make_tuple_view<Tuple>(t);
}

} // boost::spirit::alloy

#endif
