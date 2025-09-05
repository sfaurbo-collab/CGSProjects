#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// Objective: Use string manipulation functions to reverse a sentence.
// Write a program that :
//	 - Asks the user to enter a short sentence using std::getline().
//	 - Passes the sentence into a function to reverse the order of the words without reversing the words themselves.

std::vector<std::string> splitSentence(std::string userSentence)
{
    std::stringstream ss(userSentence);

    std::string word;

    std::vector<std::string> words;

    while (std::getline(ss, word, ' '))
    {
        words.push_back(word);
    }

    return words;
}


int main()
{
	std::string sentence;

	std::cout << "Please enter a complete sentence: " << std::endl;

	std::getline(std::cin, sentence);

    std::vector<std::string> words = splitSentence(sentence);

    for (std::string w : words) 
    {
        std::cout << w << std::endl;
    }

    return 0;
}