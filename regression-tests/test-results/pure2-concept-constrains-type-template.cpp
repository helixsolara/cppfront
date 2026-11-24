
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-concept-constrains-type-template.cpp2"

#line 39 "pure2-concept-constrains-type-template.cpp2"
namespace N
 {

#line 43 "pure2-concept-constrains-type-template.cpp2"
}
namespace M
 {
    class tag;
    template<typename T> requires( (T::value == 1) )
class tagged; }

#line 51 "pure2-concept-constrains-type-template.cpp2"
class shape;
class circle;

#line 57 "pure2-concept-constrains-type-template.cpp2"
namespace A {

#line 60 "pure2-concept-constrains-type-template.cpp2"
}
namespace B {

#line 64 "pure2-concept-constrains-type-template.cpp2"
}

#line 68 "pure2-concept-constrains-type-template.cpp2"
namespace P {
    template<typename T> requires( (std::is_integral<T>::value) )
class integral_holder; }
template<typename T> concept is_text = std::is_same_v<T,std::string>; template<typename T> requires( is_text<T> )class holder;template<typename T> concept is_integral_or_float = std::is_integral_v<T> || std::is_floating_point_v<T>; template<is_integral_or_float T> class counted;template<typename T> concept drawable = std::derived_from<T,shape>; template<drawable T> class canvas;namespace A {template<typename T> concept c = std::integral<T>; }namespace B {template<typename T> concept c = std::floating_point<T>; }

template<typename T> concept small = cpp2::impl::cmp_less_eq(sizeof(T),8u); 
template<small T> class box;
template<typename T> concept is_box = std::is_same_v<T,box<int>>; 
template<is_box T> class wrapper;
template<typename T> concept is_late = is_integral_or_float<T>; namespace A {template<c T> class holder;}template<typename T> requires( is_late<T> )class late_holder;

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-concept-constrains-type-template.cpp2"
//  Concepts that a type template's declaration uses (in its requires clause or
//  template parameter list) are emitted before the type's forward declaration,
//  wherever they are written; other concepts can still call functions

#line 7 "pure2-concept-constrains-type-template.cpp2"
template<typename T> 
    requires( is_text<T> )
