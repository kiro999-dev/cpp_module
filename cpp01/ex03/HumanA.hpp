#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon &WpA;
        std::string name;
    public:
    HumanA(std::string name,Weapon &weaponA);
    void attack();
    ~HumanA();
};

#endif