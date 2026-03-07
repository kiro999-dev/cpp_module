#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
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
void ProcessDate(std::string date)
{
    std::vector<std::string> dateFromat = splitString(date,'-');
    if(dateFromat.size() != 3)
    {
        std::cout<<"Error: bad inpute => "+date<<std::endl;
        return;
    }
   if(!CheckIsNumber(dateFromat[0])
        || !CheckIsNumber(dateFromat[1])
        || !CheckIsNumber(dateFromat[2]))
        std::cout<<"Error: bad inpute => "+date<<std::endl;
    
}
void ProcessLine(std::string line)
{
    std::vector<std::string> data = splitString(line,' ');
    static int flag = 0;
    if(data.size() != 3)
    {
        std::cout<<"Error: bad inpute => "+line<<std::endl;
        return;
    }
    if(flag == 0)
    { 
        if(data[0].compare("date") != 0 
        || data[1].compare("|") !=0 
        || data[2].compare("value") !=0)
             std::cout<<"Error: bad inpute => " + line<<std::endl;
        flag++;
        return;
    }
    ProcessDate(data[0]);
}
int main(int argc,char**argv)
{
    if(argc  < 2)
    {
       std::cout<< "Error: could not open file"<<std::endl;
       return 1;
    }
    std::ifstream inpute(argv[1]);
    if (!inpute.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(inpute,line))
    {
        ProcessLine(line);
    }
    
}