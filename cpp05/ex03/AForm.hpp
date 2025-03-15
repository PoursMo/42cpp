#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
	class NotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

protected:
	virtual void actualExecute() const = 0;

public:
	AForm();
	AForm(const std::string name, const int sign_grade, const int execute_grade);
	AForm(const AForm &rhs);
	virtual ~AForm();
	AForm &operator=(const AForm &rhs);
	std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	bool getIsSigned() const;
	void beSigned(const Bureaucrat &bureaucrat);
	void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &stream, const AForm &AForm);

#endif