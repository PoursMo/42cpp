#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		Zombie( std::string name );
		Zombie();
		~Zombie();
		void announce( void );

	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif