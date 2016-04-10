/*
-----------------------------------------------------------------------------------
 COURSE:		CSC125, 001, Homework4
 PROGRAMMER:	Sean Straus, Straus21
 DATE MODIFIED:	2/11/2014

 DESCRIPTION:	This program stores and displays information about a transfer student
 FILES:			hw4.cpp
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
	string name = "Peter Ford";
	unsigned short age = 21;
	//social security number
	unsigned long ssn = 789341256;
	//Gender: 1 = male, 0 = female
	bool gender = 1;
	string genstr = "FM";
	trha = 58; 
	trqpts = 182.0; 
	msuha = 25; 
	msuqpts = 93.0; 
	trgpa = gpacalc(trqpts,trha);
	msugpa = gpacalc(msuqpts,msuha);
	gpa = gpacalc((trqpts+msuqpts),(trha+msuha));

	//Print Information to Screen
	cout << "Student Name: " << name << endl;
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