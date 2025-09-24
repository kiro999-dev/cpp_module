#include "ScavTrap.hpp"
ScavTrap::ScavTrap(std::string name):_name(name)
{
    std::cout<<" ScavTrap constructor has been called"<<std::endl;
}
ScavTrap::ScavTrap():_AttackDamage(20), _HitPoint(100),_EnergyPoint(50) , _guard_mod(0)
{
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
    _name= other._name;
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
bool ScavTrap::get_guard()
{
    return _guard_mod;
}
void ScavTrap::set_guard(int val)
{
   _guard_mod = val;
}
void ScavTrap::guardGate()
{
    if(get_guard())
    {
          std::cout<<_name<<" is already in Gate keeper mode"<<std::endl;
          return;
    }
    std::cout<<_name<<" is now in Gate keeper mode"<<std::endl;
    set_guard(1);
}