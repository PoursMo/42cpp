#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
private:
	const std::string target;
	void actualExecute() const;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &rhs);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
};

#endif