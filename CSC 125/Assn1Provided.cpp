#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>  // this is required in order to use vectors
using std::string;
using std::cout;
using std::cin;
using std::vector;

// This program uses command-line parameters. argc counts the parameters,
// argv[] contains the parameters.
int main(int argc, char *argv[]) 
{
  vector<int> playerA_cards;  // Vector of ints. No size specified.
  int seed;  // Seed value for random number generator
  
  // We are using command-line parameters to pass in information about how
  // this program should run. Those parameters are typed at the command line
  // (that is, DOS), and passed to this program in argv[]. 
  // argc is the count of parameters including the executable name.
  // argv[0] is the executable name, argv[1] is the next parameter as a
  // string, and so on.
  if (argc < 2) // Note: correct argc does not guarantee correct argv[] contents
  {
    printf("\nThis program requires a number parameter for seed.\n");
    printf("     Run the program by:     <executable> <integer seed>\n");
    exit(0);  // Exit program if it wasn't run with correct parameter
  }
  printf("argv[1] is %s\n", argv[1] );  // Notice: no asterisk on argv[1]
  seed = atoi(argv[1]);  // atoi converts the string of digit chars into an integer
  srand ( seed );  // Start random number generator at a known position



  // Demonstration of vector use and operation
  for (int i = 0; i < 5; i++)  // Five cards in my hand of cards
  {
    // Make a random choice of the 13 card types, scale between 2 and 14 (ace)
    int newCard = (rand() % 13) + 2;  // This is the card drawn from the deck
    playerA_cards.push_back( newCard );  // Put the new card into my hand
    printf("  Added card %d to my hand\n", playerA_cards.at( i ) );
  }
  
  // KV feels that the parameter to the STL vector erase function ought to be
  // simpler than this. But, it is what it is.
  // The STL vector erase function requires a parameter type of an iterator to
  // the element to be removed. 
  playerA_cards.erase( playerA_cards.begin() + 2 );  // Discard the card at index 2
  printf("  Now my card[2] is %d\n", playerA_cards.at( 2 ) );


  


} // end main

