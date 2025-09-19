#include <iostream>
#include <string>
#include "BankAccount.h"
#include <cctype>

// Learn how to apply access modifiers and encapsulation.
// Create a class BankAccount with the following attributes :
//	 - double balance
//	 - std::string accountHolderName
// Set the attributes as private and provide public getter and setter functions to access and modify them.
// Implement a member function deposit() that adds a specified amount to the balance and withdraw() that subtracts from the balance.
// Use these functions to simulate a deposit and a withdrawal.
// Organise the class declaration in a header file and its implementation in a cpp file.
//Bonus Task :
//	Add a method to check the balance and make sure it’s only accessible via the getter function(encapsulation).

int main()
{
	BankAccount chequing;
	chequing.setBalance(1000);
	chequing.setAccountHolderName("Steven Faurbo");
	chequing.displayInfo();

	std::string response;
	std::cout << "Would you like to make a deposit? (yes/no)" << std::endl;
	std::cin >> response;

	if (response == "yes")
	{
		std::cout << "How much are you depositing?" << std::endl;
		int moreMoney;
		std::cin >> moreMoney;
		chequing.deposit(moreMoney);
		chequing.displayInfo();
	}
	else if (response == "no")
	{
		std::string nextResponse;
		std::cout << "Would you like to make a withdrawal? (yes/no)" << std::endl;
		std::cin >> nextResponse;
		
		if (nextResponse == "yes")
		{
			std::cout << "How much would you like to withdrawal?" << std::endl;
			int lessMoney;
			std::cin >> lessMoney;
			chequing.withdrawal(lessMoney);
			chequing.displayInfo();
		}
		else if (nextResponse == "no")
		{
			std::cout << "Thank you" << std::endl;
		}
		else
		{
			std::cout << "Invalid Entry" << std::endl;
		}
	}
	else
	{
		std::cout << "Invalid Entry" << std::endl;
	}
}