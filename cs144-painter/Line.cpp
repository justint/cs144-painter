//
//  Line.cpp
//  cs144-painter
//

#include "Line.hpp"


template<typename T>
Line<T>::Line(bool filled, rgb color) : Drawable<T>(filled, color) { }

template<typename T>
void Line<T>::draw()
{
    //printf("Drawing line...");
    
    std::vector<GLint> GLverts;
    for (T v : Drawable<T>::verts)
        GLverts.push_back((GLint)v);
    
    
    glColor3ub (Drawable<T>::color.r, Drawable<T>::color.g, Drawable<T>::color.b);
    
    glBegin(GL_LINES);
    glVertex2d(GLverts[0], GLverts[1]);
    glVertex2d(GLverts[2], GLverts[3]);
    glEnd();
    
}