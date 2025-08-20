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
	
	Fixed(const Fixed &obj);
	Fixed(void);
	Fixed(const int );
	Fixed(const float );
	~Fixed();
	Fixed &operator=(const Fixed &other);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

};  
std::ostream& operator<<(std::ostream& stream, const Fixed& obj);
#endif