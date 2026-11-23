
module;
#define CPP2_INCLUDE_STD         Yes

#include "cpp2util.h"

//  Primary module interface unit: 'export module name;'
//  Exports each kind of declaration Cpp2 can write at namespace scope,
//  re-exports a partition, and keeps a helper private to the module.

export module shapes;
export import :geometry;
import :detail;

//=== Cpp2 type declarations ====================================================

#line 1 "pure2-module-interface.cpp2"

#line 16 "pure2-module-interface.cpp2"
export class color;
    

#line 22 "pure2-module-interface.cpp2"
export class rectangle;

#line 43 "pure2-module-interface.cpp2"
export template<typename T> class labeled;
    

#line 48 "pure2-module-interface.cpp2"
export namespace units {

#line 51 "pure2-module-interface.cpp2"
}

#line 54 "pure2-module-interface.cpp2"
namespace text {
    export using std::string_view;
}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-module-interface.cpp2"

#line 9 "pure2-module-interface.cpp2"
//  Not exported: has module linkage, so importers can't see it
#line 10 "pure2-module-interface.cpp2"
[[nodiscard]] auto square(cpp2::impl::in<double> x) -> double;

export using length = double;

export cpp2::i32 inline constexpr sides_of_square{ 4 };

class color {
private: cpp2::i8 _value; private: constexpr color(cpp2::impl::in<cpp2::i64> _val);

private: constexpr auto operator=(cpp2::impl::in<cpp2::i64> _val) -> color& ;
public: static const color red;
public: static const color green;
public: static const color blue;
public: [[nodiscard]] constexpr auto get_raw_value() const& -> cpp2::i8;
public: constexpr explicit color();
public: constexpr color(color const& that);
public: constexpr auto operator=(color const& that) -> color& ;
public: constexpr color(color&& that) noexcept;
public: constexpr auto operator=(color&& that) noexcept -> color& ;
public: [[nodiscard]] auto operator<=>(color const& that) const& -> std::strong_ordering = default;
public: [[nodiscard]] auto to_string_impl(cpp2::impl::in<std::string_view> prefix) const& -> std::string;
public: [[nodiscard]] auto to_string() const& -> std::string;
public: [[nodiscard]] auto to_code() const& -> std::string;
public: [[nodiscard]] static auto from_string(cpp2::impl::in<std::string_view> s) -> color;
public: [[nodiscard]] static auto from_code(cpp2::impl::in<std::string_view> s) -> color;

#line 20 "pure2-module-interface.cpp2"
};

class rectangle {
           public: length width {0.0}; 
    public: length height {0.0}; 

