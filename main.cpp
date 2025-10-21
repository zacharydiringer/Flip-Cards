// main.cpp — Flip Card Project
// Authors: Kyle Murrah, Rachel Barume, Zachary Diringer
// Description: Main file to test the Deck class and run the Flip Card game.

#include "deck.h"
#include "card.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to play the Flip Card game
void playFlip() {
    cout << "Starting Flip Card game..." << endl;

    // Create and display a new deck
    cout << "Creating a new deck..." << endl;
    deck gameDeck;

    cout << "\n--- Deck BEFORE shuffle ---" << endl;
    cout << gameDeck << endl;

    // Seed RNG and shuffle multiple times
    srand(static_cast<unsigned int>(time(0)));
    cout << "\n--- Shuffling deck ---" << endl;
    gameDeck.shuffle();
    gameDeck.shuffle();
    gameDeck.shuffle();

    // Print the top 24 cards after shuffle
    cout << "\n--- Top 24 cards AFTER shuffle ---" << endl;
    node<card>* tempCard = gameDeck.getDeckHead();
    for (int i = 0; i < 24 && tempCard != nullptr; ++i) {
        cout << tempCard->nodeValue << endl;
        tempCard = tempCard->next;
    }

    // Initialize game variables
    bool continueGame = true;
    int cardsFlipped = 0;
    double points = 0;
    double pointGain = 0;

    // Game loop
    while (continueGame && cardsFlipped < 24) {
        // Deal and display the top card
        card topCard = gameDeck.deal();
        cout << "\nFlipped card: " << topCard << endl;

        // Reset point gain for this round
        pointGain = 0;

        // Determine point change based on card value
        string value = topCard.getValue();
        if (value == "ace") {
            pointGain = 10;
        } else if (value == "king" || value == "queen" || value == "jack") {
            pointGain = 5;
        } else if (value == "10" || value == "9" || value == "8") {
            pointGain = 0;
        } else if (value == "7") {
            pointGain = -0.5 * points;
            points /= 2;
        } else if (value == "6" || value == "5" || value == "4" ||
                   value == "3" || value == "2") {
            pointGain = -1 * points;
            points = 0;
        }

        // Add bonus for hearts
        if (topCard.getSuit() == "hearts") {
            pointGain += 1;
        }

        // Update total points (except when already reset above)
        if (value != "7" && value != "6" && value != "5" &&
            value != "4" && value != "3" && value != "2") {
            points += pointGain;
        }

        // Display score update
        cout << "Points gained/lost this flip: " << pointGain
             << ", Total points: " << points << endl;

        // Ask the player if they want to continue
        cout << "Do you want to flip another card? (y/n): ";
        char playerChoice;
        cin >> playerChoice;
        if (playerChoice == 'n' || playerChoice == 'N') {
            continueGame = false;
        }

        ++cardsFlipped;
    }

    // End of game summary
    cout << "\nGame over! You flipped " << cardsFlipped
         << " cards and scored " << points << " points." << endl;
}

int main() {
    playFlip();
    return 0;
}
