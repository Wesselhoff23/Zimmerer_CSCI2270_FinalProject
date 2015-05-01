/*
  Nicholas Zimmerer
  Jake Mitchell
  Hoenigman CSCI2270
  4-24-15
*/

#include "Deck.h"
#include "War.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

War::War()
{
    string suit;
	for(int s = 0; s < 4; s++)
    {				//Assigns suits as follows
		if     (s == 0)	suit = "Spade";
		else if(s == 1)	suit = "Heart";
		else if(s == 2)	suit = "Diamond";
		else 			suit = "Club";

		for(int r = 2; r < 15; r++)
        {		//jack-11, queen-12, king-13, ace-14
			Card temp;
			temp.suit = suit;
			temp.rank = r;
			deck.push_back(temp);
		}
	}

    shuffle();

	for(int i = 0; i < deck.size(); i++)
    {
        if(i % 2)
        {
            playerQueue.push(deal());
        }
        else
        {
            compQueue.push(deal());
        }
    }
}

War::~War()
{

}

void War::playRound()
{
    if(gameOver()) //Handles the cases where the queues are empty due to a player winning
    {
        if(gameOver() == 1)
        {
            cout << "Computer has won the game!" << endl;
            cout << "Reset the game to play again, or quit to play something else." << endl;
        }
        else if(gameOver() == 2)
        {
            cout << "Player has won the game! Congrats!" << endl;
            cout << "Reset the game to play again, or quit to play something else." << endl;
        }
    }
    else
    {
        cout << "Player has " << playerCardsLeft() << " Cards left" << endl;

        cout << "Computer has " << compCardsLeft() << " Cards left" << endl;

        Card pCard, cCard;
        pCard = playerQueue.front();
        playerQueue.pop();
        cCard = compQueue.front();
        compQueue.pop();

        int cCResult = cardCompare(pCard, cCard);
        cout << "Player plays:" << endl;
        printCard(pCard);
        cout << "Computer plays:" << endl;
        printCard(cCard);

        bool winner = false;

        if(cCResult == 0)
        {
            cout << endl;
            cout << "War!" << endl;
            cout << endl;
            winner = playWar(pCard, cCard);
        }
        else
        {
            if(cCResult == 1)
            {
                winner = true;
            }
            else
            {
                winner = false;
            }
        }
        if(winner)
        {
            cout << "Player Wins!" << endl;
            playerQueue.push(pCard);
            playerQueue.push(cCard);
        }
        else
        {
            cout << "Computer Wins!" << endl;
            compQueue.push(cCard);
            compQueue.push(pCard);
        }
    }
    cout << endl;
}

int War::gameOver()
{
    if(playerQueue.empty())
    {
        return 1;
    }
    else if(compQueue.empty())
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void War::resetGame()
{
    deck.clear();
        string suit;
	for(int s = 0; s < 4; s++)
    {				//Assigns suits as follows
		if     (s == 0)	suit = "Spade";
		else if(s == 1)	suit = "Heart";
		else if(s == 2)	suit = "Diamond";
		else 			suit = "Club";

		for(int r = 2; r < 15; r++)
        {		//jack-11, queen-12, king-13, ace-14
			Card temp;
			temp.suit = suit;
			temp.rank = r;
			deck.push_back(temp);
		}
	}

    shuffle();

	for(int i = 0; i < deck.size(); i++)
    {
        if(i % 2)
        {
            playerQueue.push(deal());
        }
        else
        {
            compQueue.push(deal());
        }
    }
}

int War::cardCompare(Card pC, Card cC)
{
    if(pC.rank > cC.rank)
    {
        return 1;
    }
    else if(pC.rank < cC.rank)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int War::play()
{
    bool quit = false;
    while(!quit)
    {
        string command = menu();
        if(command == "1")
        {
            playRound();
        }
        else if(command == "2")
        {
            resetGame();
        }
        else if(command == "3")
        {
            quit = true;
        }
    }

    return 0;
}

string War::menu()
{
    cout << "=====Game Menu=====" << endl;
    cout << "1. Play a Round" << endl;
    cout << "2. Reset Game" << endl;
    cout << "3. Quit War" << endl;

	string command;
	getline(cin, command);
	cout<<endl;
	return command;
}

int War::compCardsLeft()
{
    return compQueue.size();
}

int War::playerCardsLeft()
{
    return playerQueue.size();
}

bool War::playWar(Card pCard, Card cCard)
{
    Card pCards[4], cCards[4];
    for(int i = 0; i < 4; i++) //getting the two arrays of cards
    {
        pCards[i] = playerQueue.front();
        playerQueue.pop();
        cCards[i] = compQueue.front();
        compQueue.pop();
    }

    int cCResult = cardCompare(pCards[3], cCards[3]);
    cout << "Player plays:" << endl;
    printCard(pCards[3]);
    cout << "Computer plays:" << endl;
    printCard(cCards[3]);

    bool pWinner = false;

    if(cCResult == 0)
    {
        cout << endl;
        cout << "War!" << endl;
        cout << endl;
        pWinner = playWar(pCards[3], cCards[3]);
    }
    else
    {
        if(cCResult == 1)
        {
            pWinner = true;
        }
        else
        {
            pWinner = false;
        }
    }

    if(pWinner)
    {
        cout << "Player Wins!" << endl;
        cout << "Player's 3 down cards" << endl;
        for(int i = 0; i < 3; i++)
        {
            printCard(pCards[i]);
            playerQueue.push(pCards[i]);
        }
        playerQueue.push(pCards[3]);
        cout << "Computers's 3 down cards" << endl;
        for(int i = 0; i < 3; i++)
        {
            printCard(cCards[i]);
            playerQueue.push(cCards[i]);
        }
        playerQueue.push(cCards[4]);
        playerQueue.push(pCard);
        playerQueue.push(cCard);
    }
    else
    {
        cout << "Computer Wins!" << endl;
        cout << "Player's 3 down cards" << endl;
        for(int i = 0; i < 3; i++)
        {
            printCard(pCards[i]);
            compQueue.push(pCards[i]);
        }
        compQueue.push(pCards[3]);
        cout << "Computers's 3 down cards" << endl;
        for(int i = 0; i < 3; i++)
        {
            printCard(cCards[i]);
            compQueue.push(cCards[i]);
        }
        compQueue.push(cCards[3]);
        cout << "cCards[4]" << endl;
        compQueue.push(pCard);
        cout << "pCard" << endl;
        compQueue.push(cCard);
        cout << "cCard" << endl;
    }
    cout << endl;
    return pWinner;
}
