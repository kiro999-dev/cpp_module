#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
    std::cout<<" ScavTrap constructor has been called"<<std::endl;
}
ScavTrap::ScavTrap():ClapTrap()
{
    _AttackDamage = 20;
    _EnergyPoint = 50;
    _HitPoint = 100;
    std::cout<<" ScavTrap constructor has been called"<<std::endl;
}
void ScavTrap::attack(const std::string& target)
{
    if(_EnergyPoint == 0)
    {
        std::cout<<"you can not attack you had 0 Eenergy point"<<std::endl;
        return;
    }
    _EnergyPoint--;
    std::cout<<"ScavTrap "<<_name <<"attacks"<<target<<" , causing points of damage!"<<std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout<<"ScavTrap destructor has been called"<<std::endl;
}
ScavTrap ::ScavTrap(const ScavTrap &other)
{
    _name = other._name;
    _AttackDamage=other._AttackDamage;
    _EnergyPoint = other._EnergyPoint;
   _HitPoint = other._HitPoint;
   std::cout<<" ScavTrap copy construcor has been called"<<std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{   
    if(this == &other)
    {
        return *this;
    }
     _name= other._name;
    _AttackDamage=other._AttackDamage;
    _EnergyPoint = other._EnergyPoint;
   _HitPoint = other._HitPoint;
   std::cout<<"ScavTrap copy  assignment operator has been called"<<std::endl;
   return *this;
}

