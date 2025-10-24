#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("elliot");
    ClapTrap b("mr robot");

    std::cout << std::endl;

    a.attack("mr robot");
    b.takeDamage(5);

    std::cout << std::endl;
    b.beRepaired(3);
    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
        a.attack("Training Dummy");

    std::cout << std::endl;
    a.attack("Training Dummy");
    std::cout << std::endl;
    b.takeDamage(100);
    b.beRepaired(5);
    std::cout << std::endl;

    return 0;
}
