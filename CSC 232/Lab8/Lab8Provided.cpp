/*===================================================================================
 PROGRAMMER:			Sean Straus, Straus21
 COURSE:				CSC 232
 MODIFIED BY:			Sean Straus
 LAST MODIFIED DATE:	10/21/2014
 DESCRIPTION:			Thesaurus Stuff
===================================================================================*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>  // this is required in order to use vectors
#include <time.h>  // need this to use in srand (time(NULL))
using std::string;
using std::cout;
using std::cin;
using std::vector;

using namespace std;

class WordInThesaurus
{
  public:
    WordInThesaurus(string w) {word = w;}

    void add_synonym(string s)
    {
	synonyms.push_back(s);
    } // end add_synonym

    string getWord()
        {
        return word;
        }

    int getNumberOfSynonyms()
        {
        return synonyms.size();
        }

    string getSynonym(int i)
        {
        return synonyms.at(i);
        }

    string getRandomSynonym()
        {
        if (synonyms.size() > 0)
            {
            return synonyms.at((rand()%synonyms.size()));
            }
        }

  private:
        string word;
        vector<string> synonyms;

};




// This program uses command-line parameters. argc counts the parameters,
// argv[] contains the parameters.
int main(int argc, char *argv[])
{
  vector<WordInThesaurus> thesaurus;  // Vector of word objects. No size specified.
  WordInThesaurus *temp;

  srand (time(NULL));      // initialize random seed


  // Initialize a word and synonyms for it.
  temp = new WordInThesaurus("assisted");
  temp->add_synonym("accommodated");
  temp->add_synonym("collaborated");
  temp->add_synonym("facilitated");
  temp->add_synonym("served");
  temp->add_synonym("supported");
  thesaurus.push_back(*temp);

  // initialize a word and synonyms for it.
  temp = new WordInThesaurus("demonstrated");
  temp->add_synonym("achieved");
  temp->add_synonym("determined");
  temp->add_synonym("established");
  temp->add_synonym("exhibited");
  temp->add_synonym("indicated");
  thesaurus.push_back(*temp);


  temp = new WordInThesaurus("developed");
  temp->add_synonym("created");
  temp->add_synonym("coordinated");
  temp->add_synonym("designed");
  temp->add_synonym("established");
  temp->add_synonym("formed");
  temp->add_synonym("generated");
  thesaurus.push_back(*temp);

  temp = new WordInThesaurus("handled");
  temp->add_synonym("conducted");
  temp->add_synonym("coordinated");
  temp->add_synonym("directed");
  temp->add_synonym("managed");
  temp->add_synonym("monitored");
  temp->add_synonym("organized");
  temp->add_synonym("supervised");
  thesaurus.push_back(*temp);


  temp = new WordInThesaurus("led");
  temp->add_synonym("arranged");
  temp->add_synonym("controlled");
  temp->add_synonym("engineered");
  temp->add_synonym("directed");
  temp->add_synonym("managed");
  temp->add_synonym("supervised");
  thesaurus.push_back(*temp);


  temp = new WordInThesaurus("made");
  temp->add_synonym("assembled");
  temp->add_synonym("composed");
  temp->add_synonym("constructed");
  temp->add_synonym("created");
  temp->add_synonym("designed");
  temp->add_synonym("generated");
  temp->add_synonym("planned");
  temp->add_synonym("prepared");
  temp->add_synonym("produced");
  thesaurus.push_back(*temp);


  temp = new WordInThesaurus("observed");
  temp->add_synonym("distinguished");
  temp->add_synonym("examined");
  temp->add_synonym("inspected");
  temp->add_synonym("monitored");
  thesaurus.push_back(*temp);


  temp = new WordInThesaurus("participated");
  temp->add_synonym("contributed");
  temp->add_synonym("cooperated");
  temp->add_synonym("engaged");
  temp->add_synonym("joined");
  temp->add_synonym("performed");
  thesaurus.push_back(*temp);


  temp = new WordInThesaurus("performed");
  temp->add_synonym("accomplished");
  temp->add_synonym("achieved");
  temp->add_synonym("completed");
  temp->add_synonym("implemented");
  temp->add_synonym("delivered");
  thesaurus.push_back(*temp);


  temp = new WordInThesaurus("planned");
  temp->add_synonym("arranged");
  temp->add_synonym("coordinated");
  temp->add_synonym("designed");
  temp->add_synonym("developed");
  temp->add_synonym("created");
  temp->add_synonym("organized");
  temp->add_synonym("prepared");
  temp->add_synonym("produced");
  thesaurus.push_back(*temp);


  temp = new WordInThesaurus("practiced");
  temp->add_synonym("administered");
  temp->add_synonym("engaged");
  temp->add_synonym("executed");
  temp->add_synonym("exercised");
  temp->add_synonym("implemented");
  temp->add_synonym("utilized");
  thesaurus.push_back(*temp);


  temp = new WordInThesaurus("provided");
  temp->add_synonym("accommodated");
  temp->add_synonym("contributed");
  temp->add_synonym("dispensed");
  temp->add_synonym("granted");
  temp->add_synonym("implemented");
  temp->add_synonym("prepared");
  temp->add_synonym("presented");
  temp->add_synonym("produced");
  temp->add_synonym("supplied");
  thesaurus.push_back(*temp);


  temp = new WordInThesaurus("ran");
  temp->add_synonym("administered");
  temp->add_synonym("conducted");
  temp->add_synonym("controlled");
  temp->add_synonym("coordinated");
  temp->add_synonym("directed");
  temp->add_synonym("operated");
  temp->add_synonym("supervised");
  temp->add_synonym("handled");
  temp->add_synonym("performed");
  thesaurus.push_back(*temp);


  temp = new WordInThesaurus("researched");
  temp->add_synonym("analyzed");
  temp->add_synonym("experimented");
  temp->add_synonym("explored");
  temp->add_synonym("discovered");
  temp->add_synonym("identified");
  temp->add_synonym("investigated");
  temp->add_synonym("studied");
  thesaurus.push_back(*temp);


  temp = new WordInThesaurus("sold");
  temp->add_synonym("persuaded");
  temp->add_synonym("advertised");
  temp->add_synonym("marketed");
  temp->add_synonym("promoted");
  temp->add_synonym("publicized");
  thesaurus.push_back(*temp);


  temp = new WordInThesaurus("worked");
  temp->add_synonym("managed");
  temp->add_synonym("collaborated");
  temp->add_synonym("conducted");
  temp->add_synonym("developed");
  temp->add_synonym("formed");
  temp->add_synonym("formulated");
  temp->add_synonym("operated");
  temp->add_synonym("performed");
  temp->add_synonym("utilized");
  thesaurus.push_back(*temp);


  temp = new WordInThesaurus("wrote");
  temp->add_synonym("authored");
  temp->add_synonym("created");
  temp->add_synonym("established");
  thesaurus.push_back(*temp);


  // Initialize paragraph of sentences for which synonyms will be found.
  vector<vector<string> > paragraph;
  vector<string> sentenceA = {"I", "ran", "a", "marathon", "and", "led", "several", "miles", "but", "the", "provided", "shoes", "gave", "me", "blisters." };
  vector<string> sentenceB = {"My", "team", "participated", "in", "every", "review", "and", "developed", "an", "excellently", "planned", "product." };
  vector<string> sentenceC = {"Our", "led", "zeppelin", "tribute", "polka", "band", "named", "demonstrated", "commitment", "performed", "to", "sold", "out", "crowds." };
  paragraph.push_back(sentenceA);
  paragraph.push_back(sentenceB);
  paragraph.push_back(sentenceC);




  // Show the paragraph of provided words.

for(auto i : paragraph)
{
    for(auto j : i)
    {
    cout << j << " ";
    }
    cout << endl;
}

  // Show the contents of thesaurus
for(auto i : thesaurus)
    {
    cout << "The word " << i.getWord() << " has " << i.getNumberOfSynonyms()<< " synonyms: ";
    for(int j=0;j<i.getNumberOfSynonyms();j++)
        {
        if ((i.getNumberOfSynonyms()>1)&&(j == (i.getNumberOfSynonyms()-1)))
            {
            cout << "and " << i.getSynonym(j) << ".";
            }
        else
            {
            cout<< i.getSynonym(j) << ", ";
            }
        }
    cout << endl;
    cout << endl;
    }

  // Where possible, replace words in the paragraph with a word from the thesaurus

    for(auto i : paragraph)
        {
        for(auto j : i)
            {
            for (auto k : thesaurus)
                {
                if (j == k.getWord())
                    {
                    j = k.getRandomSynonym();
                    }
                }
            cout << j << " ";
            }
        cout << endl;
        }





} // end main

