#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}
Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout<<this->name<<" destroyed"<<std::endl;
}
void Zombie::SetName(std::string name)
{
    this->name = name;
}