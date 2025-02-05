#include "Fixed.hpp"

void printBits(int n) {
	for (int i = 31; i >= 0; i--) {
		std::cout << ((n >> i) & 1);
		if (i % 8 == 0) std::cout << ' ';
	}
	std::cout << std::endl;
}

int main(void)
{
	printBits(roundf(42.42)  * (1 << 8));

	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	
	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}
