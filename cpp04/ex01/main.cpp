#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	int size = 20;
	std::cout << "\e[1;35mcreating array\e[0m" << std::endl;
	Animal *animals[size];
	int i = 0;
	for (; i < size / 2; i++)
	{
		animals[i] = new Dog();
	}
	for (; i < size; i++)
	{
		animals[i] = new Cat();
	}
	std::cout << "\e[1;35mdeleting both arrays\e[0m" << std::endl;
	for (i = 0; i < size; i++)
	{
		delete animals[i];
	}
	std::cout << "\e[1;35m*****************\e[0m" << std::endl;
	Cat *cat = new Cat();
	cat->get_brain()->get_ideas()[51] = "bonjour";
	Cat *cat_copy = new Cat(*cat);
	cat_copy->get_brain()->get_ideas()[52] = "hello";
	Cat *cat_copy2 = new Cat();
	*cat_copy2 = *cat_copy;
	cat_copy2->get_brain()->get_ideas()[53] = "coucou";
	cat->get_brain()->print_ideas();
	cat_copy->get_brain()->print_ideas();
	cat_copy2->get_brain()->print_ideas();
	delete cat;
	delete cat_copy;
	delete cat_copy2;
}