#include "ScalarConverter.hpp"
#include "converter.hpp"
ScalarConverter::ScalarConverter(){
     std::cout<<"ScalarConverter constructor has been called";
}
ScalarConverter::ScalarConverter(const ScalarConverter&o)
{
    (void)o;
     std::cout<<"ScalarConverter copy constructor has been called";
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&o)
{
     std::cout<<"ScalarConverter operator= has been called";
    (void)o;
    return *this;
}
void ScalarConverter::convert(const std::string &s)
{
    converter(s);
}
ScalarConverter::~ScalarConverter()
{
    std::cout<<"ScalarConverter destructor has been called";
}