#include "iter.hpp"
#include <iostream>

#define SIZE 5

int main()
{
	int intarr[SIZE] = {1, 2, 3, 4, 5};
	iter(intarr, SIZE, increment);
	iter(intarr, SIZE, print);
	std::cout << std::endl;
	float fltarr[SIZE] = {1.2f, 2.98f, 3.1f, 4.4f, 5.12f};
	iter(fltarr, SIZE, increment);
	iter(fltarr, SIZE, print);
	std::cout << std::endl;
	std::string strarr[SIZE] = {"this", "is", "a", "cool", "feature"};
	iter(strarr, SIZE, print);
}