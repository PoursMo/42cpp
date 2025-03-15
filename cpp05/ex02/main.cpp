#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(NULL));
	Bureaucrat george("Boss George", 1);
	std::cout << george << std::endl;
	Bureaucrat john("Private John", 145);
	std::cout << john << std::endl;
	// *************************************************************
	std::cout << std::endl;
	AForm *form = new ShrubberyCreationForm("tree");
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
	form = new RobotomyRequestForm("Will Smith");
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
	form = new PresidentialPardonForm("Brad Pitt");
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