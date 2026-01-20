#ifndef __XPLAT_EXCEPTION_H__
#define __XPLAT_EXCEPTION_H__

#include <xplat/Traits.h>

namespace xplat 
{

    template <typename Ex>
    [[noreturn]] void throw_exception(Ex&& ex) 
    {
        throw static_cast<Ex&&>(ex);
    }

namespace detail 
{

    // This struct is used to handle the case when an exception argument is a C-string array (e.g., const char[]).
    // It helps deduce the proper argument type to pass (as a pointer) to the exception constructor.
    // 
    // - `v<R>` strips any reference and array extent from R, resulting in the underlying element type (e.g., char for char[]).
    // - `apply<R>` enables this type only when R (after removing extent and reference) is exactly `const char`.
    //   In that case, it resolves to `const char*`.
    struct throw_exception_arg_array_ 
    {
        // v<R>: Strip reference and array dimensions, get base type
        template <typename R>
        using v = std::remove_extent_t<std::remove_reference_t<R>>;
        // apply<R>: SFINAE, only enabled if R is a (const) char array; yields pointer type
        template <typename R>
        using apply = std::enable_if_t<std::is_same<char const, v<R>>::value, v<R>*>;
    };
    struct throw_exception_arg_trivial_ 
    {
        template <typename R>
        using apply = remove_cvref_t<R>;
    };
    struct throw_exception_arg_base_ 
    {
        template <typename R>
        using apply = R;
    };
    template <typename R>
    using throw_exception_arg_ = //
        conditional_t<
            std::is_array<std::remove_reference_t<R>>::value,
            throw_exception_arg_array_,
            conditional_t<
                std::is_trivially_copyable_v<remove_cvref_t<R>>,
                throw_exception_arg_trivial_,
                throw_exception_arg_base_>>;

    template <typename R>
    using throw_exception_arg_t = typename throw_exception_arg_<R>::template apply<R>;

    template <typename R>
    using throw_exception_arg_fmt_t = remove_cvref_t<typename throw_exception_arg_<R>::template apply<R>>;

    template <typename Ex, typename... Args>
    [[noreturn]]  void throw_exception_(Args... args) 
    {
        throw_exception(Ex(static_cast<Args>(args)...));
    }

    template <typename Ex, typename... Args>
    [[noreturn]]  void terminate_with_(Args... args) noexcept 
    {
        throw_exception(Ex(static_cast<Args>(args)...));
    }
    
} // namespace detail

template <typename Ex, typename... Args>
[[noreturn]] void throw_exception(Args&&... args) 
{
  detail::throw_exception_<Ex, detail::throw_exception_arg_t<Args&&>...>(static_cast<Args&&>(args)...);
}

template <typename Ex, typename... Args>
[[noreturn]] void terminate_with(Args&&... args) 
{
  detail::terminate_with_<Ex, detail::throw_exception_arg_t<Args&&>...>(static_cast<Args&&>(args)...);
}


}
#endif