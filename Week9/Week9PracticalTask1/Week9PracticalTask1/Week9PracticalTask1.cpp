#include <iostream>

//Learn the basics of operator overloading, focusing on addition and assignment operators.
//
// Write a C++ program that defines a Position class with the following attributes :
//	 - int x
//	 - int y
// Overload the addition operator (operator+) to allow adding two Position objects :
//	 - position1 + position2 should return a new Position where x = position1.x + position2.x and y = position1.y + position2.y.
// Overload the assignment operator (operator=) to correctly assign both x and y between two Position instances.
// Demonstrate the overloaded operators by creating two Position objects and performing both addition and assignment operations.
// Bonus Task :
//	Add a method to print the Position(e.g., std::cout << position).

class Position
{
public:
	int x;
	int y;

	Position()
	{
		x = 0;
		y = 0;
	}

	Position(int xCoord, int yCoord)
	{
		x = xCoord;
		y = yCoord;
	}

	Position operator+(const Position& other) const
	{
		return Position(x + other.x, y + other.y);
	}

	Position operator=(const Position& other)
	{
		if (this != &other)
		{
			x = other.x;
			y = other.y;
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Position& pos)
	{
		os << "(" << pos.x << ", " << pos.y << ")";
		return os;
	}
	//Why did I have to overload the "<<" operator inorder to use std::cout???
};

int main()
{
	Position position1(3, 7);
	Position position2(4, 2); 

	Position newPosition = position1 + position2;

	Position assignPosition;
	assignPosition = position1;

	std::cout << "Position 1: " << position1 << std::endl;
	std::cout << "Position 2: " << position2 << std::endl;
	std::cout << "New Position: " << newPosition << std::endl;
	std::cout << "Assigned Position: " << assignPosition << std::endl;
}