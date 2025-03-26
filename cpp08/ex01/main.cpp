#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	std::srand(time(0));
	// *************************************************************
	try
	{
		Span sp;
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span sp(2);
		sp.addNumber(1);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	// *************************************************************
	Span sp(5);
	try
	{
		for (size_t i = 0; i < 6 * 2; i += 2)
		{
			sp.addNumber(i);
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << sp << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	// *************************************************************
	std::cout << std::endl;
	std::vector<int> vec;
	for (size_t i = 0; i < 1000 * 2; i += 2)
	{
		vec.push_back(i);
	}
	Span sp2(100);
	try
	{
		sp2.addNumbers(vec.begin(), vec.end());
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << sp2 << std::endl;
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	// *************************************************************
}