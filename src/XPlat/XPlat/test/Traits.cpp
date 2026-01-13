#include <iostream>
#include <XPlat/Traits.h>

class TraitsTest
{

public:
    static bool testArray()
    {
        int bounded_array[10] = {0};
        int unbounded_array[] = {0};
        int constant = 10;

        std::cout << xplat::is_bounded_array_v<decltype(bounded_array)> << std::endl;  // TRUE
        std::cout << xplat::is_unbounded_array_v<decltype(unbounded_array)> << std::endl; // FLASE
        std::cout << xplat::is_unbounded_array_v<decltype(constant)> << std::endl; // FLASE
        return true;
    }


};

int main()
{
    std::cout << TraitsTest::testArray() << std::endl;
    return 0;
}