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
    Line(rgb color);
    void draw();
};

#endif /* Line_hpp */
