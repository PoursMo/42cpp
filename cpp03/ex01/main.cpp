#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct("George");
	ct.beRepaired(20);
	ct.attack("John");
	ct.takeDamage(100);
	ct.attack("John");
	ct.beRepaired(20);
	
	ct = ClapTrap("William");
	for (size_t i = 0; i < 11; i++)
	{
		ct.attack("John");
	}
	ct.beRepaired(20);
}