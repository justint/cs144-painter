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
#include <vector>

#include "Drawable.hpp"

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
    ~Canvas();
    
    static Context c;
    
    void init(int argc, char * argv[]);
private:
    int x_resolution = X_RESOLUTION;
    int y_resolution = Y_RESOLUTION;
    
    std::vector< Drawable<int> > drawables;
    
    void create_context_menu();
    static void menu(int value);
    
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

/*
 Main draw loop, is called after window is initialized.
 */
void Canvas::display()
{
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity ();
    glFlush ();
}

void Canvas::reshape(const int w, const int h)
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
    if (x < 20)
    {
        x = 20;
    }
    if (x > (X_RESOLUTION - 20))
    {
        x = X_RESOLUTION - 20;
    }
    if (y < 20)
    {
        y = 20;
    }
    if (y > (Y_RESOLUTION - 20))
    {
        y = Y_RESOLUTION - 20;
    }
    if ((mouse_button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
    {
        
        c.last_mouse_button_pressed = LEFT_MOUSE_BUTTON;
        c.left_mouse_button_x = x;
        c.left_mouse_button_y = y;
        
        glutPostRedisplay ();
    }
    if ((mouse_button == GLUT_MIDDLE_BUTTON) && (state == GLUT_DOWN))
    {
        /*
        c.last_mouse_button_pressed = MIDDLE_MOUSE_BUTTON;
        c.middle_mouse_button_x = x;
        c.middle_mouse_button_y = y;
         */
        glutPostRedisplay ();
    }
    if ((mouse_button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN))
    {
        /*
        c.last_mouse_button_pressed = RIGHT_MOUSE_BUTTON;
        c.right_mouse_button_x = x;
        c.right_mouse_button_y = y;
         */
        glutPostRedisplay ();
    }
}

void Canvas::in_keyboard(unsigned char key, int x, int y)
{
    // To be written
}

void Canvas::arrow_keys(const int key, int x, int y)
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
    create_context_menu();
    glutDisplayFunc (display);
    glutReshapeFunc (reshape);
    glutMouseFunc (in_mouse);
    glutKeyboardFunc (in_keyboard);
    glutSpecialFunc (arrow_keys);
    glutMainLoop ();
}

/*
 This case statement is the primary controller for the menu -> draw().
 Every case is covered such that the call to draw can be sent directly
 from this case statement.  The printf statements exist for debugging.
 Each time the context menu is clicked it shows the printed path to
 compare that it matches the expected output.
 */
