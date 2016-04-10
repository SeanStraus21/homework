/*==================================================================================================
PROGRAMMERS:			David Robinson (Robinson003) , Sean Straus (Straus21)
COURSE:				CSC 525/625
MODIFIED BY:
LAST MODIFIED DATE:	11/6/2015
DESCRIPTION:			HW 4
NOTE:					50% Each
						Sean: menu, rotation and viewing
						David: help menu, windows creations
FILES:					HW5.cpp, (hwProject.sln, ...)
IDE/COMPILER:			MicroSoft Visual Studio 2013
INSTRUCTION FOR COMPILATION AND EXECUTION:
1.		Double click on hwProj.sln	to OPEN the project
2.		Press Ctrl+F7					to COMPILE
3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/
#include <iostream>
#include <string>
#include <GL/glut.h>				// include GLUT library
#include <math.h>
#include <vector>
#define PI 3.14159265
using namespace std;
//***********************************************************************************


//global variables
//***********************************************************************************
bool helping = false;
bool flag = false;
GLfloat xr = 0.0f;
GLfloat yr = 0.0f;
GLfloat zr = 0.0f;
int camera_speed = 10;
int camera_range = 100;
double camera_angle = 0;
GLdouble eyex = 200;
GLdouble eyez = 200;
GLdouble eyey = 10;
GLdouble target_x = eyex + camera_range*cos(camera_angle*PI / 180);
GLdouble target_z = eyez + camera_range*(camera_angle*PI / 180);
GLdouble target_y = 0;
vector<int> user_input;
void override_defaults(int a, int b, int c, int d){
	//do nothing
}

//forward declare drawpoints
void drawPoints();
//***********************************************************************************
//Input Handling Functions
//***********************************************************************************
void mouse_window_kill(int button, int state, int x, int y){
	if (button == GLUT_RIGHT_BUTTON){
		helping = false;
		glutHideWindow();
	}
}

void keyboard_thing(int key, int x, int y){
	switch(key){
	case GLUT_KEY_RIGHT:
		//rotate camera to the right(or rotate everything else to the left)
		camera_angle += 5;
		break;
	case GLUT_KEY_LEFT:
		//rotate camera to the left(or rotate everything else to the right)
		camera_angle -= 5;
		break;
	case GLUT_KEY_UP:
		//move the camera up
		eyex += camera_speed*cos(camera_angle*PI / 180);
		eyez += camera_speed*sin(camera_angle*PI / 180);
		break;
	case GLUT_KEY_DOWN:
		//move the camera down
		eyex -= camera_speed*cos(camera_angle*PI / 180);
		eyez -= camera_speed*sin(camera_angle*PI / 180);
		break;
	}
	GLdouble target_x = eyex + camera_range*cos(camera_angle*PI / 180);
	GLdouble target_z = eyez + camera_range*(camera_angle*PI / 180);
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
	camera_angle = 0;
	eyex = 200;
	eyez = 200;
	//eyey = 50;
	/*
	glPopMatrix();
	glPushMatrix();
	xr = 0.0f;
	yr = 0.0f;
	zr = 0.0f;
	glutPostRedisplay();
	*/
}


//*********************************************************************
//Draw Objects
//*********************************************************************
void draw_ground(){

	GLshort v0[] = {200,0,200};
	GLshort v1[] = {-200,0,-200};
	GLshort v2[] = {200,0,-200};
	GLshort v3[] = {-200,0,200};

	glBegin(GL_QUADS);

	glColor3f(0.0f, 1.0f, 0.0f);//Green
	glVertex3sv(v0);//top left
	glVertex3sv(v2);//top right
	glVertex3sv(v1);//bottom right
	glVertex3sv(v3);//bottom left
	glEnd();

}

void draw_roads(){
	//road 1 vertices
	GLshort v0[] = {50,1,200};
	GLshort v1[] = {-50,1,200};
	GLshort v2[] = {50,1,-200};
	GLshort v3[] = {-50,1,-200};
	//road 2 vertices
	GLshort v4[] = {200,1,50};
	GLshort v5[] = {-200,1,50};
	GLshort v6[] = {200,1,-50};
	GLshort v7[] = {-200,1,-50};

	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.0f, 0.0f);//Black
	//road 1
	glVertex3sv(v0);
	glVertex3sv(v2);
	glVertex3sv(v3);
	glVertex3sv(v1);
	//road 2
	glVertex3sv(v4);
	glVertex3sv(v6);
	glVertex3sv(v7);
	glVertex3sv(v5);
	glEnd();
}

