#ifndef POINT_HPP
#define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& rhs);
		~Point();
		Point& operator=(const Point& rhs);
		const Fixed get_x() const ;
		const Fixed get_y() const ;
};

std::ostream& operator<<(std::ostream& stream, const Point& point);

#endif