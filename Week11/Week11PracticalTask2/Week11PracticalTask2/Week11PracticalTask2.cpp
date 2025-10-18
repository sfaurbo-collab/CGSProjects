#include <iostream>

// Learn to implement the Singleton Pattern for managing global access to a single instance.
// 
// Create a text - based inventory system for a game where the player can collect and manage items.
// Implement a Singleton class to represent the inventory manager.The inventory manager should :
//	 - Maintain a list of collected items.
//	 - Provide methods for adding, removing, and displaying items.
//	 - Ensure only one instance of the inventory manager exists throughout the game.
// Allow the player to interact with the inventory system using console commands, such as :
//	 - add items, remove items, or view inventory contents.
// Use the Singleton pattern to guarantee the inventory manager is globally accessible and unique.

class Inventory
{
public:
    static Inventory& instance()
    {
        static Inventory* instance = new Inventory();
        return *instance;
    }

private:
    Inventory() {}
};

int main()
{

}