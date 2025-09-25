#include<iostream>
#include<string>

// Understand the complexities of multiple inheritance and virtual inheritance.
//
// Create a base class Shape with a pure virtual function Draw().
// Create two derived classes, Circle and Rectangle, that override the Draw() function.
// Create a third class, ColoredShape, that inherits from both Circle and Rectangle and adds an additional member std::string color.
// Implement a Draw() function in ColoredShape that calls the Draw() function from both Circle and Rectangle, and prints the color attribute.
// Demonstrate the usage of virtual inheritance in this scenario to avoid the diamond problem(where two classes inherit from the same base class).
// 
// Bonus Task :
//	Show the difference in behavior between regular inheritance and virtual inheritance in this example.Add a second base class (e.g., Position) and demonstrate the issue that occurs with regular inheritance vs. virtual inheritance.

class Shape 
{
public:

    virtual void Draw() = 0;

    virtual ~Shape() {}
};