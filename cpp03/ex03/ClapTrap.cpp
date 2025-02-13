#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " was created with default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " was created with parameterized constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs) : name(rhs.name), hit_points(rhs.hit_points), energy_points(rhs.energy_points), attack_damage(rhs.attack_damage)
{
	std::cout << "ClapTrap " << name << " was created with a copy constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != &rhs)
	{
		std::cout << "ClapTrap " << "Assigning " << rhs.name << " to " << name << std::endl;
		name = rhs.name;
		hit_points = rhs.hit_points;
		energy_points = rhs.energy_points;
		attack_damage = rhs.attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << "'s Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else
		std::cout << "ClapTrap " << name << " can't attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " takes " << amount << " damage!" << std::endl;
	hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << "ClapTrap " << name << " repairs itself, regaining " << amount << " hit points!" << std::endl;
		hit_points += amount;
		energy_points--;
	}
	else
		std::cout << "ClapTrap " << name << " can't repair" << std::endl;
}
