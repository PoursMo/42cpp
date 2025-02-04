#include "Zombie.hpp"

int main()
{
	int horde_size = 5;
	Zombie* horde = zombieHorde(horde_size, "zombie horde");
	for (int i = 0; i < horde_size; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
}