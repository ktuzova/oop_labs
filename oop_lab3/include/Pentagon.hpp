#ifndef PENTAGON_HPP_INCLUDED
#define PENTAGON_HPP_INCLUDED

#include "Point.hpp"
#include "Figure.hpp"

class Pentagon: public Figure{
private:
    Point p1{}, p2{}, p3{}, p4{}, p5{};
    double side{};

public:
    Pentagon() = default;
    Pentagon(const Point &p1, const Point &p2, const Point &p3, const Point &p4, const Point &p5);
    explicit Pentagon(double side);
    Pentagon(const Pentagon& other);
    Pentagon(Pentagon&& other) noexcept;
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;

    bool operator==(const Pentagon& other);
    friend std::istream& operator>>(std::istream& in, Pentagon& a);
    friend std::ostream& operator<<(std::ostream& out, Pentagon& a);
    virtual Point geom_center() const override;
    virtual double area() const override;
    virtual operator double() const override;
};

#endif