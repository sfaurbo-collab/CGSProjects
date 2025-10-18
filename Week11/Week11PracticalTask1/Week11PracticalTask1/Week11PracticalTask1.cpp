#include <iostream>
#include <string>

// Learn to apply the State Pattern to manage object behaviour based on internal state.
// 
// Create a simple text - based game where the player controls a character.The character should have three states : resting, exploring, and fighting.
// Implement the State Pattern to manage the character's behaviour based on its current state. Each state should have:
//	 - Distinct actions and transitions(e.g., "fight" transitions from exploring to fighting).
//	 - A method to change states based on player input.
// Allow the player to input commands to interact with the game and observe how the character’s behaviour changes based on the state.

class PlayerState
{
public:
    virtual void handleRequest() = 0;
    virtual void transitionToNextState(class Player* state) = 0;
    virtual ~PlayerState() {}
};


class Player
{
private:
    PlayerState* currentState;
public:
    Player(PlayerState* initialState) : currentState(initialState) {}

    void setState(PlayerState* newState)
    {
        delete currentState;
        currentState = newState;
    }

    void request()
    {
        currentState->handleRequest();
    }

    void change()
    {
        currentState->transitionToNextState(this);
    }

    ~Player()
    {
        delete currentState;
    }
};

class RestState : public PlayerState
{
public:
    void handleRequest() override 
    {
        std::cout << "The player is resting." << std::endl;
    }
    void transitionToNextState(Player* state) override
    {
        state->setState(new ExploringState());
    }
};

class ExploringState : public PlayerState
{
public:
    void handleRequest() override 
    {
        std::cout << "The player is exploring." << std::endl;
    }
    void transitionToNextState(Player* state) override
    {
        state->setState(new FightingState());
    }
};

class FightingState : public PlayerState
{
public:
    void handleRequest() override 
    {
        std::cout << "The player is fighting." << std::endl;
    }
    void transitionToNextState(Player* state) override
    {
        state->setState(new RestState());
    }
};

int main()
{

}