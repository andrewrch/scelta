// Copyright (c) 2017 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

// clang-format off
// Usage of C++17: `__has_include`.
#if __has_include(<boost/optional.hpp>) && __has_include(<boost/none.hpp>)
// clang-format on

#include "../../utils/optional_utils.hpp"
#include "../../utils/homogenizer.hpp"
#include "../../traits/optional.hpp"
#include <boost/optional.hpp>
#include <boost/none.hpp>

#define SCELTA_SUPPORT_OPTIONAL_BOOST 1

namespace scelta::impl
{
    template <typename T>
    struct traits<::boost::optional<T>>
    {
        template <typename Tag, typename... Ts>
        static constexpr auto visit(Tag, Ts&&... xs)
            SCELTA_RETURNS(
                ::scelta::impl::visit_optional(FWD(xs)...)
            )

        template <typename... Variants>
        static constexpr auto valid_state(Variants&&...)
            SCELTA_RETURNS(
                true
            )
    };
}


/* TODO: consider
namespace scelta::support::optional::boost
{
    template <typename F>
    constexpr auto if_supported(F&& f) SCELTA_RETURNS(f())
}
*/

#else

/* TODO: consider
namespace scelta::support::optional::boost
{
    template <typename F>
    constexpr void if_supported(F&&) {}
}
*/

// TODO: provide something like "SCELTA_DISABLE_SUPPORT_OPTIONAL_BOOST"

#endif
