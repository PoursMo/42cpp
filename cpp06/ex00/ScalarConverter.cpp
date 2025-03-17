#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <limits>

bool isChar(const std::string &literal)
{
	return literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool isInt(const std::string &literal)
{
	int i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while (literal[i])
	{
		if (!isdigit(literal[i]))
			return false;
		i++;
	}
	return true;
}

bool isDecimal(const std::string &literal, int size)
{
	int i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (!isdigit(literal[i]))
		return false;
	int dot = 0;
	while (i < size)
	{
		if ((!isdigit(literal[i]) && literal[i] != '.') || dot > 1)
			return false;
		if (literal[i] == '.')
			dot++;
		i++;
	}
	return true;
}

bool isFloat(const std::string &literal)
{
	return literal[literal.size() - 1] == 'f' && isDecimal(literal, literal.size() - 1);
}

bool isDouble(const std::string &literal)
{
	return isDecimal(literal, literal.size());
}

void printChar(char c)
{
	std::cout << "char: ";
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void convertChar(const std::string &literal)
{
	printChar(literal[1]);
	std::cout << "int: " << static_cast<int>(literal[1]) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(literal[1]) << std::endl;
	std::cout << "double: " << static_cast<double>(literal[1]) << std::endl;
}

void convertInt(const std::string &literal)
{
	int i = std::atoi(literal.c_str());
	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else
		printChar(static_cast<char>(i));
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void convertFloat(const std::string &literal)
{
	float f = std::strtof(literal.c_str(), 0);
	if (f < 0 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else
		printChar(static_cast<char>(f));
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void convertDouble(const std::string &literal)
{
	double d = std::atof(literal.c_str());
	if (d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else
		printChar(static_cast<char>(d));
	if (d > __INT_MAX__)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void convertPseudoFloat(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << (literal + "f") << std::endl;
	std::cout << "double: " << literal << std::endl;
}

void convertPseudoDouble(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << std::endl;
	std::cout << "double: ";
	std::cout.write(literal.c_str(), literal.size() - 1);
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (!literal.compare("-inf") || !literal.compare("+inf") || !literal.compare("nan"))
		convertPseudoFloat(literal);
	else if (!literal.compare("-inff") || !literal.compare("+inff") || !literal.compare("nanf"))
		convertPseudoDouble(literal);
	else if (isChar(literal))
		convertChar(literal);
	else if (isInt(literal))
		convertInt(literal);
	else if (isFloat(literal))
		convertFloat(literal);
	else if (isDouble(literal))
		convertDouble(literal);
	else
		std::cout << "invalid input" << std::endl;
}