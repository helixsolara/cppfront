
//  A module unit with an explicit global module fragment: 'module;'
//  followed by #includes. cppfront puts its own prolog after the
//  user's 'module;' instead of emitting one of its own.

module;

#include "cpp2util.h"

#include <cstdio>
export module mixed_fragment;

//=== Cpp2 type declarations ====================================================

#line 1 "mixed-module-global-fragment.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-module-global-fragment.cpp2"

#line 9 "mixed-module-global-fragment.cpp2"
export [[nodiscard]] auto twice(cpp2::impl::in<int> x) -> int;

export void print_twice(int x) { std::printf("%d\n", twice(x)); }


//=== Cpp2 function definitions =================================================

#line 1 "mixed-module-global-fragment.cpp2"

#line 9 "mixed-module-global-fragment.cpp2"
[[nodiscard]] auto twice(cpp2::impl::in<int> x) -> int { return 2 * x;  }

