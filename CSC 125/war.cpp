/*===================================================================================
 PROGRAMMERS:			Yang Wang: designed and implemented function main( )
						Sean Straus, Straus21: finished it
 COURSE:				CSC 125
 MODIFIED BY:			Sean Straus
 LAST MODIFIED DATE:	4/29/2014
 DESCRIPTION:			This program is to simulate multiple battles of the card 
							game: WAR.

 FILES:					war.cpp, (HomeworkProject.sln, ...)
 IDE/COMPILER:			MicroSoft Visual Studio 2012
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.	Double click on HomeworkProject.sln			to OPEN the project
	2.	Press Ctrl+F7					to COMPILE
	3.	Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
	4.	Press Ctrl+F5					to EXECUTE

NOTES: drawCards() passes its return values by reference. I know you said to send them 
	back to the caller, but this is definitely the best way to get all the variables 
	where they're supposed to go. Return statements are just a lot worse in this situation,
	because it means parsing an array and doing a lot of type casts, and its not as if the 
	function were being assigned to anything.
===================================================================================*/
#include <iostream>
#include <math.h>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;


void preparation()
	{
	srand(time(NULL)); // initialize random numbers using current time as seed
	}

void drawCards(unsigned short &yourFaceValue,char &yourSuit,unsigned short &opponentFaceValue,char &opponentSuit)
	{
	int rand1 = rand()%14; // declare first random number
	int rand2 = (rand()+1)%14; // declare second random number
	int rand3 = (rand()%4); // declare third random number
	int rand4 = (rand()%4); // declare fourth random number
	char suit[] = {3,4,5,6}; //list of possible values for suit

	yourFaceValue = rand1; //rank for card 1
	opponentFaceValue = rand2; //rank for card 2
	yourSuit = suit[rand3]; //suit for card 1
	opponentSuit = suit[rand4]; //suit for card 2
	}

void displayCards(unsigned short yourFaceValue,char yourSuit,unsigned short opponentFaceValue,char opponentSuit)
	{
	char vl = 179; //vertical line
	char hl = 196; //horizontal line
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
	string rank[] = {"1","2","3","4","5","6","7","8","9","10","J","Q","K","A"}; //list of possible values for rank

	string rank1 = rank[yourFaceValue]; //rank for card 1
	string rank2 = rank[opponentFaceValue]; //rank for card 2
	char suit1= yourSuit; //suit for card 1
	char suit2= opponentSuit; //suit for card 2

	// Ensure that the two cards are not identical !!!!!!!!!!!!!THIS PART IS COMMENTED!!!!!!!!!!!!!
	while (rank1 == rank2 && suit1 == suit2)
	{
		suit1 = (rand()%4 + 3);
	}

	system("CLS");
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

	cout << endl;
	}

void gameResult(unsigned short yourval,unsigned short oppval)
	{
	if (yourval > oppval)
		{
		cout << "You Won" << endl;
		}
	if (yourval < oppval)
		{
		cout << "You Lost" << endl;
		}
	if (yourval == oppval)
		{
		cout << "Tie Game" << endl;
		}
	}

bool continueBattle()
	{
	bool output = 0;
	string reply;
	cout << "Do you want to play again? (type y or n)" << endl;
	cin >> reply;
	if (reply == "y" || reply == "Y")
		{
		output = 1;
		}
	return output;
	}

int main( )
{unsigned short yourFaceValue, opponentFaceValue; 
 char			yourSuit, opponentSuit;
 
 preparation(); 
 do
 {drawCards(yourFaceValue, yourSuit, opponentFaceValue, opponentSuit);
  displayCards(yourFaceValue, yourSuit, opponentFaceValue, opponentSuit);
  gameResult(yourFaceValue, opponentFaceValue);
 } while (continueBattle());

 cout<<"\n\n\t********** Game is over! **********\n\n";
 return 0;
}
