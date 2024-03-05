#include <iostream>
#include <map>
#include "include/Allocator.hpp"
#include "include/List.hpp"

int main() {

    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>>> test_map;
    int64_t fact = 1;
    for (int i = 1; i <= 10; ++i) {
        fact *= i;
        test_map[i] = fact;
    }
    for (const auto &[k, v]: test_map)
        std::cout << k << " " << v << std::endl;

    std::cout << std::endl;

    List<int, Allocator<Node<int>>> a{};
    a.insert(a.begin(), 4);
    a.insert(a.begin(), 1);
    a.insert(++a.begin(), 2);
    a.insert(a.begin(), 8);

    List<int, Allocator<Node<int>>> b{a};

    a.push_back(146);

    for (auto it = b.begin(); it != b.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    b.insert(++b.begin(), 3, -42);
    b.insert(++b.begin(), a.begin(), a.end());

    for (auto it = b.begin(); it != b.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (auto it = a.begin(); it != a.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    a.pop_front();
    a.pop_back();

    for (auto it = a.begin(); it != a.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    List<int, Allocator<Node<int>>> c{-1, 23, 84, 55, 66};
    for (auto it = c.begin(); it != c.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
