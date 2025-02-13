#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0)
{
	for (int i = 0; i < 4; i++)
	{
		materias[i] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) : count(other.count)
{
	for (int i = 0; i < 4; i++)
	{
		if (i < other.count && other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = 0;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < count; i++)
		{
			delete materias[i];
		}
		for (int i = 0; i < 4; i++)
		{
			if (i < other.count && other.materias[i])
				materias[i] = other.materias[i]->clone();
			else
				materias[i] = 0;
		}
		count = other.count;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < count; i++)
	{
		delete materias[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (count < 4 && m)
	{
		materias[count++] = m;
	}
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	if (count > 0)
	{
		for (int i = count - 1; i >= 0; i--)
		{
			if (type == materias[i]->getType())
				return materias[i]->clone();
		}
	}
	return 0;
}
