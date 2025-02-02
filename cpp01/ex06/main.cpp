#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}
	std::string strarg(argv[1]);
	if (strarg != "DEBUG" && strarg != "INFO" && strarg != "WARNING" && strarg != "ERROR")
	{
		std::cout << "[ " << "Probably complaining about insignificant problems" << " ]" << std::endl;
		return 0;
	}
	Harl harl;
	harl.complain(strarg);
}