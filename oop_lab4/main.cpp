#include <iostream>
#include <cmath>
#include <iomanip>

#include "include/Pentagon.hpp"
#include "include/Hexagon.hpp"
#include "include/Octagon.hpp"
#include "include/FigureArray.hpp"

int main() {
    std::cout << std::setprecision(20);
    Pentagon<double> pp1(Point<double>(cos(2*M_PI/5), sin(2*M_PI/5)),
                         Point<double>(cos(4 * M_PI/5), sin(4 * M_PI/5)),
                         Point<double>(cos(6*M_PI/5), sin(6*M_PI/5)),
                         Point<double>(cos(8*M_PI/5), sin(8*M_PI/5)),
                         Point<double>(cos(2*M_PI), sin(2*M_PI)));
// Create a Pentagon object with specified points
    Point<double> p1 = pp1.geom_center(); // Calculate the geometric center of the pentagon
    std::cout << pp1 << std::endl; // Print the details of the pentagon
    std::cout << p1 << std::endl; // Print the geometric center of the pentagon
    std::cout << pp1.area() << std::endl << std::endl; // Print the area of the pentagon

    Pentagon<double> p2(5); // Create a Pentagon object with a side length
    Point p2_center = p2.geom_center(); // Calculate the geometric center of the pentagon
    std::cout << p2 << std::endl; // Print the details of the pentagon
    std::cout << p2_center << std::endl; // Print the geometric center of the pentagon
    std::cout << p2.area() << std::endl << std::endl; // Print the area of the pentagon

    Hexagon<double> h1(3); // Create a Hexagon object with a side length
    Point p3 = h1.geom_center(); // Calculate the geometric center of the hexagon
    std::cout << h1 << std::endl; // Print the details of the hexagon
    std::cout << p3 << std::endl; // Print the geometric center of the hexagon
    std::cout << h1.area() << std::endl << std::endl; // Print the area of the hexagon

    Octagon<double> o1(4); // Create an Octagon object with a side length
    Point p4 = o1.geom_center(); // Calculate the geometric center of the octagon
    std::cout << o1 << std::endl; // Print the details of the octagon
    std::cout << p4 << std::endl; // Print the geometric center of the octagon
    std::cout << o1.area() << std::endl << std::endl; // Print the area of the octagon
    return 0;
}