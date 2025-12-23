#ifndef CONVERTER_HPP
#define CONVERTER_HPP
# include <limits>
# include <cmath>
#include <iostream>
# define MIN_INT std::numeric_limits<int>::min() 
# define MAX_INT std::numeric_limits<int>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()
# define MAX_FLOAT std::numeric_limits<float>::max() 
# define MIN_DOUBLE std::numeric_limits<double>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()
enum types
{
    char_type = 1,
    valid_type = 2,
    invalid_type =3,
    science_type = 4
};
void converter(const std::string &str);
#endif