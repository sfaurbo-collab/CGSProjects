// Objective: Create a branching text - based adventure game set in a haunted house. 
#include <iostream>

using namespace std;

enum Rooms
{
	Foyer,
	Conservatory,
	DiningRoom,
	Kitchen,
	Library,
	Lounge,
	Study,
	Stairs
};

// Design a game with at least 3 rooms or decision points.
// Each room must present 2-3 choices, leading to different outcomes.
// Use both if statements and switch statements to handle choices and outcomes.
// Track the player’s progress using variables.
// Required - Include at least one nested condition
// Required - Handle invalid input gracefully.
// Required - Ensure at least one path leads to a successful escape and one to a failure.

int main()
{
	int roomChoice;
	cout << "Welcome to the foyer of Blood Moon Estate. I hope you enjoy your stay.\n";
	cout << "-----------W-W-W-W--------------WW---WWW---WW---\n";
	cout << "|        |         |________|                  |\n";
	cout << "| Pantry D Kitchen |_Stairs_|   Dining Room    |\n";
	cout << "|        |         |________|                  |\n";
	cout << "|----------------D-|________|-D----------------|\n";
	cout << "|              |                |              W\n";
	cout << "W    Lounge    D                D   Library    |\n";
	cout << "|              |                |              W\n";
	cout << "|--------------|     Foyer      |--------------|\n";
	cout << "W              |                |              |\n";
	cout << "W Conservatory D       X        D     Study    W\n";
	cout << "W              |                |              |\n";
	cout << "-WWWWWWWWWWWWWW--------DD----------WW--WW--WW---\n";
	cout << "Legend: D = Door, W = Window, X=Player\n";
	cout << "1. Conservatory\n";
	cout << "2. Dining Room\n";
	cout << "3. Kitchen\n";
	cout << "4. Library\n";
	cout << "5. Lounge\n";
	cout << "6. Study\n";
	cout << "7. Take the stairs to the second floor\n";
	cout << "\nWhich room would you like to enter?: ";

	cin >> roomChoice;

	switch (roomChoice)
	{
	case Conservatory:
	{
		cout << "\nYou have entered the Conservatory. What do you do?\n";
		cout << "1. Investigate an odd looking plant.\n";
		cout << "2. Investigate one of the windows.\n";
		cout << "3. Attempt to smash a window with nearby small gardening tools.\n";
		cout << "Please enter your selection: ";
		int consChoice;
		cin >> consChoice;
		if (consChoice == 1)
		{
			cout << "\nCurrent Room: Conservatory\n" << endl;
			cout << "The plant releases a bloom of phytochemicals which are fatally toxic to humans when inhaled.\nYou unknowingly inhale the chemicals and succum to the effects of the toxin.\n";
		}
		else if (consChoice == 2)
		{
			cout << "\nCurrent Room: Conservatory\n" << endl;
			cout << "The floor to ceiling window panes do not have a way to be opened without breaking them.\n";
		}
		else if (consChoice == 3)
		{
			cout << "\nCurrent Room: Conservatory\n" << endl;
			cout << "The window breaks but you are badly injured from a large piece of broken glass.\nYou perform first aid on yourself and when you finish with the bandage, the glass has magically repaired itself.\n";
		}
		else
		{
			cout << "\nCurrent Room: Conservatory\n" << endl;
			cout << "There is no path this way. Please try again.\n";
		}
		break;
	}
	case DiningRoom:
	{
		cout << "\nYou have entered the Dining Room. What do you do?\n";
		cout << "1. Look for a hidden passageway.\n";
		cout << "2. Investigate the place settings on the table.\n";
		cout << "3. Investigate the windows.\n";
		cout << "Please enter your selection: ";
		int drChoice;
		cin >> drChoice;
		if (drChoice == 1)
		{
			cout << "\nCurrent Room: Dining Room\n" << endl;
			cout << "You find a hallway leading to the kitchen. Lit candle sconces line the hall, bathing the hall with an eerie glow.\n";
		}
		else if (drChoice == 2)
		{
			cout << "\nCurrent Room: Dining Room\n" << endl;
			cout << "You notice the table is set for a full course meal for a dozen people.\n";
		}
		else if (drChoice == 3)
		{
			cout << "\nCurrent Room: Dining Room\n" << endl;
			cout << "You attempt to open a window and when you touch the lever to unlock the window\na metal shutter instantly descend from the ceiling covering the windows.\n";
		}
		else
		{
			cout << "\nCurrent Room: Dining Room\n" << endl;
			cout << "There is no path this way. Please try again.\n";
		}
		break;
	}
	case Kitchen:
	{
		cout << "\nYou have entered the Kitchen. What do you do?\n";
		cout << "1. Look for a hidden passageway.\n";
		cout << "2. Gather some ingredients from the pantry and make some cookies.\n";
		cout << "3. Investigate the windows.\n";
		cout << "Please enter your selection: ";
		int kitChoice;
		cin >> kitChoice;
		if (kitChoice == 1)
		{
			cout << "\nCurrent Room: Kitchen\n" << endl;
			cout << "You find a hallway leading to the dining room. Lit candle sconces line the hall, bathing it with an eerie glow.\n";
		}
		else if (kitChoice == 2)
		{
			cout << "\nCurrent Room: Kitchen\n" << endl;
			cout << "You spend two hours making delicious cookies.\n";
			cout << "When they are done you eat one of the freshly baked cookies.\n";
			cout << "The cookie causes instant pain in your stomach and you keel over.\n";
			cout << "One of the ingredients was poisoned or cursed.\n";
			cout << "You pass out on the floor from the pain and wake up later with no memory of what just happened.\n";
			cout << "You feel hungry and notice a batch of cookies so you decide to eat another one.\n";
			cout << "This cycle continues until you finally succumb to the toxic ingredients.\n";
		}
		else if (kitChoice == 3)
		{
			cout << "\nCurrent Room: Kitchen\n" << endl;
			cout << "Many small windows line the wall but they do not appear to be big enough to escape out of.\n";
		}
		else
		{
			cout << "\nCurrent Room: Kitchen\n" << endl;
			cout << "There is no path this way. Please try again.\n";
		}
		break;
	}
	case Library:
	{
		cout << "\nYou have entered the Library. What do you do?\n";
		cout << "1. Look for a hidden passageway.\n";
		cout << "2. Sit down and read a book titled 'How to escape from Blood Moon Estate'.\n";
		cout << "3. Investigate the windows.\n";
		cout << "Please enter your selection: ";
		int libChoice;
		cin >> libChoice;
		if (libChoice == 1)
		{
			cout << "\nCurrent Room: Library\n" << endl;
			cout << "You pull an odd looking book from the shelf causing a hidden door to appear from behind the bookcase.\n";
			cout << "You follow the dark passage all the way to the end.\n";
			cout << "It lets you out on a nearby beach far from the haunted house.\n";
			cout << "Congratulations! You have escaped from Blood Moon Estate.\n";
		}
		else if (libChoice == 2)
		{
			cout << "\nCurrent Room: Library\n" << endl;
			cout << "As you read the book you notice it mirrors your experience in Blood Moon Estate.\n";
			cout << "Confused, you flip to the back of the book only to find blank pages.\n";
			cout << "You search for the part in the book where words meet blank pages.\n";
			cout << "You see words filling the pages, narrating your every thought and action.\n";
			cout << "You put the book down, questioning if what you just witnessed was real.\n";
		}
		else if (libChoice == 3)
		{
			cout << "\nCurrent Room: Library\n" << endl;
			cout << "You sense something off about the glass in the large windows.\n";
			cout << "You place your hand against one of them and notice it feels soft.\n";
			cout << "As you push your hand against the window, the glass gives way as if you were pushing your hand into honey.\n";
			cout << "You push until your shoulder is in line with the window frame yet your hand does not pass through the glass.\n";
			cout << "When you try to pull your hand back you face enormous resistance from the sticky glass.\n";
			cout << "After great effort, you are finally able to free your hand and the glass returns to its previous form as if you had never touched it.\n";
		}
		else
		{
			cout << "\nCurrent Room: Library\n" << endl;
			cout << "There is no path this way. Please try again.\n";
		}
		break;
	}
	case Lounge:
	{
		cout << "\nYou have entered the Lounge. What do you do?\n";
		cout << "1. Look for a hidden passageway.\n";
		cout << "2. Sit on the comfy looking furniture.\n";
		cout << "3. Investigate the window.\n";
		cout << "Please enter your selection: ";
		int louChoice;
		cin >> louChoice;
		if (louChoice == 1)
		{
			cout << "\nCurrent Room: Lounge\n" << endl;
			cout << "You find a closet with various board games neatly stacked inside.\n";
		}
		else if (louChoice == 2)
		{
			cout << "\nCurrent Room: Lounge\n" << endl;
			cout << "You activate a trap door and fall through.\n";
			cout << "When you land, you find yourself in a dark dungeon.\n";
			cout << "You look around and see there is no way of escape.\n";
		}
		else if (louChoice == 3)
		{
			cout << "\nCurrent Room: Lounge\n" << endl;
			cout << "The window is stained glass portraying the history of the house and residents that used to live here.\n";
			cout << "You think about smashing the glass but you feel as though doing so would bring about an unthinkable fate.\n";
		}
		else
		{
			cout << "\nCurrent Room: Lounge\n" << endl;
			cout << "There is no path this way. Please try again.\n";
		}
		break;
	}
	case Study:
	{
		cout << "\nYou have entered the Study. What do you do?\n";
		cout << "1. Look for a hidden passageway.\n";
		cout << "2. Investigate the desk.\n";
		cout << "3. Investigate the windows.\n";
		cout << "Please enter your selection: ";
		int stuChoice;
		cin >> stuChoice;
		if (stuChoice == 1)
		{
			cout << "\nCurrent Room: Study\n" << endl;
			cout << "You find a door small enough for a small animal to pass through.\nNot nearly big enough for you to fit through\n";
		}
		else if (stuChoice == 2)
		{
			cout << "\nCurrent Room: Study\n" << endl;
			cout << "You find various papers and books detailing the lives and business of the previous inhabitants.\n";
		}
		else if (stuChoice == 3)
		{
			cout << "\nCurrent Room: Study\n" << endl;
			cout << "Upon further inspection you can see the windows are covered in spider webs.\nYou notice several large spiders you’ve never seen before.\nYou do recognize the colours on the spidera indicate they could be venomous.\n";
		}
		else
		{
			cout << "\nCurrent Room: Study\n" << endl;
			cout << "There is no path this way. Please try again.\n";
		}
		break;
	}
	case Stairs:
	{
		cout << "\nOnce you ascend the stairs you notice you are back in the foyer.\n";
		break;
	}
	default:
	{
		cout << "\nThere is no path this way. Please try again.\n";
	}
	}
}
	// Track the player’s progress using variables.
