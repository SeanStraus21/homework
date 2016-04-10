/*
----------------------------------------------------------------------------------
COURSE:			CSC 125 001, Homework 8
LAST MODIFIED:	3/27/2014
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
unsigned short displaycard()
{
	unsigned short output = 0;

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
	string rank[] = {"1","2","3","4","5","6","7","8","9","10","J","Q","K","A"}; //list of possible values for rank

	srand(time(NULL)); // initialize random numbers using current time as seed
	int rand1 = rand()%14; // declare first random number
	int rand2 = (rand()+1)%14; // declare second random number
	int rand3 = (rand()%4); // declare third random number
	int rand4 = (rand()%4); // declare fourth random number

	string rank1 = rank[rand1]; //rank for card 1
	string rank2 = rank[rand2]; //rank for card 2
	char suit1= suit[rand3]; //suit for card 1
	char suit2= suit[rand4]; //suit for card 2

	// Ensure that the two cards are not identical !!!!!!!!!!!!!THIS PART IS COMMENTED!!!!!!!!!!!!!
	if (rank1 == rank2 && suit1 == suit2)
	{
		suit1 = suit[(rand3+1)%4];
	}

	
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
	cout << vl <<"         " << suit1 << "         "<< vl <<"          "<< vl <<"         " << suit2 << "         "<< vl << endl;
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

	cout << endl << endl;
	if (rand1 < rand2)
		{output = 0;}
	else
		{if (rand1 > rand2)
			{output = 2;}
		else
			{output = 1;}}

	return output;

}
/*
//Runs in case of a tie
unsigned short war()
	{
	unsigned short outcome;
	
	displaycard();
	displaycard();
	displaycard();
	
	outcome = displaycard();
	
	return outcome;
	}
*/
int main()
{
	string quit = "";
	unsigned short outcome;

	while (quit != "q")
		{	
		outcome = displaycard();
		if (outcome == 0)
			{
			cout << "Sorry.  You lost this battle!" << endl;
			}
		else
			{
			if (outcome == 2)
				{
				cout << "Congratulations.  You win this battle!" << endl;
				}
			else 
				{
				cout << "This is a tie game." << endl;
				}
			}
		cout << "type a string to deal again or q to quit" <<endl;
		cin >> quit;
		displaycard();
		}
	return 0;
}


