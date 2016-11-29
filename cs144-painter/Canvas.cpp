//
//  Canvas.cpp
//  cs144-painter
//
//  Created by Justin Tennant on 11/17/16.
//
//

#include "Canvas.hpp"

// Initializes the context for the canvas
Context Canvas::c;

int main(int argc, char * argv[])
{
    Canvas c;
    c.init(argc, argv);
}