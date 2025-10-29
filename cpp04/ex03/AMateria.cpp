#include "AMateria.hpp"

AMateria::AMateria():type("unknown")
{
    std::cout<<"AMateria Constructor has been called "<<std::endl;
}
AMateria::AMateria(std::string const &type):type(type)
{
    std::cout<<"AMateria Constructor has been called "<<std::endl;
}
AMateria::AMateria(AMateria const& other):type(other.type)
{
    std::cout<<"AMateria copy Constructor has been called "<<std::endl;
}
AMateria & AMateria::operator=(AMateria const& other)
{
    (void)other;
    std::cout<<"AMateria copy assignment  Constructor has been called "<<std::endl;
    return *this;
}
std::string const & AMateria::getType() const
{
    return type;
}
 void AMateria::use(ICharacter &target)
 {
    (void)target;
 }
AMateria::~AMateria()
{
     std::cout<<"AMateria Destructor has been called "<<std::endl;
}

