#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *ptr, size_t len, void (*func)(T const &))
{
	for (size_t i = 0; i < len; i++)
	{
		func(ptr[i]);
	}
}

template <typename T>
void print(T const &value)
{
	std::cout << value << std::endl;
}

#endif