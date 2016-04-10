/*==================================================================================================
 PROGRAMMER:			Yang Wang
 COURSE:				CSC 525/625
 MODIFIED BY:			Sean Straus
 LAST MODIFIED DATE:	8/17/2015
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
#include <GL/glut.h>				// include GLUT library
#include <cmath>
//***********************************************************************************
void drawPoints()
{
	//draw face
	int radius = 100;
	int offset_x = 0;
	int offset_y = 0;

	glPointSize(15);
	glColor3f(1, 1, 0);

	glBegin(GL_POINTS);
	//draw circle
	for (int i = -3*radius; i < 3*radius; i++){
		glVertex2i(i + offset_x, floor(sqrt(radius*radius - i*i)) + offset_y);
		glVertex2i(i + offset_x, -1 * floor(sqrt(radius*radius - i*i)) + offset_y);
	}
	//draw mouth
	radius = 50;
	for (int i = -3 * radius; i < 3 * radius; i++){
		glVertex2i(i + offset_x, -1 * floor(sqrt(radius*radius - i*i)) + offset_y);
	}
	//draw eyes
	glVertex2i(40, 40);
	glVertex2i(-40, 40);
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
{glutInit(& argc, argv);

 glutInitWindowSize(400, 400);				// specify a window size
 glutInitWindowPosition(100, 0);			// specify a window position
 glutCreateWindow("Simple Point Drawing");	// create a titled window

 myInit();									// setting up

 glutDisplayFunc(myDisplayCallback);		// register a callback

 glutMainLoop();							// get into an infinite loop
}
