#include "function.hpp"
#include "graphical.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    function f{};
    f.insert_value(-0.1, 2);
    
    graphical g;
    g.generate_points(f);
    
    g.run(f);
}
