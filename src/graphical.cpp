#include "graphical.hpp"

#define FRAMERATE_LIMIT 60
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 600
#define DEFAULT_SCALE 5

graphical::graphical() :
    d_points(),
    
    d_origin(WINDOW_WIDTH / 2.0, WINDOW_HEIGHT / 2.0),
    d_x_axis(sf::Vector2f(WINDOW_WIDTH, 1)),
    d_y_axis(sf::Vector2f(1, WINDOW_HEIGHT)),

    d_camera{ point{0,0}, point{0,0} },
    d_scale{ 1 } 
{
    d_window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Grapher");
    d_window->setFramerateLimit(FRAMERATE_LIMIT);
       
    update_camera(); 

    d_x_axis.setPosition(sf::Vector2f(0, d_origin.y));
    d_x_axis.setFillColor(sf::Color::Red);

    d_y_axis.setPosition(sf::Vector2f(d_origin.x, 0));
    d_y_axis.setFillColor(sf::Color::Red);
}

void graphical::run(const function& f) {
    std::cout << "Drawing function " << f << std::endl;
    while (d_window->isOpen()) {
        sf::Event event;

        while (d_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                d_window->close();
        }
        
        d_window->clear(sf::Color(255, 255, 255));
        draw_axis();
        draw_function(f);
        d_window->display();
    }
}

void graphical::update_camera() {
    double min_x = (-WINDOW_WIDTH / 2.0) / d_scale;
    double max_x = (WINDOW_WIDTH / 2.0) / d_scale;

    double min_y = (-WINDOW_HEIGHT / 2.0) / d_scale;
    double max_y = (WINDOW_HEIGHT / 2.0) / d_scale;

    d_camera.setView(point{min_x, max_y}, point{max_x, min_y});
}

void graphical::set_scale(double scale) {
    d_scale = scale;
    update_camera();
}

point graphical::camera_point_to_window_point(const point& camera_point) const {
    double x = camera_point.x() - d_camera.top_left_corner().x();
    double y = camera_point.y() - d_camera.bottom_right_corner().y(); 
    std::cout << "VIEW: " << d_camera.top_left_corner().x() << "  " << d_camera.top_left_corner().y() << std::endl;
    std::cout << "(" << camera_point.x() << "," << camera_point.y() << ")    "; std::cout << "(" << x << "," << y << ")" << std::endl;
    return point{x, y};
}

void graphical::generate_points(const function& f) {
    double min_x = d_camera.top_left_corner().x();
    double max_x = d_camera.bottom_right_corner().x();

    double min_y = d_camera.bottom_right_corner().y();
    double max_y = d_camera.top_left_corner().y();
    
    float incremental_step = 0.01;

    point camera_point{};

    for (double x = min_x; x <= max_x; x++) {
        for (double step = 0.0; step < 1; step += incremental_step) {
            if (f.resolve(x + step) > min_y && f.resolve(x + step) < max_y) {
                camera_point.setPosition(x + step, f.resolve(x + step));
                camera_point = camera_point_to_window_point(camera_point);
                
                d_points.push_back(sf::Vertex(sf::Vector2f(
                                        camera_point.x(), 
                                        camera_point.y()), 
                                        sf::Color(0, 0, 0))
                );
            }
        }
    }
}

void graphical::draw_axis() {
    d_window->draw(d_x_axis);
    d_window->draw(d_y_axis);
}

void graphical::draw_function(const function& f) {
    d_window->draw(&d_points[0], d_points.size(), sf::Points);
}
