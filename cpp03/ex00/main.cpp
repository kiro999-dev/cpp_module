#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("elliot");
    ClapTrap b("mr robot");
    ClapTrap c;
    
    c.attack("random robot");
    a.attack("mr robot");
    b.takeDamage(100);
    b.takeDamage(100);
    b.beRepaired(5);
    std::cout << std::endl;

    return 0;
}
