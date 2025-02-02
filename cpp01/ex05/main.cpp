#include <iostream>
#include "Harl.hpp"

int main()
{
	Harl harl;
	harl.complain("test");
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
}