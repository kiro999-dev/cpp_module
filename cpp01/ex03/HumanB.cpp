#include "HumanB.hpp"

void HumanB::attack()
{
    if(WpB == NULL)
    {
        std::cout<<this->name<<" dose not have a weapon "<<std::endl;
        return;
    }
    std::cout<<this->name<<" attacks with their "<<WpB->getType()<<std::endl;
}
void HumanB:: setWeapon(Weapon& weapon)
{
   this->WpB = &weapon;
}

HumanB::HumanB(std::string name)
{
    this->WpB = NULL;
    this->name = name;
}

HumanB::~HumanB()
{
}