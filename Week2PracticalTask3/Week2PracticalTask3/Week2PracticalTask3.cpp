// Use if statements to assign grades based on a score.
#include <iostream>

using namespace std;

int main()
{
	// Write a program that asks the user for a grade between 0 and 100. Use if statements to output the grade :
	cout << "This simple program will convert your number grade to a letter.\nPlease enter your grade: ";
	int grade;
	cin >> grade;

	// 80 and above : A *
	if (grade >= 80 && grade <= 100)
	{
		cout << "\nYou achieved an A*\n";
	}

	// 70–79 : A
	if (grade >= 70 && grade <= 79)
	{
		cout << "\nYou achieved an A\n";
	}
	
	// 60–69 : B
	if (grade >= 60 && grade <= 69)
	{
		cout << "\nYou achieved a B\n";
	}

	// 50–59 : C
	if (grade >= 50 && grade <= 59)
	{
		cout << "\nYou achieved a C\n";
	}

	// 40–49 : D
	if (grade >= 40 && grade <= 49)
	{
		cout << "\nYou achieved a D\n";
	}

	// 1–39 : F
	if (grade >= 1 && grade <= 39)
	{
		cout << "\nYou achieved an F\n";
	}

	// 0 : U
	if (grade == 0)
	{
		cout << "\nYou have entered an invalid grade. Please restart the program.\n" << endl;
	}

	// Bonus Task : Refactor the program to use only one condition per if statement.
}