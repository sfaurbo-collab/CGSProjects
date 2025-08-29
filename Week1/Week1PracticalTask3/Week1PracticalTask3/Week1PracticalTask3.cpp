// Calculate Average. Write a program to calculate the average of numbers entered by the user.

#include <iostream>

using namespace std;

int main()
{
	// Ask the user to input three numbers.
	int datum1;
	cout << "This simple program will give you the average of three numbers. \nPlease enter the first whole number: ";
	cin >> datum1;

	int datum2;
	cout << "Please enter the second whole number: ";
	cin >> datum2;

	int datum3;
	cout << "Please enter the third whole number: ";
	cin >> datum3;

	// Calculate the sum and divide by 3 to get the average.
	int sum = (datum1 + datum2 + datum3);
	float average = (float)sum / 3.0f;

	// Print the result.
	cout << "The average of the three numbers is: " << average << endl;
}