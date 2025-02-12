#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
	std::cout << "Dog: default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &rhs) : Animal(rhs), brain(new Brain(*rhs.brain))
{
	std::cout << "Dog: copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog: copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete brain;
		brain = new Brain(*rhs.brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog: destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog: meow" << std::endl;
}

Brain* Dog::get_brain()
{
	return brain;
}