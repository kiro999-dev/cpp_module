#ifndef MAIN_HPP
#define MAIN_HPP

#include "Date.hpp"
#include <map>
#include <string>

class BitcoinExchange; 

void ProcessLine(std::string line, BitcoinExchange &btc);
std::map<int, std::string> splitString(const std::string& str, char delimiter);

#endif