#include <iostream>
#include <string>

// Use classes and object-oriented programming to create a basic game object system.
// Define a class GameObject with attributes such as std::string name and int health. DONE
// Implement a parameterized constructor to initialize the object. DONE
// Implement member functions for :
//	 - TakeDamage() to reduce health.
//	 - Heal() to restore health.
//	 - DisplayInfo() to print the current state(name and health). DONE
// Create a Player class that inherits from GameObject and adds new functionality, such as int experiencePoints and a levelUp() function.
// Demonstrate polymorphism by overriding the DisplayInfo() function in the Player class.
// Bonus Task :
//	Implement a destructor in both classes to track when the objects are destroyed.

class GameObject
{
private:
	
	std::string name;
	int health;
	int energy;

public:

	GameObject()
	{
		name = "Unknown";
		health = 0;
		energy = 0;
	}

	GameObject(std::string n, int h, int e)
	{
		name = n;
		health = h;
		energy = e;
	}

	std::string getName()
	{
		return name;
	}

	int getHealth()
	{
		return health;
	}

	int getEnergy()
	{
		return energy;
	}

	void setName(std::string n)
	{
		name = n;
	}

	void setHealth(int h)
	{
		health = h;
	}

	void setEnergy(int e)
	{
		energy = e;
	}

	void TakeDamage(int damage)
	{
		health = health - damage;
	}

	void Heal(int sanative)
	{
		health = health + sanative;
	}

	void Rest(int sleep)
	{
		energy = energy + sleep;
	}

	void DisplayInfo() //print the current state(name and health).
	{
		std::cout << "Player name: " << name << std::endl;
		std::cout << "Player health: " << health << std::endl;
		std::cout << "Player energy: " << energy << std::endl;
	}

	~GameObject()
	{
		std::cout << "Object destroyed: " << name << std::endl;
	}
};

class Player : public GameObject
{
private:
	int experiencePoints;
	int currentLevel;
	int levelOneExp = 100;
	int levelTwoExp = 380;
	int levelThreeExp = 770;
	int levelFourExp = 1300;
	int levelFiveExp = 2150;
	int levelSixExp = 3300;
	int levelSevenExp = 4800;
	int levelEightExp = 6900;
	int levelNineExp = 10000;
	int levelTenExp = 15000;

public:

	Player()
	{
		experiencePoints = 0;
		currentLevel = 0;
	}

	Player(int p, int l)
	{
		experiencePoints = p;
		currentLevel = l;
	}
	
	int getExperiencePoints()
	{
		return experiencePoints;
	}

	int getCurrentLevel()
	{
		return currentLevel;
	}

	void setExperiencePoints(int p)
	{
		experiencePoints = p;
	}

	void setCurrentLevel(int l)
	{
		currentLevel = l;
	}

	void experience(int experience)
	{
		experiencePoints = experiencePoints + experience;
		std::cout << "You gained " << experience << " XP." << std::endl;
		levelUp();
	}

	void levelUp()
	{
		if (experiencePoints < levelOneExp)
		{
			currentLevel = 0;
			std::cout << "Current player Level: 0" << std::endl;
			std::cout << std::endl;
		}
		else if (experiencePoints < levelTwoExp)
		{
			currentLevel = 1;
			std::cout << "Current player Level: 1" << std::endl;
			std::cout << std::endl;
		}
		else if (experiencePoints < levelThreeExp)
		{
			currentLevel = 2;
			std::cout << "Current player Level: 2" << std::endl;
			std::cout << std::endl;
		}
		else if (experiencePoints < levelFourExp)
		{
			currentLevel = 3;
			std::cout << "Current player Level: 3" << std::endl;
			std::cout << std::endl;
		}
		else if (experiencePoints < levelFiveExp)
		{
			currentLevel = 4;
			std::cout << "Current player Level: 4" << std::endl;
			std::cout << std::endl;
		}
		else if (experiencePoints < levelSixExp)
		{
			currentLevel = 5;
			std::cout << "Current player Level: 5" << std::endl;
			std::cout << std::endl;
		}
		else if (experiencePoints < levelSevenExp)
		{
			currentLevel = 6;
			std::cout << "Current player Level: 6" << std::endl;
			std::cout << std::endl;
		}
		else if (experiencePoints < levelEightExp)
		{
			currentLevel = 7;
			std::cout << "Current player Level: 7" << std::endl;
			std::cout << std::endl;
		}
		else if (experiencePoints < levelNineExp)
		{
			currentLevel = 8;
			std::cout << "Current player Level: 8" << std::endl;
			std::cout << std::endl;
		}
		else if (experiencePoints < levelTenExp)
		{
			currentLevel = 9;
			std::cout << "Current player Level: 9" << std::endl;
			std::cout << std::endl;
		}
		else if (experiencePoints > levelTenExp)
		{
			currentLevel = 10;
			std::cout << "Current player Level: 10" << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Player Level Unknown" << std::endl;
			std::cout << std::endl;
		}
	}

	void DisplayInfo()
	{
		std::cout << "Player Name: " << &GameObject::getName << std::endl;
		std::cout << "Player Health: " << &GameObject::getHealth << std::endl;
		std::cout << "Player Energy: " << &GameObject::getEnergy << std::endl;
		std::cout << "Total Experience Points: " << &Player::getExperiencePoints << std::endl;
		std::cout << "Player Level: " << &Player::getCurrentLevel << std::endl;
	}

	~Player()
	{
		std::cout << "Object destroyed: " << &GameObject::getName << std::endl;
	}
};

int main()
{
	Player player;
	player.setName("Steven");
	player.setHealth(100);
	player.setEnergy(125);
	player.setExperiencePoints(0);
	player.setCurrentLevel(0);
	player.experience(10);
	player.DisplayInfo();
}