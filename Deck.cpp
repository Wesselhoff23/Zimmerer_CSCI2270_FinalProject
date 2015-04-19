#include "Deck.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

Deck::Deck(){								//initialize 52 card deck
	string suit;
	
	for(int s = 0; s < 4; s++){				//Assigns suits as follows
		if     (s == 0)	suit = "Club";
		else if(s == 1)	suit = "Diamond";
		else if(s == 2)	suit = "Heart";
		else 			suit = "Spade";
		
		for(int r = 2; r < 15; r++){		//jack-11, queen-12, king-13, ace-14
			Card temp;
			temp.suit = suit;
			temp.rank = r;
			deck.push_back(temp);
		}
	}
}

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
	cout<<r<<" of "<<c.suit<<endl;
}

void Deck::printDeck(){
	for(int i = 0; i < 52; i++){
		printCard(deck[i]);
	}
}

//void Deck::resetDeck();
//void Deck::shuffle();
//void Deck::deal();