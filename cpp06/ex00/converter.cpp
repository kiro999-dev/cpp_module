#include "converter.hpp"
#include <iostream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
bool  isInfiniteDouble(double x)
{
    return x == std::numeric_limits<double>::infinity() ||
           x == -std::numeric_limits<double>::infinity();
}
bool  isInfinite(float x)
{
    return x == std::numeric_limits<float>::infinity() ||
           x == -std::numeric_limits<float>::infinity();
}
int  countChar(const std::string &str, char target)
{
    int count = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == target)
        {
            count++;
        }
    }
    return count;
}
bool  isValidNumber(const std::string &inpute)
{
    bool float_flag = 0;
    size_t sign = 0;
    if(inpute.size() > 1 && (inpute[0] == '+' || inpute[0] == '-'))
        sign++;
    for (size_t i = sign; i < inpute.length(); i++)
    {
        if (float_flag)
            return false;
        if (!isdigit(inpute[i]) && inpute[i] != '.' && inpute[i] != 'f')
            return false;
        if (inpute[i] == 'f')
            float_flag = 1;
    }
    return true;
}
bool   isScienceType(const std::string &inpute)
{
    std::string sicnce_types[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    for (size_t i = 0; i < 6; i++)
    {
        if (sicnce_types[i] == inpute)
            return true;
    }
    return false;
}
enum types  inputType(const std::string &inpute)
{
    if (inpute.empty())
        return invalid_type;
    int dotcount = 0;
    int fcount = 0;
    if (inpute.size() == 1)
        return char_type;
    if (isScienceType(inpute))
        return science_type;
    if (!isValidNumber(inpute))
        return invalid_type;
    dotcount = countChar(inpute, '.');
    fcount = countChar(inpute, 'f');
    if (dotcount > 1 || fcount > 1)
        return invalid_type;
    else if (dotcount == 1 && fcount == 0)
        return double_type;
    else if (fcount == 1 && dotcount == 1)
    {
        if (inpute.length() == 2)
            return invalid_type;
        else
            return float_type;
    }
    else if (fcount == 0 && dotcount == 0)
        return int_type;
    return invalid_type;
}
void static ConvertChar(const std::string &inpute)
{
    char c = inpute[0];
    std::cout << "char: ";
    if (isprint(c))
    {
        std::cout << "'" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
    else
        std::cout << "Non displayable" << std::endl;
}
void static ConvertInt(const std::string &inpute)
{
    char *end;
    errno = 0;
    long num = std::strtol(inpute.c_str(), &end, 10);
    if (errno == ERANGE)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    std::cout << "char: ";
    if (num > 0 && num < 127)
    {
        if (isprint(num))
        {
            std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
        }
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    if (num > MAX_INT || num < MIN_INT)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(num) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(num) << "f" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1)
              << static_cast<double>(num) << std::endl;
}
void static ConvertFloat(const std::string &inpute)
{
    double num = std::atof(inpute.c_str());
    std::cout << "char: ";
    if (num > 0 && num < 127)
    {
        if (isprint(num))
            std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    if (static_cast<long>(num) > MAX_INT || static_cast<long>(num) < MIN_INT)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(num) << std::endl;
    std::cout << "float: ";
    if (num > MAX_FLOAT || num < MIN_FLOAT)
        std::cout << "impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(4)
                  << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double: ";
    if (isInfiniteDouble(num))
        std::cout << "impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(4)
                  << static_cast<double>(num) << std::endl;
}
void static convertScience(const std::string &inpute)
{
    int indx = -1;
    std::string sicnce_types[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    for (size_t i = 0; i < 6; i++)
    {
        if (sicnce_types[i] == inpute)
        {
            indx = i;
            break;
        }
    }
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (indx <= 2)
    {
        std::cout << "float: " << inpute << std::endl;
        std::cout << "double: " << inpute.substr(0, inpute.size() - 1) << std::endl;
    }
    else
    {
        std::cout << "float: " << inpute + 'f' << std::endl;
        std::cout << "double: " << inpute << std::endl;
    }
}
void converter(const std::string &str)
{
    types s = inputType(str);
    switch (s)
    {
    case char_type:
        ConvertChar(str);
        break;
    case int_type:
        ConvertInt(str);
        break;
    case float_type:
        ConvertFloat(str);
        break;
    case double_type:
        ConvertFloat(str);
        break;
    case science_type:
        convertScience(str);
        break;
    case invalid_type:
        std::cout << "its invalid type" << std::endl;
        break;
    default:
        break;
    }
}