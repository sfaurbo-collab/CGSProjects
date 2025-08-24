#include <iostream>
#include <cstdlib>
#include <ctime>

// Objective: Work with random numbers and ranges.
// Write a program that :
//	Generates a random number between 1 and 100 using a function.
//	Calculates the sum of all integers from 1 to the random number using another function.
//	Prints the sum.
// Use a function with default parameters to specify a range(e.g., default from 1–100).
// Hint : The function declaration may look like this. int SumOfRange(int start = 1, int end = 100);

using namespace std;

int SumOfRange(int start = 1, int end = 100)
{
	return 0;
}

int main()
{
	srand(time(0));

	int randomNum = rand() % 101;
		
	int sum = (randomNum / 2) * (1 + randomNum);

	cout << "\nThe sum of 1 to " << randomNum << " is:" << sum << endl;
}