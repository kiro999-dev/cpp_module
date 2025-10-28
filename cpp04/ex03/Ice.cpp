#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice Constructor has been called " << std::endl;
}

Ice::Ice(std::string const &type) : AMateria("ice")
{
    (void)type;
    std::cout << "Ice Constructor has been called " << std::endl;
}
Ice::Ice(Ice const &other) : AMateria(other)
{
    std::cout << "Ice copy Constructor has been called " << std::endl;
}
Ice  &Ice::operator=(Ice const &other)
{
    (void)other;
    std::cout << "Ice copy assignment  Constructor has been called " << std::endl;
    return *this;
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"<<std::endl;
}
Ice::~Ice()
{
    std::cout << "Ice Destructor has been called " << std::endl;
}

AMateria *Ice::clone() const
{
    return new Ice();
}