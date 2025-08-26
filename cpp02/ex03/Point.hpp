#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
  const Fixed x;
  const Fixed y;
public:
    Point(const Point& ob);
    const Point& operator=(const Point &ob);
    Point();
    Point(float X , float Y);
    ~Point();
    const  Fixed& GetX() const;
    const Fixed& GetY() const;
};
bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif