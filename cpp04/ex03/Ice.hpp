#ifndef Ice_hpp
#define Ice_hpp

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
class Ice : public AMateria
{

public:

    Ice(std::string const &type);
    Ice(Ice const& other);
    Ice();
    Ice &operator=(Ice const& other);
    void use(ICharacter &target);
    AMateria *clone() const;
    ~Ice();
};


#endif