#include "Fixed.hpp"

Fixed& Fixed::min( Fixed &a,Fixed &b)
{
    if(a._fpoint > b._fpoint)
        return (b);
}

Fixed& Fixed::max( Fixed &a,Fixed &b)
{
    if(a._fpoint > b._fpoint)
        return (a);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if(a._fpoint > b._fpoint)
        return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if(a._fpoint > b._fpoint)
        return (a);
}
bool Fixed::operator<(const Fixed &other) const
{
    return (this->_fpoint < other._fpoint);
}
bool Fixed::operator>(const Fixed &other) const
{
    return (this->_fpoint > other._fpoint);
}
bool Fixed::operator>=(const Fixed &other) const
{
    return (this->_fpoint >= other._fpoint);
}
bool Fixed::operator<=(const Fixed &other) const
{
    return (this->_fpoint <= other._fpoint);
}
bool Fixed::operator==(const Fixed &other) const
{
    return (this->_fpoint == other._fpoint);
}
bool Fixed::operator!=(const Fixed &other) const
{
    return (this->_fpoint != other._fpoint);
}
Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->_fpoint + other._fpoint);
}
Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->_fpoint - other._fpoint);
}
Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->_fpoint *  other._fpoint);
}
Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->_fpoint /  other._fpoint);
}
Fixed &Fixed::operator++()
{
    this->_fpoint += e;
    return *this;
}
Fixed &Fixed::operator--()
{
    this->_fpoint -= e;
    return *this;
}
Fixed Fixed::operator++(int)
{
   Fixed temp (this->_fpoint);
   this->_fpoint += e;
   return temp;
}
Fixed Fixed::operator--(int)
{
   Fixed temp (this->_fpoint);
   this->_fpoint -= e;
   return temp;
}
Fixed &Fixed::operator=(const Fixed &other) 
{
    if(this == &other)
        return *this;
    std::cout<<"Copy assignment operator called"<<std::endl;
    _fpoint = other.getRawBits();
    return (*this);
}
int Fixed::getRawBits(void) const
{
     std::cout<<"getRawBits member function called"<<std::endl;
	return this->_fpoint;
}
void Fixed::setRawBits( const int  raw )
{
	_fpoint = raw;
}
Fixed::Fixed(const int integer) 
{
    _fpoint = integer << _fraction_bits;
     std::cout<<"Int constructor called"<<std::endl;
}
Fixed::Fixed(const float float_num) 
{
    _fpoint = (int)(float_num * (1 << _fraction_bits));
     std::cout<<"Float constructor called"<<std::endl;
}
Fixed:: Fixed(void)
{
      std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &obj) 
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = obj;
}

Fixed ::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}
float Fixed::toFloat( void ) const
{
    float num = (float)_fpoint / (float) (1 << _fraction_bits);
    return (num);
}
int Fixed ::toInt( void ) const
{
    return (_fpoint >> _fraction_bits);
}
std::ostream& operator<<(std::ostream& stream, const Fixed& obj)
{
        stream << obj.toFloat();
        return stream;
}