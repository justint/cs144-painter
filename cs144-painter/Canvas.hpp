//
//  Canvas.hpp
//  cs144-painter
//
//  Created by Justin Tennant on 11/17/16.
//
//

// Hides pesky deprecated warnings in Xcode
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#ifndef Canvas_hpp
#define Canvas_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <typeindex>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include "Drawable.hpp"
#include "Rectangle.cpp"
#include "Ellipse.cpp"
#include "Bezier.cpp"
#include "Line.cpp"

// Default resolution
#define X_RESOLUTION 640
#define Y_RESOLUTION 480


// Window title
#define WINDOW_TITLE "CS144 Painter"


#define LEFT_MOUSE_BUTTON 1
#define MIDDLE_MOUSE_BUTTON 2
#define RIGHT_MOUSE_BUTTON 3


/*
 Handles the main OpenGL window initialization and mouse/keyboard inputs,
 ie. the main loop of the program.
 
 Does not handle the rendering for drawables (each drawable renders itself by being called
 in the menu function).
 */
class Canvas {
public:
    Canvas();
    Canvas(int x_resolution, int y_resolution);
    ~Canvas() {};
    
    static Context cntxt;
    
    void init(int argc, char * argv[]);
private:
    int x_resolution = X_RESOLUTION;
    int y_resolution = Y_RESOLUTION;
    
    static std::vector< Drawable<int>* > drawables;
        
    void create_context_menu();
    static void menu(int value);
    
    static void display();
    static void reshape(int w, int h);
    static void in_mouse(int mouse_button, int state, int x, int y);
    static void in_keyboard(unsigned char key, int x, int y);
    static void arrow_keys(int key, int x, int y);
    void spindisplay();
};
#endif /* Canvas_hpp */
