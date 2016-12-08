#include <stdlib.h>
#include <math.h>


#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#elif __linux__
#include <GL/glut.h>
#endif





#define X_RESOLUTION 640
#define Y_RESOLUTION 480
#define LEFT_MOUSE_BUTTON 1
#define MIDDLE_MOUSE_BUTTON 2
#define RIGHT_MOUSE_BUTTON 3




GLsizei left_mouse_button_x = 120, left_mouse_button_y = 240;
GLsizei middle_mouse_button_x = 220, middle_mouse_button_y = 240;
GLsizei right_mouse_button_x = 320, right_mouse_button_y = 240;
int last_mouse_button_pressed = 0;




void draw_square_filled ()
{
    GLsizei square_center_x = 20, square_center_y = 20;
    
    if (left_mouse_button_x > 20)
    {
        if (left_mouse_button_x <= X_RESOLUTION - 20)
        {
            square_center_x = left_mouse_button_x;
        }
        else
        {
            square_center_x = X_RESOLUTION - 20;
        }
    }
    else
    {
        square_center_x = 20;
    }
    if (left_mouse_button_y > 20)
    {
        if (left_mouse_button_y <= Y_RESOLUTION)
        {
            square_center_y = left_mouse_button_y;
        }
        else
        {
            square_center_y = Y_RESOLUTION - 20;
        }
    }
    else
    {
        square_center_y = 20;
    }
    glColor3ub (255, 0, 0);
    glBegin (GL_POLYGON);
    glVertex3f (square_center_x - 20, square_center_y - 20, 0);
    glVertex3f (square_center_x + 20, square_center_y - 20, 0);
    glVertex3f (square_center_x + 20, square_center_y + 20, 0);
    glVertex3f (square_center_x - 20, square_center_y + 20, 0);
    glEnd ();
    glFlush ();
}




void draw_circle_filled ()
{
    GLsizei circle_center_x = 20, circle_center_y = 20;
    float theta, radius = 20.0, circle_iterations = 24.0;
    
    if (right_mouse_button_x > 20)
    {
        if (right_mouse_button_x <= (X_RESOLUTION - 20))
        {
            circle_center_x = right_mouse_button_x;
        }
        else
        {
            circle_center_x = X_RESOLUTION - 20;
        }
    }
    else
    {
        circle_center_x = 20;
    }
    if (right_mouse_button_y > 20)
    {
        if (right_mouse_button_y <= (Y_RESOLUTION - 20))
        {
            circle_center_y = right_mouse_button_y;
        }
        else
        {
            circle_center_y = Y_RESOLUTION - 20;
        }
    }
    else
    {
        circle_center_y = 20;
    }
    glColor3ub (0, 0, 255);
    glPolygonMode (GL_FRONT, GL_FILL);
    glBegin (GL_POLYGON);
    glVertex3f (circle_center_x + radius, circle_center_y, 0.0f);
    for (theta = 0; theta < 2 * M_PI; theta += M_PI / circle_iterations)
    {
        glVertex3f (circle_center_x + cos(theta) * radius, circle_center_y + sin(theta) * radius, 0.0f);
    }
    glEnd();
    glFlush ();
}





void draw_triangle_filled ()
{
    GLsizei triangle_center_x = 20, triangle_center_y = 20;
    
    if (middle_mouse_button_x > 20)
    {
        if (middle_mouse_button_x <= (X_RESOLUTION - 20))
        {
            triangle_center_x = middle_mouse_button_x;
        }
        else
        {
            triangle_center_x = X_RESOLUTION - 20;
        }
    }
    else
    {
        triangle_center_x = 20;
    }
    if (middle_mouse_button_y > 20)
    {
        if (middle_mouse_button_y <= (Y_RESOLUTION - 20))
        {
            triangle_center_y = middle_mouse_button_y;
        }
        else
        {
            triangle_center_y = Y_RESOLUTION - 20;
        }
    }
    else
    {
        triangle_center_y = 20;
    }
    glColor3ub (0, 255, 0);
    glBegin (GL_POLYGON);
    glVertex3f (triangle_center_x, triangle_center_y - 20, 0);
    glVertex3f (triangle_center_x - 20, triangle_center_y + 20, 0);
    glVertex3f (triangle_center_x + 20, triangle_center_y + 20, 0);
    glEnd ();
    glFlush ();
}





void display (void)
{
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity ();
    draw_square_filled ();
    draw_circle_filled ();
    draw_triangle_filled ();
    glFlush ();
}





