
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-module-private-fragment-consumer.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-module-private-fragment-consumer.cpp2"
//  Uses the module 'greeter' (pure2-module-private-fragment.cpp2), whose
//  function bodies are in its private module fragment, except those of
//  templates
import greeter;

#line 6 "pure2-module-private-fragment-consumer.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-module-private-fragment-consumer.cpp2"

#line 6 "pure2-module-private-fragment-consumer.cpp2"
auto main() -> int
{
    std::cout << greeting("module") << "\n";
    announce("a void function");
    std::cout << twice(21) << "\n";
    std::cout << length(std::string("forwarded")) << "\n";
    std::cout << sum(1, 2, 3) << "\n";
    counter c {10}; 
    static_cast<void>(CPP2_UFCS(increment)(c));
    std::cout << CPP2_UFCS(increment)(c) << "\n";
    static_cast<void>(cpp2::move(c));
}

