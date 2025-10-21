//main.cpp file for the Flip Card Project
//Kyle Murrah, Rachel Barume, Zachary Diringer
//Main file to test the deck class

// Import statements
#include "deck.h"
#include "card.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Main function to test deck initialization and shuffle
int main()
{
    // Seed the random number generator for shuffle
    srand(time(0));
    
    cout << "=== Flip Card Game - Deck Test ===" << endl << endl;
    
    // Create a new deck (constructor will create 52 cards in order)
    cout << "Creating a new deck..." << endl;
    deck gameDeck;
    
    // Print the deck before shuffle
    cout << "\n--- Deck BEFORE shuffle ---" << endl;
    cout << gameDeck << endl;
    
    // Shuffle the deck
    cout << "\n--- Shuffling deck ---" << endl;
    gameDeck.shuffle();
    
    // Print the deck after shuffle
    cout << "\n--- Deck AFTER shuffle ---" << endl;
    cout << gameDeck << endl;
    
    cout << "\n=== Test Complete ===" << endl;
    
    return 0;
}
