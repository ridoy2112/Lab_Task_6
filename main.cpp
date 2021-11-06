#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<math.h>
void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500.0, 500.0, -500.0, 500.0, -1.0, 1.0);
}
void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glBegin(GL_POINTS);
    for (int i=-200; i<=200; i++)
    {
        glVertex2d(0,i);
        glVertex2d(i,0);
        glVertex2d(i,i);
        glVertex2d(i,-i);
    }
    double m=0, n=0, r=2112;
    double pk=1-r;
    double pkk;
    double x=m, y=n+r;
    glBegin(GL_POINTS);
    glVertex2d(x,y);

    while(1)
    {
        if(pk<0)
        {
            x++;
            pkk=pk +(2*x)+1;
        }
        else if(pk>=0)
        {
            x++;
            y--;
            pkk=pk +(2*x)+1-(2*y);
        }

        pk=pkk;

        glColor3f(0.1, 0.1, 0.2);
        glVertex2d(x,y);
        glColor3f(0.2, 0.1, 0.1);
        glVertex2d(x,-y);
        glColor3f(0.1, 0.2, 0.1);
        glVertex2d(-x,y);
        glColor3f(0.1, 0.1, 0.2);
        glVertex2d(-x,-y);
        glColor3f(0.2, 0.1, 0.1);
        glVertex2d(y,x);
        glColor3f(0.1, 0.1, 0.2);
        glVertex2d(-y,x);
        glColor3f(0.2, 0.1, 0.1);
        glVertex2d(y,-x);
        glColor3f(0.1, 0.1, 0.2);
        glVertex2d(-y,-x);
        if(x>=y)
        {
            break;
        }
    }
    glEnd();
    glFlush();
    glutSwapBuffers();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(600,600);
    glutCreateWindow("182-15-2112");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
