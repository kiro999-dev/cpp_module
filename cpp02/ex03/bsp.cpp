#include "Point.hpp"

Fixed absval(Fixed point)
{
	if (point < 0)
		return point * -1;
	return point;
}

Fixed area(Point const a, Point const b, Point const c)
{
	return ((a.GetX() * (b.GetY() - c.GetY()) + b.GetX() * (c.GetY() - a.GetY()) + c.GetX() * (a.GetY() - b.GetY()))/2);
}
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed a0 = absval(area(a, b, c));
	Fixed a1 = absval(area(point, b, c));
	Fixed a2 = absval(area(a, point, c));
	Fixed a3 = absval(area(a, b, point));


	if (a1 * a2 * a3 == 0)
		return false;
	if (a0 == a1 + a2 + a3)
		return true;
	return false;
}