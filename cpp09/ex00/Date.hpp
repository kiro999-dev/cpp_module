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
class Date
{
private:
    std::string date;
    long year;
    short month;
    short day;
public:
    Date(long, short, short, std::string);
    Date();
    Date(const Date &other);             
    Date &operator=(const Date &other); 
    ~Date();
    bool IsValidDate();
    bool isvalidrange();
    bool operator<(const Date &other) const;
    bool operator==(const Date &other) const;
    std::string Getdate() const;
};

#endif