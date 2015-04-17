/*Jake Mitchell
  Nicholas Zimmerer
  CSCI 2270-Final Project
  Start Date: 4-16-15*/
/*
  It errors saying undefined reference to Deck, very confused
*/

#include <vector>
#include <iostream>
#include "Deck.h"
using namespace std;

string displayMenu();

int main()
{
    string command = "";

    //initialize the main deck
    Deck mainDeck;
    mainDeck.resetDeck();

    while(command != "5")
    {
        if(command == "1")
        {
            mainDeck.resetDeck();
        }

        command = displayMenu();
    }

    cout << "Goodbye!" << endl;
    return 0;
}

string displayMenu()
{
    string input;
    cout << "=== Main Menu ===" << endl;
    cout << "1. Reset Deck" << endl;
    cout << "2. Print Deck" << endl;
    cout << "3. Shuffle Deck" << endl;
    cout << "4. Deal Deck" << endl;
    cout << "5. Quit" << endl;
    getline(cin, input);
    return input;
}
