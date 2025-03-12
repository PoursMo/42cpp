#include "Bureaucrat.hpp"

int main()
{
// *********************************************************
	try
	{
		Bureaucrat b;
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
// *********************************************************
	std::cout << std::endl;
	try
	{
		Bureaucrat b("Johnny", 1);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
// *********************************************************
	std::cout << std::endl;
	try
	{
		Bureaucrat b("Patrick", 160);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
// *********************************************************
}