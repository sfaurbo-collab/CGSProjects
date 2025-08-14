#include <iostream>

using namespace std;

int main()
{
	// Prompt user to enter distance in cm
	cout << "Please enter a distance in centimeters: ";

	// Get cm
	int centimeters;
	cin >> centimeters;

	// Calculate feet
	float totalFeet = centimeters / 30.48f;
	int justFeet = (int)totalFeet;

	// Calculate inches
	int justInches = (int)((totalFeet - justFeet) * 12);

	// Display info to user
	cout << "Feet = " << justFeet << endl;
	cout << "Inches = " << justInches << endl;
}