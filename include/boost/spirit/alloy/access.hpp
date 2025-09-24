#ifndef BOOST_SPIRIT_ALLOY_ACCESS_HPP
#define BOOST_SPIRIT_ALLOY_ACCESS_HPP

/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/spirit/alloy/tuple_like.hpp>

#include <functional>
#include <type_traits>
#include <utility>

#include <cstddef>

namespace boost::spirit::alloy {

namespace result_of {

template<class T>
    requires TupleLike<std::remove_cvref_t<T>>
inline constexpr std::size_t size = adaptor<std::remove_cvref_t<T>>::getters::size;

} // result_of

template<class T>
    requires TupleLike<std::remove_cvref_t<T>>
constexpr std::size_t size(T&&) noexcept
{
    return result_of::size<T>;
}

namespace detail {

// Clang workaround
template<std::size_t I, class T>
inline constexpr auto getter_of = adaptor<T>::getters::template get<I>;

} // detail

namespace result_of {

// `std::invoke_result_t` MUST NOT be used here due to its side effects:
// <https://eel.is/c++draft/meta.trans.other#tab:meta.trans.other-row-11-column-2-note-2>
template<std::size_t I, class T>
    requires TupleLike<std::remove_cvref_t<T>>
using get = decltype(std::invoke(detail::getter_of<I, std::remove_cvref_t<T>>, std::declval<T>()));

} // result_of

template<std::size_t I, class T>
    requires TupleLike<std::remove_cvref_t<T>>
constexpr result_of::get<I, T> get(T&& x)
    noexcept(noexcept(std::is_nothrow_invocable_v<decltype(detail::getter_of<I, std::remove_cvref_t<T>>), T>))
{
    return std::invoke(detail::getter_of<I, std::remove_cvref_t<T>>, std::forward<T>(x));
}

} // boost::spirit::alloy

#endif
