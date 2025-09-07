#include <iostream>
#include <list>

// Objective: Practice unique operations of std::list.
// Write a program that :
//	 - Initializes a std::list<int> with at least 10 random integers.
//	 - Uses member functions to:some text
//		 - Add an element to the front and back of the list.
//		 - Remove all even numbers from the list.
//		 - Reverse the list.
// Print the list after each operation to the console.

int main()
{
	//Initialize a std::list<int>

	std::list<int> numbers[10];
	
	//Generate a random number
	
	srand(time(0));
		
	int randomNum = rand() % 101;
	
	//insert the random number into the list

}