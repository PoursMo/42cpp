#include "MutantStack.hpp"
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

template <typename T>
void printTests(T it)
{
	std::cout << std::setw(20) << std::setfill('_') << std::left << "it value" << *it << std::endl;
	std::cout << std::setw(20) << std::setfill('_') << std::left << "it += 1" << *(it += 1) << std::endl;
	std::cout << std::setw(20) << std::setfill('_') << std::left << "it -= 1" << *(it -= 1) << std::endl;
	std::cout << std::setw(20) << std::setfill('_') << std::left << "1 + it" << *(1 + it) << std::endl;
	std::cout << std::setw(20) << std::setfill('_') << std::left << "it + 3" << *(it + 3) << std::endl;
	std::cout << std::setw(20) << std::setfill('_') << std::left << "it[5]" << it[5] << std::endl;
	std::cout << std::setw(20) << std::setfill('_') << std::left << "it - (it + 2)" << it - (it + 2) << std::endl;
	std::cout << std::setw(20) << std::setfill('_') << std::left << "it < (it - 2)" << (it < (it - 2) ? "true" : "false") << std::endl;
	std::cout << std::setw(20) << std::setfill('_') << std::left << "it > (it - 2)" << (it > (it - 2) ? "true" : "false") << std::endl;
	std::cout << std::setw(20) << std::setfill('_') << std::left << "it >= (it - 2)" << (it >= (it - 2) ? "true" : "false") << std::endl;
	std::cout << std::setw(20) << std::setfill('_') << std::left << "it >= it" << (it >= it ? "true" : "false") << std::endl;
	std::cout << std::setw(20) << std::setfill('_') << std::left << "it <= (it - 2)" << (it <= (it - 2) ? "true" : "false") << std::endl;
}

int main()
{
	{
		std::cout << "MutantStack: " << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	{
		std::cout << "std::list: " << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}
	std::cout << std::endl;
	{
		std::cout << "std::vector: " << std::endl;
		std::vector<int> vector;
		for (size_t i = 0; i < 10; i++)
		{
			vector.push_back(i);
		}
		for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
		{
			std::cout << *it;
			if (it != vector.end() - 1)
				std::cout << ", ";
			it - it;
		}
		std::cout << std::endl;
		printTests(vector.begin());
	}
	std::cout << std::endl;
	{
		std::cout << "MutantStack: " << std::endl;
		MutantStack<int> mstack;
		for (size_t i = 0; i < 10; i++)
		{
			mstack.push(i);
		}
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
		{
			std::cout << *it;
			if (it != mstack.end() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		printTests(mstack.begin());
	}
}