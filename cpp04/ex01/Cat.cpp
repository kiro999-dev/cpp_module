#include "Cat.hpp"
Cat::Cat():Animal("Cat")
{
    this->type = "Cat";
     std::cout<<"Cat Constructor has been called "<<std::endl;
}

Cat::~Cat()
{
     std::cout<<"Cat Destructor has been called "<<std::endl;
}
Cat::Cat(Cat const& other)
{
    this->type = other.type;
    std::cout<<"Cat copy Constructor has been called "<<std::endl;
}
Cat& Cat::operator=(Cat const& other)
{
    this->type = other.type;
    std::cout<<"Cat copy assignment  Constructor has been called "<<std::endl;
    return *this;
}
void Cat::makeSound() const
{
    std::cout<<"meow meow meeeeow"<<std::endl;
}