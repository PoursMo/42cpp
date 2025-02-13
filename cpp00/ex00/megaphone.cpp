#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 1)
	{
		argv++;
		while (*argv)
		{
			std::string strarg(*argv);
			for (size_t i = 0; i < strarg.size(); i++)
				std::cout << (char)std::toupper(strarg[i]);
			argv++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}
