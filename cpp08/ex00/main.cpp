#include "easyfind.hpp"
#include <vector>
int main()
{
    std::vector<int> x ={1,2,3,4,5};
    std::cout<<::easyfind(x,3)<<std::endl;  
    std::cout<<::easyfind(x,-9)<<std::endl;
}