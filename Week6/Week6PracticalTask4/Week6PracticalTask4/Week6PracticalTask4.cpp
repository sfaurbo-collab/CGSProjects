#include <iostream>

// Explore the difference between passing by reference and passing by value with structs.
// Define a Rectangle struct with members :
//	 - int width
//	 - int height
// Create a function that :
//	 - Takes a Rectangle by value and modifies its width and height.
//	 - Takes a Rectangle by reference and modifies its width and height.
// Create two instances of the Rectangle struct, pass one by value and the other by reference, and print their values before and after the function call.
// Bonus Task :
//	Add a function to compare the areas of two rectangles and return which one is larger.

struct RectangleOne
{
	int width;
	int height;
};

struct RectangleTwo
{
	int width;
	int height;
};

void ModifyRectangleOne(RectangleOne x)
{
	x.width = 6;
	x.height = 7;
	std::cout << "The modified width of the first rectangle is " << x.width << " and the height is " << x.height << "." << std::endl;
}

void ModifyRectangleTwo(RectangleTwo& x)
{
	x.width = 9;
	x.height = 4;
	std::cout << "The modified width of the second rectangle is " << x.width << " and the height is " << x.height << "." << std::endl;
}

int main()
{
	RectangleOne rectangleA = { 10, 10 };
	
	std::cout << "The original width of the first rectangle is " << rectangleA.width << " and the height is " << rectangleA.height << "." << std::endl;

	ModifyRectangleOne(rectangleA);

	RectangleTwo rectangleB = { 5, 5 };

	std::cout << "The original width of the second rectangle is " << rectangleB.width << " and the height is " << rectangleB.height << "." << std::endl;

	ModifyRectangleTwo(rectangleB);
}