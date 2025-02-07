#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap " << name << " was created with default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap " << name << " was created with parameterized constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs) : ScavTrap(rhs), FragTrap(rhs)
{
	std::cout << "DiamondTrap " << name << " was created with a copy constructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	if (this != &rhs)
	{
		ScavTrap::operator=(rhs);
		FragTrap::operator=(rhs);
		std::cout << "DiamondTrap " << "Assigning " << rhs.name << " to " << name << std::endl;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << "'s Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << "DiamondTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else
		std::cout << "DiamondTrap " << name << " can't attack" << std::endl;
}
