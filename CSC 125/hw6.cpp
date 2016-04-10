/*
----------------------------------------------------------------------------------
COURSE:			CSC 125 001, Homework 6
LAST MODIFIED:	2/28/2014
PROGRAMMER:		Sean Straus, Straus21

Description: This program displays two stunningly rendered playing cards
FILES: HomeWork6.cpp
IDE/COMPILER: Microsoft Visual Studia 2012
INSTRUCTION FOR COMPILATION AND EXECUTION:
	1. Double click on HomeworkProject.sln	to OPEN the project
	2. Press Ctrl+F7	to COMPILE
	3. Press Ctrl+Shift+B	to BUILD (COMPILE+LINK)
	4. Press Ctrl+F5	to EXECUTE
Notes: The pseudorandom number generator leaves a lot to be desired.

---------------------------------------------------------------------------------
*/

#include <iostream>
#include <math.h>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

//Prints the cards when called
void displaycard()
{
	char vl = 179; //vertical line
	char hl = 196; //horizontal line
	char heart = 3; // heart symbol
	char diamond = 4; // diamond symbol
	char club = 5; // club symbol
	char spade = 6; // spade symbol
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
	char suit[] = {heart,diamond,club,spade}; //list of possible values for suit
	string rank[] = {"1","2","3","4","5","6","7","8","9","10","Jack","Queen","King","A"}; //list of possible values for rank
	srand(time(NULL)); // initialize random numbers using current time as seed
	int rand1 = rand()%14; // declare first random number
	int rand2 = (rand()+1)%14; // declare second random number
	string rank1 = rank[rand1]; //rank for card 1
	string rank2 = rank[rand2]; //rank for card 2
	
	cout << "             " << nwb << setfill(hb) << setw(25) << neb << endl;
	cout <<	"             " << vb << "  The Card Game: \"WAR\"  " << vb << endl;
	cout << "             " << swb << setfill(hb) << setw(25) << seb << endl;
	cout << "      Your Card                   Opponent's Card   " << endl;
	//top border
	cout << nwc << setfill(hl) << setw(20) << nec << "          ";
	cout << nwc << setfill(hl) << setw(20) << nec << endl;
	//top rank line
	cout << vl << left << setfill(' ') << setw(19) << rank1;
	cout << right << vl << "          "<< vl;
	cout << left << setfill(' ') << setw(19) << rank2<< right << vl << endl;
	//card body
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"         " << suit[rand()%4] << "         "<< vl <<"          "<< vl <<"         " << suit[(rand()+1)%4] << "         "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	cout << vl <<"                   "<< vl <<"          "<< vl <<"                   "<< vl << endl;
	//bottom rank line
	cout << vl << setfill(' ') << setw(19) << rank1 << vl <<"          "<< vl;
	cout << setfill(' ') << setw(19) << rank2 << vl << endl;
	//bottom border
	cout << swc << setfill(hl) << setw(20) << sec << "          ";
	cout << swc << setfill(hl) << setw(20) << sec << endl;

}

int main()
{
	string quit = "";

	while (quit != "q")
		{	
		displaycard();
		cout << "type a string to deal again or q to quit" <<endl;
		cin >> quit;
		displaycard();
		}
	return 0;
}


