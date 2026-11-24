
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-stdio-with-raii.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-stdio-with-raii.cpp2"

//  "A better C than C" ... ?
//
#line 4 "pure2-stdio-with-raii.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-stdio-with-raii.cpp2"

#line 4 "pure2-stdio-with-raii.cpp2"
[[nodiscard]] auto main() -> int{
    std::string s {"Fred"}; 
    auto myfile {cpp2::fopen("xyzzy", "w")}; 
    static_cast<void>(CPP2_UFCS_ARGS((, auto&& cpp2_ufcs_a0), (fprintf), "Hello %s with UFCS!", CPP2_FORWARD(cpp2_ufcs_a0))(cpp2::move(myfile), CPP2_UFCS(c_str)(cpp2::move(s))));
}

