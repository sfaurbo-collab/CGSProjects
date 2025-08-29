#include <iostream>
#include <cstdlib>
#include <ctime>

// Objective: Explore random number generation and parameter handling.
// Create a program that :
//	Generates a random whole number between 1 and 100 using a function.
//	Prints the result.
//	Determines whether the number is odd or even using another function.
//	Outputs "ODD" or "EVEN" based on the result.
// Use the modulus operator (%) to check for odd / even numbers.

using namespace std;

int main()
{
	srand(time(0));
	
	int randomNum = rand() % 101;

	cout << randomNum << endl;

	if (randomNum % 2 == 0)
	{
		cout << "EVEN" << endl;
	}
	else if (randomNum % 2 != 0)
	{
		cout << "ODD" << endl;
	}
}