// deck.h file for the Flip Card Project
// Kyle Murrah, Rachel Barume, Zachary Diringer
// Header file containing the deck class declaration
// This class represents a deck of 52 playing cards implemented as a linked list

#pragma once // Prevents multiple inclusion of this header file

// Import statements for required dependencies
#include "card.h"        // Header file for card class (needed for node<card>)
#include "d_node.h"       // Template node class for linked list implementation
#include <iostream>       // For input/output operations (ostream for << operator)
using namespace std;

// Forward declaration of the deck class
class deck;

// Deck class declaration
// This class represents a complete deck of 52 playing cards
// Implemented using a linked list data structure for efficient operations
class deck
{
private:
	// Private data member: pointer to the first node in the linked list
	// Each node contains a card object, and nodes are linked together
	node<card>* deckHead; // Points to the head (first card) of the linked list

public:
	// PUBLIC MEMBER FUNCTIONS:

	// Constructor: Creates a new deck with all 52 cards in order
	// Cards are created in order: ace-king of clubs, diamonds, hearts, spades
	deck();

	// Shuffle function: Randomizes the order of all cards in the deck
	// Uses random selection algorithm to ensure truly random card order
	void shuffle();

	// Overloaded << operator: Allows printing the entire deck using cout
	// Friend function so it can access private member variables
	// Returns output stream for chaining operations
	friend ostream& operator<<(ostream& os, const deck& resp);

}; // end deck class declaration