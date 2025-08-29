#include <iostream>

// Objective: Practice while loops and control flow.
// 1. Write a program that :
//	- Uses a while loop to continually ask the user to enter any number other than 5.
//	- Exits the loop and tells the user : some text
//		- “Hey you weren’t supposed to enter 5!” when the number 5 is entered.
//		- “Wow, you’re more patient than I am, you win.” if the user doesn’t enter 5 after 10 iterations.
// Hint : Use the break keyword to exit the loop early.

using namespace std;

int main()
{

	int number = 0;
	int counter = 0;

	while (number != 5)
	{
		cout << "Please enter any number, except for 5: ";
		cin >> number;
		
		if (counter < 9)
		{
			counter++;
			cout << "Attempt: " << counter << endl;
		}
		else if (counter == 9)
		{
			cout << "Wow, you're more patient than I am, you win." << endl;
			break;
		}
		else if (number == 5)
		{
			cout << "Hey you weren’t supposed to enter 5!" << endl;
		}
	}
}