/*Jake Mitchell
  Nicholas Zimmerer
  CSCI 2270-Final Project
  Start Date: 4-16-15*/

#include "Deck.h"



Deck::Deck()
{
    vector<card> deck;
}

Deck::~Deck()
{
    //dtor
}

void Deck::resetDeck()
{
    deck.clear();
    for(int i = 2; i < 15; i++)
    {
        //14 = ace, need to go up to i = 14
        card newCard;
        newCard.card = i;
        newCard.suit = "Club";
        deck.push_back(newCard);
    }
    for(int i = 2; i < 15; i++)
    {
        //14 = ace, need to go up to i = 14
        card newCard;
        newCard.card = i;
        newCard.suit = "Diamond";
        deck.push_back(newCard);
    }
    for(int i = 2; i < 15; i++)
    {
        //14 = ace, need to go up to i = 14
        card newCard;
        newCard.card = i;
        newCard.suit = "Heart";
        deck.push_back(newCard);
    }
    for(int i = 2; i < 15; i++)
    {
        //14 = ace, need to go up to i = 14
        card newCard;
        newCard.card = i;
        newCard.suit = "Spade";
        deck.push_back(newCard);
    }
}
