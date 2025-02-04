#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

const Harl::t_comment Harl::comments[] = 
{
	{"DEBUG", &Harl::debug},
	{"INFO", &Harl::info},
	{"WARNING", &Harl::warning},
	{"ERROR", &Harl::error}
};

void Harl::complain( std::string level )
{
	int level_index = -1;
	for (int i = 0; i < 4; i++)
	{
		if (comments[i].level == level)
		{
			level_index = i;
			break ;
		}
	}
	if (level_index == -1)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}
	call_level(level_index);
}

void Harl::call_level( int level )
{
	switch (level)
	{
		case 0:
			(this->*comments[0].ptr)();
			break ;
		case 1:
			(this->*comments[1].ptr)();
			break ;
		case 2:
			(this->*comments[2].ptr)();
			break ;
		case 3:
			(this->*comments[3].ptr)();
			break ;
		default:
			return ;
	}
	call_level(level + 1);
}