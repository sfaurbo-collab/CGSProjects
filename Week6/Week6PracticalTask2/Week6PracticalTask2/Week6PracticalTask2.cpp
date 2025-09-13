#include <iostream>

// Compare stack and heap memory allocation for arrays.
// Write a program that :
//	 - Creates an array of 5 integers using stack allocation.
//	 - Dynamically allocates an array of 5 integers on the heap.
//	 - Prompts the user to enter values for both arrays and prints the values and their memory addresses.
// Properly deallocate the heap memory and print a confirmation message.

int main()
{
	int numbers[5];

	std::cout << "Please enter 5 numbers: " << std::endl;
	std::cin >> numbers[0];
	std::cin >> numbers[1];
	std::cin >> numbers[2];
	std::cin >> numbers[3];
	std::cin >> numbers[4];

	std::cout << "You entered " << std::endl;

	for (int i = 0; i < 5; ++i)
	{
		std::cout << numbers[i] << ", ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

    int* moreNumbers;
	moreNumbers = new int[5];

	std::cout << "Please enter 5 more numbers: " << std::endl;
	std::cin >> moreNumbers[0];
	std::cin >> moreNumbers[1];
	std::cin >> moreNumbers[2];
	std::cin >> moreNumbers[3];
	std::cin >> moreNumbers[4];

	std::cout << "You entered " << std::endl;

	for (int i = 0; i < 5; ++i)
	{
		std::cout << moreNumbers[i] << ", ";
	}
	
	std::cout << std::endl;
	std::cout << std::endl;

	delete[] moreNumbers;
	moreNumbers = nullptr;

	if (moreNumbers == nullptr)
	{
		std::cout << "The heap memory has been cleared." << std::endl;
	}
}