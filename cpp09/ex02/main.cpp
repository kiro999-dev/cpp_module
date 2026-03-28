#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <stdlib.h>
#include <deque>
std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    int i = 0;
    while (std::getline(ss, token, delimiter)) {
        if(token.empty())
            i++;
        else
        {
            tokens.push_back(token);
            i++;    
        }
        
    }
    return tokens;
}
int error()
{
    std::cerr << "Error" << std::endl;
    return -1;
}
int parse_int(const char *str, int *result)
{
    char *end;
    long val;
    errno = 0;
    val = strtol(str, &end, 10);
    if (errno == ERANGE || val > INT_MAX)
        return 0;

    if (*end != '\0')
        return 0;  
    *result = (int)val;
    return 1;      
}
bool  fillVector(std::vector<int> &numbersV,char *str){
    int i = 0;
    int res = 0;
    std::vector<std::string> numbersS  = splitString(str,' ');

    while (i < numbersS.size())
    {
        if(!parse_int(numbersS[i].c_str(),&res))  return false;
        numbersV.push_back(res);
        i++;
    }
    return true;
}
bool  fillDeque(std::deque<int> &numbersD,char *str){
    int i = 0;
    int res = 0;
    std::vector<std::string> numbersS  = splitString(str,' ');
    
    while (i < numbersS.size())
    {
        if(!parse_int(numbersS[i].c_str(),&res)) return false;
        numbersD.push_back(res);
        i++;
    }
    return true;
    
}
bool isvalid(char *str){
    int i = 0;
    while (str[i])
    {
        if(str[i] == ' ') i++;
        if(str[i] == '+' && !isdigit(str[i+1])) return false;
        if(!isdigit(str[i]) && str[i] !='+') return false;
        i++;
    }
    return true;
}
std::vector<int,int>MakePairs(const std::vector<int> &numbersV)
{
    int leftover = -1;
    std::vector<std::pair<int,int>> pairs;

    for (size_t i = 0; i + 1 < numbersV.size(); i += 2)
    {
        pairs.push_back({numbersV[i], numbersV[i+1]});
    }

    if (numbersV.size() % 2 != 0)
        leftover = numbersV.back();
}
int main(int argc ,char **argv)
{
    if(argc < 2)
    {
        std::cerr<<"Error\n";
        return -1;
    }
    std::vector<int> numbersV;
    std::deque<int> numbersD;
    int i = 1;
    while (argv[i])
    {
       if(isvalid(argv[i]) == false) return error();
       if (!fillVector(numbersV,argv[i])) return error();
       if (!fillDeque(numbersD,argv[i])) return error();
       i++;
    }
    i = 0;
    while (i < numbersV.size())
    {
        std::cout<<numbersV[i]<<" ";
        i++;
    }
    std::cout<<'\n';

}