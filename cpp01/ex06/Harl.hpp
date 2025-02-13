#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void call_level(int level);
	typedef struct s_comment
	{
		std::string level;
		void (Harl::*ptr)();
	} t_comment;
	static const t_comment comments[];

public:
	void complain(std::string level);
};

#endif