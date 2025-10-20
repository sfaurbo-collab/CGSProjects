#include <iostream>
#include <list>
#include <string>

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
    static Inventory* GetInventory()
    {
        if (Instance == nullptr)
        {
            Instance = new Inventory;
        }
        
        return Instance;
    }

    std::list<std::string> inventory;

    void addItem(std::string a)
    {
        inventory.push_back(a);
    }

    void removeItem(std::string r)
    {
        inventory.remove(r);
    }

    void viewInventory()
    {
        for (std::list<std::string>::iterator itx = inventory.begin(); itx != inventory.end(); ++itx)
        {
            std::cout << *itx << std::endl;
        }
    }

private:
    Inventory() {};

    static Inventory* Instance;
};

int main()
{
    Inventory& GetInventory();
    Inventory* playerInventory;
    playerInventory->addItem("Splint Armor");
    playerInventory->addItem("Fifty feet of Hemp Rope");
    playerInventory->addItem("Potion of Stone Giant Strength");
    playerInventory->addItem("Navigator's Tools");
    playerInventory->addItem("Scroll of Wish");
    playerInventory->addItem("Axe of the Dwarvish Lords");
    playerInventory->viewInventory();
    playerInventory->removeItem("Fifty feet of Hemp Rope");
    playerInventory->viewInventory();
}