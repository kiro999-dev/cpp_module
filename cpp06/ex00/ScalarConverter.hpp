#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
class ScalarConverter
{
private:
   
public:
    static void convert(const std::string &s);
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &o);
    ScalarConverter& operator=(const ScalarConverter &o);
};



#endif