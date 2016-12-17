//
//  Ellipse.hpp
//  cs144-painter
//


#ifndef Ellipse_hpp
#define Ellipse_hpp

#include <stdio.h>

#include "Drawable.hpp"

template<typename T>
class Ellipse : public Drawable<T>{
public:
    Ellipse(bool filled, rgb color);
    void draw();
};

#endif /* Ellipse_hpp */
