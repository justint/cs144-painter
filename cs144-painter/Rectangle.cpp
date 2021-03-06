//
//  Rectangle.cpp
//  cs144-painter
//


#include "Rectangle.hpp"

#define THICKNESS 5

template<typename T>
Rectangle<T>::Rectangle(bool filled, rgb color) : Drawable<T>(filled, color) { }

template<typename T>
void Rectangle<T>::draw()
{
    std::vector<GLint> GLverts;
    for (T v : Drawable<T>::verts)
        GLverts.push_back((GLint)v);
    
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