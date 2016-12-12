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

//these enums will be used as indexes into an array of COLORS
enum Color {
    red, green, blue, yellow, purple, orange, white, black
};

//a small struct to hold the three values that will determine rgb colors
struct rgb {
    int r, g, b; //values from 0-255
};

//constants to be entered into the COLORS array for easy reference
namespace Colors {
const rgb RED = {255, 0, 0};
const rgb GREEN = {0,128,0};
const rgb BLUE = {0,0,255};
const rgb YELLOW = {255,255,0};
const rgb PURPLE = {128,0,128};
const rgb ORANGE = {255,165,0};
const rgb WHITE = {255,255,255};
const rgb BLACK = {0,0,0};
}

/*
void colorToString()
{
    printf("COLORS[red]: %d,%d,%d\n",Colors::RED.r, Colors::RED.g, Colors::RED.b);
    printf("COLORS[green]: %d,%d,%d\n",COLORS[green].r, COLORS[green].g, COLORS[green].b);
    printf("COLORS[blue]: %d,%d,%d\n",COLORS[blue].r, COLORS[blue].g, COLORS[blue].b);
    printf("COLORS[yellow]: %d,%d,%d\n",COLORS[yellow].r, COLORS[yellow].g, COLORS[yellow].b);
    printf("COLORS[purple]: %d,%d,%d\n",COLORS[purple].r, COLORS[purple].g, COLORS[purple].b);
    printf("COLORS[orange]: %d,%d,%d\n",COLORS[orange].r, COLORS[orange].g, COLORS[orange].b);
    printf("COLORS[white]: %d,%d,%d\n",COLORS[white].r, COLORS[white].g, COLORS[white].b);
    printf("COLORS[black]: %d,%d,%d\n",COLORS[black].r, COLORS[black].g, COLORS[black].b);
}
*/

struct Context;

/*
 Abstract class which provides a draw() method for each of the drawable
 elements in the canvas (shapes, lines, etc).
 */
template<typename T>
class Drawable {
public:
    enum type {
        rectangle, ellipse, bezier_curve, line
    };
    
    Drawable(bool filled, rgb color);
    ~Drawable();
    void virtual draw();
    
    std::vector<T> verts;
    
    static bool check_vert_type(std::vector<T> verts);
    
    Drawable<T> operator=(Drawable<T> d);
protected:
    const bool filled;
    const rgb color;
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
    
    Drawable<int> *drawable;
    bool currently_drawing;
    int counter;
    bool bez;
    
    std::vector<int> verts;
    
    Context() : left_mouse_button_x(120), left_mouse_button_y(240), middle_mouse_button_x(220), middle_mouse_button_y(240), right_mouse_button_x(320), right_mouse_button_y(240), last_mouse_button_pressed(0), currently_drawing(false)
    { }
};

template<typename T>
Drawable<T>::Drawable(bool filled, rgb color) : filled(filled), color(color) { }

template<typename T>
Drawable<T>::~Drawable() { }

template<typename T>
bool Drawable<T>::check_vert_type(std::vector<T> verts)
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
void Drawable<T>::draw() { }

template<typename T>
Drawable<T> Drawable<T>::operator=(Drawable<T> d)
{
    return *this;
}

#endif /* Drawable_hpp */