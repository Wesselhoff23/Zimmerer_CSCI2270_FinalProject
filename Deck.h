#include <iostream>
#include <vector>
#ifndef DECK_H
#define DECK_H


struct Card{
	std::string suit;	//Club first, Diamond second, Heart third, Spade last -- ORDER MATTERS
	int rank;
	
	Card(){}
	
	Card(std::string s, int r){
		suit = s;
		rank = r;
	}
};

class Deck
{
	public:
		Deck();
		~Deck();
		void printCard(Card);
		void printDeck();
		void resetDeck();
		void shuffle();
		void deal();
	private:
		std::vector<Card> deck;
};

#endif