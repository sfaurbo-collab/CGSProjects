#include <iostream>
#include <string>

// Use pointers to dynamically allocate structs on the heap.
// Write a program that :
//	 - Defines a Car struct with members :some text
//		 - std::string make
//		 - std::string model
//		 - int year
//	 - Dynamically allocates a Car struct on the heap using a pointer.
//	 - Prompts the user to input the car’s make, model, and year.
//	 - Prints the data stored in the struct via the pointer using the dereference operator (->).
// Properly deallocate the heap memory and print a confirmation message.
// Bonus Task :
//	Add a function to compare the ages of two cars and return the newer car.

struct Car
{
	std::string make;
	std::string model;
	int year;
};

int main()
{
	Car* myCar = new Car;

	std::cout << "Please enter the year of your vehicle: " << std::endl;
	std::cin >> myCar->year;
	std::cout << "Please enter the make of your vehicle: " << std::endl;
	std::cin >> myCar->make;
	std::cout << "Please enter the model of your vehicle: " << std::endl;
	std::cin >> myCar->model;
	std::cout << std::endl;
	std::cout << "You own a " << myCar->year << " " << myCar->make << " " << myCar->model << std::endl;
	std::cout << std::endl;

	Car* myDreamCar = new Car;

	std::cout << "Please enter the year of dream vehicle: " << std::endl;
	std::cin >> myDreamCar->year;
	std::cout << "Please enter the make of your dream vehicle: " << std::endl;
	std::cin >> myDreamCar->make;
	std::cout << "Please enter the model of dream vehicle: " << std::endl;
	std::cin >> myDreamCar->model;
	std::cout << std::endl;
	std::cout << "Your dream car is a " << myDreamCar->year << " " << myDreamCar->make << " " << myDreamCar->model << std::endl;
	std::cout << std::endl;

	if (myCar->year > myDreamCar->year)
	{
		std::cout << "Your car is newer than your dream car" << std::endl;
	}
	else
	{
		std::cout << "Your dream car is newer than your actual car" << std::endl;
	}

	std::cout << std::endl;

	delete myCar;
	myCar = nullptr;

	delete myDreamCar;
	myDreamCar = nullptr;


	if (myCar == nullptr && myDreamCar == nullptr)
	{
		std::cout << "The heap memory has been cleared" << std::endl;
	}

}