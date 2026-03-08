#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

std::map<int ,std::string> splitString(const std::string& str, char delimiter) {
    std::map<int ,std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    int i = 0;
    while (std::getline(ss, token, delimiter)) {
        tokens.insert({i,token});
        i++;
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
    std::map<int ,std::string> dateFromat = splitString(date,'-');
    if(dateFromat.size() != 3)
    {
        std::cout<<"Error: bad inpute4 => "+date<<std::endl;
        return;
    }
   if(!CheckIsNumber(dateFromat[0])
        || !CheckIsNumber(dateFromat[1])
        || !CheckIsNumber(dateFromat[2]))
        std::cout<<"Error: bad inpute3 => "+date<<std::endl;
    
}
void ProcessLine(std::string line)
{
    std::map<int ,std::string> data = splitString(line,' ');
    static int flag = 0;
    if(data.size() != 3)
    {
        std::cout<<"Error: bad inpute1 => "+line<<std::endl;
        flag++;
        return;
    }
    if(flag == 0)
    { 
        if(data[0].compare("date") != 0 
        || data[1].compare("|") !=0 
        || data[2].compare("value") !=0)
             std::cout<<"Error: bad inpute2 => " + line<<std::endl;
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