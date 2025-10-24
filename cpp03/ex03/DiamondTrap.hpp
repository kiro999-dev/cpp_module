#ifndef DIAMONDTRAP_HPP
#define  DIAMONDTRAP_HPP
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator =(const DiamondTrap &other);
	DiamondTrap();
	~DiamondTrap();
};

#endif