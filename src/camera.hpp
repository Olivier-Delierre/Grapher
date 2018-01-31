/**
 * @author Olivier Delierre
 * @version dev
 */

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "geometry/point.hpp"

class camera {
public:
    /**
     * Constructor with two points which defines
     * the top left corner and the bottom right corner
     * of the view.
     *
     * @param top_left_corner The top left corner's point ;
     * @param bottom_right_corner The bottom right corner's point.
     */
    camera(const point& top_left_corner, 
            const point& bottom_right_corner);

    /**
     * Returns the point of the top left corner.
     *
     * @returns the point of the top left corner.
     */
    point top_left_corner() const;

    /**
     * Returns the point of the bottom right corner.
     *
     * @returns the point of the bottom right corner.
     */
    point bottom_right_corner() const;


    /**
     * Modify the view of the camera, by passing two points
     * which defines the new corners.
     *
     * @param top_left_corner The new top left corner's point ;
     * @param bottom_right_corner The new bottom right corner's point.
     */
    void setView(const point& top_left_corner, 
                    const point& bottom_right_corner);
private: 
    /**
     * Set the new top left corner.
     *
     * @param top_left_corner The new top left corner's point.
     */
    void setTopLeftCorner(const point& top_left_corner);
    
    /**
     * Set the new bottom right corner.
     *
     * @param bottom_right_corner The new bottom right corner's point.
     */
    void setBottomRightCorner(const point& bottom_right_corner);

    /// The two points which limits the camera's view.
    point d_top_left_corner, d_bottom_right_corner;
};

#endif
