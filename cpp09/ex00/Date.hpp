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
    Date();
    ~Date();
};

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
