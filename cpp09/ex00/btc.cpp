
#include "Date.hpp"
#include "BitcoinExchange.hpp"

bool CheckIsNumber(std::string str)
{
    int i  = 0;
    while (str[i])
    {
        if(!isdigit(str[i]))
            return false; 
        i++;
    }
    return true;

}
float parse_float(const char *str, float *res,int flag)
{
    char *end;
    float val;

    errno = 0;
    val = strtof(str, &end);
    if(flag && strlen(str) < 2)
    {
        return 0;
    }
    if (errno == ERANGE) {
        *res = 0.0f; 
        return 0;
    }

    if (*end != '\0') {
        *res = 0.0f; 
        return 0;
    }

    *res =val; 
    return 1;
}

bool ProcessValue(std::string s)
{
    float val;
    if(!parse_float(s.c_str(),&val,0) || val > 1000)
    {
        std::cerr<<"Error: too large a number"<<std::endl;
        return true; 
    }
    else if(val < 0)
    {
        std::cerr<<"Error: not a positive number."<<std::endl;
       return true;
    }
    return false;
}

void ProcessLine(std::string line, BitcoinExchange &btc)
{
    std::map<int ,std::string> data = splitString(line,' ');
    int y,m,d;
    float value;
    static int flag = 0;
    if(data.size() != 3)
    {
        std::cerr<<"Error: bad inpute => "+line<<std::endl;
        flag++;
        return;
    }
    if(flag == 0)
    { 
        if(data[0].compare("date") != 0 
        || data[1].compare("|") !=0 
        || data[2].compare("value") !=0)
             std::cerr<<"Error: bad inpute => " + line<<std::endl;
        flag++;
        return;
    }
    value = atof(data[2].c_str());
    if(ProcessDate(data[0],y,m,d) || ProcessValue(data[2]))
        return;
    btc.MatchDate(Date(y,m,d),value);

}
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