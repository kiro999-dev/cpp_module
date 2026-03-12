#ifndef ddd
#define ddd
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <errno.h> 
#include <climits>

int strlen(const char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}
std::map<int ,std::string> splitString(const std::string& str, char delimiter) {
  std::map<int ,std::string> tokens;
  std::stringstream ss(str);
  std::string token;
  int i = 0;
  while (std::getline(ss, token, delimiter)) {
      tokens.insert({i,token});
      i++;
  }
  return tokens;
}
class Date
{
private:
   long year;
   short month;
   short day;
public:
    Date(long,short,short);
    bool IsValidDate();
    bool isvalidrange();
    bool operator<(const Date &other) const
    {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
    Date();
    ~Date();
};
int parse_int(const char *str, int *result,int flag)
{
    char *end;
    long val;
    errno = 0;
    if(flag && strlen(str) < 2)
        return 0;
    val = strtol(str, &end, 10);
    if (errno == ERANGE || val > INT_MAX)
        return 0;

    if (*end != '\0')
        return 0;  
    *result = (int)val;
    return 1;      
}

bool ProcessDate(std::string date,int &yy,int &mm,int &dd)
{
    int y,m,d;
    std::map<int ,std::string> dateFromat = splitString(date,'-');
    if(dateFromat.size() != 3)
    {
        std::cerr<<"Error: bad inpute => "+date<<std::endl;
        return true;
    }
    if(!parse_int(dateFromat[0].c_str(),&y,1) || 
    !parse_int(dateFromat[1].c_str(),&m,1) || 
    !parse_int(dateFromat[2].c_str(),&d,1))
    {
        std::cerr<<"Error: bad inpute => "+date<<std::endl;
        return true;
    }
    Date format(y,m,d);
    if(!format.IsValidDate() || !format.isvalidrange())
    {
        std::cerr<<"Error: bad inpute => "+date<<std::endl;
        return true;
    }
    yy = y;
    mm = m;
    dd = d;
    return false;
}
Date::Date(long y,short m ,short d ):year(y),month(m),day(d)
{
}
bool Date::isvalidrange()
{
    if(year  < 2009 && day < 2)
    {
        return false;
    }
    return true;
}
bool Date::IsValidDate()

{
  if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
    return false;
  }
  short maxDay;
  switch (month) {
    case 2:
      maxDay = 28;
      if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        maxDay = 29;
      break;
    case 4: case 6: case 9: case 11: maxDay = 30; break;
    default: maxDay = 31; break;
  }
  return day <= maxDay;

}
Date::Date()
{
}

Date::~Date()
{
}
#endif