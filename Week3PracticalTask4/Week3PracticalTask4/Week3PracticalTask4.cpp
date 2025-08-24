#include <iostream>
#include <string>

// Objective: Use recursion to create a diamond shape.
// Write a program that asks the user to input an integer representing the size of the diamond(e.g., the maximum number of stars in the middle row).
// Use recursion to :
//	Print the first half of the diamond(increasing number of stars).
//	Print the second half of the diamond(decreasing number of stars).

using namespace std;

void Space(int space)
{
	if (space == 0)
	{
		return;
	}
	cout << " ";
	Space(space - 1);
}

void Stars(int stars)
{
	if (stars == 0)
	{
		return;
	}
	cout << "*";
	Stars(stars - 1);
}

void UpperDiamond(int d, int f)
{
	if (d == 0)
	{
		return;
	}
	Space(d);
	Stars(2 * (f - d) + 1);
	cout << endl;
	UpperDiamond(d - 1, f);
}

void LowerDiamond(int d, int f)
{
	if (d == 0)
	{
		return;
	}
	Space(f - d + 1);
	Stars(2 * d - 1);
	cout << endl;
	LowerDiamond(d - 1, f);
}

void DiamondShape(int d, int f)
{
	UpperDiamond(d, f);
	LowerDiamond(d - 1, f);
}

int main()
{
	int num;
	
	cout << "This simple program will make a diamond based on the number you input.\n\nPlease enter a number: ";

	cin >> num;
	
	int diamond = ((num / 2) + 1);
	
	DiamondShape(diamond, diamond);
}