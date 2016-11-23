//
//  Drawable.hpp
//  cs144-painter
//
//  Created by Justin Tennant on 11/22/16.
//
//

#ifndef Drawable_hpp
#define Drawable_hpp

#include <stdio.h>

class Drawable {
public:
    Drawable();
    ~Drawable();
    void virtual draw();
};

Drawable::Drawable() { }

Drawable::~Drawable() { }

#endif /* Drawable_hpp */