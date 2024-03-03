#ifndef PENTAGON_HPP_INCLUDED
#define PENTAGON_HPP_INCLUDED

#include "Point.hpp"
#include "Figure.hpp"

template<typename T>
class Pentagon: public Figure<T>{
public:
    Point<T> p1{}, p2{}, p3{}, p4{}, p5{};
    double side{};

public:
    Pentagon() = default;
    Pentagon(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3, const Point<T> &p4, const Point<T> &p5);
    explicit Pentagon(T side);
    Pentagon(const Pentagon& other);
    Pentagon(Pentagon&& other) noexcept;
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;

    bool operator==(const Pentagon& other);

    template<typename U>
    friend std::istream& operator>>(std::istream& in, Pentagon& a);
    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, Pentagon& a);

    virtual Point<T> geom_center() const override;
    virtual T area() const override;
    virtual operator double() const override;
};
#include "../src/Pentagon.cpp"
#endif