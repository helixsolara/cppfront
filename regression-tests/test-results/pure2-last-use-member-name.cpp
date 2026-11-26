
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-last-use-member-name.cpp2"

#line 14 "pure2-last-use-member-name.cpp2"
class point;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-last-use-member-name.cpp2"
//  A member access whose member is named like a local in scope (r.x with a
//  local x) may be a UFCS call, x(r), until the next token shows it isn't.
//  That token starts what comes next, and still counts as a use when it
//  names a local: here v, whose use in v.size() right after r.x makes
//  take(v) not its last use, so v isn't moved there

#line 7 "pure2-last-use-member-name.cpp2"
[[nodiscard]] auto take(std::string s) -> std::size_t;

auto show(cpp2::impl::in<std::string_view> label, cpp2::impl::in<int> a, cpp2::impl::in<std::size_t> b, cpp2::impl::in<std::size_t> c) -> void;

#line 14 "pure2-last-use-member-name.cpp2"
class point {public: int x {1}; public: int y {2}; 
public: point(auto&& x_, auto&& y_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(x_), std::add_const_t<int>&> && std::is_convertible_v<CPP2_TYPEOF(y_), std::add_const_t<int>&>) ;
public: point();
};
#line 15 "pure2-last-use-member-name.cpp2"

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-last-use-member-name.cpp2"

#line 7 "pure2-last-use-member-name.cpp2"
[[nodiscard]] auto take(std::string s) -> std::size_t { return CPP2_UFCS(size)(cpp2::move(s));  }

#line 9 "pure2-last-use-member-name.cpp2"
auto show(cpp2::impl::in<std::string_view> label, cpp2::impl::in<int> a, cpp2::impl::in<std::size_t> b, cpp2::impl::in<std::size_t> c) -> void
{
    std::cout << label << ": " << a << " " << b << " " << c << "\n";
}

point::point(auto&& x_, auto&& y_)
requires (std::is_convertible_v<CPP2_TYPEOF(x_), std::add_const_t<int>&> && std::is_convertible_v<CPP2_TYPEOF(y_), std::add_const_t<int>&>) 
                                                                             : x{ CPP2_FORWARD(x_) }
                                                                             , y{ CPP2_FORWARD(y_) }{}
point::point(){}

#line 16 "pure2-last-use-member-name.cpp2"
auto main() -> int
{
    //  A member named like a local, then at once a use of another local
    std::string v {"hello"}; 
    point r {}; 
    auto n {take(v)}; 
    auto x {r.x}; 
    auto size {cpp2::move(v).size()}; 
    show("next statement", cpp2::move(x), size, cpp2::move(n));

    //  ... the member and the use as two arguments of one call
    std::string w {"world!"}; 
    auto m {take(w)}; 
    show("next argument", cpp2::move(r).x, CPP2_UFCS_MOVE(size)(cpp2::move(w)), cpp2::move(m));
}

