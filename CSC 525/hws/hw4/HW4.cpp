/*==================================================================================================
PROGRAMMERS:			David Robinson (Robinson003) , Sean Straus (Straus21)
COURSE:				CSC 525/625
MODIFIED BY:
LAST MODIFIED DATE:	11/04/2015
DESCRIPTION:			HW 4
NOTE:					50%
FILES:					HW3.cpp, (hwProject.sln, ...)
IDE/COMPILER:			MicroSoft Visual Studio 2013
INSTRUCTION FOR COMPILATION AND EXECUTION:
1.		Double click on myCPPproj.sln	to OPEN the project
2.		Press Ctrl+F7					to COMPILE
3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/
#include <GL/glut.h>				// include GLUT library
#include<string>
#include<cmath>

using namespace std;

//*************************
class Vertex{
	public:
	float x,y;
	GLfloat color[3];
	Vertex(float x_=0,float y_=0, GLfloat R=0, GLfloat G=0, GLfloat B=0){
		x = x_;
		y = y_;
		color[0] = R;
		color[1] = G;
		color[2] = B;
	}
};

class Crumb{
	Vertex vertices[4];
	float angle = 0;
	float scale_x = 1;
	float scale_y = 1;
	float x = 0;
	float y = 0;
	public:
		Crumb(){
		vertices[0] = Vertex(100,100,1,0,0);
		vertices[1] = Vertex(-100,100,0,1,0);
		vertices[2] = Vertex(-100,-100,0,0,1);
		vertices[3] = Vertex(100,-100,1,1,0);
		}
		float trans_matrix[9] = {
		1,0,0,
		0,1,0,
		0,0,1
		};
		void draw(){
			//compute final matrix
			glBegin(GL_POLYGON);
			float final_x;
			float final_y;
			for (int i=0;i<4;i++){//4 vertices, repeat 4 times
				glColor3f(vertices[i].color[0],vertices[i].color[1],vertices[i].color[2]);
				final_x = vertices[i].x*trans_matrix[0] + vertices[i].y*trans_matrix[1] + trans_matrix[2];
				final_y = vertices[i].x*trans_matrix[3] + vertices[i].y*trans_matrix[4] + trans_matrix[5];
				glVertex2f(final_x,final_y);
			}
			glEnd();
		}
		void set_translation(float x_mod, float y_mod){
		trans_matrix[2]+= x_mod;
		trans_matrix[5]+= y_mod;
		}
		void set_scale(float x_mod,float y_mod){
			scale_x += x_mod;
			scale_y += y_mod;
			trans_matrix[0] = scale_x;
			trans_matrix[4] = scale_y;

		}
		void set_rotation(float r_mod){
			r_mod *= 3.14159265358979323846/180;
			angle += r_mod;
			trans_matrix[0] = cos(angle);
			trans_matrix[1] = -1*sin(angle);
			trans_matrix[3] = sin(angle);
			trans_matrix[4] = cos(angle);

		}
		//replace transformation matrix with identity matrix
		void clear_modifications(){
			angle = 0;
			trans_matrix[0] = 1; trans_matrix[3] = 0; trans_matrix[6] = 0;
			trans_matrix[1] = 0; trans_matrix[4] = 1; trans_matrix[7] = 0;
			trans_matrix[2] = 0; trans_matrix[5] = 0; trans_matrix[8] = 1;

		}
};

//***
//Global Variables
bool quit = false;
int window;
Crumb poly;
//***

void menu(int input){
	switch (input){
	case 1:
		poly.set_translation(-5,0);
		break;
	case 2:
		poly.set_translation(5,0);
		break;
	case 3:
		poly.set_translation(0,-5);
		break;
	case 4:
		poly.set_translation(0,5);
		break;
	case 5:
		poly.set_scale(1,0);
		break;
	case 6:
		poly.set_scale(-1,0);
		break;
	case 7:
		poly.set_scale(0,1);
		break;
	case 8:
		poly.set_scale(0,-1);
		break;
	case 9:
		poly.set_rotation(45);
		break;
	case 10:
		poly.set_rotation(-45);
		break;
	case 11:
		glutDestroyWindow(window);
		exit(0);
		break;
	case 12:
		poly.clear_modifications();
		break;
	}
}

void menu_create(void){
	int translation_menu = glutCreateMenu(menu);
	glutAddMenuEntry("X -5", 1);
	glutAddMenuEntry("X +5", 2);
	glutAddMenuEntry("Y -5", 3);
	glutAddMenuEntry("Y +5", 4);

	int scale_menu = glutCreateMenu(menu);
		glutAddMenuEntry("X Scale + 1", 5);
		glutAddMenuEntry("X Scale - 1", 6);
		glutAddMenuEntry("Y Scale + 1", 7);
		glutAddMenuEntry("Y Scale - 1", 8);


	int rotation_menu = glutCreateMenu(menu);
		glutAddMenuEntry("Rotate +45 degrees", 9);
		glutAddMenuEntry("Rotate -45 degrees", 10);


	int crnt_menu = glutCreateMenu(menu);
	glutAddMenuEntry("Exit", 11);
	glutAddMenuEntry("Reset", 12);
	glutAddSubMenu("Translate", translation_menu);
	glutAddSubMenu("Scale", scale_menu);
	glutAddSubMenu("Rotate", rotation_menu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//***********************************************************************************
void myInit()
{
	glClearColor(1, 1, 1, 0);			// specify a background color: white
	gluOrtho2D(-300, 300, -300, 300);  // specify a viewing area
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	poly.draw();

	glFlush(); // flush out the buffer contents
}

//***********************************************************************************
int main(int argc, char ** argv)
{

	glutInit(& argc, argv);

	glutInitWindowSize(512, 512);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	window = glutCreateWindow("Simple Point Drawing");	// create a titled window

	myInit();									// setting up
	menu_create();
	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutMainLoop();							// get into an infinite loop
}
