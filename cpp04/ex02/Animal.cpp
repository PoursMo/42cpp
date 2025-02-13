#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal: default constructor called" << std::endl;
}

Animal::Animal(const Animal &rhs)
{
	type = rhs.type;
	std::cout << "Animal: copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &rhs)
{
	std::cout << "Animal: copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal: destructor called" << std::endl;
}

const std::string Animal::getType() const
{
	return type;
}
