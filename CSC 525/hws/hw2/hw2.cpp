/*==================================================================================================
 PROGRAMMERS:			Sean Straus(Straus21), David Robinson (Robinson003)
 CONTRIBUTION:			Straus 50%, Robinson 50%
 TASKS:
	Straus				Scanline Algorithm
	Robinson			Edge Class, Point Class, UserInput Handling
 COURSE:				CSC 525/625
 MODIFIED BY:			
 LAST MODIFIED DATE:	9/17/2015
 DESCRIPTION:			HW 2
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
#include <vector>
#include <algorithm>
using namespace std;
//***********************************************************************************

class Point{
	public:
	int x, y;
	Point(int a = 0, int b = 0){
		x = a;
		y = b;
	}
	friend bool operator> (Point &a, Point &b);
	friend bool operator< (Point &a, Point &b);
};
	bool operator> (Point &a, Point &b)
	{
		bool output;
		if (a.y == b.y){
			output = a.x > b.x;
		}
		else{
			output = a.y > b.y;
		}
		return output;
	}

	bool operator< (Point &a, Point &b)
	{
		bool output;
		if (a.y == b.y){
			output = a.x < b.x;
		}
		else{
			output = a.y < b.y;
		}
		return output;
	}



class Edge{
	public:
	Point p1, p2;
	Edge(Point a, Point b){
		p1 = a;
		p2 = b;
	}
	void align(){
		if (p2.x < p1.x){
			Point temp;
			temp = p1;
			p1 = p2;
			p2 = temp;
		}
	}
};

//GLOBAL VECTOR
vector<Edge> global_vector;

//Utility Function, returns -1 if x is negative, 1 if positive, and 0 if 0;
short sign(int x){
	short output = ((x > 0) ? 1 : ((x < 0) ? -1 : 0));
	return output;
}

void generate_polygon(vector<Point> points){
	for (int i = 0; i < points.size()-1; i++){
		global_vector.push_back(Edge(points.at(i),points.at(i+1)));
	}
	global_vector.push_back(Edge(points.at(points.size() - 1), points.at(0)));
}

/**
The scan_line function takes a vector of edges as a parameter
For each scanline it draws a line a single pixel in length.
*/
void scan_line(vector<Edge> edges){
	int h; //height of the polygon = max_y - min_y
	float delta, sigma; //used for controlling rasterization of diagonal lines
	int x, y;
	glPointSize(6);//set pointsize
	glColor3f(255, 0, 0);//set color
	vector<Point> intersections;
	//find the points of intersection
	for (int i = 0; i < edges.size(); i++){ //for each line, convert to series of points and add to vector: "intersections"
		edges.at(i).align();
		Point a = edges.at(i).p1;
		Point b = edges.at(i).p2;
		if (b.x != a.x){	//if not a vertical line
			sigma = 0;
			delta = abs(float(a.y - b.y) / float(a.x - b.x));
			y = a.y;
			//begin finding points, going left to right
			for (x = a.x; x < b.x; x++){
				intersections.push_back(Point(x, y));
				sigma += delta;
				while (sigma >= 0.5){
					intersections.push_back(Point(x, y));
					y -= sign(a.y - b.y);
					sigma -= 1.0;
				}
			}
		}else{//if it is a vertical line
			for (y = a.y; y != b.y; y += sign(b.y - a.y)){
				intersections.push_back(Point(a.x, y));
			}
		}
		

	}
	//sort the points of intersection by y, secondarily by x, so that all the points on the same row are adjacent within the vector
	for (int i = 0; i < intersections.size(); i++){
		cout << "index:" << i << " x:" << intersections.at(i).x << " y:" << intersections.at(i).y << endl;
	}
	sort(intersections.begin(), intersections.end());

	h = intersections.at(intersections.size()-1).y - intersections.at(0).y;

	glBegin(GL_LINES);
	glPointSize(4);//set pointsize
	glColor3f(0, 0, 0);//set color
	for (int i = 0; i < intersections.size(); i+=2){
		glVertex2i(intersections.at(i).x, intersections.at(i).y);
		glVertex2i(intersections.at(i+1).x, intersections.at(i+1).y);
	}
	glEnd();
}



//main function, draws stuff
void drawPoints()
{	
	
	//Scanline Algorithm
	scan_line(global_vector);

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

 string filename;
 //request file path from user
 cout << "Enter the complete path including the name and file extension of a file containing the schematics for a polygon." << endl;
 cin >> filename;

 //extract coordinates from file
 ifstream myfile(filename);
 vector<Point> points;
 int line_count, x, y;
 float R, G, B;
 if (myfile.is_open()){
	 myfile >> line_count;
   	 for (int i = 0; i < line_count; i++){
		 //get points
		 myfile >> x;
		 myfile >> y;
		 myfile >> R;
		 myfile >> G;
		 myfile >> B;
		 Point p = Point(x, y);
		 points.push_back(p);
	 }
	 generate_polygon(points);
	 myfile.close(); 
 }else{
	 //show error if file not found
	 cout << "Specified file Not Found. Check to make sure you entered a valid file name." << endl;
	 return;
 }

	glutInit(&argc, argv);

	glutInitWindowSize(400, 400);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("Simple Point Drawing");	// create a titled window

	myInit();									// setting up

	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutMainLoop();							// get into an infinite loop
 }
