#ifndef DIAMONDTRAP_HPP
#define  DIAMONDTRAP_HPP
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
class DiamondTrap : public ClapTrap
{
private:

public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator =(const DiamondTrap &other);
	DiamondTrap();
	~DiamondTrap();
};

#endif