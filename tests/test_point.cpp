#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../src/geometry/point.hpp"

bool coordinates_are(const point& p, double x, double y) {
    return ( p.x() == x ) && ( p.y() == y );
}

TEST_CASE("Testing the construction of points") {
    SUBCASE("Constructor with params") {
        double x{ 2.0 };
        double y{ 3.0 };
        point p{ x, y };

        REQUIRE(coordinates_are(p, x, y));
    }

    SUBCASE("Constructor without params") {
        double default_x{ 0.0 };
        double default_y{ 0.0 };
        point p{};

        REQUIRE(coordinates_are(p, default_x, default_y));
    }

    SUBCASE("Recopy constructor") {
        double x{ 2.0 };
        double y{ 2.5 };
        point p{ x, y };
        point p2{ p };

        REQUIRE(coordinates_are(p2, x, y));
    }
}

TEST_CASE("Setter are okay") {
    double x{ 5.0 };
    double y{ 10.0 };
    point p{};

    p.setPosition(x, y);
    
    REQUIRE(coordinates_are(p, x, y));
}
