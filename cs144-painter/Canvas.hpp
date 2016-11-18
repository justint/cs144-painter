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

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>


// Default resolution
#define X_RESOLUTION 640
#define Y_RESOLUTION 480


// Window title
#define WINDOW_TITLE "CS144 Painter"


#define LEFT_MOUSE_BUTTON 1
#define MIDDLE_MOUSE_BUTTON 2
#define RIGHT_MOUSE_BUTTON 3

class Canvas {
public:
    Canvas();
    Canvas(int x_resolution, int y_resolution);
    ~Canvas();
    
    void init(int argc, char * argv[]);
private:
    int last_mouse_button_pressed = 0;
    int x_resolution = X_RESOLUTION;
    int y_resolution = Y_RESOLUTION;
    
    static void display();
    static void reshape(int w, int h);
    static void in_mouse(int mouse_button, int state, int x, int y);
    static void in_keyboard(unsigned char key, int x, int y);
    static void arrow_keys(int key, int x, int y);
    void spindisplay();
};

Canvas::Canvas() { }

Canvas::~Canvas() { }

Canvas::Canvas(int x_resolution, int y_resolution)
{
    this->x_resolution = x_resolution;
    this->y_resolution = y_resolution;
}

void Canvas::display()
{
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity ();

    glFlush ();
}

void Canvas::reshape(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho (0.0, X_RESOLUTION, Y_RESOLUTION, 0, -1.0, 1.0);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
}

void Canvas::in_mouse(int mouse_button, int state, int x, int y)
{
    // To be written
}

void Canvas::in_keyboard(unsigned char key, int x, int y)
{
    // To be written
}

void Canvas::arrow_keys(int key, int x, int y)
{
    // To be written
}

void Canvas::init(int argc, char **argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (this->x_resolution, this->y_resolution);
    glutInitWindowPosition (0,0);
    glutCreateWindow (WINDOW_TITLE);
    glutDisplayFunc (display);
    glutReshapeFunc (reshape);
    glutMouseFunc (in_mouse);
    glutKeyboardFunc (in_keyboard);
    glutSpecialFunc (arrow_keys);
    glutMainLoop ();
}

#endif /* Canvas_hpp */
