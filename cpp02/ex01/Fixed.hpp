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
	Fixed(const int );
	Fixed(const float );
	float toFloat( void ) const;
	int toInt( void ) const;
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	
};  
std::ostream& operator<<(std::ostream& stream, const Fixed& obj);
#endif 