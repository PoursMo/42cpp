#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0)
{
}

Fixed::Fixed(const int raw) : fixed_point_value(raw << Fixed::fractional_bits)
{
}

Fixed::Fixed(const float raw) : fixed_point_value(roundf(raw * (1 << Fixed::fractional_bits)))
{
}

Fixed::Fixed(const Fixed& rhs)
{
	this->setRawBits(rhs.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	this->setRawBits(rhs.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
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
	return (float)fixed_point_value / (1 << Fixed::fractional_bits);
}

int Fixed::toInt( void ) const
{
	return fixed_point_value >> Fixed::fractional_bits;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return stream;
}

bool Fixed::operator>(const Fixed& rhs) const
{
	return this->fixed_point_value > rhs.fixed_point_value;
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return this->fixed_point_value < rhs.fixed_point_value;
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return this->fixed_point_value >= rhs.fixed_point_value;
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	return this->fixed_point_value <= rhs.fixed_point_value;
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return this->fixed_point_value == rhs.fixed_point_value;
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return this->fixed_point_value != rhs.fixed_point_value;
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++()
{
	++fixed_point_value;
	return *this;
} //prefix

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++fixed_point_value;
	return tmp;
} //postfix

Fixed& Fixed::operator--()
{
	--fixed_point_value;
	return *this;
} //prefix

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--fixed_point_value;
	return tmp;
} //postfix

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}
