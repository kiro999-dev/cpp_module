#include "Date.hpp"
#include <map>
#include <iostream>
class BitcoinExchange
{
private:
    std::map<Date,double> db;
public:
    BitcoinExchange();
    ~BitcoinExchange();
    void AddElem(Date date,double value);
    void MatchDate(Date date);

};
void BitcoinExchange::AddElem(Date date,double value)
{
    db.insert({date,value});
}
void BitcoinExchange::MatchDate(Date date)
{
    std::map<Date,double>::iterator it = db.lower_bound(date);
    std::cout<<it->second;
}
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}
