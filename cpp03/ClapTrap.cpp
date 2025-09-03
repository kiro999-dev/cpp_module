#include "ClapTrap.hpp"
ClapTrap::ClapTrap(std::string name):_name(name)
{
    std::cout<<"constructor has been called";
}
ClapTrap::ClapTrap():_AttackDamage(0), _HitPoint(10),_EnergyPoint(10) 
{
    std::cout<<"constructor has been called";
}
void ClapTrap::attack(const std::string& target)
{
    _EnergyPoint--;
    std::cout<<"ClapTrap "<<_name <<"attacks"<<target<<" , causing points of damage!";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout<<"clapTrap take damage";
    _HitPoint -=amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout<<"clapTrap be Repaired";
    _HitPoint +=amount;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"destructor has been called";
}
ClapTrap ::ClapTrap(const ClapTrap &other)
{
    _name= other._name;
    _AttackDamage=other._AttackDamage;
    _EnergyPoint = other._EnergyPoint;
   _HitPoint = other._HitPoint;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{   
    if(this == &other)
    {
        return *this;
    }
     _name= other._name;
    _AttackDamage=other._AttackDamage;
    _EnergyPoint = other._EnergyPoint;
   _HitPoint = other._HitPoint;
   return *this;
}