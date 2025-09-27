#include "Zombie.hpp"

int main()
{
    Zombie * array = zombieHorde(10,"monsters");
    if(!array)
    {
        std::cout<<"array is null exiting..."<<std::endl;
        return 1;
    }
    int i = 0;
    while (i < 10)
    {
       array[i].announce();
       i++;
    }
    delete [] array;
}