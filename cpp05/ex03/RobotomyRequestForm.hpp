#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
private:
	const std::string target;
	void actualExecute() const;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &rhs);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
};

#endif