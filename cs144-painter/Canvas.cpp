//
//  Canvas.cpp
//  cs144-painter
//


#include "Canvas.hpp"

// Initializes the context for canvas members
Context Canvas::cntxt;
std::vector< Drawable<int>* > Canvas::drawables;

Canvas::Canvas() { }

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
    if (!drawables.empty())
    {
        for (auto d : drawables)
            (*d).draw();
    }
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
        if (cntxt.last_mouse_button_pressed == RIGHT_MOUSE_BUTTON)
        {
            std::cout << "first click (x1 = " << x << ", y1 = " << y << ") after menu selection: " << typeid(*cntxt.drawable).name() << std::endl;
            
            cntxt.verts.push_back(x);
            cntxt.verts.push_back(y);
            
            if (cntxt.bezier) cntxt.bezier_click_count = 1;
            
            cntxt.currently_drawing = true;
        }
        else if (cntxt.bezier)
        {
            cntxt.bezier_click_count++;
            
            std::cout << "click number " << cntxt.bezier_click_count << ": (x2 = " << x << ", y2 = " << y << ") for bezier "<< std::endl;
            
            cntxt.verts.push_back(x);
            cntxt.verts.push_back(y);
            
            if (cntxt.bezier_click_count >= 4) {
                (*cntxt.drawable).verts = cntxt.verts;
                drawables.push_back(cntxt.drawable);
                
                cntxt.verts.clear();
                
                
                cntxt.bezier = false;
                cntxt.bezier_click_count = 0;
                cntxt.currently_drawing = false;
            }
        }
        else if (cntxt.last_mouse_button_pressed == LEFT_MOUSE_BUTTON && cntxt.currently_drawing == true)
        {
            std::cout << "second click (x2 = " << x << ", y2 = " << y << ") after menu selection: " << typeid(*cntxt.drawable).name() << std::endl;
            
            cntxt.verts.push_back(x);
            cntxt.verts.push_back(y);
            (*cntxt.drawable).verts = cntxt.verts;
            drawables.push_back(cntxt.drawable);
            
            cntxt.verts.clear();
            
            cntxt.currently_drawing = false;
        }
        cntxt.last_mouse_button_pressed = LEFT_MOUSE_BUTTON;
        cntxt.left_mouse_button_x = x;
        cntxt.left_mouse_button_y = y;
        
        glutPostRedisplay ();
    }
    if ((mouse_button == GLUT_MIDDLE_BUTTON) && (state == GLUT_DOWN))
    {
        
        cntxt.last_mouse_button_pressed = MIDDLE_MOUSE_BUTTON;
        cntxt.middle_mouse_button_x = x;
        cntxt.middle_mouse_button_y = y;
        
        glutPostRedisplay ();
    }
    if ((mouse_button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN))
    {
        
        cntxt.last_mouse_button_pressed = RIGHT_MOUSE_BUTTON;
        cntxt.right_mouse_button_x = x;
        cntxt.right_mouse_button_y = y;
        printf("right mouse button pressed\n");
        glutPostRedisplay ();
    }
}

/*
 Create the context menus.  Each submenu is declared and created before its
 parent because the parent call includes the submenu.  In this way the
 submenu exists for the parent call to invoke and no error is created.
 */
