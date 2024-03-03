#include <iostream>
#include <cmath>
#include <cfloat>
#include "../include/Pentagon.hpp"

template<typename T>
Pentagon<T>::Pentagon(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3,
                   const Point<T> &p4, const Point<T> &p5) : p1(p1), p2(p2), p3(p3), p4(p4), p5(p5) {
    side = p1.dist(p2);
    bool c1 = fabs(p2.dist(p3) - side) > FLT_EPSILON;
    bool c2 = fabs(p3.dist(p4) - side) > FLT_EPSILON;
    bool c3 = fabs(p4.dist(p5) - side) > FLT_EPSILON;
    bool c4 = fabs(p5.dist(p1) - side) > FLT_EPSILON;
    if (c1 || c2 || c3 || c4) {
        throw std::logic_error("Pentagon with given points does not have equal sides");
    }
}
template<typename T>
Pentagon<T>::Pentagon(T side) : side(side) {
    if (side <= 0) {
        throw std::logic_error("Side must be a positive number");
    }
    T R = side / (2 * sin(M_PI / 5));
    p1 = Point(R * std::cos(1 * 2 * M_PI / 5), R * std::sin(1 * 2 * M_PI / 5));
    p2 = Point(R * std::cos(2 * 2 * M_PI / 5), R * std::sin(2 * 2 * M_PI / 5));
    p3 = Point(R * std::cos(3 * 2 * M_PI / 5), R * std::sin(3 * 2 * M_PI / 5));
    p4 = Point(R * std::cos(4 * 2 * M_PI / 5), R * std::sin(4 * 2 * M_PI / 5));
    p5 = Point(R * std::cos(5 * 2 * M_PI / 5), R * std::sin(5 * 2 * M_PI / 5));
}
template<typename T>
Pentagon<T>::Pentagon(const Pentagon<T> &other) {
    p1 = other.p1;
    p2 = other.p2;
    p3 = other.p3;
    p4 = other.p4;
    p5 = other.p5;
    side = other.side;
}
template<typename T>
Pentagon<T>::Pentagon(Pentagon<T> &&other) noexcept {
    p1 = std::move(other.p1);
    p2 = std::move(other.p2);
    p3 = std::move(other.p3);
    p4 = std::move(other.p4);
    p5 = std::move(other.p5);
    side = std::move(other.side);
}
template<typename T>
Pentagon<T> &Pentagon<T>::operator=(const Pentagon<T> &other) {
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
template<typename T>
Pentagon<T> &Pentagon<T>::operator=(Pentagon<T> &&other) noexcept {
    p1 = std::move(other.p1);
    p2 = std::move(other.p2);
    p3 = std::move(other.p3);
    p4 = std::move(other.p4);
    p5 = std::move(other.p5);
    side = std::move(other.side);

    return *this;
}

template<typename T>
bool Pentagon<T>::operator==(const Pentagon<T> &other) {
    return (p1 == other.p1 && p2 == other.p2 && p3 == other.p3 &&
            p4 == other.p4 && p5 == other.p5);
}

template<typename U>
std::istream &operator>>(std::istream &in, Pentagon<U> &a) {
    Point<U> p1, p2, p3, p4, p5;
    in >> p1 >> p2 >> p3 >> p4 >> p5;
    a = Pentagon<U>(p1, p2, p3, p4, p5);
    return in;
}

template<typename U>
std::ostream &operator<<(std::ostream &out, Pentagon<U> &a) {

    out << a.p1 << " " << a.p2 << " " << a.p3 << " " << a.p4 << " " << a.p5;
    return out;
}

template<typename T>
Point<T> Pentagon<T>::geom_center() const {
    return {(p1.get_x() + p2.get_x() + p3.get_x() + p4.get_x() + p5.get_x()) / 5,
            (p1.get_y() + p2.get_y() + p3.get_y() + p4.get_y() + p5.get_y()) / 5};
}

template<typename T>
T Pentagon<T>::area() const {
    return 0.25 * sqrt (5 + 2 * sqrt(5)) * side * side;
}

template<typename T>
Pentagon<T>::operator double() const {
    return 0.25 * sqrt (5 + 2 * sqrt(5)) * side * side;
}


