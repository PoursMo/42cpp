#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;

public:
	Cat();
	Cat(const Cat &rhs);
	Cat &operator=(const Cat &rhs);
	~Cat();
	void makeSound() const;
	Brain *get_brain();
};

#endif