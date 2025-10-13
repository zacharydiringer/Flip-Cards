// deck.cpp file for the Flip Card Project
// Kyle Murrah, Rachel Barume, Zachary Diringer
// Initialization of the deck class

// Import statements
#include "deck.h"
#include <iostream>
#include "card.cpp"
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

void shuffle() {
    Card cards[52]; //Array for card deck
    Node* temp = front;
    int total = 0;

    while (temp != NULL) {
        cards[total] = temp->card;
        temp = temp->next;
        total++;
	} //End while loop

    Card shuffled[52];
    bool used[52] = { false }; //Keeps track of which cards were used
    int count = 0;

    while (count < total) {
        int index = rand() % total; //Pick random position in the card deck

        if (used[index] == false) {
            shuffled[count] = cards[index]; //Copy card
            used[index] = true;  //Mark it as used
            count++;
		} //End if statement
	} //End while loop

    temp = front;
    int i = 0;
    //Copy shuffled cards back into the list 
    while (temp != NULL) {
        temp->card = shuffled[i];
        temp = temp->next;
        i++;
	} //End while loop

    cout << "Deck has been shuffled.\n"; //End confirmation message
} // End function