#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : AForm("ShrubberyCreationForm", 145, 137), target(rhs.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return *this;
}

void ShrubberyCreationForm::actualExecute() const
{
	std::ofstream file((target + "_shrubbery").c_str());
	if (file)
	{
		file	<< "             .o00o\n"
				<< "           o000000oo\n"
				<< "          00000000000o\n"
				<< "         00000000000000\n"
				<< "      oooooo  00000000  o88o\n"
				<< "   ooOOOOOOOoo  ```''  888888\n"
				<< " OOOOOOOOOOOO'.qQQQQq. `8888'\n"
				<< "oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n"
				<< "OOOOOOOOOO'.QQQQQQQQQQ/ /q\n"
				<< " OOOOOOOOO QQQQQQQQQQ/ /QQ\n"
				<< "   OOOOOOOOO `QQQQQQ/ /QQ'\n"
				<< "     OO:F_P:O `QQQ/  /Q'\n"
				<< "        \\. \\ |  // |\n"
				<< "        d\\ \\\\|_////\n"
				<< "        qP| \\\\ _' `|Ob\n"
				<< "           \\  / \\  \\Op\n"
				<< "           |  | O| |\n"
				<< "   _       /\\. \\_/ /\\\n"
				<< "    `---__/|_\\\\   //|  __\n"
				<< "          `-'  `-'`-'-'\n";
		file.close();
	}
	else
	{
		std::cerr << "Error: Could not create file " << target + "_shrubbery" << std::endl;
	}
}
