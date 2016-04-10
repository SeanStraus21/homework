//Wargame
/*===================================================================================
PROGRAMMER:			Sean Straus, Straus21: finished it
COURSE:				CSC 232
LAST MODIFIED DATE:	01/09/2014
DESCRIPTION:		This program plays a game of war

FILES:					Assn1.cpp
IDE/COMPILER:			Codeblocks/MinGw

NOTES: 
===================================================================================*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

/*
4 vectors
draw function
card class
*/
int main(int argc, char* argv[])
	{
	if (argc < 2) // Note: correct argc does not guarantee correct argv[] contents
		{
		printf("\nThis program requires a number parameter for seed.\n");
		printf("	 Run the program by:	 <executable> <integer seed>\n");
		exit(0);  // Exit program if it wasn't run with correct parameter
		}
	printf("argv[1] is %s\n", argv[1] );	// Notice: no asterisk on argv[1]
	seed = atoi(argv[1]);	 // atoi converts the string of digit chars into an integer
	srand ( seed );  // Start random number generator at a known position
	for (int i = 0; i < 5; i++)  // Five cards in my hand of cards
		{
		// Make a random choice of the 13 card types, scale between 2 and 14 (ace)
		int newCard = (rand() % 13) + 2;  // This is the card drawn from the deck
		playerA_cards.push_back( newCard );	 // Put the new card into my hand
		printf("  Added card %d to my hand\n", playerA_cards.at( i ) );
		}
	//initialize stacks
	vector<int> deck_a;
	vector<int> deck_b;
	vector<int> played_a;
	vector<int> played_b;
	
	//fill decks
	int card;
	for (int i=0; i<26; i++)
		{
		card = (rand()%13)+2; // generate random card
		deck_a.push_back(card); // push back card for player A
		card = (rand()%13)+2; // generate random card
		deck_b.push_back(card); // push back card for player B
		}
		
	bool endgame = false;
	string winner = "Nobody";
	while (endgame == false) //while neither player is out of cards
		{
		if deck_a.size() > 0 && deck_b.size() > 0 //if both players have a card, play a round
			{
			played_a.push_back(deck_a.front())); //check top card of deck_a and put it on played stack A
			deck_a.erase(deck_a.front());//remove top card of deck_a 
			played_a.push_back(deck_b.front())); //check top card of deck_b and put it on played stack B
			deck_a.erase(deck_b.front());//remove top card of deck_b 
			if played_a.back() != played_b.back()//compare 
				{
				if played_a.back() > played_b.back() // player A wins
					{
					while(played_a.size() > 0)
						{
						deck_a.push_back(played_a.back());
						played_a.pop_back();
						}
					while(played_b.size() > 0)
						{
						deck_a.push_back(played_b.back());
						played_b.pop_back();
						}
					}
				else //								// player B wins
					{
					while(played_b.size() > 0)
						{
						deck_b.push_back(played_b.back());
						played_b.pop_back();
						}
					while(played_a.size() > 0)
						{
						deck_b.push_back(played_a.back());
						played_a.pop_back();
						}
					}
				}
			}
		else
			{
			//check conditions for winner
			if (deck_a.size() > 0) xor (deck_b.size() > 0) //if game is not a tie
				{
				if deck_a.size > 0
					{
					winner = "Player A"
					}
				else
					{
					winner = "Player B"
					}
				}
			endgame = true;
			}
		}
	cout << winner << " Wins!" << endl;
	}



