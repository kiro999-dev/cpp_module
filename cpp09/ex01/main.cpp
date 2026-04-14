#include "RPN.hpp"

int main(int argc,char **argv)
{
    if (argc != 2)
        return error();
    std::string str = argv[1];
    return RPN(str);
}