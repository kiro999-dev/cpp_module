#include "main.hpp"
#include "BitcoinExchange.hpp"
int main(int argc,char**argv)
{
    if(argc < 2)
    {
       std::cout<< "Error: could not open file"<<std::endl;
       return 1;
    }else if(argc  > 2)
    {
       std::cout<< "Error: Too many arguments"<<std::endl;
       return 1;
    }
    std::ifstream csv("data.csv");
    if (!csv.is_open()) {
        std::cout << "Error opening file!" << std::endl;
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
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }
    int flag = 0;
    while (std::getline(inpute,line))
    {
        flag = 1;
        ProcessLine(line,btc);
    }
    if(!flag)
    {
        std::cout << "Error empty file!" << std::endl;
        return 1;
    }
    
}