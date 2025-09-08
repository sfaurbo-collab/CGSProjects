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
	std::vector<int> numbers[10];
	
	for (int i = 0; i <= numbers->size(); i++)
	{
		srand(time(0));

		int randomNum = rand() % 101;

		numbers->push_back(randomNum);
	}
			
	//??? what is going on here

	for (std::vector<int>::iterator it = numbers->begin(); it != numbers->end(); ++it)
	{
		std::cout << *it << " ";
	}
}