#include <windows.h>

#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857

#include <iostream>
using namespace std;

/*/////
#define X1 10
#define Y1 10
#define X2 -400
#define Y2 200
/////*/

//////
#define X1 0
#define Y1 0
#define X2 200
#define Y2 0
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
    //gluOrtho2D(-700, 700, -400, 400);
    gluOrtho2D(-400, 400, -400, 400);
}

//void TrazarRecta (int x0, int y0, int xf, int yf)
void TrazarRecta (int x1, int y1, int x2, int y2)
 {
 int x0, y0, xf, yf;
 if(x2>x1) {xf=x2; yf=y2; x0=x1; y0=y1;}
 else      {xf=x1; yf=y1; x0=x2; y0=y2;}
 int dx = xf - x0 ;
 int dy = yf - y0 ;
 float m = float(dy)/float(dx);
 bool m_neg = false;
 if(m<0)
  {
  int temp;
  temp=xf; xf=-x0; x0=-temp;
  temp=yf; yf= y0; y0= temp;
  dx = xf - x0 ;
  dy = yf - y0 ;
  m=-m; m_neg=true;
  }

 glVertex2i(x1,y1); glVertex2i(x2,y2);
 int x = x0, y = y0;

 ////
 cout << "dy = " << dy << endl;
 cout << "dx = " << dx << endl;
 cout << "m  = " << m  << endl;
 cout << "x0 = " << x0 << endl;
 cout << "y0 = " << y0 << endl;
 cout << "xf = " << xf << endl;
 cout << "yf = " << yf << endl << endl;
 ///*/

 if (m<=1)
  {
  int VarDNE = 2*dy - 2*dx ;
  int VarDE  = 2*dy ;
  int D = 2*dy - dx ;
  while ( x < xf )
   {
   if( D <= 0 ) { x++;
                  D = D + VarDE; }
   else         { x++;
                  y++;
                  D = D + VarDNE; }
   if(m_neg) glVertex2i(-x,y);
   else glVertex2i(x,y);
   }
  }

 else
  {
  int VarDNE = 2*dy - 2*dx ;
  int VarDN = -2*dx ;
  int D = 2*dy - dx ;
  while ( x < xf )
   {
   if( D <= 0 ) { x++;
                  y++;
                  D = D + VarDNE; }
   else         { y++;
                  D = D + VarDN; }
   if(m_neg) glVertex2i(-x,y);
   else glVertex2i(x,y);
   }
  }


 }

void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    TrazarRecta(X1,Y1,X2,Y2);


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
