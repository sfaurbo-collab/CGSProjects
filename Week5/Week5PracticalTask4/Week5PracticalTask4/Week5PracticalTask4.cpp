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

	std::cout << randomNum << std::endl;

	//insert the random number into the list 1o times

	//???

	//Add an element to the front

	std::cout << "Please enter a number to put at the top of the list: ";
	int firstElement;
	std::cin >> firstElement;

	numbers->push_front(firstElement);

	//Add an element to the back of the list

	std::cout << "Please enter a number to put at the end of the list: ";
	int lastElement;
	std::cin >> lastElement;

	numbers->push_back(lastElement);

	//Remove even numbers from the list --> 

	numbers->remove_if([](int n) { return n % 2 == 0; });

	//Reverse the list
	
	numbers->reverse();

	//Print the list

	std::cout << numbers << std::endl;
}