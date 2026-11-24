
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-macro-arguments-with-commas.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-macro-arguments-with-commas.cpp2"
//  The safety checks cppfront wraps around divisions and subscripts are macros.
//  An argument with a template argument list holds a comma outside parentheses,
//  which must not split it into two macro arguments.

#line 5 "pure2-macro-arguments-with-commas.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-macro-arguments-with-commas.cpp2"

#line 5 "pure2-macro-arguments-with-commas.cpp2"
auto main() -> int
{
    std::vector<int> v {10, 20, 30}; 

    //  The divisor has a template comma
    std::cout << 100 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(100),std::common_type_t<int,long>(4)) << "\n";

    //  So does the subscript
    std::cout << CPP2_ASSERT_IN_BOUNDS((cpp2::move(v)), std::common_type_t<int,short>(1)) << "\n";

    //  And the subscripted expression
    std::cout << CPP2_ASSERT_IN_BOUNDS_LITERAL((std::array<int,3>()), 2) << "\n";

    //  A numerator whose type has a template comma, divided in place
    std::common_type_t<int,long> x {50}; 
    x /= CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x),std::common_type_t<int,short>(5));
    std::cout << cpp2::move(x) << "\n";
}

