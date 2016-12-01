//
//  Rectangle.hpp
//  cs144-painter
//
//  Created by Justin Tennant on 11/30/16.
//
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
    
private:
    T x1, x2, y1, y2;
};

#endif /* Rectangle_hpp */
