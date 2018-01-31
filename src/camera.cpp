#include "camera.hpp"

camera::camera(const point& top_left_corner,
                const point& bottom_right_corner) :
    d_top_left_corner{ top_left_corner },
    d_bottom_right_corner{ bottom_right_corner }
{}

point camera::top_left_corner() const
{ return d_top_left_corner; }

point camera::bottom_right_corner() const
{ return d_bottom_right_corner; } 

void camera::setTopLeftCorner(const point& top_left_corner)
{ d_top_left_corner = top_left_corner; } 

void camera::setBottomRightCorner(const point& bottom_right_corner)
{ d_bottom_right_corner = bottom_right_corner; } 

void camera::setView(const point& top_left_corner,
                        const point& bottom_right_corner)
{ 
    setTopLeftCorner(top_left_corner);
    setBottomRightCorner(bottom_right_corner);
}
