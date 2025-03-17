#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#define INT_MIN -2147483648

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &rhs);
	ScalarConverter &operator=(const ScalarConverter &rhs);
	~ScalarConverter();

public:
	static void convert(const std::string &literal);
};

#endif