#include <iostream>

using namespace std;

int main()
{
	int x = 10;
	x = x + 20; // same as x += 20;
	x += 20; // same as x = x + 20;

	x -= 10; // same as x = x - 10;
	x *= 10; // same as x = x * 10;
	x /= 10; // same as x = x / 10;
	x %= 10; // same as x = x % 10;
}