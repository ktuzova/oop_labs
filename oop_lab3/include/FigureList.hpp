#ifndef FIGURELIST_HPP_INCLUDED
#define FIGURELIST_HPP_INCLUDED

#include "Vector.hpp"
#include "Figure.hpp"
#include "Pentagon.hpp"
#include "Hexagon.hpp"
#include "Octagon.hpp"

class FigureList {
private:
    Vector<Figure*> figures;

public:
    FigureList() = default;
    size_t size() const;

    friend std::istream& operator>>(std::istream& in, FigureList& a);
    friend std::ostream& operator<<(std::ostream& out, FigureList& a);

    void print_geom_center() const;
    double total_area() const;
    operator double() const;

    void push_back(Figure *a);
    void erase(size_t index);

};

#endif