void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho (0.0, X_RESOLUTION, Y_RESOLUTION, 0, -1.0, 1.0);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
}





void spindisplay(void)
{
    glutPostRedisplay();
}





void mouse (int mouse_button, int state, int x, int y)
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
        last_mouse_button_pressed = LEFT_MOUSE_BUTTON;
        left_mouse_button_x = x;
        left_mouse_button_y = y;
        glutPostRedisplay ();
    }
    if ((mouse_button == GLUT_MIDDLE_BUTTON) && (state == GLUT_DOWN))
    {
        last_mouse_button_pressed = MIDDLE_MOUSE_BUTTON;
        middle_mouse_button_x = x;
        middle_mouse_button_y = y;
        glutPostRedisplay ();
    }
    if ((mouse_button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN))
    {
        last_mouse_button_pressed = RIGHT_MOUSE_BUTTON;
        right_mouse_button_x = x;
        right_mouse_button_y = y;
        glutPostRedisplay ();
    }
}





void keyboard (unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
            exit (0);
            break;
        default:
            break;
    }
}





void arrow_keys (int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_UP:
            switch (last_mouse_button_pressed)
        {
            case LEFT_MOUSE_BUTTON:
                if (left_mouse_button_y >= 20)
                {
                    left_mouse_button_y--;
                    glutPostRedisplay ();
                }
                break;
            case MIDDLE_MOUSE_BUTTON:
                if (middle_mouse_button_y >= 20)
                {
                    middle_mouse_button_y--;
                    glutPostRedisplay ();
                }
                break;
            case RIGHT_MOUSE_BUTTON:
                if (right_mouse_button_y >= 20)
                {
                    right_mouse_button_y--;
                    glutPostRedisplay ();
                }
                break;
            default:
                break;
        }
            break;
        case GLUT_KEY_DOWN:
            switch (last_mouse_button_pressed)
        {
            case LEFT_MOUSE_BUTTON:
                if (left_mouse_button_y < Y_RESOLUTION - 20)
                {
                    left_mouse_button_y++;
                    glutPostRedisplay ();
                }
                break;
            case MIDDLE_MOUSE_BUTTON:
                if (middle_mouse_button_y < Y_RESOLUTION - 20)
                {
                    middle_mouse_button_y++;
                    glutPostRedisplay ();
                }
                break;
            case RIGHT_MOUSE_BUTTON:
                if (right_mouse_button_y < Y_RESOLUTION - 20)
                {
                    right_mouse_button_y++;
                    glutPostRedisplay ();
                }
                break;
            default:
                break;
        }
            break;
        case GLUT_KEY_LEFT:
            switch (last_mouse_button_pressed)
        {
            case LEFT_MOUSE_BUTTON:
                if (left_mouse_button_x > 20)
                {
                    left_mouse_button_x--;
                    glutPostRedisplay ();
                }
                break;
            case MIDDLE_MOUSE_BUTTON:
                if (middle_mouse_button_x > 20)
                {
                    middle_mouse_button_x--;
                    glutPostRedisplay ();
                }
                break;
            case RIGHT_MOUSE_BUTTON:
                if (right_mouse_button_x > 20)
                {
                    right_mouse_button_x--;
                    glutPostRedisplay ();
                }
                break;
            default:
                break;
        }
            break;
        case GLUT_KEY_RIGHT:
            switch (last_mouse_button_pressed)
        {
            case LEFT_MOUSE_BUTTON:
                if (left_mouse_button_x < X_RESOLUTION - 20)
                {
                    left_mouse_button_x++;
                    glutPostRedisplay ();
                }
                break;
            case MIDDLE_MOUSE_BUTTON:
                if (middle_mouse_button_x < X_RESOLUTION - 20)
                {
                    middle_mouse_button_x++;
                    glutPostRedisplay ();
                }
                break;
            case RIGHT_MOUSE_BUTTON:
                if (right_mouse_button_x < X_RESOLUTION - 20)
                {
                    right_mouse_button_x++;
                    glutPostRedisplay ();
                }
                break;
        }
            break;
        default:
            break;
    }
}




// Named _main to avoid collision with Canvas
int _main (int argc, char *argv[])
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (X_RESOLUTION, Y_RESOLUTION);
    glutInitWindowPosition (0,0);
    glutCreateWindow ("Mouse keyboard click demo");
    glutDisplayFunc (display);
    glutReshapeFunc (reshape);
    glutMouseFunc (mouse);
    glutKeyboardFunc (keyboard);
    glutSpecialFunc (arrow_keys);
    glutMainLoop ();
}