#ifndef AMateria_hpp
#define AMateria_hpp

#include <iostream>
#include "ICharacter.hpp"
class AMateria
{
protected:
    std::string const type;
public:
    AMateria();
    AMateria(std::string const &type);
    AMateria(AMateria const& other);
    ~AMateria();
    AMateria &operator=(AMateria const& other);
    std::string const &getType() const; // Returns the materia type
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};


#endif