#include "function.hpp"
#include "graphical.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    function f{};
    f.insert_value(-1, 1);

    graphical g;
    g.generate_points(f);
    
    g.run(f);
}
