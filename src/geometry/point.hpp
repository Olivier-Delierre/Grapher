/**
 * @author Olivier Delierre
 * @version dev
 */

#ifndef POINT_HPP
#define POINT_HPP

class point {
public:
    /**
     * Constructor with x and y coordinates, 0 by default.
     *
     * @param x The x coordinate ;
     * @param y The y coordinate.
     */
    point(double x = 0.0, double y = 0.0);

    /**
     * Recopy constructor.
     *
     * @param p The point to copy.
     */
    point(const point& p);

    /**
     * Returns the x coordinate.
     *
     * @returns the x coordinate.
     */
    double x() const;

    /**
     * Returns the y coordinate.
     *
     * @returns the y coordinate.
     */
    double y() const;

    /**
     * Set a new position for the point.
     *
     * @param x The new x coordinate ;
     * @param y The new y coordinate.
     */
    void setPosition(double x, double y);
private:
    /**
     * Modify the x coordinate.
     *
     * @param x The new x coordinate.
     */
    void setX(double x);
    
    /**
     * Modify the y coordinate.
     *
     * @param y The new y coordinate.
     */
    void setY(double y);

    /// Coordinates of the point.
    double d_x, d_y;
};

#endif
