#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name) : ClapTrap(name)
{
    _HitPoint = 100;
    _EnergyPoint = 100;
    _AttackDamage = 30;
    std::cout << "FragTrap constructor has been called" << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
    _HitPoint = 100;
    _EnergyPoint = 100;
    _AttackDamage = 30;
    std::cout << "FragTrap constructor has been called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor has been called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    _AttackDamage = other._AttackDamage;
    std::cout << "FragTrap copy constructor has been called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{   
    if(this == &other)
        return *this;
    ClapTrap::operator=(other);
    _AttackDamage = other._AttackDamage;
    std::cout << "FragTrap assignment operator has been called" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " requests high fives! ✋" << std::endl;
}
