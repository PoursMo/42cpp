#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
	std::string first_name, last_name, nickname, darkest_secret, phone_number;

public:
	void display_contact();
	bool empty();

	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string get_darkest_secret();
	std::string get_phone_number();

	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_nickname(std::string nickname);
	void set_darkest_secret(std::string darkest_secret);
	void set_phone_number(std::string phone_number);
};

#endif