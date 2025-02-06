#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw) : fixed_point_value(raw << Fixed::factional_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float raw) : fixed_point_value(roundf(raw * (1 << Fixed::factional_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(rhs.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(rhs.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return fixed_point_value;
}

void Fixed::setRawBits( int const raw )
{
	fixed_point_value = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)fixed_point_value / (1 << Fixed::factional_bits);
}

int Fixed::toInt( void ) const
{
	return fixed_point_value >> Fixed::factional_bits;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return stream;
}

bool Fixed::operator>(const Fixed& rhs)
{
	return this->fixed_point_value > rhs.fixed_point_value;
}

bool Fixed::operator<(const Fixed& rhs)
{
	return this->fixed_point_value < rhs.fixed_point_value;
}

bool Fixed::operator>=(const Fixed& rhs)
{
	return this->fixed_point_value >= rhs.fixed_point_value;
}

bool Fixed::operator<=(const Fixed& rhs)
{
	return this->fixed_point_value <= rhs.fixed_point_value;
}

bool Fixed::operator==(const Fixed& rhs)
{
	return this->fixed_point_value == rhs.fixed_point_value;
}

bool Fixed::operator!=(const Fixed& rhs)
{
	return this->fixed_point_value != rhs.fixed_point_value;
}

// operations

Fixed& Fixed::operator++()
{
	++fixed_point_value;
	return *this;
} //prefix

Fixed Fixed::operator++(int)
{

} //postfix

Fixed& Fixed::operator--()
{
	--fixed_point_value;
	return *this;
} //prefix

Fixed Fixed::operator--(int)
{

} //postfix
