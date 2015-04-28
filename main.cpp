/*
  Nicholas Zimmerer
  Jake Mitchell
  Hoenigman CSCI2270
  4-20-15
*/
#include <iostream>
#include <sstream>
#include "Deck.h"
#include "War.h"

using namespace std;

string displayMenu(int menuNum);

int main(){
	Deck d;

	string choice = "0";
	int menu = 1;
	bool quit = false;

	do{
		choice = displayMenu(menu);

		if(menu == 1){
			if(choice=="1"){
				cout<<endl;
				d.printDeck();
				cout<<endl;
			}
			else if(choice=="2"){
				d.resetDeck();
			}
			else if(choice=="3"){
				d.shuffle();
			}
			else if(choice=="4"){
				string numStr;
				cout<<"How many cards would you like to deal: ";
				getline(cin, numStr);
				stringstream ss;
				ss << numStr;
				int num;
				ss >> num;
				if(!ss.fail())
                {
                    int cardsLeft = d.numCardsLeft();
                    if(num > cardsLeft)
                    {
                        cout << "Only " << cardsLeft << " cards left in deck." << endl;
                        cout << endl;
                        d.dealX(cardsLeft);
                        cout << endl;
                    }
                    else
                    {
                        cout << endl;
                        d.dealX(num);
                        cout << endl;
                    }
                }
                else
                {
                    cout << "Please enter an integer 1-52" << endl;
                }
			}
			else if(choice=="5"){
				menu = 2;
			}
			else if(choice == "6"){
				quit = true;
			}
			else{
				cout << "Please enter a valid input 1-6" << endl;
			}
		}

		else if(menu == 2){
			if(choice == "1"){
				//play blackjack
				cout << "Play Blackjack here" << endl;
			}
			else if(choice == "2"){
				//play war
				War warGame;
				int success = warGame.play();
			}
			else if(choice == "3"){
				menu = 1;
			}
			else if(choice == "4"){
				quit = true;
			}
			else{
				cout << "Please enter a valid input 1-4" << endl;
			}
		}
	}
	while(!quit);
	return 0;
}

string displayMenu(int menuNum){
	if(menuNum == 1){ //Main menu
		cout<<"=====Main Menu====="<<endl;
		cout<<"1. Print Deck"<<endl;
		cout<<"2. Reset Deck"<<endl;
		cout<<"3. Shuffle Deck"<<endl;
		cout<<"4. Deal Deck"<<endl;
		cout<<"5. Games"<<endl;
		cout<<"6. Quit"<<endl;
	}
	else if(menuNum == 2){
		cout << "=====Game Menu=====" << endl;
		cout << "1. Blackjack" << endl;
		cout << "2. War" << endl;
		cout << "3. Main Menu" << endl;
		cout << "4. Quit" << endl;
	}
	string command;
	getline(cin, command);
	cout<<endl;
	return command;
}
