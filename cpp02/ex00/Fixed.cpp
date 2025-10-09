#include "Fixed.hpp"

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
Fixed::Fixed(const int intger) 
{
    _fpoint = intger << _fracions_bits;
     std::cout<<"Int constructor called"<<std::endl;
}
Fixed::Fixed(const float float_num) 
{
    _fpoint = roundf(float_num * (1 << _fracions_bits));
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
    float num = (float)_fpoint / (float) (1 << _fracions_bits);
    return (num);
}
int Fixed ::toInt( void ) const
{
    return (_fpoint >> _fracions_bits);
}
std::ostream& operator<<(std::ostream& stream, const Fixed& obj)
{
        stream << obj.toFloat();
        return stream;
}