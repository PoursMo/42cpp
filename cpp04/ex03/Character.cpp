#include "Character.hpp"

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = 0;
	}
}

Character::Character(Character const &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = 0;
	}
}

Character &Character::operator=(Character const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = 0;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	for (size_t i = 0; i < unequipped_materias.size(); i++)
	{
		delete unequipped_materias[i];
	}
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!inventory[i])
			{
				inventory[i] = m;
				return;
			}
		}
		unequipped_materias.push_back(m);
	}
}

void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && inventory[idx])
	{
		unequipped_materias.push_back(inventory[idx]);
		inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 4 && idx >= 0 && inventory[idx])
		inventory[idx]->use(target);
}