/*==================================================================================================
 PROGRAMMER:			Yang Wang
 COURSE:				CSC 525/625
 MODIFIED BY:			N/A
 LAST MODIFIED DATE:	11/28/2015
 DESCRIPTION:			The program reads in 2D textures (RGB images) and map to 2D objects. It
						is composed of a source file textureTo2D_p2.cpp, which contains all operations
						related to texture mapping, and a pre-compiled object file textureTo2D_p1.obj,
						which contains all other operations.
 NOTE:					1. Since the object file is created with the configuration of our departmental
						   lab machines, it might not work on machines at other places.
						2. The assumed location for the image files is folder C:\Temp.
						3. Brfore compile/build:
 						  a) Link to your C++ project the source file "textureTo2D_p2.cpp" under the 
						     "Source Files" folder.
						  b) Link to your C++ project the object file "textureTo2D_p1.obj" under the
							 "Resource Files" folder.
 FILES:					textureTo2D_p2.cpp, textureTo2D_p1.obj, redLava256x256UB.raw, 
						emerald256x256UB.raw, (xxx.sln, ...)
 IDE/COMPILER:			MicroSoft Visual Studio 2013
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on xxx.sln			to OPEN the project
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
	4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/
#include<GL/glut.h>

#define	imgWidth  256 	// size of the textures (RGB images)
#define	imgHeight 256 
#define	imgDepth  3

// variables declared in textureTo2D_p1.obj already
extern GLubyte myImg1[imgHeight][imgWidth][imgDepth]; //arrays to hold the textures
extern GLubyte myImg2[imgHeight][imgWidth][imgDepth];

// Subroutines related to texture mapping
//***********************************************************************************
void initSettingForTextureMapping()			// a subroutine called by main()
{glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

//***********************************************************************************
void myDrawing()							// a subroutine called by a displayCallback
{// Texture mapping with the 1st image
 glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, myImg1); 
 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

 glEnable(GL_TEXTURE_2D);
	glColor3f(1, 0, 1);
	glBegin(GL_POLYGON);					// a magenta square
		glTexCoord2f(0,0); glVertex2f(-200, -150);
		glTexCoord2f(1,0); glVertex2f(0, -150);
		glTexCoord2f(1,1); glVertex2f(0, 50);
		glTexCoord2f(0,1); glVertex2f(-200, 50);
	glEnd();
 glDisable(GL_TEXTURE_2D);

 glBegin(GL_POLYGON);						// a magenta pentagon
   glVertex2f(-50, 190);
   glVertex2f(-150, 190);
   glVertex2f(-180, 130);
   glVertex2f(-100, 80);
   glVertex2f(-20, 130);
 glEnd();

 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD);	// change from REPLACE to ADD

 glEnable(GL_TEXTURE_2D);
 	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);					// a blue triangle
		glTexCoord2f(0.3,0.2); glVertex2f( 10, -50);
		glTexCoord2f(0.6,1.0); glVertex2f(210, 220);
		glTexCoord2f(0.2,0.8); glVertex2f( 10, 220);
	glEnd();

 // Texture mapping with the 2nd image
 glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, myImg2);

	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);					// a red rectangle
		glTexCoord2f(0.8, 0.9); glVertex2f(50, -200);
		glTexCoord2f(0.2, 0.5); glVertex2f(230, -200);
		glTexCoord2f(0.5, 0.0); glVertex2f(230, -110);
		glTexCoord2f(1.0, 0.3); glVertex2f(50, -110);
	glEnd();

 glDisable(GL_TEXTURE_2D);
}