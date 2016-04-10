/*==================================================================================================
PROGRAMMER:			David Robinson
COURSE:				CSC 525/625
MODIFIED BY:			N/A
LAST MODIFIED DATE:	8/31/2015
DESCRIPTION:			Demo: drawing lines.
NOTE:					N/A
FILES:					lines.cpp, (labProject.sln, ...)
IDE/COMPILER:			MicroSoft Visual Studio 2013
INSTRUCTION FOR COMPILATION AND EXECUTION:
1.		Double click on myCPPproj.sln	to OPEN the project
2.		Press Ctrl+F7					to COMPILE
3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/
#include<iostream>
#include<GL/glut.h>				// include GLUT library
#include<math.h>
#include<string>
#define PI 3.14159265

using namespace std;

GLfloat xr = 0.0f;
GLfloat yr = 0.0f;
GLfloat zr = 0.0f;
int camera_distance = 50;
double camera_angle = 0;
GLdouble eyex = 100*cos(camera_angle*PI/180);
GLdouble eyez = 100*sin(camera_angle*PI/180);
GLdouble eyey = 100;

//points for cars body
float c1[] = {0,3,0};
float c2[] = {-20,3,40};
float c3[] = {-30,3, 60};
float c4[] = {-35, 3, 90};
float c5[] = {35, 3, 90};
float c6[] = {30, 3, 60};
float c7[] = {20, 3, 40};

float ct1[] = {0,13,0};
float ct2[] = {-20, 13,40};
float ct3[] = {-30,13, 60};
float ct4[] = {-35, 13,90};
float ct5[] = {35, 13, 90};
float ct6[] = {30, 13, 60};
float ct7[] = {20, 13, 40};

//points for spoiler
float s1[] ={-35, 14,70};
float s2[] = {-40, 18, 88};
float s3[] = {40, 18, 88};
float s4[] = {35, 14, 70};


//car inside
float i1[] = {0,8,20};
float i2[] = {-10, 8,40};
float i3[] = {-15,8,50};
float i4[] = {-17,8, 75};
float i5[] = {17, 8, 75};
float i6[] = {15, 8, 50};
float i7[] = {10, 8, 40};

//***********************************************************************************
void drawCar()
{

	glPointSize(1);		// change point size back to 1

	glBegin(GL_POINTS);	// use points to form X-/Y-axes
	glColor3f(0, 0, 0);			 // change drawing color to black
	for (int x = -150; x <= 150; x++) // draw X-axis
		glVertex3i(x, 0, 0);
	for (int y = -150; y <= 150; y++) // draw Y-axis
		glVertex3i(0, y, 0);

	for (int z = -150; z <= 150; z++) // draw Z-axis
		glVertex3i(0, 0, z);
	glEnd();

	//draw x and y on axis
	glRasterPos3i(152, 0, 0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'x');
	glRasterPos3i(3, 152, 0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'y');

	glRasterPos3i(0, 0, 158);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'z');

	//car body
	glColor3f(1, 0, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);// use the default point size: 1
	glVertex3fv(c1);
	glVertex3fv(c2);
	glVertex3fv(c3);
	glVertex3fv(c4);
	glVertex3fv(c5);
	glVertex3fv(c6);
	glVertex3fv(c7);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);// use the default point size: 1
	glVertex3fv(ct1);
	glVertex3fv(ct2);
	glVertex3fv(ct3);
	glVertex3fv(ct4);
	glVertex3fv(i4);
	glVertex3fv(i3);
	glVertex3fv(i2);
	glVertex3fv(i1);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);// use the default point size: 1
	glVertex3fv(ct4);
	glVertex3fv(ct5);
	glVertex3fv(i5);
	glVertex3fv(i4);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);// use the default point size: 1
	glVertex3fv(ct5);
	glVertex3fv(ct6);
	glVertex3fv(ct7);
	glVertex3fv(ct1);
	glVertex3fv(i1);
	glVertex3fv(i7);
	glVertex3fv(i6);
	glVertex3fv(i5);
	glEnd();

	glColor3f(1,0,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);// use the default point size: 1
	glVertex3fv(c1);
	glVertex3fv(c2);
	glVertex3fv(c3);
	glVertex3fv(c4);
	glVertex3fv(ct4);
	glVertex3fv(ct3);
	glVertex3fv(ct2);
	glVertex3fv(ct1);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);// use the default point size: 1
	glVertex3fv(c1);
	glVertex3fv(c7);
	glVertex3fv(c6);
	glVertex3fv(c5);
	glVertex3fv(ct5);
	glVertex3fv(ct6);
	glVertex3fv(ct7);
	glVertex3fv(ct1);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);// use the default point size: 1
	glVertex3fv(c4);
	glVertex3fv(c5);
	glVertex3fv(ct5);
	glVertex3fv(ct4);
	glEnd();

	//spoiler
	glColor3f(0,0,1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);// use the default point size: 1
	glVertex3fv(s1);
	glVertex3fv(s2);
	glVertex3fv(s3);
	glVertex3fv(s4);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex3f(-25,13,75);
	glVertex3f(-25, 16, 80);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(25,13,75);
	glVertex3f(25, 16, 80);
	glEnd();

	//wheels
	float x, y, z;
	glColor3f(0,0,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	for (x = 20; x<=30; x=x+0.1)
	{
	 for (float angle = 0; angle <= 2 *PI; angle += 0.01)
	 {
		 z = 15 +(7) * cos(angle);
		 y = 7 +(7) * sin(angle);

		 glVertex3f(x, y, z);
	}
	}
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	for (x = -30; x<=-20; x=x+0.1)
	{
	 for (float angle = 0; angle <= 2 *PI; angle += 0.01)
	 {
		 z = 15 +(7) * cos(angle);
		 y = 7 +(7) * sin(angle);

		 glVertex3f(x, y, z);
	}
	}
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	for (x=40; x<=50; x=x+0.1)
	{
	 for (float angle = 0; angle <= 2 *PI; angle += 0.01)
	 {
		 z = 70 +(7) * cos(angle);
		 y = 7 +(7) * sin(angle);

		 glVertex3f(x, y, z);
	}
	}
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	for (x=-50; x<=-40; x=x+0.1)
	{
	 for (float angle = 0; angle <= 2 *PI; angle += 0.01)
	 {
		 z = 70 +(7) * cos(angle);
		 y = 7 +(7) * sin(angle);

		 glVertex3f(x, y, z);
	}
	}
	glEnd();

	//inside the car
	glColor3f(1, 1, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);// use the default point size: 1
	glVertex3fv(i1);
	glVertex3fv(i2);
	glVertex3fv(i3);
	glVertex3fv(i4);
	glVertex3fv(i5);
	glVertex3fv(i6);
	glVertex3fv(i7);
	glEnd();

	//car axis
	glColor3d(0.5,0.5,0.5);
	glBegin(GL_LINES);
	glVertex3f(-20, 8,15);
	glVertex3f(-5, 8, 15);
	glEnd();


	glBegin(GL_LINES);
	glVertex3f(20, 8,15);
	glVertex3f(5, 8, 15);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-40, 8,70);
	glVertex3f(-30, 8, 70);
	glEnd();


	glBegin(GL_LINES);
	glVertex3f(40, 8,70);
	glVertex3f(30, 8, 70);
	glEnd();

	//helmet
	glColor3f(1,0.5,0);
	glTranslatef(0,13,62);
	glutSolidSphere(8,100,100);
	glTranslatef(0,-13,-60);

	//windshield
	glColor3f(0,0.75, 1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);// use the default point size: 1
	glVertex3fv(i1);
	glVertex3fv(i2);
	glVertex3fv(i3);
	glVertex3f(-10,18,50);
	glVertex3f(10,18,50);
	glVertex3fv(i6);
	glVertex3fv(i7);
	glEnd();

	//steering wheel
	glPointSize(2);
	glColor3f(0,0,0);
	glBegin(GL_POINTS);
	 for (float angle = 0; angle <= 2 *PI; angle += 0.01)
	 {
		 x = (5) * cos(angle);
		 y = 12 +(3.5) * sin(angle);

		 glVertex3f(x, y, 45);
	}
	glEnd();


}

//***********************************************************************************
void myInit()
{
	glClearColor(1, 1, 1, 0);			// specify a background clor: white
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	glOrtho(-200, 200, -200, 200, -200, 200);  // specify a viewing area
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	glPushMatrix();
	//gluLookAt(0, 0, 60, 0, 20, 0, 0, 1, 0);//camera
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// draw the background
	glPushMatrix();
	gluLookAt(eyex,eyey,eyez, 0,0,0,0,1,0);

	drawCar();
	glPopMatrix();
	glFlush(); // flush out the buffer contents
}

//***********************************************************************************
/*void keyboardCallback(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT){
		glTranslatef(-1.0f, 0.0f, 0.0f);
	}
	if (key == GLUT_KEY_RIGHT){
		glTranslatef(1.0f, 0.0f, 0.0f);
	}
	if (key == GLUT_KEY_UP){
		glTranslatef(0.0f, 0.0f, 1.0f);
	}
	if (key == GLUT_KEY_DOWN){
		glTranslatef(0.0f, 0.0f, -1.0f);
	}

	myDisplayCallback();
}*/

