//
//  Bezier.hpp
//  cs144-painter
//
//  Created by Justin Tennant on 11/30/16.
//
//

#ifndef Bezier_hpp
#define Bezier_hpp

#include <stdio.h>

#include "Drawable.hpp"

template<typename T>
class Bezier : public Drawable<T>{
    
public:
    Bezier(rgb color);
    void draw();
    
};

#endif /* Bezier_hpp */
