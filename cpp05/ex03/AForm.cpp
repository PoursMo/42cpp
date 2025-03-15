#include "AForm.hpp"

AForm::AForm() : name("default"), is_signed(false), sign_grade(1), execute_grade(1)
{
}
AForm::AForm(const std::string name, const int sign_grade, const int execute_grade) : name(name), is_signed(false), sign_grade(sign_grade), execute_grade(execute_grade)
{
	if (sign_grade > 150 || execute_grade > 150)
		throw AForm::GradeTooLowException();
	if (sign_grade < 1 || execute_grade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &rhs) : name(rhs.name), is_signed(rhs.is_signed), sign_grade(rhs.sign_grade), execute_grade(rhs.execute_grade)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		this->is_signed = rhs.is_signed;
	}
	return *this;
}

std::string AForm::getName() const
{
	return name;
}

int AForm::getSignGrade() const
{
	return sign_grade;
}

int AForm::getExecuteGrade() const
{
	return execute_grade;
}

bool AForm::getIsSigned() const
{
	return is_signed;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > sign_grade)
		throw AForm::GradeTooLowException();
	is_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!is_signed)
		throw AForm::NotSignedException();
	if (executor.getGrade() > execute_grade)
		throw AForm::GradeTooLowException();
	actualExecute();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm: grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm: grade too low";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "AForm: form is not signed";
}

std::ostream &operator<<(std::ostream &stream, const AForm &AForm)
{
	stream << AForm.getName() << ", AForm grade to sign: " << AForm.getSignGrade();
	stream << ", grade to execute: " << AForm.getExecuteGrade();
	stream << ", the AForm is " << (AForm.getIsSigned() ? "signed" : "not signed");
	return stream;
}
