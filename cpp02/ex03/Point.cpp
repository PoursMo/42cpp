#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point &rhs) : x(rhs.x), y(rhs.y)
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &rhs)
{
	(void)rhs;
	return *this;
}

const Fixed Point::get_x() const
{
	return x;
}

const Fixed Point::get_y() const
{
	return y;
}

std::ostream &operator<<(std::ostream &stream, const Point &point)
{
	stream << "x: " << point.get_x() << ", y: " << point.get_y();
	return stream;
}