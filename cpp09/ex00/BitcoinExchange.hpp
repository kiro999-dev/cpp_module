#ifndef BitcoinExchange_hpp
#define BitcoinExchange_hpp
#include "Date.hpp"
#include <map>
#include <iostream>
#include "main.hpp"

class BitcoinExchange
{
private:
    std::map<Date, double> db;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &obj);
    BitcoinExchange &operator=(const BitcoinExchange &obj);
    ~BitcoinExchange();
    void MatchDate(Date date, double value);
    void ParsData(std::string str);
};

#endif