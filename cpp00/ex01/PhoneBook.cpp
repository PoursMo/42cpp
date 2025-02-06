#include "PhoneBook.hpp"

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
		if (!contacts[i].empty())
		{
			std::cout << '|' << std::setw(10) << i;
			std::cout << '|' << std::setw(10) << truncated_string(contacts[i].first_name);
			std::cout << '|' << std::setw(10) << truncated_string(contacts[i].last_name);
			std::cout << '|' << std::setw(10) << truncated_string(contacts[i].nickname) << '|' << std::endl;
		}
	}
}

PhoneBook::PhoneBook()
{
	contact_index = 0;
}

bool has_digit(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if(!isdigit(str[i]))
			return false;
	}
	return true;
}

void PhoneBook::add_contact()
{
	while(contacts[contact_index].first_name.empty() && !std::cin.eof())
	{
		std::cout << "First name:" << std::endl;
		std::getline(std::cin, contacts[contact_index].first_name);
	}
	while(contacts[contact_index].last_name.empty() && !std::cin.eof())
	{
		std::cout << "Last name:" << std::endl;
		std::getline(std::cin, contacts[contact_index].last_name);
	}
	while(contacts[contact_index].nickname.empty() && !std::cin.eof())
	{
		std::cout << "Nickname:" << std::endl;
		std::getline(std::cin, contacts[contact_index].nickname);
	}
	while(contacts[contact_index].darkest_secret.empty() && !std::cin.eof())
	{
		std::cout << "Darkest secret:" << std::endl;
		std::getline(std::cin, contacts[contact_index].darkest_secret);
	}
	while ((contacts[contact_index].phone_number.empty() && !std::cin.eof()) || !has_digit(contacts[contact_index].phone_number))
	{
		std::cout << "Phone number:" << std::endl;
		std::getline(std::cin, contacts[contact_index].phone_number);
	}
	if (contact_index + 1 >= 8)
		contact_index = 0;
	else
		contact_index++;
}

void PhoneBook::search_contact()
{
	display_contacts();
	int i;
	std::cin >> i;
	std::cin.ignore(__INT32_MAX__, '\n');
	if (i < 0 || i > 7 || contacts[i].empty())
	{
		std::cout << "Not a valid index" << std::endl;
		return ;
	}
	contacts[i].display_contact();
}