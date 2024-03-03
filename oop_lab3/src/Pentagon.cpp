#include <iostream>
#include <cmath>
#include <cfloat>
#include "../include/Pentagon.hpp"

Pentagon::Pentagon(const Point &p1, const Point &p2, const Point &p3,
                   const Point &p4, const Point &p5) : p1(p1), p2(p2), p3(p3), p4(p4), p5(p5) {
    side = p1.dist(p2);
    bool c1 = fabs(p2.dist(p3) - side) > FLT_EPSILON;
    bool c2 = fabs(p3.dist(p4) - side) > FLT_EPSILON;
    bool c3 = fabs(p4.dist(p5) - side) > FLT_EPSILON;
    bool c4 = fabs(p5.dist(p1) - side) > FLT_EPSILON;
    if (c1 || c2 || c3 || c4) {
        throw std::logic_error("Pentagon with given points does not have equal sides");
    }
}

Pentagon::Pentagon(double side) : side(side) {
    if (side <= 0) {
        throw std::logic_error("Side must be a positive number");
    }
    double R = side / (2 * sin(M_PI / 5));
    p1 = Point(R * std::cos(1 * 2 * M_PI / 5), R * std::sin(1 * 2 * M_PI / 5));
    p2 = Point(R * std::cos(2 * 2 * M_PI / 5), R * std::sin(2 * 2 * M_PI / 5));
    p3 = Point(R * std::cos(3 * 2 * M_PI / 5), R * std::sin(3 * 2 * M_PI / 5));
    p4 = Point(R * std::cos(4 * 2 * M_PI / 5), R * std::sin(4 * 2 * M_PI / 5));
    p5 = Point(R * std::cos(5 * 2 * M_PI / 5), R * std::sin(5 * 2 * M_PI / 5));
}

Pentagon::Pentagon(const Pentagon &other) {
    p1 = other.p1;
    p2 = other.p2;
    p3 = other.p3;
    p4 = other.p4;
    p5 = other.p5;
    side = other.side;
}

Pentagon::Pentagon(Pentagon &&other) noexcept {
    p1 = std::move(other.p1);
    p2 = std::move(other.p2);
    p3 = std::move(other.p3);
    p4 = std::move(other.p4);
    p5 = std::move(other.p5);
    side = std::move(other.side);
}

Pentagon &Pentagon::operator=(const Pentagon &other) {
    if (this != &other) {
        p1 = other.p1;
        p2 = other.p2;
        p3 = other.p3;
        p4 = other.p4;
        p5 = other.p5;
        side = other.side;
    }

    return *this;
}

Pentagon &Pentagon::operator=(Pentagon &&other) noexcept {
    p1 = std::move(other.p1);
    p2 = std::move(other.p2);
    p3 = std::move(other.p3);
    p4 = std::move(other.p4);
    p5 = std::move(other.p5);
    side = std::move(other.side);

    return *this;
}

bool Pentagon::operator==(const Pentagon &other) {
    return (p1 == other.p1 && p2 == other.p2 && p3 == other.p3 &&
            p4 == other.p4 && p5 == other.p5);
}

std::istream &operator>>(std::istream &in, Pentagon &a) {
    Point p1, p2, p3, p4, p5;
    in >> p1 >> p2 >> p3 >> p4 >> p5;
    a = Pentagon(p1, p2, p3, p4, p5);

    return in;
}

std::ostream &operator<<(std::ostream &out, Pentagon &a) {
    out << a.p1 << " " << a.p2 << " " << a.p3 << " " << a.p4 << " " << a.p5;
    return out;
}

Point Pentagon::geom_center() const {
    return {(p1.get_x() + p2.get_x() + p3.get_x() + p4.get_x() + p5.get_x()) / 5,
            (p1.get_y() + p2.get_y() + p3.get_y() + p4.get_y() + p5.get_y()) / 5};
}

double Pentagon::area() const {
    return 0.25 * sqrt (5 + 2 * sqrt(5)) * side * side;
}

Pentagon::operator double() const {
    return 0.25 * sqrt (5 + 2 * sqrt(5)) * side * side;
}
