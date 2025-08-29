#include <iostream>

// Objective: Work with arrays to store data and calculate statistics.
// 1. Write a program that :
//	- Asks the user to input 10 integer values.
//	- Stores these values in an array.
//	- Uses a loop to print the array contents.
//	- Calculates and prints the following statistics :
//		- The sum of all values.
//		- The average of the values.
//		- The largest and smallest values.
//		- The number of even and odd values.

using namespace std;

int main()
{
	int data [10];

	cout << "Please enter 10 numbers: ";
	cin >> data[0];
	cin >> data[1];
	cin >> data[2];
	cin >> data[3];
	cin >> data[4];
	cin >> data[5];
	cin >> data[6];
	cin >> data[7];
	cin >> data[8];
	cin >> data[9];
	cout << endl;

	cout << "These are the numbers you entered: " << endl;
	for (int num : data)
	{
		cout << num << ", ";
	}

	float arraySum = 0.0f;
	for (int i = 0; i < 10; ++i)
	{
		arraySum += data[i];
	}
	cout << "\n\nThe sum of the numbers you entered is: " << arraySum << endl;

	float arrayAverage = arraySum / 10;
	cout << "\nThe average of the numbers you entered is : " << arrayAverage << endl;

	int minValue = numeric_limits<int>::max(); 
	int maxValue = numeric_limits<int>::min(); 
	for (int num : data) 
	{
		if (num < minValue) 
		{
			minValue = num;
		}
		if (num > maxValue) 
		{
			maxValue = num;
		}
	}
	cout << "\nThe lowest number you entered was: " << minValue << endl;
	cout << "\nThe highest number you entered was: " << maxValue << endl;

	int evenNumbers = 0;
	int oddNumbers = 0;
	for (int i = 0; i < 10; i++) 
	{
		if (data[i] % 2 == 0)
		{
			evenNumbers++;
		}
		else 
		{
			oddNumbers++;
		}
	}
	cout << "\nThe number of even numbers that were entered is: " << evenNumbers << endl;
	cout << "\nThe number of odd numbers that were entered is: " << oddNumbers << endl;
}