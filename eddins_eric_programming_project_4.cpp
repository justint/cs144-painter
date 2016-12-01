
//path in local repo:   cd Documents/cs116a/hw4/hw4


/*Added all the menu options and context menu displays properly
TODO: implement drawing functions*/


#include <math.h>
#include <stdio.h>


#ifdef __APPLE__
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
  #include <GLUT/glut.h>
#elif __linux__
  #include <GL/glut.h>
#endif

//using namespace std;

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

bool mouseRightDown = false; //true if mouse right button is clicked
int mousex, mousey, mousex1, mousex2, mousey1, mousey2; //storage for the captured coordinates
int winHeight = 640;
int winWidth = 480;

//these enums will be used as indexes into an array of COLORS
enum Color {
    red, green, blue, yellow, purple, orange, white, black
};

//a small struct to hold the three values that will determine rgb colors
struct rgb {
    int r, g, b;//values from 0-255
};

//constants to be entered into the COLORS array for easy reference
const rgb RED = {255, 0, 0};
const rgb GREEN = {0,128,0};
const rgb BLUE = {0,0,255};
const rgb YELLOW = {255,255,0};
const rgb PURPLE = {128,0,128};
const rgb ORANGE = {255,165,0};
const rgb WHITE = {255,255,255};
const rgb BLACK = {0,0,0};

const rgb COLORS[] = {RED, GREEN, BLUE, YELLOW, PURPLE, ORANGE, WHITE, BLACK};

void colorToString()
{
    printf("COLORS[red]: %d,%d,%d\n",COLORS[red].r, COLORS[red].g, COLORS[red].b);
    printf("COLORS[green]: %d,%d,%d\n",COLORS[green].r, COLORS[green].g, COLORS[green].b);
    printf("COLORS[blue]: %d,%d,%d\n",COLORS[blue].r, COLORS[blue].g, COLORS[blue].b);
    printf("COLORS[yellow]: %d,%d,%d\n",COLORS[yellow].r, COLORS[yellow].g, COLORS[yellow].b);
    printf("COLORS[purple]: %d,%d,%d\n",COLORS[purple].r, COLORS[purple].g, COLORS[purple].b);
    printf("COLORS[orange]: %d,%d,%d\n",COLORS[orange].r, COLORS[orange].g, COLORS[orange].b);
    printf("COLORS[white]: %d,%d,%d\n",COLORS[white].r, COLORS[white].g, COLORS[white].b);
    printf("COLORS[black]: %d,%d,%d\n",COLORS[black].r, COLORS[black].g, COLORS[black].b);
}


//
// A general OpenGL initialization function.  Sets all of the initial parameters.
void InitGL (int width, int height)     // We call this right after our OpenGL window is created.
{
  glClearColor (255.0f, 255.0f, 255.0f, 0.0f); // This will clear the background color to white
  glClearDepth (1.0);           // Enables clearing of the depth buffer
  glDepthFunc (GL_LESS);        // The type of depth test to do
  glEnable (GL_DEPTH_TEST);     // Enables depth testing
  glShadeModel (GL_SMOOTH);     // Enables smooth color shading
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();            // Reset the projection matrix
  gluPerspective (45.0f, (GLfloat) width / (GLfloat) height, 0.1f, 100.0f); // Calculate the aspect ratio of the window
  glMatrixMode (GL_MODELVIEW);
}

/*struct color{
  int rValue;
  int gValue;
  int bValue;
};*/

//vector<color> COLORS

void ReSizeGLScene (int width, int height)
{
  if (height == 0)                  // Prevent A Divide By Zero If The Window Is Too Small
  {
    height = 1;
  }
  glViewport (0, 0, width, height); // Reset The Current Viewport And Perspective Transformation
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective (45.0f, (GLfloat) width / (GLfloat) height, 0.1f, 100.0f);
  glMatrixMode (GL_MODELVIEW);
}




void DrawGLScene ()
{
  float radius = 1.0;
  float theta;
  float major_axis = 1.0;
  float minor_axis = 0.5;

  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer
  glLoadIdentity ();                                   // Reset The View
// swap buffers to display, since we're double buffered.
  glutSwapBuffers ();
}

void mouse(int button, int state, int x, int y)
{
  if (button == GLUT_RIGHT_BUTTON)
  {
    mouseRightDown = (state == GLUT_DOWN) ? true : false;

    //save the mouse position
    mousex = x;
    mousey = y;
    printf("made a mouseclick. mousex: %d, mousey: %d\n",mousex, mousey);
  }


}


void clickCollector()
{
  //have to figure out a way to register mouseclicks during loop
  while(mouseRightDown)
  {
    printf("inside clickCollector while loop\n");
    mousex1 = mousex;
    mousey1 = mousey;
    mouseRightDown = true;
  }
  printf("after while loop\n");
  printf("mousex1: %d, mousey1: %d\n",mousex1,mousey1);
  mouseRightDown = false;
}


/*
This case statement is the primary controller for the menu -> draw().
Every case is covered such that the call to draw can be sent directly
from this case statement.  The printf statements exist for debugging.
Each time the context menu is clicked it shows the printed path to
compare that it matches the expected output.
*/
void menu (int value)
{
  switch (value)
  {
    case recFillRed:
      printf ("add rectangle -> filled -> red\n");
      clickCollector();
      printf("mousex1: %d, mousey1: %d, mousex2: %d, mousey2: %d\n",mousex1, mousey2, mousex2,mousey2);
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
void contextMenu()
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



int main (int argc, char *argv[])
{
  int window;

  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
  glutInitWindowSize (winHeight, winWidth);
  glutInitWindowPosition (0, 0);
  window = glutCreateWindow ("Eddins Drawing Program");
  //create context menus
  contextMenu();
  colorToString();
  glutMouseFunc(mouse);
  glutDisplayFunc (&DrawGLScene);
  glutReshapeFunc (&ReSizeGLScene);
  InitGL (winHeight, winWidth);
  glutMainLoop ();
}
