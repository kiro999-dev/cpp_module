#include "BitcoinExchange.hpp"

void BitcoinExchange::ParsData(std::string str)
{
    std::map<int,std::string> data = splitString(str,',');
    std::map<int ,std::string> dateFromat = splitString(data[0],'-');
    int y,m,d;
    double value;
    value = atof(data[1].c_str());
    y = atoi(dateFromat[0].c_str());
    m = atoi(dateFromat[1].c_str());
    d = atoi(dateFromat[2].c_str());
    Date date(y,m,d,str);
    db.insert({date,value});
}
void BitcoinExchange::MatchDate(Date date, double value)
{
    std::map<Date, double>::iterator it = db.lower_bound(date);

    if (it != db.end() && it->first == date)
    {
        std::cout << date.Getdate() << " => " << value << " = " << value * it->second << std::endl;
        return;
    }
    // std::cout<<it->first.Getdate()<<std::endl;
    --it;
    // std::cout<<it->first.Getdate()<<std::endl;
    if (it == db.begin())
    {
        std::cout<<"year not available in db\n";
        return ;
    }
    
    std::cout << date.Getdate() << " => " << value << " = " << value * it->second << std::endl;
}
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}