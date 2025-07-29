#include "Zombie.hpp"

int main()
{
    Zombie * array = zombieHorde(10,"monsters");
    int i = 0;
    while (i < 10)
    {
       array[i].announce();
       i++;
    }
    delete [] array;
}