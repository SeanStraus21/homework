/*=============================================================
	COURSE:	CSC-460, assignment 3
	PROGRAMMERS: 	Sean Straus (ss), Di Wu(dw)
	MODIFIED BY:
	LAST MODIFIED DATE:	03/15/2016
	DESCRIPTION:	Processes a text file and classifies each word as a string, float, or int
	NOTE:
	FILES:	classifier.cpp, classifier.h, main.cpp, makefile
	IDE/COMPILER/INTERPRETER:	C++11
	INSTRUCTION FOR COMPILATION AND EXECUTION:
	1. to COMPILE, run the following line
		$makefile
	2. to EXECUTE, run the following
		$ ./classifier

	Percentage of team members:
        Sean Straus
        Di Wu
=============================================================*/
#include <string>
using namespace std;

char classify(string s);
void child_report(string s, int pe, int child_count);
bool read_report(int &string_count,int &float_count,int &int_count,int pe);
