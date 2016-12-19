//
//  Bezier.cpp
//  cs144-painter
//

#include "Bezier.hpp"

template<typename T>
Bezier<T>::Bezier(rgb color) : Drawable<T>(true, color) { }

template<typename T>
void Bezier<T>::draw()
{
    std::vector<GLint> GLverts;
    for (T v : Drawable<T>::verts)
        GLverts.push_back((GLint)v);
    
    
    GLfloat ctrlPts [4][3] = {{static_cast<GLfloat>(GLverts[0]), static_cast<GLfloat>(GLverts[1]), 0.0}, {static_cast<GLfloat>(GLverts[2]), static_cast<GLfloat>(GLverts[3]), 0.0}, {static_cast<GLfloat>(GLverts[4]), static_cast<GLfloat>(GLverts[5]), 0.0}, {static_cast<GLfloat>(GLverts[6]), static_cast<GLfloat>(GLverts[7]), 0.0}};
    
    glMap1f (GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, *ctrlPts);
    glEnable(GL_MAP1_VERTEX_3);
    
    GLint k;
    
    glColor3ub (Drawable<T>::color.r, Drawable<T>::color.g, Drawable<T>::color.b);
    
    //Generate Bezier "curve"
    glBegin(GL_LINE_STRIP);
    for(k=0; k <= 50; k++)
    {
        glEvalCoord1f(GLfloat (k) / 50.0);
    }
    glEnd();
    
}