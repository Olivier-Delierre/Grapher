#ifndef GRAPHICAL_HPP
#define GRAPHICAL_HPP

#include <vector>

#include <SFML/Graphics.hpp>

#include "function.hpp"

class graphical {
public:
    graphical();

    void run(const function& f);
    void generate_points(const function& f);
    void draw_function(const function& f);
private:
    sf::RenderWindow* d_window;
    std::vector<sf::Vertex> d_points;
};

#endif
