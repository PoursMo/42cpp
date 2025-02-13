#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &rhs);
	WrongAnimal &operator=(const WrongAnimal &rhs);
	virtual ~WrongAnimal();
	const std::string getType() const;
	void makeSound() const;
};

#endif