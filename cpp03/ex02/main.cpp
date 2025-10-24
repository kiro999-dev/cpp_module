#include "FragTrap.hpp"

int main()
{
 
    FragTrap st1; 
    FragTrap st2("ST-Two");

    std::cout << "\n==== Testing FragTrap Attacks ====" << std::endl;
    st2.attack("Intruder");
    st2.attack("Another Intruder");

    st2.highFivesGuys(); 

  

    return 0;
}
