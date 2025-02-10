#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog: default constructor called" << std::endl;
}

Dog::Dog(const Dog &rhs) : Animal(rhs)
{
	std::cout << "Dog: copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog: copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog: destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog: woof" << std::endl;
}