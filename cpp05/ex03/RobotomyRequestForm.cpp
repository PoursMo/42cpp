#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : AForm("RobotomyRequestForm", 72, 45), target(rhs.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return *this;
}

void RobotomyRequestForm::actualExecute() const
{
	std::cout << "* bzzzzzzz bzzzzzzzzzzzzzzz *" << std::endl;
	if (std::rand() & 1)
		std::cout << target << " has been successfully robotomized !" << std::endl;
	else
		std::cout << "the robotomy on "<< target << " failed" <<std::endl;
}
