#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string type)
{
    this->type = type;
    std::cout<<"WrongAnimal Constructor has been called "<<std::endl;
}
WrongAnimal::WrongAnimal()
{
    type = "unknown";
    std::cout<<"WrongAnimal Constructor has been called "<<std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
    this->type = other.type;
    std::cout<<"WrongAnimal copy Constructor has been called "<<std::endl;
}
WrongAnimal& WrongAnimal::operator=(WrongAnimal const  &other)
{
    this->type = other.type;
    std::cout<<"WrongAnimal copy assignment  Constructor has been called "<<std::endl;
    return *this;
}
WrongAnimal::~WrongAnimal()
{
     std::cout<<"WrongAnimal Destructor has been called "<<std::endl;
}
void WrongAnimal::makeSound () const
{
    std::cout<<"WrongAnimal making sound"<<std::endl;
}
std::string const& WrongAnimal::getType() const
{
    return this->type;
}