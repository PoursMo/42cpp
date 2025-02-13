#include "Zombie.hpp"

int main()
{
	std::cout << "*** randomChump function ***" << std::endl;
	randomChump("random chump");
	std::cout << "*** newZombie function ***" << std::endl;
	Zombie *allocated_zombie = newZombie("allocated zombie");
	allocated_zombie->announce();
	delete allocated_zombie;
}