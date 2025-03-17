#include "Base.hpp"
#include "ABC.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base *generate(void)
{
	int rnd = std::rand();
	if(rnd >= 0 && rnd <= 715827882)
	{
		std::cout << "generating A" << std::endl;
		return new A();
	}
	else if(rnd >= 715827883 && rnd <= 1431655764)
	{
		std::cout << "generating B" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "generating C" << std::endl;
		return new C();
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}

void identify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (...)
	{
		try
		{
			dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (...)
		{
			try
			{
				dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch (...)
			{
				std::cout << "unknown" << std::endl;
			}
		}
	}
}

int main()
{
	std::srand(std::time(0));
	Base *ptr = generate();
	std::cout << "identify *: ";
	identify(ptr);
	std::cout << "identify &: ";
	identify(*ptr);
}