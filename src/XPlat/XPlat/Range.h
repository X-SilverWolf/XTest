#ifndef XPLAT_RANGE_H
#define XPLAT_RANGE_H


#include <iterator>
#include <string>
#include <stdexcept>
#include "Traits.h"
#include "Exception.h"

namespace xplat
{

namespace detail
{
    template <typename T>
    struct IsCharPointer{};

    template <>
    struct IsCharPointer<char*>
    {
        using type = int;
    };

    template <>
    struct IsCharPointer<const char*>
    {
        using const_type = int;
        using type = int;
    };

    template <class T>
    struct IsUnsignedCharPointer {};

    template <>
    struct IsUnsignedCharPointer<unsigned char*>
    {
        using type = int;
    };

    template <>
    struct IsUnsignedCharPointer<const unsigned char*>
    {
        using const_type = int;
        using type = int;
    };


} // namespace detail




template <class Iter>
class Range 
{
private:
    using iter_traits = std::iterator_traits<Iter>;

    template <typename Alloc>
    using string = std::basic_string<char, std::char_traits<char>, Alloc>;

    Iter b_;
    Iter e_;
public:
    using value_type = typename iter_traits::value_type;
    using size_type = std::size_t;
    using defference_type = typename iter_traits::difference_type;
    using iterator = Iter;
    using reference = typename iter_traits::reference;
    using const_reference = conditional_t<
        std::is_lvalue_reference_v<reference>,
        std::add_lvalue_reference_t<std::add_const_t<std::remove_reference_t<reference>>>,
        conditional_t<
            std::is_rvalue_reference_v<reference>,
            std::add_rvalue_reference_t<std::add_const_t<std::remove_reference_t<reference>>>,
            reference>>;

    using const_range_type = typename std::conditional<
        std::is_same<Iter, char*>::value || std::is_same<Iter, unsigned char*>::value,
        Range<const value_type*>,
        Range<Iter>>::type;

    static const size_type npos;


public:
    constexpr Range() : b_(), e_() {}
    constexpr Range(const Range&) = default;
    constexpr Range(Range&&) = default;

    constexpr Range(Iter b, Iter e) : b_(b), e_(e) {}
    constexpr Range(Iter b, size_t size) : b_(b), e_(b + size) {}
    Range(std::nullptr_t) = delete;

    constexpr Range(Iter str)
        : b_(str), e_(str + constexpr_strlen(str))
    {
        static_assert(std::is_same<int, typename detail::IsCharPointer<Iter>::type>::value, "Range(Iter str) is only valid for char*");
    }

    /**
     * @brief Construct a new Range object from a string
     * 
     * @param str 
     */
    template <
        class Alloc,
        class T = Iter,
        typename detail::IsCharPointer<T>::const_type = 0>
        Range(const string<Alloc>& str)
        : b_(str.data()), e_(str.data() + str.size()){}

    template <
        class Alloc,
        class T = Iter,
        typename detail::IsCharPointer<T>::const_type = 0>
        Range(const string<Alloc>& str, typename string<Alloc>::size_type startFrom)
        {
            if(XPLAT_UNLIKELY(startFrom > str.size()))
            {
                throw_exception<std::out_of_range>("index out of range");
            }
            b_ = str.data() + startFrom;
            e_ = str.data() + str.size();
        }
};


} // namespace xplat


#endif