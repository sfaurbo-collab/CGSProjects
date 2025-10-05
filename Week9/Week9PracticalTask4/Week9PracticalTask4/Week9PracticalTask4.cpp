#include<iostream>

// Implement advanced operator overloading for comparison and stream insertion.
// Write a Point class with int x and int y.
// Overload the equality operator (operator==) to compare if two Point objects are equal based on their x and y values.
// Overload the stream insertion operator (operator<<) to allow printing the Point object using std::cout.
//	 - The Point should print in the format(x, y).
// Create two Point objects, use the overloaded equality operator to compare them, and print the results using the overloaded stream insertion operator.
// Bonus Task :
//	Add more operators(e.g., +, -) to allow arithmetic operations on Point objects.

class Point
{
public:

	double x;
	double y;

	Point()
	{
		x = 0;
		y = 0;
	}

	Point(double xCoord, double yCoord)
	{
		x = xCoord;
		y = yCoord;
	}

	Point operator+(const Point& other) const
	{
		return Point(x + other.x, y + other.y);
	}

	Point operator-(const Point& other) const
	{
		return Point(x - other.x, y - other.y);
	}

	Point operator*(const Point& other) const
	{
		return Point(x * other.x, y * other.y);
	}

	Point operator/(const Point& other) const
	{
		return Point(x / other.x, y / other.y);
	}

	Point operator=(const Point& other)
	{
		if (this != &other)
		{
			x = other.x;
			y = other.y;
		}
		return *this;
	}

	bool operator==(const Point& other) const 
	{
		return (x == other.x && y == other.y);
	}

	friend std::ostream& operator<<(std::ostream& os, const Point& point)
	{
		os << "(" << point.x << ", " << point.y << ")";
		return os;
	}
};

int main()
{
	Point point1(3.7, -4.2);
	Point point2(7.3, 2.4);
	//Point point2(3.7, -4.2);

	std::cout << "Point 1: " << point1 << std::endl;
	std::cout << "Point 2: " << point2 << std::endl;

	if (point1 == point2)
	{
		std::cout << "The coordinates are the same." << std::endl;
	}
	else
	{
		std::cout << "The coordinates are not the same." << std::endl;
	}

	Point sumPoint = point1 + point2;
	Point difPoint = point1 - point2;
	Point proPoint = point1 * point2;
	Point quoPoint = point1 / point2;

	std::cout << "The sum of the two points is " << sumPoint << "." << std::endl;
	std::cout << "The difference of the two points is " << difPoint << "." << std::endl;
	std::cout << "The product of the two points is " << proPoint << "." << std::endl;
	std::cout << "The quotient of the two points is " << quoPoint << "." << std::endl;
}