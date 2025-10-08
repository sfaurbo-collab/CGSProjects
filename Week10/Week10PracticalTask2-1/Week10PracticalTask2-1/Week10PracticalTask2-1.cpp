#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

//Write a C++ program that takes in a list of integers and uses the linear search algorithm to find a specific value in the list. Print out the index of the value if it is found, or a message indicating that the value was not found.

int linearSearch(const std::vector<int>& list, int targetValue) 
{
    for (int i = 0; i < list.size(); ++i) 
    {
        if (list[i] == targetValue) {
            return i;
        }
    }
    return -1; 
}

int main()
{
    std::random_device random;

    std::mt19937 generate(random());

    std::uniform_int_distribution<> dist(1, 1000);

    std::vector<int> numbers;
    int MAX_Elements = 25;

    for (int i = 0; i < MAX_Elements; ++i)
    {
        numbers.push_back(dist(generate));
    }

    std::cout << "Original vector: ";
    for (int num : numbers)
    {
        std::cout << num << ", ";
    }

    std::cout << std::endl;

    int searchValue;

    std::cout << "From the original vector, please select a number to find: ";
    std::cin >> searchValue;

    int index = linearSearch(numbers, searchValue);

    if (index != -1) {
        std::cout << "Value " << searchValue << " found at index: " << index << std::endl;
    }
    else {
        std::cout << "Value " << searchValue << " not found in the list." << std::endl;
    }

}