
module;
#define CPP2_INCLUDE_STD         Yes

#include "cpp2util.h"

//  Module internal partition: 'module name:partition;'
//  Nothing here is exported; the primary interface imports it
//  with 'import :detail;' and uses it in its own definitions.

module shapes:detail;

//=== Cpp2 type declarations ====================================================

#line 1 "pure2-module-internal-partition.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-module-internal-partition.cpp2"

#line 7 "pure2-module-internal-partition.cpp2"
[[nodiscard]] auto clamp_to_zero(cpp2::impl::in<double> v) -> double;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-module-internal-partition.cpp2"

#line 7 "pure2-module-internal-partition.cpp2"
[[nodiscard]] auto clamp_to_zero(cpp2::impl::in<double> v) -> double{
    if (cpp2::impl::cmp_less(v,0.0)) {
        return 0.0; 
    }
    return v; 
}

