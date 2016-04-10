/*
-----------------------------------------------------------------------------------
 COURSE:		CSC125, 001, Homework5
 PROGRAMMER:	Sean Straus, Straus21
 DATE MODIFIED:	2/20/2014

 DESCRIPTION:	This program receives, stores, and displays information about transfer students
 FILES:			hw5.cpp
 IDE/COMPILER:	MicroSoft Visual Studio 2012
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1. Double click on HomeworkProject.sln	to OPEN the project
	2. Press Ctrl+F7	to COMPILE
	3. Press Ctrl+Shift+B	to BUILD (COMPILE+LINK)
	4. Press Ctrl+F5	to EXECUTE

------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

//Calculates Quality points by the formula Quality points = Hours Attempted x Grade Points
float gpacalc(float qpt,int ha)
{
	return (qpt/ha);
}

int main()
{	
	// Transferred Hours Attempted, MSU Hours Attempted
	unsigned int trha, msuha;
	// Transferred Quality Points, MSU Quality Points, Transferred GPA, MSU GPA, Total GPA
	float trqpts, msuqpts, trgpa, msugpa, gpa; 
	string firstname, lastname;
	unsigned short age;
	//social security number
	unsigned long ssn;
	//Gender: 1 = male, 0 = female
	bool gender = 1;
	string genstr = "FM"; //this would be more efficient if multiple students were stored

	//request data from user
	cout << "Enter student's first name" << endl;
	cin >> firstname;
	cout << "Enter student's last name" << endl;
	cin >> lastname;
	cout << "enter student's Social Security Number (enter a single ten digit number)" << endl;
	cin >> ssn;
	cout << "Enter student's age (enter a positive integer)" << endl;
	cin >> age;
	cout << "Enter student's gender (enter either 1 for male or 0 for female)" << endl;
	cin >> gender;
	cout << "Enter the number of hours attempted being tranferred (enter a single integer between 0 and 999)" << endl;
	cin >> trha;
	cout << "Enter the number of quality points being tranferred (enter a single integer between 0 and 999)" << endl;
	cin >> trqpts;
	cout << "Enter the number of hours attempted at MSU (enter a single integer between 0 and 999)" << endl;
	cin >> msuha;
	cout << "Enter the number of quality points earned at MSU (enter a single integer between 0 and 999)" << endl;
	cin >> msuqpts;
	//calculate gpas
	trgpa = gpacalc(trqpts,trha);
	msugpa = gpacalc(msuqpts,msuha);
	gpa = gpacalc((trqpts+msuqpts),(trha+msuha));

	//Print Information to Screen
	cout << "Student Name: " << firstname << " " << lastname << endl;
	cout << "Age: " << age << endl;
	cout << "Gender: " << genstr[gender] << endl;
	cout << "SSN: " << ssn << endl;
	cout << "Transferred Hours Attempted: " << trha << endl;
	cout << "Transferred Quality Points: " << trqpts << endl;
	cout << "Transfer GPA: " << trgpa << endl;
	cout << "MSU Hours Attempted: " << msuha << endl;
	cout << "MSU Quality Points: " << msuqpts << endl;
	cout << "MSU GPA: " << msugpa << endl;
	cout << "Total GPA: " << gpa << endl;

	return 0;
}