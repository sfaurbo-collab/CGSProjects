#include <iostream>

// Practice defining and chaining multiple functions.
// Write a program that includes the following functions :
//	A function that increments an integer by 1.
//	A function that multiplies an integer by 2.
//	A function that increments the result by 4.
//	A function that divides the result by 2.
//	A function that subtracts the original input from the final result.
// Sequentially call these functions, passing the results from one function to the next.

using namespace std;

int IncrementByOne(int i)
{
	return ++i;
}

int MultiplyByTwo(int i)
{
	return i * 2;
}

int IncrementByFour(int i)
{
	return i + 4;
}

int DivideByTwo(int i)
{
	return i / 2;
}

int SubtractOriginalNumber(int i, int originalNum)
{
	return i - originalNum;
}

int main()
{
	int i;
	
	cout << "Enter a number: " << endl;
	
	cin >> i;
		
	int result = IncrementByOne(i);
	
	int result2 = MultiplyByTwo(result);

	int result3 = IncrementByFour(result2);

	int result4 = DivideByTwo(result3);

	int result5 = SubtractOriginalNumber(result4, i);

	cout << "The result of the function is: " << result << endl;
	cout << "The second result of the function is: " << result2 << endl;
	cout << "The third result of the function is: " << result3 << endl;
	cout << "The fourth result of the function is: " << result4 << endl;
	cout << "The fifth result of the function is: " << result5 << endl;
}