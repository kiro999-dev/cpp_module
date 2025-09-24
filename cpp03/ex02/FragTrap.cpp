#include "FragTrap.hpp"
FragTrap::FragTrap(std::string name):_name(name)
{
    std::cout<<" FragTrap constructor has been called"<<std::endl;
}
FragTrap::FragTrap():_AttackDamage(30), _HitPoint(100),_EnergyPoint(100) 
{
    std::cout<<" FragTrap constructor has been called"<<std::endl;
}

FragTrap::~FragTrap()
{
	std::cout<<"FragTrap destructor has been called"<<std::endl;
}
FragTrap ::FragTrap(const FragTrap &other)
{
    _name = other._name;
    _AttackDamage=other._AttackDamage;
    _EnergyPoint = other._EnergyPoint;
   _HitPoint = other._HitPoint;
   std::cout<<" FragTrap copy construcor has been called"<<std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &other)
{   
    if(this == &other)
    {
        return *this;
    }
     _name= other._name;
    _AttackDamage=other._AttackDamage;
    _EnergyPoint = other._EnergyPoint;
   _HitPoint = other._HitPoint;
   std::cout<<"FragTrap assignment operator has been called"<<std::endl;
   return *this;
}