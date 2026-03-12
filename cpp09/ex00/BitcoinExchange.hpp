#ifndef bb
#define bb
#include "Date.hpp"
#include <map>
#include <iostream>
class BitcoinExchange
{
private:
    std::map<Date,float> db;
public:
    BitcoinExchange();
    ~BitcoinExchange();
    void MatchDate(Date date,float value);
    void ParsData(std::string str);
};
void BitcoinExchange::ParsData(std::string str)
{
    std::map<int,std::string> data = splitString(str,',');
    std::map<int ,std::string> dateFromat = splitString(data[0],'-');
    int y,m,d;
    float value;
    value = atof(data[2].c_str());
    y = atoi(dateFromat[0].c_str());
    m = atoi(dateFromat[1].c_str());
    d = atoi(dateFromat[2].c_str());
    Date date(y,m,d);
    std::cout<<"adding "<<y<<+" "<<m<<+" "<<d<<std::endl;
    db.insert({date,value});
}

void BitcoinExchange::MatchDate(Date date,float value)
{
    std::map<Date,float>::iterator it = db.lower_bound(date);
    std::cout<<value<<std::endl;
}
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}
#endif