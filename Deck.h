/*Jake Mitchell
  Nicholas Zimmerer
  CSCI 2270-Final Project
  Start Date: 4-16-15*/

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>

struct card
{
    int card;
    std::string suit;
};


class Deck
{
    public:
        Deck();
        virtual ~Deck();
        void resetDeck();
    protected:
    private:
        std::vector<card> deck;
};

#endif // DECK_H
