#include <iostream>
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
private:
	std::string _name;
	int _HitPoint;
	int _EnergyPoint;
	int _AttackDamage;

public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator =(const ScavTrap &other);
	ScavTrap();
	~ScavTrap();
	void attack(const std::string& target);
    void guardGate();
};

