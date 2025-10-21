// card.cpp file for the Flip Card Project
// Kyle Murrah, Rachel Barume, Zachary Diringer
// Initialization of the card class

// Import statements
#include "card.h"
#include <iostream>
using namespace std;

// Constructor for the card class
card::card(string suitInput, string valueInput)
{
	suit = suitInput;
	value = valueInput;
} // end constructor

// the copy constructor
card::card(const card& other)
{
	suit = other.suit;
	value = other.value;
} // end of the copy constructor

// Overloaded assignment operator
card& card::operator=(const card& other)
{
	if (this != &other) // Check for assignments to itself
	{
		suit = other.suit;
		value = other.value;
	}
	return *this;
} // end of the assignment operator

// Overloaded function to print the card
ostream& operator<<(ostream& os, const card& resp)
{
	os << resp.value << " of " << resp.suit;
	return os;
} // end overloaded function

// Function to get the suit of the card
string card::getSuit()
{
	return suit;
} // end getSuit

// Function to get the value of the card
string card::getValue()
{
	return value;
} // end getValue

// Function to set the suit of the card
void card::setSuit(string suitInput)
{
	suit = suitInput;
} // end setSuit

// Function to set the value of the card
void card::setValue(string valueInput)
{
	value = valueInput;
} // end setValue
