#include <iostream>
#include <string>

// Work with constructors, destructors, and member functions.
// Create a class Book with the following attributes :
//	 - std::string title
//	 - std::string author
//	 - int pages
// Define a parameterised constructor to initialise these attributes.
// Implement a destructor to print a message when the object is destroyed.
// Implement a member function to display the book’s details(title, author, pages).
// Create an instance of the Book class and call the member function to display its information.

class Book
{
public:
	std::string title;
	std::string author;
	int pages;

	Book()
	{
		title = "Unknown";
		author = "Unknown";
		pages = 0;
	}

	Book(std::string t, std::string a, int p)
	{
		title = t;
		author = a;
		pages = p;
	}

	void DisplayBookInfo()
	{
		std::cout << "Title: " << title << std::endl;
		std::cout << "Author: " << author << std::endl;
		std::cout << "Pages: " << pages << std::endl;
	}

	~Book()
	{
		std::cout << "Object destroyed: " << title << std::endl;
	}
};

int main()
{
	Book book1("Red Rising", "Brown, Pierce", 382);
	book1.DisplayBookInfo();
}