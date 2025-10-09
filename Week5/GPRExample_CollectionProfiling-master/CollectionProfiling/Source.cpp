// Includes
#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <deque>
#include <random>

// Constants
const int NUM_ELEMENTS = 1000000;

// Functions declarations
void ProfileBackInsertVector(std::vector<int>& vec);
void ProfileRandomAccessVector(std::vector<int>& vec);
void ProfileBackInsertList(std::list<int>& vec);
void ProfileFrontInsertList(std::list<int>& vec);
void ProfileBackInsertDeque(std::deque<int>& vec);
void ProfileFrontInsertDeque(std::deque<int>& vec);

// Functions Definitions
int main()
{
    std::vector<int> vec;
    ProfileBackInsertVector(vec);

    ProfileRandomAccessVector(vec);

    std::list<int> newList;

    ProfileBackInsertList(newList);

    ProfileFrontInsertList(newList);

    std::deque<int> newDeque;
    
    ProfileBackInsertDeque(newDeque);

    ProfileFrontInsertDeque(newDeque);
    
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> distribution(0, newDeque.size() - 1);

    std::vector<int> random_numbers;
    random_numbers.reserve(10);

    for (int i = 0; i < 10; ++i)
    {
        int random_index = distribution(gen);
        random_numbers.push_back(newDeque[random_index]);
    }

    std::cout << "Picked random numbers: ";
    for (int num : random_numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken pick 10 random numbers from std::deque: " << duration.count() << " ms\n";
}

void ProfileBackInsertVector(std::vector<int>& vec)
{
    // Start time
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    // Insert elements at the back
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.push_back(i);
    }

    // End time
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Duration
    std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken to insert at the back for std::vector: " << duration.count() << " ms\n";
}

void ProfileRandomAccessVector(std::vector<int>& vec)
{
    // Start time
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, vec.size() - 1);

    std::vector<int> random_numbers;
    random_numbers.reserve(10);

    for (int i = 0; i < 10; ++i) 
    {
        int random_index = distrib(gen);
        random_numbers.push_back(vec[random_index]);
    }

    std::cout << "Picked random numbers: ";
    for (int num : random_numbers) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // End time
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Duration
    std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken pick 10 random numbers from std::vector: " << duration.count() << " ms\n";
}

void ProfileBackInsertList(std::list<int>& vec)
{
    // Start time
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    // Insert elements at the back
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.push_back(i);
    }

    // End time
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Duration
    std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken to insert at the back for std::list: " << duration.count() << " ms\n";
}

void ProfileFrontInsertList(std::list<int>& vec)
{
    // Start time
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    // Insert elements at the back
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.push_front(i);
    }

    // End time
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Duration
    std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken to insert at the front for std::list: " << duration.count() << " ms\n";
}

void ProfileBackInsertDeque(std::deque<int>& vec)
{
    // Start time
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    // Insert elements at the back
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.push_back(i);
    }

    // End time
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Duration
    std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken to insert at the back for std::deque: " << duration.count() << " ms\n";
}

void ProfileFrontInsertDeque(std::deque<int>& vec)
{
    // Start time
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    // Insert elements at the back
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.push_front(i);
    }

    // End time
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Duration
    std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken to insert at the front for std::deque: " << duration.count() << " ms\n";
}