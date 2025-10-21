//deck.h file for the Flip Card Project
//Kyle Murrah, Rachel Barume, Zachary Diringer
//Declaration of the deck class

#pragma once
// Import statements
#include "card.h"
#include "d_node.h"
#include <iostream>
using namespace std;

class deck;

class deck
{
private:
	node<card>* deckHead;

public:

	// Constructor for the deck class
	deck();

	// Function to shuffle the deck
	void shuffle();

	// Function to deal card
	card deal();

	// Function to replace card
	void replace(node<card>* cardNode);

	// Overloaded function to print the deck
	friend ostream& operator<<(ostream& os, const deck& resp);

	// Function to get the head of the deck
	node<card>* getDeckHead();

}; // end class deck