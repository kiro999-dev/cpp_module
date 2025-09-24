#include<iostream>
#include "ClapTrap.hpp"

class FragTrap :  public ClapTrap
{
private:
    std::string _name;
	int _HitPoint;
	int _EnergyPoint;
	int _AttackDamage;
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	FragTrap &operator =(const FragTrap &other);
	FragTrap();
	~FragTrap();
    void highFivesGuys(void);
};
