/*==================================================================================================
 PROGRAMMER:			Yang Wang
 COURSE:				CSC 525/625
 MODIFIED BY:			Sean Straus
 LAST MODIFIED DATE:	9/09/2015
 DESCRIPTION:			Demo: drawing points.
 NOTE:					N/A
 FILES:					points.cpp, (myCPPproj.sln, ...)
 IDE/COMPILER:			MicroSoft Visual Studio 2013
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on myCPPproj.sln	to OPEN the project
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
	4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/
#include <iostream>
#include <string>
#include <GL/glut.h>				// include GLUT library
#include <cmath>
#include <vector>
using namespace std;
//***********************************************************************************

class Thingy{
public:
	float angle, x, y, z;
	Thingy(float a, float _x, float _y, float _z){
		angle = a;
		x = _x;
		y = _y;
		z = _z;
	}
};
//global variable
int window;
bool flag = false;
GLfloat xr = 0.0f;
GLfloat yr = 0.0f;
GLfloat zr = 0.0f;
GLdouble eyex = 0;
GLdouble eyey = 0;
GLdouble eyez = 100;
vector<Thingy> transform_vector;
void override_defaults(int a, int b, int c, int d){
	//do nothing
}

void drawPoints();

void change_view(int type){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	switch (type){
	case 0://orthogonal
		eyex = 0;
		eyey = 0;
		eyez = 100;
		break;
	case 1://perspective
		eyex = 60;
		eyey = 70;
		eyez = 60;
		break;
	}
	glOrtho(-400, 400, -400, 400, -400, 400);
	gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

//rotates the faces by theta
void my_rotate(short axis, GLfloat theta){
	switch (axis){
	case 0:
		//xr += theta;
		glRotatef(theta, 1.0f, 0.0f, 0.0f);
		break;
	case 1:
		//yr += theta;
		glRotatef(theta, 0.0f, 1.0f, 0.0f);
		break;
	case 2:
		//zr += theta;
		glRotatef(theta, 0.0f, 0.0f, 1.0f);
		break;
	}
	glutPostRedisplay();
}

//removes modifications to the faces
void clear_modifications(){
	glLoadIdentity();
	glutPostRedisplay();
	/*
	glPopMatrix();
	glPushMatrix();
	xr = 0.0f;
	yr = 0.0f;
	zr = 0.0f;
	glutPostRedisplay();
	*/
}

void draw_axes(){
	//Draw Text
	//glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, text);
	glColor3f(255, 0, 0);
	glRasterPos2s(0, 0);

	//draw axis labels
	glColor3f(0, 0, 0);
	
	glRasterPos3s(190, 0, 0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'X');
	glRasterPos3s(0, 190, 0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'Y');
	glRasterPos3s(0, 0, 190);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'Z');

	//draw axes
	glPointSize(1);		// change point size back to 1


	glBegin(GL_LINES);	// use points to form X-/Y-axes
	glColor3f(0, 0, 0);	// change drawing color to black
	// draw X-axis
	glVertex3s(-200, 0, 0);
	glVertex3s(200, 0, 0);
	// draw Y-axis
	glVertex3s(0, -200, 0);
	glVertex3s(0, 200, 0);
	// draw Z-axis
	glVertex3s(0, 0, -200);
	glVertex3s(0, 0, 200);
	glEnd();
}

void menu(int input){
	switch (input){
	case 0:
		my_rotate(0,45);
		break;
	case 1:
		my_rotate(0,-45);
		break;
	case 2:
		my_rotate(1,45);
		break;
	case 3:
		my_rotate(1,-45);
		break;
	case 4:
		my_rotate(2,45);
		break;
	case 5:
		my_rotate(2,-45);
		break;
	case 6:
		clear_modifications();
		break;
	case 7:
		glutDestroyWindow(window);
		exit(0);
		break;
	case 8:
		change_view(0);
		break;
	case 9:
		change_view(1);
		break;
	}
}

void menu_create(void){
	int rx_menu = glutCreateMenu(menu);
		glutAddMenuEntry("Rotate +45 degrees", 0);
		glutAddMenuEntry("Rotate -45 degrees", 1);

	int ry_menu = glutCreateMenu(menu);
		glutAddMenuEntry("Rotate +45 degrees", 2);
		glutAddMenuEntry("Rotate -45 degrees", 3);


	int rz_menu = glutCreateMenu(menu);
		glutAddMenuEntry("Rotate +45 degrees", 4);
		glutAddMenuEntry("Rotate -45 degrees", 5);

	int view_menu = glutCreateMenu(menu);
		glutAddMenuEntry("Orthogonal", 8);
		glutAddMenuEntry("Perspective", 9);


	int crnt_menu = glutCreateMenu(menu);
		glutAddMenuEntry("Reset", 6);
		glutAddMenuEntry("Exit", 7);
		glutAddSubMenu("Rotate Around X Axis", rx_menu);
		glutAddSubMenu("Rotate Around Y Axis", ry_menu);
		glutAddSubMenu("Rotate Around Z Axis", rz_menu);
		glutAddSubMenu("Change View", view_menu);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void drawPoints()
{
	
	//glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLineWidth(1);//set width
	glPointSize(1);//set pointsize
	
	//define vertices
	GLshort v0[] = {60, 55, 40};
	GLshort v1[] = {60, -50, 40};
	GLshort v2[] = {65, 90, -70};
	GLshort v3[] = {65, 0, -70};
	GLshort v4[] = {-70, 70, 20};
	GLshort v5[] = {-70, -20, 20};

	glBegin(GL_QUADS);

	// Red
	glColor3f(1.0f, 0.0f, 0.0f);     
	glVertex3sv(v0);//top left
	glVertex3sv(v2);//top right
	glVertex3sv(v3);//bottom right
	glVertex3sv(v1);//bottom left
	// Green
	glColor3f(0.0f, 1.0f, 0.0f);     
	glVertex3sv(v2);
	glVertex3sv(v4);
	glVertex3sv(v5);
	glVertex3sv(v3);
	// Blue
	glColor3f(0.0f, 0.0f, 1.0f);     
	glVertex3sv(v4);
	glVertex3sv(v0);
	glVertex3sv(v1);
	glVertex3sv(v5);
	glEnd();

	glPopMatrix();

	draw_axes();
}

//***********************************************************************************
void myInit(){
	glClearColor(1, 1, 1, 0);	// specify a background color: white
	glPolygonMode(GL_BACK, GL_FILL);
	glPolygonMode(GL_FRONT, GL_LINE);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glOrtho(-400, 400, -400, 400, -800, 800);  // specify a viewing area
	gluLookAt(0, 0, 100, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
}

//***********************************************************************************
void myDisplayCallback()
{glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// draw the background

 drawPoints();
 glutSwapBuffers();
 glFlush(); // flush out the buffer contents
}

//***********************************************************************************
int main(int argc, char ** argv)
{


 glutInit(& argc, argv);

 glutInitWindowSize(400, 400);				// specify a window size
 glutInitWindowPosition(100, 0);			// specify a window position
 window = glutCreateWindow("Simple Point Drawing");	// create a titled window

 myInit();									// setting up
 menu_create();

 glutMouseFunc(override_defaults);

 glutDisplayFunc(myDisplayCallback);		// register a callback

 glutMainLoop();							// get into an infinite loop
}
