/**
 * The class which contains the main loop
 * of the graphical application.
 *
 * @author Olivier Delierre
 * @version dev
 */

#ifndef GRAPHICAL_HPP
#define GRAPHICAL_HPP

#include <vector>

#include <SFML/Graphics.hpp>

#include "function.hpp"
#include "camera.hpp"

class graphical {
public:
    /// Default constructor
    graphical();

    /**
     * Run the window and the main loop.
     *
     * @param f The function to draw.
     */
    void run(const function& f);

    /**
     * Update the view of the camera.
     */
    void update_camera();

    /**
     * Modify the scale of the axis.
     *
     * @param scale The new scale.
     */
    void set_scale(double scale);

    /**
     * Convert a camera point to a window point.
     *
     * @param camera_point A camera point to convert.
     */
    point camera_point_to_window_point(const point& camera_point) const;

    /**
     * Generate the vector of points given a function
     * with a precision of 0.01.
     *
     * @param f The function.
     */
    void generate_points(const function& f);

    /**
     * Draw the two axis on the main window.
     */
    void draw_axis();

    /**
     * Draw the function using his points.
     *
     * @param f The function.
     */
    void draw_function(const function& f);
private:
    /// A render window.
    sf::RenderWindow* d_window;
    /// The array of points.
    std::vector<sf::Vertex> d_points;
    sf::Vector2f d_origin;

    /// X-axis.
    sf::RectangleShape d_x_axis;
    /// Y-axis.
    sf::RectangleShape d_y_axis;

    /// Camera.
    camera d_camera;
    /// Scale of axis;
    double d_scale;
};

#endif
