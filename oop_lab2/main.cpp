#include <iostream>
#include "include/Seven.hpp"

int main() {
    Seven x("1006");
    x += Seven("146");
    std::cout << x << std::endl;
    x -= Seven("66");
    std::cout << x << std::endl;
    std::cout << x - Seven("66") << std::endl;
    std::cout << (x > Seven("34")) << std::endl;
    std::cout << (x > Seven("242152345")) << std::endl;
    std::cout << (x < Seven("0")) << std::endl;
    std::cout << (x != Seven("666")) << std::endl;
    std::cout << (x == Seven("1056")) << std::endl;

    return 0;
}
