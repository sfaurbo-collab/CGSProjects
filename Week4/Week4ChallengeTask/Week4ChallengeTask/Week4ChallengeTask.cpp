#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

// Objective: Work with file I/O, 2D arrays, and nested loops to create a simple maze renderer.
// 1. Write a program that :
//	- Loads the contents of the provided Maze.txt file into a 2D array.
//	- Draws the loaded maze into the console using nested loops.
// Optional Extension :
//	- Add a function to find a path from the Start(S) to the End(E) in the maze.
//	- Modify the maze to include the path and display it in the console.

using namespace std;

int main()
{
    const int MAX_ROWS = 11;
    const int MAX_COLS = 18;
    char maze[MAX_ROWS][MAX_COLS];
    int currentRow = 0;
    int currentColumn = 0;
    
    ifstream render("Maze.txt");
   
    string line;
    while (currentRow < MAX_ROWS && getline(render, line)) 
    {
        if (line.length() < MAX_COLS) 
        {
            strcpy_s(maze[currentRow], MAX_COLS, line.c_str());
            currentRow++;
        }
        else 
        {
            cerr << "Warning: Line too long, truncated or skipped." << endl;
        }
    }

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            render >> maze[i][j];
            cout << maze[i][j] << "\n";
        }
    }
    render.close();
}