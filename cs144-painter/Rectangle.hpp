//
//  Rectangle.hpp
//  cs144-painter
//


#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
#include <vector>
#include <typeinfo>

#include "Drawable.hpp"

template<typename T>
class Rectangle : public Drawable<T> {
public:
    Rectangle(bool filled, rgb color);
    void draw();
};

#endif /* Rectangle_hpp */
