#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[argc - 1]);
}