#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

//Write a C++ program that measures the time it takes to perform a specific operation on a list of integers(e.g.a Bubble Sort).
//Then, modify the program to measure the time it takes to perform the same operation on a list that is twice as long.
//Use the results to calculate the time complexity of the algorithm and express it using Big O notation.

// Constants
const int NUM_ELEMENTS = 100000;
const int DOUBLE_NUM_ELEMENTS = 200000;

void ProfileBubbleSort(std::vector<int>& arr)
{
    // Start time
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

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

    // End time
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Duration
    std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken to bublle sort std::vector: " << duration.count() << " ms\n";
}

void BackInsertVectorOne(std::vector<int>& vec)
{
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        srand(time(0));
        
        const int MAX_CAPACITY = 1000;
        std::vector<int> numbers;
        numbers.reserve(MAX_CAPACITY);

        for (int i = 0; i < MAX_CAPACITY; i++)
        {
            int randomNum = rand() % 10001;

            numbers.push_back(randomNum);
        }
    }
}

void BackInsertVectorTwo(std::vector<int>& vec)
{
    for (int i = 0; i < DOUBLE_NUM_ELEMENTS; ++i)
    {
        srand(time(0));

        const int DOUBLE_MAX_CAPACITY = 2000;
        std::vector<int> numbers;
        numbers.reserve(DOUBLE_MAX_CAPACITY);

        for (int i = 0; i < DOUBLE_MAX_CAPACITY; i++)
        {
            int randomNum = rand() % 20001;

            numbers.push_back(randomNum);
        }
    }
}


int main()
{
    std::vector<int> vecOne;
    std::vector<int> vecTwo;

    BackInsertVectorOne(vecOne);
    BackInsertVectorTwo(vecTwo);

    ProfileBubbleSort(vecOne);
    ProfileBubbleSort(vecTwo);
}
