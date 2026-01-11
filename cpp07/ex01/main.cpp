#include "iter.hpp"

void printString(std::string s)
{
    std::cout<<s<<std::endl;
}
void printInt(int val)
{
    std::cout<<val<<" ";
}
int main()
{
    const std::string strings[4] = {"hello","bro","how","!"};
    const int arr[5] = {1,2,54,6,5};
    ::iter(strings,4,printString);
    ::iter(arr,5,printInt);
    std::cout<<std::endl;
}