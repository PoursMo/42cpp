#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

int main()
{
	std::list<int> list;
	std::deque<int> deque;
	std::vector<int> vector;

	for (int i = 0; i < 10; i++)
	{
		list.push_back(i);
		deque.push_front(i);
		vector.push_back(i);
	}

	/* Testing with list */
	std::cout << "List:";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << ' ' << *it;

	std::list<int>::iterator list_it = easyfind(list, 1);
	std::cout << "\nFound:  " << *list_it << " followed by " << *(++list_it) << "\n"
			  << std::endl;

	/* Testing with deque */
	std::cout << "Deque:";
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
		std::cout << ' ' << *it;

	std::deque<int>::iterator deque_it = easyfind(deque, 2);
	std::cout << "\nFound: " << *deque_it << " followed by " << *(++deque_it) << "\n"
			  << std::endl;

	/* Testing with vector */
	std::cout << "Vector:";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << ' ' << *it;

	std::vector<int>::iterator vector_it = easyfind(vector, 3);
	std::cout << "\nFound: " << *vector_it << " followed by " << *(++vector_it) << "\n"
			  << std::endl;

	/* Testing with non-existent element */
	std::cout << "non-element in the vector\n"
			  << std::endl;

	std::cout << "Vector:";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << ' ' << *it;

	try
	{
		std::cout << '\n';
		std::vector<int>::iterator it = easyfind(vector, 42);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}