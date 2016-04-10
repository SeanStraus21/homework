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
#include <fstream>
#include <string>
#include <GL/glut.h>				// include GLUT library
#include <cmath>
using namespace std;
//***********************************************************************************

//global variable use_stipple
GLubyte pmi[512][512][3];

void drawPoints()
{
		
	glLineWidth(1);//set width
	glPointSize(1);//set pointsize

	//Draw Pixel Map Image
	glRasterPos2s(-256, -256);
	glDrawPixels(512, 512, GL_RGB, GL_UNSIGNED_BYTE, pmi);
	

	
	//draw axis labels
	glRasterPos2s(0, 190);
	glColor3f(0, 255, 0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'X');
	glRasterPos2s(190, 0);
	glColor3f(0, 255, 0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'Y');

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
 gluOrtho2D(-300, 300, -300, 300);  // specify a viewing area
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

	ifstream myfile("..\\..\\lab7\\autumn.txt");
	float R, G, B;
	if (myfile.is_open()){
		int i = 0;
		while (myfile >> R && myfile >> G && myfile >> B){
			pmi[i % 512][i / 512][0] = R;
			pmi[i % 512][i / 512][1] = G;
			pmi[i % 512][i / 512][2] = B;
			i += 1;
		}
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		myfile.close();
		
	}
	else{
		//show error if file not found
		cout << "Specified file Not Found. Check to make sure you entered a valid file name." << endl;
		return;
	}
	for (int i = 0; i < 512; i += 1){
		for (int j = 0; j < 512; i += 1){
			cout << pmi[i][j][0] << pmi[i][j][1] << pmi[i][j][2] << endl;
		}
	}

 glutInit(& argc, argv);

 glutInitWindowSize(600, 600);				// specify a window size
 glutInitWindowPosition(100, 0);			// specify a window position
 glutCreateWindow("Simple Point Drawing");	// create a titled window

 myInit();									// setting up

 glutDisplayFunc(myDisplayCallback);		// register a callback

 glutMainLoop();							// get into an infinite loop
}
