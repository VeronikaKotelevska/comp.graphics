// Simple_objects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLAux.h>



void CALLBACK resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, 2, 12);
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
}



void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPointSize(2);

    glBegin(GL_POINTS);

    glColor3d(1, 0, 0);

    glVertex3d(-4, 4, 0); // ����� �����

    glColor3d(0, 1, 0);

    glVertex3d(-3.5, 3.5, 0); // ����� �����

    glColor3d(0, 0, 1); // �����

    glVertex3d(-3, 3, 0);

    glEnd();

    glPointSize(5);

    glBegin(GL_POINTS);

    glColor3d(1, 0, 0);

    glVertex3d(-2.5, 2.5, 0); // ����� �����

    glColor3d(0, 1, 0);

    glVertex3d(-2, 2.2, 0); // ����� �����

    glColor3d(0, 0, 1);

    glVertex3d(-1.5, 2.2, 0);// �����

    glEnd();

    glPointSize(10);

    glEnable(GL_POINT_SMOOTH);

    glBegin(GL_POINTS);

    glColor3d(1, 0, 0);

    glVertex3d(-1.1, 2.4, 0); // ����� �����

    glColor3d(0, 1, 0);

    glVertex3d(-0.8, 2.7, 0); // ����� �����

    glColor3d(0, 0, 1); // �����

    glVertex3d(-0.6, 3, 0);

    glEnd();

    glDisable(GL_POINT_SMOOTH);


    auxSwapBuffers();

}



int main()
{
    float pos[4] = { 3,3,3,1 };
    float dir[3] = { -1,-1,-1 };

    GLfloat mat_specular[] = { 1,1,1,1 };

    auxInitPosition(50, 10, 400, 400);
    auxInitDisplayMode(AUX_RGB | AUX_DEPTH | AUX_DOUBLE);
    auxInitWindowA("Kotelevska IN82");
    auxIdleFunc(display);
    auxReshapeFunc(resize);


    glEnable(GL_DEPTH_TEST);

    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, 128.0);


    /*
    * Enter your cod here
    */
    auxMainLoop(display);
}
