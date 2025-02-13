#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap " << name << " was created with default constructor" << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " was created with parameterized constructor" << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap(rhs)
{
	std::cout << "ScavTrap " << name << " was created with a copy constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	if (this != &rhs)
	{
		std::cout << "ScavTrap " << "Assigning " << rhs.name << " to " << name << std::endl;
		ClapTrap::operator=(rhs);
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << "'s Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else
		std::cout << "ScavTrap " << name << " can't attack" << std::endl;
}

void ScavTrap::guardGate()
{
	if (hit_points > 0)
		std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
	else
		std::cout << "ScavTrap " << name << " can't guard the Gate" << std::endl;
}