
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-finally-moved-from.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-finally-moved-from.cpp2"
//  Moving a cpp2::finally hands its action to the new object; the moved-from
//  one must not run it again when it is destroyed

#line 4 "pure2-finally-moved-from.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-finally-moved-from.cpp2"

#line 4 "pure2-finally-moved-from.cpp2"
auto main() -> int
{
    {
        auto first {cpp2::finally([]() -> decltype(auto) { return std::cout << "action ran\n";  })}; 
        auto second {cpp2::move(first)}; // the last use of first, so this moves it
        static_cast<void>(cpp2::move(second));
        std::cout << "leaving the scope\n";
    }
    std::cout << "left the scope\n";
}

