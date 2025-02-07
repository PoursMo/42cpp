#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int fixed_point_value;
		static const int fractional_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed& rhs);
		~Fixed();
		Fixed& operator=(const Fixed& rhs);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif