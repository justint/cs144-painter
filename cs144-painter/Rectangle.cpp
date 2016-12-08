//
//  Rectangle.cpp
//  cs144-painter
//
//  Created by Justin Tennant on 11/26/16.
//
//

#include "Rectangle.hpp"

#define THICKNESS 5

template<typename T>
Rectangle<T>::Rectangle(bool filled, rgb color) : Drawable<T>(filled, color) { }

template<typename T>
void Rectangle<T>::draw()
{
    //printf("Drawing rectangle...");
    
    std::vector<GLint> GLverts;
    for (T v : Drawable<T>::verts)
        GLverts.push_back((GLint)v);
    
    //printf("verts[0]: %u, verts[1]: %u, verts[2]: %u, verts[3]: %u\n", GLverts[0], GLverts[1], GLverts[2], GLverts[3]);
    
    glColor3ub (Drawable<T>::color.r, Drawable<T>::color.g, Drawable<T>::color.b);
    if (Drawable<T>::filled)
        glRecti(GLverts[0], GLverts[1], GLverts[2], GLverts[3]);
    else
    {
        glRecti(GLverts[0], GLverts[1], GLverts[2], GLverts[1] + THICKNESS); // top
        glRecti(GLverts[0], GLverts[1], GLverts[0] + THICKNESS, GLverts[3]); // left
        glRecti(GLverts[2] - THICKNESS, GLverts[1], GLverts[2], GLverts[3]); // right
        glRecti(GLverts[0], GLverts[3] - THICKNESS, GLverts[2], GLverts[3]); // bottom
    }
}