#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _HitPoint = 100;
    _EnergyPoint = 50;
    _AttackDamage = 20;
    std::cout << "ScavTrap constructor has been called" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
    _HitPoint = 100;
    _EnergyPoint = 50;
    _AttackDamage = 20;
    std::cout << "ScavTrap constructor has been called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(_HitPoint == 0)
    {
        std::cout << "ScavTrap " << _name << " you can not attack you have 0 Hit Point" << std::endl;
        return;
    }
    if(_EnergyPoint == 0)
    {
        std::cout << "ScavTrap " << _name << " you can not attack you have 0 Energy point" << std::endl;
        return;
    }
    _EnergyPoint--;
    std::cout << "ScavTrap " << _name << " attacks " << target 
              << " causing " << _AttackDamage << " points of damage!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor has been called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor has been called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{   
    if(this == &other)
    {
        return *this;
    }
    ClapTrap::operator=(other);
    std::cout << "ScavTrap copy assignment operator has been called" << std::endl;
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << _name << " is now in Gate keeper mode" << std::endl;
}