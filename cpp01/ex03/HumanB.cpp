#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
}

void HumanB::attack()
{
	std::cout << name << " attacks with their ";
	if (weapon)
		std::cout << (*weapon).getType();
	else
		std::cout << "hands";
	std::cout << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}