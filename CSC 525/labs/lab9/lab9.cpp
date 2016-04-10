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
using namespace std;
//***********************************************************************************

//global variable
int mouse_x = 0;
int mouse_y = 0;
bool mouse_btn = 0;//0 is left, 1 is right
bool left_down = true;
bool right_down = true;
string user_string = "";


void mouse_thing(int button, int state, int x, int y){
	switch (button){
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN){
			mouse_btn = 0;
			left_down = true;
		}
		else{
			left_down = false;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN){
			mouse_btn = 1;
			right_down = true;
		}
		else{
			right_down = false;
		}
		break;
	}
}

void other_mouse_thing(int x, int y){
	if (right_down || left_down){
		mouse_x = x;
		mouse_y = y;
	}
}

void drawPoints()
{
		
	glLineWidth(1);//set width
	glPointSize(1);//set pointsize

	if (mouse_btn){
		glColor3f(0, 1, 0);
	}
	else{
		glColor3f(1, 0, 0);
	}
	//draw bitmap
	glBegin(GL_POINT);
		for (int i = 0; i < user_string.length(); i++){

			glRasterPos2s(-200 + mouse_x + 10*i, 200 - mouse_y);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, user_string[i]);
		}
	glEnd();
	//Draw Text
	//glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, text);
	
	//draw axis labels
	glRasterPos2s(0, 0);
	glColor3f(0, 0, 0);
	
	glBegin(GL_POINT);
	glRasterPos2s(152, 0);
	glColor3f(0, 0, 0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'X');
	glRasterPos2s(-2, 152);
	glColor3f(0, 255, 0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'Y');
	glEnd();


	//draw axes
	glPointSize(1);		// change point size back to 1

	glBegin(GL_POINTS);	// use points to form X-/Y-axes
	glColor3f(0, 0, 0);			 // change drawing color to black
	for (int x = -150; x <= 150; x++) // draw X-axis
		glVertex2i(x, 0);
	for (int y = -150; y <= 150; y++) // draw Y-axis
		glVertex2i(0, y);
	glEnd();

	glutPostRedisplay();
}

//***********************************************************************************
void myInit()
{glClearColor(1, 1, 1, 0);			// specify a background clor: white 
 gluOrtho2D(-200, 200, -200, 200);  // specify a viewing area
}

//***********************************************************************************
void myDisplayCallback()
{glClear(GL_COLOR_BUFFER_BIT);	// draw the background

 drawPoints();

 glFlush(); // flush out the buffer contents
}

//***********************************************************************************
void main(int argc, char ** argv)
{

	cout << "Enter a message to be displayed: ";
	cin >> user_string;

 glutInit(& argc, argv);

 glutInitWindowSize(400, 400);				// specify a window size
 glutInitWindowPosition(100, 0);			// specify a window position
 glutCreateWindow("Simple Point Drawing");	// create a titled window

 myInit();									// setting up

 glutMouseFunc(mouse_thing);
 glutPassiveMotionFunc(other_mouse_thing);
 glutDisplayFunc(myDisplayCallback);		// register a callback

 glutMainLoop();							// get into an infinite loop
}
