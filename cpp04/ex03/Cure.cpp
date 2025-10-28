#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
    std::cout << "Cure Constructor has been called " << std::endl;
}

Cure::Cure(std::string const &type) : AMateria("Cure")
{
    (void)type;
    std::cout << "Cure Constructor has been called " << std::endl;
}
Cure::Cure(Cure const &other) : AMateria(other)
{
    std::cout << "Cure copy Constructor has been called " << std::endl;
}
Cure  &Cure::operator=(Cure const &other)
{
    (void)other;
    std::cout << "Cure copy assignment  Constructor has been called " << std::endl;
    return *this;
}

void Cure::use(ICharacter &target)
{
    std::cout << "* shoots an Cure bolt at " << target.getName() << " *"<<std::endl;
}
Cure::~Cure()
{
    std::cout << "Cure Destructor has been called " << std::endl;
}

AMateria *Cure::clone() const
{
    return new Cure();
}