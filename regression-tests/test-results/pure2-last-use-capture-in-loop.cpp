
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-last-use-capture-in-loop.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-last-use-capture-in-loop.cpp2"
//  A use inside a loop isn't a last use, since the loop may run it again. That
//  holds for a capture too: a function expression written inside a loop is
//  evaluated on every iteration, so its capture copies

#line 5 "pure2-last-use-capture-in-loop.cpp2"
auto print(std::shared_ptr<int> p) -> void;

#line 10 "pure2-last-use-capture-in-loop.cpp2"
auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-last-use-capture-in-loop.cpp2"

#line 5 "pure2-last-use-capture-in-loop.cpp2"
auto print(std::shared_ptr<int> p) -> void
{
    std::cout << "print: " << *cpp2::impl::assert_not_null(cpp2::move(p)) << "\n";
}

#line 10 "pure2-last-use-capture-in-loop.cpp2"
auto main(int const argc_, char** argv_) -> int
{
    auto const args = cpp2::make_args(argc_, argv_); 
    //  True, but not known to be at compile time
#line 13 "pure2-last-use-capture-in-loop.cpp2"
    auto yes {cpp2::impl::cmp_less(CPP2_UFCS(size)(args),100u)}; 

    //  A function expression in a 'while' body
    auto a {std::make_shared<int>(1)}; 
    auto i {0}; 
    for( ; cpp2::impl::cmp_less(i,3); ++i ) 
    {
        auto f {[_0 = a, _1 = i]() mutable -> int { return *cpp2::impl::assert_not_null(_0) + _1;  }}; 
        std::cout << "a: " << cpp2::move(f)() << "\n";
    }

    //  ... in a 'for' body
    auto b {std::make_shared<int>(10)}; 
    for ( auto const& n : { 1, 2 } ) 
    {
        auto f {[_0 = b, _1 = n]() mutable -> int { return *cpp2::impl::assert_not_null(_0) + _1;  }}; 
        std::cout << "b: " << cpp2::move(f)() << "\n";
    }

    //  ... in a 'do' body, with the capture in a branch of its own body
    auto c {std::make_shared<int>(20)}; 
    auto j {0}; 
    do 
    {
        auto f {[_0 = yes, _1 = c, _2 = j]() mutable -> int{if (_0) {return *cpp2::impl::assert_not_null(_1) + _2; }return 0; }}; 
        std::cout << "c: " << cpp2::move(f)() << "\n";
    } while ( [&]{ 
    ++j ; return true; }() && 
    cpp2::impl::cmp_less(j,2));

    //  ... in a branch inside a loop
    auto d {std::make_shared<int>(30)}; 
    auto k {0}; 
    for( ; cpp2::impl::cmp_less(k,2); ++k ) 
    {
        if (yes) 
        {
            auto f {[_0 = d, _1 = k]() mutable -> int { return *cpp2::impl::assert_not_null(_0) + _1;  }}; 
            std::cout << "d: " << cpp2::move(f)() << "\n";
        }
    }

    //  A function expression inside another one, in a loop (the inner one
    //  captures the outer one's copy, since C++ can't capture through it)
    auto e {std::make_shared<int>(40)}; 
    auto m {0}; 
    for( ; cpp2::impl::cmp_less(m,2); ++m ) 
    {
        auto f {[_0 = e, _1 = m]() mutable -> int{auto y {_0}; auto g {[_0 = cpp2::move(y)]() mutable -> int { return *cpp2::impl::assert_not_null(_0);  }}; return cpp2::move(g)() + _1; }}; 
        std::cout << "e: " << cpp2::move(f)() << "\n";
    }

    //  A plain use in a loop that also holds an unrelated function expression
    auto p {std::make_shared<int>(60)}; 
    auto q {0}; 
    for( ; cpp2::impl::cmp_less(q,2); ++q ) 
    {
        print(p);
        auto one {[]() -> int { return 1;  }}; 
        static_cast<void>(cpp2::move(one)());
    }

    //  ... and one that also holds a name hiding the local
    auto r {std::make_shared<int>(70)}; 
    auto s {0}; 
    for( ; cpp2::impl::cmp_less(s,2); ++s ) 
    {
        print(r);
        {
            auto r {std::make_shared<int>(-1)}; 
            print(cpp2::move(r));
        }
    }

    //  A function expression in the loop's condition
    auto t {std::make_shared<int>(2)}; 
    auto u {0}; 
    for( ; [_0 = u, _1 = t]() mutable -> bool { return cpp2::impl::cmp_less(_0,*cpp2::impl::assert_not_null(_1));  }(); ++u ) 
    {
        std::cout << "t: " << u << "\n";
    }

    //  Outside a loop, the last capture still moves
    auto z {std::make_shared<int>(50)}; 
    auto first {[_0 = z]() mutable -> int { return *cpp2::impl::assert_not_null(_0);  }}; 
    auto last {[_0 = cpp2::move(z)]() mutable -> int { return *cpp2::impl::assert_not_null(_0) + 1;  }}; 
    std::cout << "z: " << cpp2::move(first)() << " " << cpp2::move(last)() << "\n";
}

