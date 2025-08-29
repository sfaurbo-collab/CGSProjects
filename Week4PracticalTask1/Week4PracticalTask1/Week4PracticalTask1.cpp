#include <iostream>

// Objective: Use while, do - while, and for loops to solve simple problems.
// 1. Write a program that demonstrates the following :
//	- Use a while loop to print numbers from 1 to 10.
//	- Use a do - while loop to prompt the user to input a number between 1 and 10. If the number is invalid, prompt them again.
//	- Use a for loop to print the first 10 multiples of 3 (i.e., 3, 6, 9, ..., 30).

using namespace std;

int main()
{
	int number = 0;

	while (number <= 9)
	{
		number++;
		cout << number << endl;
	}
	
	int input;

	do
	{
		cout << "Please enter a number from 1 to 10: " << endl;
		cin >> input;
	} while (input > 10 || input < 1);
	cout << "The number you have entered is valid" << endl;



}