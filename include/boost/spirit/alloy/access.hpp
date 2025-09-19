/*=============================================================================
    Copyright (c) 2025 Yaito Kakeyama

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_SPIRIT_ALLOY_ACCESS_HPP
#define BOOST_SPIRIT_ALLOY_ACCESS_HPP

#include <boost/spirit/alloy/non_type_list.hpp>

#include <functional>
#include <type_traits>
#include <utility>

#include <cstddef>

namespace boost::spirit::alloy
{
    template <typename T>
    struct adaptor;

    template <typename T>
    concept TupleLike = detail::NonTypeList<typename adaptor<T>::getters>;

    namespace result_of
    {
        template <typename T>
            requires TupleLike<std::remove_cvref_t<T>>
        inline constexpr std::size_t size = adaptor<std::remove_cvref_t<T>>::getters::size;
    } // result_of

    template <typename T>
        requires TupleLike<std::remove_cvref_t<T>>
    constexpr std::size_t size(T&&) noexcept
    {
        return result_of::size<T>;
    }

    namespace result_of
    {   
        // `std::invoke_result_t` MUST NOT be used here due to its side effects:
        // <https://eel.is/c++draft/meta.trans.other#tab:meta.trans.other-row-11-column-2-note-2>
        template <std::size_t I, typename T>
            requires TupleLike<std::remove_cvref_t<T>>
        using get = decltype(std::invoke(adaptor<std::remove_cvref_t<T>>::getters::template get<I>, std::declval<T>()));
    } // result_of

    template <std::size_t I, typename T>
        requires TupleLike<std::remove_cvref_t<T>>
    constexpr result_of::get<I, T> get(T&& x)
        noexcept(noexcept(std::is_nothrow_invocable_v<decltype(adaptor<std::remove_cvref_t<T>>::getters::template get<I>), T>))
    {
        return std::invoke(adaptor<std::remove_cvref_t<T>>::getters::template get<I>, std::forward<T>(x));
    }
} // boost::spirit::alloy

#endif
