#include <iostream>

//Learn to implement the Factory Pattern for object creation.
//
//Build a text - based character creation system for a role - playing game.
//Implement a character factory that generates different types of characters, such as :
//	 - warrior, mage, and archer.
//Each character type should have :
//	 - Specific attributes(e.g., health, mana, attack) and abilities(e.g., spellcasting, archery).
//Use the Factory Pattern to create new characters based on user input or predefined options.
//Allow the player to customise and create characters through the console and display the created character's attributes and abilities.

class Character 
{
public:
    virtual void type() = 0;
    virtual ~Character() {}
};

class Warrior : public Character 
{
public:
    void type() override 
    {
        std::cout << "The player has chosen to be a Warrior." << std::endl;
    }
};

class Mage : public Character
{
public:
    void type() override
    {
        std::cout << "The player has chosen to be a Mage." << std::endl;
    }
};

class Archer : public Character
{
public:
    void type() override
    {
        std::cout << "The player has chosen to be an Archer." << std::endl;
    }
};

class CharacterCreator 
{
public:
    virtual Character* createCharacter() = 0;
    virtual ~CharacterCreator() {}
};

class CreateWarrior : public CharacterCreator 
{
public:
    Character* createCharacter() override 
    {
        return new Warrior();
    }
};

class CreateMage : public CharacterCreator
{
public:
    Character* createCharacter() override
    {
        return new Mage();
    }
};

class CreateArcher : public CharacterCreator
{
public:
    Character* createCharacter() override
    {
        return new Archer();
    }
};

int main()
{
    
}