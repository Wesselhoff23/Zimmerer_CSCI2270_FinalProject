# Zimmerer_CSCI2270_FinalProject
Final Project for CSCI2270
*****Read Me*****
This program contains a class and a executable file to build a
deck of cards and play different games with. The deck contains
all 13 unique cards in each of the four suits. There are shuffle
and deal functions which will randomize the deck and deal out an
input amount of cards respectively.



*****How To Run*****
After executing the main program, you will see a main menu:

=== Main Menu ===
1. Print Deck
2. Reset Deck
3. Shuffle Deck
4. Deal Deck
5. Quit

1) Print Deck
Prints each card in the array, both rank and suit.
Additionally, prints the number of cards in the deck.


2) Reset Deck
Resets the deck to it's original condition. The deck is initially
sorted by suit, by order of Clubs, Diamonds, Hearts, and Spades.
Further still, the suit is organized from Ace to King.


3) Shuffle Deck
Randomizes the order of the deck. Does not add or remove any
cards.


4) Deal Deck
This will prompt the user for an integer, and prints that many
cards, while removing them from the deck.

Ex. for Deal Deck:
How many cards would you like to deal: 4
Ace of Clubs
King of Hearts
4 of Diamonds
7 of Clubs

This would leave 48 cards in the deck, assuming this is the first
call to the Deal function.


5) Quit
Quits the program.

*****Dependencies*****
This program does not use any third-party libraries. 


*****System Requirements*****
Program is not OS specific, can be run thought command prompt/terminal


*****Group Members*****
Nicholas Zimmerer
Jake Mitchell


*****Contributors*****



*****Enhancement Requests*****
-Poker function
	Rather ambitious function, but a functioning Texas Hold'em function
	which keeps track of currency, properly jugdes winning hands, and 
	can be played vs the computer would be very impressive.

-Blackjack Function
	Does not need to keep track of money/chips, although that would be 
	cool, just a one-hand-at-a-time would be fine. Would be fun to be
	able to play more than one, however, and add in card-counting
	functionality.

<<<<<<< HEAD

=======
- War Function
	A user vs. computer game of War.  Each player will have one deck of
	cards likely implemented as a queue.  Possibly 	another function
	to auto-complete the game and display the winner.
>>>>>>> a9ddd58a71bec8a7bf35e6f5e5cfe121bbc9d249

*****Bugs*****
