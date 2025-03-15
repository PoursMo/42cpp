#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(std::time(NULL));
	Bureaucrat george("Boss George", 1);
	std::cout << george << std::endl;
	Bureaucrat john("Private John", 145);
	std::cout << john << std::endl;
	Intern someRandomIntern;
	AForm *form;
	// *************************************************************
	std::cout << std::endl;
	form = someRandomIntern.makeForm("not found", "test");
	// *************************************************************
	std::cout << std::endl;
	form = someRandomIntern.makeForm("shrubbery creation", "tree");
	std::cout << *form << std::endl;
	john.executeForm(*form);
	george.executeForm(*form);
	john.signForm(*form);
	george.signForm(*form);
	john.executeForm(*form);
	george.executeForm(*form);
	delete form;
	// *************************************************************
	std::cout << std::endl;
	form = someRandomIntern.makeForm("robotomy request", "Will Smith");
	std::cout << *form << std::endl;
	john.executeForm(*form);
	george.executeForm(*form);
	john.signForm(*form);
	george.signForm(*form);
	john.executeForm(*form);
	george.executeForm(*form);
	delete form;
	// *************************************************************
	std::cout << std::endl;
	form = someRandomIntern.makeForm("presidential pardon", "Brad Pitt");
	std::cout << *form << std::endl;
	john.executeForm(*form);
	george.executeForm(*form);
	john.signForm(*form);
	george.signForm(*form);
	john.executeForm(*form);
	george.executeForm(*form);
	delete form;
	// *************************************************************
}