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
//	 - Add a pointer member to the struct and dynamically allocate memory for it. Compare the size of the struct with and without the pointer.

struct Person
{
	std::string name;
	int age;
	float height; //height is in meters
	int* weight; //weight is in kilograms
};

int main()
{
	Person person1;
	person1.name = "Adam";
	person1.age = 42;
	person1.height = 1.88f;
	person1.weight = new int;
	*person1.weight = 100;

	std::cout << "The name of the first character is: " << person1.name << std::endl;
	std::cout << "They are " << person1.age << " years old." << std::endl;
	std::cout << "They are " << person1.height << " meters tall." << std::endl;
	std::cout << "They weigh " << *person1.weight << " kilograms." << std::endl;
	std::cout << std::endl;

	delete person1.weight;
	person1.weight = nullptr;

	Person person2;
	person2.name = "Eve";
	person2.age = 37;
	person2.height = 1.68f;
	person2.weight = new int;
	*person2.weight = 50;

	std::cout << "The name of the second character is: " << person2.name << std::endl;
	std::cout << "They are " << person2.age << " years old." << std::endl;
	std::cout << "They are " << person2.height << " meters tall." << std::endl;
	std::cout << "They weigh " << *person2.weight << " kilograms." << std::endl;
	std::cout << std::endl;
	std::cout << "The Person struct is " << sizeof(Person) << " bytes." << std::endl;

	delete person2.weight;
	person2.weight = nullptr;
}