void Canvas::menu (int value)
{
    switch (value)
    {
        case recFillRed:
            printf ("add rectangle -> filled -> red\n");
            //do something
            break;
        case recFillGreen:
            printf ("add rectangle -> filled -> green\n");
            //do something
            break;
        case recFillBlue:
            printf ("add rectangle -> filled -> blue\n");
            //do something
            break;
        case recFillYellow:
            printf ("add rectangle -> filled -> yellow\n");
            //do something
            break;
        case recFillPurple:
            printf ("add rectangle -> filled -> purple\n");
            //do something
            break;
        case recFillOrange:
            printf ("add rectangle -> filled -> orange\n");
            //do something
            break;
        case recFillWhite:
            printf ("add rectangle -> filled -> white\n");
            //do something
            break;
        case recFillBlack:
            printf ("add rectangle -> filled -> black\n");
            //do something
            break;
        case recOutlineRed:
            printf ("add rectangle -> outline -> red\n");
            //do something
            break;
        case recOutlineGreen:
            printf ("add rectangle -> outline -> green\n");
            //do something
            break;
        case recOutlineBlue:
            printf ("add rectangle -> outline -> blue\n");
            //do something
            break;
        case recOutlineYellow:
            printf ("add rectangle -> outline -> yellow\n");
            //do something
            break;
        case recOutlinePurple:
            printf ("add rectangle -> outline -> purple\n");
            //do something
            break;
        case recOutlineOrange:
            printf ("add rectangle -> outline -> orange\n");
            //do something
            break;
        case recOutlineWhite:
            printf ("add rectangle -> outline -> white\n");
            //do something
            break;
        case recOutlineBlack:
            printf ("add rectangle -> outline -> black\n");
            //do something
            break;
        case ellFillRed:
            printf ("add ellipse -> fill -> red\n");
            //do something
            break;
        case ellFillGreen:
            printf ("add ellipse -> fill -> green\n");
            //do something
            break;
        case ellFillBlue:
            printf ("add ellipse -> fill -> blue\n");
            //do something
            break;
        case ellFillYellow:
            printf ("add ellipse -> fill -> yellow\n");
            //do something
            break;
        case ellFillPurple:
            printf ("add ellipse -> fill -> purple\n");
            //do something
            break;
        case ellFillOrange:
            printf ("add ellipse -> fill -> orange\n");
            //do something
            break;
        case ellFillWhite:
            printf ("add ellipse -> fill -> white\n");
            //do something
            break;
        case ellFillBlack:
            printf ("add ellipse -> fill -> black\n");
            //do something
            break;
        case ellOutRed:
            printf ("add ellipse -> outline -> red\n");
            //do something
            break;
        case ellOutGreen:
            printf ("add ellipse -> outline -> green\n");
            //do something
            break;
        case ellOutBlue:
            printf ("add ellipse -> outline -> blue\n");
            //do something
            break;
        case ellOutYellow:
            printf ("add ellipse -> outline -> yellow\n");
            //do something
            break;
        case ellOutPurple:
            printf ("add ellipse -> outline -> purple\n");
            //do something
            break;
        case ellOutOrange:
            printf ("add ellipse -> outline -> orange\n");
            //do something
            break;
        case ellOutWhite:
            printf ("add ellipse -> outline -> white\n");
            //do something
            break;
        case ellOutBlack:
            printf ("add ellipse -> outline -> black\n");
            //do something
            break;
        case lineRed:
            printf ("add line -> red\n");
            //do something
            break;
        case lineGreen:
            printf ("add line -> green\n");
            //do something
            break;
        case lineBlue:
            printf ("add line -> blue\n");
            //do something
            break;
        case lineYellow:
            printf ("add line -> yellow\n");
            //do something
            break;
        case linePurple:
            printf ("add line -> purple\n");
            //do something
            break;
        case lineOrange:
            printf ("add line -> orange\n");
            //do something
            break;
        case lineWhite:
            printf ("add line -> white\n");
            //do something
            break;
        case lineBlack:
            printf ("add line -> black\n");
            //do something
            break;
        case bezRed:
            printf ("add bezier -> red\n");
            //do something
            break;
        case bezGreen:
            printf ("add bezier -> green\n");
            //do something
            break;
        case bezBlue:
            printf ("add bezier -> blue\n");
            //do something
            break;
        case bezYellow:
            printf ("add bezier -> yellow\n");
            //do something
            break;
        case bezPurple:
            printf ("add bezier -> purple\n");
            //do something
            break;
        case bezOrange:
            printf ("add bezier -> orange\n");
            //do something
            break;
        case bezWhite:
            printf ("add bezier -> white\n");
            //do something
            break;
        case bezBlack:
            printf ("add bezier -> black\n");
            //do something
            break;
        default:
            break;
    }
    glutPostRedisplay();
}


/*
 Create the context menus.  Each submenu is declared and created before its
 parent because the parent call includes the submenu.  In this way the
 submenu exists for the parent call to invoke and no error is created.
 */
