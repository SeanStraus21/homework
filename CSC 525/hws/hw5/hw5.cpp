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
GLint win1, win2;
bool helping = false;
bool flag = false;
GLfloat xr = 0.0f;
GLfloat yr = 0.0f;
GLfloat zr = 0.0f;
int camera_distance = 50;
double camera_angle = 0;
GLdouble eyex = 100*cos(camera_angle*PI/180);
GLdouble eyez = 100*sin(camera_angle*PI/180);
GLdouble eyey = 100;
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



void change_view(int type){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	switch (type){
	case 0://orthogonal
		glOrtho(-400, 400, -400, 400, -800, 800);
		break;
	case 1://perspective
		glFrustum(-400, 400, -400, 400, -800, 800);
		break;
	}

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
	camera_angle = 0;
	eyex = 100*cos(camera_angle*PI/180);
	eyez = 100*sin(camera_angle*PI/180);
	eyey = 100;
	/*
	glPopMatrix();
	glPushMatrix();
	xr = 0.0f;
	yr = 0.0f;
	zr = 0.0f;
	glutPostRedisplay();
	*/
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
		glutDestroyWindow(win1);
		glutDestroyWindow(win2);
		exit(0);
		break;
	case 8:
		change_view(0);
		break;
	case 9:
		change_view(1);
		break;
	case 10:
		helping = true;
		glutSetWindow(win2);
		glutShowWindow();
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
		glutAddMenuEntry("Help", 10);
		glutAddMenuEntry("Reset", 6);
		glutAddMenuEntry("Exit", 7);
		glutAddSubMenu("Rotate Around X Axis", rx_menu);
		glutAddSubMenu("Rotate Around Y Axis", ry_menu);
		glutAddSubMenu("Rotate Around Z Axis", rz_menu);
		glutAddSubMenu("Change View", view_menu);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
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
	gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
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

	glPopMatrix();
}

void drawHelp(){
	if (helping){
		glutShowWindow();
		string string1 = "Right click to open up the menu in the ";
		string string2 = "main window. Click on any of the ";
		string string3 = "rotations to rotate the view.press the ";
		string string4 = "arrow keys to rotate the object also.";
		string string5 = "Right click on this window to close it. ";
		string string6 = "Click exit in the menu to exit. You may ";
		string string7 = "click reset if you would like to restart.";
		int l = string1.length();
		int l2= string2.length();
		int l3= string3.length();
		int l4= string4.length();
		int l5= string5.length();
		int l6= string6.length();
		int l7= string7.length();
		glColor3f(0,0,0);
		glBegin(GL_POINT);
		for (int i = 0; i < l; i++){
			glRasterPos2s(-200 + 10*i, 150);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string1[i]);
		}
		for (int i = 0; i < l2; i++){
			glRasterPos2s(-200 + 10*i, 139);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string2[i]);
		}
		for (int i = 0; i < l3; i++){
			glRasterPos2s(-200 + 10*i, 128);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string3[i]);
		}
		for (int i = 0; i < l4; i++){
			glRasterPos2s(-200 + 10*i, 117);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string4[i]);
		}
		for (int i = 0; i < l5; i++){
			glRasterPos2s(-200 + 10*i, 106);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string5[i]);
		}
		for (int i = 0; i < l6; i++){
			glRasterPos2s(-200 + 10*i, 95);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string6[i]);
		}
		for (int i = 0; i < l7; i++){
			glRasterPos2s(-200 + 10*i, 84);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string7[i]);
		}
		glEnd();

		

		glutPostRedisplay();
	}else{
		//glutHideWindow();
	}
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

void myInit2(){
 glClearColor(1, 1, 1, 0);			// specify a background clor: white
 gluOrtho2D(-200, 200, -200, 200);  // specify a viewing area
}

//***********************************************************************************
void myDisplayCallback()
{glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// draw the background

 drawPoints();
 glutSwapBuffers();
 glFlush(); // flush out the buffer contents
}

void myDisplayCallback2()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	drawHelp();

	glFlush(); // flush out the buffer contents
}

//***********************************************************************************
int main(int argc, char ** argv)
{

 glutInit(& argc, argv);

 glutInitWindowSize(400, 400);				// specify a window size
 glutInitWindowPosition(100, 0);			// specify a window position
 win1 = glutCreateWindow("3D Scene");	// create a titled window
 myInit();									// setting up
 menu_create();
 glutSpecialFunc(keyboard_thing);
 //glutMouseFunc(override_defaults);
 glutDisplayFunc(myDisplayCallback);		// register a callback

 glutInitWindowSize(400, 400);				// specify a window size
 glutInitWindowPosition(500, 0);
 win2 = glutCreateWindow("Help");	// create a titled window
 myInit2();
 glutMouseFunc(mouse_window_kill);
 glutDisplayFunc(myDisplayCallback2);
 glutHideWindow();

 glutSetWindow(win1);

 glutMainLoop();							// get into an infinite loop
}
