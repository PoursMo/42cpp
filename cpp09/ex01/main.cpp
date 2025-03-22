#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "no input" << std::endl;
		return 1;
	}
	RPN(std::string(argv[1]));
}