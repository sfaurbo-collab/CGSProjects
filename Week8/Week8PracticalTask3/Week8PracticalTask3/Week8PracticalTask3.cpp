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