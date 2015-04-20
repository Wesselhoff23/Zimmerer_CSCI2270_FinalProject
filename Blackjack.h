#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "Deck.h"
#include <vector>
#include <iostream>

class Blackjack
{
	public:
		Blackjack();
		~Blackjack();
		void clearHands();	//clears both hands, for use after the hand is played
		void dealHands();	//deals the player and dealer 2 cards, and displays
		void play();		//function to proctor the player's turn
		void resolve();		//finishes the computer's turn and declares the winner
	private:
		std::vector<Card> playerHand;
		std::vector<Card> dealerHand;
}

#endif