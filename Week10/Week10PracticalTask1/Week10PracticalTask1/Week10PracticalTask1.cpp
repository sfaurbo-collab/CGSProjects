#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

// Write a C++ program that sorts a list of integers using the "Bubble Sort" algorithm. Print out the sorted list.

void bubbleSort(std::vector<int>& arr) 
{
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) 
    {
        swapped = false;
        
        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        if (!swapped) {
            break;
        }
    }
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
    std::cout << std::endl;

    bubbleSort(numbers);

    std::cout << "Sorted vector: ";
    for (int x : numbers) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;

}