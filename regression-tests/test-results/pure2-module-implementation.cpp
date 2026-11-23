
module;
#define CPP2_INCLUDE_STD         Yes

#include "cpp2util.h"

//  Module implementation unit: 'module name;'
//  It implicitly imports the primary interface, so it can use its
//  declarations, including the non-exported ones.

module shapes;

//=== Cpp2 type declarations ====================================================

#line 1 "pure2-module-implementation.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-module-implementation.cpp2"

#line 7 "pure2-module-implementation.cpp2"
[[nodiscard]] auto perimeter(cpp2::impl::in<rectangle> r) -> length;

[[nodiscard]] auto diagonal_squared(cpp2::impl::in<rectangle> r) -> length;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-module-implementation.cpp2"

#line 7 "pure2-module-implementation.cpp2"
[[nodiscard]] auto perimeter(cpp2::impl::in<rectangle> r) -> length { return 2.0 * (r.width + r.height);  }

#line 9 "pure2-module-implementation.cpp2"
[[nodiscard]] auto diagonal_squared(cpp2::impl::in<rectangle> r) -> length { return square(r.width) + square(r.height);  }