    public: rectangle(cpp2::impl::in<length> w, cpp2::impl::in<length> h);

#line 31 "pure2-module-interface.cpp2"
    public: [[nodiscard]] auto area() const& -> length;
        public: rectangle(rectangle const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(rectangle const&) -> void = delete;

#line 32 "pure2-module-interface.cpp2"
};

export [[nodiscard]] auto square_area(cpp2::impl::in<length> side) -> length;

export template<typename T> [[nodiscard]] auto larger(T const& a, T const& b) -> T;

#line 43 "pure2-module-interface.cpp2"
template<typename T> class labeled {
    public: std::string label; 
    public: T value; 
    public: labeled(auto&& label_, T&& value_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(label_), std::add_const_t<std::string>&>) ;

#line 46 "pure2-module-interface.cpp2"
};

export namespace units {
    cpp2::i32 inline constexpr inches_per_foot{ 12 };
    [[nodiscard]] auto to_inches(cpp2::impl::in<cpp2::i32> feet) -> cpp2::i32;
}

//  'export using' is a statement, so it goes inside a namespace body
namespace text {
    export using std::string_view;
}


//=== Cpp2 function definitions =================================================

#line 1 "pure2-module-interface.cpp2"

#line 10 "pure2-module-interface.cpp2"
[[nodiscard]] auto square(cpp2::impl::in<double> x) -> double { return x * x;  }


constexpr color::color(cpp2::impl::in<cpp2::i64> _val)
                                                          : _value{ cpp2::unchecked_narrow<cpp2::i8>(_val) } {  }

constexpr auto color::operator=(cpp2::impl::in<cpp2::i64> _val) -> color&  { 
                                                          _value = cpp2::unchecked_narrow<cpp2::i8>(_val);
                                                          return *this; }
inline CPP2_CONSTEXPR color color::red{ 0 };

inline CPP2_CONSTEXPR color color::green{ 1 };

inline CPP2_CONSTEXPR color color::blue{ 2 };

[[nodiscard]] constexpr auto color::get_raw_value() const& -> cpp2::i8 { return _value; }
constexpr color::color()
                                        : _value{ red._value }{}
constexpr color::color(color const& that)
                                              : _value{ that._value }{}
constexpr auto color::operator=(color const& that) -> color& {
                                              _value = that._value;
                                              return *this;}
constexpr color::color(color&& that) noexcept
                                              : _value{ std::move(that)._value }{}
constexpr auto color::operator=(color&& that) noexcept -> color& {
                                              _value = std::move(that)._value;
                                              return *this;}
[[nodiscard]] auto color::to_string_impl(cpp2::impl::in<std::string_view> prefix) const& -> std::string{

auto pref {cpp2::to_string(prefix)}; 
if ((*this) == color::red) {return pref + "red"; }
if ((*this) == color::green) {return pref + "green"; }
if ((*this) == color::blue) {return cpp2::move(pref) + "blue"; }
return "invalid color value"; 
}

[[nodiscard]] auto color::to_string() const& -> std::string { return to_string_impl(""); }
[[nodiscard]] auto color::to_code() const& -> std::string { return to_string_impl("color::"); }
[[nodiscard]] auto color::from_string(cpp2::impl::in<std::string_view> s) -> color{

auto x {s}; 
if ("red" == x) {return color::red; }
else {if ("green" == x) {return color::green; }
else {if ("blue" == cpp2::move(x)) {return color::blue; }
#line 1 "pure2-module-interface.cpp2"
}}
CPP2_UFCS(report_violation)(cpp2::type_safety, CPP2_UFCS(c_str)(("can't convert string '" + cpp2::to_string(s) + "' to enum of type color")));
return color::red; 
}

[[nodiscard]] auto color::from_code(cpp2::impl::in<std::string_view> s) -> color{
std::string str {s}; return from_string(cpp2::string_util::replace_all(cpp2::move(str), "color::", "")); }

#line 26 "pure2-module-interface.cpp2"
    rectangle::rectangle(cpp2::impl::in<length> w, cpp2::impl::in<length> h)
        : width{ clamp_to_zero(w) }
        , height{ clamp_to_zero(h) }{

#line 29 "pure2-module-interface.cpp2"
    }

#line 31 "pure2-module-interface.cpp2"
    [[nodiscard]] auto rectangle::area() const& -> length { return width * height;  }

#line 34 "pure2-module-interface.cpp2"
[[nodiscard]] auto square_area(cpp2::impl::in<length> side) -> length { return square(side);  }

#line 36 "pure2-module-interface.cpp2"
template<typename T> [[nodiscard]] auto larger(T const& a, T const& b) -> T{
    if (cpp2::impl::cmp_less(a,b)) {
        return b; 
    }
    return a; 
}

template <typename T> labeled<T>::labeled(auto&& label_, T&& value_)
requires (std::is_convertible_v<CPP2_TYPEOF(label_), std::add_const_t<std::string>&>) 
                                                                                           : label{ CPP2_FORWARD(label_) }
                                                                                           , value{ CPP2_FORWARD(value_) }{}

#line 48 "pure2-module-interface.cpp2"
namespace units {

#line 50 "pure2-module-interface.cpp2"
    [[nodiscard]] auto to_inches(cpp2::impl::in<cpp2::i32> feet) -> cpp2::i32 { return feet * inches_per_foot;  }
}

#line 54 "pure2-module-interface.cpp2"
namespace text {
    export using std::string_view;
}

