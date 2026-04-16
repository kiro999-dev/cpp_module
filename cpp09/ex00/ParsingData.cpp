#include "main.hpp"
#include "BitcoinExchange.hpp"
int strlen(const char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}
std::map<int, std::string> splitString(const std::string &str, char delimiter)
{
    std::map<int, std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    int i = 0;
    while (std::getline(ss, token, delimiter))
    {
        tokens.insert(std::make_pair(i, token));
        i++;
    }
    return tokens;
}

int parse_int(const char *str, int *result, int flag)
{
    char *end;
    long val;
    errno = 0;
    if ((flag == 1 && strlen(str) != 2))
        return 0;
    val = strtol(str, &end, 10);
    if (errno == ERANGE || val > INT_MAX)
        return 0;

    if (*end != '\0')
        return 0;
    *result = (int)val;
    return 1;
}

bool ProcessDate(std::string date, int &yy, int &mm, int &dd)
{
    int y, m, d;
    std::map<int, std::string> dateFromat = splitString(date, '-');
    if (dateFromat.size() != 3)
    {
        std::cout << "Error: bad input => " + date << std::endl;
        return true;
    }
    if (!parse_int(dateFromat[0].c_str(), &y, 2) ||
        !parse_int(dateFromat[1].c_str(), &m, 1) ||
        !parse_int(dateFromat[2].c_str(), &d, 1))
    {
        std::cout << "Error: bad input => " + date << std::endl;
        return true;
    }
    Date format(y, m, d, date);
    if (!format.IsValidDate())
    {
        std::cout << "Error: bad input => " + date << std::endl;
        return true;
    }
    yy = y;
    mm = m;
    dd = d;
    return false;
}
bool CheckIsNumber(std::string str)
{
    int i = 0;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}
float parse_float(const char *str, float *res, int flag)
{
    char *end;
    float val;

    errno = 0;
    val = strtof(str, &end);

    if (flag && strlen(str) < 2)
    {
        return 0;
    }
    if (errno == ERANGE)
    {
        *res = 1;
        return 0;
    }

    if (*end != '\0')
    {
        *res = 0.0f;
        return 0;
    }

    *res = val;
    return 1;
}

bool ProcessValue(std::string s)
{
    float val;
    if (!parse_float(s.c_str(), &val, 0) || val > 1000)
    {
        if (val == 0)
            std::cout << "Error: bad input => " + s << std::endl;
        else
            std::cout << "Error: too large a number" << std::endl;
        return true;
    }
    else if (val < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return true;
    }
    return false;
}

void ProcessLine(std::string line, BitcoinExchange &btc)
{
    std::map<int, std::string> data = splitString(line, ' ');
    int y, m, d;
    float value;
    static int flag = 0;
    if (data.size() != 3)
    {
        std::cout << "Error: bad input => " + line << std::endl;
        flag++;
        return;
    }
    if (flag == 0)
    {
        if (data[0] != "date"  || data[1] != "|"  || data[2]!= "value")
            std::cout << "Error: bad input => " + line << std::endl;
        flag++;
        return;
    }
    value = std::atof(data[2].c_str());
    if(data[1] !="|")
    {
        std::cout << "Error: bad input => " + line << std::endl;
        return;
    }
    if (ProcessDate(data[0], y, m, d) || ProcessValue(data[2]))
        return;
    btc.MatchDate(Date(y, m, d, data[0]), value);
}