#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <string>

class PhoneBook
{
	private:
		int contact_index;
		Contact contacts[8];
		void display_contacts();

	public:
		PhoneBook();
		void add_contact();
		void search_contact();
};

#endif