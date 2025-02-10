#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	Dog().makeSound();
	Cat().makeSound();
	delete meta;
	delete j;
	delete i;

	const WrongAnimal *wrongmeta = new WrongAnimal();
	const WrongAnimal *k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	wrongmeta->makeSound();
	delete wrongmeta;
	delete k;
}