void Canvas::create_context_menu()
{
    int ellFillMenu, ellOutlineMenu, rectangleFillMenu, rectangleOutlineMenu,
    mainMenu, bezierSubMenu, ellipseSubMenu, lineSubMenu, rectangleSubMenu;
    
    //create rectangleFillMenu
    rectangleFillMenu = glutCreateMenu (menu);
    //color options: red green blue yellow purple orange white black
    glutAddMenuEntry ("red", recFillRed);
    glutAddMenuEntry ("green", recFillGreen);
    glutAddMenuEntry ("blue", recFillBlue);
    glutAddMenuEntry ("yellow", recFillYellow);
    glutAddMenuEntry ("purple", recFillPurple);
    glutAddMenuEntry ("orange", recFillOrange);
    glutAddMenuEntry ("white", recFillWhite);
    glutAddMenuEntry ("black", recFillBlack);
    //end rectangleFillMenu
    
    //create rectangleOutlineMenu
    rectangleOutlineMenu = glutCreateMenu (menu);
    //color options: red green blue yellow purple orange white black
    glutAddMenuEntry ("red", recOutlineRed);
    glutAddMenuEntry ("green", recOutlineGreen);
    glutAddMenuEntry ("blue", recOutlineBlue);
    glutAddMenuEntry ("yellow", recOutlineYellow);
    glutAddMenuEntry ("purple", recOutlinePurple);
    glutAddMenuEntry ("orange", recOutlineOrange);
    glutAddMenuEntry ("white", recOutlineWhite);
    glutAddMenuEntry ("black", recOutlineBlack);
    //end rectangleOutlineMenu
    
    
    //create rectangleSubMenu
    rectangleSubMenu = glutCreateMenu (menu);
    glutAddSubMenu ("filled", rectangleFillMenu);
    glutAddSubMenu ("outline", rectangleOutlineMenu);
    //end rectangleSubMenu
    
    //create ellOutlineMenu
    ellOutlineMenu = glutCreateMenu(menu);
    glutAddMenuEntry ("red", ellOutRed);
    glutAddMenuEntry ("green", ellOutGreen);
    glutAddMenuEntry ("blue", ellOutBlue);
    glutAddMenuEntry ("yellow", ellOutYellow);
    glutAddMenuEntry ("purple", ellOutPurple);
    glutAddMenuEntry ("orange", ellOutOrange);
    glutAddMenuEntry ("white", ellOutWhite);
    glutAddMenuEntry ("black", ellOutBlack);
    //end ellOutlineMenu
    
    //create ellFillMenu
    ellFillMenu = glutCreateMenu(menu);
    glutAddMenuEntry ("red", ellFillRed);
    glutAddMenuEntry ("green", ellFillGreen);
    glutAddMenuEntry ("blue", ellFillBlue);
    glutAddMenuEntry ("yellow", ellFillYellow);
    glutAddMenuEntry ("purple", ellFillPurple);
    glutAddMenuEntry ("orange", ellFillOrange);
    glutAddMenuEntry ("white", ellFillWhite);
    glutAddMenuEntry ("black", ellFillBlack);
    //end ellFillMenu
    
    //create ellipseSubMenu
    ellipseSubMenu = glutCreateMenu (menu);
    glutAddSubMenu ("filled", ellFillMenu);
    glutAddSubMenu ("outline", ellOutlineMenu);
    //end ellipseSubMenu
    
    //create lineSubmenu
    lineSubMenu = glutCreateMenu(menu);
    //color options: red green blue yellow purple orange white black
    glutAddMenuEntry ("red", lineRed);
    glutAddMenuEntry ("green", lineGreen);
    glutAddMenuEntry ("blue", lineBlue);
    glutAddMenuEntry ("yellow", lineYellow);
    glutAddMenuEntry ("purple", linePurple);
    glutAddMenuEntry ("orange", lineOrange);
    glutAddMenuEntry ("white", lineWhite);
    glutAddMenuEntry ("black", lineBlack);
    //end lineSubMenu
    
    //create bezier subMenu
    bezierSubMenu = glutCreateMenu(menu);
    //color options: red green blue yellow purple orange white black
    glutAddMenuEntry ("red", bezRed);
    glutAddMenuEntry ("green", bezGreen);
    glutAddMenuEntry ("blue", bezBlue);
    glutAddMenuEntry ("yellow", bezYellow);
    glutAddMenuEntry ("purple", bezPurple);
    glutAddMenuEntry ("orange", bezOrange);
    glutAddMenuEntry ("white", bezWhite);
    glutAddMenuEntry ("black", bezBlack);
    //end bezier subMenu
    
    //create main menu
    glutCreateMenu (menu);
    //add first set of options
    glutAddSubMenu ("add rectangle", rectangleSubMenu);
    glutAddSubMenu ("add ellipse", ellipseSubMenu);
    glutAddSubMenu ("add line", lineSubMenu);
    glutAddSubMenu ("add bezier curve", bezierSubMenu);
    //the button that will activate the menu
    glutAttachMenu (GLUT_LEFT_BUTTON);
}

#endif /* Canvas_hpp */
