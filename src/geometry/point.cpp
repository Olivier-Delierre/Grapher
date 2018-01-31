#include "point.hpp"

point::point(double x, double y) :
    d_x{ x },
    d_y{ y }
{}

point::point(const point& p) :
    d_x{ p.d_x },
    d_y{ p.d_y }
{}

double point::x() const
{ return d_x; }

double point::y() const
{ return d_y; }

void point::setX(double x)
{ d_x = x; }

void point::setY(double y)
{ d_y = y; }

void point::setPosition(double x, double y) 
{ setX(x); setY(y); }
