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
	return (first_name.empty() && last_name.empty() && nickname.empty() && darkest_secret.empty() && phone_number.empty());
}

std::string Contact::get_first_name()
{
	return first_name;
}

std::string Contact::get_last_name()
{
	return last_name;
}

std::string Contact::get_nickname()
{
	return nickname;
}

std::string Contact::get_darkest_secret()
{
	return darkest_secret;
}

std::string Contact::get_phone_number()
{
	return phone_number;
}

void Contact::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}

void Contact::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}

void Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void Contact::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

void Contact::set_phone_number(std::string phone_number)
{
	this->phone_number = phone_number;
}
