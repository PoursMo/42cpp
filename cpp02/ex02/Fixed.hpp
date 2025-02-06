#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int fixed_point_value;
		static const int factional_bits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& rhs);
		~Fixed();
		Fixed& operator=(const Fixed& rhs);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator>(const Fixed& rhs);
		bool operator<(const Fixed& rhs);
		bool operator>=(const Fixed& rhs);
		bool operator<=(const Fixed& rhs);
		bool operator==(const Fixed& rhs);
		bool operator!=(const Fixed& rhs);
		// operator+
		// operator-
		// operator*
		// operator/
		Fixed& operator++(); //prefix
		Fixed operator++(int); //postfix
		Fixed& operator--(); //prefix
		Fixed operator--(int); //postfix

};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif