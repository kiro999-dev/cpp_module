#include "DiamondTrap.hpp"

int main()
{
 
    DiamondTrap st1; 
    DiamondTrap st2("ST-Two");

    std::cout << "\n==== Testing DiamondTrap Attacks ====" << std::endl;
    st2.attack("Intruder");
    st2.attack("Another Intruder");

    st2.highFivesGuys(); 

  

    return 0;
}
