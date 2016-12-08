//
//  Line.hpp
//  cs144-painter
//
//  Created by Justin Tennant on 11/30/16.
//
//

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>

#include "Drawable.hpp"

template<typename T>
class Line : public Drawable<T>{
public:
    Line(rgb color);
    void draw();
    
private:
    T x1, x2, y1, y2;

};

#endif /* Line_hpp */
