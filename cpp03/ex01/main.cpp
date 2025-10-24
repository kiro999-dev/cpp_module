#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
 
    ScavTrap st1; 
    ScavTrap st2("ST-Two");

    std::cout << "\n==== Testing ScavTrap Attacks ====" << std::endl;
    st1.attack("Intruder");
    st2.attack("Another Intruder");

    st2.guardGate(); 

  

    return 0;
}
