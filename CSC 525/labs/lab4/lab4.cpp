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
#include <GL/glut.h>				// include GLUT library
#include <cmath>
using namespace std;
//***********************************************************************************

//global variable use_stipple
unsigned short mode;

void drawPoints()
{
	glLineWidth(1);//set width
	glPointSize(10);//set pointsize

	//draw polygon
	switch (mode){
	case 1:// GL_FILL
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;
	case 2:// GL_LINE
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	case 3://GL_POINT
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		break;
	case 4://PATTERN_FILL
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glEnable(GL_POLYGON_STIPPLE);
		GLubyte pattern[] = {0x00, 0x01};
		glPolygonStipple(pattern);
		break;
	}
	
	glBegin(GL_POLYGON);
	//(0, 80), (-70, 0), (-30, -60), (30, -60), (70, 0)
	glColor3f(255, 0, 0); //set color
	glVertex3f(0,80,0);//set point 1

	glColor3f(255, 255, 0); //set color
	glVertex3f(-70,0,0);//set point 2

	glColor3f(0, 255, 0); //set color
	glVertex3f(-30, -60, 0);//set point 3

	glColor3f(0, 0, 255); //set color
	glVertex3f(30, -60, 0);//set point 4

	glColor3f(255, 0, 255); //set color
	glVertex3f(70, 0, 0);//set point 5
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
	cout << "Enter a digit to choose your display mode." << endl << "1: GL_FILL" << endl << "2: GL_LINE" << endl << "3: GL_POINT" << endl << "4: FILL WITH A PATTERN" << endl;
 cin >> mode;
 glutInit(& argc, argv);

 glutInitWindowSize(400, 400);				// specify a window size
 glutInitWindowPosition(100, 0);			// specify a window position
 glutCreateWindow("Simple Point Drawing");	// create a titled window

 myInit();									// setting up

 glutDisplayFunc(myDisplayCallback);		// register a callback

 glutMainLoop();							// get into an infinite loop
}
