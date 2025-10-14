#pragma once // Prevents multiple inclusion of this header file

// card.h file for the Flip Card Project
// Kyle Murrah, Rachel Barume, Zachary Diringer
// Header file containing the card class declaration
// This class represents a single playing card with suit and value

// Forward declaration of the card class
class card;

// Import statements for required dependencies
#include <iostream>       // For input/output operations (ostream for << operator)
using namespace std;

// Card class declaration
// This class represents a single playing card with a suit and value
// Suits: clubs, diamonds, hearts, spades
// Values: ace, 2-10, jack, queen, king
class card
{
private:
	// PRIVATE DATA MEMBERS:
	string suit;  // Stores the suit of the card (clubs, diamonds, hearts, spades)
	string value; // Stores the value of the card (ace, 2-10, jack, queen, king)

public:
	// PUBLIC MEMBER FUNCTIONS:

	// Constructor: Creates a new card with specified suit and value
	// Parameters: suitInput - the suit of the card
	//           : valueInput - the value of the card
	card(string suitInput, string valueInput);

	// Overloaded << operator: Allows printing a card using cout
	// Friend function so it can access private member variables
	// Returns output stream for chaining operations
	friend ostream& operator<<(ostream& os, const card& resp);

	// Getter function: Returns the suit of the card
	// Returns: string containing the suit (clubs, diamonds, hearts, or spades)
	string getSuit();

	// Getter function: Returns the value of the card
	// Returns: string containing the value (ace, 2-10, jack, queen, or king)
	string getValue();

	// Setter function: Changes the suit of the card
	// Parameters: suitInput - the new suit to assign to the card
	void setSuit(string suitInput);

	// Setter function: Changes the value of the card
	// Parameters: valueInput - the new value to assign to the card
	void setValue(string valueInput);

}; // end card class declaration