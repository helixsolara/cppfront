
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-ufcs-constant-arguments.cpp2"

#line 5 "pure2-ufcs-constant-arguments.cpp2"
class printer;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-ufcs-constant-arguments.cpp2"
//  A string literal passed through UFCS (x.f("...")) stays a constant
//  expression, so it can initialize a parameter that must be one, such as a
//  std::format_string

#line 5 "pure2-ufcs-constant-arguments.cpp2"
class printer
 {
    public: template<typename ...Args> [[nodiscard]] auto print(std::format_string<Args...> const& pattern, Args const& ...args) const& -> decltype(auto);

#line 10 "pure2-ufcs-constant-arguments.cpp2"
    public: template<typename T> [[nodiscard]] auto print_as(std::format_string<T> const& pattern, T const& value) const& -> decltype(auto);

#line 13 "pure2-ufcs-constant-arguments.cpp2"
    //  A pack forwarded with a literal pattern
    public: template<typename ...Args> auto print_pair(Args const& ...args) const& -> void;

    //  A pack followed by another argument
    public: [[nodiscard]] auto cat(cpp2::impl::in<std::string> a, cpp2::impl::in<std::string> b, cpp2::impl::in<std::string> c) const& -> std::string;
    public: [[nodiscard]] auto cat(cpp2::impl::in<std::string> a, cpp2::impl::in<std::string> b, cpp2::impl::in<std::string> c, cpp2::impl::in<std::string> d) const& -> std::string;
    public: template<typename ...Args> [[nodiscard]] auto cat_all(cpp2::impl::in<std::string> last, Args const& ...args) const& -> std::string;
    public: printer() = default;
    public: printer(printer const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(printer const&) -> void = delete;

#line 20 "pure2-ufcs-constant-arguments.cpp2"
};

//  A non-member, reached through UFCS when printer has no such member
template<typename ...Args> auto shout(cpp2::impl::in<printer> p, std::format_string<Args...> const& pattern, Args const& ...args) -> void;

#line 29 "pure2-ufcs-constant-arguments.cpp2"
//  (A qualified call, p.ns::f<T>("..."), takes the same path, but GCC rejects
//  UFCS to a qualified non-member with or without this change, so it isn't
//  tested here)

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-ufcs-constant-arguments.cpp2"

#line 7 "pure2-ufcs-constant-arguments.cpp2"
    template<typename ...Args> [[nodiscard]] auto printer::print(std::format_string<Args...> const& pattern, Args const& ...args) const& -> decltype(auto) { 
        return std::cout << std::vformat(CPP2_UFCS(get)(pattern), std::make_format_args(args...)) << "\n";  }

#line 10 "pure2-ufcs-constant-arguments.cpp2"
    template<typename T> [[nodiscard]] auto printer::print_as(std::format_string<T> const& pattern, T const& value) const& -> decltype(auto) { 
        return std::cout << std::vformat(CPP2_UFCS(get)(pattern), std::make_format_args(value)) << "\n";  }

#line 14 "pure2-ufcs-constant-arguments.cpp2"
    template<typename ...Args> auto printer::print_pair(Args const& ...args) const& -> void{static_cast<void>(CPP2_UFCS_ARGS((, auto&&... cpp2_ufcs_rest), (print), "{} and {}", CPP2_FORWARD(cpp2_ufcs_rest)...)((*this), args...)); }

#line 17 "pure2-ufcs-constant-arguments.cpp2"
    [[nodiscard]] auto printer::cat(cpp2::impl::in<std::string> a, cpp2::impl::in<std::string> b, cpp2::impl::in<std::string> c) const& -> std::string { return a + b + c;  }
#line 18 "pure2-ufcs-constant-arguments.cpp2"
    [[nodiscard]] auto printer::cat(cpp2::impl::in<std::string> a, cpp2::impl::in<std::string> b, cpp2::impl::in<std::string> c, cpp2::impl::in<std::string> d) const& -> std::string { return a + b + c + d;  }
#line 19 "pure2-ufcs-constant-arguments.cpp2"
    template<typename ...Args> [[nodiscard]] auto printer::cat_all(cpp2::impl::in<std::string> last, Args const& ...args) const& -> std::string { return CPP2_UFCS(cat)((*this), "lit", args..., last);  }

#line 23 "pure2-ufcs-constant-arguments.cpp2"
template<typename ...Args> auto shout(cpp2::impl::in<printer> p, std::format_string<Args...> const& pattern, Args const& ...args) -> void
{
    static_cast<void>(p);
    std::cout << std::vformat(CPP2_UFCS(get)(pattern), std::make_format_args(args...)) << "!\n";
}

#line 33 "pure2-ufcs-constant-arguments.cpp2"
auto main() -> int
{
    printer p {}; 
    auto count {3}; 
    CPP2_UFCS_ARGS((, auto&& cpp2_ufcs_a0, auto&& cpp2_ufcs_a1, auto&& cpp2_ufcs_a2), (print), "{} + {} = {}", CPP2_FORWARD(cpp2_ufcs_a0), CPP2_FORWARD(cpp2_ufcs_a1), CPP2_FORWARD(cpp2_ufcs_a2))(p, 1, 2, 3);//  a member, with a literal pattern
    CPP2_UFCS_ARGS((), (shout), "{} through UFCS", "non-member")(p);//  a non-member
    CPP2_UFCS_TEMPLATE_ARGS((, auto&& cpp2_ufcs_a0), (print_as<int>), "as an int: {}", CPP2_FORWARD(cpp2_ufcs_a0))(p, 42);//  with template arguments
    CPP2_UFCS_ARGS((, auto&& cpp2_ufcs_a0), (print_pair), CPP2_FORWARD(cpp2_ufcs_a0), "two")(p, 1);//  a pack with a literal pattern
    std::cout << CPP2_UFCS_ARGS((, auto&& cpp2_ufcs_a0, auto&& cpp2_ufcs_a1), (cat_all), "LAST", CPP2_FORWARD(cpp2_ufcs_a0), CPP2_FORWARD(cpp2_ufcs_a1))(p, std::string("mid1"), std::string("mid2")) << "\n";
    CPP2_UFCS_ARGS((, auto&& cpp2_ufcs_a0), (print), "count is {}", CPP2_FORWARD(cpp2_ufcs_a0))(p, cpp2::move(count));//  a literal with a last-use argument
    static_cast<void>(cpp2::move(p));

    //  A UFCS call with a literal inside another's arguments
    std::string s {"hello world"}; 
    std::string t {"lo"}; 
    std::cout << CPP2_UFCS_ARGS((, auto&& cpp2_ufcs_a0), (find), "o", CPP2_FORWARD(cpp2_ufcs_a0))(cpp2::move(s), CPP2_UFCS_ARGS((), (find), "o")(cpp2::move(t))) << "\n";
}

