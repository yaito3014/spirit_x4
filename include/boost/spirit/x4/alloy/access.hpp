#ifndef BOOST_SPIRIT_X4_ALLOY_ACCESS_HPP
#define BOOST_SPIRIT_X4_ALLOY_ACCESS_HPP

#include <boost/spirit/x4/alloy/non_type_list.hpp>

#include <functional>
#include <type_traits>
#include <utility>

#include <cstddef>

namespace boost::spirit::x4::alloy
{
    template <typename T>
    struct adaptor;

    template <typename T>
    concept TupleLike = requires {
        requires detail::NonTypeList<typename adaptor<T>::getters>;
        requires []<std::size_t... Is>(std::index_sequence<Is...>){
            return std::conjunction_v<std::is_invocable<decltype(adaptor<T>::getters::template get<Is>), T>...>;
        }(std::make_index_sequence<adaptor<T>::getters::size>{});
    };

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
        template <std::size_t I, typename T>
            requires TupleLike<std::remove_cvref_t<T>>
        using get = std::invoke_result_t<decltype(adaptor<std::remove_cvref_t<T>>::getters::template get<I>), T>;
    } // result_of

    template <std::size_t I, typename T>
        requires TupleLike<std::remove_cvref_t<T>>
    constexpr result_of::get<I, T> get(T&& x)
        noexcept(noexcept(std::is_nothrow_invocable_v<decltype(adaptor<std::remove_cvref_t<T>>::getters::template get<I>), T>))
    {
        return std::invoke(adaptor<std::remove_cvref_t<T>>::getters::template get<I>, std::forward<T>(x));
    }
} // boost::spirit::x4::alloy

#endif // BOOST_SPIRIT_X4_ALLOY_ACCESS_HPP
