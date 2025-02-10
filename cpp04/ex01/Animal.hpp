#ifndef Brain_HPP
#define Brain_HPP

# include <iostream>

class Brain
{
	protected:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &rhs);
		Brain& operator=(const Brain &rhs);
		virtual ~Brain();
};

#endif