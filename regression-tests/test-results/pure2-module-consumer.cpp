
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-module-consumer.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-module-consumer.cpp2"
//  Imports the 'shapes' module built from the pure2-module-*.cpp2 units
//  and uses each kind of exported declaration.

import shapes;

#line 6 "pure2-module-consumer.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-module-consumer.cpp2"

#line 6 "pure2-module-consumer.cpp2"
auto main() -> int{
    rectangle r {3.0, -4.0}; 
    std::cout << "area (negative side clamped): " + cpp2::to_string(CPP2_UFCS(area)(cpp2::move(r))) + "\n";
    std::cout << "square area: " + cpp2::to_string(square_area(5.0)) + "\n";
    std::cout << "sides of a square: " + cpp2::to_string(sides_of_square) + "\n";
    std::cout << "larger: " + cpp2::to_string(larger(3, 7)) + " " + cpp2::to_string(larger(std::string("pear"), std::string("apple"))) + "\n";

    labeled<int> item {"count", 42}; 
    std::cout << "labeled: " + cpp2::to_string(item.label) + " = " + cpp2::to_string(item.value) + "\n";

    std::cout << "inches in 3 feet: " + cpp2::to_string(units::to_inches(3)) + "\n";

    auto c {color::green}; 
    std::cout << "color: " + cpp2::to_string(CPP2_UFCS(to_string)(cpp2::move(c))) + "\n";

    point a {0.0, 0.0}; 
    point b {3.0, 4.0}; 
    std::cout << "distance squared: " + cpp2::to_string(distance_squared(cpp2::move(a), cpp2::move(b))) + "\n";

    text::string_view name {"shapes"}; 
    std::cout << "module: " + cpp2::to_string(cpp2::move(name)) + "\n";
}

