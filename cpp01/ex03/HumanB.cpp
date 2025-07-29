#include "HumanB.hpp"

void HumanB::attack()
{
    if(WpB == nullptr)
        return;
    std::cout<<this->name<<" attacks with their "<<WpB->getType()<<std::endl;
}
void HumanB:: setWeapon(Weapon& weapon)
{
   this->WpB = &weapon;
}

HumanB::HumanB(std::string name)
{
    this->WpB = nullptr;
    this->name = name;
}

HumanB::~HumanB()
{
}