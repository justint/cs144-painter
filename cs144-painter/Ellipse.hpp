//
//  Ellipse.hpp
//  cs144-painter
//
//  Created by Justin Tennant on 11/30/16.
//
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
    
private:
    T x1, x2, y1, y2;

    
};

#endif /* Ellipse_hpp */
