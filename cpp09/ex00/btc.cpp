#include "main.hpp"
#include "BitcoinExchange.hpp"
int main(int argc,char**argv)
{
    if(argc  < 2)
    {
       std::cerr<< "Error: could not open file"<<std::endl;
       return 1;
    }
    std::ifstream csv("data.csv");
    if (!csv.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    std::string line;
    BitcoinExchange btc;
    while (std::getline(csv,line))
    {
        btc.ParsData(line);
    }

    std::ifstream inpute(argv[1]);
    if (!inpute.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    while (std::getline(inpute,line))
    {
        ProcessLine(line,btc);
    }

 
    
}