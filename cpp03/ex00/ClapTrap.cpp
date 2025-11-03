#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):_name(name),_AttackDamage(0), _HitPoint(10),_EnergyPoint(10) 
{
    std::cout<<"ClapTrap "<<_name<<" constructor has been called"<<std::endl;
}
ClapTrap::ClapTrap():_AttackDamage(0), _HitPoint(10),_EnergyPoint(10) 
{
    _name = "unnamed";
    std::cout<<"ClapTrap constructor has been called"<<std::endl;
}
void ClapTrap::attack(const std::string& target)
{
    if(_HitPoint == 0)
    {
        std::cout<<"ClapTrap "<<_name<<" you can not attack you have 0 Hit Point"<<std::endl;
        return;
    }
    if(_EnergyPoint == 0)
    {
        std::cout<<"ClapTrap "<<_name<<" you can not attack you have 0 Energy point"<<std::endl;
        return;
    }
    _EnergyPoint--;
    std::cout<<"ClapTrap "<<_name <<" attacks "<<target
        <<" causing "<<_AttackDamage<<" points of damage!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(_HitPoint <=0)
    {
        std::cout<<"ClapTrap "<<_name<<" is already dead — why are you still hitting him?!"<<std::endl;
        return;
    }
    _HitPoint -=amount;
    if(_HitPoint < 0)
        _HitPoint = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount << " damage! HP now: " << _HitPoint << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(_HitPoint<=0)
    {
        std::cout<<"ClapTrap "<<_name<<" is already dead — no repairs can save it!"<<std::endl;
        return;
    }
    if(_EnergyPoint <= 0)
    {
        std::cout<<"ClapTrap "<<_name<<" you can not be Repaired you have 0 Energy point"<<std::endl;
        return;
    }
    std::cout<<"ClapTrap "<<_name<<" is being repaired"<<std::endl;
    _EnergyPoint--;
    _HitPoint +=amount;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"ClapTrap destructor has been called"<<std::endl;
}
ClapTrap ::ClapTrap(const ClapTrap &other)
{
    _name= other._name;
    _AttackDamage=other._AttackDamage;
    _EnergyPoint = other._EnergyPoint;
   _HitPoint = other._HitPoint;
   std::cout<<"ClapTrap copy constructor has been called"<<std::endl;
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