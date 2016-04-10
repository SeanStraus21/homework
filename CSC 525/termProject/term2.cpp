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
#include<fstream>
#include"doodads.h"
#include"textures.h"
#define PI 3.14159265

using namespace std;

string filename;

GLfloat xr = 0.0f;
GLfloat yr = 0.0f;
GLfloat zr = 0.0f;
int camera_distance = 20;
double camera_angle = 90;
GLdouble eyex = 100*cos(camera_angle*PI/180);
GLdouble eyez = 100*sin(camera_angle*PI/180);
GLdouble eyey = 80;
float TransX = 0;
float TransY = 0;
float TransZ = 0;
float TransLine = 0;

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

GLfloat skyTex[160][160][3];
GLfloat roadTex[512][512][3];

tex rockTex;
tex sign1Tex;
tex sign2Tex;
tex cheekTex;
//***********************************************************************************
void drawCar()
{
	glTranslatef(TransX,TransY,TransZ);
	glPointSize(1);		// change point size back to 1

	glBegin(GL_POINTS);	// use points to form X-/Y-axes
	glColor3f(0, 0, 0);			 // change drawing color to black
	for (int x = -500; x <= 500; x++) // draw X-axis
		glVertex3i(x, 0, 0);
	for (int y = -500; y <= 500; y++) // draw Y-axis
		glVertex3i(0, y, 0);
	for (int z = -500; z <= 500; z++) // draw Z-axis
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
	glColor3f(0,0.85, 1);
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
void background()
{
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 512,512, 0, GL_RGB, GL_UNSIGNED_BYTE, *roadTex);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(700, 0,1000);
	glVertex3f(700, 0,-1000);
	glVertex3f(-700, 0,-1000);
	glVertex3f(-700, 0, 1000);
	glEnd();
	//glColor3f(0.5, 0.5, 0.5);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 160, 160, 0, GL_RGB, GL_FLOAT, *skyTex);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glTexCoord2f(1, 0); glVertex3f(100,500, 1);
	glTexCoord2f(1, 1); glVertex3f(50, -500, 1);
	glTexCoord2f(0, 1); glVertex3f(-50, -500, 1);
	glTexCoord2f(0, 0); glVertex3f(-100, 500, 1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void sky()
{
	//sky
	//glColor3f(0, 0.75, 1);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 160,160, 0, GL_RGB, GL_FLOAT, *skyTex);

	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0.25); glVertex3f(-500, -200, -220);
	glTexCoord2f(0, 0.75); glVertex3f(-500, 500, -220);
	glTexCoord2f(1,0.75); glVertex3f(500,500,-220);
	glTexCoord2f(1, 0.25); glVertex3f(500, -200, -220);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void lines()

{
	glTranslatef(0,0,TransLine);
	glColor3f(1,1,0);
	glBegin(GL_QUADS);
	for (int z =420; z>=-1200; z -= 90)
	{
		glVertex3f(-5, 1.2,z+60);
		glVertex3f(-5, 1.2,z);
		glVertex3f(5, 1.2,z);
		glVertex3f(5, 1.2,z+60);
	}
	glEnd();
}


//***********************************************************************************
void myInit()
{
	glClearColor(1, 1, 1, 0);			// specify a background clor: white
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	glOrtho(-300,300,-300,300,-300,300);  // specify a viewing area
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	glPushMatrix();

	//gluLookAt(0, 0, 60, 0, 0, 0, 0, 1, 0);//camera
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// draw the background
	glPushMatrix();
	gluLookAt(eyex,eyey,eyez, 0,0,0,0,1,0);
	drawCar();
	glTranslatef(0-TransX,0-TransY,0-TransZ);
	background();
	lines();
	draw_doodads(0, 0,TransLine);
	glPopMatrix();

	sky();
	glFlush(); // flush out the buffer contents
}
//***********************************************************************************
void timerCallback(int value)
{
	if (value == 1){
	TransLine += 5;
	}

	myDisplayCallback();
	glutTimerFunc(100, timerCallback, 1);

}
//***********************************************************************************
void keyboardCallback(unsigned char key, int x, int y) {
	if (key == 'w'){
		//move the camera up
		eyey += 10;
	}
	if (key == 'a'){
		//rotate camera to the left(or rotate everything else to the right)
		camera_angle -= 5;
		eyex = 100*cos(camera_angle*PI/180);
		eyez = 100*sin(camera_angle*PI/180);
	}
	if (key == 's'){
		//move the camera down
		eyey -= 10;
	}
	if (key == 'd'){
		//rotate camera to the right(or rotate everything else to the left)
		camera_angle += 5;
		eyex = 100*cos(camera_angle*PI/180);
		eyez = 100*sin(camera_angle*PI/180);
	}
	if (key == ' '){
		timerCallback(1);
	}
	cout<<eyex << " " << eyey << " " << eyez<< " ";
	myDisplayCallback();
}

void keyboardCallback2(int key, int x, int y){
	switch(key){
	case GLUT_KEY_RIGHT:
		TransX += 3.0f;
		break;
	case GLUT_KEY_LEFT:
		TransX += -3.0f;
		break;
	case GLUT_KEY_UP:
		TransZ += -5.0f;
		break;
	case GLUT_KEY_DOWN:
		TransZ += 5.0f;
		break;
	}
	//cout<< TransX << " " <<TransY<< " " << TransZ;
	myDisplayCallback();
}

//***********************************************************************************
int main(int argc, char ** argv)
{
	/*string fileloc = "C:\\TEMP\\sky.txt";
	ifstream myfile;
	float input;
	myfile.open(fileloc);
	for (int i = 249; i >=0; i--)
	{
		for (int j = 249; j>= 0; j--)
		{
			for (int k = 2; k >=0; k--)
			{
				myfile >> r;
				skyTex[i][j][k] = input;

			}
		}
	}*/

	/*ifstream input("C:\\TEMP\\sky.txt");
	if (!input) {
		cout << "Please place vollmar-face.txt in your C:\\TEMP directory.\n";
		exit(1);
	}
	else
	{
		//Read in RGB data
		float r, g, b;
		for (int i = 159; i >= 0; --i) {
			for (int j = 159; j >= 0; --j) {
				input >> r;
				input >> g;
				input >> b;
				skyTex[i][j][0] = r / 255; //data in file is 0-255, need 0-1
				skyTex[i][j][1] = g / 255;
				skyTex[i][j][2] = b / 255;
			}
		}
	}
	input.close();*/
	float input;
	string path = "C:/Users/Sean/Homework/CSC 525/termProject/Road.txt";
	ifstream myfile;
	myfile.open(path);
	if (myfile.is_open()){
		for (int i = 0; i < 160; i++)
		{
			for (int j = 0; j < 160; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					myfile >> input;
					skyTex[i][j][k] = input / 255;
				}
			}
		}
		myfile.close();
	}else{
		cout<<"unable to open file" <<endl;
	}
	tex rockTex = get_texture("C:/Users/Sean/Homework/CSC 525/termProject/projectRock.txt");
	tex sign1Tex = get_texture("C:/Users/Sean/Homework/CSC 525/termProject/projectSign1.txt");
	tex sign2Tex = get_texture("C:/Users/Sean/Homework/CSC 525/termProject/projectSign2.txt");
	tex cheekTex = get_texture("C:/Users/Sean/Homework/CSC 525/termProject/projectCheek.txt");

	/*fileloc = "C:\\TEMP\\Road.txt";
	ifstream myfile1;
	myfile1.open(fileloc);
	for (int i = 0; i < 512; i++)
	{
		for (int j = 0; j < 512; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				myfile1 >> input;
				roadTex[i][j][k] = input / 255;
			}
		}
	}*/
	//myfile1.close();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH);
	glutInitWindowSize(600,600);				// specify a window size
	glutInitWindowPosition(100, 0);
	// specify a window position
	glutCreateWindow("Cruisin down the street");	// create a titled window
	myInit();									// setting up
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glutDisplayFunc(myDisplayCallback);			// register a callback
	glutKeyboardFunc(keyboardCallback);
	glutSpecialFunc(keyboardCallback2);
	glutMainLoop();							// get into an infinite loop

	return 1;
}
