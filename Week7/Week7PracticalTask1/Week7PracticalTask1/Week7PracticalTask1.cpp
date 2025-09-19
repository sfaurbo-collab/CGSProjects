#include <iostream>
#include <string>

// Learn how to create and use classes, including constructors.
// Define a class Person with the following attributes :
//	 - std::string name
//	 - int age
// Create an object of Person and initialize it using a parameterized constructor(constructor that takes name and age).
// Print the object's data using a member function.
// Bonus Task :
//	Add a destructor to the class that prints "Object destroyed" when the Person object is destroyed.

class Person
{
public:
	std::string name;
	int age;

	Person() 
	{
		name = "Unknown";
		age = 0;
	}

	Person(std::string n, int a) 
	{
		name = n;
		age = a;
	}
	
	void DisplayPerson()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Age: " << age << std::endl;
	}

	~Person() 
	{
		std::cout << "Object destroyed: " << name << std::endl;
	}

};

int main()
{
	Person character("Steven", 40);
	character.DisplayPerson();
	std::cout << std::endl;
}