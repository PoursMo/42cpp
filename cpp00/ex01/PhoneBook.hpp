#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <string>

class PhoneBook
{
	int contact_index;

	public:
		Contact contacts[8];
		PhoneBook();
		void add_contact();
		void display_contacts();
		void search_contact();
};

#endif