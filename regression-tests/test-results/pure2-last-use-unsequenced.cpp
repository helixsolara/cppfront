
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-last-use-unsequenced.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-last-use-unsequenced.cpp2"
//  The arguments of one call are evaluated in no set order (MSVC goes right
//  to left), and so are the operands of most operators, so a name used in
//  two of them isn't moved at either: the other may see it already moved.
//  The same holds for two function expressions capturing the name in one
//  expression, and for a capture beside a plain use

#line 7 "pure2-last-use-unsequenced.cpp2"
[[nodiscard]] auto pair(std::shared_ptr<int> a, std::shared_ptr<int> b) -> int;

[[nodiscard]] auto two(cpp2::impl::in<std::function<int()>> f, cpp2::impl::in<std::function<int()>> g) -> int;

[[nodiscard]] auto mixed(std::shared_ptr<int> a, cpp2::impl::in<std::function<int()>> g) -> int;

[[nodiscard]] auto value(std::shared_ptr<int> a) -> int;

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-last-use-unsequenced.cpp2"

#line 7 "pure2-last-use-unsequenced.cpp2"
[[nodiscard]] auto pair(std::shared_ptr<int> a, std::shared_ptr<int> b) -> int { return *cpp2::impl::assert_not_null(cpp2::move(a)) + *cpp2::impl::assert_not_null(cpp2::move(b));  }

#line 9 "pure2-last-use-unsequenced.cpp2"
[[nodiscard]] auto two(cpp2::impl::in<std::function<int()>> f, cpp2::impl::in<std::function<int()>> g) -> int { return f() + g();  }

#line 11 "pure2-last-use-unsequenced.cpp2"
[[nodiscard]] auto mixed(std::shared_ptr<int> a, cpp2::impl::in<std::function<int()>> g) -> int { return *cpp2::impl::assert_not_null(cpp2::move(a)) + g();  }

#line 13 "pure2-last-use-unsequenced.cpp2"
[[nodiscard]] auto value(std::shared_ptr<int> a) -> int { return *cpp2::impl::assert_not_null(cpp2::move(a));  }

#line 15 "pure2-last-use-unsequenced.cpp2"
auto main() -> int
{
    //  The same name in two arguments of one call
    auto p {std::make_shared<int>(1)}; 
    std::cout << "pair: " << pair(p, p) << "\n";

    //  ... in an argument of a nested call
    auto n {std::make_shared<int>(2)}; 
    std::cout << "nested: " << pair(n, std::make_shared<int>(value(n))) << "\n";

    //  Two function expressions capturing it, in two arguments
    auto q {std::make_shared<int>(3)}; 
    std::cout << "two captures: " << two([_0 = q]() mutable -> int { return *cpp2::impl::assert_not_null(_0);  }, [_0 = q]() mutable -> int { return *cpp2::impl::assert_not_null(_0);  }) << "\n";

    //  A plain use beside a capture
    auto r {std::make_shared<int>(4)}; 
    std::cout << "mixed: " << mixed(r, [_0 = r]() mutable -> int { return *cpp2::impl::assert_not_null(_0);  }) << "\n";

    //  Still moved: a single use in a call, and two captures in one closure
    auto s {std::make_shared<int>(5)}; 
    std::cout << "single: " << pair(std::make_shared<int>(0), cpp2::move(s)) << "\n";
    auto u {std::make_shared<int>(6)}; 
    auto one {[_0 = cpp2::move(u)]() mutable -> int { return *cpp2::impl::assert_not_null(_0) + *cpp2::impl::assert_not_null(_0);  }}; 
    std::cout << "one closure: " << cpp2::move(one)() << "\n";
}

