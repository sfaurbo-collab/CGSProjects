#include <iostream>
#include <string>

// Learn to apply the State Pattern to manage object behaviour based on internal state.
// 
// Create a simple text - based game where the player controls a character.The character should have three states : resting, exploring, and fighting.
// Implement the State Pattern to manage the character's behaviour based on its current state. Each state should have:
//	 - Distinct actions and transitions(e.g., "fight" transitions from exploring to fighting).
//	 - A method to change states based on player input.
// Allow the player to input commands to interact with the game and observe how the character’s behaviour changes based on the state.

class Player
{
    std::string player;
};

class Input
{
public:
    Input() 
    {
        int exploring = 0;
        int fighting = 0;
    };


    
};

class PlayerState
{
public:
    virtual ~PlayerState() {}
    virtual void handleInput(Player& player, Input input) {}
};

class ExploringState : public PlayerState
{
public:
    ExploringState() {}

    virtual void handleInput(Player& player, Input input)
    {
        if (input == 1)
        {
            std::cout << "The player is exploring." << std::endl;
        }
    }
};

class FightingState : public PlayerState
{
public:
    FightingState() {}

    virtual void handleInput(Player& player, Input input)
    {
        if (input == 2)
        {
            std::cout << "The player is fighting." << std::endl;
        }
    }
};

int main()
{

}