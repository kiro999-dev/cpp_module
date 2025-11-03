#include "DiamondTrap.hpp"

int main()
{
 
    DiamondTrap st1; 
    DiamondTrap st2("ST-Two");

    DiamondTrap diamond("Diamond");
    diamond.attack("target");
    std::cout << "\n==== Testing DiamondTrap Attacks ====" << std::endl;
    st2.attack(" Intruder");
    st2.attack(" Another Intruder");
    st1.beRepaired(10);
    st2.whoAmI();
    return 0;
}
