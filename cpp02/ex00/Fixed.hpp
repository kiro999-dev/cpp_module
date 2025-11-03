#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
class Fixed
{
private:
	int _fpoint;
	static const int _fracions_bits = 8;
public:
	
	
	Fixed(void);
	Fixed(const Fixed &obj);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );

};  
  

#endif