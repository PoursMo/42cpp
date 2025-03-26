#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack() : std::stack<T>() {}

	MutantStack(const MutantStack &rhs) : std::stack<T>(rhs) {}

	MutantStack &operator=(const MutantStack &rhs)
	{
		if (this != &rhs)
		{
			std::stack<T>::operator=(rhs);
		}
		return *this;
	}

	~MutantStack() {}

	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
};

#endif