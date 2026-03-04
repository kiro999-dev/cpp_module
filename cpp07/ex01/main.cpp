#include "iter.hpp"

void printString(const std::string &s)
{
    std::cout<<s<<std::endl;
}
void editSring(std::string &s)
{
  
    s +=" (Edited)\n";
    std::cout<<s;
}
int main()
{
    const std::string strings[4] = {"hello","bro","how","!"};
    std::string s[4] = {"hello","bro","how","!"};
    ::iter(strings,4,printString);
    ::iter(s,4,editSring);
    std::cout<<std::endl;
}