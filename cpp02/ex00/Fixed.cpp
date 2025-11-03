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
    std::cout<<"setRawBits member function called"<<std::endl;
	_fpoint = raw;
}

Fixed:: Fixed(void)
{
      _fpoint = 0;
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
