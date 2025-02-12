#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: default constructor called" << std::endl;
}

Brain::Brain(const Brain &rhs)
{
	std::cout << "Brain: copy constructor called" << std::endl;
	std::copy(rhs.ideas, rhs.ideas + 100, ideas);
}

Brain& Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain: copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		std::copy(rhs.ideas, rhs.ideas + 100, ideas);
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain: destructor called" << std::endl;
}

void Brain::print_ideas() const
{
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << i << ": " << ideas[i] << std::endl;
	}
}

std::string* Brain::get_ideas()
{
	return ideas;
}
