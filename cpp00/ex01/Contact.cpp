#include "Contact.hpp"

void Contact::display_contact()
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
}

bool Contact::empty()
{
	return (first_name.empty()
		&& last_name.empty()
		&& nickname.empty()
		&& darkest_secret.empty()
		&& phone_number.empty());
}