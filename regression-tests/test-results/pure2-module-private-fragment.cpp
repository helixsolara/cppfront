
module;
#define CPP2_INCLUDE_STD         Yes

#include "cpp2util.h"

export module greeter;

//=== Cpp2 type declarations ====================================================

#line 1 "pure2-module-private-fragment.cpp2"

#line 31 "pure2-module-private-fragment.cpp2"
export class counter;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-module-private-fragment.cpp2"
#line 2 "pure2-module-private-fragment.cpp2"

//  'module :private;' starts the private module fragment. Cpp2 writes each
//  function once, with its body, so cppfront keeps every declaration in the
//  module's interface and puts after this line the function bodies importers
//  don't need. Where the line is written doesn't matter

#line 9 "pure2-module-private-fragment.cpp2"
export [[nodiscard]] auto greeting(cpp2::impl::in<std::string_view> name) -> std::string;

#line 15 "pure2-module-private-fragment.cpp2"
//  Not exported: only this module calls it
[[nodiscard]] auto suffix() -> std::string;

//  No '->' and a { } body: returns void, so its body can be private too
export auto announce(cpp2::impl::in<std::string_view> what) -> void;

#line 24 "pure2-module-private-fragment.cpp2"
//  These bodies stay in the interface, where importers need them:
//  a template, and functions cppfront emits as templates ('forward' and
//  variadic parameters get 'auto' types)
export template<typename T> [[nodiscard]] auto twice(T const& value) -> T;
export [[nodiscard]] auto length(auto&& s) -> int
CPP2_REQUIRES (std::is_convertible_v<CPP2_TYPEOF(s), std::add_const_t<std::string>&>) ;
#line 29 "pure2-module-private-fragment.cpp2"
export [[nodiscard]] auto sum(auto const& ...args) -> int
CPP2_REQUIRES ((std::is_convertible_v<CPP2_TYPEOF(args), int> && ...)) ;

#line 31 "pure2-module-private-fragment.cpp2"
class counter
 {
    private: int count {0}; 

    //  A constructor's body can be private
    public: explicit counter(cpp2::impl::in<int> start);
#line 36 "pure2-module-private-fragment.cpp2"
    public: auto operator=(cpp2::impl::in<int> start) -> counter& ;

    public: [[nodiscard]] auto increment() & -> int;
        public: counter(counter const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(counter const&) -> void = delete;

#line 39 "pure2-module-private-fragment.cpp2"
};


//=== Cpp2 function definitions =================================================

#line 1 "pure2-module-private-fragment.cpp2"

#line 27 "pure2-module-private-fragment.cpp2"
template<typename T> [[nodiscard]] auto twice(T const& value) -> T { return value + value;  }
#line 28 "pure2-module-private-fragment.cpp2"
[[nodiscard]] auto length(auto&& s) -> int
requires (std::is_convertible_v<CPP2_TYPEOF(s), std::add_const_t<std::string>&>)  { return cpp2::unchecked_narrow<int>(CPP2_UFCS(ssize)(CPP2_FORWARD(s)));  }
#line 29 "pure2-module-private-fragment.cpp2"
[[nodiscard]] auto sum(auto const& ...args) -> int
requires ((std::is_convertible_v<CPP2_TYPEOF(args), int> && ...))  { return (0 + ... + args);  }
module :private;

#line 1 "pure2-module-private-fragment.cpp2"

#line 9 "pure2-module-private-fragment.cpp2"
[[nodiscard]] auto greeting(cpp2::impl::in<std::string_view> name) -> std::string
{
    //  A comment in a private body, printed with it
    return "Hello, " + std::string(name) + suffix(); 
}

#line 16 "pure2-module-private-fragment.cpp2"
[[nodiscard]] auto suffix() -> std::string { return "!";  }

#line 19 "pure2-module-private-fragment.cpp2"
auto announce(cpp2::impl::in<std::string_view> what) -> void
{
    std::cout << "announcing " << what << "\n";
}

#line 36 "pure2-module-private-fragment.cpp2"
    counter::counter(cpp2::impl::in<int> start)
                                          : count{ start }{}
#line 36 "pure2-module-private-fragment.cpp2"
    auto counter::operator=(cpp2::impl::in<int> start) -> counter& {
                                          count = start;
                                          return *this; }

#line 38 "pure2-module-private-fragment.cpp2"
    [[nodiscard]] auto counter::increment() & -> int{++count; return count; }