void draw_rock(){
	GLshort v0[] = {-200,0,-50};//front-left
	GLshort v1[] = {-100,0,-50};//front-right
	GLshort v2[] = {-200,0,50};//right-back
	GLshort v3[] = {-100,0,50};//left-back
	GLshort v4[] = {-150,100,0};//top

	glBegin(GL_TRIANGLES);

	glColor3f(0.5f, 0.5f, 0.5f);//Grey
	//front
	glVertex3sv(v0);
	glVertex3sv(v1);
	glVertex3sv(v4);
	//right
	glVertex3sv(v1);
	glVertex3sv(v3);
	glVertex3sv(v4);
	//back
	glVertex3sv(v2);
	glVertex3sv(v3);
	glVertex3sv(v4);
	//left
	glVertex3sv(v2);
	glVertex3sv(v0);
	glVertex3sv(v4);

	glEnd();
}

void draw_building(){
	//top vertices
	GLshort v0[] = {-50,50,125};//front-left
	GLshort v1[] = {50,50,125};//front-right
	GLshort v2[] = {50,50,175};//right-back
	GLshort v3[] = {-50,50,175};//left-back
	//bottom vertices
	GLshort v4[] = {-50,0,125};//front-left
	GLshort v5[] = {50,0,125};//front-right
	GLshort v6[] = {50,0,175};//right-back
	GLshort v7[] = {-50,0,175};//left-back

	glBegin(GL_QUADS);

	glColor3f(0.5f, 0.5f, 0.5f);//Grey
	//front
	glVertex3sv(v0);
	glVertex3sv(v1);
	glVertex3sv(v5);
	glVertex3sv(v4);
	//right
	glVertex3sv(v1);
	glVertex3sv(v2);
	glVertex3sv(v6);
	glVertex3sv(v5);
	//back
	glVertex3sv(v2);
	glVertex3sv(v3);
	glVertex3sv(v7);
	glVertex3sv(v6);
	//left
	glVertex3sv(v3);
	glVertex3sv(v0);
	glVertex3sv(v4);
	glVertex3sv(v7);
	//top
	glVertex3sv(v0);
	glVertex3sv(v1);
	glVertex3sv(v2);
	glVertex3sv(v3);
	glEnd();
}

void draw_sign(){
//top vertices
	GLshort v0[] = {75,50,-77.5};//front-left
	GLshort v1[] = {175,50,-77.5};//front-right
	GLshort v2[] = {75,50,-72.5};//right-back
	GLshort v3[] = {175,50,-72.5};//left-back
	//bottom vertices
	GLshort v4[] = {75,0,-77.5};//front-left
	GLshort v5[] = {175,0,-77.5};//front-right
	GLshort v6[] = {75,0,-72.5};//right-back
	GLshort v7[] = {175,0,-72.5};//left-back

	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);//Red
	//front
	glVertex3sv(v0);
	glVertex3sv(v1);
	glVertex3sv(v5);
	glVertex3sv(v4);
	//right
	glVertex3sv(v1);
	glVertex3sv(v2);
	glVertex3sv(v6);
	glVertex3sv(v5);
	//back
	glVertex3sv(v2);
	glVertex3sv(v3);
	glVertex3sv(v7);
	glVertex3sv(v6);
	//left
	glVertex3sv(v3);
	glVertex3sv(v0);
	glVertex3sv(v4);
	glVertex3sv(v7);
	//top
	glVertex3sv(v0);
	glVertex3sv(v1);
	glVertex3sv(v2);
	glVertex3sv(v3);
	glEnd();
}

void draw_sky(){

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

//***********************************************************************************
//Main Functions
//***********************************************************************************


void drawPoints()
{
	//glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(eyex, eyey, eyez, target_x, target_y, target_z, 0, 1, 0);
	glLineWidth(1);//set width
	glPointSize(1);//set pointsize

	//Draw Objects
	draw_ground();
	draw_roads();
	draw_rock();
	draw_sign();

	draw_building();
	draw_sky();
	draw_axes();

	//draw_car();

	glPopMatrix();
}

//***********************************************************************************
void myInit(){
	glClearColor(0.9, 0.9, 1, 0);	// specify a background color: light blue
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glOrtho(-400, 400, -400, 400, -800, 800);  // specify a viewing area

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
 glutCreateWindow("3D Scene");	// create a titled window
 myInit();									// setting up
 glutSpecialFunc(keyboard_thing);
 glutMouseFunc(override_defaults);
 glutDisplayFunc(myDisplayCallback);		// register a callback


 glutMainLoop();							// get into an infinite loop
}
