// deck.cpp file for the Flip Card Project
// Kyle Murrah, Rachel Barume, Zachary Diringer
// Initialization of the deck class

// Import statements
#include "deck.h"
#include "d_node.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Constructor for the deck class
deck::deck()
{
	string values[13] = { "ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king"};
	string suits[4] = { "clubs", "diamonds", "hearts", "spades" };
	
	// Initialize deckHead to nullptr (empty list)
	deckHead = nullptr;
	node<card>* tail = nullptr; // Keep track of the last node
	
	// Create all 52 cards in order: clubs, diamonds, hearts, spades
	for (int i = 0; i < 4; i++) // Loop through 4 suits
	{
		for (int j = 0; j < 13; j++) // Loop through 13 values per suit
		{
			// Create a new card with current suit and value
			card newCard(suits[i], values[j]);
			
			// Create a new node containing this card
			node<card>* newNode = new node<card>(newCard, nullptr);
			
			// Add this node to the linked list
			if (deckHead == nullptr) // First card
			{
				deckHead = newNode;
				tail = newNode;
			}
			else // Not the first card
			{
				tail->next = newNode;
				tail = newNode;
			}
		}
	}
} // end constructor

// Function to print the deck
ostream& operator<<(ostream& os, const deck& resp)
{
	os << "Deck contents:\n";
	auto* current = resp.deckHead;  // temp pointer
	while (current != nullptr)
	{
		os << current->nodeValue << endl;  // relies on overloaded << for card
		current = current->next;
	}
	return os;
} // end function

// Function to shuffle the deck
void deck::shuffle()
{
	card* cards[52]; // Array of pointers to cards
	node<card>* temp = deckHead;
	int total = 0;

	// Extract cards from linked list to array
	while (temp != nullptr) {
		cards[total] = new card(temp->nodeValue.getValue(), temp->nodeValue.getSuit());
		temp = temp->next;
		total++;
	}

	card* shuffled[52];
	bool used[52] = {false}; // Keeps track of which cards were used
	int count = 0;

	// Shuffle using random selection without replacement
	while (count < total) {
		int index = rand() % total; // Pick random position in the card deck

		if (used[index] == false) {
			shuffled[count] = cards[index]; // Copy card pointer
			used[index] = true; // Mark it as used
			count++;
		}
	}

	// Copy shuffled cards back into the list
	temp = deckHead;
	int i = 0;
	while (temp != nullptr) {
		temp->nodeValue = *shuffled[i]; // Dereference pointer to get card value
		temp = temp->next;
		i++;
	}

	// Clean up dynamically allocated memory
	for (int j = 0; j < total; j++) {
		delete cards[j];
	}

	cout << "Deck has successfully been shuffled.\n"; // End confirmation message
} // end shuffle