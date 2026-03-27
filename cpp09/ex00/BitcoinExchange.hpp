#ifndef bb
#define bb
#include "Date.hpp"
#include <map>
#include <iostream>
#include "main.hpp"
class BitcoinExchange
{
private:
    std::map<Date,double> db;
public:
    BitcoinExchange();
    ~BitcoinExchange();
    void MatchDate(Date date,double value);
    void ParsData(std::string str);
};

#endif