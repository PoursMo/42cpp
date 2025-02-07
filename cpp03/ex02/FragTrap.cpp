#include "FragTrap.hpp"FragTrap::FragTrap() : ClapTrap()
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " was created with default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " was created with parameterized constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& rhs) : ClapTrap(rhs)
{
	std::cout << "FragTrap " << name << " was created with a copy constructor" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		std::cout << "FragTrap " << "Assigning " << rhs.name << " to " << name << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << "'s Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else
		std::cout << "FragTrap " << name << " can't attack" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}