#include <iostream>
#include<string>

// Refactor the Person class and introduce inheritance with method overriding.
//
// Refactor the Person class from the previous week to include :
//	 - A constructor that initializes name and age.
//	 - A method GetName() that returns the name of the person.
// Create a Student class that inherits from Person and :
//	 - Adds a private member std::string courseName.
//	 - Implements a constructor to initialize name, age, and courseName.
//	 - Overrides the GetName() method to include the courseName in the output.
// Instantiate a Student object and call GetName() to demonstrate the method overriding.
// 
// Bonus Task :
//	Add a polymorphic behavior by defining a base class pointer Person* and store a Student object in it.Call the GetName() method to see the overridden behavior.

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

	std::string GetName()
	{
		return name;
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

class Student : public Person
{
private: 
	
	std::string courseName;

public:
	Student()
	{
		courseName = "Unknown";
	}

	Student(std::string n, int a, std::string c)
	{
		name = n;
		age = a;
		courseName = c;
	}

	std::string GetName()
	{
		return courseName;
	}

	void DisplayStudent()
	{
		DisplayPerson();
		std::cout << "Course: " << courseName << std::endl;
	}

	~Student()
	{
		std::cout << "Student is no longer enrolled.\n" << std::endl;
	}
};

int main()
{
	Student student("Steven", 40, "Human Anatomy");
	student.GetName();
	student.DisplayStudent();
	std::cout << std::endl;
}