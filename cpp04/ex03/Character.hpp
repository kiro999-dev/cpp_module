#ifndef Character_hpp
#define Character_hpp
#include "ICharacter.hpp"


class Character :public ICharacter
{
private:
    std::string name;
    AMateria *amateria_arr[4];
public:
    Character();
    Character  &operator=(Character const &other);
    Character(Character const &other);
    Character(std::string name);
    ~Character();
     std::string const &getName() const;
     void equip(AMateria *m);
     void unequip(int idx);
     void use(int idx, ICharacter &target);
     
};



#endif