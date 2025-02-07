#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	FragTrap ct("George");
	ct.beRepaired(20);
	ct.attack("John");
	ct.takeDamage(150);
	ct.attack("John");
	ct.beRepaired(20);
	
	ct = FragTrap("William");
	for (size_t i = 0; i < 11; i++)
	{
		ct.attack("John");
	}
	ct.beRepaired(20);
}