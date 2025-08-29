#include <iostream>

int main()
{
	// Create a variable to hold the number entered
	int numEntered = 0;

	// Print out a message to tell the user to enter a number
	std::cout << "Enter a whole number between 1 and 10: ";

	// Store the number the user enters in the "numEntered" variable
	std::cin >> numEntered;

	// Print out a new line to space out our text better
	std::cout << "\n";

	// Add 3 to the number entered
	int finalResult = numEntered + 3;
	std::cout << "The number entered plus three equals: " << finalResult << "\n";

	return 0;
}