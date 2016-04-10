/*
----------------------------------------------------------------------------------
COURSE:			CSC 125 001, Homework 3
LAST MODIFIED:	2/06/2014
PROGRAMMER:		Sean Straus, Straus21

Description: This program displays two stunningly rendered playing cards
FILES: HomeWork3.cpp
IDE/COMPILER: Microsoft Visual Studia 2012
INSTRUCTION FOR COMPILATION AND EXECUTION:
	1. Double click on HomeworkProject.sln	to OPEN the project
	2. Press Ctrl+F7	to COMPILE
	3. Press Ctrl+Shift+B	to BUILD (COMPILE+LINK)
	4. Press Ctrl+F5	to EXECUTE

---------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

//Prints the cards when called
int displaycard()
{
	char vl = 179; //vertical line
	char hl = 196; //horizontal line
	char heart = 3; // heart symbol
	char club = 5; // club symbol
	char vb = 186; //vertical border
	char hb = 205; //horizontal border
	char neb = 187; // northeast border corner
	char seb = 188; // southeast border corner
	char swb = 200; // southwest border corner
	char nwb = 201; // northwest border corner
	char nec = 191; // northeast corner
	char swc = 192; // southwest corner
	char sec = 217; // southeast corner
	char nwc = 218; // northwest corner
	
	cout << "             " << nwb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << neb << endl;
	cout <<	"             " << vb << "  The Card Game: \"WAR\"  " << vb << endl;
	cout << "             " << swb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << hb << seb << endl;
	cout << "      Your Card                   Opponent's Card   " << endl;
	cout << nwc << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << nec << "          " << nwc << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << nec << endl;
	cout << vl<<"5                  "<<vl<<"          "<<vl<<"10                 "<<vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"         " << heart << "         "<< vl <<"          "<< vl <<"         " << club << "         "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << swc << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << sec << "          " << swc << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl << sec << endl;

	return 0;
}

int main()
{
	displaycard();
	return 0;
}


