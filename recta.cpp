#include <windows.h>

#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857

//////
#define X0 -200
#define Y0 -200
#define XF 400
#define YF 400
/////*/

/*/////
#define X0 10
#define Y0 10
#define XF 200
#define YF 400
/////*/

// function to initialize
void myInit (void)
{
    /// making background color black as first
    // 3 arguments all are 0.0
    glClearColor(0.0, 0.0, 0.0, 1.0);
    //glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    /// making picture color green (in RGB mode), as middle argument is 1.0
    glColor3f(1.0, 1.0, 0.0);

    // breadth of picture boundary is 1 pixel
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /// setting window dimension in X- and Y- direction
    //gluOrtho2D(-780, 780, -420, 420);
    gluOrtho2D(-700, 700, -400, 400);
}

void TrazarRecta (int x0, int y0, int xf, int yf)
 {
 int dx = xf - x0 ;
 int dy = yf - x0 ;
 int VarDNE = 2*dy - 2*dx ;
 int VarDE  = 2*dy ;
 int D = 2*dy ;

 glVertex2i(x0,y0); glVertex2i(xf,yf);

 int x = x0, y = y0;

 while ( x < xf )
  {
  if( D <= 0 ) { x++;
                 D = D + VarDE; }
  else         { x++;
                 y++;
                 D = D + VarDNE; }
  glVertex2i(x,y);
  }
 }

void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    TrazarRecta(X0,Y0,XF,YF);


    glEnd();
    glFlush();
}

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // giving window size in X- and Y- direction
    glutInitWindowSize(1366, 768);
    ///glutInitWindowSize(1400, 800);
    ///glutInitWindowSize(2000, 1600);
    glutInitWindowPosition(0, 0);

    // Giving name to window
    glutCreateWindow("Circle Drawing");
    myInit();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
