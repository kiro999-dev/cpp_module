#include "iter.hpp"
#include <iostream>
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
    std::string strings[4] = {"hello","bro","how","!"};
    int arr[5] = {1,2,54,6,5};
    ::iter(strings,4,printString);
    ::iter(arr,5,printInt);
    std::cout<<std::endl;
}