
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-deref-call.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-deref-call.cpp2"
//  A postfix * followed by ( is taken for multiplication, as in a*(b),
//  but nothing is multiplied by an empty (): f*() dereferences f and calls
//  what it points to, and so does a captured pointer's p$*()

#line 5 "pure2-deref-call.cpp2"
[[nodiscard]] auto call_through(cpp2::impl::in<std::function<int()>*> f) -> int;

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-deref-call.cpp2"

#line 5 "pure2-deref-call.cpp2"
[[nodiscard]] auto call_through(cpp2::impl::in<std::function<int()>*> f) -> int { return (*cpp2::impl::assert_not_null(f))();  }

#line 7 "pure2-deref-call.cpp2"
auto main() -> int
{
    std::function<int()> g {[]() -> int{return 42; }}; 
    std::cout << "through a parameter: " << call_through(&g) << "\n";

    auto h {&g}; 
    auto k {[_0 = cpp2::move(h)]() mutable -> int{return (*cpp2::impl::assert_not_null(_0))(); }}; 
    std::cout << "through a capture: " << cpp2::move(k)() << "\n";

    auto p {std::make_unique<std::function<int()>>([]() -> int{return 7; })}; 
    std::cout << "through a smart pointer: " << (*cpp2::impl::assert_not_null(cpp2::move(p)))() << "\n";

    //  With something in the parentheses it is still multiplication
    auto a {6}; 
    auto b {7}; 
    std::cout << "multiplication: " << cpp2::move(a) * (cpp2::move(b)) << "\n";
}

