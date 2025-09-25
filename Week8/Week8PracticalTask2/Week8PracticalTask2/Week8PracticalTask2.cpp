#include<iostream>
#include<string>
#include<vector>
#include<memory>

// Use virtual functions and demonstrate runtime polymorphism.
//
// Refactor the Player and Enemy classes from Task 3 to :
//	 - Introduce a base class Entity with a virtual Attack() function.
//	 - Both Player and Enemy should override Attack() with their specific implementations.
// Create a collection of Entity * pointers, mixing Player and Enemy objects, and iterate through the collection, calling Attack() for each.
// Demonstrate the polymorphism of the Attack() method by showing how the base class pointer calls the correct derived class method.
// 
// Bonus Task :
//	Compare the behavior when Attack() is non - virtual (comment out virtual keyword) and see the difference in how the methods are called.


class GameObject
{
public:

    virtual void Interact() = 0;
    virtual ~GameObject() = default;
};

class Entity 
{
public:
    
    virtual void Attack()
    {
        std::cout << "An attack has been made." << std::endl;
    }

    virtual ~Entity() = default;
};

class Player : public GameObject, public Entity
{
public:

    void Interact() override
    {
        std::cout << "The player is interacting with The Game." << std::endl;
    }
    
    void Attack() override
    {
        std::cout << "The player attacks the enemy." << std::endl;
    }
};

class Enemy : public GameObject, public Entity
{
public:

    void Interact() override
    {
        std::cout << "The enemy is interacting with the Player." << std::endl;
    }
    
    void Attack() override
    {
        std::cout << "The enemy attacks the player." << std::endl;
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
    std::vector<std::unique_ptr<Entity>> gameObjects;

    gameObjects.push_back(std::make_unique<Player>());
    gameObjects.push_back(std::make_unique<Enemy>());
    gameObjects.push_back(std::make_unique<Player>());
    gameObjects.push_back(std::make_unique<Enemy>());
    gameObjects.push_back(std::make_unique<Player>());
    gameObjects.push_back(std::make_unique<Enemy>());
    gameObjects.push_back(std::make_unique<Player>());
    gameObjects.push_back(std::make_unique<Enemy>());
    gameObjects.push_back(std::make_unique<Player>());
    gameObjects.push_back(std::make_unique<Enemy>());

    for (auto& obj : gameObjects)
    {
        obj->Attack();
    }

    std::cout << std::endl;

    Entity entity;
    Player player;
    Enemy enemy;

    Entity* entityPtr1 = &entity;
    entityPtr1->Attack();

    Player* playerPtr2 = &player;
    playerPtr2->Attack();

    Enemy* enemyPtr3 = &enemy;
    enemyPtr3->Attack();
}