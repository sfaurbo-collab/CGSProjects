#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

//Write a C++ program that takes in a sorted list of integers and uses the binary search algorithm to find a specific value in the list.Print out the index of the value if it is found, or a message indicating that the value was not found.

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

int binarySearch(const std::vector<int>& arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else {
            high = mid - 1;
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
    std::cout << std::endl;

    bubbleSort(numbers);

    //std::cout << "Sorted vector: ";
    //for (int x : numbers) {
    //    std::cout << x << ", ";
    //}

    int searchNumber;

    std::cout << "Enter a number to search for from the sorted vector: ";
    std::cin >> searchNumber;

    int index = binarySearch(numbers, searchNumber);

    if (index != -1) 
    {
        std::cout << "The number " << searchNumber << " has been found at index: " << index << std::endl;
    }
    else 
    {
        std::cout << "The number " << searchNumber << " was not found in the list." << std::endl;
    }

}