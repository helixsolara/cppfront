
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-template-specialization.cpp2"

#line 17 "pure2-template-specialization.cpp2"
class widget;

#line 23 "pure2-template-specialization.cpp2"
template<typename T> class traits;
template<> class traits<char>;template<> class traits<decltype(CPP2_UFCS_NONLOCAL(size)((*cpp2::impl::assert_not_null(std::declval<std::string*>()))))>;

#line 29 "pure2-template-specialization.cpp2"
template<> class traits<widget>;

#line 35 "pure2-template-specialization.cpp2"
template<typename T> class traits<std::vector<T>>;

#line 41 "pure2-template-specialization.cpp2"
template<> class std::hash<widget>;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-template-specialization.cpp2"
//  A template specialization names the template it specializes with its
//  template arguments, and its template parameter list says what stays
//  generic: '<>' for an explicit specialization

//  A specialization written before its primary template
#line 6 "pure2-template-specialization.cpp2"
template<> class traits<char>
 {
    public: [[nodiscard]] static auto name() -> std::string_view;
    public: traits() = default;
    public: traits(traits const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(traits const&) -> void = delete;

#line 9 "pure2-template-specialization.cpp2"
};

//  A specialization whose template arguments hold a '>' inside parentheses
template<> class traits<decltype(CPP2_UFCS_NONLOCAL(size)((*cpp2::impl::assert_not_null(std::declval<std::string*>()))))>
 {
    public: [[nodiscard]] static auto name() -> std::string_view;
    public: traits() = default;
    public: traits(traits const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(traits const&) -> void = delete;

#line 15 "pure2-template-specialization.cpp2"
};

class widget
 {
    public: int id {0}; 
    public: explicit widget(cpp2::impl::in<int> i);
#line 20 "pure2-template-specialization.cpp2"
    public: auto operator=(cpp2::impl::in<int> i) -> widget& ;
    public: [[nodiscard]] auto operator<=>(widget const& that) const& -> std::strong_ordering = default;
public: widget(widget const& that);

public: auto operator=(widget const& that) -> widget& ;
public: widget(widget&& that) noexcept;
public: auto operator=(widget&& that) noexcept -> widget& ;
public: explicit widget();

#line 21 "pure2-template-specialization.cpp2"
};

template<typename T> class traits
 {
    public: [[nodiscard]] static auto name() -> std::string_view;
    public: traits() = default;
    public: traits(traits const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(traits const&) -> void = delete;

#line 26 "pure2-template-specialization.cpp2"
};

//  An explicit specialization of a Cpp2 template
template<> class traits<widget>
 {
    public: [[nodiscard]] static auto name() -> std::string_view;
    public: traits() = default;
    public: traits(traits const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(traits const&) -> void = delete;

#line 32 "pure2-template-specialization.cpp2"
};

//  A partial specialization
template<typename T> class traits<std::vector<T>>
 {
    public: [[nodiscard]] static auto name() -> std::string_view;
    public: traits() = default;
    public: traits(traits const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(traits const&) -> void = delete;

#line 38 "pure2-template-specialization.cpp2"
};

//  A specialization of a standard library template, qualified by its namespace
template<> class std::hash<widget>
 {
    public: [[nodiscard]] auto operator()(cpp2::impl::in<widget> w) const& -> std::size_t;
};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-template-specialization.cpp2"

#line 8 "pure2-template-specialization.cpp2"
    [[nodiscard]] auto traits<char>::name() -> std::string_view { return "char";  }

#line 14 "pure2-template-specialization.cpp2"
    [[nodiscard]] auto traits<decltype(CPP2_UFCS_NONLOCAL(size)((*cpp2::impl::assert_not_null(std::declval<std::string*>()))))>::name() -> std::string_view { return "size type";  }

#line 20 "pure2-template-specialization.cpp2"
    widget::widget(cpp2::impl::in<int> i)
                                      : id{ i }{}
#line 20 "pure2-template-specialization.cpp2"
    auto widget::operator=(cpp2::impl::in<int> i) -> widget& {
                                      id = i;
                                      return *this; }


    widget::widget(widget const& that)
                                : id{ that.id }{}

auto widget::operator=(widget const& that) -> widget& {
                                id = that.id;
                                return *this;}
widget::widget(widget&& that) noexcept
                                : id{ std::move(that).id }{}
auto widget::operator=(widget&& that) noexcept -> widget& {
                                id = std::move(that).id;
                                return *this;}
widget::widget(){}
#line 25 "pure2-template-specialization.cpp2"
    template <typename T> [[nodiscard]] auto traits<T>::name() -> std::string_view { return "generic";  }

#line 31 "pure2-template-specialization.cpp2"
    [[nodiscard]] auto traits<widget>::name() -> std::string_view { return "widget";  }

#line 37 "pure2-template-specialization.cpp2"
    template <typename T> [[nodiscard]] auto traits<std::vector<T>>::name() -> std::string_view { return "vector";  }

#line 43 "pure2-template-specialization.cpp2"
    [[nodiscard]] auto std::hash<widget>::operator()(cpp2::impl::in<widget> w) const& -> std::size_t { return std::hash<int>()(w.id);  }

#line 46 "pure2-template-specialization.cpp2"
auto main() -> int
{
    std::cout << traits<int>::name() << " " << traits<widget>::name() << " " << traits<std::vector<int>>::name() << "\n";
    std::cout << traits<char>::name() << " " << traits<std::size_t>::name() << "\n";

    std::unordered_set<widget> set {}; 
    CPP2_UFCS(insert)(set, widget(1));
    CPP2_UFCS(insert)(set, widget(1));
    CPP2_UFCS(insert)(set, widget(2));
    std::cout << CPP2_UFCS(size)(cpp2::move(set)) << "\n";
}

