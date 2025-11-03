#include "Animal.hpp"

Animal::Animal(std::string type)
{
    this->type = type;
    std::cout<<"Animal Constructor has been called "<<std::endl;
}
Animal::Animal()
{
    type = "unknown";
    std::cout<<"Animal Constructor has been called "<<std::endl;
}
Animal::Animal(Animal const &other)
{
    this->type = other.type;
    std::cout<<"Animal copy Constructor has been called "<<std::endl;
}
Animal& Animal::operator=(Animal const  &other)
{
    this->type = other.type;
    std::cout<<"Animal copy assignment  Constructor has been called "<<std::endl;
    return *this;
}
Animal::~Animal()
{
     std::cout<<"Animal Destructor has been called "<<std::endl;
}

std::string const& Animal::getType() const
{
    return this->type;
}