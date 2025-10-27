#include "Dog.hpp"
Dog::Dog():Animal("Dog")
{
    this->type = "Dog";
     std::cout<<"Dog Constructor has been called "<<std::endl;
}

Dog::~Dog()
{
     std::cout<<"Dog Destructor has been called "<<std::endl;
}
Dog::Dog(Dog const &other)
{
    this->type = other.type;
    std::cout<<"Dog copy Constructor has been called "<<std::endl;
}
Dog& Dog::operator=(Dog const &other)
{

    this->type = other.type;
    std::cout<<"Dog copy assignment  Constructor has been called "<<std::endl;
    return *this;
}
void Dog::makeSound() const
{
    std::cout<<"3aw 3aw 3awwww"<<std::endl;
}