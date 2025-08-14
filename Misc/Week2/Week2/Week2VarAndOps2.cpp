#include <iostream>

using namespace std;

int main()
{
	// Prompt user to enter temp in celsius
	cout << "Please enter a temperature in Celsius: ";

	// Get temperature
	float celsius;
	cin >> celsius;

	// Convert the temperature to fahrenheit
	float fahrenheit = (celsius * 9.0f) / 5.0f + 32;

	// Display temps
	cout << celsius << " Celsius in fahrenheit is " << fahrenheit << endl;
}