#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>

class Contact
{
	public:
		std::string first_name, last_name, nickname, darkest_secret, phone_number;
		void display_contact();
};

#endif