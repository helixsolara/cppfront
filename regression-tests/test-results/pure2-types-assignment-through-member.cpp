
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-types-assignment-through-member.cpp2"

#line 6 "pure2-types-assignment-through-member.cpp2"
class settings;

class widget;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-types-assignment-through-member.cpp2"
//  A constructor's leading assignments to its members, in order, are their
//  initializers. An assignment through a member (binding*.kind = 2, which
//  sets a member of what binding points to) doesn't initialize binding: it
//  is a statement of the body, run after every member is initialized

#line 6 "pure2-types-assignment-through-member.cpp2"
class settings {public: int kind {0}; 
public: settings(auto&& kind_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(kind_), std::add_const_t<int>&>) ;

public: auto operator=(auto&& kind_) -> settings& 
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(kind_), std::add_const_t<int>&>) ;
public: settings();

#line 6 "pure2-types-assignment-through-member.cpp2"
};

class widget
 {
    private: std::shared_ptr<settings> binding {std::make_shared<settings>()}; 
    private: int count {1}; 

    //  An assignment through the first member, first
    public: explicit widget();

#line 19 "pure2-types-assignment-through-member.cpp2"
    //  The second member's initializer, then an assignment through the first
    public: explicit widget(cpp2::impl::in<int> n);
#line 20 "pure2-types-assignment-through-member.cpp2"
    public: auto operator=(cpp2::impl::in<int> n) -> widget& ;

#line 26 "pure2-types-assignment-through-member.cpp2"
    public: [[nodiscard]] auto kind() const& -> int;
    public: [[nodiscard]] auto count_of() const& -> int;
    public: widget(widget const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(widget const&) -> void = delete;

#line 28 "pure2-types-assignment-through-member.cpp2"
};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-types-assignment-through-member.cpp2"


settings::settings(auto&& kind_)
requires (std::is_convertible_v<CPP2_TYPEOF(kind_), std::add_const_t<int>&>) 
                                                              : kind{ CPP2_FORWARD(kind_) }{}
auto settings::operator=(auto&& kind_) -> settings& 
requires (std::is_convertible_v<CPP2_TYPEOF(kind_), std::add_const_t<int>&>) {
                                                              kind = CPP2_FORWARD(kind_);
                                                              return *this;}
settings::settings(){}
#line 14 "pure2-types-assignment-through-member.cpp2"
    widget::widget()
    {
        (*cpp2::impl::assert_not_null(binding)).kind = 2;
    }

#line 20 "pure2-types-assignment-through-member.cpp2"
    widget::widget(cpp2::impl::in<int> n)
        : count{ n }
#line 21 "pure2-types-assignment-through-member.cpp2"
    {

        (*cpp2::impl::assert_not_null(binding)).kind = n * 2;
    }
#line 20 "pure2-types-assignment-through-member.cpp2"
    auto widget::operator=(cpp2::impl::in<int> n) -> widget& 
#line 21 "pure2-types-assignment-through-member.cpp2"
    {
        binding = std::make_shared<settings>();
        count = n;

#line 23 "pure2-types-assignment-through-member.cpp2"
        (*cpp2::impl::assert_not_null(binding)).kind = n * 2;
        return *this;
#line 24 "pure2-types-assignment-through-member.cpp2"
    }

#line 26 "pure2-types-assignment-through-member.cpp2"
    [[nodiscard]] auto widget::kind() const& -> int { return (*cpp2::impl::assert_not_null(binding)).kind;  }
#line 27 "pure2-types-assignment-through-member.cpp2"
    [[nodiscard]] auto widget::count_of() const& -> int { return count;  }

#line 30 "pure2-types-assignment-through-member.cpp2"
auto main() -> int
{
    widget a {}; 
    widget b {5}; 
    std::cout << "first statement: " << CPP2_UFCS(kind)(a) << " " << CPP2_UFCS(count_of)(a) << "\n";
    std::cout << "after an initializer: " << CPP2_UFCS(kind)(b) << " " << CPP2_UFCS(count_of)(b) << "\n";
}

