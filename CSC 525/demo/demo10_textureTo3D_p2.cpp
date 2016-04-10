/*==================================================================================================
 PROGRAMMER:			Yang Wang
 COURSE:				CSC 525/625
 MODIFIED BY:			N/A
 LAST MODIFIED DATE:	11/28/2015
 DESCRIPTION:			The program reads in 2D textures (RGB images) and map to 3D objects. It
						is composed of a source file textureTo3D_p2.cpp, which contains all operations
						related to texture mapping, and a pre-compiled object file textureTo3D_p1.obj,
						which contains all other operations.
 NOTE:					1. Since the object file is created with the configuration of our departmental
						   lab machines, it might not work on machines at other places.
						2. The assumed location for the image files is folder C:\Temp.
						3. Brfore compile/build:
						  a) Link to your C++ project the source file "textureTo3D_p2.cpp" under the
							 "Source Files" folder.
						  b) Link to your C++ project the object file "textureTo3D_p1.obj" under the
							 "Resource Files" folder.
 FILES:					textureTo3D_p2.cpp, textureTo3D_p1.obj, redLava256x256UB.raw, 
						io32x32UB.raw, (xxx.sln, ...)
 IDE/COMPILER:			MicroSoft Visual Studio 2013
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on xxx.sln			to OPEN the project
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
	4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/
#include <GL/glut.h>

#define	img1Width  256	// size of the textures (RGB images)
#define	img1Height 256 
#define	img2Width  32
#define	img2Height 32
#define	imgDepth   3

#define	Replace		11	// menu options
#define Blend		12

// variables/functions definded in textureTo3D_p1.obj already
extern GLubyte myImg1[img1Height][img1Width][3]; //arrays to hold the textures
extern GLubyte myImg2[img2Height][img2Width][3];

extern GLUquadricObj * sphere;		// two 3D objects for texture mapping
extern GLUquadricObj * cylinder;

void myDisplayCallback();

//***********************************************************************************
// Stuff related to texture mapping

GLuint textures[2];		// this demo will use two texture objects

//***********************************************************************************
void initSettingForTextureMapping()		// a subroutine called by main()
{glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); // my default setting

 sphere   = gluNewQuadric();			// create two 3D geometric objects
 cylinder = gluNewQuadric();
 gluQuadricTexture(sphere, GL_TRUE);	// generate texture coordinates for the geometric objects
 gluQuadricTexture(cylinder, GL_TRUE);

 glGenTextures(2, textures);			// Generate two texture names and store them in array textures

 glBindTexture(GL_TEXTURE_2D, textures[0]);			// create the 1st texture object
 glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img1Width, img1Height, 
	          0, GL_RGB, GL_UNSIGNED_BYTE, myImg1);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

 glBindTexture(GL_TEXTURE_2D, textures[1]);			// create the 2nd texture object
 glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img2Width, img2Height, 
	          0, GL_RGB, GL_UNSIGNED_BYTE, myImg2);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

 glEnable(GL_TEXTURE_2D);
}

//***********************************************************************************
void myDrawing()						// a subroutine called by a displayCallback
{// For a yellow sphere
 glBindTexture(GL_TEXTURE_2D, textures[0]);	// activate the 1st texture object

 glColor3f(1, 1, 0);
 gluSphere(sphere, 100, 100, 100);

 // For a blue cylinder
 glBindTexture(GL_TEXTURE_2D, textures[1]);	// activate the 2nd texture object

 glPushMatrix();				 // preserve the matrix for the sphere
 glTranslatef(100, -150.0, 0.0); // to avoid overlapping with the sphere near the origin
 glColor3f(0, 0, 1);
 gluCylinder(cylinder, 50, 50, 200, 100, 1);
 glPopMatrix();					 // resume the matrix for the sphere
}

//***********************************************************************************
void myTextureMenuCallback(int option)	// option  MUST be Replace or Blend (error 
{switch (option)						// handling for out-of-range is done by the caller)
 {case Replace: glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);  break;
  case Blend:	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND); break;
 }
 myDisplayCallback();
}