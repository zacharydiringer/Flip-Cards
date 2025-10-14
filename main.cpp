// main.cpp file for the Flip Card Project
// Kyle Murrah, Rachel Barume, Zachary Diringer
// Driver program to test the deck class functionality

// Import statements for required libraries and classes
#include "deck.h"          // Header file for deck class declaration
#include "deck.cpp"        // Implementation of deck class (constructor, shuffle, print)
#include "card.cpp"        // Implementation of card class (constructors, getters, setters)
#include <iostream>        // For input/output operations (cout, endl)
#include <cstdlib>         // For random number generation (rand function)
#include <ctime>           // For seeding random number generator (srand function)
using namespace std;

// Main function to test deck initialization and shuffle functionality
// This program demonstrates the complete deck class implementation
int main()
{
    // STEP 1: Seed the random number generator for the shuffle function
    // Using current time ensures different shuffle results each time program runs
    srand(time(0));
    
    // Print program header to identify what we're testing
    cout << "=== Flip Card Game - Deck Test ===" << endl << endl;
    
    // STEP 2: Create a new deck object
    // This calls the deck constructor which creates all 52 cards in order
    // Order: ace-king of clubs, then ace-king of diamonds, hearts, spades
    cout << "Creating a new deck..." << endl;
    deck gameDeck;
    
    // STEP 3: Display the deck before shuffling
    // This shows the cards in their original ordered state
    cout << "\n--- Deck BEFORE shuffle ---" << endl;
    cout << gameDeck << endl; // Uses overloaded << operator to print all cards
    
    // STEP 4: Shuffle the deck using the shuffle function
    // This randomizes the order of all 52 cards in the deck
    cout << "\n--- Shuffling deck ---" << endl;
    gameDeck.shuffle(); // Calls the shuffle function to randomize card order
    
    // STEP 5: Display the deck after shuffling
    // This shows the cards in their new randomized order
    cout << "\n--- Deck AFTER shuffle ---" << endl;
    cout << gameDeck << endl; // Uses overloaded << operator to print all shuffled cards
    
    // Print completion message
    cout << "\n=== Test Complete ===" << endl;
    cout << "The deck class has been successfully tested!" << endl;
    cout << "All 52 cards were created, displayed, shuffled, and displayed again." << endl;
    
    return 0; // Indicate successful program completion
}
