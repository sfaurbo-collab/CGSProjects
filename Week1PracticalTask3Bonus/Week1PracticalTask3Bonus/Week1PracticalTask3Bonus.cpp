// Calculate Average. Write a program to calculate the average of numbers entered by the user.

#include <iostream>

using namespace std;

int main()
{
	// Ask the user to input three numbers.
	int datum1;
	cout << "This simple program will give you the sum, product and average of five numbers. \nPlease enter the first whole number: ";
	cin >> datum1;

	int datum2;
	cout << "Please enter the second whole number: ";
	cin >> datum2;

	int datum3;
	cout << "Please enter the third whole number: ";
	cin >> datum3;

	int datum4;
	cout << "Please enter the fourth whole number: ";
	cin >> datum4;

	int datum5;
	cout << "Please enter the fifth whole number: ";
	cin >> datum5;

	// Calculate the sum and divide by 5 to get the average.
	int sum = (datum1 + datum2 + datum3 + datum4 + datum5);
	int product = (datum1 * datum2 * datum3 * datum4 * datum5);
	float average = (float)sum / 5.0f;

	// Print the result.
	cout << "The sum of the numbers is: " << sum << endl;
	cout << "The product of the numbers is: " << product << endl;
	cout << "The average of the numbers is: " << average << endl;
	}