void keyboard_thing(int key, int x, int y){
	switch(key){
	case GLUT_KEY_RIGHT:
		//rotate camera to the right(or rotate everything else to the left)
		camera_angle += 5;
		eyex = 100*cos(camera_angle*PI/180);
		eyez = 100*sin(camera_angle*PI/180);

		break;
	case GLUT_KEY_LEFT:
		//rotate camera to the left(or rotate everything else to the right)
		camera_angle -= 5;
		eyex = 100*cos(camera_angle*PI/180);
		eyez = 100*sin(camera_angle*PI/180);
		//gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
		break;
	case GLUT_KEY_UP:
		//move the camera up
		eyey += 10;
		//gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
		break;
	case GLUT_KEY_DOWN:
		//move the camera down
		eyey -= 10;
		//gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
		break;
	}
	glutPostRedisplay();
}

//***********************************************************************************
int main(int argc, char ** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH);
	glutInitWindowSize(600,600);				// specify a window size
	glutInitWindowPosition(100, 0);
	// specify a window position
	glutCreateWindow("Cruisin down the street");	// create a titled window
	myInit();									// setting up

	glutDisplayFunc(myDisplayCallback);		// register a callback
	glutSpecialFunc(keyboard_thing);
	glutMainLoop();							// get into an infinite loop

	return 1;
}
