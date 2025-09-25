#include<iostream>
#include<string>
#include<vector>
#include<memory>

// Work with abstract classes and implement polymorphic behavior.
//
// Create an abstract base class GameObject with :
//	 - A pure virtual function Interact().
//	 - The class should be abstract and cannot be instantiated.
// Derive three classes from GameObject :
//	 - Player with an overridden Interact() method that displays a player interaction message.
//	 - Enemy with an overridden Interact() method that displays an enemy interaction message.
//	 - Item with an overridden Interact() method that displays an item interaction message.
// Store objects of all three derived classes in a std::vector<GameObject*>.
// Iterate through the vector and call Interact() for each object, demonstrating polymorphism.
//
// Bonus Task :
//	Add additional derived classes(e.g., Weapon or NPC) and demonstrate extensibility of abstract classes.

class GameObject 
{
public:

    virtual void Interact() = 0;
    virtual ~GameObject() = default;
};

class Player : public GameObject
{
    void Interact() override
    {
        std::cout << "The player is interacting with The Game." << std::endl;
    }
};

class Enemy : public GameObject
{
    void Interact() override
    {
        std::cout << "The enemy is interacting with the Player." << std::endl;
    }
};

class Item : public GameObject
{
    void Interact() override
    {
        std::cout << "The item has been interacted with." << std::endl;
    }
};

int main()
{
    std::vector<std::unique_ptr<GameObject>> gameObjects;

    gameObjects.push_back(std::make_unique<Player>());
    gameObjects.push_back(std::make_unique<Enemy>());
    gameObjects.push_back(std::make_unique<Item>());

    for (const auto& obj : gameObjects) 
    {
        obj->Interact();
    }
}