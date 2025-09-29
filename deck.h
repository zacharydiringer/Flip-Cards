//deck.h file for the Flip Card Project
//Kyle Murrah, Rachel Barume, Zachary Diringer
//Declaration of the deck class

#pragma once
// Import statements
#include "card.cpp"
#include <iostream>
using namespace std;

class deck;

class deck
{
private:
	*card deckHead;

public:

	// Constructor for the deck class
	deck(*card);

	// Function to shuffle the deck
	void shuffle();

	// Overloaded function to print the deck
	friend ostream& operator<<(ostream& os, const deck& resp);


}; // end class deck