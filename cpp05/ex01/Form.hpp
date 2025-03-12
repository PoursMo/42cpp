#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool is_signed;
	const int sign_grade;
	const int execute_grade;
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

public:
	Form();
	Form(const std::string name, const int sign_grade, const int execute_grade);
	Form(const Form &rhs);
	~Form();
	Form operator=(const Form &rhs);
	std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	bool getIsSigned() const;
	void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &stream, const Form &form);

#endif