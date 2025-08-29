#include <iostream>
#include <string>

// Objective: Use recursion to generate a pyramid of letters that builds up to the middle of the alphabet and then narrows symmetrically.
// User Input :
//	Ask the user for an integer input representing the number of rows in the pyramid.
// Recursive Logic :
//	Use recursion to build the pyramid row by row.
//	Each row includes letters starting from A, incrementing alphabetically to the row’s position, and then decrementing symmetrically.

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

void Letters(int letters, int i)
{
	if (letters == 0)
	{
		return;
	}
	char ch = 'A';
	if (letters < (2 * i + 1) / 2) ch++;
	else ch--;
	cout << ch;
	Letters(letters - 1, i - 1);
}

void Pyramid(int i, int j)
{
	if (i == 0)
	{
		return;
	}
	Space(i);
	Letters(2 * (j - i) + 1, i);
	cout << endl;
	Pyramid(i - 1, j);
}

void PyramidShape(int i, int j)
{
	Pyramid(i, j);
}

int main()
{
	// User Input: Ask the user for an integer input representing the number of rows in the pyramid.
	
	int num;
	
	cout << "This simple program will make a pyramid out of letters based on the number you input.\nThe number represents the number of rows in the pyramid\n\nPlease enter a number: ";
	
	cin >> num;

	int pyramid = num;

	PyramidShape(pyramid, pyramid);
}