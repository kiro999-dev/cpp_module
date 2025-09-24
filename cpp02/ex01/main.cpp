#include <iostream>
#include"Fixed.hpp"

int main( void ) {
Fixed a (4);
Fixed y (a); // copy constructor called
Fixed z = y;  // copy constructor called

return 0;
}
