/*==================================================================================================
 PROGRAMMERS:			Sean Straus, David Robinson
 COURSE:				CSC 525/625
 MODIFIED BY:			
 LAST MODIFIED DATE:	9/10/2015
 DESCRIPTION:			HW 1
 NOTE:					N/A
 FILES:					hw1.cpp, (myCPPproj.sln, ...)
 IDE/COMPILER:			MicroSoft Visual Studio 2013
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on myCPPproj.sln	to OPEN the project
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
	4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/
#include <iostream>
#include <string>
#include <fstream>
#include <GL/glut.h>				// include GLUT library
#include <cmath>
using namespace std;
//***********************************************************************************

//global integer length
int By,Ay,Bx,Ax;


//Utility Function, returns -1 if x is negative, 1 if positive, and 0 if 0;
short sign(int x){
	short output = ((x > 0) ? 1 : ((x < 0) ? -1 : 0));
	return output;
}

//main function, draws stuff
void drawPoints()
{	
	float delta, sigma;
	int x, y;
	glPointSize(1);//set pointsize

	if (Bx != Ax){//if not a vertical line
		sigma = 0;
		delta = abs(float(Ay - By)/float(Ax - Bx));
		y = Ay;
		//begin drawing line
		glBegin(GL_POINTS);
			glColor3f(0, 0, 0);// change drawing color to black
			for (x = Ax; x < Bx; x++){ 
				glVertex2i(x, y);
				sigma += delta;
				while (sigma >= 0.5){
					glVertex2i(x,y);
					y -= sign(Ay - By);
					sigma -= 1.0;
				}
			}
		glEnd();
	}
	else{//if it is a vertical line
		//begin drawing line
		glBegin(GL_POINTS);
		glColor3f(0, 0, 0);// change drawing color to black
		for (int y = Ay; y != By; y += sign(By-Ay)){
			glVertex2i(Ax, y);
		}
		glEnd();
	}


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

 int temp;
 string filename;
 //request file path from user
 cout << "Enter the path of a file containing the coordinates of two points." << endl;
 cin >> filename;

 //extract coordinates from file
 ifstream myfile(filename);
 if (myfile.is_open()){
	 myfile >> Ax;
	 myfile >> Ay;
	 myfile >> Bx;
	 myfile >> By;
	 myfile.close();
 }
 else{
	 //show error if file not found
	 cout << "File Not Found" << endl;
	 exit;
 }
 


 // Make sure point A is on the left, for convenience
 if (Ax > Bx){
	 temp = Bx;
	 Bx = Ax;
	 Ax = temp;

	 temp = By;
	 By = Ay;
	 Ay = temp;
 }


 glutInit(& argc, argv);

 glutInitWindowSize(400, 400);				// specify a window size
 glutInitWindowPosition(100, 0);			// specify a window position
 glutCreateWindow("Simple Point Drawing");	// create a titled window

 myInit();									// setting up

 glutDisplayFunc(myDisplayCallback);		// register a callback

 glutMainLoop();							// get into an infinite loop
}
