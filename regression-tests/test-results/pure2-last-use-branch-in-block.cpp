
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-last-use-branch-in-block.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-last-use-branch-in-block.cpp2"
//  A use inside a branch is a last use only on the paths through that branch,
//  so a use before the branch isn't a last use: on the path into the branch,
//  the name is used again. That holds when the branch sits inside a plain
//  block, or after other compound statements, too

#line 6 "pure2-last-use-branch-in-block.cpp2"
auto use(std::shared_ptr<int> p) -> void;

#line 11 "pure2-last-use-branch-in-block.cpp2"
[[nodiscard]] auto is_set(std::shared_ptr<int> p) -> bool;

//  A parameter used in a precondition and then only inside a branch: the
//  function body is a plain block too
auto check_then_use(std::shared_ptr<int> p, cpp2::impl::in<bool> flag) -> void;

#line 25 "pure2-last-use-branch-in-block.cpp2"
//  A forward parameter, used before a block holding a branch
auto forward_then_use(auto&& p, cpp2::impl::in<bool> flag) -> void
CPP2_REQUIRES (std::is_convertible_v<CPP2_TYPEOF(p), std::add_const_t<std::shared_ptr<int>>&>) ;

#line 37 "pure2-last-use-branch-in-block.cpp2"
auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-last-use-branch-in-block.cpp2"

#line 6 "pure2-last-use-branch-in-block.cpp2"
auto use(std::shared_ptr<int> p) -> void
{
    std::cout << "use: " << *cpp2::impl::assert_not_null(cpp2::move(p)) << "\n";
}

#line 11 "pure2-last-use-branch-in-block.cpp2"
[[nodiscard]] auto is_set(std::shared_ptr<int> p) -> bool { return cpp2::move(p) != nullptr;  }

#line 15 "pure2-last-use-branch-in-block.cpp2"
auto check_then_use(std::shared_ptr<int> p, cpp2::impl::in<bool> flag) -> void

#line 18 "pure2-last-use-branch-in-block.cpp2"
{
    if (cpp2::cpp2_default.is_active() && !(is_set(p)) ) { cpp2::cpp2_default.report_violation(""); }
#line 19 "pure2-last-use-branch-in-block.cpp2"
    if (flag) 
    {
        use(cpp2::move(p));
    }
}

#line 26 "pure2-last-use-branch-in-block.cpp2"
auto forward_then_use(auto&& p, cpp2::impl::in<bool> flag) -> void
requires (std::is_convertible_v<CPP2_TYPEOF(p), std::add_const_t<std::shared_ptr<int>>&>) 
#line 27 "pure2-last-use-branch-in-block.cpp2"
{
    use(p);
    {
        if (flag) 
        {
            use(CPP2_FORWARD(p));
        }
    }
}

#line 37 "pure2-last-use-branch-in-block.cpp2"
auto main(int const argc_, char** argv_) -> int
{
    auto const args = cpp2::make_args(argc_, argv_); 
    //  True, but not known to be at compile time
#line 40 "pure2-last-use-branch-in-block.cpp2"
    auto yes {cpp2::impl::cmp_less(CPP2_UFCS(size)(args),100u)}; 
    auto no {!(yes)}; 

    //  The earlier use comes before a block holding an 'if' that is taken,
    //  so moving at the earlier use would leave the branch an empty pointer
    auto a {std::make_shared<int>(1)}; 
    use(a);
    {
        if (yes) 
        {
            use(cpp2::move(a));
        }
    }

    //  ... holding an 'if' and an 'else'
    auto b {std::make_shared<int>(2)}; 
    use(b);
    {
        if (yes) 
        {
            use(cpp2::move(b));
        }
        else 
        {
            use(cpp2::move(b));
        }
    }

    //  ... with the use only in the 'else'
    auto h {std::make_shared<int>(8)}; 
    use(h);
    {
        if (no) 
        {
        }
        else 
        {
            use(cpp2::move(h));
        }
    }

    //  ... in blocks nested twice, after an earlier sibling 'if'
    auto c {std::make_shared<int>(3)}; 
    use(c);
    if (no) 
    {
    }
    {
        {
            if (yes) 
            {
                use(cpp2::move(c));
            }
        }
    }

    //  An earlier loop, then a block holding an 'if' whose condition holds
    //  the last use: walking back from that condition passes the loop body's
    //  end, which used to stop the walk and fail an assertion
    auto m {std::make_shared<int>(11)}; 
    auto n {0}; 
    for( ; cpp2::impl::cmp_less(n,2); ++n ) 
    {
        use(m);
    }
    {
        if (is_set(cpp2::move(m))) 
        {
            std::cout << "m is set\n";
        }
    }

    //  ... with a use in the branch too
    auto d {std::make_shared<int>(4)}; 
    auto i {0}; 
    for( ; cpp2::impl::cmp_less(i,2); ++i ) 
    {
        use(d);
    }
    {
        if (is_set(d)) 
        {
            use(cpp2::move(d));
        }
    }

    //  ... and the same without the block: the walk used to stop at the
    //  loop body's start and take the earlier use for a last one
    auto k {std::make_shared<int>(9)}; 
    use(k);
    auto j {0}; 
    for( ; cpp2::impl::cmp_less(j,1); ++j ) 
    {
        std::cout << "loop\n";
    }
    if (is_set(k)) 
    {
        use(cpp2::move(k));
    }

    //  A capture in the branch
    auto e {std::make_shared<int>(5)}; 
    use(e);
    {
        if (yes) 
        {
            auto f {[_0 = cpp2::move(e)]() mutable -> int { return *cpp2::impl::assert_not_null(_0);  }}; 
            std::cout << "e: " << cpp2::move(f)() << "\n";
        }
    }

    //  The block holds the only use, after the branch: that one is the last
    auto g {std::make_shared<int>(6)}; 
    {
        if (cpp2::move(no)) 
        {
            std::cout << "never\n";
        }
        use(cpp2::move(g));
    }

    check_then_use(std::make_shared<int>(7), yes);
    forward_then_use(std::make_shared<int>(10), cpp2::move(yes));
}

