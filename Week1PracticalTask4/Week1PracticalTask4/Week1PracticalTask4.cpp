// Unit Conversion Challenge - Create a program that converts a length in inches to multiple units.

#include <iostream>

using namespace std;

int main()
{
	// Ask the user to input a length in inches.
	cout << "This simple program will convert inches to feet, centimeters and meters. \nPlease enter the number of inches: ";
	float inches;
	cin >> inches;

	// Convert the length to feet using the formula: 1 foot = 12 inches.
	float feet = inches / 12.0f;

	// Convert the length to meters using the formula: 1 inch = 0.0254 meters.
	float meters = inches * 0.0254f;

	// Convert the length to centimeters using the formula: 1 inch = 2.54 centimeters.
	float centimeteres = inches * 2.54f;

	// Print all the converted values.
	cout << inches << " is equal to " << feet << " feet." << endl;
	cout << inches << " is equal to " << meters << " meters." << endl;
	cout << inches << " is equal to " << centimeteres << endl;
}