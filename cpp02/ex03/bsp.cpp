#include "Point.hpp"

static float area(Point const &a, Point const &b, Point const &c)
{
	return std::abs((a.get_x().toFloat() * (b.get_y().toFloat() - c.get_y().toFloat()) +
					 b.get_x().toFloat() * (c.get_y().toFloat() - a.get_y().toFloat()) +
					 c.get_x().toFloat() * (a.get_y().toFloat() - b.get_y().toFloat())) /
					2.0f);
}

static bool is_point_on_edge(Point const &a, Point const &b, Point const &point)
{
	float area1 = area(a, b, point);
	return area1 == 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float A = area(a, b, c);
	float A1 = area(point, b, c);
	float A2 = area(a, point, c);
	float A3 = area(a, b, point);

	if (is_point_on_edge(a, b, point) || is_point_on_edge(b, c, point) || is_point_on_edge(c, a, point))
		return false;

	return (A == A1 + A2 + A3);
}
