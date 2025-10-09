// deck.cpp file for the Flip Card Project
// Kyle Murrah, Rachel Barume, Zachary Diringer
// Initialization of the deck class

// Import statements
#include "deck.h"
#include <iostream>
using namespace std;

// Constructor for the deck class
deck::deck()
{
	string values[13] = { "ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king"};
	string suits[4] = { "clubs", "diamonds", "hearts", "spades" };

} // end constructor

// Function to print the deck
ostream& operator<<(ostream& os, const deck& resp)
{
	os << "Deck contents:\n";
	auto* current = resp.deckHead;  // temp pointer
	while (current != nullptr)
	{
		os << *current << endl;  // relies on overloaded << for card
		current = current->next;
	}
	return os;
} // end function