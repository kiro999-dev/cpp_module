#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
    Zombie *Zombies = new Zombie[N];
    int i = 0;
    while(i < N)
    {
        Zombies[i].SetName(name);
        i++;
    }
    return (Zombies);
}