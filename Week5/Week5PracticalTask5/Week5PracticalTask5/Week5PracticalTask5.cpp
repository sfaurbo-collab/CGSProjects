#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

// Objective: Solve a specific anagram using the provided dictionary file.
// Load the Dictionary :
//	 - Use the provided dictionary.txt file, which contains 100 words.
//	 - Load the words into an std::vector or std::list.
// Solve the Anagram :
//	 - The anagram to solve is : gimnoprgamr.
//	 - Write a program to identify all valid words in the dictionary that match this anagram.
// Output the Results :
//	 - Print all matching anagrams to the console.

int main()
{
	std::list<std::string> dictionary;
	std::ifstream textFile("dictionary.txt");

	std::string line;
	while (std::getline(textFile, line))
	{
		dictionary.push_back(line);
	}

	//for (std::list<std::string>::iterator it = dictionary.begin(); it != dictionary.end(); ++it) 
	//{
	//	std::cout << *it << std::endl;
	//}

	textFile.close();
		 
	std::vector<char> anagram = { 'g', 'i', 'm', 'n', 'o', 'p', 'r', 'g', 'a', 'm', 'r' };

	//for (int i = 0; i < anagram.size(); i++)
	//{
	//	std::cout << anagram[i] << std::endl;
	//}

	//Now I have to find the words in "dictionary" with starting letters corresponding to "anagram"
	//Then I have to print out the results
	//for loop to generate next word
		//for loop comparing against the dictionary
			//if the two words are the same print them out
	//Bubble sort
}