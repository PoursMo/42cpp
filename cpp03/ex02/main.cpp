#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	FragTrap ft("George");
	ft.beRepaired(20);
	ft.attack("John");
	ft.highFivesGuys();
	ft.takeDamage(150);
	ft.attack("John");
	ft.beRepaired(20);
	ft.highFivesGuys();

	ft = FragTrap("William");
	for (size_t i = 0; i < 101; i++)
	{
		ft.attack("John");
	}
	ft.beRepaired(20);
	ft.highFivesGuys();

	ScavTrap st("George");
	st.beRepaired(20);
	st.attack("John");
	st.guardGate();
	st.takeDamage(150);
	st.attack("John");
	st.beRepaired(20);
	st.guardGate();

	st = ScavTrap("William");
	for (size_t i = 0; i < 51; i++)
	{
		st.attack("John");
	}
	st.beRepaired(20);
	st.guardGate();
}