#include <iostream>
#include <vector>

//Understand runtime polymorphism by creating a base class and derived classes.
// Define a base class Shape with a virtual function area() that returns the area of the shape.
// Create two derived classes :
//	 - Circle with a member radius and a method to calculate the area.
//	 - Rectangle with width and height members and a method to calculate the area.
// Demonstrate polymorphism by creating a Shape* array and assigning both Circle and Rectangle objects to it.Call area() using the base class pointer and display the results.
// Use runtime polymorphism to ensure that the correct area() function is called for each object, regardless of the pointer’s type.
// Bonus Task :
//	Implement a display() function in both derived classes and call it using polymorphism.

class Shape
{
public:
	virtual double area() = 0;
};

class Circle : public Shape
{
public:
	double radius;
	const double PI = 3.14159265358979323846;

	Circle()
	{
		radius = 0;
	}

	Circle(double r)
	{
		radius = r;
	}

	double area() override
	{
		return PI * radius * radius;
		std::cout << "The area of the circle is " << (PI * radius * radius) << "." << std::endl;
	}
};

class Rectangle : public Shape
{
public:
	double width;
	double height;

	Rectangle()
	{
		width = 0;
		height = 0;
	}

	Rectangle(double w, double h)
	{
		width = w;
		height = h;
	}

	double area() override
	{
		return width * height;
		std::cout << "The area of the rectangle is " << (width * height) << "." << std::endl;
	}
};

const int NumOfInstances = 2;

int main()
{
	std::vector<Shape*> ShapeCollection;

	ShapeCollection.push_back(new Circle(3.7));
	ShapeCollection.push_back(new Rectangle(4.6, 2.9));

	for (auto& shape_ptr : ShapeCollection) 
	{
		std::cout << "Area: " << shape_ptr->area() << std::endl;
	}

	for (auto& shape_ptr : ShapeCollection) 
	{
		delete shape_ptr;
	}
	
	ShapeCollection.clear();
}