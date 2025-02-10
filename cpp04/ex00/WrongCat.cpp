#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat: default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs) : WrongAnimal(rhs)
{
	std::cout << "WrongCat: copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "WrongCat: copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		WrongAnimal::operator=(rhs);
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat: meowent" << std::endl;
}