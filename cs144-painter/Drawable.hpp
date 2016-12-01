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
#include <tuple>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

//color options: red green blue yellow purple orange white black
enum menuOptions {recFillRed, recFillGreen, recFillBlue, recFillYellow, recFillPurple,
    recFillOrange, recFillWhite, recFillBlack, recOutlineRed, recOutlineGreen,
    recOutlineBlue, recOutlineYellow, recOutlinePurple, recOutlineOrange,
    recOutlineWhite, recOutlineBlack, ellFillRed, ellFillGreen, ellFillBlue,
    ellFillYellow, ellFillPurple, ellFillOrange, ellFillWhite, ellFillBlack,
    ellOutRed, ellOutGreen, ellOutBlue, ellOutYellow, ellOutPurple, ellOutOrange,
    ellOutWhite, ellOutBlack, lineRed, lineGreen, lineBlue, lineYellow, linePurple,
    lineOrange, lineWhite, lineBlack, bezRed, bezGreen, bezBlue, bezYellow, bezPurple,
    bezOrange, bezWhite, bezBlack};

const char* menuOptionsToString(menuOptions m)
{
    switch(m)
    {
        case recFillRed:
            return "recFillRed";
        default:
            break;
    }
    return NULL;
}

enum Color {
    red, green, blue, yellow, purple, orange, white, black
};

struct rgb {
    Color r, g, b;
};

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
    
    menuOptions e;
    
    bool currently_drawing;
    
    Context() : left_mouse_button_x(120), left_mouse_button_y(240), middle_mouse_button_x(220), middle_mouse_button_y(240), right_mouse_button_x(320), right_mouse_button_y(240), last_mouse_button_pressed(0), currently_drawing(false)
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
    
    bool filled;
    
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

template<typename T>
void Drawable<T>::draw(const Context &c)
{

}

#endif /* Drawable_hpp */