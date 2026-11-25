
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-last-use-capture-in-branch.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-last-use-capture-in-branch.cpp2"
//  A capture happens when its function expression is evaluated, wherever the
//  captured name appears in the function expression's body. So a capture that
//  appears inside a branch of a later function expression still follows every
//  earlier capture, and only the last capture moves

#line 6 "pure2-last-use-capture-in-branch.cpp2"
auto check(cpp2::impl::in<std::string_view> name, cpp2::impl::in<std::function<int()>> f) -> void;

#line 11 "pure2-last-use-capture-in-branch.cpp2"
auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-last-use-capture-in-branch.cpp2"

#line 6 "pure2-last-use-capture-in-branch.cpp2"
auto check(cpp2::impl::in<std::string_view> name, cpp2::impl::in<std::function<int()>> f) -> void
{
    std::cout << name << ": " << f() << "\n";
}

#line 11 "pure2-last-use-capture-in-branch.cpp2"
auto main(int const argc_, char** argv_) -> int
{
    auto const args = cpp2::make_args(argc_, argv_); 
    //  True, but not known to be at compile time
#line 14 "pure2-last-use-capture-in-branch.cpp2"
    auto yes {cpp2::impl::cmp_less(CPP2_UFCS(size)(args),100u)}; 
    auto no {!(yes)}; 

    //  The later capture is inside an 'if' in its function expression
    auto a {std::make_shared<int>(1)}; 
    auto first_a {[_0 = a]() mutable -> int { return *cpp2::impl::assert_not_null(_0);  }}; 
    auto second_a {[_0 = yes, _1 = cpp2::move(a)]() mutable -> int{if (_0) {return *cpp2::impl::assert_not_null(_1) + 1; }return 0; }}; 
    check("a, first", cpp2::move(first_a));
    check("a, second", cpp2::move(second_a));

    //  ... inside an 'else'
    auto b {std::make_shared<int>(10)}; 
    auto first_b {[_0 = b]() mutable -> int { return *cpp2::impl::assert_not_null(_0);  }}; 
    auto second_b {[_0 = no, _1 = cpp2::move(b)]() mutable -> int{if (_0) {return 0; }else {return *cpp2::impl::assert_not_null(_1) + 1; }}}; 
    check("b, first", cpp2::move(first_b));
    check("b, second", cpp2::move(second_b));

    //  ... inside a nested block
    auto c {std::make_shared<int>(20)}; 
    auto first_c {[_0 = c]() mutable -> int { return *cpp2::impl::assert_not_null(_0);  }}; 
    auto second_c {[_0 = cpp2::move(c)]() mutable -> int{{return *cpp2::impl::assert_not_null(_0) + 1; }}}; 
    check("c, first", cpp2::move(first_c));
    check("c, second", cpp2::move(second_c));

    //  ... and the earlier capture is inside a branch too
    auto d {std::make_shared<int>(30)}; 
    auto first_d {[_0 = yes, _1 = d]() mutable -> int{if (_0) {return *cpp2::impl::assert_not_null(_1); }return 0; }}; 
    auto second_d {[_0 = yes, _1 = cpp2::move(d)]() mutable -> int{if (_0) {return *cpp2::impl::assert_not_null(_1) + 1; }return 0; }}; 
    check("d, first", cpp2::move(first_d));
    check("d, second", cpp2::move(second_d));

    //  ... inside a loop in its function expression
    auto f {std::make_shared<int>(50)}; 
    auto first_f {[_0 = f]() mutable -> int { return *cpp2::impl::assert_not_null(_0);  }}; 
    auto second_f {[_0 = cpp2::move(f)]() mutable -> int{auto sum {0}; auto count {0}; for( ; cpp2::impl::cmp_less(count,2); ++count ) {sum += *cpp2::impl::assert_not_null(_0); }return sum; }}; 
    check("f, first", cpp2::move(first_f));
    check("f, second", cpp2::move(second_f));

    //  An earlier use in a loop of the enclosing function isn't a last use;
    //  the capture after it is
    auto g {std::make_shared<int>(60)}; 
    auto total {0}; 
    auto round {0}; 
    for( ; cpp2::impl::cmp_less(round,2); ++round ) 
    {
        total += *cpp2::impl::assert_not_null(g);
    }
    auto second_g {[_0 = yes, _1 = cpp2::move(g), _2 = cpp2::move(total)]() mutable -> int{if (_0) {return *cpp2::impl::assert_not_null(_1) + _2; }return 0; }}; 
    check("g, after a loop", cpp2::move(second_g));

    //  A function expression in a branch of the enclosing function still
    //  makes a use in that branch, after an earlier capture outside it
    auto e {std::make_shared<int>(40)}; 
    auto first_e {[_0 = e]() mutable -> int { return *cpp2::impl::assert_not_null(_0);  }}; 
    if (cpp2::move(no)) 
    {
        check("e, in a branch", [_0 = cpp2::move(e)]() mutable -> int { return *cpp2::impl::assert_not_null(_0);  });
    }
    else 
    {
        check("e, in the other branch", [_0 = cpp2::move(yes), _1 = cpp2::move(e)]() mutable -> int{if (_0) {return *cpp2::impl::assert_not_null(_1) + 1; }return 0; });
    }
    check("e, first", cpp2::move(first_e));
}

