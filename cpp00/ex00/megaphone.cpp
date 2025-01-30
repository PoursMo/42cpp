#include <iostream>

int main(int argc, char **argv)
{
	if(argc != 1)
	{
		argv++;
		while(*argv)
		{
			while(**argv)
			{
				std::cout << (char)toupper(**argv);
				(*argv)++;
			}
			argv++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}