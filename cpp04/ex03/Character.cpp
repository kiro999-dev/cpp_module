#include "Character.hpp"
Character::~Character()
{
    for (size_t i = 0; i < 4; i++)
    {
        if (amateria_arr[i])
            delete amateria_arr[i];
    }
}
Character::Character()
{
    for (size_t i = 0; i < 4; i++)
    {
        amateria_arr[i] = NULL;
    }
    std::cout << "Character Constructor has been called " << std::endl;
}

Character::Character(std::string name) : name(name)
{
    for (size_t i = 0; i < 4; i++)
    {
        amateria_arr[i] = NULL;
    }
    std::cout << "Character Constructor has been called " << std::endl;
}
Character::Character(Character const &other)
{
    name = other.name;
    for (size_t i = 0; i < 4; i++)
    {
        if (other.amateria_arr[i])
            amateria_arr[i] = other.amateria_arr[i]->clone();
        else
            amateria_arr[i] = NULL;
    }
    std::cout << "Character copy Constructor has been called " << std::endl;
}
/*
character A; all of a equipes are null // are not null
charcter B(A);
A [0] = B [4]
A = B;//leaks
*/
Character &Character::operator=(Character const &other)
{
    if (this == &other)
        return *this;
    for (size_t i = 0; i < 4; i++)
    {

        if (amateria_arr[i])
            delete amateria_arr[i];

        if (other.amateria_arr[i])
            amateria_arr[i] = other.amateria_arr[i]->clone();
        else
            amateria_arr[i] = NULL;
    }
    name = other.name;
    std::cout << "Character copy assignment  Constructor has been called " << std::endl;
    return *this;
}

std::string const &Character::getName() const
{
    return this->name;
}
void Character::equip(AMateria *m)
{
    if (m == NULL)
        return;
    for (size_t i = 0; i < 4; i++)
    {
        if (amateria_arr[i] == NULL)
        {
            amateria_arr[i] = m;
            if (m != NULL)
                std::cout << "equip AMateria " << m->getType() << std::endl;
            return;
        }
    }
    delete m;
}

void Character::unequip(int idx)
{
    if (idx < 4 && idx >= 0)
    {
        if (amateria_arr[idx] != NULL)
        {
            std::cout << "unequip AMateria " << amateria_arr[idx]->getType() << std::endl;
            amateria_arr[idx] = NULL;
            // save address for delete later
        }
        else
            std::cout << " nothing to unequip " << std::endl;
    }
}
void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && amateria_arr[idx] != NULL)
    {
        amateria_arr[idx]->use(target);
    }
}