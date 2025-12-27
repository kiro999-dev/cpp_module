#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
class ScalarConverter
{
private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &o);
    ScalarConverter& operator=(const ScalarConverter &o);
public:
    static void convert(const std::string &s);
   
    
};



#endif