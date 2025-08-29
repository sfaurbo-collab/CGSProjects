#include <iostream>

using namespace std;

int x = 37;

int main()
{
	int x = 42;

	cout << "The value of x is: " << x << endl;
	cout << "The other value of x is: " << ::x << endl;
}