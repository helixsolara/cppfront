
module;
#define CPP2_INCLUDE_STD         Yes

#include "cpp2util.h"

//  Module interface partition: 'export module name:partition;'
//  The primary interface (pure2-module-interface.cpp2) re-exports it
//  with 'export import :geometry;'.

export module shapes:geometry;

//=== Cpp2 type declarations ====================================================

#line 1 "pure2-module-partition.cpp2"

#line 7 "pure2-module-partition.cpp2"
export class point;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-module-partition.cpp2"

#line 7 "pure2-module-partition.cpp2"
class point {
    public: double x; 
    public: double y; 
    public: point(auto&& x_, auto&& y_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(x_), std::add_const_t<double>&> && std::is_convertible_v<CPP2_TYPEOF(y_), std::add_const_t<double>&>) ;

#line 10 "pure2-module-partition.cpp2"
};

export [[nodiscard]] auto distance_squared(cpp2::impl::in<point> a, cpp2::impl::in<point> b) -> double;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-module-partition.cpp2"


point::point(auto&& x_, auto&& y_)
requires (std::is_convertible_v<CPP2_TYPEOF(x_), std::add_const_t<double>&> && std::is_convertible_v<CPP2_TYPEOF(y_), std::add_const_t<double>&>) 
                                                                                   : x{ CPP2_FORWARD(x_) }
                                                                                   , y{ CPP2_FORWARD(y_) }{}
#line 12 "pure2-module-partition.cpp2"
[[nodiscard]] auto distance_squared(cpp2::impl::in<point> a, cpp2::impl::in<point> b) -> double{
    auto dx {b.x - a.x}; 
    auto dy {b.y - a.y}; 
    return dx * dx + dy * dy; 
}

