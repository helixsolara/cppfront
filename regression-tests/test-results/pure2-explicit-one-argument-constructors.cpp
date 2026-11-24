
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-explicit-one-argument-constructors.cpp2"

#line 4 "pure2-explicit-one-argument-constructors.cpp2"
class widget;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-explicit-one-argument-constructors.cpp2"
//  A one-argument constructor is explicit unless its 'this' is 'implicit'
//  (docs/cpp2/types.md, "implicit")

#line 4 "pure2-explicit-one-argument-constructors.cpp2"
class widget
 {
    public: int value {0}; 

    public: explicit widget();
    public: explicit widget(cpp2::impl::in<int> v);
#line 9 "pure2-explicit-one-argument-constructors.cpp2"
    public: auto operator=(cpp2::impl::in<int> v) -> widget& ;
    public: widget(cpp2::impl::in<std::string_view> s);
#line 10 "pure2-explicit-one-argument-constructors.cpp2"
    public: auto operator=(cpp2::impl::in<std::string_view> s) -> widget& ;
    public: widget(cpp2::impl::in<int> a, cpp2::impl::in<int> b);
    public: widget(widget const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(widget const&) -> void = delete;

#line 12 "pure2-explicit-one-argument-constructors.cpp2"
};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-explicit-one-argument-constructors.cpp2"

#line 8 "pure2-explicit-one-argument-constructors.cpp2"
    widget::widget(){}
#line 9 "pure2-explicit-one-argument-constructors.cpp2"
    widget::widget(cpp2::impl::in<int> v)
                                      : value{ v }{}
#line 9 "pure2-explicit-one-argument-constructors.cpp2"
    auto widget::operator=(cpp2::impl::in<int> v) -> widget& {
                                      value = v;
                                      return *this; }
#line 10 "pure2-explicit-one-argument-constructors.cpp2"
    widget::widget(cpp2::impl::in<std::string_view> s)
                                                            : value{ cpp2::unchecked_narrow<int>(CPP2_UFCS_NONLOCAL(ssize)(s)) }{}
#line 10 "pure2-explicit-one-argument-constructors.cpp2"
    auto widget::operator=(cpp2::impl::in<std::string_view> s) -> widget& {
                                                            value = cpp2::unchecked_narrow<int>(CPP2_UFCS_NONLOCAL(ssize)(s));
                                                            return *this; }
#line 11 "pure2-explicit-one-argument-constructors.cpp2"
    widget::widget(cpp2::impl::in<int> a, cpp2::impl::in<int> b)
                                              : value{ a + b }{}

#line 14 "pure2-explicit-one-argument-constructors.cpp2"
auto main() -> int
{
    std::cout << "converts from int: " + cpp2::to_string(std::is_convertible_v<int,widget>) + "\n";
    std::cout << "converts from std::string_view: " + cpp2::to_string(std::is_convertible_v<std::string_view,widget>) + "\n";
    std::cout << "constructible from int: " + cpp2::to_string(std::is_constructible_v<widget,int>) + "\n";

    widget w {7}; 
    std::cout << "direct initialization: " + cpp2::to_string(cpp2::move(w).value) + "\n";
}

