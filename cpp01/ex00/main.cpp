#include "Zombie.hpp"

int main()
{
	randomChump("random chump");
	Zombie* allocated_zombie = newZombie("allocated zombie");
	allocated_zombie->announce();
	delete allocated_zombie;
}