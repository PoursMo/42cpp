#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat: default constructor called" << std::endl;
}

Cat::Cat(const Cat &rhs) : Animal(rhs)
{
	std::cout << "Cat: copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat: copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat: destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat: meow" << std::endl;
}