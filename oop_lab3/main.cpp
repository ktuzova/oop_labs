#include <iostream>
#include <cmath>
#include "include/Pentagon.hpp"
#include "include/Hexagon.hpp"
#include "include/Octagon.hpp"
#include "include/FigureList.hpp"

int main() {

    Octagon o2(2);
    Point point2 = o2.geom_center();
    std::cout << o2 << std::endl;
    std::cout << point2 << std::endl;
    std::cout << o2.area() << std::endl << std::endl;

    Pentagon p1(3);
    Point point3 = p1.geom_center();
    std::cout << p1 << std::endl;
    std::cout << point3 << std::endl;
    std::cout << p1.area() << std::endl << std::endl;

    Hexagon h1(4);
    Point point4 = h1.geom_center();
    std::cout << h1 << std::endl;
    std::cout << point4 << std::endl;
    std::cout << h1.area() << std::endl << std::endl;

    FigureList fl{};

    fl.push_back(&o2);
    fl.push_back(&p1);
    fl.push_back(&h1);
    fl.print_geom_center();
    std::cout << fl.total_area() << std::endl;
    return 0;
}