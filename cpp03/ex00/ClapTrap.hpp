#include <iostream>

class ClapTrap
{
private:
	std::string _name;
	int _HitPoint;
	int _EnergyPoint;
	int _AttackDamage;

public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator =(const ClapTrap &other);
	ClapTrap();
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

