#include <iostream>
#include <string>

int main(int argc,char **argv)
{
    std::string str;
    if(argc == 1)
    {
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    for ( int i = 1; i < argc; i++)
    {
        str = argv[i];
        for (size_t j = 0; j < str.size(); j++)
        {
            std::cout<<(char)std::toupper(str[j]);
            
        }
        
    }
    std::cout <<'\n';
    return(0);
}