#include "Zombie.hpp"

int main()
{
    randomChump("Zombie0");
    Zombie *Zombie1 = newZombie("Zombie1");
    Zombie1->announce();
    delete Zombie1;
}