// Includes
#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <deque>

// Constants
const int NUM_ELEMENTS = 1000000;

// Functions declarations
void ProfileBackInsertVector(std::vector<int>& vec);


// Functions Definitions
int main()
{
    std::vector<int> vec;
    ProfileBackInsertVector(vec);

    // TODO: Profile RandomAccessVector

    // TODO: Create list
    std::list<int> newList;

    // TODO: ProfileBackInsertList
    

    // TODO: ProfileFrontInsertList


    // TODO: Create deque
    std::deque<int> newDeque;
    
    // TODO: ProfileBackInsertDeque
    
    
    // TODO: ProfileFrontInsertDeque
    
    
    // TODO: ProfileRandomAccessDeque

    return 0;
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