class holder {
    private: T value {"held"}; 
    public: [[nodiscard]] auto size() const& -> std::size_t;
    public: holder() = default;
    public: holder(holder const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(holder const&) -> void = delete;

#line 12 "pure2-concept-constrains-type-template.cpp2"
};

//  A concept that names a type declared before it in the file
template<typename T> concept is_holder = std::is_same_v<T,holder<std::string>>; 

//  A concept that calls a function: no type uses it, so it still comes after
//  the function declarations
template<typename T> [[nodiscard]] constexpr auto fits_in_word() -> bool;
template<typename T> concept is_small = fits_in_word<T>(); 

//  A type whose concept is written after it, and that concept uses another
template<typename T> 
    requires( is_late<T> )
class late_holder {
    public: T value {}; 
    public: late_holder() = default;
    public: late_holder(late_holder const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(late_holder const&) -> void = delete;

#line 27 "pure2-concept-constrains-type-template.cpp2"
};

#line 31 "pure2-concept-constrains-type-template.cpp2"
//  A constraint in the template parameter list
template<is_integral_or_float T> class counted
 {
    public: T value {3}; 
    public: counted() = default;
    public: counted(counted const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(counted const&) -> void = delete;

#line 35 "pure2-concept-constrains-type-template.cpp2"
};

//  A member named like a concept: 'T::value' doesn't name the concept 'value',
//  which uses a function and so must stay after the function declarations
namespace N
 {
    template<typename T> [[nodiscard]] constexpr auto fits() -> bool;
    template<typename T> concept value = fits<T>(); 
}
namespace M
 {
    class tag {public: static const int value;
    
          public: tag() = default;
          public: tag(tag const&) = delete; /* No 'that' constructor, suppress copy */
          public: auto operator=(tag const&) -> void = delete;

#line 46 "pure2-concept-constrains-type-template.cpp2"
    };
    template<typename T> requires( (T::value == 1) )
class tagged {
          public: tagged() = default;
          public: tagged(tagged const&) = delete; /* No 'that' constructor, suppress copy */
          public: auto operator=(tagged const&) -> void = delete;

#line 47 "pure2-concept-constrains-type-template.cpp2"
    };
}

//  A hoisted concept that names Cpp2 types declared before it
class shape {
      public: shape() = default;
      public: shape(shape const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(shape const&) -> void = delete;
};
#line 52 "pure2-concept-constrains-type-template.cpp2"
class circle: public shape {
      public: circle() = default;
      public: circle(circle const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(circle const&) -> void = delete;
};
#line 53 "pure2-concept-constrains-type-template.cpp2"

template<drawable T> class canvas {
      public: canvas() = default;
      public: canvas(canvas const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(canvas const&) -> void = delete;
};
#line 55 "pure2-concept-constrains-type-template.cpp2"

//  Two concepts with the same name in different namespaces
namespace A {

    template<c T> class holder {
          public: holder() = default;
          public: holder(holder const&) = delete; /* No 'that' constructor, suppress copy */
          public: auto operator=(holder const&) -> void = delete;
};
#line 60 "pure2-concept-constrains-type-template.cpp2"
}
namespace B {

    [[nodiscard]] auto f(auto const& x) -> bool
CPP2_REQUIRES (c<CPP2_TYPEOF(x)>) ;
#line 64 "pure2-concept-constrains-type-template.cpp2"
}

//  A member of a template-id isn't a concept candidate: 'value' here doesn't
//  name the concept N::value
namespace P {
    template<typename T> requires( (std::is_integral<T>::value) )
class integral_holder {
          public: integral_holder() = default;
          public: integral_holder(integral_holder const&) = delete; /* No 'that' constructor, suppress copy */
          public: auto operator=(integral_holder const&) -> void = delete;

#line 69 "pure2-concept-constrains-type-template.cpp2"
    };
}

//  A concept that names a constrained type, constraining another type

template<small T> class box {
      public: box() = default;
      public: box(box const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(box const&) -> void = delete;
};
#line 75 "pure2-concept-constrains-type-template.cpp2"

template<is_box T> class wrapper {
      public: wrapper() = default;
      public: wrapper(wrapper const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(wrapper const&) -> void = delete;
};
#line 77 "pure2-concept-constrains-type-template.cpp2"

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-concept-constrains-type-template.cpp2"

#line 11 "pure2-concept-constrains-type-template.cpp2"
    template <typename T> requires( is_text<T> )
[[nodiscard]] auto holder<T>::size() const& -> std::size_t { return CPP2_UFCS(size)(value); }

#line 19 "pure2-concept-constrains-type-template.cpp2"
template<typename T> [[nodiscard]] constexpr auto fits_in_word() -> bool { return cpp2::impl::cmp_less_eq(sizeof(T),8u);  }

#line 39 "pure2-concept-constrains-type-template.cpp2"
namespace N
 {
#line 41 "pure2-concept-constrains-type-template.cpp2"
    template<typename T> [[nodiscard]] constexpr auto fits() -> bool { return cpp2::impl::cmp_less_eq(sizeof(T),8u);  }

}
namespace M
 {
    inline CPP2_CONSTEXPR int tag::value{ 1 };
    
}

#line 57 "pure2-concept-constrains-type-template.cpp2"
namespace A {

#line 60 "pure2-concept-constrains-type-template.cpp2"
}
namespace B {

#line 63 "pure2-concept-constrains-type-template.cpp2"
    [[nodiscard]] auto f(auto const& x) -> bool
requires (c<CPP2_TYPEOF(x)>) {static_cast<void>(x); return true; }
#line 64 "pure2-concept-constrains-type-template.cpp2"
}

#line 68 "pure2-concept-constrains-type-template.cpp2"
namespace P {

}

#line 78 "pure2-concept-constrains-type-template.cpp2"
auto main() -> int
{
    wrapper<box<int>> w {}; 
    static_cast<void>(cpp2::move(w));
    canvas<circle> cv {}; 
    static_cast<void>(cpp2::move(cv));
    A::holder<int> ah {}; 
    static_cast<void>(cpp2::move(ah));
    std::cout << B::f(1.0) << "\n";
    P::integral_holder<long> ih {}; 
    static_cast<void>(cpp2::move(ih));

    holder<std::string> h {}; 
    std::cout << CPP2_UFCS(size)(cpp2::move(h)) << "\n";
    std::cout << is_holder<holder<std::string>> << "\n";
    std::cout << is_small<char> << "\n";
    late_holder<int> l {}; 
    std::cout << cpp2::move(l).value << "\n";
    counted<int> c {}; 
    std::cout << cpp2::move(c).value << "\n";
    M::tagged<M::tag> t {}; 
    static_cast<void>(cpp2::move(t));
    std::cout << N::value<int> << "\n";
}

