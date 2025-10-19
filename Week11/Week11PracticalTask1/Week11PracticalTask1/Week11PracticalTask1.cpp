#include <iostream>

// Learn to apply the State Pattern to manage object behaviour based on internal state.
// 
// Create a simple text - based game where the player controls a character.The character should have three states : resting, exploring, and fighting.
// Implement the State Pattern to manage the character's behaviour based on its current state. Each state should have:
//	 - Distinct actions and transitions(e.g., "fight" transitions from exploring to fighting).
//	 - A method to change states based on player input.
// Allow the player to input commands to interact with the game and observe how the character’s behaviour changes based on the state.

class Player;

class State
{
public:
    virtual void handleInput() = 0;
    virtual ~State() = default;
};

class RestState : public State
{
public:
    void handleInput() override
    {
        std::cout << "Player is resting." << std::endl;
    }
};

class ExploringState : public State
{
public:
    void handleInput() override
    {
        std::cout << "Player is exploring." << std::endl;
    }
};

class FightingState : public State
{
public:
    void handleInput() override
    {
        std::cout << "Player is fighting." << std::endl;
    }
};

class Player
{
private:
    State* currentState;

public:
    Player(State* initialState) : currentState(initialState) {}

    void setState(State* newState)
    {
        currentState = newState;
    }

    void input()
    {
        currentState->handleInput();
    }
};

int main()
{
    RestState rest;
    ExploringState explore;
    FightingState fight;

    Player player(&rest);
    player.input();
    player.setState(&explore);
    player.input();
    player.setState(&fight);
    player.input();
    player.setState(&rest);
    player.input();
}