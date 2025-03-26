#include "MutantStack.hpp"

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
		for (size_t i = 0; i < 1000; i++)
		{
			mstack.push(i);
		}
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	{
		std::cout << "std::list: " << std::endl;
		std::list<int> stdlist;
		stdlist.push_back(5);
		stdlist.push_back(17);
		std::cout << stdlist.back() << std::endl;
		stdlist.pop_back();
		std::cout << stdlist.size() << std::endl;
		for (size_t i = 0; i < 1000; i++)
		{
			stdlist.push_back(i);
		}
		std::list<int>::iterator it = stdlist.begin();
		std::list<int>::iterator ite = stdlist.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::list<int> s(stdlist);
	}
	std::cout << "*******************************************" << std::endl;
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