#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

// Objective: Use iterators to navigate and manipulate collections.
// Create a program that :
//	 - Initializes a std::vector<int> with 10 random integers between 1 and 100.
//	 - Uses an iterator to :
//		 - Print all elements in the vector.
//		 - Double the value of each element.
// Modify the program to repeat the same operations on an std::list<int> using an iterator.

int main()
{
	srand(time(0));
	//srand(1); testing value
	
	//int test[5];

	const int MAX_CAPACITY = 10;
	std::vector<int> numbers;
	numbers.reserve(MAX_CAPACITY);
	
	for (int i = 0; i < MAX_CAPACITY; i++)
	{
		int randomNum = rand() % 101;

		numbers.push_back(randomNum);
	}
			
	//??? what is going on here

	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		std::cout << *it << " ";
	}
}