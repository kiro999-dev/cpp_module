#include<iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	int _AttackDamage;

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	FragTrap &operator =(const FragTrap &other);
	~FragTrap();
    void highFivesGuys(void);
};
