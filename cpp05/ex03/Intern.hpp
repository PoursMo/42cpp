#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

struct FormType
{
	std::string name;
	AForm *(*create)(const std::string &target);
};
extern const FormType formTypes[];

class Intern
{
public:
	Intern();
	Intern(const Intern &rhs);
	~Intern();
	Intern &operator=(const Intern &rhs);
	AForm *makeForm(const std::string &name, const std::string &target);
};

#endif