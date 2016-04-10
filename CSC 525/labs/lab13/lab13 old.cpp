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
	Thingy(float a, float _x,float _y,float _z){
		angle = a;
		x = _x;
		y = _y;
		z = _z;
	}
};

//global variable
int window;
vector<Thingy> transform_vector;
void override_defaults(int a, int b, int c, int d){
	//do nothing
}

void drawPoints();

//rotates the faces by theta
void my_rotate(short axis, short theta){
	
	switch (axis){
	case 0:
		transform_vector.push_back(Thingy(theta, 1, 0, 0));
		break;
	case 1:
		transform_vector.push_back(Thingy(theta, 0, 1, 0));
		break;
	case 2:
		transform_vector.push_back(Thingy(theta, 0, 0, 1));
		break;
	}
}

//removes modifications to the faces
void clear_modifications(){
	glPopMatrix();
	glPushMatrix();
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


	int crnt_menu = glutCreateMenu(menu);
		glutAddMenuEntry("Reset", 6);
		glutAddMenuEntry("Exit", 7);
		glutAddSubMenu("Rotate X", rx_menu);
		glutAddSubMenu("Rotate Y", ry_menu);
		glutAddSubMenu("Rotate Z", rz_menu);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void drawPoints()
{
	//glPushMatrix();
	int l = transform_vector.size();
	for (int i = 0; i < l; i++){
		Thingy crnt = transform_vector[i];
		
		glTranslatef(0.0f, 0.0f, 0.0f);
		glRotatef(crnt.angle, crnt.x, crnt.y, crnt.z);
	}
	transform_vector.clear();
	gluLookAt(60, 70, 60, 0, 0, 0, 0, 1, 0);

	glLineWidth(1);//set width
	glPointSize(1);//set pointsize

	GLshort v0[] = {60, 55, 40};
	GLshort v1[] = {60, -50, 40};
	GLshort v2[] = {65, 90, -70};
	GLshort v3[] = {65, 0, -70};
	GLshort v4[] = {-70, 70, 20};
	GLshort v5[] = {-70, -20, 20};

	glPolygonMode(GL_BACK, GL_FILL);
	glPolygonMode(GL_FRONT, GL_LINE);
	glBegin(GL_QUADS);

	
	glColor3f(0.0f, 0.0f, 0.0f);     // Black
	glVertex3sv(v0);//top left
	glVertex3sv(v2);//top right
	glVertex3sv(v3);//bottom right
	glVertex3sv(v1);//bottom left


	glColor3f(1.0f, 0.5f, 0.0f);     // Orange
	glVertex3sv(v2);
	glVertex3sv(v4);
	glVertex3sv(v5);
	glVertex3sv(v3);


	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3sv(v4);
	glVertex3sv(v0);
	glVertex3sv(v1);
	glVertex3sv(v5);
	glEnd();

	//Draw Text
	//glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, text);
	glColor3f(255, 0, 0);
	glRasterPos2s(-50, -50);


	//draw axis labels
	glColor3f(0, 0, 0);
	glRasterPos3s(0, 190,0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'X');
	glRasterPos3s(190, 0,0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'Y');
	glRasterPos3s(0, 0,190);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'Z');

	//draw axes
	glPointSize(1);		// change point size back to 1


	glBegin(GL_LINES);	// use points to form X-/Y-axes
	glColor3f(0, 0, 0);	// change drawing color to black
	 // draw X-axis
	glVertex3s(-150,0,0);
	glVertex3s(150, 0, 0);
	// draw Y-axis
	glVertex3s(0, -150, 0);
	glVertex3s(0, 150, 0);
	// draw Z-axis
	glVertex3s(0, 0, -150);
	glVertex3s(0, 0, 150);
	glEnd();
	//glPopMatrix();

}

//***********************************************************************************
void myInit()
{glClearColor(1, 1, 1, 0);			// specify a background clor: white
 glOrtho(-200, 200, -200, 200, -200, 200);  // specify a viewing area
 glEnable(GL_DEPTH_TEST);
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
}

//***********************************************************************************
void myDisplayCallback()
{glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// draw the background

 drawPoints();

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
