#include "Intern.hpp"

static AForm *createShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *createRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm *createPresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

const FormType formTypes[] = {
	{"shrubbery creation", createShrubberyCreationForm},
	{"robotomy request", createRobotomyRequestForm},
	{"presidential pardon", createPresidentialPardonForm},
	{"", 0},
};

Intern::Intern()
{
}

Intern::Intern(const Intern &rhs)
{
	(void)rhs;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	for (int i = 0; !formTypes[i].name.empty(); i++)
	{
		if (formTypes[i].name == name)
			return formTypes[i].create(target);
	}
	std::cout << "form not found" << std::endl;
	return 0;
}
