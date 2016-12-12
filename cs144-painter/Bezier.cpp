//
//  Bezier.cpp
//  cs144-painter
//

#include "Bezier.hpp"

template<typename T>
Bezier<T>::Bezier(bool filled, rgb color) : Drawable<T>(filled, color) { }

template<typename T>
void Bezier<T>::draw()
{
    
    std::vector<GLint> GLverts;
    for (T v : Drawable<T>::verts)
        GLverts.push_back((GLint)v);
    
    
    
    //find the radius of the x1-x2 coords
    float radiusX = abs(GLverts[0] - GLverts[2])/2;
    //find the radius of the y1-y2 coords
    float radiusY = abs(GLverts[1]- GLverts[3])/2;
    int topX, topY;
    //find which x value is the top corner
    if(GLverts[0] < GLverts[6])
    {
        topX = GLverts[0];
    }
    else{
        topX = GLverts[6];
    }
    //Find which y value is the top corner
    if(GLverts[1] < GLverts[7])
    {
        topY = GLverts[1];
    }
    else{
        topY = GLverts[7];
    }
    
    
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
    
    
    /*glBegin(GL_POINTS);
    for(k=0; k < 4; k++)
    {
        glVertex3fv(&ctrlPts [k][0]);
    }
    glEnd();*/
    
}