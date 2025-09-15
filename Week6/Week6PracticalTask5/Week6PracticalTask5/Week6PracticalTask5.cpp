#include <iostream>

// Use pointers and references to manage dynamic memory for related structs.
// Define a Player struct with members :
//	 - std::string name
//	 - int score
//	 - A pointer to a Player struct named rival.
// Write a program that :
//	 - Dynamically allocates memory for two Player structs.
//	 - Prompts the user to enter details for each player(name and score).
//	 - Links the two players as rivals by setting the rival pointer of each struct.
//	 - Prints the details of both players and their rivals using the dereference operator (->).
// Deallocate all dynamic memory and print a confirmation message.
// Bonus Task :
//	Add a function to swap the scores of the two rivals using pointers.

