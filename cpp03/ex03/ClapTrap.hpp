#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string _name;
	int _AttackDamage;
	int _HitPoint;
	int _EnergyPoint;
	
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator =(const ClapTrap &other);
	ClapTrap();
	~ClapTrap();
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif