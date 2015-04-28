/*
  Nicholas Zimmerer
  Jake Mitchell
  Hoenigman CSCI2270
  4-24-15
*/

#ifndef WAR_H
#define WAR_H
#include <iostream>
#include <vector>
#include "Deck.h"
#include <queue>

class War : public Deck
{
    public:
        War();
        ~War();
        void playRound();
        int gameOver();
        void resetGame();
        int cardCompare(Card pC, Card cC);
        int play();
        std::string menu();
        int playerCardsLeft();
        int compCardsLeft();
        bool playWar(Card pCard, Card cCard);
    private:
        std::queue<Card> playerQueue;
        std::queue<Card> compQueue;
};



#endif
