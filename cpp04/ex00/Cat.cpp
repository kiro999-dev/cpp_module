#include "Cat.hpp"
Cat::Cat()
{
    this->type = "Cat";
     std::cout<<"Cat Constructor has been called "<<std::endl;
}

Cat::~Cat()
{
     std::cout<<"Cat Destructor has been called "<<std::endl;
}
Cat::Cat(Cat &other)
{
    this->type = other.type;
    std::cout<<"Cat copy Constructor has been called "<<std::endl;
}
Cat& Cat::operator=(Cat &other)
{
    this->type = other.type;
    std::cout<<"Cat copy assignment  Constructor has been called "<<std::endl;
}
void makeSound()
{
    std::cout<<"meow meow meeeeow"<<std::endl;
}