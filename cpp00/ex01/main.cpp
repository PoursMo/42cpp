#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook book;

	while (1)
	{
		std::string input;

		std::cout << "Type in your command (ADD, SEARCH, EXIT):" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (!input.compare("ADD"))
			book.add_contact();
		if (!input.compare("SEARCH"))
			book.search_contact();
		if (!input.compare("EXIT"))
			break ;
	}
	std::cout << "Your contacts are lost forever" << std::endl;
}
