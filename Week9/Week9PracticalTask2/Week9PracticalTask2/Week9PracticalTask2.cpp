#include <iostream>

//Implement function overloading for handling multiple types of input.
// Write a program that defines a class Rectangle with the following members :
//	 - int width
//	 - int height
// Overload a function area() that calculates the area of the rectangle :
//	 - One version of the function should accept both width and height as parameters.
//	 - Another version should calculate the area using default values for width and height(e.g., default to 5x5).
// Demonstrate the overloaded function by creating instances of the Rectangle class and calling the area() function in different ways.
// Bonus Task :
//	Overload the area() function to also accept a parameter that allows the calculation of area for a square(where width = height).

class Rectangle
{
public:
	int width;
	int height;
	const int defaultWidth = 5;
	const int defaultHeight = 5;

	Rectangle()
	{
		width = defaultWidth;
		height = defaultHeight;
	}

	Rectangle(int w, int h)
	{
		width = w;
		height = h;
	}

	int Area(int width, int height)
	{
		return width * height;
	}

	int Area()
	{
		return defaultHeight * defaultWidth;
	}

	void DisplayDimensions()
	{
		std::cout << "The dimenstions of the rectangle are " << width << " wide and " << height << " high." << std::endl;
	}
};

int main()
{
	Rectangle rectangle(4, 2);
	rectangle.DisplayDimensions();
	rectangle.Area(4, 2);
	std::cout << "The area of the first rectangle is: " << rectangle.Area(4, 2) << std::endl;
	Rectangle rectangleTwo;
	rectangleTwo.DisplayDimensions();
	rectangleTwo.Area();
	std::cout << "The area of the first rectangle is: " << rectangleTwo.Area() << std::endl;
	
}