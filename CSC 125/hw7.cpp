/*
-----------------------------------------------------------------------------------
 COURSE:		CSC125, 001, Homework 7
 PROGRAMMER:	Sean Straus, Straus21
 DATE MODIFIED:	3/20/2014

 DESCRIPTION:	This program receives, stores, and displays information about transfer students using files
 FILES:			hw7.cpp
 IDE/COMPILER:	MicroSoft Visual Studio 2012
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1. Double click on homeworkProject.sln	to OPEN the project
	2. Press Ctrl+F7	to COMPILE
	3. Press Ctrl+Shift+B	to BUILD (COMPILE+LINK)
	4. Press Ctrl+F5	to EXECUTE

NOTES: To save time testing, I hardcoded the address of my file on eccentric into lines 50 and 115
	You only need to type info*.txt

------------------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//Calculates Quality points by the formula Quality points = Hours Attempted x Grade Points
float gpacalc(float qpt,float ha)
{
	return (qpt/ha);
}

int main()
{	
	// Social Security Number
	unsigned int  ssn;
	// Transferred Hours Attempted, MSU Quality Points, Transferred GPA, MSU GPA, Total GPA,Transferred Quality Points, MSU Hours Attempted
	float trgpa, msugpa, gpa; 
	string name, sex, filename, headerdump, tempstr;
	unsigned short age,trha, msuha,trqpts, msuqpts;
	ifstream ifile;
	ofstream ofile;


	//request data from user
	cout << "Enter the name of a file which contains the information of a student" << endl;
	getline(cin,filename);
	
	//open file and extract data
	ifile.open("\\\\eccentric\\Class\\csc125\\001\\Straus21\\hws\\hw07\\" + filename);
	if (ifile.is_open())
	{
		getline(ifile,headerdump,'	');
		getline(ifile,name);

		getline(ifile,headerdump,'	');
		getline(ifile,tempstr);
		age = atoi(tempstr.c_str());

		getline(ifile,headerdump,'	');
		getline(ifile,tempstr);
		ssn = atoi(tempstr.c_str());

		getline(ifile,headerdump,'	');
		getline(ifile,sex);

		getline(ifile,headerdump,':');
		getline(ifile,tempstr,'	');
		trha = atoi(tempstr.c_str());

		getline(ifile,headerdump,':');
		getline(ifile,tempstr,'\n');
		trqpts = atoi(tempstr.c_str());

		getline(ifile,headerdump,'	');
		getline(ifile,tempstr,'	');
		msuha = atoi(tempstr.c_str());

		getline(ifile,headerdump,'	');
		getline(ifile,tempstr);
		msuqpts = atoi(tempstr.c_str());

		ifile.close();
	}
	else 
	{
		cout << "failed to open file";
	}
	
	//calculate gpas
	trgpa = gpacalc(trqpts,trha);
	msugpa = gpacalc(msuqpts,msuha);
	gpa = float(gpacalc((trqpts+msuqpts),(trha+msuha)));

	//Print Information to Screen
	cout << endl << endl << endl;
	cout << "Name: " << name << endl;
	cout << "Age:  " << age << endl;
	cout << "SSN:  " << ssn << endl;
	cout << "Sex:  " << sex << endl << endl;

	cout << "Transferred Hours: " << setfill(' ') << setw(3) << trha;
	cout << setfill(' ') << setw(35) << "Transferred Quality Points: "; 
	cout << setfill(' ') << setw(3) << trqpts << endl;
	cout << "MSU Hours:         " << setfill(' ') << setw(3) << msuha;
	cout << setfill(' ') << setw(35)<< "MSU Quality Points:         ";
	cout << setfill(' ') << setw(3) << msuqpts << endl << endl;

	cout << fixed << setprecision(2);
	cout << "Transfer GPA:"  << setfill(' ') << setw(6) << trgpa << endl;
	cout << "MSU GPA:     "  << setfill(' ') << setw(6) << msugpa << endl;
	cout << "Overall GPA: " << setfill(' ') << setw(6) << gpa << endl;
	
	ofile.open("\\\\eccentric\\Class\\csc125\\001\\Straus21\\hws\\hw07\\record_of_"+ filename);
	if (ofile.is_open())
	{	
		ofile << "Name:	" << name << endl;
		ofile << "Age:	" << age << endl;
		ofile << "SSN:	" << ssn << endl;
		ofile << "Sex:	" << sex << endl << endl;
		ofile << "Transfer Hours:   " << trha  << "	Transfer Quality Points:   " << trqpts << endl;
		ofile << "MSU Hours:	" << msuha  << "	MSU Quality Points:		   " << msuqpts << endl << endl;
		ofile << "Transfer GPA:"  << setfill(' ') << setw(6) << trgpa << endl;
		ofile << "MSU GPA:     "  << setfill(' ') << setw(6) << msugpa << endl;
		ofile << "Overall GPA: " << setfill(' ') << setw(6) << gpa << endl;
		ofile.close();
	}

	//keep the window from closing
	while (true);
	{
	cin >> age;
	}

	return 0;
}