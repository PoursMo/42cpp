#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *ptr, std::size_t len, void (*func)(T &))
{
	for (std::size_t i = 0; i < len; i++)
	{
		func(ptr[i]);
	}
}

template <typename T>
void iter(const T *ptr, std::size_t len, void (*func)(const T &))
{
	for (std::size_t i = 0; i < len; i++)
	{
		func(ptr[i]);
	}
}

template <typename T>
void print(const T &value)
{
	std::cout << value << std::endl;
}

void increment(int &value)
{
	value++;
}

void increment(float &value)
{
	value++;
}

#endif