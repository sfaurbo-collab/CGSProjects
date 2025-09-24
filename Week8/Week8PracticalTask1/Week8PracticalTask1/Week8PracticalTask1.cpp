// Refactor the Person class and introduce inheritance with method overriding.
//
// Refactor the Person class from the previous week to include :
//	 - A constructor that initializes name and age.
//	 - A method GetName() that returns the name of the person.
// Create a Student class that inherits from Person and :
//	 - Adds a private member std::string courseName.
//	 - Implements a constructor to initialize name, age, and courseName.
//	 - Overrides the GetName() method to include the courseName in the output.
// Instantiate a Student object and call GetName() to demonstrate the method overriding.
// 
// Bonus Task :
//	Add a polymorphic behavior by defining a base class pointer Person* and store a Student object in it.Call the GetName() method to see the overridden behavior.