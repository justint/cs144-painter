//
//  Ellipse.cpp
//  cs144-painter
//
//  Created by Justin Tennant on 11/30/16.
//
//

#include "Ellipse.hpp"
#include <math.h>

#define THICKNESS 5
#define DEG2RAD 3.14159/180.0


template<typename T>
Ellipse<T>::Ellipse(bool filled, rgb color) : Drawable<T>(filled, color) { }

template<typename T>
void Ellipse<T>::draw()
{

    //printf("Drawing Ellipse...");
    
    std::vector<GLint> GLverts;
    for (T v : Drawable<T>::verts)
        GLverts.push_back((GLint)v);
        printf("verts[0]: %u, verts[1]: %u, verts[2]: %u, verts[3]: %u\n", GLverts[0], GLverts[1], GLverts[2], GLverts[3]);
    
    float radiusX = abs(GLverts[0] - GLverts[2])/2;
    float radiusY = abs(GLverts[1]- GLverts[3])/2;
    printf("radiusX: %i, radiusY: %i \n", radiusX, radiusY);
    int topX, topY;
    //find which x value is the top corner
    if(GLverts[0] < GLverts[2])
    {
        topX = GLverts[0];
    }
    else{
        topX = GLverts[2];
    }
    //Find which y value is the top corner
    if(GLverts[1] < GLverts[3])
    {
        topY = GLverts[1];
    }
    else{
        topY = GLverts[3];
    }
    
    
    glColor3ub (Drawable<T>::color.r, Drawable<T>::color.g, Drawable<T>::color.b);
    //draw a filled ellipse
    if (Drawable<T>::filled)
    {
        glBegin(GL_TRIANGLE_FAN);
        
        for(int i=0;i<360;i++)
        {
            float rad = i*DEG2RAD;
            glVertex2f((cos(rad)*radiusX + (topX + radiusX)),
                       (sin(rad)*radiusY) + (topY + radiusY));
        }
        
        glEnd();
    }
    //draw an unfilled ellipse
    else
    {
        glBegin(GL_LINE_LOOP);
        
        for(int i=0;i<360;i++)
        {
            float rad = i*DEG2RAD;
            glVertex2f((cos(rad)*radiusX + (topX + radiusX)),
                       (sin(rad)*radiusY) + (topY + radiusY));
        }
        
        glEnd();
    }
}