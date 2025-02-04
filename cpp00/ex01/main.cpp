#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

void Contact::display_contact()
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
}

PhoneBook::PhoneBook()
{
	contact_index = 0;
}

void PhoneBook::add_contact()
{
	std::cout << "First name:" << std::endl;
	std::cin >> contacts[contact_index].first_name;
	std::cout << "Last name:" << std::endl;
	std::cin >> contacts[contact_index].last_name;
	std::cout << "Nickname:" << std::endl;
	std::cin >> contacts[contact_index].nickname;
	std::cout << "Darkest secret:" << std::endl;
	std::cin >> contacts[contact_index].darkest_secret;
	std::cout << "Phone number:" << std::endl;
	std::cin >> contacts[contact_index].phone_number;
	if (contact_index + 1 >= 8)
		contact_index = 0;
	else
		contact_index++;
}

bool is_empty_contact(Contact contact)
{
	return (contact.first_name.empty()
		&& contact.last_name.empty()
		&& contact.nickname.empty()
		&& contact.darkest_secret.empty()
		&& contact.phone_number.empty());
}

std::string truncated_string(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::display_contacts()
{
	for (int i = 0; i < 8; i++)
	{
		if (!is_empty_contact(contacts[i]))
		{
			std::cout << '|' << std::setw(10) << i;
			std::cout << '|' << std::setw(10) << truncated_string(contacts[i].first_name);
			std::cout << '|' << std::setw(10) << truncated_string(contacts[i].last_name);
			std::cout << '|' << std::setw(10) << truncated_string(contacts[i].nickname) << '|' << std::endl;
		}
	}
}

void search_contact(PhoneBook *book)
{
	book->display_contacts();
	int i;
	std::cin >> i;
	if (i < 0 || i > 7 || is_empty_contact(book->contacts[i]))
	{
		std::cout << "Not a valid index" << std::endl;
		return ;
	}
	book->contacts[i].display_contact();
}

int main()
{
	PhoneBook book;

	while (1)
	{
		std::string input;

		std::cout << "Type in your command (ADD, SEARCH, EXIT):" << std::endl;
		std::cin >> input;
		if (std::cin.eof())
			break ;
		if (!input.compare("ADD"))
			book.add_contact();
		if (!input.compare("SEARCH"))
			search_contact(&book);
		if (!input.compare("EXIT"))
			break ;
	}
	std::cout << "Your contacts are lost forever" << std::endl;
}
