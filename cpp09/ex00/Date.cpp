#include "Date.hpp"
std::string Date::Getdate() const
{
    return date;
}
Date::Date(long y,short m ,short d ,std::string ddate):date(ddate),year(y),month(m),day(d)
{
}
Date::Date(const Date &other)
    : date(other.date), year(other.year), month(other.month), day(other.day)
{
}

Date &Date::operator=(const Date &other)
{
    if (this != &other)
    {
        date  = other.date;
        year  = other.year;
        month = other.month;
        day   = other.day;
    }
    return *this;
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
      if (year % 4 == 0)
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
bool Date::operator<(const Date &other) const
{
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
        return day < other.day;
}
bool Date::operator==(const Date &other) const
{
    return year == other.year && month == other.month && day == other.day;
}