#include <iostream>

using namespace std;

enum Drinks
{
	unavailable,
	cocaCola,
	dietCoke,
	sprite,
	fanta,
	fresca
};

int main()
{
	// Objective: Create a program that uses a switch statement to simulate a drinks machine.
	
	// Present the user with a menu of 5 beverages(e.g., Coke, Water).
	
	cout << "Welcome to the Drink Vending Machine.\n\nPlease select a drink.\n\n";
	cout << "1. Coka Cola\n";
	cout << "2. Diet Coke\n";
	cout << "3. Sprite\n";
	cout << "4. Fanta\n";
	cout << "5. Fresca\n\n";
	
	// Ask the user to input a number(1–5) to select a beverage.
	
	cout << "Enter which drink you would like by selecting the corresponding number: ";
	
	int drink;
	cin >> drink;

	// Use a switch statement to output the selected beverage : eg: “You chose : Coke.”

	switch (drink)
	{
		case cocaCola:
		{
			cout << "\nYou chose: Coca Cola.";
			cout << "\nThank you for your selection. Enjoy your beverage.\n";
			break;
		}
		case dietCoke:
		{
			cout << "\nYou chose: Diet Coke.";
			cout << "\nThank you for your selection. Enjoy your beverage.\n";
			break;
		}
		case sprite:
		{
			cout << "\nYou chose: Sprite:";
			cout << "\nThank you for your selection. Enjoy your beverage.\n";
			break;
		}
		case fanta:
		{
			cout << "\nYou chose: Fanta";
			cout << "\nThank you for your selection. Enjoy your beverage.\n";
			break;
		}
		case fresca:
		{
			cout << "\nYou chose; Fresca";
			cout << "\nThank you for your selection. Enjoy your beverage.\n";
			break;
		}
		
		// Add error handling for invalid input(e.g., numbers outside the range 1–5).

		default:
		{
			cout << "\nYou have chosen and invalid entry. Please try again.\n";
		}	
	}
}