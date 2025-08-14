#include <iostream>

using namespace std;

int main()
{
	// Prompt for name
	cout << "Plese enter your name: ";

	// Get the name
	string name;
	cin >> name;

	// Prompt user for year of birth
	cout << "What year were you born? ";

	// Get the year of birth
	int yearOfBirth;
	cin >> yearOfBirth;

	// Prompt user for current year
	cout << "What is the current year? ";

	// Get the current year
	int currentYear;
	cin >> currentYear;

	// Display information to the user
	int age = currentYear - yearOfBirth;
	cout << name << ", you are " << age << " years old! " << endl;
}