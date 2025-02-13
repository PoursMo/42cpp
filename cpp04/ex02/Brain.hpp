#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain(const Brain &rhs);
	Brain &operator=(const Brain &rhs);
	virtual ~Brain();
	std::string *get_ideas();
	void print_ideas() const;
};

#endif