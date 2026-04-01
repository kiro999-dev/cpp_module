#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <stdlib.h>
#include <deque>
#include <algorithm>
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
std::vector<int> jacobSthal(int n)
{
    std::vector<int> jacob;
    std::vector<int> Sq;
    jacob.push_back(0);
    jacob.push_back(1);
    int x = 3;
    int i = 2;
    int xprim;
    while (x <= n)
    {
        x = jacob[i-1] + 2*jacob[i-2];
        jacob.push_back(x);
        i++;
    }
    i = 2;
    int size = 0;
    while (size < n)
    {
        if(jacob[i] <= n)
            Sq.push_back(jacob[i]);
        size++;
        x = jacob[i];
        xprim = jacob[i-1] + 1;
        while (x > xprim)
        {
            size++;
            x--;
            if(x <= n)
                Sq.push_back(x);
        }
        i++;
    }
    
    return Sq;
}

std::vector<int> Ford_jhonson(std::vector<int> &numbersV)
{
    int leftover = -1;
    std::vector<std::pair<int,int>> pairs;
    std::vector<std::pair<int,int>> pend;
    std::vector<int> mc;
    std::vector<int> Sq;
    if(numbersV.size() == 1)
        return numbersV;

    for (size_t i = 0; i + 1 < numbersV.size(); i += 2)
    {
        if(numbersV[i] < numbersV[i+1])
            pairs.push_back({numbersV[i], numbersV[i+1]});
        else
            pairs.push_back({numbersV[i+1], numbersV[i]});
    }
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::cout<<"["<<pairs[i].first<<", "<<pairs[i].second<<"] "; 
    }
    std::cout<<"\n";
    if (numbersV.size() % 2 != 0)
        leftover = numbersV.back();

    for (size_t i = 0; i < pairs.size(); i++)
    {
        mc.push_back(pairs[i].second);
        pend.push_back({pairs[i].second,pairs[i].first});
    }
   
    mc = Ford_jhonson(mc);
    std::cout<<"new Main"<<":[";
    for (size_t i = 0; i < mc.size(); i++)
    {
        std::cout<<mc[i]<<" ";
    }
    std::cout<<"]\n";
    std::cout<<"new Pend"<<":[";
    std::sort(pend.begin(),pend.end());
    for (size_t i = 0; i < pend.size(); i++)
    {
        std::cout<<pend[i].second<<" ";
    }
    std::cout<<"]\n";
    Sq = jacobSthal(pend.size());
    int idx = 0;
    for (size_t i = 0; i < Sq.size(); i++)
    {
        if(Sq.size() > 2)
            idx = Sq[i]-1;
        else
            idx = i;
       
        if (idx < (int)pend.size())
        {
           std::vector<int>::iterator it = std::lower_bound(mc.begin(), mc.end(), pend[idx].second);
            mc.insert(it, pend[idx].second);
        }
    }
    if(leftover!=-1)
    {
        std::vector<int>::iterator it = std::lower_bound(mc.begin(),mc.end(),leftover);
        mc.insert(it,leftover);
    }
  
    return mc;
   
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

    numbersV =  Ford_jhonson(numbersV);
    while (i < numbersV.size())
    {
        std::cout<<numbersV[i]<<" ";
        i++;
    }
    std::cout<<'\n';

}