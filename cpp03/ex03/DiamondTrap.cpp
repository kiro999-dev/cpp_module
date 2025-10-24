#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
{
    this->name = name;
    _AttackDamage = FragTrap::_AttackDamage;
    _HitPoint = FragTrap::_HitPoint;
    _EnergyPoint = ScavTrap::_EnergyPoint;

    std::cout << "_AttackDamage: " << _AttackDamage << std::endl;
    std::cout << "_HitPoint: " << _HitPoint << std::endl;
    std::cout << "_EnergyPoint: " << _EnergyPoint << std::endl;
    // std::cout << "DiamondTrap " << this->name << " has been constructed!" << std::endl;
}
DiamondTrap::DiamondTrap()
{
    this->name = "default diamond";
    _AttackDamage = FragTrap::_AttackDamage;
    _HitPoint = FragTrap::_HitPoint;
    _EnergyPoint = ScavTrap::_EnergyPoint;
    // std::cout<<"DiamondTrap constructor has been called"<<std::endl;
}


DiamondTrap::~DiamondTrap()
{
	// std::cout<<"DiamondTrap destructor has been called"<<std::endl;
}
DiamondTrap ::DiamondTrap(const DiamondTrap &other)
{
    name= other.name;
    _AttackDamage= other._AttackDamage;
    _EnergyPoint = other._EnergyPoint;
   _HitPoint = other._HitPoint;
//    std::cout<<"DiamondTrap copy construcor has been called"<<std::endl;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{   
    // std::cout<<"DiamondTrap copy  assignment operator has been called"<<std::endl;
    if(this == &other)
    {
        return *this;
    }
     name = other.name;
    _AttackDamage=other._AttackDamage;
    _EnergyPoint = other._EnergyPoint;
   _HitPoint = other._HitPoint;
   return *this;
}

