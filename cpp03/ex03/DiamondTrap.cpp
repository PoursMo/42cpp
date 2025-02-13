#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap " << name << " was created with default constructor" << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 30;
	print_stats();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	std::cout << "DiamondTrap " << name << " was created with parameterized constructor" << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 30;
	print_stats();
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs) : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs), name(rhs.name)
{
	std::cout << "DiamondTrap " << name << " was created with a copy constructor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (this != &rhs)
	{
		std::cout << "DiamondTrap " << "Assigning " << rhs.name << " to " << name << std::endl;
		ScavTrap::operator=(rhs);
		FragTrap::operator=(rhs);
		name = rhs.name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << "'s Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::print_stats()
{
	std::cout << name << " ";
	std::cout << "hit points: " << hit_points << ", ";
	std::cout << "energy points: " << energy_points << ", ";
	std::cout << "attack damage: " << attack_damage << std::endl;
}