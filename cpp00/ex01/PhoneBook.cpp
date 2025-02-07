#include "PhoneBook.hpp"

static std::string truncated_string(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

static bool is_valid_number(std::string str)
{
	if(str.empty())
		return false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if(!std::isdigit(str[i]) && str[i] != ' ')
			return false;
	}
	return true;
}

static std::string get_element(std::string message)
{
	std::string element;
	while(element.empty() && !std::cin.eof())
	{
		std::cout << message << std::endl;
		std::getline(std::cin, element);
	}
	return element;
}

PhoneBook::PhoneBook() : contact_index(0)
{
}

void PhoneBook::display_contacts()
{
	for (int i = 0; i < 8; i++)
	{
		if (!contacts[i].empty())
		{
			std::cout << '|' << std::setw(10) << i;
			std::cout << '|' << std::setw(10) << truncated_string(contacts[i].get_first_name());
			std::cout << '|' << std::setw(10) << truncated_string(contacts[i].get_last_name());
			std::cout << '|' << std::setw(10) << truncated_string(contacts[i].get_nickname()) << '|' << std::endl;
		}
	}
}

void PhoneBook::add_contact()
{
	contacts[contact_index].set_first_name(get_element("First name:"));
	contacts[contact_index].set_last_name(get_element("Last name:"));
	contacts[contact_index].set_nickname(get_element("Nickname:"));
	contacts[contact_index].set_darkest_secret(get_element("Darkest secret:"));
	while (!is_valid_number(contacts[contact_index].get_phone_number()) && !std::cin.eof())
		contacts[contact_index].set_phone_number(get_element("Phone number:"));
	if (contact_index + 1 >= 8)
		contact_index = 0;
	else
		contact_index++;
}

void PhoneBook::search_contact()
{
	display_contacts();
	std::string index = get_element("Index:");
	int i = index[0] - '0';
	if (i < 0 || i > 7 || contacts[i].empty())
	{
		std::cout << "Not a valid index" << std::endl;
		return ;
	}
	contacts[i].display_contact();
}