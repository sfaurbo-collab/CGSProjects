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