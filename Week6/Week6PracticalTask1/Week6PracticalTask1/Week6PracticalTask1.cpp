#include <iostream>
#include <string>

// Learn to define and use structs, and explore memory size considerations.
// Write a program that :
//	 - Defines a Person struct with members :
//		 - std::string name
//		 - int age
//		 - float height(in meters).
//	 - Creates two instances of the Person struct, assigns values to each member, and prints their data to the console.
// Use the sizeof operator to print the size of the Person struct in bytes.
// Bonus Task :
//	 - Add a pointer member to the struct and dynamically allocate memory for it.Compare the size of the struct with and without the pointer.

struct Person
{
	std::string name;
	int age;
	float height; //height is in meters
};

int main()
{
	Person person1;
	person1.name = "Adam";
	person1.age = 42;
	person1.height = 1.88f;

	std::cout << "The name of the first character is: " << person1.name << std::endl;
	std::cout << "They are " << person1.age << " years old." << std::endl;
	std::cout << "They are " << person1.height << " meters tall." << std::endl;
	std::cout << std::endl;

	Person person2;
	person2.name = "Eve";
	person2.age = 37;
	person2.height = 1.68f;

	std::cout << "The name of the second character is: " << person2.name << std::endl;
	std::cout << "They are " << person2.age << " years old." << std::endl;
	std::cout << "They are " << person2.height << " meters tall." << std::endl;
	std::cout << std::endl;
	std::cout << "The Person struct is " << sizeof(Person) << " bytes." << std::endl;
}