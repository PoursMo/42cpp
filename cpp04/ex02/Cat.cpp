#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain())
{
	std::cout << "Cat: default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &rhs) : Animal(rhs), brain(new Brain(*rhs.brain))
{
	std::cout << "Cat: copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat: copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete brain;
		brain = new Brain(*rhs.brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat: destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat: meow" << std::endl;
}

Brain *Cat::get_brain()
{
	return brain;
}