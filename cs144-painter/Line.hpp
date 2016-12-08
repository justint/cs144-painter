//
//  Line.hpp
//  cs144-painter
//


#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>

#include "Drawable.hpp"

template<typename T>
class Line : public Drawable<T>{
    
public:
    Line(bool filled, rgb color);
    void draw();
    
private:
    T x1, x2, y1, y2;

};

#endif /* Line_hpp */
