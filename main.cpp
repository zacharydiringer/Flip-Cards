//main.cpp file for the Flip Card Project
//Kyle Murrah, Rachel Barume, Zachary Diringer
//Main file to test the deck class

// Import statements
#include "deck.h"
#include "deck.cpp"
#include "card.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to play the Flip Card game
void playFlip() {
    // Game logic would go here
	cout << "Starting Flip Card game..." << endl;
    // Create a new deck (constructor will create 52 cards in order)
    cout << "Creating a new deck..." << endl;
    deck gameDeck;
    // Print the deck before shuffle
    cout << "\n--- Deck BEFORE shuffle ---" << endl;
    cout << gameDeck << endl;

    // Seed the random number generator for shuffle
    srand(time(0));
    // Shuffle the deck
    cout << "\n--- Shuffling deck ---" << endl;
    gameDeck.shuffle();
    gameDeck.shuffle();
	gameDeck.shuffle();

    // Print the deck after shuffle
    cout << "\n--- Deck AFTER shuffle ---" << endl;
    cout << gameDeck << endl;


	// Variable to continue or end the game
	bool continueGame = true;
    
	// Keep track of the number of cards flipped
	int cardsFlipped = 0;
    
	// Keep track of the player's score
    double points = 0;
    double pointGain = 0
    // Game loop
    while (continueGame == true and cardsFlipped <= 24) {
		// Flip the top card of the deck and display it
        card topCard = gameDeck.deal();
		cout << "Flipped card: " << topCard << endl;

		// Determine points based on the card value
        if (topCard.value == "ace") {
            points += 10;
			pointGain = 10;
		} // end if

        else if (topCard.value == "king" or topCard.value == "queen" or topCard.value == "jack") {
			points += 5;
            pointGain = 5;
		} // end else if

		else if (topCard.value == "10" or topCard.value == "9" or topCard.value == "8") {
            pointGain = 0;
		} // end else if

        else if (topCard.value == "7"){
            pointGain = -0.5 * points;
			points = points / 2;
		} // end else if

        else if (topCard.value == "6" or topCard.value == "5" or topCard.value == "4"
            or topCard.value == "3" or topCard.value == "2") {
            pointGain = -1 * points;
            points = 0;
        } // end else if

        if (topCard.suit == "hearts") {
            points += 1;
            pointGain += 1;
        }

		// Display points gained or lost
		cout << "Points gained/lost this flip: " << pointGain << ", Total points: " << points << endl;

		// Ask the player if they want to continue
		cout << "Do you want to flip another card? (y/n): ";
		char playerChoice;
		cin >> playerChoice;
        if (playerChoice == 'n' or playerChoice == 'N') {
            continueGame = false;
		} // end if

		// Increment the number of cards flipped
		cardsFlipped++;
	} // end while
	
    // Print results
	cout << "\nGame over! You flipped " << cardsFlipped << " cards and scored " << points << " points." << endl;

} // end playFlip

// Main function to test deck initialization and shuffle
int main()
{
	playFlip();
    return 0;
}
