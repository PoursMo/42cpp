#include "Form.hpp"

Form::Form() : name("default"), is_signed(false), sign_grade(1), execute_grade(1)
{
}
Form::Form(const std::string name, const int sign_grade, const int execute_grade) : name(name), is_signed(false), sign_grade(sign_grade), execute_grade(execute_grade)
{
	if (sign_grade > 150 || execute_grade > 150)
		throw Form::GradeTooLowException();
	if (sign_grade < 1 || execute_grade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &rhs) : name(rhs.name), is_signed(rhs.is_signed), sign_grade(rhs.sign_grade), execute_grade(rhs.execute_grade)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		this->is_signed = rhs.is_signed;
	}
	return *this;
}

std::string Form::getName() const
{
	return name;
}

int Form::getSignGrade() const
{
	return sign_grade;
}

int Form::getExecuteGrade() const
{
	return execute_grade;
}

bool Form::getIsSigned() const
{
	return is_signed;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > sign_grade)
		throw Form::GradeTooLowException();
	is_signed = true;
}


const char *Form::GradeTooHighException::what() const throw()
{
	return "Form: grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form: grade too low";
}

std::ostream &operator<<(std::ostream &stream, const Form &form)
{
	stream << form.getName() << ", form grade to sign: " << form.getSignGrade();
	stream << ", grade to execute: " << form.getExecuteGrade();
	stream << ", the form is " << (form.getIsSigned() ? "signed" : "not signed");
	return stream;
}
