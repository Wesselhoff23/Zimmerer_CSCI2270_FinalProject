#include "Deck.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/*
    Function prototype:
        N/A
    Function description:
        This is just the constructor for a basic deck.
        It simply initializes a full 52 card deck ordered by
        card and suit.
    Example:
        Deck d;
    Precondition:
        None, it is the precondition for everything else.
*/

Deck::Deck(){								//initialize 52 card deck
	string suit;
	for(int s = 0; s < 4; s++){				//Assigns suits as follows
		if     (s == 0)	suit = "Spade";
		else if(s == 1)	suit = "Heart";
		else if(s == 2)	suit = "Diamond";
		else 			suit = "Club";

		for(int r = 2; r < 15; r++){		//jack-11, queen-12, king-13, ace-14
			Card temp;
			temp.suit = suit;
			temp.rank = r;
			deck.push_back(temp);
		}
	}
}

Deck::~Deck(){

}

/*
    Function Prototype:
        void Deck::printCard(Card c)
    Function Description:
        This function takes a card as a parameter and outputs
        to the terminal a formatted statement of the card.
        ex. 10 of diamonds, ace of Spades
    Example:
        Card aceOS;
        aceOS.rank = 14;
        aceOS.suit = "Spade";
        printCard(aceOS);
    Precondition:
        A Deck must have been declared to call the function
        a Card must also have been made to pass to the function.
*/
void Deck::printCard(Card c){
	string r;
	if(c.rank < 11){
		stringstream s;
		s<<c.rank;
		r = s.str();
	}
	else if(c.rank == 11)	r="Jack";
	else if(c.rank == 12)	r="Queen";
	else if(c.rank == 13)	r="King";
	else 					r="Ace";
	cout<<r<<" of "<<c.suit<<"s"<<endl;
}

/*
    Function prototype:
        void Deck::printDeck()
    Function description:
        A function that loops through the deck and calls
        printCard() on each card, printing out the whole
        deck in order.
    Example:
        Deck d;
        d.printDeck();
    Precondition:
        That a deck has been declared.
*/
void Deck::printDeck(){
	for(int i = 0; i < deck.size(); i++){
		printCard(deck[i]);
	}
}

/*
    Function prototype:
        void Deck::resetDeck()
    Function description:
        This function does the same thing as the constructor,
        it clears the current deck and reinitializes it to
        a full deck ordered by rank and suit
    Example:
        Deck d;
        d.drawX(5);
        d.resetDeck();
    Precondition:
        A Deck has been initialized.
*/
void Deck::resetDeck(){
	deck.clear();
	string suit;
	for(int s = 0; s < 4; s++){				//Assigns suits as follows
		if     (s == 0)	suit = "Spade";
		else if(s == 1)	suit = "Heart";
		else if(s == 2)	suit = "Diamond";
		else 			suit = "Club";

		for(int r = 2; r < 15; r++){		//jack-11, queen-12, king-13, ace-14
			Card temp;
			temp.suit = suit;
			temp.rank = r;
			deck.push_back(temp);
		}
	}
}

/*
    Function prototype:
        void Deck::shuffle()
    Function description:
        This function doesn't really count as a made function.
        It shuffles the vector of the deck, just as a perfect
        shuffle would do to a real deck of cards.
    Example:
        Deck d;
        d.shuffle();
    Precondition:
        A deck has been initialized.
*/
void Deck::shuffle(){
	random_shuffle(deck.begin(), deck.end());
}

//A secondary function to deal(), this one allows for multiple
//cards to be dealt and printed without using them for
//anything
void Deck::dealX(int num){
	if(deck.size()<num)
		cout<<"There are only "<<deck.size()<<" cards in the deck."<<endl;
	else{
		Card temp;
		while(num > 0){
			temp = deal();
			printCard(temp);
			num--;
		}
	}
}

Card Deck::deal(){
    Card temp;
    temp = deck.back();
    deck.pop_back();
    return temp;
}
