#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	int contact_index;

	public:
		Contact contacts[8];
		PhoneBook();
		void add_contact();
		void display_contacts();
};

#endif