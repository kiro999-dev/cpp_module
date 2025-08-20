#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout<<this->name<<" attacks with their "<<this->WpA.getType()<<std::endl;
}
HumanA::HumanA(std::string name, Weapon &weaponA):WpA(weaponA)
{
    this->name = name;
}

HumanA::~HumanA()
{
}