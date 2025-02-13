#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << "b: " << b << std::endl;

	std::cout << "b > a: " << (b > a) << std::endl;
	std::cout << "b == a: " << (b == a) << std::endl;
	std::cout << "b <= a: " << (b <= a) << std::endl;
	std::cout << "b / a: " << (b / a) << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
}