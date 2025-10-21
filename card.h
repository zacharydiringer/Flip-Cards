#pragma once

//card.h file for the Flip Card Project
//Kyle Murrah, Rachel Barume, Zachary Diringer
//Declaration of the card class

class card;

// Import statements
#include <iostream>
using namespace std;

class card
{
private:
	string suit;
	string value;
public:
	// Constructor for the card class
	card(string suitInput, string valueInput);
	
	// Copy constructor
	card(const card& other);
	
	// Overloaded assignment operator
	card& operator=(const card& other);

	// Overloaded function to print the card
	friend ostream& operator<<(ostream& os, const card& resp);

	// Function to get the suit of the card
	string getSuit();

	// Function to get the value of the card
	string getValue();

	// Function to set the suit of the card
	void setSuit(string suitInput);

	// Function to set the value of the card
	void setValue(string valueInput);
}; // end class card