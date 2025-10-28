#ifndef Cure_hpp
#define Cure_hpp

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
class Cure : public AMateria
{

public:

    Cure(std::string const &type);
    Cure(Cure const& other);
    Cure();
    Cure &operator=(Cure const& other);
    void use(ICharacter &target);
    AMateria *clone() const;
    ~Cure();
};


#endif