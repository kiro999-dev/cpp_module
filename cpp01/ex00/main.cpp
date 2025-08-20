#include "Zombie.hpp"

int main()
{
    randomChump("Zombie0");
    Zombie *Zombie1 = newZombie("Zombie1");
    Zombie Zombie2("Zombie2");
    Zombie1->announce();
    Zombie2.announce();
    delete Zombie1;
}