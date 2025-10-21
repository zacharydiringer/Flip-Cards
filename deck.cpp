// deck.cpp file for the Flip Card Project
// Kyle Murrah, Rachel Barume, Zachary Diringer
// Initialization of the deck class

#include "deck.h"
#include "d_node.h" // linked list node template class
#include <iostream>
#include <vector>    // for vector data structure
#include <cstdlib>   // for random number generation
#include <ctime>     // for seeding random number generator
using namespace std;

// Constructor for the deck class
deck::deck()
{
    string values[13] = { "ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king" };
    string suits[4] = { "clubs", "diamonds", "hearts", "spades" };
    
    deckHead = nullptr;
    node<card>* tail = nullptr;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            card newCard(suits[i], values[j]);
            node<card>* newNode = new node<card>(newCard, nullptr);
            
            if (deckHead == nullptr) {
                deckHead = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }
}

// Destructor for the deck class
deck::~deck()
{
	node<card>* current = deckHead;
	while (current != nullptr)
	{
		node<card>* next = current->next;
		delete current;
		current = next;
	}
	deckHead = nullptr;
} // end destructor

// Function to print the deck
ostream& operator<<(ostream& os, const deck& resp)
{
    os << "Deck contents:\n";
    auto* current = resp.deckHead;
    while (current != nullptr) {
        os << current->nodeValue << endl;
        current = current->next;
    }
    return os;
}

// Function to shuffle the deck

node<card>* deck::getDeckHead(){
    return deckHead;
} //end getDeckHead

void deck::shuffle()
{
    srand(time(nullptr)); // seed random generator once

    card* cards[52];
    node<card>* temp = deckHead;
    int total = 0;

    // Extract cards to array
    while (temp != nullptr) {
        cards[total] = new card(temp->nodeValue.getSuit(), temp->nodeValue.getValue());
        temp = temp->next;
        total++;
    }

    card* shuffled[52];
    bool used[52] = { false };
    int count = 0;

    while (count < total) {
        int index = rand() % total;
        if (!used[index]) {
            shuffled[count] = cards[index];
            used[index] = true;
            count++;
        }
    }

    // Copy shuffled cards back to linked list
    temp = deckHead;
    int i = 0;
    while (temp != nullptr) {
        temp->nodeValue = *shuffled[i];
        temp = temp->next;
        i++;
    }

    // Clean up memory
    for (int j = 0; j < total; j++) {
        delete cards[j];
    }

    cout << "Deck has successfully been shuffled.\n";
}

//Deal function to return top card from deck and then remove it from the deck

card deck::deal()

{
    /*
    if (deckHead == nullptr)

    {

        cout << "The deck is empty, can't complete deal.\n";

        return nullptr;

    }
    */
    node<card>* dealtCard = deckHead; //Store the top card

    deckHead = deckHead->next; //Set top card to be the next card

    dealtCard->next = nullptr; //Remove the top card from the original deck

    return dealtCard->nodeValue; //Return top card

} //end deal

//Replace function that adds a card at the back of the deck

void deck::replace(node<card>* cardNode)

{

    if (cardNode == nullptr)

    {

        return; //Do nothing if new card is null

    }

    if (deckHead == nullptr) //If deck is empty, replaced card becomes head

    {

        deckHead = cardNode;

        return;

    }

    node<card>* temp = deckHead;

    while (temp->next != nullptr) //Move to last spot in the deck

    {

        temp = temp->next;

    }

    temp->next = cardNode; //Add replace card at the end

} //end replace

