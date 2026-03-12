#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <errno.h> 
#include <climits>
#include "Date.hpp"
int strlen(const char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}


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
int parse_int(const char *str, int *result,int flag)
{
    char *end;
    long val;
    errno = 0;
    if(flag &&strlen(str) < 2)
        return 0;
    val = strtol(str, &end, 10);
    if (errno == ERANGE || val > INT_MAX)
        return 0;

    if (*end != '\0')
        return 0;  
    *result = (int)val;
    return 1;      
}
void ProcessValue(std::string s)
{
    float val;
    if(!parse_float(s.c_str(),&val,0) || val > 1000)
    {
        std::cerr<<"Error: too large a number"<<std::endl;
        return; 
    }
    else if(val < 0)
    {
        std::cerr<<"Error: not a positive number."<<std::endl;
       return;
    }
}
void ProcessDate(std::string date)
{
    int y,m,d;
    std::map<int ,std::string> dateFromat = splitString(date,'-');
    if(dateFromat.size() != 3)
    {
        std::cerr<<"Error: bad inpute => "+date<<std::endl;
       
        return;
    }
    if(!parse_int(dateFromat[0].c_str(),&y,1) || 
    !parse_int(dateFromat[1].c_str(),&m,1) || 
    !parse_int(dateFromat[2].c_str(),&d,1))
    {
        std::cerr<<"Error: bad inpute => "+date<<std::endl;
        return;
    }
    Date format(y,m,d);
    if(!format.IsValidDate() || !format.isvalidrange())
    {
        std::cerr<<"Error: bad inpute => "+date<<std::endl;
        return;
    }
}
void ProcessLine(std::string line)
{
    std::map<int ,std::string> data = splitString(line,' ');
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
    ProcessDate(data[0]);
    ProcessValue(data[2]);
    
}
int main(int argc,char**argv)
{
    if(argc  < 2)
    {
       std::cerr<< "Error: could not open file"<<std::endl;
       return 1;
    }
    std::ifstream inpute(argv[1]);
    if (!inpute.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(inpute,line))
    {
        ProcessLine(line);
    }
    
}