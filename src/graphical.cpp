#include "graphical.hpp"

#define FRAMERATE_LIMIT 60
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 600

graphical::graphical() :
    d_points()
{
    d_window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Grapher");
    d_window->setFramerateLimit(FRAMERATE_LIMIT);
}

void graphical::run(const function& f) {
    while (d_window->isOpen()) {
        sf::Event event;

        while (d_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                d_window->close();
        }
        
        d_window->clear(sf::Color(255, 255, 255));
        draw_function(f);
        d_window->display();
    }
}

void graphical::generate_points(const function& f) {
    unsigned int window_height{ d_window->getSize().y };
    unsigned int window_width{ d_window->getSize().x };

    
    for (unsigned int i = 0; i < window_width; i++) {
        for (double j = 0.01; j <= 0.99; j += 0.01) {
            if (f.resolve(window_height - i) > 0) {
                d_points.push_back(sf::Vertex(sf::Vector2f(i + j, window_height - f.resolve(i + j)), sf::Color(0, 0, 0)));
            }
        }
    }
}

void graphical::draw_function(const function& f) {
    d_window->draw(&d_points[0], d_points.size(), sf::Points);
}
