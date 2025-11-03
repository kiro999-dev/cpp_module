#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name")
{
    this->_name = name;
    _AttackDamage = FragTrap::_AttackDamage;
    _HitPoint = FragTrap::_HitPoint;
    _EnergyPoint = ScavTrap::_EnergyPoint;

    std::cout << "DiamondTrap " << this->_name << " has been constructed!" << std::endl;
}
DiamondTrap::DiamondTrap():ClapTrap("default diamond_clap_name"), FragTrap(), ScavTrap()
{
    this->_name = "default diamond";
    _AttackDamage = FragTrap::_AttackDamage;
    _HitPoint = FragTrap::_HitPoint;
    _EnergyPoint = ScavTrap::_EnergyPoint;
    std::cout<<"DiamondTrap constructor has been called"<<std::endl;
}


DiamondTrap::~DiamondTrap()
{
	std::cout<<"DiamondTrap destructor has been called"<<std::endl;
}
DiamondTrap ::DiamondTrap(const DiamondTrap &other):ClapTrap(other),FragTrap(other),ScavTrap(other)
{
    _name= other._name;
   std::cout<<"DiamondTrap copy construcor has been called"<<std::endl;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{   
    std::cout<<"DiamondTrap copy  assignment operator has been called"<<std::endl;
    if(this == &other)
    {
        return *this;
    }
    _name=other._name;
    ClapTrap::operator=(other);
    FragTrap::operator=(other);
    ScavTrap::operator=(other);
   return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout<<"my _name: "<<_name<<" ClapTrap _name: "<<ClapTrap::_name<<std::endl;
}