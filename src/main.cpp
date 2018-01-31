#include "function.hpp"
#include "graphical.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    function f{};
    f.insert_value(1, 1);
    f.insert_value(12, 2);
    f.insert_value(1, 3);

    
    graphical g;
    g.generate_points(f);
    
    g.run(f);
}
