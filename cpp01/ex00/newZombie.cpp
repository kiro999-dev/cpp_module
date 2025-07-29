#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *newZo = new Zombie(name);
    return newZo;
}