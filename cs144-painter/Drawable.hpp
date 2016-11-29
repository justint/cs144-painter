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
#include <vector>
#include <exception>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

/*
 Provides important resolution, mouse info to each drawable so
 they can properly draw their elements at the correct locations
 in the canvas.
 
 Should be constructed before each window resize/draw and passed into
 every draw() call.
 
 */
struct Context {
    GLsizei left_mouse_button_x, left_mouse_button_y;
    GLsizei middle_mouse_button_x, middle_mouse_button_y;
    GLsizei right_mouse_button_x, right_mouse_button_y;
    int last_mouse_button_pressed;
    
    int x_res;
    int y_res;
    
    Context() : left_mouse_button_x(120), left_mouse_button_y(240), middle_mouse_button_x(220), middle_mouse_button_y(240), right_mouse_button_x(320), right_mouse_button_y(240), last_mouse_button_pressed(0)
    { }
};

/*
 Abstract class which provides a draw() method for each of the drawable
 elements in the canvas (shapes, lines, etc).
 */
template<typename T>
class Drawable {
public:
    Drawable();
    ~Drawable();
    void virtual draw(const Context& c);
    
    static bool check_type(std::vector<T> verts);
};

template<typename T>
Drawable<T>::Drawable() { }

template<typename T>
Drawable<T>::~Drawable() { }

template<typename T>
bool Drawable<T>::check_type(std::vector<T> verts)
{
    for (T v : verts)
    {
        if (typeid(v) != typeid(int) || typeid(v) != typeid(float)
            || typeid(v) != typeid(double) || typeid(v) != typeid(short)) 
            throw typeid(v).name();
    }
    return true;
}

#endif /* Drawable_hpp */