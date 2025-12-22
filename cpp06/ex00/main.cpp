#include <iostream>
#include "ScalarConverter.hpp"
int main(int argc,char **argv)
{
    if(argc !=2)
    {
        std::cout<<"enter a type (int,float ,double ,char)"<<std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
}