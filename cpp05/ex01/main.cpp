#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat george("George", 10);
	std::cout << george << std::endl;
	try
	{
		Form form("Formy", 151, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Form form("Formy", 150, 150);
	std::cout << form << std::endl;
	george.signForm(form);
	std::cout << form << std::endl;
	Form big_form("Big Formy", 1, 1);
	std::cout << big_form << std::endl;
	george.signForm(big_form);
}