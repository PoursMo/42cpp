#include "ScavTrap.hpp"

int main()
{
	ScavTrap ct("George");
	ct.beRepaired(20);
	ct.attack("John");
	ct.guardGate();
	ct.takeDamage(150);
	ct.attack("John");
	ct.beRepaired(20);
	ct.guardGate();

	ct = ScavTrap("William");
	for (size_t i = 0; i < 51; i++)
	{
		ct.attack("John");
	}
	ct.beRepaired(20);
	ct.guardGate();
}