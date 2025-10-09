#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):_name(name)
{
    std::cout<<" ClapTrap constructor has been called"<<std::endl;
}
ClapTrap::ClapTrap():_AttackDamage(0), _HitPoint(10),_EnergyPoint(10) 
{
    std::cout<<" ClapTrap constructor has been called"<<std::endl;
}
void ClapTrap::attack(const std::string& target)
{
    if(_HitPoint == 0)
    {
        std::cout<<"you can not attack you had 0 Hit Point "<<std::endl;
    }
    if(_EnergyPoint == 0)
    {
        std::cout<<"you can not attack you had 0 Eenergy point"<<std::endl;
        return;
    }
    _EnergyPoint--;
    std::cout<<"ClapTrap "<<_name <<"attacks"<<target<<" , causing points of damage!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout<<"clapTrap take damage"<<std::endl;
    _HitPoint -=amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
       if(_EnergyPoint == 0)
    {
        std::cout<<"you can not be Repaired  you had 0 Eenergy point"<<std::endl;
        return;
    }
    std::cout<<"clapTrap be Repaired"<<std::endl;
    _HitPoint +=amount;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"ClaptTrap destructor has been called"<<std::endl;
}
ClapTrap ::ClapTrap(const ClapTrap &other)
{
    _name= other._name;
    _AttackDamage=other._AttackDamage;
    _EnergyPoint = other._EnergyPoint;
   _HitPoint = other._HitPoint;
   std::cout<<" ClapTrap copy construcor has been called"<<std::endl;
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
   std::cout<<"ClapTrap assignment operator has been called"<<std::endl;
   return *this;
}