void Canvas::create_context_menu()
{
    int ellFillMenu, ellOutlineMenu, rectangleFillMenu, rectangleOutlineMenu,
    bezierSubMenu, ellipseSubMenu, lineSubMenu, rectangleSubMenu;
    
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
    glutAttachMenu (GLUT_RIGHT_BUTTON);
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
    if (cntxt.currently_drawing) {
        delete cntxt.drawable;
        
        cntxt.verts.clear();
        cntxt.currently_drawing = false;
        cntxt.bezier = false;
        cntxt.bezier_click_count = 0;
    }
    switch (value)
    {
        case recFillRed:
            printf ("add rectangle -> filled -> red\n");
            cntxt.drawable = new Rectangle<int>(true, Colors::RED);
            break;
        case recFillGreen:
            printf ("add rectangle -> filled -> green\n");
            cntxt.drawable = new Rectangle<int>(true, Colors::GREEN);
            break;
        case recFillBlue:
            printf ("add rectangle -> filled -> blue\n");
            cntxt.drawable = new Rectangle<int>(true, Colors::BLUE);
            break;
        case recFillYellow:
            printf ("add rectangle -> filled -> yellow\n");
            cntxt.drawable = new Rectangle<int>(true, Colors::YELLOW);
            break;
        case recFillPurple:
            printf ("add rectangle -> filled -> purple\n");
            cntxt.drawable = new Rectangle<int>(true, Colors::PURPLE);
            break;
        case recFillOrange:
            printf ("add rectangle -> filled -> orange\n");
            cntxt.drawable = new Rectangle<int>(true, Colors::ORANGE);
            break;
        case recFillWhite:
            printf ("add rectangle -> filled -> white\n");
            cntxt.drawable = new Rectangle<int>(true, Colors::WHITE);
            break;
        case recFillBlack:
            printf ("add rectangle -> filled -> black\n");
            cntxt.drawable = new Rectangle<int>(true, Colors::BLACK);
            break;
        case recOutlineRed:
            printf ("add rectangle -> outline -> red\n");
            cntxt.drawable = new Rectangle<int>(false, Colors::RED);
            break;
        case recOutlineGreen:
            printf ("add rectangle -> outline -> green\n");
            cntxt.drawable = new Rectangle<int>(false, Colors::GREEN);
            break;
        case recOutlineBlue:
            printf ("add rectangle -> outline -> blue\n");
            cntxt.drawable = new Rectangle<int>(false, Colors::BLUE);
            break;
        case recOutlineYellow:
            printf ("add rectangle -> outline -> yellow\n");
            cntxt.drawable = new Rectangle<int>(false, Colors::YELLOW);
            break;
        case recOutlinePurple:
            printf ("add rectangle -> outline -> purple\n");
            cntxt.drawable = new Rectangle<int>(false, Colors::PURPLE);
            break;
        case recOutlineOrange:
            printf ("add rectangle -> outline -> orange\n");
            cntxt.drawable = new Rectangle<int>(false, Colors::ORANGE);
            break;
        case recOutlineWhite:
            printf ("add rectangle -> outline -> white\n");
            cntxt.drawable = new Rectangle<int>(false, Colors::WHITE);
            break;
        case recOutlineBlack:
            printf ("add rectangle -> outline -> black\n");
            cntxt.drawable = new Rectangle<int>(false, Colors::BLACK);
            break;
        case ellFillRed:
            printf ("add ellipse -> fill -> red\n");
            cntxt.drawable = new Ellipse<int>(true, Colors::RED);
            break;
        case ellFillGreen:
            printf ("add ellipse -> fill -> green\n");
            cntxt.drawable = new Ellipse<int>(true, Colors::GREEN);
            break;
        case ellFillBlue:
            printf ("add ellipse -> fill -> blue\n");
            cntxt.drawable = new Ellipse<int>(true, Colors::BLUE);
            break;
        case ellFillYellow:
            printf ("add ellipse -> fill -> yellow\n");
            cntxt.drawable = new Ellipse<int>(true, Colors::YELLOW);
            break;
        case ellFillPurple:
            printf ("add ellipse -> fill -> purple\n");
            cntxt.drawable = new Ellipse<int>(true, Colors::PURPLE);
            break;
        case ellFillOrange:
            printf ("add ellipse -> fill -> orange\n");
            cntxt.drawable = new Ellipse<int>(true, Colors::ORANGE);
            break;
        case ellFillWhite:
            printf ("add ellipse -> fill -> white\n");
            cntxt.drawable = new Ellipse<int>(true, Colors::WHITE);
            break;
        case ellFillBlack:
            printf ("add ellipse -> fill -> black\n");
            cntxt.drawable = new Ellipse<int>(true, Colors::BLACK);
            break;
        case ellOutRed:
            printf ("add ellipse -> outline -> red\n");
            cntxt.drawable = new Ellipse<int>(false, Colors::RED);
            break;
        case ellOutGreen:
            printf ("add ellipse -> outline -> green\n");
            cntxt.drawable = new Ellipse<int>(false, Colors::GREEN);
            break;
        case ellOutBlue:
            printf ("add ellipse -> outline -> blue\n");
            cntxt.drawable = new Ellipse<int>(false, Colors::BLUE);
            break;
        case ellOutYellow:
            printf ("add ellipse -> outline -> yellow\n");
            cntxt.drawable = new Ellipse<int>(false, Colors::YELLOW);
            break;
        case ellOutPurple:
            printf ("add ellipse -> outline -> purple\n");
            cntxt.drawable = new Ellipse<int>(false, Colors::PURPLE);
            break;
        case ellOutOrange:
            printf ("add ellipse -> outline -> orange\n");
            cntxt.drawable = new Ellipse<int>(false, Colors::ORANGE);
            break;
        case ellOutWhite:
            printf ("add ellipse -> outline -> white\n");
            cntxt.drawable = new Ellipse<int>(false, Colors::WHITE);
            break;
        case ellOutBlack:
            printf ("add ellipse -> outline -> black\n");
            cntxt.drawable = new Ellipse<int>(false, Colors::BLACK);
            break;
        case lineRed:
            printf ("add line -> red\n");
            cntxt.drawable = new Line<int>(Colors::RED);
            break;
        case lineGreen:
            printf ("add line -> green\n");
            cntxt.drawable = new Line<int>(Colors::GREEN);
            break;
        case lineBlue:
            printf ("add line -> blue\n");
            cntxt.drawable = new Line<int>(Colors::BLUE);
            break;
        case lineYellow:
            printf ("add line -> yellow\n");
            cntxt.drawable = new Line<int>(Colors::YELLOW);
            break;
        case linePurple:
            printf ("add line -> purple\n");
            cntxt.drawable = new Line<int>(Colors::PURPLE);
            break;
        case lineOrange:
            printf ("add line -> orange\n");
            cntxt.drawable = new Line<int>(Colors::ORANGE);
            break;
        case lineWhite:
            printf ("add line -> white\n");
            cntxt.drawable = new Line<int>(Colors::WHITE);
            break;
        case lineBlack:
            printf ("add line -> black\n");
            cntxt.drawable = new Line<int>(Colors::BLACK);
            break;
        case bezRed:
            printf ("add bezier -> red\n");
            cntxt.drawable = new Bezier<int>(Colors::RED);
            cntxt.bezier = true;
            break;
        case bezGreen:
            printf ("add bezier -> green\n");
            cntxt.drawable = new Bezier<int>(Colors::GREEN);
            cntxt.bezier = true;
            break;
        case bezBlue:
            printf ("add bezier -> blue\n");
            cntxt.drawable = new Bezier<int>(Colors::BLUE);
            cntxt.bezier = true;
            break;
        case bezYellow:
            printf ("add bezier -> yellow\n");
            cntxt.drawable = new Bezier<int>(Colors::YELLOW);
            cntxt.bezier = true;
            break;
        case bezPurple:
            printf ("add bezier -> purple\n");
            cntxt.drawable = new Bezier<int>(Colors::PURPLE);
            cntxt.bezier = true;
            break;
        case bezOrange:
            printf ("add bezier -> orange\n");
            cntxt.drawable = new Bezier<int>(Colors::ORANGE);
            cntxt.bezier = true;
            break;
        case bezWhite:
            printf ("add bezier -> white\n");
            cntxt.drawable = new Bezier<int>(Colors::WHITE);
            cntxt.bezier = true;
            break;
        case bezBlack:
            printf ("add bezier -> black\n");
            cntxt.drawable = new Bezier<int>(Colors::BLACK);
            cntxt.bezier = true;
            break;
        default:
            break;
    }
    cntxt.last_mouse_button_pressed = RIGHT_MOUSE_BUTTON;
    glutPostRedisplay();
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
    glutMainLoop ();
}

int main(int argc, char * argv[])
{
    Canvas c;
    c.init(argc, argv);
}