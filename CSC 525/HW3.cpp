/*==================================================================================================
PROGRAMMERS:			David Robinson (Robinson003) , Sean Straus (Straus21)
COURSE:				CSC 525/625
MODIFIED BY:
LAST MODIFIED DATE:	10/1/2015
DESCRIPTION:			HW 1
NOTE:					50%
FILES:					HW3.cpp, (hwProject.sln, ...)
IDE/COMPILER:			MicroSoft Visual Studio 2013
INSTRUCTION FOR COMPILATION AND EXECUTION:
1.		Double click on myCPPproj.sln	to OPEN the project
2.		Press Ctrl+F7					to COMPILE
3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/
#include<iostream>
#include <GL/glut.h>				// include GLUT library
#include<math.h>
#include<string>

using namespace std;
//***********************************************************************************
//draw background with pixel map
GLfloat myPixelmap[512][512][3];
void background()
{
	glPointSize(1);		// change point size back to 1
	glRasterPos2i(-300, -300);
	for (int i = 85; i < 512; i++)
	{
		for (int j = 0; j < 512; j++)
		{
			myPixelmap[i][j][0] = 0;
			myPixelmap[i][j][1] = 0;
			myPixelmap[i][j][2] = 0.5;
		}
	}
	for (int i = 0; i <85; i++)
	{
		for (int j = 0; j < 512; j++)
		{
			myPixelmap[i][j][0] = 1;
			myPixelmap[i][j][1] = 1;
			myPixelmap[i][j][2] = 1;
		}
	}
	glDrawPixels(512, 512, GL_RGB, GL_FLOAT, myPixelmap);

	}
//***********************************************************************************
//Draw mountain and snow with polygon and polyon fill pattern

void scenery()
{
	GLubyte aPattern[]=
	{
		0X10, 0X00, 0X00, 0X00,
		0X10, 0X00, 0X00, 0X00,
		0X38, 0X00, 0X00, 0X00,
		0X7c, 0X00, 0X00, 0X00,//4
		0X38, 0X00, 0X00, 0X00, 
		0X10, 0X00, 0X00, 0X00,
		0X10, 0X00, 0X00, 0X00,
		0X00, 0X00, 0X00, 0X00,//8
		0X00, 0X00, 0X00, 0X00,
		0X00, 0X00, 0X00, 0X00,
		0X00, 0X00, 0X00, 0X00,
		0X00, 0X00, 0X00, 0X00,//12
		0X00, 0X00, 0X00, 0X00,
		0X00, 0X00, 0X00, 0X00,
		0X00, 0X00, 0X01, 0X00,
		0X00, 0X00, 0X01, 0X00,//16 
		0X00, 0X00, 0X38, 0X00,
		0X00, 0X00, 0X7c, 0X00,
		0X00, 0X00, 0X38, 0X00,
		0X00, 0X00, 0X10, 0X00, //20
		0X00, 0X00, 0X10, 0X00,
		0X00, 0X00, 0X00, 0X00, 
		0X00, 0X00, 0X00, 0X00,
		0X00, 0X00, 0X00, 0X00,//24
		0X00, 0X00, 0X00, 0X00,
		0X00, 0X00, 0X00, 0X00,
		0X00, 0X00, 0X00, 0X00,
		0X00, 0X00, 0X00, 0X00,//28
		0X00, 0X00, 0X00, 0X00,
		0X00, 0X00, 0X00, 0X00,
		0X00, 0X00, 0X00, 0X00,
		0X00, 0X00, 0X00, 0X00,//32
	};
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(aPattern);
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2f(-300,300);
	glVertex2f(-300,-200);
	glVertex2f(300,-200);
	glVertex2f(300,300);
	glEnd();
	glDisable(GL_POLYGON_STIPPLE);
	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);			// specify drawing color: red 
	glVertex2f(300, 180);		// 1st point
	glColor3d(0.625, 0.32, 0.17);
	glVertex2f(180, 0);
	glVertex2f(300, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(300,0);
	glVertex2f(180, 0);	
	glVertex2f(50, -215);		
	glVertex2f(300, -215);
	glEnd();

	glColor3f(0.54, 0.27, 0.07);
	glBegin(GL_POLYGON);
	glVertex2f(-250,-210);
	glVertex2f(-200, -210);	
	glVertex2f(-200, -140);		
	glVertex2f(-250, -140);
	glEnd();
	
	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(-225,0);
	glVertex2f(-175, -140);	
	glVertex2f(-275, -140);		
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-225,40);
	glVertex2f(-175, -100);	
	glVertex2f(-275, -100);		
	glEnd();
}
//***********************************************************************************
//draw firewood with line segments

void firewood()
{
	glColor3f(0.54, 0.27, 0.07);
	glLineWidth(4);
	glBegin(GL_LINES);
	glVertex2f(-12,-224);
	glVertex2f(30, -215);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(30, -224);
	glVertex2f(-12, -215);
	glEnd();
}
//***********************************************************************************

//draw campfire with bitmap
GLubyte fire[] = 
	{ 0x00, 0x00, 0x00, 0x00,
	0X01, 0Xff, 0Xff, 0X80,
	0X03, 0Xff, 0Xff, 0Xc0,
	0X07, 0Xff, 0Xff, 0Xd0,//4
	0X0f, 0Xff, 0Xff, 0Xd0,
	0X1f, 0Xff, 0Xff, 0Xd0,
	0X1f, 0Xff, 0Xff, 0Xd0,
	0X3f, 0Xff, 0Xff, 0Xd0,//8
	0X7f, 0Xff, 0Xff, 0Xf0,
	0Xff, 0Xff, 0Xff, 0Xf0,
	0Xff, 0Xff, 0Xff, 0Xf8,
	0Xdf, 0Xff, 0Xff, 0Xf8,//12
	0X9f, 0Xff, 0Xff, 0Xf8,
	0X1f, 0Xff, 0Xff, 0Xf8,
	0X3f, 0Xff, 0Xff, 0Xf8,
	0X3f, 0Xff, 0Xff, 0Xf8,//16
	0X3f, 0Xff, 0Xff, 0Xf8,
	0X3f, 0Xff, 0Xff, 0Xf8,
	0X3f, 0Xff, 0Xff, 0Xf8,
	0X7f, 0Xff, 0Xff, 0Xfc,//20
	0X7f, 0Xff, 0Xff, 0Xfc,
	0X7f, 0Xff, 0Xff, 0Xfc,
	0X7f, 0Xff, 0Xff, 0Xec,
	0X7f, 0Xff, 0Xff, 0Xec,//24
	0X7f, 0Xff, 0Xff, 0Xec,
	0X6f, 0Xff, 0Xff, 0Xec,
	0X6f, 0Xff, 0Xff, 0Xec,
	0X4f, 0Xff, 0Xff, 0Xe4,//28
	0X0f, 0Xff, 0Xff, 0Xe0,
	0X1f, 0Xff, 0Xff, 0Xf0,
	0X3f, 0Xff, 0Xff, 0Xf8,
	0X3f, 0Xff, 0Xff, 0Xf8,//32
	0X3f, 0Xff, 0Xff, 0Xf8,
	0X3f, 0Xff, 0Xff, 0Xf8,
	0X3f, 0Xff, 0Xff, 0Xe8,
	0X3f, 0Xff, 0Xff, 0Xe8,//36
	0X2f, 0Xff, 0Xff, 0Xe0,
	0X2f, 0Xff, 0Xff, 0Xe0,
	0X07, 0Xff, 0Xff, 0Xe0,
	0X07, 0Xff, 0Xff, 0X60,//40
	0X07, 0Xff, 0Xfe, 0X40,
	0X03, 0Xff, 0Xfc, 0X00,
	0X03, 0Xff, 0Xfc, 0X00,
	0X00, 0Xff, 0Xf8, 0X00,//44
	0X00, 0X7f, 0Xf8, 0X00,
	0X00, 0X3f, 0Xf0, 0X00,
	0X00, 0X07, 0Xc0, 0X00,
	0X00, 0X07, 0X80, 0X00,//48
};

void campfire()
{
	glColor3f(1,0.84,0);
	glRasterPos2i(-10, -220);
	glBitmap(32, 48, 0, 0, 0, 0, fire);
	glColor3f(1,0.27,0);
	glRasterPos2i(-5, -220);
	glBitmap(32, 48, 0, 0, 0, 0, fire);
}
//***********************************************************************************
//draw snowman with polygon fill and outline with unilled circles and make smiley face with points
void snowman()
{
	glColor3f(1,1,1);
	const float PI = 3.1415;
	float x, y;

	//top
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	 for (float angle = 0; angle <= 2 *PI; angle += 0.01)
	 {
		 x = -80+(45) * cos(angle);
		 y = -205 +(45) * sin(angle);

		 glVertex2f(x, y);
	}
	 glEnd();
	  glColor3f(0,0,0);
	glBegin(GL_POINTS);
	 for (float angle = 0; angle <= 2 *PI; angle += 0.01)
	 {
		 x = -80+(45) * cos(angle);
		 y = -205 +(45) * sin(angle);

		 glVertex2f(x, y);
	}
	 glEnd();

	 //middle
	 glColor3f(1,1,1);
	 glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	 for (float angle = 0; angle <= 2 *PI; angle += 0.01)
	 {
		 x = -80+(40) * cos(angle);
		 y = -150 +(40) * sin(angle);

		 glVertex2f(x, y);
	}
	 glEnd();
	  glColor3f(0,0,0);
	glBegin(GL_POINTS);
	 for (float angle = 0; angle <= 2 *PI; angle += 0.01)
	 {
		 x = -80+(40) * cos(angle);
		 y = -150 +(40) * sin(angle);

		 glVertex2f(x, y);
	}
	 glEnd();

	 //head
	 glColor3f(1,1,1);
	 glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	 for (float angle = 0; angle <= 2 *PI; angle += 0.01)
	 {
		 x = -80+(35) * cos(angle);
		 y = -95 +(35) * sin(angle);

		 glVertex2f(x, y);
	}
	 glEnd();
	  glColor3f(0,0,0);
	glBegin(GL_POINTS);
	 for (float angle = 0; angle <= 2 *PI; angle += 0.01)
	 {
		 x = -80+(35) * cos(angle);
		 y = -95 +(35) * sin(angle);

		 glVertex2f(x, y);
	}
	 glEnd();
	 glPointSize(2);
	 glBegin(GL_POINTS);
	  for (float angle = 0; angle <= 2 * PI*(0.5); angle += 0.5)
	 {
		 x = -80-(15) * cos(angle);
		 y = -100-(15) * sin(angle);

		 glVertex2f(x, y);

	 }
	  glEnd();
	  glPointSize(3);
	 glBegin(GL_POINTS);  
	  glVertex2f(-90, -85);
	  glVertex2f(-70, -85);
	 glEnd();

	 //arms
	 glColor3f(0.54, 0.27, 0.07);
	 glBegin(GL_LINES);
	 glVertex2f(-55,-130);
	glVertex2f(-25, -150);
	glEnd();

	 glBegin(GL_LINES);
	 glVertex2f(-25,-150);
	glVertex2f(-10, -115);
	glEnd();
	
	glBegin(GL_LINES);
	 glVertex2f(-135,-210);
	glVertex2f(-150, -235);
	glEnd();

	 glBegin(GL_LINES);
	 glVertex2f(-150,-235);
	glVertex2f(-120, -250);
	glEnd();

	//nose
	glColor3f(1, 0.54, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-80,-93);
	glVertex2f(-80, -98);	
	glVertex2f(-72, -94);		
	glEnd();
}
//***********************************************************************************
//place phrase usin text features
void words()
{
	string phrase;
	glColor3f(0, 0.74, 1);
	phrase = "LET IT SNOW!";
	glRasterPos2i(-100,0);
	for(int i =0; phrase[i] != NULL; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,phrase[i]);
}
//***********************************************************************************
void myInit()
{
	glClearColor(1, 1, 1, 0);			// specify a background clor: white 
	gluOrtho2D(-300, 300, -300, 300);  // specify a viewing area
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	background();
	scenery();
	firewood();
	campfire();
	snowman();
	words();
	
	glFlush(); // flush out the buffer contents
}

//***********************************************************************************
void main(int argc, char ** argv)
{

	glutInit(& argc, argv);

	glutInitWindowSize(512, 512);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("Simple Point Drawing");	// create a titled window

	myInit();									// setting up

	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutMainLoop();							// get into an infinite loop
}