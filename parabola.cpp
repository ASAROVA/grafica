#include <windows.h>

#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857

#include <iostream>
using namespace std;

#define XMIN -400
#define YMIN -400
#define XMAX  400
#define YMAX  400

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
    //gluOrtho2D(-700, 700, -400, 400);
    //gluOrtho2D(-400, 400, -400, 400);
    gluOrtho2D(XMIN, XMAX, YMIN, YMAX);
}

void TrazarParabola (float a, int xf)
 {
 float F = a - 0.5;
 int x45deg = (1.0/(2.0*a))+0.5;
 int y=0;
 int x;
 for (x=0; x<x45deg; x++)
  {
  if(F<=0)
   {
   F = F + a*(2*x + 3);
   glVertex2i(x,y);
   }
  else
   {
   F = F + a*(2*x+3) - 1;
   y++;
   glVertex2i(x,y);
   }
  }

 int y45deg = a*x45deg*x45deg;
 int yf = a*xf*xf;
 if( yf > YMAX ) yf = YMAX;
 x = x45deg;
 for (y=y45deg;y<=yf;y++)
  {
  if(F>0)
  //if(F<=0)
   {
   F = F + a*(2*x+2) - 1;
   x++;
   glVertex2i(x,y);
   }
  else
   {
   F = F + 1;
   glVertex2i(x,y);
   }
  }
 }


void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    #define A 0.001
    #define XF 400
    TrazarParabola(A, XF);

    glEnd();
    glFlush();
}

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // giving window size in X- and Y- direction
    ///glutInitWindowSize(1366, 768);
    ///glutInitWindowSize(1400, 800);
    ///glutInitWindowSize(2000, 1600);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);

    // Giving name to window
    glutCreateWindow("Circle Drawing");
    myInit();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
