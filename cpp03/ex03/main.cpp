#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap dt("William");
	dt.print_stats();
	dt.whoAmI();
	dt.attack("John");
	dt.guardGate();
	dt.highFivesGuys();
	std::cout << std::endl
			  << std::endl;

	DiamondTrap dt2 = dt;
	dt2.print_stats();
	dt2.whoAmI();
	dt2.attack("John");
	dt2.guardGate();
	dt2.highFivesGuys();
	std::cout << std::endl
			  << std::endl;

	DiamondTrap dt3;
	dt3 = DiamondTrap("George");
	dt3.print_stats();
	dt3.whoAmI();
	dt3.guardGate();
	dt3.highFivesGuys();
	dt3.attack("John");
}