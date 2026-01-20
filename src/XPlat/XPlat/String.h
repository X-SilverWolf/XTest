#ifndef XPLAT_STRING_H
#define XPLAT_STRING_H

namespace xplat
{

// Options for splitting the string
class SplitOptions 
{
public:
    struct Defaults
    {
        // Whether to preallocate the memory for the result
        // This is used to split the large strings efficiently
        static constexpr bool preallocate = false;
        // Whether to ignore the empty strings
        // This is used to split the strings and ignore the empty strings
        static constexpr bool ignore_empty = false;

    };

    constexpr bool preallocate() const { return preallocate_; }
    constexpr SplitOptions& preallocate(bool enable)
    {
        preallocate_ = enable;
        return *this;
    }

    constexpr bool ignore_empty() const { return ignore_empty_; }
    constexpr SplitOptions& ignore_empty(bool enable) 
    {
        ignore_empty_ = enable;
        return *this;
    }

    private:
    bool preallocate_ = Defaults::preallocate;
    bool ignore_empty_ = Defaults::ignore_empty;
};

// C-escape a string

}// xplat


#endif // XPLAT_STRING_H