#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie zo(name); 
    zo.announce();
}