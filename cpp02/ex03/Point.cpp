#include "Point.hpp"

Point::Point():x(0),y(0)
{

}
Point::Point(float X, float Y):x(X),y(Y)
{
    
}

Point::Point(const Point &obj):x(obj.x),y(obj.y)
{
    
}

const Point& Point:: operator=(const Point &ob) 
{
    (void) ob;
    return *this;
}

Point::~Point()
{
     
}

const Fixed &Point::GetX() const
{
    return this->x;
}

const Fixed &Point::GetY() const
{
    return this->y;
}

