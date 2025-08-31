#include <iostream>
#include <fstream>

// Objective: Practice file I/O and character array manipulation.
// 1. Create a program that :
//	- Loads the provided alphabet.txt file into a char array.
//	- Replaces each lowercase letter in the array with its uppercase equivalent.
//	- Writes the updated array to a new file named uppercase_alphabet.txt.

using namespace std;

int main()
{
	ifstream file ("alphabet.txt");

	file.seekg(0, std::ios::end); 
	long fileSize = file.tellg();
	file.seekg(0, std::ios::beg);

	char* alphabet = new char[fileSize + 1];

	int i = 0;
	char ch;
	while (file.get(ch) && i < 52) 
	{ 
		if (islower(ch))
		{
			alphabet[i] = ch -32;
			i++;
		}
		else
		{
			alphabet[i] = ch;
			i++;
		}
	}
	alphabet[i] = '\0';

	file.close();

	ofstream upperfile("UpperAlphabet.txt");

	upperfile << alphabet[52] << "\n";

	upperfile.write(alphabet, 52);

	upperfile.close();

	cout << alphabet << endl;
}