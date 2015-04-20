#include <iostream>
#include "Deck.h"

using namespace std;

int main(){
	Deck d;
	
	int choice = 0;
	
	do{
		cout<<"=====Main Menu====="<<endl;
		cout<<"1. Print Deck"<<endl;
		cout<<"2. Reset Deck"<<endl;
		cout<<"3. Shuffle Deck"<<endl;
		cout<<"4. Deal Deck"<<endl;
		cout<<"5. Play War"<<endl;
		cout<<"6. Quit"<<endl;
		cin>>choice;
		cin.sync();
		
		if(choice==1){
			cout<<endl;
			d.printDeck();
			cout<<endl;
		}
		else if(choice==2){
			d.resetDeck();
		}
		else if(choice==3){
			d.shuffle();
		}
		else if(choice==4){
			int num;
			cout<<"How many cards would you like to deal: ";
			cin>>num;
			cin.sync();
			cout<<endl;
			d.deal(num);
			cout<<endl;
		}
		else if(choice==5){
			
		}
	}
	while(choice!=6);
	return 0;
}